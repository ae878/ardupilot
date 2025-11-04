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

/* ConfigFuzz Test #229 */

/* ConfigFuzz: CONFIG_NEWLIB_NANO_FORMAT */
#ifdef CONFIG_NEWLIB_NANO_FORMAT
#undef CONFIG_NEWLIB_NANO_FORMAT
#endif
#define CONFIG_NEWLIB_NANO_FORMAT 1

/* ConfigFuzz: HAL_HAVE_HARDWARE_DOUBLE */
#ifdef HAL_HAVE_HARDWARE_DOUBLE
#undef HAL_HAVE_HARDWARE_DOUBLE
#endif
#define HAL_HAVE_HARDWARE_DOUBLE 1

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 1

/* ConfigFuzz: BENCH_DEFINE_MAP_COUNT */
#ifdef BENCH_DEFINE_MAP_COUNT
#undef BENCH_DEFINE_MAP_COUNT
#endif
#define BENCH_DEFINE_MAP_COUNT 0

/* ConfigFuzz: HAL_USE_FATFS */
#ifdef HAL_USE_FATFS
#undef HAL_USE_FATFS
#endif
#define HAL_USE_FATFS 1

/* ConfigFuzz: HAL_USE_HW_RNG */
#ifdef HAL_USE_HW_RNG
#undef HAL_USE_HW_RNG
#endif
#define HAL_USE_HW_RNG 0

/* ConfigFuzz: HAL_RCOUT_RGBLED_BLUE */
#ifdef HAL_RCOUT_RGBLED_BLUE
#undef HAL_RCOUT_RGBLED_BLUE
#endif
#define HAL_RCOUT_RGBLED_BLUE 0

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 32

/* ConfigFuzz: HAL_SERIAL_ESC_COMM_ENABLED */
#ifdef HAL_SERIAL_ESC_COMM_ENABLED
#undef HAL_SERIAL_ESC_COMM_ENABLED
#endif
#define HAL_SERIAL_ESC_COMM_ENABLED 1

/* ConfigFuzz: MODE_THROW_ENABLED */
#ifdef MODE_THROW_ENABLED
#undef MODE_THROW_ENABLED
#endif
#define MODE_THROW_ENABLED 1

#endif /* _AP_CONFIG_H_ */
