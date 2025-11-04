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

/* ConfigFuzz Test #878 */

/* ConfigFuzz: AC_PRECLAND_ENABLED */
#ifdef AC_PRECLAND_ENABLED
#undef AC_PRECLAND_ENABLED
#endif
#define AC_PRECLAND_ENABLED 0

/* ConfigFuzz: MAVLINK_ENABLED_COMMON */
#ifdef MAVLINK_ENABLED_COMMON
#undef MAVLINK_ENABLED_COMMON
#endif
#define MAVLINK_ENABLED_COMMON 1

/* ConfigFuzz: MAXSONAR_SERIAL_LV_BAUD_RATE */
#ifdef MAXSONAR_SERIAL_LV_BAUD_RATE
#undef MAXSONAR_SERIAL_LV_BAUD_RATE
#endif
#define MAXSONAR_SERIAL_LV_BAUD_RATE 32

#endif /* _AP_CONFIG_H_ */
