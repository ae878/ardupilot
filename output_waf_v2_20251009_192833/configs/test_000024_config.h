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

/* ConfigFuzz Test #24 */

/* ConfigFuzz: MODE_DRIFT_ENABLED */
#ifdef MODE_DRIFT_ENABLED
#undef MODE_DRIFT_ENABLED
#endif
#define MODE_DRIFT_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_COMMON */
#ifdef MAVLINK_ENABLED_COMMON
#undef MAVLINK_ENABLED_COMMON
#endif
#define MAVLINK_ENABLED_COMMON 1

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING
#undef MAVLINK_MSG_ID_ADAP_TUNING
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING 1

#endif /* _AP_CONFIG_H_ */
