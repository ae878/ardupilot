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

/* ConfigFuzz Test #911 */

/* ConfigFuzz: HAL_USB_PRODUCT_ID */
#ifdef HAL_USB_PRODUCT_ID
#undef HAL_USB_PRODUCT_ID
#endif
#define HAL_USB_PRODUCT_ID 0

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 32

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_LAND */
#ifdef FS_THR_ENABLED_ALWAYS_LAND
#undef FS_THR_ENABLED_ALWAYS_LAND
#endif
#define FS_THR_ENABLED_ALWAYS_LAND 1

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 0

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 1

/* ConfigFuzz: AP_BEACON_ENABLED */
#ifdef AP_BEACON_ENABLED
#undef AP_BEACON_ENABLED
#endif
#define AP_BEACON_ENABLED 0

/* ConfigFuzz: HAL_SOARING_ENABLED */
#ifdef HAL_SOARING_ENABLED
#undef HAL_SOARING_ENABLED
#endif
#define HAL_SOARING_ENABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_MOUNT_CONFIGURE */
#ifdef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#undef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#endif
#define MAVLINK_MSG_ID_MOUNT_CONFIGURE 0

#endif /* _AP_CONFIG_H_ */
