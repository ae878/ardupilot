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

/* ConfigFuzz Test #707 */

/* ConfigFuzz: AP_HAL_UARTDRIVER_ENABLED */
#ifdef AP_HAL_UARTDRIVER_ENABLED
#undef AP_HAL_UARTDRIVER_ENABLED
#endif
#define AP_HAL_UARTDRIVER_ENABLED 0

/* ConfigFuzz: MODE_CIRCLE_ENABLED */
#ifdef MODE_CIRCLE_ENABLED
#undef MODE_CIRCLE_ENABLED
#endif
#define MODE_CIRCLE_ENABLED 1

/* ConfigFuzz: HAL_FLASH_ALLOW_UPDATE */
#ifdef HAL_FLASH_ALLOW_UPDATE
#undef HAL_FLASH_ALLOW_UPDATE
#endif
#define HAL_FLASH_ALLOW_UPDATE 0

/* ConfigFuzz: CONFIG_LWIP_DHCP_RESTORE_LAST_IP */
#ifdef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#undef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#endif
#define CONFIG_LWIP_DHCP_RESTORE_LAST_IP 0

#endif /* _AP_CONFIG_H_ */
