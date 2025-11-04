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

/* ConfigFuzz Test #1 */

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 0

/* ConfigFuzz: HAL_HNF_MAX_FILTERS */
#ifdef HAL_HNF_MAX_FILTERS
#undef HAL_HNF_MAX_FILTERS
#endif
#define HAL_HNF_MAX_FILTERS 16

/* ConfigFuzz: HAL_ENABLE_THREAD_STATISTICS */
#ifdef HAL_ENABLE_THREAD_STATISTICS
#undef HAL_ENABLE_THREAD_STATISTICS
#endif
#define HAL_ENABLE_THREAD_STATISTICS 1

/* ConfigFuzz: HAVE_ENUM_CAMERA_CAP_FLAGS */
#ifdef HAVE_ENUM_CAMERA_CAP_FLAGS
#undef HAVE_ENUM_CAMERA_CAP_FLAGS
#endif
#define HAVE_ENUM_CAMERA_CAP_FLAGS 0

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 8

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

/* ConfigFuzz: HAL_WITH_IO_MCU */
#ifdef HAL_WITH_IO_MCU
#undef HAL_WITH_IO_MCU
#endif
#define HAL_WITH_IO_MCU 1

#endif /* _AP_CONFIG_H_ */
