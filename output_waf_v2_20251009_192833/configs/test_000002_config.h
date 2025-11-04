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

/* ConfigFuzz Test #2 */

/* ConfigFuzz: AP_SCHEDULER_OVERTIME_MARGIN_US */
#ifdef AP_SCHEDULER_OVERTIME_MARGIN_US
#undef AP_SCHEDULER_OVERTIME_MARGIN_US
#endif
#define AP_SCHEDULER_OVERTIME_MARGIN_US 0

/* ConfigFuzz: HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS */
#ifdef HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS
#undef HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS
#endif
#define HAVE_ENUM_GIMBAL_DEVICE_CAP_FLAGS 1

/* ConfigFuzz: AP_SIM_ENABLED */
#ifdef AP_SIM_ENABLED
#undef AP_SIM_ENABLED
#endif
#define AP_SIM_ENABLED 0

/* ConfigFuzz: CONFIG_LWIP_STATS */
#ifdef CONFIG_LWIP_STATS
#undef CONFIG_LWIP_STATS
#endif
#define CONFIG_LWIP_STATS 1

/* ConfigFuzz: FS_THR_ENABLED_ALWAYS_RTL */
#ifdef FS_THR_ENABLED_ALWAYS_RTL
#undef FS_THR_ENABLED_ALWAYS_RTL
#endif
#define FS_THR_ENABLED_ALWAYS_RTL 0

/* ConfigFuzz: HAL_UART_IOMCU_IDX */
#ifdef HAL_UART_IOMCU_IDX
#undef HAL_UART_IOMCU_IDX
#endif
#define HAL_UART_IOMCU_IDX 0

#endif /* _AP_CONFIG_H_ */
