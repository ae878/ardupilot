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

/* ConfigFuzz Test #601 */

/* ConfigFuzz: HAL_NUM_CAN_IFACES */
#ifdef HAL_NUM_CAN_IFACES
#undef HAL_NUM_CAN_IFACES
#endif
#define HAL_NUM_CAN_IFACES 0

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN 0

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 0

#endif /* _AP_CONFIG_H_ */
