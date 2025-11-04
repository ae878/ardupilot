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

/* ConfigFuzz Test #416 */

/* ConfigFuzz: MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC */
#ifdef MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC
#undef MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC
#endif
#define MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC 1

/* ConfigFuzz: AP_FEATURE_SBUS_OUT */
#ifdef AP_FEATURE_SBUS_OUT
#undef AP_FEATURE_SBUS_OUT
#endif
#define AP_FEATURE_SBUS_OUT 0

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 0

#endif /* _AP_CONFIG_H_ */
