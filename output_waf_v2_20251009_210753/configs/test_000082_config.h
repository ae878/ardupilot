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

/* ConfigFuzz Test #82 */

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN 0

/* ConfigFuzz: HAL_USE_SDMMC */
#ifdef HAL_USE_SDMMC
#undef HAL_USE_SDMMC
#endif
#define HAL_USE_SDMMC 0

/* ConfigFuzz: FFT_MAX_MISSED_UPDATES */
#ifdef FFT_MAX_MISSED_UPDATES
#undef FFT_MAX_MISSED_UPDATES
#endif
#define FFT_MAX_MISSED_UPDATES 32

/* ConfigFuzz: HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS */
#ifdef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#undef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#endif
#define HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS 1

/* ConfigFuzz: AP_FOLLOW_ENABLED */
#ifdef AP_FOLLOW_ENABLED
#undef AP_FOLLOW_ENABLED
#endif
#define AP_FOLLOW_ENABLED 0

/* ConfigFuzz: TOY_MODE_ENABLED */
#ifdef TOY_MODE_ENABLED
#undef TOY_MODE_ENABLED
#endif
#define TOY_MODE_ENABLED 0

/* ConfigFuzz: HAL_HAVE_IMU_HEATER */
#ifdef HAL_HAVE_IMU_HEATER
#undef HAL_HAVE_IMU_HEATER
#endif
#define HAL_HAVE_IMU_HEATER 1

#endif /* _AP_CONFIG_H_ */
