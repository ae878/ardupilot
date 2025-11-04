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

/* ConfigFuzz Test #514 */

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 1

/* ConfigFuzz: AP_SRV_CHANNELS_ENABLED */
#ifdef AP_SRV_CHANNELS_ENABLED
#undef AP_SRV_CHANNELS_ENABLED
#endif
#define AP_SRV_CHANNELS_ENABLED 0

/* ConfigFuzz: HAL_USB_VENDOR_ID */
#ifdef HAL_USB_VENDOR_ID
#undef HAL_USB_VENDOR_ID
#endif
#define HAL_USB_VENDOR_ID 1

/* ConfigFuzz: HAL_LOGGING_ENABLED */
#ifdef HAL_LOGGING_ENABLED
#undef HAL_LOGGING_ENABLED
#endif
#define HAL_LOGGING_ENABLED 0

/* ConfigFuzz: HAL_COMPASS_AUTO_ROT_DEFAULT */
#ifdef HAL_COMPASS_AUTO_ROT_DEFAULT
#undef HAL_COMPASS_AUTO_ROT_DEFAULT
#endif
#define HAL_COMPASS_AUTO_ROT_DEFAULT 0

/* ConfigFuzz: HAL_WITH_MCU_MONITORING */
#ifdef HAL_WITH_MCU_MONITORING
#undef HAL_WITH_MCU_MONITORING
#endif
#define HAL_WITH_MCU_MONITORING 0

/* ConfigFuzz: AC_PRECLAND_ENABLED */
#ifdef AC_PRECLAND_ENABLED
#undef AC_PRECLAND_ENABLED
#endif
#define AC_PRECLAND_ENABLED 1

#endif /* _AP_CONFIG_H_ */
