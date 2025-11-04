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

/* ConfigFuzz Test #348 */

/* ConfigFuzz: AP_OPTICALFLOW_ENABLED */
#ifdef AP_OPTICALFLOW_ENABLED
#undef AP_OPTICALFLOW_ENABLED
#endif
#define AP_OPTICALFLOW_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_MOUNT_CONFIGURE */
#ifdef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#undef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#endif
#define MAVLINK_MSG_ID_MOUNT_CONFIGURE 0

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 1

#endif /* _AP_CONFIG_H_ */
