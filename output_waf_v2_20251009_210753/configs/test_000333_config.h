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

/* ConfigFuzz Test #333 */

/* ConfigFuzz: HAL_BARO_NONE */
#ifdef HAL_BARO_NONE
#undef HAL_BARO_NONE
#endif
#define HAL_BARO_NONE 0

/* ConfigFuzz: HAL_HEATER_GPIO_ON */
#ifdef HAL_HEATER_GPIO_ON
#undef HAL_HEATER_GPIO_ON
#endif
#define HAL_HEATER_GPIO_ON 0

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 1

#endif /* _AP_CONFIG_H_ */
