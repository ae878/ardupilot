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

/* ConfigFuzz Test #598 */

/* ConfigFuzz: HAL_HAVE_SERVO_VOLTAGE */
#ifdef HAL_HAVE_SERVO_VOLTAGE
#undef HAL_HAVE_SERVO_VOLTAGE
#endif
#define HAL_HAVE_SERVO_VOLTAGE 1

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 2

/* ConfigFuzz: MAVLINK_MSG_ID_ADAP_TUNING */
#ifdef MAVLINK_MSG_ID_ADAP_TUNING
#undef MAVLINK_MSG_ID_ADAP_TUNING
#endif
#define MAVLINK_MSG_ID_ADAP_TUNING 0

/* ConfigFuzz: AP_SOCKET_NATIVE_ENABLED */
#ifdef AP_SOCKET_NATIVE_ENABLED
#undef AP_SOCKET_NATIVE_ENABLED
#endif
#define AP_SOCKET_NATIVE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
