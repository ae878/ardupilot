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

/* ConfigFuzz Test #157 */

/* ConfigFuzz: AP_ICENGINE_ENABLED */
#ifdef AP_ICENGINE_ENABLED
#undef AP_ICENGINE_ENABLED
#endif
#define AP_ICENGINE_ENABLED 1

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 1

/* ConfigFuzz: HAVE_ENUM_CAMERA_CAP_FLAGS */
#ifdef HAVE_ENUM_CAMERA_CAP_FLAGS
#undef HAVE_ENUM_CAMERA_CAP_FLAGS
#endif
#define HAVE_ENUM_CAMERA_CAP_FLAGS 0

/* ConfigFuzz: MODE_AUTOROTATE_ENABLED */
#ifdef MODE_AUTOROTATE_ENABLED
#undef MODE_AUTOROTATE_ENABLED
#endif
#define MODE_AUTOROTATE_ENABLED 0

/* ConfigFuzz: HAL_IMUHEAT_P_DEFAULT */
#ifdef HAL_IMUHEAT_P_DEFAULT
#undef HAL_IMUHEAT_P_DEFAULT
#endif
#define HAL_IMUHEAT_P_DEFAULT 0

#endif /* _AP_CONFIG_H_ */
