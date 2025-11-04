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

/* ConfigFuzz Test #967 */

/* ConfigFuzz: AP_COPTER_ADVANCED_FAILSAFE_ENABLED */
#ifdef AP_COPTER_ADVANCED_FAILSAFE_ENABLED
#undef AP_COPTER_ADVANCED_FAILSAFE_ENABLED
#endif
#define AP_COPTER_ADVANCED_FAILSAFE_ENABLED 0

/* ConfigFuzz: HAL_AHRS_EKF_TYPE_DEFAULT */
#ifdef HAL_AHRS_EKF_TYPE_DEFAULT
#undef HAL_AHRS_EKF_TYPE_DEFAULT
#endif
#define HAL_AHRS_EKF_TYPE_DEFAULT 1

/* ConfigFuzz: AP_FENCE_ENABLED */
#ifdef AP_FENCE_ENABLED
#undef AP_FENCE_ENABLED
#endif
#define AP_FENCE_ENABLED 1

/* ConfigFuzz: ESC_CHANNEL_MAP_CHANNEL */
#ifdef ESC_CHANNEL_MAP_CHANNEL
#undef ESC_CHANNEL_MAP_CHANNEL
#endif
#define ESC_CHANNEL_MAP_CHANNEL 1

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 1

#endif /* _AP_CONFIG_H_ */
