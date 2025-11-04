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

/* ConfigFuzz Test #461 */

/* ConfigFuzz: MAVLINK_MSG_ID_DIGICAM_CONFIGURE */
#ifdef MAVLINK_MSG_ID_DIGICAM_CONFIGURE
#undef MAVLINK_MSG_ID_DIGICAM_CONFIGURE
#endif
#define MAVLINK_MSG_ID_DIGICAM_CONFIGURE 0

/* ConfigFuzz: KDECAN_MAX_NUM_ESCS */
#ifdef KDECAN_MAX_NUM_ESCS
#undef KDECAN_MAX_NUM_ESCS
#endif
#define KDECAN_MAX_NUM_ESCS 8

/* ConfigFuzz: HAL_COMPASS_AUTO_ROT_DEFAULT */
#ifdef HAL_COMPASS_AUTO_ROT_DEFAULT
#undef HAL_COMPASS_AUTO_ROT_DEFAULT
#endif
#define HAL_COMPASS_AUTO_ROT_DEFAULT 0

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 4

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 1

#endif /* _AP_CONFIG_H_ */
