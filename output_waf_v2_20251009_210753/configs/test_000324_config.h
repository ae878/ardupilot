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

/* ConfigFuzz Test #324 */

/* ConfigFuzz: AP_RCPROTOCOL_EMLID_RCIO_ENABLED */
#ifdef AP_RCPROTOCOL_EMLID_RCIO_ENABLED
#undef AP_RCPROTOCOL_EMLID_RCIO_ENABLED
#endif
#define AP_RCPROTOCOL_EMLID_RCIO_ENABLED 0

/* ConfigFuzz: AP_FOLLOW_ENABLED */
#ifdef AP_FOLLOW_ENABLED
#undef AP_FOLLOW_ENABLED
#endif
#define AP_FOLLOW_ENABLED 1

/* ConfigFuzz: AP_GRIPPER_ENABLED */
#ifdef AP_GRIPPER_ENABLED
#undef AP_GRIPPER_ENABLED
#endif
#define AP_GRIPPER_ENABLED 0

#endif /* _AP_CONFIG_H_ */
