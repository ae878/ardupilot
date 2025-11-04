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

/* ConfigFuzz Test #100 */

/* ConfigFuzz: AP_PERIPH_MAG_ENABLED */
#ifdef AP_PERIPH_MAG_ENABLED
#undef AP_PERIPH_MAG_ENABLED
#endif
#define AP_PERIPH_MAG_ENABLED 1

/* ConfigFuzz: AP_RELAY_ENABLED */
#ifdef AP_RELAY_ENABLED
#undef AP_RELAY_ENABLED
#endif
#define AP_RELAY_ENABLED 0

/* ConfigFuzz: HAL_WITH_IO_MCU_BIDIR_DSHOT */
#ifdef HAL_WITH_IO_MCU_BIDIR_DSHOT
#undef HAL_WITH_IO_MCU_BIDIR_DSHOT
#endif
#define HAL_WITH_IO_MCU_BIDIR_DSHOT 0

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 1

/* ConfigFuzz: AP_GRIPPER_ENABLED */
#ifdef AP_GRIPPER_ENABLED
#undef AP_GRIPPER_ENABLED
#endif
#define AP_GRIPPER_ENABLED 0

#endif /* _AP_CONFIG_H_ */
