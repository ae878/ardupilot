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

/* ConfigFuzz Test #658 */

/* ConfigFuzz: AP_SCHEDULER_OVERTIME_MARGIN_US */
#ifdef AP_SCHEDULER_OVERTIME_MARGIN_US
#undef AP_SCHEDULER_OVERTIME_MARGIN_US
#endif
#define AP_SCHEDULER_OVERTIME_MARGIN_US 1

/* ConfigFuzz: HAL_RCOUT_RGBLED_BLUE */
#ifdef HAL_RCOUT_RGBLED_BLUE
#undef HAL_RCOUT_RGBLED_BLUE
#endif
#define HAL_RCOUT_RGBLED_BLUE 1

/* ConfigFuzz: MODE_FLIP_ENABLED */
#ifdef MODE_FLIP_ENABLED
#undef MODE_FLIP_ENABLED
#endif
#define MODE_FLIP_ENABLED 0

/* ConfigFuzz: HAL_WITH_RAMTRON */
#ifdef HAL_WITH_RAMTRON
#undef HAL_WITH_RAMTRON
#endif
#define HAL_WITH_RAMTRON 1

/* ConfigFuzz: HAL_HAVE_SAFETY_SWITCH */
#ifdef HAL_HAVE_SAFETY_SWITCH
#undef HAL_HAVE_SAFETY_SWITCH
#endif
#define HAL_HAVE_SAFETY_SWITCH 1

/* ConfigFuzz: HAL_FLASH_ALLOW_UPDATE */
#ifdef HAL_FLASH_ALLOW_UPDATE
#undef HAL_FLASH_ALLOW_UPDATE
#endif
#define HAL_FLASH_ALLOW_UPDATE 0

#endif /* _AP_CONFIG_H_ */
