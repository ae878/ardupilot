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

/* ConfigFuzz Test #35 */

/* ConfigFuzz: AP_AIRSPEED_ENABLED */
#ifdef AP_AIRSPEED_ENABLED
#undef AP_AIRSPEED_ENABLED
#endif
#define AP_AIRSPEED_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC */
#ifdef MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC
#undef MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC
#endif
#define MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC 1

/* ConfigFuzz: HAL_WITH_UAVCAN */
#ifdef HAL_WITH_UAVCAN
#undef HAL_WITH_UAVCAN
#endif
#define HAL_WITH_UAVCAN 0

/* ConfigFuzz: MPUREG_CONFIG_FIFO_MODE_STOP */
#ifdef MPUREG_CONFIG_FIFO_MODE_STOP
#undef MPUREG_CONFIG_FIFO_MODE_STOP
#endif
#define MPUREG_CONFIG_FIFO_MODE_STOP 0

#endif /* _AP_CONFIG_H_ */
