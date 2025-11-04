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

/* ConfigFuzz Test #572 */

/* ConfigFuzz: MODE_BRAKE_ENABLED */
#ifdef MODE_BRAKE_ENABLED
#undef MODE_BRAKE_ENABLED
#endif
#define MODE_BRAKE_ENABLED 1

/* ConfigFuzz: HAL_WITH_SPI_RAMTRON */
#ifdef HAL_WITH_SPI_RAMTRON
#undef HAL_WITH_SPI_RAMTRON
#endif
#define HAL_WITH_SPI_RAMTRON 1

/* ConfigFuzz: AP_SIGNED_FIRMWARE */
#ifdef AP_SIGNED_FIRMWARE
#undef AP_SIGNED_FIRMWARE
#endif
#define AP_SIGNED_FIRMWARE 1

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 0

/* ConfigFuzz: MAVLINK_ENABLED_UAVIONIX */
#ifdef MAVLINK_ENABLED_UAVIONIX
#undef MAVLINK_ENABLED_UAVIONIX
#endif
#define MAVLINK_ENABLED_UAVIONIX 1

/* ConfigFuzz: AP_RANGEFINDER_MSP_TIMEOUT_MS */
#ifdef AP_RANGEFINDER_MSP_TIMEOUT_MS
#undef AP_RANGEFINDER_MSP_TIMEOUT_MS
#endif
#define AP_RANGEFINDER_MSP_TIMEOUT_MS 0

#endif /* _AP_CONFIG_H_ */
