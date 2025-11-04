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

/* ConfigFuzz Test #121 */

/* ConfigFuzz: AP_PERIPH_MAG_ENABLED */
#ifdef AP_PERIPH_MAG_ENABLED
#undef AP_PERIPH_MAG_ENABLED
#endif
#define AP_PERIPH_MAG_ENABLED 0

/* ConfigFuzz: HAL_INS_HIGHRES_SAMPLE */
#ifdef HAL_INS_HIGHRES_SAMPLE
#undef HAL_INS_HIGHRES_SAMPLE
#endif
#define HAL_INS_HIGHRES_SAMPLE 0

/* ConfigFuzz: HAL_USB_PRODUCT_ID */
#ifdef HAL_USB_PRODUCT_ID
#undef HAL_USB_PRODUCT_ID
#endif
#define HAL_USB_PRODUCT_ID 1

/* ConfigFuzz: AP_WINCH_ENABLED */
#ifdef AP_WINCH_ENABLED
#undef AP_WINCH_ENABLED
#endif
#define AP_WINCH_ENABLED 1

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 1

/* ConfigFuzz: HAL_WITH_IO_MCU_BIDIR_DSHOT */
#ifdef HAL_WITH_IO_MCU_BIDIR_DSHOT
#undef HAL_WITH_IO_MCU_BIDIR_DSHOT
#endif
#define HAL_WITH_IO_MCU_BIDIR_DSHOT 1

#endif /* _AP_CONFIG_H_ */
