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

/* ConfigFuzz Test #15 */

/* ConfigFuzz: AP_PERIPH_AIRSPEED_ENABLED */
#ifdef AP_PERIPH_AIRSPEED_ENABLED
#undef AP_PERIPH_AIRSPEED_ENABLED
#endif
#define AP_PERIPH_AIRSPEED_ENABLED 0

/* ConfigFuzz: MPUREG_CONFIG_EXT_SYNC_GZ */
#ifdef MPUREG_CONFIG_EXT_SYNC_GZ
#undef MPUREG_CONFIG_EXT_SYNC_GZ
#endif
#define MPUREG_CONFIG_EXT_SYNC_GZ 0

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 1

/* ConfigFuzz: AP_INERTIALSENSOR_KILL_IMU_ENABLED */
#ifdef AP_INERTIALSENSOR_KILL_IMU_ENABLED
#undef AP_INERTIALSENSOR_KILL_IMU_ENABLED
#endif
#define AP_INERTIALSENSOR_KILL_IMU_ENABLED 0

#endif /* _AP_CONFIG_H_ */
