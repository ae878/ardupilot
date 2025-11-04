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

/* ConfigFuzz Test #916 */

/* ConfigFuzz: MAX_PWMS */
#ifdef MAX_PWMS
#undef MAX_PWMS
#endif
#define MAX_PWMS 2

/* ConfigFuzz: HAL_FLASH_PROTECTION */
#ifdef HAL_FLASH_PROTECTION
#undef HAL_FLASH_PROTECTION
#endif
#define HAL_FLASH_PROTECTION 0

/* ConfigFuzz: LEDDARONE_DETECTIONS_MAX */
#ifdef LEDDARONE_DETECTIONS_MAX
#undef LEDDARONE_DETECTIONS_MAX
#endif
#define LEDDARONE_DETECTIONS_MAX 16

/* ConfigFuzz: HAL_EXTERNAL_AHRS_DEFAULT */
#ifdef HAL_EXTERNAL_AHRS_DEFAULT
#undef HAL_EXTERNAL_AHRS_DEFAULT
#endif
#define HAL_EXTERNAL_AHRS_DEFAULT 1

/* ConfigFuzz: MODE_AUTO_ENABLED */
#ifdef MODE_AUTO_ENABLED
#undef MODE_AUTO_ENABLED
#endif
#define MODE_AUTO_ENABLED 0

/* ConfigFuzz: HAL_SOLO_GIMBAL_ENABLED */
#ifdef HAL_SOLO_GIMBAL_ENABLED
#undef HAL_SOLO_GIMBAL_ENABLED
#endif
#define HAL_SOLO_GIMBAL_ENABLED 1

#endif /* _AP_CONFIG_H_ */
