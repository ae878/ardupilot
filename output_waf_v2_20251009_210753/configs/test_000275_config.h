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

/* ConfigFuzz Test #275 */

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 0

/* ConfigFuzz: HAL_BUTTON_ENABLED */
#ifdef HAL_BUTTON_ENABLED
#undef HAL_BUTTON_ENABLED
#endif
#define HAL_BUTTON_ENABLED 1

/* ConfigFuzz: HAL_USB_PRODUCT_ID */
#ifdef HAL_USB_PRODUCT_ID
#undef HAL_USB_PRODUCT_ID
#endif
#define HAL_USB_PRODUCT_ID 1

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN 1

/* ConfigFuzz: MAVLINK_ENABLED_AVSSUAS */
#ifdef MAVLINK_ENABLED_AVSSUAS
#undef MAVLINK_ENABLED_AVSSUAS
#endif
#define MAVLINK_ENABLED_AVSSUAS 1

/* ConfigFuzz: MODE_SMARTRTL_ENABLED */
#ifdef MODE_SMARTRTL_ENABLED
#undef MODE_SMARTRTL_ENABLED
#endif
#define MODE_SMARTRTL_ENABLED 0

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN 0

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 1

#endif /* _AP_CONFIG_H_ */
