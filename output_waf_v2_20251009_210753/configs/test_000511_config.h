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

/* ConfigFuzz Test #511 */

/* ConfigFuzz: MAVLINK_ENABLED_LOWEHEISER */
#ifdef MAVLINK_ENABLED_LOWEHEISER
#undef MAVLINK_ENABLED_LOWEHEISER
#endif
#define MAVLINK_ENABLED_LOWEHEISER 1

/* ConfigFuzz: AP_HAL_SHARED_DMA_ENABLED */
#ifdef AP_HAL_SHARED_DMA_ENABLED
#undef AP_HAL_SHARED_DMA_ENABLED
#endif
#define AP_HAL_SHARED_DMA_ENABLED 1

/* ConfigFuzz: AC_PAYLOAD_PLACE_ENABLED */
#ifdef AC_PAYLOAD_PLACE_ENABLED
#undef AC_PAYLOAD_PLACE_ENABLED
#endif
#define AC_PAYLOAD_PLACE_ENABLED 1

#endif /* _AP_CONFIG_H_ */
