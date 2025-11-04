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

/* ConfigFuzz Test #452 */

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 0

/* ConfigFuzz: HAL_HNF_MAX_FILTERS */
#ifdef HAL_HNF_MAX_FILTERS
#undef HAL_HNF_MAX_FILTERS
#endif
#define HAL_HNF_MAX_FILTERS 32

/* ConfigFuzz: MAVLINK_ENABLED_CUBEPILOT */
#ifdef MAVLINK_ENABLED_CUBEPILOT
#undef MAVLINK_ENABLED_CUBEPILOT
#endif
#define MAVLINK_ENABLED_CUBEPILOT 0

/* ConfigFuzz: MODE_THROW_ENABLED */
#ifdef MODE_THROW_ENABLED
#undef MODE_THROW_ENABLED
#endif
#define MODE_THROW_ENABLED 1

/* ConfigFuzz: FS_THR_ENABLED_BRAKE_OR_LAND */
#ifdef FS_THR_ENABLED_BRAKE_OR_LAND
#undef FS_THR_ENABLED_BRAKE_OR_LAND
#endif
#define FS_THR_ENABLED_BRAKE_OR_LAND 0

/* ConfigFuzz: HAL_HAVE_SAFETY_SWITCH */
#ifdef HAL_HAVE_SAFETY_SWITCH
#undef HAL_HAVE_SAFETY_SWITCH
#endif
#define HAL_HAVE_SAFETY_SWITCH 1

/* ConfigFuzz: FLOW_CONTROL_ENABLED */
#ifdef FLOW_CONTROL_ENABLED
#undef FLOW_CONTROL_ENABLED
#endif
#define FLOW_CONTROL_ENABLED 1

/* ConfigFuzz: HAL_BARO_NONE */
#ifdef HAL_BARO_NONE
#undef HAL_BARO_NONE
#endif
#define HAL_BARO_NONE 0

/* ConfigFuzz: HAL_HAVE_IMU_HEATER */
#ifdef HAL_HAVE_IMU_HEATER
#undef HAL_HAVE_IMU_HEATER
#endif
#define HAL_HAVE_IMU_HEATER 0

#endif /* _AP_CONFIG_H_ */
