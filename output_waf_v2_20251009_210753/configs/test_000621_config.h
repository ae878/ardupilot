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

/* ConfigFuzz Test #621 */

/* ConfigFuzz: MODE_SMARTRTL_ENABLED */
#ifdef MODE_SMARTRTL_ENABLED
#undef MODE_SMARTRTL_ENABLED
#endif
#define MODE_SMARTRTL_ENABLED 1

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_RTL
#undef FS_THR_ENABLED_ALWAYS_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_RTL 0

/* ConfigFuzz: AC_PAYLOAD_PLACE_ENABLED */
#ifdef AC_PAYLOAD_PLACE_ENABLED
#undef AC_PAYLOAD_PLACE_ENABLED
#endif
#define AC_PAYLOAD_PLACE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
