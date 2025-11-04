#pragma once
/* ConfigFuzz generated configuration */

#ifndef _AP_CONFIG_H_
#define _AP_CONFIG_H_

/* Essential defines */
#define _GNU_SOURCE 1
#define WAF_BUILD 1
#define PYTHONDIR "/usr/lib/python3/dist-packages"
#define PYTHONARCHDIR "/usr/lib/python3/dist-packages"
#define __STDC_FORMAT_MACROS 1
#define AP_SIGNED_FIRMWARE 0
#define HAVE_CMATH_ISFINITE 1
#define HAVE_CMATH_ISINF 1
#define HAVE_CMATH_ISNAN 1
#define NEED_CMATH_ISFINITE_STD_NAMESPACE 1
#define NEED_CMATH_ISINF_STD_NAMESPACE 1
#define NEED_CMATH_ISNAN_STD_NAMESPACE 1

/* ConfigFuzz Test #54 */

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 0

/* ConfigFuzz: BENCH_DEFINE_MAP_GEOMETRY */
#ifdef BENCH_DEFINE_MAP_GEOMETRY
#undef BENCH_DEFINE_MAP_GEOMETRY
#endif
#define BENCH_DEFINE_MAP_GEOMETRY 1

/* ConfigFuzz: AP_SERVORELAYEVENTS_ENABLED */
#ifdef AP_SERVORELAYEVENTS_ENABLED
#undef AP_SERVORELAYEVENTS_ENABLED
#endif
#define AP_SERVORELAYEVENTS_ENABLED 0

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 16

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_RTL */
#ifdef FS_GCS_ENABLED_ALWAYS_RTL
#undef FS_GCS_ENABLED_ALWAYS_RTL
#endif
#define FS_GCS_ENABLED_ALWAYS_RTL 1

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 2

/* ConfigFuzz: HAL_USE_SDMMC */
#ifdef HAL_USE_SDMMC
#undef HAL_USE_SDMMC
#endif
#define HAL_USE_SDMMC 0

/* ConfigFuzz: MAVLINK_MSG_ID_AP_ADC */
#ifdef MAVLINK_MSG_ID_AP_ADC
#undef MAVLINK_MSG_ID_AP_ADC
#endif
#define MAVLINK_MSG_ID_AP_ADC 0

/* ConfigFuzz: FS_GCS_ENABLED_BRAKE_OR_LAND */
#ifdef FS_GCS_ENABLED_BRAKE_OR_LAND
#undef FS_GCS_ENABLED_BRAKE_OR_LAND
#endif
#define FS_GCS_ENABLED_BRAKE_OR_LAND 1

#endif /* _AP_CONFIG_H_ */
