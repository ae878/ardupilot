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

/* ConfigFuzz Test #262 */

/* ConfigFuzz: MODE_CIRCLE_ENABLED */
#ifdef MODE_CIRCLE_ENABLED
#undef MODE_CIRCLE_ENABLED
#endif
#define MODE_CIRCLE_ENABLED 0

/* ConfigFuzz: AP_SCHEDULER_OVERTIME_MARGIN_US */
#ifdef AP_SCHEDULER_OVERTIME_MARGIN_US
#undef AP_SCHEDULER_OVERTIME_MARGIN_US
#endif
#define AP_SCHEDULER_OVERTIME_MARGIN_US 1

/* ConfigFuzz: FS_THR_ENABLED_BRAKE_OR_LAND */
#ifdef FS_THR_ENABLED_BRAKE_OR_LAND
#undef FS_THR_ENABLED_BRAKE_OR_LAND
#endif
#define FS_THR_ENABLED_BRAKE_OR_LAND 0

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

/* ConfigFuzz: AP_AIRSPEED_ENABLED */
#ifdef AP_AIRSPEED_ENABLED
#undef AP_AIRSPEED_ENABLED
#endif
#define AP_AIRSPEED_ENABLED 0

#endif /* _AP_CONFIG_H_ */
