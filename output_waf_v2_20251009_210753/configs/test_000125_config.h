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

/* ConfigFuzz Test #125 */

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 0

/* ConfigFuzz: HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS */
#ifdef HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS
#undef HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS
#endif
#define HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS 0

/* ConfigFuzz: HAL_EXTERNAL_AHRS_DEFAULT */
#ifdef HAL_EXTERNAL_AHRS_DEFAULT
#undef HAL_EXTERNAL_AHRS_DEFAULT
#endif
#define HAL_EXTERNAL_AHRS_DEFAULT 0

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 0

/* ConfigFuzz: MODE_THROW_ENABLED */
#ifdef MODE_THROW_ENABLED
#undef MODE_THROW_ENABLED
#endif
#define MODE_THROW_ENABLED 0

/* ConfigFuzz: HAL_SUPPORT_RCOUT_SERIAL */
#ifdef HAL_SUPPORT_RCOUT_SERIAL
#undef HAL_SUPPORT_RCOUT_SERIAL
#endif
#define HAL_SUPPORT_RCOUT_SERIAL 0

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 0

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 0

#endif /* _AP_CONFIG_H_ */
