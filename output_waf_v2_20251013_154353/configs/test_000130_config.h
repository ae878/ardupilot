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

/* ConfigFuzz Test #130 */

/* ConfigFuzz: FS_GCS_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#undef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_GCS_ENABLED_AUTO_RTL_OR_RTL 1

/* ConfigFuzz: HAL_HEATER_GPIO_ON */
#ifdef HAL_HEATER_GPIO_ON
#undef HAL_HEATER_GPIO_ON
#endif
#define HAL_HEATER_GPIO_ON 1

/* ConfigFuzz: TELEM_TIME_SLOT_MAX */
#ifdef TELEM_TIME_SLOT_MAX
#undef TELEM_TIME_SLOT_MAX
#endif
#define TELEM_TIME_SLOT_MAX 1

#endif /* _AP_CONFIG_H_ */
