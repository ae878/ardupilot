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

/* ConfigFuzz Test #396 */

/* ConfigFuzz: AP_FOLLOW_ENABLED */
#ifdef AP_FOLLOW_ENABLED
#undef AP_FOLLOW_ENABLED
#endif
#define AP_FOLLOW_ENABLED 0

/* ConfigFuzz: AP_SCHEDULER_OVERTIME_MARGIN_US */
#ifdef AP_SCHEDULER_OVERTIME_MARGIN_US
#undef AP_SCHEDULER_OVERTIME_MARGIN_US
#endif
#define AP_SCHEDULER_OVERTIME_MARGIN_US 1

/* ConfigFuzz: HAL_SOLO_GIMBAL_ENABLED */
#ifdef HAL_SOLO_GIMBAL_ENABLED
#undef HAL_SOLO_GIMBAL_ENABLED
#endif
#define HAL_SOLO_GIMBAL_ENABLED 1

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_RTL */
#ifdef FS_GCS_ENABLED_ALWAYS_RTL
#undef FS_GCS_ENABLED_ALWAYS_RTL
#endif
#define FS_GCS_ENABLED_ALWAYS_RTL 1

#endif /* _AP_CONFIG_H_ */
