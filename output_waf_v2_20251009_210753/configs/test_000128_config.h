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

/* ConfigFuzz Test #128 */

/* ConfigFuzz: HAL_SOLO_GIMBAL_ENABLED */
#ifdef HAL_SOLO_GIMBAL_ENABLED
#undef HAL_SOLO_GIMBAL_ENABLED
#endif
#define HAL_SOLO_GIMBAL_ENABLED 1

/* ConfigFuzz: AP_CRASHDUMP_ENABLED */
#ifdef AP_CRASHDUMP_ENABLED
#undef AP_CRASHDUMP_ENABLED
#endif
#define AP_CRASHDUMP_ENABLED 1

/* ConfigFuzz: MAVLINK_ENABLED_CSAIRLINK */
#ifdef MAVLINK_ENABLED_CSAIRLINK
#undef MAVLINK_ENABLED_CSAIRLINK
#endif
#define MAVLINK_ENABLED_CSAIRLINK 0

/* ConfigFuzz: HAL_GPIO_LED_ON */
#ifdef HAL_GPIO_LED_ON
#undef HAL_GPIO_LED_ON
#endif
#define HAL_GPIO_LED_ON 0

/* ConfigFuzz: HAL_WITH_SPI_RAMTRON */
#ifdef HAL_WITH_SPI_RAMTRON
#undef HAL_WITH_SPI_RAMTRON
#endif
#define HAL_WITH_SPI_RAMTRON 1

/* ConfigFuzz: HAL_INS_RATE_LOOP */
#ifdef HAL_INS_RATE_LOOP
#undef HAL_INS_RATE_LOOP
#endif
#define HAL_INS_RATE_LOOP 0

/* ConfigFuzz: MODE_GUIDED_ENABLED */
#ifdef MODE_GUIDED_ENABLED
#undef MODE_GUIDED_ENABLED
#endif
#define MODE_GUIDED_ENABLED 1

#endif /* _AP_CONFIG_H_ */
