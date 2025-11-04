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

/* ConfigFuzz Test #41 */

/* ConfigFuzz: HAL_IMUHEAT_P_DEFAULT */
#ifdef HAL_IMUHEAT_P_DEFAULT
#undef HAL_IMUHEAT_P_DEFAULT
#endif
#define HAL_IMUHEAT_P_DEFAULT 0

/* ConfigFuzz: HAL_WITH_RAMTRON */
#ifdef HAL_WITH_RAMTRON
#undef HAL_WITH_RAMTRON
#endif
#define HAL_WITH_RAMTRON 0

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

#endif /* _AP_CONFIG_H_ */
