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

/* ConfigFuzz Test #578 */

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 0

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC */
#ifdef MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC
#undef MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC
#endif
#define MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC 0

/* ConfigFuzz: AP_RELAY_ENABLED */
#ifdef AP_RELAY_ENABLED
#undef AP_RELAY_ENABLED
#endif
#define AP_RELAY_ENABLED 1

/* ConfigFuzz: AP_NOTIFY_DISCO_LED_ENABLED */
#ifdef AP_NOTIFY_DISCO_LED_ENABLED
#undef AP_NOTIFY_DISCO_LED_ENABLED
#endif
#define AP_NOTIFY_DISCO_LED_ENABLED 0

#endif /* _AP_CONFIG_H_ */
