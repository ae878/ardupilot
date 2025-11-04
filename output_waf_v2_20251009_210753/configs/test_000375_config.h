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

/* ConfigFuzz Test #375 */

/* ConfigFuzz: HAL_HAVE_HARDWARE_DOUBLE */
#ifdef HAL_HAVE_HARDWARE_DOUBLE
#undef HAL_HAVE_HARDWARE_DOUBLE
#endif
#define HAL_HAVE_HARDWARE_DOUBLE 0

/* ConfigFuzz: HAL_CANFD_SUPPORTED */
#ifdef HAL_CANFD_SUPPORTED
#undef HAL_CANFD_SUPPORTED
#endif
#define HAL_CANFD_SUPPORTED 1

/* ConfigFuzz: HAL_USE_SDMMC */
#ifdef HAL_USE_SDMMC
#undef HAL_USE_SDMMC
#endif
#define HAL_USE_SDMMC 1

/* ConfigFuzz: HAL_CAN_DRIVER_DEFAULT */
#ifdef HAL_CAN_DRIVER_DEFAULT
#undef HAL_CAN_DRIVER_DEFAULT
#endif
#define HAL_CAN_DRIVER_DEFAULT 1

/* ConfigFuzz: HAL_WITH_IO_MCU_BIDIR_DSHOT */
#ifdef HAL_WITH_IO_MCU_BIDIR_DSHOT
#undef HAL_WITH_IO_MCU_BIDIR_DSHOT
#endif
#define HAL_WITH_IO_MCU_BIDIR_DSHOT 0

#endif /* _AP_CONFIG_H_ */
