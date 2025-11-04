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

/* ConfigFuzz Test #215 */

/* ConfigFuzz: HAL_RCOUT_RGBLED_BLUE */
#ifdef HAL_RCOUT_RGBLED_BLUE
#undef HAL_RCOUT_RGBLED_BLUE
#endif
#define HAL_RCOUT_RGBLED_BLUE 1

/* ConfigFuzz: MODE_FLIP_ENABLED */
#ifdef MODE_FLIP_ENABLED
#undef MODE_FLIP_ENABLED
#endif
#define MODE_FLIP_ENABLED 0

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 0

#endif /* _AP_CONFIG_H_ */
