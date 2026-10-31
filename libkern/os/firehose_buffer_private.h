#ifndef _OS_FIREHOSE_BUFFER_PRIVATE_H_
#define _OS_FIREHOSE_BUFFER_PRIVATE_H_
#include <stdint.h>
#include <sys/types.h>

typedef struct firehose_tracepoint_s *firehose_tracepoint_t;

struct firehose_buffer_range_s {
    uint32_t dummy;
};

#define FIREHOSE_BUFFER_KERNEL_CHUNK_COUNT 64

static inline firehose_tracepoint_t
__firehose_buffer_tracepoint_reserve(uint64_t ts, void *stream, uint32_t pub, uint32_t priv, void *priv_data) {
    return (firehose_tracepoint_t)0;
}

static inline void
__firehose_buffer_tracepoint_flush(firehose_tracepoint_t ft, void *ftid) {
    // No-op
}

#endif
