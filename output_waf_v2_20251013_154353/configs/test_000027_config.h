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

/* ConfigFuzz Test #27 */

/* ConfigFuzz: BACKEND_SAMPLE_RATE_MAX */
#ifdef BACKEND_SAMPLE_RATE_MAX
#undef BACKEND_SAMPLE_RATE_MAX
#endif
#define BACKEND_SAMPLE_RATE_MAX 1

/* ConfigFuzz: MPUREG_GYRO_CONFIG */
#ifdef MPUREG_GYRO_CONFIG
#undef MPUREG_GYRO_CONFIG
#endif
#define MPUREG_GYRO_CONFIG 0

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC_CRC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC_CRC 1

#endif /* _AP_CONFIG_H_ */
