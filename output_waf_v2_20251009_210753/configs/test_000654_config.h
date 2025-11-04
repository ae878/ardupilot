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

/* ConfigFuzz Test #654 */

/* ConfigFuzz: HAL_WITH_MCU_MONITORING */
#ifdef HAL_WITH_MCU_MONITORING
#undef HAL_WITH_MCU_MONITORING
#endif
#define HAL_WITH_MCU_MONITORING 0

/* ConfigFuzz: HAL_USE_WSPI_DEFAULT_CFG */
#ifdef HAL_USE_WSPI_DEFAULT_CFG
#undef HAL_USE_WSPI_DEFAULT_CFG
#endif
#define HAL_USE_WSPI_DEFAULT_CFG 0

/* ConfigFuzz: HAL_DEFAULT_INS_FAST_SAMPLE */
#ifdef HAL_DEFAULT_INS_FAST_SAMPLE
#undef HAL_DEFAULT_INS_FAST_SAMPLE
#endif
#define HAL_DEFAULT_INS_FAST_SAMPLE 1

/* ConfigFuzz: MAXSONAR_SERIAL_LV_BAUD_RATE */
#ifdef MAXSONAR_SERIAL_LV_BAUD_RATE
#undef MAXSONAR_SERIAL_LV_BAUD_RATE
#endif
#define MAXSONAR_SERIAL_LV_BAUD_RATE 16

#endif /* _AP_CONFIG_H_ */
