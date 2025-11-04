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

/* ConfigFuzz Test #196 */

/* ConfigFuzz: AP_SCHEDULER_OVERTIME_MARGIN_US */
#ifdef AP_SCHEDULER_OVERTIME_MARGIN_US
#undef AP_SCHEDULER_OVERTIME_MARGIN_US
#endif
#define AP_SCHEDULER_OVERTIME_MARGIN_US 0

/* ConfigFuzz: HAL_SPEKTRUM_TELEM_ENABLED */
#ifdef HAL_SPEKTRUM_TELEM_ENABLED
#undef HAL_SPEKTRUM_TELEM_ENABLED
#endif
#define HAL_SPEKTRUM_TELEM_ENABLED 0

/* ConfigFuzz: MODE_ZIGZAG_ENABLED */
#ifdef MODE_ZIGZAG_ENABLED
#undef MODE_ZIGZAG_ENABLED
#endif
#define MODE_ZIGZAG_ENABLED 1

/* ConfigFuzz: HAL_MOUNT_ENABLED */
#ifdef HAL_MOUNT_ENABLED
#undef HAL_MOUNT_ENABLED
#endif
#define HAL_MOUNT_ENABLED 1

#endif /* _AP_CONFIG_H_ */
