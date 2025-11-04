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

/* ConfigFuzz Test #413 */

/* ConfigFuzz: HAL_COMPASS_AUTO_ROT_DEFAULT */
#ifdef HAL_COMPASS_AUTO_ROT_DEFAULT
#undef HAL_COMPASS_AUTO_ROT_DEFAULT
#endif
#define HAL_COMPASS_AUTO_ROT_DEFAULT 0

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 0

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC 0

/* ConfigFuzz: AP_RANGEFINDER_LUA_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_LUA_TIMEOUT_MS
#undef AP_RANGEFINDER_LUA_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_LUA_TIMEOUT_MS 0

#endif /* _AP_CONFIG_H_ */
