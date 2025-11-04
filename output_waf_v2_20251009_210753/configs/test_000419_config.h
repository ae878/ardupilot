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

/* ConfigFuzz Test #419 */

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 0

/* ConfigFuzz: AP_HAL_UARTDRIVER_ENABLED */
#ifdef AP_HAL_UARTDRIVER_ENABLED
#undef AP_HAL_UARTDRIVER_ENABLED
#endif
#define AP_HAL_UARTDRIVER_ENABLED 0

/* ConfigFuzz: ESC_CHANNEL_MAP_CHANNEL */
#ifdef ESC_CHANNEL_MAP_CHANNEL
#undef ESC_CHANNEL_MAP_CHANNEL
#endif
#define ESC_CHANNEL_MAP_CHANNEL 0

/* ConfigFuzz: ESC_CHANNEL_MAP_RUNNING_DIRECTION */
#ifdef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#undef ESC_CHANNEL_MAP_RUNNING_DIRECTION
#endif
#define ESC_CHANNEL_MAP_RUNNING_DIRECTION 1

#endif /* _AP_CONFIG_H_ */
