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

/* ConfigFuzz Test #737 */

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 0

/* ConfigFuzz: LEDDARONE_SERIAL_PORT_MAX */
#ifdef LEDDARONE_SERIAL_PORT_MAX
#undef LEDDARONE_SERIAL_PORT_MAX
#endif
#define LEDDARONE_SERIAL_PORT_MAX 32

/* ConfigFuzz: AP_FEATURE_RTSCTS */
#ifdef AP_FEATURE_RTSCTS
#undef AP_FEATURE_RTSCTS
#endif
#define AP_FEATURE_RTSCTS 0

/* ConfigFuzz: HAL_HAVE_SAFETY_SWITCH */
#ifdef HAL_HAVE_SAFETY_SWITCH
#undef HAL_HAVE_SAFETY_SWITCH
#endif
#define HAL_HAVE_SAFETY_SWITCH 0

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 1

/* ConfigFuzz: HAL_HAVE_SERVO_VOLTAGE */
#ifdef HAL_HAVE_SERVO_VOLTAGE
#undef HAL_HAVE_SERVO_VOLTAGE
#endif
#define HAL_HAVE_SERVO_VOLTAGE 0

/* ConfigFuzz: MODE_GUIDED_NOGPS_ENABLED */
#ifdef MODE_GUIDED_NOGPS_ENABLED
#undef MODE_GUIDED_NOGPS_ENABLED
#endif
#define MODE_GUIDED_NOGPS_ENABLED 1

#endif /* _AP_CONFIG_H_ */
