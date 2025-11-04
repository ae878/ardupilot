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

/* ConfigFuzz Test #83 */

/* ConfigFuzz: HAL_DISABLE_ADC_DRIVER */
#ifdef HAL_DISABLE_ADC_DRIVER
#undef HAL_DISABLE_ADC_DRIVER
#endif
#define HAL_DISABLE_ADC_DRIVER 1

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_GZ */
#ifdef FSYNC_CONFIG_EXT_SYNC_GZ
#undef FSYNC_CONFIG_EXT_SYNC_GZ
#endif
#define FSYNC_CONFIG_EXT_SYNC_GZ 1

/* ConfigFuzz: HAL_BARO_NONE */
#ifdef HAL_BARO_NONE
#undef HAL_BARO_NONE
#endif
#define HAL_BARO_NONE 0

/* ConfigFuzz: MPUREG_CONFIG_EXT_SYNC_SHIFT */
#ifdef MPUREG_CONFIG_EXT_SYNC_SHIFT
#undef MPUREG_CONFIG_EXT_SYNC_SHIFT
#endif
#define MPUREG_CONFIG_EXT_SYNC_SHIFT 1

#endif /* _AP_CONFIG_H_ */
