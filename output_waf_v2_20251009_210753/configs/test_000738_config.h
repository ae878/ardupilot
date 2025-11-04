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

/* ConfigFuzz Test #738 */

/* ConfigFuzz: MAXSONAR_SERIAL_LV_BAUD_RATE */
#ifdef MAXSONAR_SERIAL_LV_BAUD_RATE
#undef MAXSONAR_SERIAL_LV_BAUD_RATE
#endif
#define MAXSONAR_SERIAL_LV_BAUD_RATE 2

/* ConfigFuzz: LEDDARONE_DETECTIONS_MAX */
#ifdef LEDDARONE_DETECTIONS_MAX
#undef LEDDARONE_DETECTIONS_MAX
#endif
#define LEDDARONE_DETECTIONS_MAX 16

/* ConfigFuzz: AC_PAYLOAD_PLACE_ENABLED */
#ifdef AC_PAYLOAD_PLACE_ENABLED
#undef AC_PAYLOAD_PLACE_ENABLED
#endif
#define AC_PAYLOAD_PLACE_ENABLED 0

/* ConfigFuzz: HAL_INS_RATE_LOOP */
#ifdef HAL_INS_RATE_LOOP
#undef HAL_INS_RATE_LOOP
#endif
#define HAL_INS_RATE_LOOP 1

#endif /* _AP_CONFIG_H_ */
