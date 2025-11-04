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

/* ConfigFuzz Test #155 */

/* ConfigFuzz: HAL_USB_PRODUCT_ID */
#ifdef HAL_USB_PRODUCT_ID
#undef HAL_USB_PRODUCT_ID
#endif
#define HAL_USB_PRODUCT_ID 1

/* ConfigFuzz: AP_COPTER_AHRS_AUTO_TRIM_ENABLED */
#ifdef AP_COPTER_AHRS_AUTO_TRIM_ENABLED
#undef AP_COPTER_AHRS_AUTO_TRIM_ENABLED
#endif
#define AP_COPTER_AHRS_AUTO_TRIM_ENABLED 1

/* ConfigFuzz: FLOW_CONTROL_ENABLED */
#ifdef FLOW_CONTROL_ENABLED
#undef FLOW_CONTROL_ENABLED
#endif
#define FLOW_CONTROL_ENABLED 1

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 1

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_LAND */
#ifdef FS_THR_ENABLED_ALWAYS_LAND
#undef FS_THR_ENABLED_ALWAYS_LAND
#endif
#define FS_THR_ENABLED_ALWAYS_LAND 0

/* ConfigFuzz: HAL_SOARING_ENABLED */
#ifdef HAL_SOARING_ENABLED
#undef HAL_SOARING_ENABLED
#endif
#define HAL_SOARING_ENABLED 1

/* ConfigFuzz: AP_RELAY_ENABLED */
#ifdef AP_RELAY_ENABLED
#undef AP_RELAY_ENABLED
#endif
#define AP_RELAY_ENABLED 1

/* ConfigFuzz: AP_ICENGINE_ENABLED */
#ifdef AP_ICENGINE_ENABLED
#undef AP_ICENGINE_ENABLED
#endif
#define AP_ICENGINE_ENABLED 0

#endif /* _AP_CONFIG_H_ */
