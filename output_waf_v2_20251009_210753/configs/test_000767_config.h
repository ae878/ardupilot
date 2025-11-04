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

/* ConfigFuzz Test #767 */

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 1

/* ConfigFuzz: LEDDARONE_DETECTIONS_MAX */
#ifdef LEDDARONE_DETECTIONS_MAX
#undef LEDDARONE_DETECTIONS_MAX
#endif
#define LEDDARONE_DETECTIONS_MAX 32

/* ConfigFuzz: TAP_ESC_MAX_MOTOR_NUM */
#ifdef TAP_ESC_MAX_MOTOR_NUM
#undef TAP_ESC_MAX_MOTOR_NUM
#endif
#define TAP_ESC_MAX_MOTOR_NUM 2

/* ConfigFuzz: KDECAN_MAX_NUM_ESCS */
#ifdef KDECAN_MAX_NUM_ESCS
#undef KDECAN_MAX_NUM_ESCS
#endif
#define KDECAN_MAX_NUM_ESCS 8

/* ConfigFuzz: MODE_SPORT_ENABLED */
#ifdef MODE_SPORT_ENABLED
#undef MODE_SPORT_ENABLED
#endif
#define MODE_SPORT_ENABLED 0

/* ConfigFuzz: HAL_HEATER_GPIO_PIN */
#ifdef HAL_HEATER_GPIO_PIN
#undef HAL_HEATER_GPIO_PIN
#endif
#define HAL_HEATER_GPIO_PIN 0

/* ConfigFuzz: FS_GCS_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#undef FS_GCS_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_GCS_ENABLED_AUTO_RTL_OR_RTL 1

#endif /* _AP_CONFIG_H_ */
