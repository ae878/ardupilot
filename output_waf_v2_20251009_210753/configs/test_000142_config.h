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

/* ConfigFuzz Test #142 */

/* ConfigFuzz: MAVLINK_ENABLED_ALL */
#ifdef MAVLINK_ENABLED_ALL
#undef MAVLINK_ENABLED_ALL
#endif
#define MAVLINK_ENABLED_ALL 0

/* ConfigFuzz: AUTOTUNE_ENABLED */
#ifdef AUTOTUNE_ENABLED
#undef AUTOTUNE_ENABLED
#endif
#define AUTOTUNE_ENABLED 1

/* ConfigFuzz: HAL_BUTTON_ENABLED */
#ifdef HAL_BUTTON_ENABLED
#undef HAL_BUTTON_ENABLED
#endif
#define HAL_BUTTON_ENABLED 0

/* ConfigFuzz: HAL_AHRS_EKF_TYPE_DEFAULT */
#ifdef HAL_AHRS_EKF_TYPE_DEFAULT
#undef HAL_AHRS_EKF_TYPE_DEFAULT
#endif
#define HAL_AHRS_EKF_TYPE_DEFAULT 0

#endif /* _AP_CONFIG_H_ */
