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

/* ConfigFuzz Test #609 */

/* ConfigFuzz: AP_SIGNED_FIRMWARE */
#ifdef AP_SIGNED_FIRMWARE
#undef AP_SIGNED_FIRMWARE
#endif
#define AP_SIGNED_FIRMWARE 1

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 0

/* ConfigFuzz: BENCH_DEFINE_MAP_IMPLICIT */
#ifdef BENCH_DEFINE_MAP_IMPLICIT
#undef BENCH_DEFINE_MAP_IMPLICIT
#endif
#define BENCH_DEFINE_MAP_IMPLICIT 1

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 1

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

#endif /* _AP_CONFIG_H_ */
