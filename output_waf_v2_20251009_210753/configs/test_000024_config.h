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

/* ConfigFuzz Test #24 */

/* ConfigFuzz: MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC */
#ifdef MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC
#undef MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC
#endif
#define MAVLINK_MSG_ID_DIGICAM_CONFIGURE_CRC 0

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_LAND */
#ifdef FS_GCS_ENABLED_ALWAYS_LAND
#undef FS_GCS_ENABLED_ALWAYS_LAND
#endif
#define FS_GCS_ENABLED_ALWAYS_LAND 0

/* ConfigFuzz: HAL_BARO_NONE */
#ifdef HAL_BARO_NONE
#undef HAL_BARO_NONE
#endif
#define HAL_BARO_NONE 1

/* ConfigFuzz: AP_FENCE_ENABLED */
#ifdef AP_FENCE_ENABLED
#undef AP_FENCE_ENABLED
#endif
#define AP_FENCE_ENABLED 0

#endif /* _AP_CONFIG_H_ */
