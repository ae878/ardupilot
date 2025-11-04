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

/* ConfigFuzz Test #85 */

/* ConfigFuzz: CONFIG_LWIP_PPP_SUPPORT */
#ifdef CONFIG_LWIP_PPP_SUPPORT
#undef CONFIG_LWIP_PPP_SUPPORT
#endif
#define CONFIG_LWIP_PPP_SUPPORT 1

/* ConfigFuzz: AP_FOLLOW_ENABLED */
#ifdef AP_FOLLOW_ENABLED
#undef AP_FOLLOW_ENABLED
#endif
#define AP_FOLLOW_ENABLED 1

/* ConfigFuzz: RC_INPUT_MAX_PULSEWIDTH */
#ifdef RC_INPUT_MAX_PULSEWIDTH
#undef RC_INPUT_MAX_PULSEWIDTH
#endif
#define RC_INPUT_MAX_PULSEWIDTH 16

/* ConfigFuzz: FFT_MAX_MISSED_UPDATES */
#ifdef FFT_MAX_MISSED_UPDATES
#undef FFT_MAX_MISSED_UPDATES
#endif
#define FFT_MAX_MISSED_UPDATES 1

/* ConfigFuzz: HAL_DISABLE_ADC_DRIVER */
#ifdef HAL_DISABLE_ADC_DRIVER
#undef HAL_DISABLE_ADC_DRIVER
#endif
#define HAL_DISABLE_ADC_DRIVER 1

#endif /* _AP_CONFIG_H_ */
