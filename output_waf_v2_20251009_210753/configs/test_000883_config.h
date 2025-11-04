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

/* ConfigFuzz Test #883 */

/* ConfigFuzz: MODE_LOITER_ENABLED */
#ifdef MODE_LOITER_ENABLED
#undef MODE_LOITER_ENABLED
#endif
#define MODE_LOITER_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_CUBEPILOT */
#ifdef MAVLINK_ENABLED_CUBEPILOT
#undef MAVLINK_ENABLED_CUBEPILOT
#endif
#define MAVLINK_ENABLED_CUBEPILOT 1

/* ConfigFuzz: AP_FEATURE_SBUS_OUT */
#ifdef AP_FEATURE_SBUS_OUT
#undef AP_FEATURE_SBUS_OUT
#endif
#define AP_FEATURE_SBUS_OUT 1

/* ConfigFuzz: ESC_CHANNEL_MAP_RUNNING_DIRECTION */
#ifdef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#undef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#endif
#define ESC_CHANNEL_MAP_RUNNING_DIRECTION 0

#endif /* _AP_CONFIG_H_ */
