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

/* ConfigFuzz Test #259 */

/* ConfigFuzz: HAL_BATT_VOLT_PIN */
#ifdef HAL_BATT_VOLT_PIN
#undef HAL_BATT_VOLT_PIN
#endif
#define HAL_BATT_VOLT_PIN 0

/* ConfigFuzz: MAVLINK_ENABLED_DEVELOPMENT */
#ifdef MAVLINK_ENABLED_DEVELOPMENT
#undef MAVLINK_ENABLED_DEVELOPMENT
#endif
#define MAVLINK_ENABLED_DEVELOPMENT 0

/* ConfigFuzz: FS_GCS_ENABLED_ALWAYS_LAND */
#ifdef FS_GCS_ENABLED_ALWAYS_LAND
#undef FS_GCS_ENABLED_ALWAYS_LAND
#endif
#define FS_GCS_ENABLED_ALWAYS_LAND 0

#endif /* _AP_CONFIG_H_ */
