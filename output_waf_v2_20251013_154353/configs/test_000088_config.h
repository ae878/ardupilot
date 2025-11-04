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

/* ConfigFuzz Test #88 */

/* ConfigFuzz: HAL_HAVE_DUAL_USB_CDC */
#ifdef HAL_HAVE_DUAL_USB_CDC
#undef HAL_HAVE_DUAL_USB_CDC
#endif
#define HAL_HAVE_DUAL_USB_CDC 1

/* ConfigFuzz: AP_OPTICALFLOW_ENABLED */
#ifdef AP_OPTICALFLOW_ENABLED
#undef AP_OPTICALFLOW_ENABLED
#endif
#define AP_OPTICALFLOW_ENABLED 1

/* ConfigFuzz: AP_NETWORKING_NUM_PORTS */
#ifdef AP_NETWORKING_NUM_PORTS
#undef AP_NETWORKING_NUM_PORTS
#endif
#define AP_NETWORKING_NUM_PORTS 1

/* ConfigFuzz: MAVLINK_MSG_ID_AP_ADC_CRC */
#ifdef MAVLINK_MSG_ID_AP_ADC_CRC
#undef MAVLINK_MSG_ID_AP_ADC_CRC
#endif
#define MAVLINK_MSG_ID_AP_ADC_CRC 0

#endif /* _AP_CONFIG_H_ */
