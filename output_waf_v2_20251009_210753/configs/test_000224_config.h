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

/* ConfigFuzz Test #224 */

/* ConfigFuzz: NOOPLOOP_DIST_MAX_MM */
#ifdef NOOPLOOP_DIST_MAX_MM
#undef NOOPLOOP_DIST_MAX_MM
#endif
#define NOOPLOOP_DIST_MAX_MM 1

/* ConfigFuzz: USER_PARAMS_ENABLED */
#ifdef USER_PARAMS_ENABLED
#undef USER_PARAMS_ENABLED
#endif
#define USER_PARAMS_ENABLED 0

/* ConfigFuzz: CONFIG_LWIP_PPP_SUPPORT */
#ifdef CONFIG_LWIP_PPP_SUPPORT
#undef CONFIG_LWIP_PPP_SUPPORT
#endif
#define CONFIG_LWIP_PPP_SUPPORT 1

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 0

#endif /* _AP_CONFIG_H_ */
