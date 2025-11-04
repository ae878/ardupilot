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

/* ConfigFuzz Test #727 */

/* ConfigFuzz: HAL_WITH_SPI_RAMTRON */
#ifdef HAL_WITH_SPI_RAMTRON
#undef HAL_WITH_SPI_RAMTRON
#endif
#define HAL_WITH_SPI_RAMTRON 0

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 1

/* ConfigFuzz: HAL_AHRS_EKF_TYPE_DEFAULT */
#ifdef HAL_AHRS_EKF_TYPE_DEFAULT
#undef HAL_AHRS_EKF_TYPE_DEFAULT
#endif
#define HAL_AHRS_EKF_TYPE_DEFAULT 0

/* ConfigFuzz: ESC_CHANNEL_MAP_CHANNEL */
#ifdef ESC_CHANNEL_MAP_CHANNEL
#undef ESC_CHANNEL_MAP_CHANNEL
#endif
#define ESC_CHANNEL_MAP_CHANNEL 1

#endif /* _AP_CONFIG_H_ */
