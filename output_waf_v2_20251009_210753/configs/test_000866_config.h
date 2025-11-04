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

/* ConfigFuzz Test #866 */

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING_CRC */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#undef MAVLINK_MSG_ID_ADAP_TUNING_CRC
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING_CRC 1

/* ConfigFuzz: CONFIG_LWIP_PPP_SUPPORT */
#ifdef CONFIG_LWIP_PPP_SUPPORT
#undef CONFIG_LWIP_PPP_SUPPORT
#endif
#define CONFIG_LWIP_PPP_SUPPORT 1

/* ConfigFuzz: HAL_HAVE_IMU_HEATER */
#ifdef HAL_HAVE_IMU_HEATER
#undef HAL_HAVE_IMU_HEATER
#endif
#define HAL_HAVE_IMU_HEATER 0

#endif /* _AP_CONFIG_H_ */
