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

/* ConfigFuzz Test #52 */

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

/* ConfigFuzz: HAL_SUPPORT_RCOUT_SERIAL */
#ifdef HAL_SUPPORT_RCOUT_SERIAL
#undef HAL_SUPPORT_RCOUT_SERIAL
#endif
#define HAL_SUPPORT_RCOUT_SERIAL 1

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 32

/* ConfigFuzz: HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS */
#ifdef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#undef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#endif
#define HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS 1

#endif /* _AP_CONFIG_H_ */
