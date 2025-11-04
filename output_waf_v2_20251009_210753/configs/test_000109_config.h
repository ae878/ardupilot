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

/* ConfigFuzz Test #109 */

/* ConfigFuzz: AP_ICENGINE_ENABLED */
#ifdef AP_ICENGINE_ENABLED
#undef AP_ICENGINE_ENABLED
#endif
#define AP_ICENGINE_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC */
#ifdef MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC
#undef MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC
#endif
#define MAVLINK_MSG_ID_MOUNT_CONFIGURE_CRC 0

/* ConfigFuzz: KDECAN_MAX_NUM_ESCS */
#ifdef KDECAN_MAX_NUM_ESCS
#undef KDECAN_MAX_NUM_ESCS
#endif
#define KDECAN_MAX_NUM_ESCS 2

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 0

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 0

#endif /* _AP_CONFIG_H_ */
