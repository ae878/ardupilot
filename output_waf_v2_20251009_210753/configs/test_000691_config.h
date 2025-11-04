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

/* ConfigFuzz Test #691 */

/* ConfigFuzz: AP_SERVORELAYEVENTS_ENABLED */
#ifdef AP_SERVORELAYEVENTS_ENABLED
#undef AP_SERVORELAYEVENTS_ENABLED
#endif
#define AP_SERVORELAYEVENTS_ENABLED 1

/* ConfigFuzz: MODE_LOITER_ENABLED */
#ifdef MODE_LOITER_ENABLED
#undef MODE_LOITER_ENABLED
#endif
#define MODE_LOITER_ENABLED 0

/* ConfigFuzz: CONFIG_SPI_FLASH_ENABLE_COUNTERS */
#ifdef CONFIG_SPI_FLASH_ENABLE_COUNTERS
#undef CONFIG_SPI_FLASH_ENABLE_COUNTERS
#endif
#define CONFIG_SPI_FLASH_ENABLE_COUNTERS 1

#endif /* _AP_CONFIG_H_ */
