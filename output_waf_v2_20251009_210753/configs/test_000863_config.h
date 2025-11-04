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

/* ConfigFuzz Test #863 */

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 1

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 1

/* ConfigFuzz: HAL_INS_RATE_LOOP */
#ifdef HAL_INS_RATE_LOOP
#undef HAL_INS_RATE_LOOP
#endif
#define HAL_INS_RATE_LOOP 0

/* ConfigFuzz: HAL_SPEKTRUM_TELEM_ENABLED */
#ifdef HAL_SPEKTRUM_TELEM_ENABLED
#undef HAL_SPEKTRUM_TELEM_ENABLED
#endif
#define HAL_SPEKTRUM_TELEM_ENABLED 0

#endif /* _AP_CONFIG_H_ */
