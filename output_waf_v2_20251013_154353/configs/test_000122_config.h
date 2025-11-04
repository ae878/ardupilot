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

/* ConfigFuzz Test #122 */

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 1

/* ConfigFuzz: FFT_MAX_MISSED_UPDATES */
#ifdef FFT_MAX_MISSED_UPDATES
#undef FFT_MAX_MISSED_UPDATES
#endif
#define FFT_MAX_MISSED_UPDATES 1

/* ConfigFuzz: MODE_SPORT_ENABLED */
#ifdef MODE_SPORT_ENABLED
#undef MODE_SPORT_ENABLED
#endif
#define MODE_SPORT_ENABLED 1

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 0

/* ConfigFuzz: MODE_GUIDED_NOGPS_ENABLED */
#ifdef MODE_GUIDED_NOGPS_ENABLED
#undef MODE_GUIDED_NOGPS_ENABLED
#endif
#define MODE_GUIDED_NOGPS_ENABLED 1

/* ConfigFuzz: BACKEND_SAMPLE_RATE_MAX */
#ifdef BACKEND_SAMPLE_RATE_MAX
#undef BACKEND_SAMPLE_RATE_MAX
#endif
#define BACKEND_SAMPLE_RATE_MAX 16

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 0

#endif /* _AP_CONFIG_H_ */
