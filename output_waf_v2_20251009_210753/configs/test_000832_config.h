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

/* ConfigFuzz Test #832 */

/* ConfigFuzz: HAL_RCOUT_RGBLED_RED */
#ifdef HAL_RCOUT_RGBLED_RED
#undef HAL_RCOUT_RGBLED_RED
#endif
#define HAL_RCOUT_RGBLED_RED 1

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 0

/* ConfigFuzz: AP_GRIPPER_ENABLED */
#ifdef AP_GRIPPER_ENABLED
#undef AP_GRIPPER_ENABLED
#endif
#define AP_GRIPPER_ENABLED 1

/* ConfigFuzz: MODE_SPORT_ENABLED */
#ifdef MODE_SPORT_ENABLED
#undef MODE_SPORT_ENABLED
#endif
#define MODE_SPORT_ENABLED 0

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 0

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 0

/* ConfigFuzz: MODE_AUTOROTATE_ENABLED */
#ifdef MODE_AUTOROTATE_ENABLED
#undef MODE_AUTOROTATE_ENABLED
#endif
#define MODE_AUTOROTATE_ENABLED 0

/* ConfigFuzz: HAL_USE_WSPI_DEFAULT_CFG */
#ifdef HAL_USE_WSPI_DEFAULT_CFG
#undef HAL_USE_WSPI_DEFAULT_CFG
#endif
#define HAL_USE_WSPI_DEFAULT_CFG 0

#endif /* _AP_CONFIG_H_ */
