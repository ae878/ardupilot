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

/* ConfigFuzz Test #42 */

/* ConfigFuzz: AP_FEATURE_RTSCTS */
#ifdef AP_FEATURE_RTSCTS
#undef AP_FEATURE_RTSCTS
#endif
#define AP_FEATURE_RTSCTS 0

/* ConfigFuzz: HAL_NO_ROMFS_SUPPORT */
#ifdef HAL_NO_ROMFS_SUPPORT
#undef HAL_NO_ROMFS_SUPPORT
#endif
#define HAL_NO_ROMFS_SUPPORT 1

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 1

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 1

/* ConfigFuzz: AP_TEMPCALIBRATION_ENABLED */
#ifdef AP_TEMPCALIBRATION_ENABLED
#undef AP_TEMPCALIBRATION_ENABLED
#endif
#define AP_TEMPCALIBRATION_ENABLED 1

/* ConfigFuzz: HAL_PERIPH_ENABLE_RC_OUT */
#ifdef HAL_PERIPH_ENABLE_RC_OUT
#undef HAL_PERIPH_ENABLE_RC_OUT
#endif
#define HAL_PERIPH_ENABLE_RC_OUT 1

/* ConfigFuzz: AP_RC_CHANNEL_ENABLED */
#ifdef AP_RC_CHANNEL_ENABLED
#undef AP_RC_CHANNEL_ENABLED
#endif
#define AP_RC_CHANNEL_ENABLED 0

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 1

#endif /* _AP_CONFIG_H_ */
