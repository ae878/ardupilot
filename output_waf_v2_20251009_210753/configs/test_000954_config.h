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

/* ConfigFuzz Test #954 */

/* ConfigFuzz: HAL_FLASH_PROTECTION */
#ifdef HAL_FLASH_PROTECTION
#undef HAL_FLASH_PROTECTION
#endif
#define HAL_FLASH_PROTECTION 1

/* ConfigFuzz: HAL_DEFAULT_INS_FAST_SAMPLE */
#ifdef HAL_DEFAULT_INS_FAST_SAMPLE
#undef HAL_DEFAULT_INS_FAST_SAMPLE
#endif
#define HAL_DEFAULT_INS_FAST_SAMPLE 0

/* ConfigFuzz: HAL_HAVE_HARDWARE_DOUBLE */
#ifdef HAL_HAVE_HARDWARE_DOUBLE
#undef HAL_HAVE_HARDWARE_DOUBLE
#endif
#define HAL_HAVE_HARDWARE_DOUBLE 0

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 0

#endif /* _AP_CONFIG_H_ */
