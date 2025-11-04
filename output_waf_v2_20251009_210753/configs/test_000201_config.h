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

/* ConfigFuzz Test #201 */

/* ConfigFuzz: MODE_GUIDED_NOGPS_ENABLED */
#ifdef MODE_GUIDED_NOGPS_ENABLED
#undef MODE_GUIDED_NOGPS_ENABLED
#endif
#define MODE_GUIDED_NOGPS_ENABLED 0

/* ConfigFuzz: AP_NOTIFY_DISCO_LED_ENABLED */
#ifdef AP_NOTIFY_DISCO_LED_ENABLED
#undef AP_NOTIFY_DISCO_LED_ENABLED
#endif
#define AP_NOTIFY_DISCO_LED_ENABLED 1

/* ConfigFuzz: HAL_AIRSPEED_TYPE_DEFAULT */
#ifdef HAL_AIRSPEED_TYPE_DEFAULT
#undef HAL_AIRSPEED_TYPE_DEFAULT
#endif
#define HAL_AIRSPEED_TYPE_DEFAULT 1

#endif /* _AP_CONFIG_H_ */
