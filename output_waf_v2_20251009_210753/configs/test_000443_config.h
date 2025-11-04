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

/* ConfigFuzz Test #443 */

/* ConfigFuzz: CONFIG_SPI_FLASH_DANGEROUS_WRITE_ALLOWED */
#ifdef CONFIG_SPI_FLASH_DANGEROUS_WRITE_ALLOWED
#undef CONFIG_SPI_FLASH_DANGEROUS_WRITE_ALLOWED
#endif
#define CONFIG_SPI_FLASH_DANGEROUS_WRITE_ALLOWED 0

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 1

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 1

#endif /* _AP_CONFIG_H_ */
