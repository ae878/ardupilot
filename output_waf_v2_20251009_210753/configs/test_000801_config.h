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

/* ConfigFuzz Test #801 */

/* ConfigFuzz: MAVLINK_MSG_ID_PARAM_MAP_RC_CRC */
#ifdef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#undef MAVLINK_MSG_ID_PARAM_MAP_RC_CRC
#endif
#define MAVLINK_MSG_ID_PARAM_MAP_RC_CRC 0

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_RTL
#undef FS_THR_ENABLED_ALWAYS_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_RTL 0

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_LAND */
#ifdef FS_THR_ENABLED_ALWAYS_LAND
#undef FS_THR_ENABLED_ALWAYS_LAND
#endif
#define FS_THR_ENABLED_ALWAYS_LAND 0

/* ConfigFuzz: HAL_HEATER_GPIO_ON */
#ifdef HAL_HEATER_GPIO_ON
#undef HAL_HEATER_GPIO_ON
#endif
#define HAL_HEATER_GPIO_ON 1

/* ConfigFuzz: AP_FENCE_ENABLED */
#ifdef AP_FENCE_ENABLED
#undef AP_FENCE_ENABLED
#endif
#define AP_FENCE_ENABLED 0

/* ConfigFuzz: HAL_HAVE_SERVO_VOLTAGE */
#ifdef HAL_HAVE_SERVO_VOLTAGE
#undef HAL_HAVE_SERVO_VOLTAGE
#endif
#define HAL_HAVE_SERVO_VOLTAGE 0

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 0

/* ConfigFuzz: AP_GRIPPER_ENABLED */
#ifdef AP_GRIPPER_ENABLED
#undef AP_GRIPPER_ENABLED
#endif
#define AP_GRIPPER_ENABLED 1

#endif /* _AP_CONFIG_H_ */
