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

/* ConfigFuzz Test #122 */

/* ConfigFuzz: HAL_NUM_CAN_IFACES */
#ifdef HAL_NUM_CAN_IFACES
#undef HAL_NUM_CAN_IFACES
#endif
#define HAL_NUM_CAN_IFACES 0

/* ConfigFuzz: BENCH_DEFINE_MAP_GEOMETRY */
#ifdef BENCH_DEFINE_MAP_GEOMETRY
#undef BENCH_DEFINE_MAP_GEOMETRY
#endif
#define BENCH_DEFINE_MAP_GEOMETRY 1

/* ConfigFuzz: MODE_ZIGZAG_ENABLED */
#ifdef MODE_ZIGZAG_ENABLED
#undef MODE_ZIGZAG_ENABLED
#endif
#define MODE_ZIGZAG_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_CUBEPILOT */
#ifdef MAVLINK_ENABLED_CUBEPILOT
#undef MAVLINK_ENABLED_CUBEPILOT
#endif
#define MAVLINK_ENABLED_CUBEPILOT 0

/* ConfigFuzz: HAL_SERIAL_ESC_COMM_ENABLED */
#ifdef HAL_SERIAL_ESC_COMM_ENABLED
#undef HAL_SERIAL_ESC_COMM_ENABLED
#endif
#define HAL_SERIAL_ESC_COMM_ENABLED 0

/* ConfigFuzz: HAL_MOUNT_ENABLED */
#ifdef HAL_MOUNT_ENABLED
#undef HAL_MOUNT_ENABLED
#endif
#define HAL_MOUNT_ENABLED 0

#endif /* _AP_CONFIG_H_ */
