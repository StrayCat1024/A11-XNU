#!/bin/bash
HEADERS="IOTypes.h IOReturn.h IORPC.h IOKitKeys.h IOKernelReportStructs.h IOReportTypes.h queue_implementation.h macro_help.h bounded_ptr.h bounded_array.h bounded_array_ref.h bounded_ptr_fwd.h OSBoundedArray.h OSBoundedArrayRef.h OSBoundedPtr.h OSBoundedPtrFwd.h safe_allocation.h"

for h in $HEADERS; do
    if [ -f "iokit/DriverKit/$h" ]; then
        continue
    fi
    FOUND=$(find . -name "$h" | head -n 1)
    if [ -n "$FOUND" ]; then
        cp "$FOUND" "iokit/DriverKit/$h"
        echo "✅ Copied $h from $FOUND"
    else
        echo "⚠️ WARNING: $h not found"
    fi
done

echo "Cleaning Makefile..."
python3 - << 'PY_EOF'
import re, os
with open('iokit/DriverKit/Makefile', 'r') as f:
    content = f.read()
match = re.search(r'OTHER_HEADERS\s*=\s*(.*?)(?=\n[A-Z_]+\s*=|\n\n)', content, re.DOTALL)
if match:
    block = match.group(0)
    headers = re.findall(r'([a-zA-Z0-9_]+\.h)', block)
    missing = [h for h in headers if not os.path.exists(f"iokit/DriverKit/{h}")]
    if missing:
        print(f"Removing missing headers: {missing}")
        new_block = block
        for m in missing:
            new_block = new_block.replace(f" {m}", "").replace(f"{m} ", "")
        new_block = re.sub(r'\\\s*\n', ' \\\n', new_block)
        new_block = re.sub(r'OTHER_HEADERS\s*=\s*\\\n', 'OTHER_HEADERS = \\\n', new_block)
        content = content.replace(block, new_block)
        with open('iokit/DriverKit/Makefile', 'w') as f:
            f.write(content)
    else:
        print("All declared headers are present!")
PY_EOF
