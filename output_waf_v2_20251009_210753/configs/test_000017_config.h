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

/* ConfigFuzz Test #17 */

/* ConfigFuzz: HAL_CAN_DRIVER_DEFAULT */
#ifdef HAL_CAN_DRIVER_DEFAULT
#undef HAL_CAN_DRIVER_DEFAULT
#endif
#define HAL_CAN_DRIVER_DEFAULT 0

/* ConfigFuzz: AP_AIS_ENABLED */
#ifdef AP_AIS_ENABLED
#undef AP_AIS_ENABLED
#endif
#define AP_AIS_ENABLED 0

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_ALL */
#ifdef MAVLINK_ENABLED_ALL
#undef MAVLINK_ENABLED_ALL
#endif
#define MAVLINK_ENABLED_ALL 0

#endif /* _AP_CONFIG_H_ */
