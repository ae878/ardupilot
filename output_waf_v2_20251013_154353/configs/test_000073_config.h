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

/* ConfigFuzz Test #73 */

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 1

/* ConfigFuzz: HAL_USE_WSPI_DEFAULT_CFG */
#ifdef HAL_USE_WSPI_DEFAULT_CFG
#undef HAL_USE_WSPI_DEFAULT_CFG
#endif
#define HAL_USE_WSPI_DEFAULT_CFG 0

/* ConfigFuzz: AP_PERIPH_RTC_ENABLED */
#ifdef AP_PERIPH_RTC_ENABLED
#undef AP_PERIPH_RTC_ENABLED
#endif
#define AP_PERIPH_RTC_ENABLED 0

/* ConfigFuzz: AP_DEVO_TELEM_ENABLED */
#ifdef AP_DEVO_TELEM_ENABLED
#undef AP_DEVO_TELEM_ENABLED
#endif
#define AP_DEVO_TELEM_ENABLED 0

/* ConfigFuzz: MODE_BRAKE_ENABLED */
#ifdef MODE_BRAKE_ENABLED
#undef MODE_BRAKE_ENABLED
#endif
#define MODE_BRAKE_ENABLED 0

/* ConfigFuzz: HAL_GCS_ENABLED */
#ifdef HAL_GCS_ENABLED
#undef HAL_GCS_ENABLED
#endif
#define HAL_GCS_ENABLED 1

#endif /* _AP_CONFIG_H_ */
