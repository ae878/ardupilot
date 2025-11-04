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

/* ConfigFuzz Test #84 */

/* ConfigFuzz: FLOW_CONTROL_ENABLED */
#ifdef FLOW_CONTROL_ENABLED
#undef FLOW_CONTROL_ENABLED
#endif
#define FLOW_CONTROL_ENABLED 0

/* ConfigFuzz: MODE_CIRCLE_ENABLED */
#ifdef MODE_CIRCLE_ENABLED
#undef MODE_CIRCLE_ENABLED
#endif
#define MODE_CIRCLE_ENABLED 1

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

/* ConfigFuzz: NOOPLOOP_DIST_MAX_MM */
#ifdef NOOPLOOP_DIST_MAX_MM
#undef NOOPLOOP_DIST_MAX_MM
#endif
#define NOOPLOOP_DIST_MAX_MM 8

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 1

/* ConfigFuzz: HAL_WITH_RAMTRON */
#ifdef HAL_WITH_RAMTRON
#undef HAL_WITH_RAMTRON
#endif
#define HAL_WITH_RAMTRON 0

/* ConfigFuzz: AP_ADVANCEDFAILSAFE_ENABLED */
#ifdef AP_ADVANCEDFAILSAFE_ENABLED
#undef AP_ADVANCEDFAILSAFE_ENABLED
#endif
#define AP_ADVANCEDFAILSAFE_ENABLED 0

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 0

#endif /* _AP_CONFIG_H_ */
