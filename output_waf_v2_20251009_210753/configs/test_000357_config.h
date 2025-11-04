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

/* ConfigFuzz Test #357 */

/* ConfigFuzz: HAL_DSHOT_ENABLED */
#ifdef HAL_DSHOT_ENABLED
#undef HAL_DSHOT_ENABLED
#endif
#define HAL_DSHOT_ENABLED 1

/* ConfigFuzz: AP_GRIPPER_ENABLED */
#ifdef AP_GRIPPER_ENABLED
#undef AP_GRIPPER_ENABLED
#endif
#define AP_GRIPPER_ENABLED 0

/* ConfigFuzz: HAL_IMUHEAT_P_DEFAULT */
#ifdef HAL_IMUHEAT_P_DEFAULT
#undef HAL_IMUHEAT_P_DEFAULT
#endif
#define HAL_IMUHEAT_P_DEFAULT 1

/* ConfigFuzz: MODE_GUIDED_ENABLED */
#ifdef MODE_GUIDED_ENABLED
#undef MODE_GUIDED_ENABLED
#endif
#define MODE_GUIDED_ENABLED 1

/* ConfigFuzz: HAL_HEATER_GPIO_PIN */
#ifdef HAL_HEATER_GPIO_PIN
#undef HAL_HEATER_GPIO_PIN
#endif
#define HAL_HEATER_GPIO_PIN 1

/* ConfigFuzz: BENCH_DEFINE_MAP_EXPLICIT */
#ifdef BENCH_DEFINE_MAP_EXPLICIT
#undef BENCH_DEFINE_MAP_EXPLICIT
#endif
#define BENCH_DEFINE_MAP_EXPLICIT 1

#endif /* _AP_CONFIG_H_ */
