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

/* ConfigFuzz Test #538 */

/* ConfigFuzz: HAL_MEMORY_TOTAL_KB */
#ifdef HAL_MEMORY_TOTAL_KB
#undef HAL_MEMORY_TOTAL_KB
#endif
#define HAL_MEMORY_TOTAL_KB 1

/* ConfigFuzz: MAVLINK_MSG_ID_AP_ADC_CRC */
#ifdef MAVLINK_MSG_ID_AP_ADC_CRC
#undef MAVLINK_MSG_ID_AP_ADC_CRC
#endif
#define MAVLINK_MSG_ID_AP_ADC_CRC 0

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

/* ConfigFuzz: AP_ADVANCEDFAILSAFE_ENABLED */
#ifdef AP_ADVANCEDFAILSAFE_ENABLED
#undef AP_ADVANCEDFAILSAFE_ENABLED
#endif
#define AP_ADVANCEDFAILSAFE_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_LOWEHEISER */
#ifdef MAVLINK_ENABLED_LOWEHEISER
#undef MAVLINK_ENABLED_LOWEHEISER
#endif
#define MAVLINK_ENABLED_LOWEHEISER 0

/* ConfigFuzz: RPMMAX */
#ifdef RPMMAX
#undef RPMMAX
#endif
#define RPMMAX 1

/* ConfigFuzz: AP_CRASHDUMP_ENABLED */
#ifdef AP_CRASHDUMP_ENABLED
#undef AP_CRASHDUMP_ENABLED
#endif
#define AP_CRASHDUMP_ENABLED 1

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 1

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 1

#endif /* _AP_CONFIG_H_ */
