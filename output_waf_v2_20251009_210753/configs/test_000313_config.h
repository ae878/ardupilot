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

/* ConfigFuzz Test #313 */

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 1

/* ConfigFuzz: HAL_GPIO_INPUT */
#ifdef HAL_GPIO_INPUT
#undef HAL_GPIO_INPUT
#endif
#define HAL_GPIO_INPUT 0

/* ConfigFuzz: LEDDARONE_DETECTIONS_MAX */
#ifdef LEDDARONE_DETECTIONS_MAX
#undef LEDDARONE_DETECTIONS_MAX
#endif
#define LEDDARONE_DETECTIONS_MAX 16

/* ConfigFuzz: AP_FEATURE_RTSCTS */
#ifdef AP_FEATURE_RTSCTS
#undef AP_FEATURE_RTSCTS
#endif
#define AP_FEATURE_RTSCTS 0

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

/* ConfigFuzz: HAL_GPIO_ALT */
#ifdef HAL_GPIO_ALT
#undef HAL_GPIO_ALT
#endif
#define HAL_GPIO_ALT 0

/* ConfigFuzz: AP_CAMERA_ENABLED */
#ifdef AP_CAMERA_ENABLED
#undef AP_CAMERA_ENABLED
#endif
#define AP_CAMERA_ENABLED 1

/* ConfigFuzz: HAL_SERIAL_ESC_COMM_ENABLED */
#ifdef HAL_SERIAL_ESC_COMM_ENABLED
#undef HAL_SERIAL_ESC_COMM_ENABLED
#endif
#define HAL_SERIAL_ESC_COMM_ENABLED 1

#endif /* _AP_CONFIG_H_ */
