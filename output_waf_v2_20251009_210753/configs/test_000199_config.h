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

/* ConfigFuzz Test #199 */

/* ConfigFuzz: ESC_CHANNEL_MAP_RUNNING_DIRECTION */
#ifdef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#undef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#endif
#define ESC_CHANNEL_MAP_RUNNING_DIRECTION 0

/* ConfigFuzz: RPMMAX */
#ifdef RPMMAX
#undef RPMMAX
#endif
#define RPMMAX 2

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 1

/* ConfigFuzz: MAVLINK_ENABLED_ALL */
#ifdef MAVLINK_ENABLED_ALL
#undef MAVLINK_ENABLED_ALL
#endif
#define MAVLINK_ENABLED_ALL 0

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

#endif /* _AP_CONFIG_H_ */
