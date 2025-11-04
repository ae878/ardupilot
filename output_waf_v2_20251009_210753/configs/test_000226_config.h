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

/* ConfigFuzz Test #226 */

/* ConfigFuzz: AP_AIS_ENABLED */
#ifdef AP_AIS_ENABLED
#undef AP_AIS_ENABLED
#endif
#define AP_AIS_ENABLED 0

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 1

/* ConfigFuzz: MAVLINK_ENABLED_STANDARD */
#ifdef MAVLINK_ENABLED_STANDARD
#undef MAVLINK_ENABLED_STANDARD
#endif
#define MAVLINK_ENABLED_STANDARD 1

#endif /* _AP_CONFIG_H_ */
