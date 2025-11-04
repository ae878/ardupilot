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

/* ConfigFuzz Test #1 */

/* ConfigFuzz: CONFIG_LWIP_DHCP_RESTORE_LAST_IP */
#ifdef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#undef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#endif
#define CONFIG_LWIP_DHCP_RESTORE_LAST_IP 1

/* ConfigFuzz: HAL_USE_SDMMC */
#ifdef HAL_USE_SDMMC
#undef HAL_USE_SDMMC
#endif
#define HAL_USE_SDMMC 1

/* ConfigFuzz: BENCH_DEFINE_MAP_COUNT */
#ifdef BENCH_DEFINE_MAP_COUNT
#undef BENCH_DEFINE_MAP_COUNT
#endif
#define BENCH_DEFINE_MAP_COUNT 0

/* ConfigFuzz: FS_GCS_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#undef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_GCS_ENABLED_AUTO_RTL_OR_RTL 1

#endif /* _AP_CONFIG_H_ */
