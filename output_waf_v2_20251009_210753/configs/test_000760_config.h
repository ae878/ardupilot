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

/* ConfigFuzz Test #760 */

/* ConfigFuzz: MODE_SMARTRTL_ENABLED */
#ifdef MODE_SMARTRTL_ENABLED
#undef MODE_SMARTRTL_ENABLED
#endif
#define MODE_SMARTRTL_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC 1

/* ConfigFuzz: HAL_SEMAPHORE_BLOCK_FOREVER */
#ifdef HAL_SEMAPHORE_BLOCK_FOREVER
#undef HAL_SEMAPHORE_BLOCK_FOREVER
#endif
#define HAL_SEMAPHORE_BLOCK_FOREVER 0

/* ConfigFuzz: AP_SIGNED_FIRMWARE */
#ifdef AP_SIGNED_FIRMWARE
#undef AP_SIGNED_FIRMWARE
#endif
#define AP_SIGNED_FIRMWARE 1

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 0

/* ConfigFuzz: HAL_HAVE_HARDWARE_DOUBLE */
#ifdef HAL_HAVE_HARDWARE_DOUBLE
#undef HAL_HAVE_HARDWARE_DOUBLE
#endif
#define HAL_HAVE_HARDWARE_DOUBLE 1

#endif /* _AP_CONFIG_H_ */
