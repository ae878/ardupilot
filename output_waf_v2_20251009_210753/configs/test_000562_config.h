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

/* ConfigFuzz Test #562 */

/* ConfigFuzz: HAL_FLASH_ALLOW_UPDATE */
#ifdef HAL_FLASH_ALLOW_UPDATE
#undef HAL_FLASH_ALLOW_UPDATE
#endif
#define HAL_FLASH_ALLOW_UPDATE 1

/* ConfigFuzz: HAL_SOLO_GIMBAL_ENABLED */
#ifdef HAL_SOLO_GIMBAL_ENABLED
#undef HAL_SOLO_GIMBAL_ENABLED
#endif
#define HAL_SOLO_GIMBAL_ENABLED 1

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 0

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 0

/* ConfigFuzz: AC_MAVLINK_SOLO_BUTTON_COMMAND_HANDLING_ENABLED */
#ifdef AC_MAVLINK_SOLO_BUTTON_COMMAND_HANDLING_ENABLED
#undef AC_MAVLINK_SOLO_BUTTON_COMMAND_HANDLING_ENABLED
#endif
#define AC_MAVLINK_SOLO_BUTTON_COMMAND_HANDLING_ENABLED 0

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 1

#endif /* _AP_CONFIG_H_ */
