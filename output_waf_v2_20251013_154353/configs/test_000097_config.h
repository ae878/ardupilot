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

/* ConfigFuzz Test #97 */

/* ConfigFuzz: MODE_SMARTRTL_ENABLED */
#ifdef MODE_SMARTRTL_ENABLED
#undef MODE_SMARTRTL_ENABLED
#endif
#define MODE_SMARTRTL_ENABLED 0

/* ConfigFuzz: FFT_MAX_MISSED_UPDATES */
#ifdef FFT_MAX_MISSED_UPDATES
#undef FFT_MAX_MISSED_UPDATES
#endif
#define FFT_MAX_MISSED_UPDATES 4

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC 0

/* ConfigFuzz: AP_PERIPH_RPM_ENABLED */
#ifdef AP_PERIPH_RPM_ENABLED
#undef AP_PERIPH_RPM_ENABLED
#endif
#define AP_PERIPH_RPM_ENABLED 1

/* ConfigFuzz: MODE_ACRO_ENABLED */
#ifdef MODE_ACRO_ENABLED
#undef MODE_ACRO_ENABLED
#endif
#define MODE_ACRO_ENABLED 1

/* ConfigFuzz: AP_MISSION_ENABLED */
#ifdef AP_MISSION_ENABLED
#undef AP_MISSION_ENABLED
#endif
#define AP_MISSION_ENABLED 0

#endif /* _AP_CONFIG_H_ */
