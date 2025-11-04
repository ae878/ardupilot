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

/* ConfigFuzz Test #116 */

/* ConfigFuzz: HAL_HEATER_GPIO_ON */
#ifdef HAL_HEATER_GPIO_ON
#undef HAL_HEATER_GPIO_ON
#endif
#define HAL_HEATER_GPIO_ON 1

/* ConfigFuzz: MODE_ZIGZAG_ENABLED */
#ifdef MODE_ZIGZAG_ENABLED
#undef MODE_ZIGZAG_ENABLED
#endif
#define MODE_ZIGZAG_ENABLED 1

/* ConfigFuzz: MODE_AUTOROTATE_ENABLED */
#ifdef MODE_AUTOROTATE_ENABLED
#undef MODE_AUTOROTATE_ENABLED
#endif
#define MODE_AUTOROTATE_ENABLED 0

/* ConfigFuzz: AP_SRV_CHANNELS_ENABLED */
#ifdef AP_SRV_CHANNELS_ENABLED
#undef AP_SRV_CHANNELS_ENABLED
#endif
#define AP_SRV_CHANNELS_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_COMMON */
#ifdef MAVLINK_ENABLED_COMMON
#undef MAVLINK_ENABLED_COMMON
#endif
#define MAVLINK_ENABLED_COMMON 0

#endif /* _AP_CONFIG_H_ */
