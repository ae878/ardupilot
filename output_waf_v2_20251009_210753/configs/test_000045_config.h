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

/* ConfigFuzz Test #45 */

/* ConfigFuzz: MAVLINK_ENABLED_DEVELOPMENT */
#ifdef MAVLINK_ENABLED_DEVELOPMENT
#undef MAVLINK_ENABLED_DEVELOPMENT
#endif
#define MAVLINK_ENABLED_DEVELOPMENT 1

/* ConfigFuzz: FS_THR_ENABLED_AUTO_RTL_OR_RTL */
#ifdef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#undef FS_THR_ENABLED_AUTO_RTL_OR_RTL
#endif
#define FS_THR_ENABLED_AUTO_RTL_OR_RTL 1

/* ConfigFuzz: MAVLINK_MSG_ID_MOUNT_CONFIGURE */
#ifdef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#undef MAVLINK_MSG_ID_MOUNT_CONFIGURE
#endif
#define MAVLINK_MSG_ID_MOUNT_CONFIGURE 1

#endif /* _AP_CONFIG_H_ */
