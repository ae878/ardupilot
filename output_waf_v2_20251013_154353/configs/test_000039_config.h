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

/* ConfigFuzz Test #39 */

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 0

/* ConfigFuzz: HAL_PERIPH_ENABLE_RC_OUT */
#ifdef HAL_PERIPH_ENABLE_RC_OUT
#undef HAL_PERIPH_ENABLE_RC_OUT
#endif
#define HAL_PERIPH_ENABLE_RC_OUT 1

/* ConfigFuzz: BENCH_DEFINE_MAP_OVERRIDE */
#ifdef BENCH_DEFINE_MAP_OVERRIDE
#undef BENCH_DEFINE_MAP_OVERRIDE
#endif
#define BENCH_DEFINE_MAP_OVERRIDE 1

/* ConfigFuzz: HAL_SOARING_ENABLED */
#ifdef HAL_SOARING_ENABLED
#undef HAL_SOARING_ENABLED
#endif
#define HAL_SOARING_ENABLED 1

/* ConfigFuzz: HAL_GENERATOR_ENABLED */
#ifdef HAL_GENERATOR_ENABLED
#undef HAL_GENERATOR_ENABLED
#endif
#define HAL_GENERATOR_ENABLED 1

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 0

#endif /* _AP_CONFIG_H_ */
