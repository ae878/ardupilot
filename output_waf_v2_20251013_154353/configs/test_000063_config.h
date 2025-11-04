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

/* ConfigFuzz Test #63 */

/* ConfigFuzz: AP_RADIO_ENABLED */
#ifdef AP_RADIO_ENABLED
#undef AP_RADIO_ENABLED
#endif
#define AP_RADIO_ENABLED 1

/* ConfigFuzz: AP_INERTIALSENSOR_KILL_IMU_ENABLED */
#ifdef AP_INERTIALSENSOR_KILL_IMU_ENABLED
#undef AP_INERTIALSENSOR_KILL_IMU_ENABLED
#endif
#define AP_INERTIALSENSOR_KILL_IMU_ENABLED 1

/* ConfigFuzz: AP_PERIPH_RANGEFINDER_ENABLED */
#ifdef AP_PERIPH_RANGEFINDER_ENABLED
#undef AP_PERIPH_RANGEFINDER_ENABLED
#endif
#define AP_PERIPH_RANGEFINDER_ENABLED 1

#endif /* _AP_CONFIG_H_ */
