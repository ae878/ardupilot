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

/* ConfigFuzz Test #183 */

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 1

/* ConfigFuzz: MAVLINK_MSG_ID_DIGICAM_CONFIGURE */
#ifdef MAVLINK_MSG_ID_DIGICAM_CONFIGURE
#undef MAVLINK_MSG_ID_DIGICAM_CONFIGURE
#endif
#define MAVLINK_MSG_ID_DIGICAM_CONFIGURE 1

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING
#undef MAVLINK_MSG_ID_ADAP_TUNING
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING 1

/* ConfigFuzz: HAL_SERIAL_ESC_COMM_ENABLED */
#ifdef HAL_SERIAL_ESC_COMM_ENABLED
#undef HAL_SERIAL_ESC_COMM_ENABLED
#endif
#define HAL_SERIAL_ESC_COMM_ENABLED 0

#endif /* _AP_CONFIG_H_ */
