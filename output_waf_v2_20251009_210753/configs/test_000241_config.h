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

/* ConfigFuzz Test #241 */

/* ConfigFuzz: HAL_BUTTON_ENABLED */
#ifdef HAL_BUTTON_ENABLED
#undef HAL_BUTTON_ENABLED
#endif
#define HAL_BUTTON_ENABLED 1

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 0

/* ConfigFuzz: MAVLINK_ENABLED_AVSSUAS */
#ifdef MAVLINK_ENABLED_AVSSUAS
#undef MAVLINK_ENABLED_AVSSUAS
#endif
#define MAVLINK_ENABLED_AVSSUAS 0

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 0

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 0

/* ConfigFuzz: CONFIG_LWIP_PPP_SUPPORT */
#ifdef CONFIG_LWIP_PPP_SUPPORT
#undef CONFIG_LWIP_PPP_SUPPORT
#endif
#define CONFIG_LWIP_PPP_SUPPORT 0

/* ConfigFuzz: HAL_INS_RATE_LOOP */
#ifdef HAL_INS_RATE_LOOP
#undef HAL_INS_RATE_LOOP
#endif
#define HAL_INS_RATE_LOOP 1

#endif /* _AP_CONFIG_H_ */
