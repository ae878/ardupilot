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

/* ConfigFuzz Test #5 */

/* ConfigFuzz: AC_PAYLOAD_PLACE_ENABLED */
#ifdef AC_PAYLOAD_PLACE_ENABLED
#undef AC_PAYLOAD_PLACE_ENABLED
#endif
#define AC_PAYLOAD_PLACE_ENABLED 0

/* ConfigFuzz: AP_SERIALMANAGER_ENABLED */
#ifdef AP_SERIALMANAGER_ENABLED
#undef AP_SERIALMANAGER_ENABLED
#endif
#define AP_SERIALMANAGER_ENABLED 1

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 32

/* ConfigFuzz: AP_FENCE_ENABLED */
#ifdef AP_FENCE_ENABLED
#undef AP_FENCE_ENABLED
#endif
#define AP_FENCE_ENABLED 0

#endif /* _AP_CONFIG_H_ */
