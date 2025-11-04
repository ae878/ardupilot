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

/* ConfigFuzz Test #66 */

/* ConfigFuzz: AP_CRASHDUMP_ENABLED */
#ifdef AP_CRASHDUMP_ENABLED
#undef AP_CRASHDUMP_ENABLED
#endif
#define AP_CRASHDUMP_ENABLED 0

/* ConfigFuzz: AP_CAMERA_ENABLED */
#ifdef AP_CAMERA_ENABLED
#undef AP_CAMERA_ENABLED
#endif
#define AP_CAMERA_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_CUBEPILOT */
#ifdef MAVLINK_ENABLED_CUBEPILOT
#undef MAVLINK_ENABLED_CUBEPILOT
#endif
#define MAVLINK_ENABLED_CUBEPILOT 0

#endif /* _AP_CONFIG_H_ */
