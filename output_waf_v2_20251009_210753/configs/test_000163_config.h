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

/* ConfigFuzz Test #163 */

/* ConfigFuzz: HAL_USE_WSPI_DEFAULT_CFG */
#ifdef HAL_USE_WSPI_DEFAULT_CFG
#undef HAL_USE_WSPI_DEFAULT_CFG
#endif
#define HAL_USE_WSPI_DEFAULT_CFG 1

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 1

/* ConfigFuzz: HAL_QUADPLANE_ENABLED */
#ifdef HAL_QUADPLANE_ENABLED
#undef HAL_QUADPLANE_ENABLED
#endif
#define HAL_QUADPLANE_ENABLED 0

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 1

/* ConfigFuzz: HAL_MOUNT_ENABLED */
#ifdef HAL_MOUNT_ENABLED
#undef HAL_MOUNT_ENABLED
#endif
#define HAL_MOUNT_ENABLED 0

#endif /* _AP_CONFIG_H_ */
