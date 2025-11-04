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

/* ConfigFuzz Test #927 */

/* ConfigFuzz: USER_PARAMS_ENABLED */
#ifdef USER_PARAMS_ENABLED
#undef USER_PARAMS_ENABLED
#endif
#define USER_PARAMS_ENABLED 1

/* ConfigFuzz: MAVLINK_MSG_ID_AP_ADC */
#ifdef MAVLINK_MSG_ID_AP_ADC
#undef MAVLINK_MSG_ID_AP_ADC
#endif
#define MAVLINK_MSG_ID_AP_ADC 0

/* ConfigFuzz: HAL_CANFD_SUPPORTED */
#ifdef HAL_CANFD_SUPPORTED
#undef HAL_CANFD_SUPPORTED
#endif
#define HAL_CANFD_SUPPORTED 0

#endif /* _AP_CONFIG_H_ */
