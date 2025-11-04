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

/* ConfigFuzz Test #165 */

/* ConfigFuzz: AP_HAL_UARTDRIVER_ENABLED */
#ifdef AP_HAL_UARTDRIVER_ENABLED
#undef AP_HAL_UARTDRIVER_ENABLED
#endif
#define AP_HAL_UARTDRIVER_ENABLED 0

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 1

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 0

/* ConfigFuzz: HAL_HEATER_GPIO_PIN */
#ifdef HAL_HEATER_GPIO_PIN
#undef HAL_HEATER_GPIO_PIN
#endif
#define HAL_HEATER_GPIO_PIN 0

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_RTL */
#ifdef FS_GCS_ENABLED_ALWAYS_RTL
#undef FS_GCS_ENABLED_ALWAYS_RTL
#endif
#define FS_GCS_ENABLED_ALWAYS_RTL 0

/* ConfigFuzz: AP_STATS_ENABLED */
#ifdef AP_STATS_ENABLED
#undef AP_STATS_ENABLED
#endif
#define AP_STATS_ENABLED 1

#endif /* _AP_CONFIG_H_ */
