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

/* ConfigFuzz Test #592 */

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 1

/* ConfigFuzz: HAL_HEATER_GPIO_ON */
#ifdef HAL_HEATER_GPIO_ON
#undef HAL_HEATER_GPIO_ON
#endif
#define HAL_HEATER_GPIO_ON 1

/* ConfigFuzz: MAVLINK_ENABLED_CSAIRLINK */
#ifdef MAVLINK_ENABLED_CSAIRLINK
#undef MAVLINK_ENABLED_CSAIRLINK
#endif
#define MAVLINK_ENABLED_CSAIRLINK 1

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 0

/* ConfigFuzz: FS_THR_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#undef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_THR_ENABLED_AUTO_RTL_OR_RTL 1

/* ConfigFuzz: MODE_CIRCLE_ENABLED */
#ifdef MODE_CIRCLE_ENABLED
#undef MODE_CIRCLE_ENABLED
#endif
#define MODE_CIRCLE_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_ICAROUS */
#ifdef MAVLINK_ENABLED_ICAROUS
#undef MAVLINK_ENABLED_ICAROUS
#endif
#define MAVLINK_ENABLED_ICAROUS 1

/* ConfigFuzz: AP_STATS_ENABLED */
#ifdef AP_STATS_ENABLED
#undef AP_STATS_ENABLED
#endif
#define AP_STATS_ENABLED 0

#endif /* _AP_CONFIG_H_ */
