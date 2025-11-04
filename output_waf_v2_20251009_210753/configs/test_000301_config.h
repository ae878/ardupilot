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

/* ConfigFuzz Test #301 */

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 1

/* ConfigFuzz: AP_RANGEFINDER_MSP_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_MSP_TIMEOUT_MS
#undef AP_RANGEFINDER_MSP_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_MSP_TIMEOUT_MS 0

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING_CRC */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#undef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING_CRC 1

/* ConfigFuzz: KDECAN_MAX_NUM_ESCS */
#ifdef KDECAN_MAX_NUM_ESCS
#undef KDECAN_MAX_NUM_ESCS
#endif
#define KDECAN_MAX_NUM_ESCS 8

/* ConfigFuzz: AP_FEATURE_RTSCTS */
#ifdef AP_FEATURE_RTSCTS
#undef AP_FEATURE_RTSCTS
#endif
#define AP_FEATURE_RTSCTS 0

/* ConfigFuzz: AP_CAMERA_ENABLED */
#ifdef AP_CAMERA_ENABLED
#undef AP_CAMERA_ENABLED
#endif
#define AP_CAMERA_ENABLED 1

#endif /* _AP_CONFIG_H_ */
