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

/* ConfigFuzz Test #6 */

/* ConfigFuzz: AP_PERIPH_AIRSPEED_ENABLED */
#ifdef AP_PERIPH_AIRSPEED_ENABLED
#undef AP_PERIPH_AIRSPEED_ENABLED
#endif
#define AP_PERIPH_AIRSPEED_ENABLED 0

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 0

/* ConfigFuzz: MPUREG_ACCEL_CONFIG */
#ifdef MPUREG_ACCEL_CONFIG
#undef MPUREG_ACCEL_CONFIG
#endif
#define MPUREG_ACCEL_CONFIG 0

/* ConfigFuzz: HAL_USB_VENDOR_ID */
#ifdef HAL_USB_VENDOR_ID
#undef HAL_USB_VENDOR_ID
#endif
#define HAL_USB_VENDOR_ID 1

/* ConfigFuzz: HAL_PARACHUTE_ENABLED */
#ifdef HAL_PARACHUTE_ENABLED
#undef HAL_PARACHUTE_ENABLED
#endif
#define HAL_PARACHUTE_ENABLED 0

/* ConfigFuzz: AP_GRIPPER_ENABLED */
#ifdef AP_GRIPPER_ENABLED
#undef AP_GRIPPER_ENABLED
#endif
#define AP_GRIPPER_ENABLED 0

#endif /* _AP_CONFIG_H_ */
