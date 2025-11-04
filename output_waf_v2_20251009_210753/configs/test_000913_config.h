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

/* ConfigFuzz Test #913 */

/* ConfigFuzz: MAVLINK_ENABLED_ALL */
#ifdef MAVLINK_ENABLED_ALL
#undef MAVLINK_ENABLED_ALL
#endif
#define MAVLINK_ENABLED_ALL 1

/* ConfigFuzz: HAVE_ENUM_CAMERA_CAP_FLAGS */
#ifdef HAVE_ENUM_CAMERA_CAP_FLAGS
#undef HAVE_ENUM_CAMERA_CAP_FLAGS
#endif
#define HAVE_ENUM_CAMERA_CAP_FLAGS 0

/* ConfigFuzz: HAL_AHRS_EKF_TYPE_DEFAULT */
#ifdef HAL_AHRS_EKF_TYPE_DEFAULT
#undef HAL_AHRS_EKF_TYPE_DEFAULT
#endif
#define HAL_AHRS_EKF_TYPE_DEFAULT 0

/* ConfigFuzz: TELEM_TIME_SLOT_MAX */
#ifdef TELEM_TIME_SLOT_MAX
#undef TELEM_TIME_SLOT_MAX
#endif
#define TELEM_TIME_SLOT_MAX 4

#endif /* _AP_CONFIG_H_ */
