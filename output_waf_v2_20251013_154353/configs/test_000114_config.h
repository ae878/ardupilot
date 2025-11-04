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

/* ConfigFuzz Test #114 */

/* ConfigFuzz: AP_PERIPH_BATTERY_ENABLED */
#ifdef AP_PERIPH_BATTERY_ENABLED
#undef AP_PERIPH_BATTERY_ENABLED
#endif
#define AP_PERIPH_BATTERY_ENABLED 1

/* ConfigFuzz: MPUREG_CONFIG_EXT_SYNC_AX */
#ifdef MPUREG_CONFIG_EXT_SYNC_AX
#undef MPUREG_CONFIG_EXT_SYNC_AX
#endif
#define MPUREG_CONFIG_EXT_SYNC_AX 1

/* ConfigFuzz: HAL_INS_HIGHRES_SAMPLE */
#ifdef HAL_INS_HIGHRES_SAMPLE
#undef HAL_INS_HIGHRES_SAMPLE
#endif
#define HAL_INS_HIGHRES_SAMPLE 1

#endif /* _AP_CONFIG_H_ */
