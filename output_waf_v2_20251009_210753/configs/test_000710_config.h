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

/* ConfigFuzz Test #710 */

/* ConfigFuzz: MODE_BRAKE_ENABLED */
#ifdef MODE_BRAKE_ENABLED
#undef MODE_BRAKE_ENABLED
#endif
#define MODE_BRAKE_ENABLED 1

/* ConfigFuzz: HAL_USB_PRODUCT_ID */
#ifdef HAL_USB_PRODUCT_ID
#undef HAL_USB_PRODUCT_ID
#endif
#define HAL_USB_PRODUCT_ID 0

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 16

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 0

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 1

/* ConfigFuzz: MODE_DRIFT_ENABLED */
#ifdef MODE_DRIFT_ENABLED
#undef MODE_DRIFT_ENABLED
#endif
#define MODE_DRIFT_ENABLED 1

/* ConfigFuzz: FS_THR_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#undef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_THR_ENABLED_AUTO_RTL_OR_RTL 0

#endif /* _AP_CONFIG_H_ */
