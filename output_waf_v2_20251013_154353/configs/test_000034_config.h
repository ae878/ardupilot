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

/* ConfigFuzz Test #34 */

/* ConfigFuzz: HAL_INS_CONVERGANCE_MS */
#ifdef HAL_INS_CONVERGANCE_MS
#undef HAL_INS_CONVERGANCE_MS
#endif
#define HAL_INS_CONVERGANCE_MS 1

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 0

/* ConfigFuzz: MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC */
#ifdef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#undef MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC
#endif
#define MAVLINK_MSG_ID_WIFI_CONFIG_AP_CRC 0

/* ConfigFuzz: AP_PERIPH_RPM_ENABLED */
#ifdef AP_PERIPH_RPM_ENABLED
#undef AP_PERIPH_RPM_ENABLED
#endif
#define AP_PERIPH_RPM_ENABLED 1

/* ConfigFuzz: HAL_HEATER_GPIO_PIN */
#ifdef HAL_HEATER_GPIO_PIN
#undef HAL_HEATER_GPIO_PIN
#endif
#define HAL_HEATER_GPIO_PIN 0

/* ConfigFuzz: INS_MAX_GYRO_WINDOW_SAMPLES */
#ifdef INS_MAX_GYRO_WINDOW_SAMPLES
#undef INS_MAX_GYRO_WINDOW_SAMPLES
#endif
#define INS_MAX_GYRO_WINDOW_SAMPLES 32

#endif /* _AP_CONFIG_H_ */
