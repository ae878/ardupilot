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

/* ConfigFuzz Test #841 */

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 1

/* ConfigFuzz: AP_SERVORELAYEVENTS_ENABLED */
#ifdef AP_SERVORELAYEVENTS_ENABLED
#undef AP_SERVORELAYEVENTS_ENABLED
#endif
#define AP_SERVORELAYEVENTS_ENABLED 0

/* ConfigFuzz: MODE_DRIFT_ENABLED */
#ifdef MODE_DRIFT_ENABLED
#undef MODE_DRIFT_ENABLED
#endif
#define MODE_DRIFT_ENABLED 1

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 1

/* ConfigFuzz: MODE_ZIGZAG_ENABLED */
#ifdef MODE_ZIGZAG_ENABLED
#undef MODE_ZIGZAG_ENABLED
#endif
#define MODE_ZIGZAG_ENABLED 0

/* ConfigFuzz: AUTOTUNE_ENABLED */
#ifdef AUTOTUNE_ENABLED
#undef AUTOTUNE_ENABLED
#endif
#define AUTOTUNE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
