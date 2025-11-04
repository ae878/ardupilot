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

/* ConfigFuzz Test #649 */

/* ConfigFuzz: MODE_ZIGZAG_ENABLED */
#ifdef MODE_ZIGZAG_ENABLED
#undef MODE_ZIGZAG_ENABLED
#endif
#define MODE_ZIGZAG_ENABLED 1

/* ConfigFuzz: HAL_HNF_MAX_FILTERS */
#ifdef HAL_HNF_MAX_FILTERS
#undef HAL_HNF_MAX_FILTERS
#endif
#define HAL_HNF_MAX_FILTERS 1

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 0

/* ConfigFuzz: HAL_GENERATOR_ENABLED */
#ifdef HAL_GENERATOR_ENABLED
#undef HAL_GENERATOR_ENABLED
#endif
#define HAL_GENERATOR_ENABLED 0

/* ConfigFuzz: USER_PARAMS_ENABLED */
#ifdef USER_PARAMS_ENABLED
#undef USER_PARAMS_ENABLED
#endif
#define USER_PARAMS_ENABLED 1

#endif /* _AP_CONFIG_H_ */
