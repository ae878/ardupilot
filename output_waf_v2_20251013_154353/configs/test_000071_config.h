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

/* ConfigFuzz Test #71 */

/* ConfigFuzz: FS_THR_ENABLED_BRAKE_OR_LAND */
#ifdef FS_THR_ENABLED_BRAKE_OR_LAND
#undef FS_THR_ENABLED_BRAKE_OR_LAND
#endif
#define FS_THR_ENABLED_BRAKE_OR_LAND 0

/* ConfigFuzz: AP_PERIPH_MAG_ENABLED */
#ifdef AP_PERIPH_MAG_ENABLED
#undef AP_PERIPH_MAG_ENABLED
#endif
#define AP_PERIPH_MAG_ENABLED 0

/* ConfigFuzz: AP_PERIPH_BARO_ENABLED */
#ifdef AP_PERIPH_BARO_ENABLED
#undef AP_PERIPH_BARO_ENABLED
#endif
#define AP_PERIPH_BARO_ENABLED 0

#endif /* _AP_CONFIG_H_ */
