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

/* ConfigFuzz Test #843 */

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN 1

/* ConfigFuzz: MODE_SPORT_ENABLED */
#ifdef MODE_SPORT_ENABLED
#undef MODE_SPORT_ENABLED
#endif
#define MODE_SPORT_ENABLED 1

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 8

#endif /* _AP_CONFIG_H_ */
