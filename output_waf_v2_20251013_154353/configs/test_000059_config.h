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

/* ConfigFuzz Test #59 */

/* ConfigFuzz: BENCH_DEFINE_MAP_IMPLICIT */
#ifdef BENCH_DEFINE_MAP_IMPLICIT
#undef BENCH_DEFINE_MAP_IMPLICIT
#endif
#define BENCH_DEFINE_MAP_IMPLICIT 0

/* ConfigFuzz: HAL_USB_VENDOR_ID */
#ifdef HAL_USB_VENDOR_ID
#undef HAL_USB_VENDOR_ID
#endif
#define HAL_USB_VENDOR_ID 1

/* ConfigFuzz: AP_RC_CHANNEL_ENABLED */
#ifdef AP_RC_CHANNEL_ENABLED
#undef AP_RC_CHANNEL_ENABLED
#endif
#define AP_RC_CHANNEL_ENABLED 1

/* ConfigFuzz: HAL_SOLO_GIMBAL_ENABLED */
#ifdef HAL_SOLO_GIMBAL_ENABLED
#undef HAL_SOLO_GIMBAL_ENABLED
#endif
#define HAL_SOLO_GIMBAL_ENABLED 1

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_LAND */
#ifdef FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_LAND
#undef FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_LAND
#endif
#define FS_GCS_ENABLED_ALWAYS_SMARTRTL_OR_LAND 1

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

#endif /* _AP_CONFIG_H_ */
