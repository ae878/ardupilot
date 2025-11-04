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

/* ConfigFuzz Test #945 */

/* ConfigFuzz: RPMMAX */
#ifdef RPMMAX
#undef RPMMAX
#endif
#define RPMMAX 2

/* ConfigFuzz: HAVE_ENUM_CAMERA_CAP_FLAGS */
#ifdef HAVE_ENUM_CAMERA_CAP_FLAGS
#undef HAVE_ENUM_CAMERA_CAP_FLAGS
#endif
#define HAVE_ENUM_CAMERA_CAP_FLAGS 1

/* ConfigFuzz: AP_AIRSPEED_ENABLED */
#ifdef AP_AIRSPEED_ENABLED
#undef AP_AIRSPEED_ENABLED
#endif
#define AP_AIRSPEED_ENABLED 0

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 0

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 0

/* ConfigFuzz: HAL_SOLO_GIMBAL_ENABLED */
#ifdef HAL_SOLO_GIMBAL_ENABLED
#undef HAL_SOLO_GIMBAL_ENABLED
#endif
#define HAL_SOLO_GIMBAL_ENABLED 1

#endif /* _AP_CONFIG_H_ */
