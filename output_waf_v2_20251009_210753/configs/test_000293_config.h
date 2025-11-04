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

/* ConfigFuzz Test #293 */

/* ConfigFuzz: AP_COPTER_AHRS_AUTO_TRIM_ENABLED */
#ifdef AP_COPTER_AHRS_AUTO_TRIM_ENABLED
#undef AP_COPTER_AHRS_AUTO_TRIM_ENABLED
#endif
#define AP_COPTER_AHRS_AUTO_TRIM_ENABLED 0

/* ConfigFuzz: HAL_HEATER_GPIO_PIN */
#ifdef HAL_HEATER_GPIO_PIN
#undef HAL_HEATER_GPIO_PIN
#endif
#define HAL_HEATER_GPIO_PIN 1

/* ConfigFuzz: HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS */
#ifdef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#undef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#endif
#define HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS 1

#endif /* _AP_CONFIG_H_ */
