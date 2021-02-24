#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER rostime

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "clock_recorder/tp.h"

#if !defined(_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>
#include <lttng/tracepoint-event.h>

TRACEPOINT_EVENT(
    TRACEPOINT_PROVIDER,
    ros_time,
    TP_ARGS(
        const uint64_t, stamp_arg
    ),
    TP_FIELDS(
        ctf_integer(const uint64_t, stamp, stamp_arg)
    )
)

#endif /* _TP_H */

