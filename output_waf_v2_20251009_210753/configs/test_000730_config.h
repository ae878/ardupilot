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

/* ConfigFuzz Test #730 */

/* ConfigFuzz: RANGEFINDER_MAX_INSTANCES */
#ifdef RANGEFINDER_MAX_INSTANCES
#undef RANGEFINDER_MAX_INSTANCES
#endif
#define RANGEFINDER_MAX_INSTANCES 1

/* ConfigFuzz: MAVLINK_ENABLED_ALL */
#ifdef MAVLINK_ENABLED_ALL
#undef MAVLINK_ENABLED_ALL
#endif
#define MAVLINK_ENABLED_ALL 1

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP 1

#endif /* _AP_CONFIG_H_ */
