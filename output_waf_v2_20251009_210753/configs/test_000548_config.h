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

/* ConfigFuzz Test #548 */

/* ConfigFuzz: MODE_DRIFT_ENABLED */
#ifdef MODE_DRIFT_ENABLED
#undef MODE_DRIFT_ENABLED
#endif
#define MODE_DRIFT_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC_CRC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC_CRC 0

/* ConfigFuzz: AP_AIS_ENABLED */
#ifdef AP_AIS_ENABLED
#undef AP_AIS_ENABLED
#endif
#define AP_AIS_ENABLED 1

/* ConfigFuzz: HAL_NUM_CAN_IFACES */
#ifdef HAL_NUM_CAN_IFACES
#undef HAL_NUM_CAN_IFACES
#endif
#define HAL_NUM_CAN_IFACES 1

#endif /* _AP_CONFIG_H_ */
