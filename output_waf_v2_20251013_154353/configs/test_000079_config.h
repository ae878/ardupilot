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

/* ConfigFuzz Test #79 */

/* ConfigFuzz: AP_PERIPH_BATTERY_BALANCE_ENABLED */
#ifdef AP_PERIPH_BATTERY_BALANCE_ENABLED
#undef AP_PERIPH_BATTERY_BALANCE_ENABLED
#endif
#define AP_PERIPH_BATTERY_BALANCE_ENABLED 0

/* ConfigFuzz: AP_PERIPH_AIRSPEED_ENABLED */
#ifdef AP_PERIPH_AIRSPEED_ENABLED
#undef AP_PERIPH_AIRSPEED_ENABLED
#endif
#define AP_PERIPH_AIRSPEED_ENABLED 0

/* ConfigFuzz: HAL_USE_SDMMC */
#ifdef HAL_USE_SDMMC
#undef HAL_USE_SDMMC
#endif
#define HAL_USE_SDMMC 1

#endif /* _AP_CONFIG_H_ */
