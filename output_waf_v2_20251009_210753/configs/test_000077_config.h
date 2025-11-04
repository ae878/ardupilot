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

/* ConfigFuzz Test #77 */

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 1

/* ConfigFuzz: HAL_USB_VENDOR_ID */
#ifdef HAL_USB_VENDOR_ID
#undef HAL_USB_VENDOR_ID
#endif
#define HAL_USB_VENDOR_ID 1

/* ConfigFuzz: HAL_HAVE_SAFETY_SWITCH */
#ifdef HAL_HAVE_SAFETY_SWITCH
#undef HAL_HAVE_SAFETY_SWITCH
#endif
#define HAL_HAVE_SAFETY_SWITCH 0

/* ConfigFuzz: HAL_USB_PRODUCT_ID */
#ifdef HAL_USB_PRODUCT_ID
#undef HAL_USB_PRODUCT_ID
#endif
#define HAL_USB_PRODUCT_ID 0

/* ConfigFuzz: MODE_SMARTRTL_ENABLED */
#ifdef MODE_SMARTRTL_ENABLED
#undef MODE_SMARTRTL_ENABLED
#endif
#define MODE_SMARTRTL_ENABLED 1

/* ConfigFuzz: AUTOTUNE_ENABLED */
#ifdef AUTOTUNE_ENABLED
#undef AUTOTUNE_ENABLED
#endif
#define AUTOTUNE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
