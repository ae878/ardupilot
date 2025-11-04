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

/* ConfigFuzz Test #488 */

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

/* ConfigFuzz: ESC_CHANNEL_MAP_CHANNEL */
#ifdef ESC_CHANNEL_MAP_CHANNEL
#undef ESC_CHANNEL_MAP_CHANNEL
#endif
#define ESC_CHANNEL_MAP_CHANNEL 0

/* ConfigFuzz: FS_GCS_ENABLED_BRAKE_OR_LAND */
#ifdef FS_GCS_ENABLED_BRAKE_OR_LAND
#undef FS_GCS_ENABLED_BRAKE_OR_LAND
#endif
#define FS_GCS_ENABLED_BRAKE_OR_LAND 1

/* ConfigFuzz: MAVLINK_ENABLED_AVSSUAS */
#ifdef MAVLINK_ENABLED_AVSSUAS
#undef MAVLINK_ENABLED_AVSSUAS
#endif
#define MAVLINK_ENABLED_AVSSUAS 0

#endif /* _AP_CONFIG_H_ */
