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

/* ConfigFuzz Test #96 */

/* ConfigFuzz: HAL_INS_HIGHRES_SAMPLE */
#ifdef HAL_INS_HIGHRES_SAMPLE
#undef HAL_INS_HIGHRES_SAMPLE
#endif
#define HAL_INS_HIGHRES_SAMPLE 0

/* ConfigFuzz: MPUREG_CONFIG_EXT_SYNC_GY */
#ifdef MPUREG_CONFIG_EXT_SYNC_GY
#undef MPUREG_CONFIG_EXT_SYNC_GY
#endif
#define MPUREG_CONFIG_EXT_SYNC_GY 0

/* ConfigFuzz: HAL_NO_FLASH_SUPPORT */
#ifdef HAL_NO_FLASH_SUPPORT
#undef HAL_NO_FLASH_SUPPORT
#endif
#define HAL_NO_FLASH_SUPPORT 1

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING_CRC */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#undef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING_CRC 0

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 1

/* ConfigFuzz: AP_FEATURE_SBUS_OUT */
#ifdef AP_FEATURE_SBUS_OUT
#undef AP_FEATURE_SBUS_OUT
#endif
#define AP_FEATURE_SBUS_OUT 1

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_TEMP */
#ifdef FSYNC_CONFIG_EXT_SYNC_TEMP
#undef FSYNC_CONFIG_EXT_SYNC_TEMP
#endif
#define FSYNC_CONFIG_EXT_SYNC_TEMP 0

#endif /* _AP_CONFIG_H_ */
