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

/* ConfigFuzz Test #845 */

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 1

/* ConfigFuzz: HAL_WITH_RAMTRON */
#ifdef HAL_WITH_RAMTRON
#undef HAL_WITH_RAMTRON
#endif
#define HAL_WITH_RAMTRON 1

/* ConfigFuzz: BENCH_DEFINE_MAP_COUNT */
#ifdef BENCH_DEFINE_MAP_COUNT
#undef BENCH_DEFINE_MAP_COUNT
#endif
#define BENCH_DEFINE_MAP_COUNT 0

/* ConfigFuzz: HAL_USB_VENDOR_ID */
#ifdef HAL_USB_VENDOR_ID
#undef HAL_USB_VENDOR_ID
#endif
#define HAL_USB_VENDOR_ID 0

/* ConfigFuzz: HAL_FLASH_PROTECTION */
#ifdef HAL_FLASH_PROTECTION
#undef HAL_FLASH_PROTECTION
#endif
#define HAL_FLASH_PROTECTION 1

/* ConfigFuzz: AP_SOCKET_NATIVE_ENABLED */
#ifdef AP_SOCKET_NATIVE_ENABLED
#undef AP_SOCKET_NATIVE_ENABLED
#endif
#define AP_SOCKET_NATIVE_ENABLED 0

#endif /* _AP_CONFIG_H_ */
