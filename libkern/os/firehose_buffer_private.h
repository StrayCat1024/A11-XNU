#ifndef _OS_FIREHOSE_BUFFER_PRIVATE_H_
#define _OS_FIREHOSE_BUFFER_PRIVATE_H_
#include <stdint.h>
#include <sys/types.h>
#include <firehose/chunk_private.h>

typedef struct firehose_tracepoint_s *firehose_tracepoint_t;

struct firehose_buffer_range_s {
    uint16_t fbr_offset;
    uint16_t fbr_length;
};

#define FIREHOSE_BUFFER_KERNEL_CHUNK_COUNT 64

static inline firehose_tracepoint_t
__firehose_buffer_tracepoint_reserve(uint64_t ts, firehose_stream_t stream, uint16_t pub, uint16_t priv, void *priv_data) {
    return (firehose_tracepoint_t)0;
}

static inline void
__firehose_buffer_tracepoint_flush(firehose_tracepoint_t ft, firehose_tracepoint_id_u ftid) {
}

#endif
