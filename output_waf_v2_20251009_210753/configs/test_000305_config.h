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

/* ConfigFuzz Test #305 */

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 4

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

/* ConfigFuzz: BENCH_DEFINE_MAP_IMPLICIT */
#ifdef BENCH_DEFINE_MAP_IMPLICIT
#undef BENCH_DEFINE_MAP_IMPLICIT
#endif
#define BENCH_DEFINE_MAP_IMPLICIT 0

/* ConfigFuzz: HAL_IMUHEAT_P_DEFAULT */
#ifdef HAL_IMUHEAT_P_DEFAULT
#undef HAL_IMUHEAT_P_DEFAULT
#endif
#define HAL_IMUHEAT_P_DEFAULT 1

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 0

/* ConfigFuzz: MAVLINK_ENABLED_DEVELOPMENT */
#ifdef MAVLINK_ENABLED_DEVELOPMENT
#undef MAVLINK_ENABLED_DEVELOPMENT
#endif
#define MAVLINK_ENABLED_DEVELOPMENT 0

#endif /* _AP_CONFIG_H_ */
