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

/* ConfigFuzz Test #21 */

/* ConfigFuzz: LEDDARONE_SERIAL_PORT_MAX */
#ifdef LEDDARONE_SERIAL_PORT_MAX
#undef LEDDARONE_SERIAL_PORT_MAX
#endif
#define LEDDARONE_SERIAL_PORT_MAX 32

/* ConfigFuzz: MODE_RTL_ENABLED */
#ifdef MODE_RTL_ENABLED
#undef MODE_RTL_ENABLED
#endif
#define MODE_RTL_ENABLED 0

/* ConfigFuzz: MODE_AUTOROTATE_ENABLED */
#ifdef MODE_AUTOROTATE_ENABLED
#undef MODE_AUTOROTATE_ENABLED
#endif
#define MODE_AUTOROTATE_ENABLED 0

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 0

/* ConfigFuzz: HAL_AHRS_EKF_TYPE_DEFAULT */
#ifdef HAL_AHRS_EKF_TYPE_DEFAULT
#undef HAL_AHRS_EKF_TYPE_DEFAULT
#endif
#define HAL_AHRS_EKF_TYPE_DEFAULT 0

#endif /* _AP_CONFIG_H_ */
