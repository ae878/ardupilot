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

/* ConfigFuzz Test #756 */

/* ConfigFuzz: METADATA_MAX_i */
#ifdef METADATA_MAX_i
#undef METADATA_MAX_i
#endif
#define METADATA_MAX_i 8

/* ConfigFuzz: HAL_BATT_CURR_PIN */
#ifdef HAL_BATT_CURR_PIN
#undef HAL_BATT_CURR_PIN
#endif
#define HAL_BATT_CURR_PIN 0

/* ConfigFuzz: HAL_INS_NONE */
#ifdef HAL_INS_NONE
#undef HAL_INS_NONE
#endif
#define HAL_INS_NONE 0

/* ConfigFuzz: HAL_WITH_IO_MCU_BIDIR_DSHOT */
#ifdef HAL_WITH_IO_MCU_BIDIR_DSHOT
#undef HAL_WITH_IO_MCU_BIDIR_DSHOT
#endif
#define HAL_WITH_IO_MCU_BIDIR_DSHOT 0

/* ConfigFuzz: MAVLINK_ENABLED_ASLUAV */
#ifdef MAVLINK_ENABLED_ASLUAV
#undef MAVLINK_ENABLED_ASLUAV
#endif
#define MAVLINK_ENABLED_ASLUAV 1

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

/* ConfigFuzz: RC_INPUT_MAX_PULSEWIDTH */
#ifdef RC_INPUT_MAX_PULSEWIDTH
#undef RC_INPUT_MAX_PULSEWIDTH
#endif
#define RC_INPUT_MAX_PULSEWIDTH 32

/* ConfigFuzz: HAL_COMPASS_AUTO_ROT_DEFAULT */
#ifdef HAL_COMPASS_AUTO_ROT_DEFAULT
#undef HAL_COMPASS_AUTO_ROT_DEFAULT
#endif
#define HAL_COMPASS_AUTO_ROT_DEFAULT 0

#endif /* _AP_CONFIG_H_ */
