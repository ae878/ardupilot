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

/* ConfigFuzz Test #821 */

/* ConfigFuzz: MAVLINK_ENABLED_ASLUAV */
#ifdef MAVLINK_ENABLED_ASLUAV
#undef MAVLINK_ENABLED_ASLUAV
#endif
#define MAVLINK_ENABLED_ASLUAV 1

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 32

/* ConfigFuzz: AP_NOTIFY_NAVIGATOR_LED_ENABLED */
#ifdef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#undef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#endif
#define AP_NOTIFY_NAVIGATOR_LED_ENABLED 0

/* ConfigFuzz: HAL_EXTERNAL_AHRS_DEFAULT */
#ifdef HAL_EXTERNAL_AHRS_DEFAULT
#undef HAL_EXTERNAL_AHRS_DEFAULT
#endif
#define HAL_EXTERNAL_AHRS_DEFAULT 1

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 1

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 1

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 1

/* ConfigFuzz: TELEM_TIME_SLOT_MAX */
#ifdef TELEM_TIME_SLOT_MAX
#undef TELEM_TIME_SLOT_MAX
#endif
#define TELEM_TIME_SLOT_MAX 2

#endif /* _AP_CONFIG_H_ */
