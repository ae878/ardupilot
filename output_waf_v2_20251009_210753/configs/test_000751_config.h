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

/* ConfigFuzz Test #751 */

/* ConfigFuzz: AP_FEATURE_RTSCTS */
#ifdef AP_FEATURE_RTSCTS
#undef AP_FEATURE_RTSCTS
#endif
#define AP_FEATURE_RTSCTS 1

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 1

/* ConfigFuzz: AP_NOTIFY_RCOUTPUTRGBLEDINVERTED_LED_ENABLED */
#ifdef AP_NOTIFY_RCOUTPUTRGBLEDINVERTED_LED_ENABLED
#undef AP_NOTIFY_RCOUTPUTRGBLEDINVERTED_LED_ENABLED
#endif
#define AP_NOTIFY_RCOUTPUTRGBLEDINVERTED_LED_ENABLED 0

#endif /* _AP_CONFIG_H_ */
