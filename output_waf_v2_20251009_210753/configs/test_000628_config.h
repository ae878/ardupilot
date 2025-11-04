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

/* ConfigFuzz Test #628 */

/* ConfigFuzz: HAL_EXTERNAL_AHRS_DEFAULT */
#ifdef HAL_EXTERNAL_AHRS_DEFAULT
#undef HAL_EXTERNAL_AHRS_DEFAULT
#endif
#define HAL_EXTERNAL_AHRS_DEFAULT 0

/* ConfigFuzz: AP_RSSI_ENABLED */
#ifdef AP_RSSI_ENABLED
#undef AP_RSSI_ENABLED
#endif
#define AP_RSSI_ENABLED 0

/* ConfigFuzz: BENCH_DEFINE_MAP_GEOMETRY */
#ifdef BENCH_DEFINE_MAP_GEOMETRY
#undef BENCH_DEFINE_MAP_GEOMETRY
#endif
#define BENCH_DEFINE_MAP_GEOMETRY 0

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 0

/* ConfigFuzz: MODE_LOITER_ENABLED */
#ifdef MODE_LOITER_ENABLED
#undef MODE_LOITER_ENABLED
#endif
#define MODE_LOITER_ENABLED 0

#endif /* _AP_CONFIG_H_ */
