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

/* ConfigFuzz Test #389 */

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 0

/* ConfigFuzz: HAL_WITH_IO_MCU */
#ifdef HAL_WITH_IO_MCU
#undef HAL_WITH_IO_MCU
#endif
#define HAL_WITH_IO_MCU 1

/* ConfigFuzz: HAL_FLASH_PROTECTION */
#ifdef HAL_FLASH_PROTECTION
#undef HAL_FLASH_PROTECTION
#endif
#define HAL_FLASH_PROTECTION 1

/* ConfigFuzz: MODE_AUTOROTATE_ENABLED */
#ifdef MODE_AUTOROTATE_ENABLED
#undef MODE_AUTOROTATE_ENABLED
#endif
#define MODE_AUTOROTATE_ENABLED 1

/* ConfigFuzz: AP_FENCE_ENABLED */
#ifdef AP_FENCE_ENABLED
#undef AP_FENCE_ENABLED
#endif
#define AP_FENCE_ENABLED 0

/* ConfigFuzz: HAL_CANFD_SUPPORTED */
#ifdef HAL_CANFD_SUPPORTED
#undef HAL_CANFD_SUPPORTED
#endif
#define HAL_CANFD_SUPPORTED 1

/* ConfigFuzz: HAL_WITH_RAMTRON */
#ifdef HAL_WITH_RAMTRON
#undef HAL_WITH_RAMTRON
#endif
#define HAL_WITH_RAMTRON 1

/* ConfigFuzz: MAVLINK_MSG_ID_MOUNT_CONFIGURE */
#ifdef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#undef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#endif
#define MAVLINK_MSG_ID_MOUNT_CONFIGURE 1

#endif /* _AP_CONFIG_H_ */
