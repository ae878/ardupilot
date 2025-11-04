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

/* ConfigFuzz Test #608 */

/* ConfigFuzz: HAL_WITH_UAVCAN */
#ifdef HAL_WITH_UAVCAN
#undef HAL_WITH_UAVCAN
#endif
#define HAL_WITH_UAVCAN 1

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL */
#ifdef FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL
#undef FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL
#endif
#define FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_RTL 0

/* ConfigFuzz: HAL_BARO_NONE */
#ifdef HAL_BARO_NONE
#undef HAL_BARO_NONE
#endif
#define HAL_BARO_NONE 1

/* ConfigFuzz: AP_SERIALMANAGER_ENABLED */
#ifdef AP_SERIALMANAGER_ENABLED
#undef AP_SERIALMANAGER_ENABLED
#endif
#define AP_SERIALMANAGER_ENABLED 1

#endif /* _AP_CONFIG_H_ */
