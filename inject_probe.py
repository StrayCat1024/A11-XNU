from pathlib import Path

p = Path('osfmk/arm64/start.s')
s = p.read_text()

probe_asm = '''
    /* ===== A11 GREEN SCREEN PROBE ===== */
    mov x0, #0x5c000000
    movz w1, #0xff00, lsl #16
    movz x2, #0x5400, lsl #16
    movk x2, #0x5400, lsl #16
1:  str w1, [x0], #4
    subs x2, x2, #1
    b.ne 1b
2:  b 2b
    /* ================================== */
'''

# 找到 reset_vector 标签并紧跟在后面插入
target = 'LEXT(reset_vector)'
if target in s:
    s = s.replace(target, target + '\n' + probe_asm, 1)
    p.write_text(s)
    print("✅ 成功在 reset_vector 后注入绿屏探针！")
else:
    print("❌ 依然找不到入口，请检查！")
