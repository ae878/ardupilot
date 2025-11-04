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

/* ConfigFuzz Test #722 */

/* ConfigFuzz: USER_PARAMS_ENABLED */
#ifdef USER_PARAMS_ENABLED
#undef USER_PARAMS_ENABLED
#endif
#define USER_PARAMS_ENABLED 0

/* ConfigFuzz: AP_FOLLOW_ENABLED */
#ifdef AP_FOLLOW_ENABLED
#undef AP_FOLLOW_ENABLED
#endif
#define AP_FOLLOW_ENABLED 1

/* ConfigFuzz: HAL_BATT_CURR_PIN */
#ifdef HAL_BATT_CURR_PIN
#undef HAL_BATT_CURR_PIN
#endif
#define HAL_BATT_CURR_PIN 0

/* ConfigFuzz: AP_EXTERNAL_CONTROL_ENABLED */
#ifdef AP_EXTERNAL_CONTROL_ENABLED
#undef AP_EXTERNAL_CONTROL_ENABLED
#endif
#define AP_EXTERNAL_CONTROL_ENABLED 0

/* ConfigFuzz: LEDDARONE_SERIAL_PORT_MAX */
#ifdef LEDDARONE_SERIAL_PORT_MAX
#undef LEDDARONE_SERIAL_PORT_MAX
#endif
#define LEDDARONE_SERIAL_PORT_MAX 4

/* ConfigFuzz: AP_MODULE_SUPPORTED */
#ifdef AP_MODULE_SUPPORTED
#undef AP_MODULE_SUPPORTED
#endif
#define AP_MODULE_SUPPORTED 1

#endif /* _AP_CONFIG_H_ */
