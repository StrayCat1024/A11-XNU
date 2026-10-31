#ifndef _TRUSTCACHE_API_H_
#define _TRUSTCACHE_API_H_
#include <stdint.h>
#include <stdbool.h>

#define kTCEntryHashSize 20
#define kUUIDSize 16

#define kTCReturnError 1
#define kTCReturnSuccess 0
#define kTCCapabilityNone 0

#define kTCTypeLTRS 1
#define kTCTypeStatic 2
#define kTCTypeEngineering 3
#define kTCTypeCryptex1BootOS 4
#define kTCTypeCryptex1BootApp 5
#define kTCTypeDTRS 6
#define kTCTypeLegacy 7
#define kTCTypeTotal 8

typedef uint32_t TCType_t;
typedef uint32_t TCQueryType_t;
typedef uint32_t TCCapabilities_t;
typedef uint32_t TrustCacheQueryToken_t;

typedef struct {
    int error;
    int component;
    int uniqueError;
} TCReturn_t;

typedef struct {
    uint32_t dummy;
} TrustCache_t;

typedef struct {
    bool allowEngineeringTC;
} TrustCacheRuntime_t;

typedef struct {
    const char *entitlementValue;
} TCTypeConfig_t;

static const TCTypeConfig_t TCTypeConfig[10] = {0};

#endif
