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

/* ConfigFuzz Test #98 */

/* ConfigFuzz: HAL_WITH_SPI_RAMTRON */
#ifdef HAL_WITH_SPI_RAMTRON
#undef HAL_WITH_SPI_RAMTRON
#endif
#define HAL_WITH_SPI_RAMTRON 0

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP 1

/* ConfigFuzz: HAL_SUPPORT_RCOUT_SERIAL */
#ifdef HAL_SUPPORT_RCOUT_SERIAL
#undef HAL_SUPPORT_RCOUT_SERIAL
#endif
#define HAL_SUPPORT_RCOUT_SERIAL 0

/* ConfigFuzz: HAL_PERIPH_ENABLE_NOTIFY */
#ifdef HAL_PERIPH_ENABLE_NOTIFY
#undef HAL_PERIPH_ENABLE_NOTIFY
#endif
#define HAL_PERIPH_ENABLE_NOTIFY 1

/* ConfigFuzz: AP_RC_CHANNEL_ENABLED */
#ifdef AP_RC_CHANNEL_ENABLED
#undef AP_RC_CHANNEL_ENABLED
#endif
#define AP_RC_CHANNEL_ENABLED 1

#endif /* _AP_CONFIG_H_ */
