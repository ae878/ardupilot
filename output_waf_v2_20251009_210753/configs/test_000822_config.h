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

/* ConfigFuzz Test #822 */

/* ConfigFuzz: AP_SOCKET_NATIVE_ENABLED */
#ifdef AP_SOCKET_NATIVE_ENABLED
#undef AP_SOCKET_NATIVE_ENABLED
#endif
#define AP_SOCKET_NATIVE_ENABLED 1

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 8

/* ConfigFuzz: MODE_SPORT_ENABLED */
#ifdef MODE_SPORT_ENABLED
#undef MODE_SPORT_ENABLED
#endif
#define MODE_SPORT_ENABLED 1

/* ConfigFuzz: HAL_SEMAPHORE_BLOCK_FOREVER */
#ifdef HAL_SEMAPHORE_BLOCK_FOREVER
#undef HAL_SEMAPHORE_BLOCK_FOREVER
#endif
#define HAL_SEMAPHORE_BLOCK_FOREVER 0

/* ConfigFuzz: MAVLINK_ENABLED_COMMON */
#ifdef MAVLINK_ENABLED_COMMON
#undef MAVLINK_ENABLED_COMMON
#endif
#define MAVLINK_ENABLED_COMMON 1

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 1

#endif /* _AP_CONFIG_H_ */
