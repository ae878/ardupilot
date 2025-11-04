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

/* ConfigFuzz Test #465 */

/* ConfigFuzz: AP_AIS_ENABLED */
#ifdef AP_AIS_ENABLED
#undef AP_AIS_ENABLED
#endif
#define AP_AIS_ENABLED 1

/* ConfigFuzz: AP_EXTERNAL_CONTROL_ENABLED */
#ifdef AP_EXTERNAL_CONTROL_ENABLED
#undef AP_EXTERNAL_CONTROL_ENABLED
#endif
#define AP_EXTERNAL_CONTROL_ENABLED 1

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC 1

/* ConfigFuzz: HAL_BATT_CURR_PIN */
#ifdef HAL_BATT_CURR_PIN
#undef HAL_BATT_CURR_PIN
#endif
#define HAL_BATT_CURR_PIN 1

/* ConfigFuzz: MAVLINK_ENABLED_COMMON */
#ifdef MAVLINK_ENABLED_COMMON
#undef MAVLINK_ENABLED_COMMON
#endif
#define MAVLINK_ENABLED_COMMON 1

#endif /* _AP_CONFIG_H_ */
