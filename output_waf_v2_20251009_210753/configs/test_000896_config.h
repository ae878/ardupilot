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

/* ConfigFuzz Test #896 */

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_LAND */
#ifdef FS_GCS_ENABLED_ALWAYS_LAND
#undef FS_GCS_ENABLED_ALWAYS_LAND
#endif
#define FS_GCS_ENABLED_ALWAYS_LAND 1

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 0

/* ConfigFuzz: HAL_CAN_DRIVER_DEFAULT */
#ifdef HAL_CAN_DRIVER_DEFAULT
#undef HAL_CAN_DRIVER_DEFAULT
#endif
#define HAL_CAN_DRIVER_DEFAULT 0

/* ConfigFuzz: AP_NOTIFY_NAVIGATOR_LED_ENABLED */
#ifdef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#undef AP_NOTIFY_NAVIGATOR_LED_ENABLED
#endif
#define AP_NOTIFY_NAVIGATOR_LED_ENABLED 0

/* ConfigFuzz: HAL_PWM_COUNT */
#ifdef HAL_PWM_COUNT
#undef HAL_PWM_COUNT
#endif
#define HAL_PWM_COUNT 1

/* ConfigFuzz: FS_THR_DISABLED */
#ifdef FS_THR_DISABLED
#undef FS_THR_DISABLED
#endif
#define FS_THR_DISABLED 1

/* ConfigFuzz: HAL_SPRAYER_ENABLED */
#ifdef HAL_SPRAYER_ENABLED
#undef HAL_SPRAYER_ENABLED
#endif
#define HAL_SPRAYER_ENABLED 0

/* ConfigFuzz: HAL_AIRSPEED_TYPE_DEFAULT */
#ifdef HAL_AIRSPEED_TYPE_DEFAULT
#undef HAL_AIRSPEED_TYPE_DEFAULT
#endif
#define HAL_AIRSPEED_TYPE_DEFAULT 1

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 4

#endif /* _AP_CONFIG_H_ */
