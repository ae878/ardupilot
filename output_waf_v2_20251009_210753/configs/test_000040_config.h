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

/* ConfigFuzz Test #40 */

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 1

/* ConfigFuzz: SUMD_MAX_CHANNELS */
#ifdef SUMD_MAX_CHANNELS
#undef SUMD_MAX_CHANNELS
#endif
#define SUMD_MAX_CHANNELS 32

/* ConfigFuzz: MAVLINK_ENABLED_UAVIONIX */
#ifdef MAVLINK_ENABLED_UAVIONIX
#undef MAVLINK_ENABLED_UAVIONIX
#endif
#define MAVLINK_ENABLED_UAVIONIX 0

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 0

/* ConfigFuzz: LEDDARONE_SERIAL_PORT_MAX */
#ifdef LEDDARONE_SERIAL_PORT_MAX
#undef LEDDARONE_SERIAL_PORT_MAX
#endif
#define LEDDARONE_SERIAL_PORT_MAX 32

/* ConfigFuzz: HAL_GENERATOR_ENABLED */
#ifdef HAL_GENERATOR_ENABLED
#undef HAL_GENERATOR_ENABLED
#endif
#define HAL_GENERATOR_ENABLED 0

#endif /* _AP_CONFIG_H_ */
