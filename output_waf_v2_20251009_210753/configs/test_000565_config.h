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

/* ConfigFuzz Test #565 */

/* ConfigFuzz: AP_OPTICALFLOW_ENABLED */
#ifdef AP_OPTICALFLOW_ENABLED
#undef AP_OPTICALFLOW_ENABLED
#endif
#define AP_OPTICALFLOW_ENABLED 0

/* ConfigFuzz: HAL_FLASH_PROTECTION */
#ifdef HAL_FLASH_PROTECTION
#undef HAL_FLASH_PROTECTION
#endif
#define HAL_FLASH_PROTECTION 0

/* ConfigFuzz: HAL_WITH_IO_MCU */
#ifdef HAL_WITH_IO_MCU
#undef HAL_WITH_IO_MCU
#endif
#define HAL_WITH_IO_MCU 1

#endif /* _AP_CONFIG_H_ */
