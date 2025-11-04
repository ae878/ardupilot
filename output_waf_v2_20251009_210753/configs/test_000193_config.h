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

/* ConfigFuzz Test #193 */

/* ConfigFuzz: MAXSONAR_SERIAL_LV_BAUD_RATE */
#ifdef MAXSONAR_SERIAL_LV_BAUD_RATE
#undef MAXSONAR_SERIAL_LV_BAUD_RATE
#endif
#define MAXSONAR_SERIAL_LV_BAUD_RATE 8

/* ConfigFuzz: RC_INPUT_MAX_PULSEWIDTH */
#ifdef RC_INPUT_MAX_PULSEWIDTH
#undef RC_INPUT_MAX_PULSEWIDTH
#endif
#define RC_INPUT_MAX_PULSEWIDTH 8

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 16

/* ConfigFuzz: AUTOTUNE_ENABLED */
#ifdef AUTOTUNE_ENABLED
#undef AUTOTUNE_ENABLED
#endif
#define AUTOTUNE_ENABLED 1

/* ConfigFuzz: CONFIG_LWIP_PPP_SUPPORT */
#ifdef CONFIG_LWIP_PPP_SUPPORT
#undef CONFIG_LWIP_PPP_SUPPORT
#endif
#define CONFIG_LWIP_PPP_SUPPORT 0

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 1

#endif /* _AP_CONFIG_H_ */
