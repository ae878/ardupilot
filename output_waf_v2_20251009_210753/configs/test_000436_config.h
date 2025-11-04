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

/* ConfigFuzz Test #436 */

/* ConfigFuzz: HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS */
#ifdef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#undef HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS
#endif
#define HAVE_ENUM_GIMBAL_MANAGER_CAP_FLAGS 0

/* ConfigFuzz: FS_THR_ENABLED_BRAKE_OR_LAND */
#ifdef FS_THR_ENABLED_BRAKE_OR_LAND
#undef FS_THR_ENABLED_BRAKE_OR_LAND
#endif
#define FS_THR_ENABLED_BRAKE_OR_LAND 0

/* ConfigFuzz: HAL_HAVE_IMU_HEATER */
#ifdef HAL_HAVE_IMU_HEATER
#undef HAL_HAVE_IMU_HEATER
#endif
#define HAL_HAVE_IMU_HEATER 1

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 0

#endif /* _AP_CONFIG_H_ */
