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

/* ConfigFuzz Test #842 */

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC 1

/* ConfigFuzz: MODE_BRAKE_ENABLED */
#ifdef MODE_BRAKE_ENABLED
#undef MODE_BRAKE_ENABLED
#endif
#define MODE_BRAKE_ENABLED 1

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING_CRC */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#undef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING_CRC 0

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 0

#endif /* _AP_CONFIG_H_ */
