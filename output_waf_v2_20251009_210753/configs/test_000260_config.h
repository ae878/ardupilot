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

/* ConfigFuzz Test #260 */

/* ConfigFuzz: AC_PRECLAND_ENABLED */
#ifdef AC_PRECLAND_ENABLED
#undef AC_PRECLAND_ENABLED
#endif
#define AC_PRECLAND_ENABLED 1

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 1

/* ConfigFuzz: HAL_INS_RATE_LOOP */
#ifdef HAL_INS_RATE_LOOP
#undef HAL_INS_RATE_LOOP
#endif
#define HAL_INS_RATE_LOOP 1

#endif /* _AP_CONFIG_H_ */
