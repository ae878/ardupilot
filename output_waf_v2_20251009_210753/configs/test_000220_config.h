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

/* ConfigFuzz Test #220 */

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 0

/* ConfigFuzz: BENCH_DEFINE_MAP_EXPLICIT */
#ifdef BENCH_DEFINE_MAP_EXPLICIT
#undef BENCH_DEFINE_MAP_EXPLICIT
#endif
#define BENCH_DEFINE_MAP_EXPLICIT 0

/* ConfigFuzz: AP_CAMERA_ENABLED */
#ifdef AP_CAMERA_ENABLED
#undef AP_CAMERA_ENABLED
#endif
#define AP_CAMERA_ENABLED 0

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_GREEN_PIN 0

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP 0

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 0

#endif /* _AP_CONFIG_H_ */
