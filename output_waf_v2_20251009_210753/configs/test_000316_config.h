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

/* ConfigFuzz Test #316 */

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 1

/* ConfigFuzz: HAL_USB_VENDOR_ID */
#ifdef HAL_USB_VENDOR_ID
#undef HAL_USB_VENDOR_ID
#endif
#define HAL_USB_VENDOR_ID 1

/* ConfigFuzz: HAL_GENERATOR_ENABLED */
#ifdef HAL_GENERATOR_ENABLED
#undef HAL_GENERATOR_ENABLED
#endif
#define HAL_GENERATOR_ENABLED 0

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

#endif /* _AP_CONFIG_H_ */
