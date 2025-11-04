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

/* ConfigFuzz Test #384 */

/* ConfigFuzz: AP_MISSION_ENABLED */
#ifdef AP_MISSION_ENABLED
#undef AP_MISSION_ENABLED
#endif
#define AP_MISSION_ENABLED 0

/* ConfigFuzz: AP_COMPASS_OFFSETS_MAX_DEFAULT */
#ifdef AP_COMPASS_OFFSETS_MAX_DEFAULT
#undef AP_COMPASS_OFFSETS_MAX_DEFAULT
#endif
#define AP_COMPASS_OFFSETS_MAX_DEFAULT 2

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 8

/* ConfigFuzz: HAL_HNF_MAX_FILTERS */
#ifdef HAL_HNF_MAX_FILTERS
#undef HAL_HNF_MAX_FILTERS
#endif
#define HAL_HNF_MAX_FILTERS 4

/* ConfigFuzz: HAL_WITH_MCU_MONITORING */
#ifdef HAL_WITH_MCU_MONITORING
#undef HAL_WITH_MCU_MONITORING
#endif
#define HAL_WITH_MCU_MONITORING 0

#endif /* _AP_CONFIG_H_ */
