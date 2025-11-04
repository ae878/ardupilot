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

/* ConfigFuzz Test #574 */

/* ConfigFuzz: AP_RANGEFINDER_LUA_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_LUA_TIMEOUT_MS
#undef AP_RANGEFINDER_LUA_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_LUA_TIMEOUT_MS 1

/* ConfigFuzz: HAL_HAVE_IMU_HEATER */
#ifdef HAL_HAVE_IMU_HEATER
#undef HAL_HAVE_IMU_HEATER
#endif
#define HAL_HAVE_IMU_HEATER 0

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN 0

/* ConfigFuzz: AP_SRV_CHANNELS_ENABLED */
#ifdef AP_SRV_CHANNELS_ENABLED
#undef AP_SRV_CHANNELS_ENABLED
#endif
#define AP_SRV_CHANNELS_ENABLED 0

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 1

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 0

#endif /* _AP_CONFIG_H_ */
