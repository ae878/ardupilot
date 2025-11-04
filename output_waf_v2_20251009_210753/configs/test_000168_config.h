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

/* ConfigFuzz Test #168 */

/* ConfigFuzz: MODE_GUIDED_ENABLED */
#ifdef MODE_GUIDED_ENABLED
#undef MODE_GUIDED_ENABLED
#endif
#define MODE_GUIDED_ENABLED 1

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 1

/* ConfigFuzz: AP_RANGEFINDER_LUA_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_LUA_TIMEOUT_MS
#undef AP_RANGEFINDER_LUA_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_LUA_TIMEOUT_MS 1

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING
#undef MAVLINK_MSG_ID_ADAP_TUNING
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING 1

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 1

#endif /* _AP_CONFIG_H_ */
