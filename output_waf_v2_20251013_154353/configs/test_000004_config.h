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

/* ConfigFuzz Test #4 */

/* ConfigFuzz: MODE_ZIGZAG_ENABLED */
#ifdef MODE_ZIGZAG_ENABLED
#undef MODE_ZIGZAG_ENABLED
#endif
#define MODE_ZIGZAG_ENABLED 1

/* ConfigFuzz: FFT_MAX_MISSED_UPDATES */
#ifdef FFT_MAX_MISSED_UPDATES
#undef FFT_MAX_MISSED_UPDATES
#endif
#define FFT_MAX_MISSED_UPDATES 1

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 0

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 0

/* ConfigFuzz: FSYNC_CONFIG_EXT_SYNC_AY */
#ifdef FSYNC_CONFIG_EXT_SYNC_AY
#undef FSYNC_CONFIG_EXT_SYNC_AY
#endif
#define FSYNC_CONFIG_EXT_SYNC_AY 0

/* ConfigFuzz: HAL_GCS_ENABLED */
#ifdef HAL_GCS_ENABLED
#undef HAL_GCS_ENABLED
#endif
#define HAL_GCS_ENABLED 0

#endif /* _AP_CONFIG_H_ */
