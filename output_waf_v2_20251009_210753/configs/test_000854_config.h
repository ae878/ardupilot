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

/* ConfigFuzz Test #854 */

/* ConfigFuzz: AP_SIGNED_FIRMWARE */
#ifdef AP_SIGNED_FIRMWARE
#undef AP_SIGNED_FIRMWARE
#endif
#define AP_SIGNED_FIRMWARE 0

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 0

/* ConfigFuzz: HAL_BARO_EXTERNAL_BUS_DEFAULT */
#ifdef HAL_BARO_EXTERNAL_BUS_DEFAULT
#undef HAL_BARO_EXTERNAL_BUS_DEFAULT
#endif
#define HAL_BARO_EXTERNAL_BUS_DEFAULT 0

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

/* ConfigFuzz: HAL_LOGGING_ENABLED */
#ifdef HAL_LOGGING_ENABLED
#undef HAL_LOGGING_ENABLED
#endif
#define HAL_LOGGING_ENABLED 1

/* ConfigFuzz: AP_RELAY_ENABLED */
#ifdef AP_RELAY_ENABLED
#undef AP_RELAY_ENABLED
#endif
#define AP_RELAY_ENABLED 0

#endif /* _AP_CONFIG_H_ */
