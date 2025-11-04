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

/* ConfigFuzz Test #397 */

/* ConfigFuzz: HAL_WITH_UAVCAN */
#ifdef HAL_WITH_UAVCAN
#undef HAL_WITH_UAVCAN
#endif
#define HAL_WITH_UAVCAN 1

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

/* ConfigFuzz: FS_THR_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#undef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_THR_ENABLED_AUTO_RTL_OR_RTL 0

/* ConfigFuzz: NOOPLOOP_DIST_MAX_MM */
#ifdef NOOPLOOP_DIST_MAX_MM
#undef NOOPLOOP_DIST_MAX_MM
#endif
#define NOOPLOOP_DIST_MAX_MM 16

/* ConfigFuzz: HAL_SPEKTRUM_TELEM_ENABLED */
#ifdef HAL_SPEKTRUM_TELEM_ENABLED
#undef HAL_SPEKTRUM_TELEM_ENABLED
#endif
#define HAL_SPEKTRUM_TELEM_ENABLED 1

/* ConfigFuzz: HAL_WITH_RAMTRON */
#ifdef HAL_WITH_RAMTRON
#undef HAL_WITH_RAMTRON
#endif
#define HAL_WITH_RAMTRON 1

/* ConfigFuzz: HAL_MOUNT_ENABLED */
#ifdef HAL_MOUNT_ENABLED
#undef HAL_MOUNT_ENABLED
#endif
#define HAL_MOUNT_ENABLED 1

#endif /* _AP_CONFIG_H_ */
