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

/* ConfigFuzz Test #144 */

/* ConfigFuzz: HAL_HAVE_SAFETY_SWITCH */
#ifdef HAL_HAVE_SAFETY_SWITCH
#undef HAL_HAVE_SAFETY_SWITCH
#endif
#define HAL_HAVE_SAFETY_SWITCH 1

/* ConfigFuzz: MAVLINK_MSG_ID_AP_ADC_CRC */
#ifdef MAVLINK_MSG_ID_AP_ADC_CRC
#undef MAVLINK_MSG_ID_AP_ADC_CRC
#endif
#define MAVLINK_MSG_ID_AP_ADC_CRC 0

/* ConfigFuzz: AP_AIRSPEED_ENABLED */
#ifdef AP_AIRSPEED_ENABLED
#undef AP_AIRSPEED_ENABLED
#endif
#define AP_AIRSPEED_ENABLED 0

#endif /* _AP_CONFIG_H_ */
