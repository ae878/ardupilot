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

/* ConfigFuzz Test #928 */

/* ConfigFuzz: FS_GCS_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#undef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_GCS_ENABLED_AUTO_RTL_OR_RTL 0

/* ConfigFuzz: CONFIG_SPI_FLASH_ENABLE_COUNTERS */
#ifdef CONFIG_SPI_FLASH_ENABLE_COUNTERS
#undef CONFIG_SPI_FLASH_ENABLE_COUNTERS
#endif
#define CONFIG_SPI_FLASH_ENABLE_COUNTERS 0

/* ConfigFuzz: AP_SIGNED_FIRMWARE */
#ifdef AP_SIGNED_FIRMWARE
#undef AP_SIGNED_FIRMWARE
#endif
#define AP_SIGNED_FIRMWARE 1

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 1

#endif /* _AP_CONFIG_H_ */
