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

/* ConfigFuzz Test #340 */

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 1

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 0

/* ConfigFuzz: RANGEFINDER_MAX_INSTANCES */
#ifdef RANGEFINDER_MAX_INSTANCES
#undef RANGEFINDER_MAX_INSTANCES
#endif
#define RANGEFINDER_MAX_INSTANCES 8

/* ConfigFuzz: AP_AIS_ENABLED */
#ifdef AP_AIS_ENABLED
#undef AP_AIS_ENABLED
#endif
#define AP_AIS_ENABLED 0

/* ConfigFuzz: AP_ICENGINE_ENABLED */
#ifdef AP_ICENGINE_ENABLED
#undef AP_ICENGINE_ENABLED
#endif
#define AP_ICENGINE_ENABLED 1

/* ConfigFuzz: HAL_RCOUT_RGBLED_GREEN */
#ifdef HAL_RCOUT_RGBLED_GREEN
#undef HAL_RCOUT_RGBLED_GREEN
#endif
#define HAL_RCOUT_RGBLED_GREEN 0

/* ConfigFuzz: HAL_AIRSPEED_TYPE_DEFAULT */
#ifdef HAL_AIRSPEED_TYPE_DEFAULT
#undef HAL_AIRSPEED_TYPE_DEFAULT
#endif
#define HAL_AIRSPEED_TYPE_DEFAULT 0

/* ConfigFuzz: AP_OPTICALFLOW_ENABLED */
#ifdef AP_OPTICALFLOW_ENABLED
#undef AP_OPTICALFLOW_ENABLED
#endif
#define AP_OPTICALFLOW_ENABLED 0

#endif /* _AP_CONFIG_H_ */
