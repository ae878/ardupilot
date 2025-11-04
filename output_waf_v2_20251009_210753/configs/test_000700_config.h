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

/* ConfigFuzz Test #700 */

/* ConfigFuzz: MAXSONAR_SERIAL_LV_BAUD_RATE */
#ifdef MAXSONAR_SERIAL_LV_BAUD_RATE
#undef MAXSONAR_SERIAL_LV_BAUD_RATE
#endif
#define MAXSONAR_SERIAL_LV_BAUD_RATE 16

/* ConfigFuzz: HAL_NUM_CAN_IFACES */
#ifdef HAL_NUM_CAN_IFACES
#undef HAL_NUM_CAN_IFACES
#endif
#define HAL_NUM_CAN_IFACES 0

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 0

/* ConfigFuzz: MODE_LOITER_ENABLED */
#ifdef MODE_LOITER_ENABLED
#undef MODE_LOITER_ENABLED
#endif
#define MODE_LOITER_ENABLED 0

/* ConfigFuzz: HAL_WITH_IO_MCU */
#ifdef HAL_WITH_IO_MCU
#undef HAL_WITH_IO_MCU
#endif
#define HAL_WITH_IO_MCU 1

#endif /* _AP_CONFIG_H_ */
