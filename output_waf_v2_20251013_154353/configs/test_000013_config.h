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

/* ConfigFuzz Test #13 */

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 0

/* ConfigFuzz: MPUREG_CONFIG_EXT_SYNC_GY */
#ifdef MPUREG_CONFIG_EXT_SYNC_GY
#undef MPUREG_CONFIG_EXT_SYNC_GY
#endif
#define MPUREG_CONFIG_EXT_SYNC_GY 0

/* ConfigFuzz: BENCH_DEFINE_MAP_PERMUTATION */
#ifdef BENCH_DEFINE_MAP_PERMUTATION
#undef BENCH_DEFINE_MAP_PERMUTATION
#endif
#define BENCH_DEFINE_MAP_PERMUTATION 1

#endif /* _AP_CONFIG_H_ */
