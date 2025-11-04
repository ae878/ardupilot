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

/* ConfigFuzz Test #804 */

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

/* ConfigFuzz: HAL_RCOUT_RGBLED_RED */
#ifdef HAL_RCOUT_RGBLED_RED
#undef HAL_RCOUT_RGBLED_RED
#endif
#define HAL_RCOUT_RGBLED_RED 1

/* ConfigFuzz: CONFIG_LWIP_DHCP_RESTORE_LAST_IP */
#ifdef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#undef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#endif
#define CONFIG_LWIP_DHCP_RESTORE_LAST_IP 1

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC 1

/* ConfigFuzz: AP_NOTIFY_NAVIGATOR_LED_ENABLED */
#ifdef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#undef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#endif
#define AP_NOTIFY_NAVIGATOR_LED_ENABLED 0

/* ConfigFuzz: AC_PRECLAND_ENABLED */
#ifdef AC_PRECLAND_ENABLED
#undef AC_PRECLAND_ENABLED
#endif
#define AC_PRECLAND_ENABLED 0

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 0

#endif /* _AP_CONFIG_H_ */
