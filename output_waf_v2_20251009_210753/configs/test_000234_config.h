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

/* ConfigFuzz Test #234 */

/* ConfigFuzz: HAL_BARO_EXTERNAL_BUS_DEFAULT */
#ifdef HAL_BARO_EXTERNAL_BUS_DEFAULT
#undef HAL_BARO_EXTERNAL_BUS_DEFAULT
#endif
#define HAL_BARO_EXTERNAL_BUS_DEFAULT 1

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING_CRC */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#undef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING_CRC 1

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP 1

/* ConfigFuzz: HAL_INS_VRBRAIN */
#ifdef HAL_INS_VRBRAIN
#undef HAL_INS_VRBRAIN
#endif
#define HAL_INS_VRBRAIN 0

/* ConfigFuzz: HAL_USE_WSPI_DEFAULT_CFG */
#ifdef HAL_USE_WSPI_DEFAULT_CFG
#undef HAL_USE_WSPI_DEFAULT_CFG
#endif
#define HAL_USE_WSPI_DEFAULT_CFG 0

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 1

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 1

/* ConfigFuzz: AC_PRECLAND_ENABLED */
#ifdef AC_PRECLAND_ENABLED
#undef AC_PRECLAND_ENABLED
#endif
#define AC_PRECLAND_ENABLED 0

#endif /* _AP_CONFIG_H_ */
