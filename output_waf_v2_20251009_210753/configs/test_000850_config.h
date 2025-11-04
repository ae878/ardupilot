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

/* ConfigFuzz Test #850 */

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 1

/* ConfigFuzz: HAL_COMPASS_AUTO_ROT_DEFAULT */
#ifdef HAL_COMPASS_AUTO_ROT_DEFAULT
#undef HAL_COMPASS_AUTO_ROT_DEFAULT
#endif
#define HAL_COMPASS_AUTO_ROT_DEFAULT 0

/* ConfigFuzz: AUTOTUNE_ENABLED */
#ifdef AUTOTUNE_ENABLED
#undef AUTOTUNE_ENABLED
#endif
#define AUTOTUNE_ENABLED 1

/* ConfigFuzz: FS_THR_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#undef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_THR_ENABLED_AUTO_RTL_OR_RTL 1

#endif /* _AP_CONFIG_H_ */
