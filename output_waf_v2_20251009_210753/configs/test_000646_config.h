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

/* ConfigFuzz Test #646 */

/* ConfigFuzz: HAL_RCOUT_RGBLED_BLUE */
#ifdef HAL_RCOUT_RGBLED_BLUE
#undef HAL_RCOUT_RGBLED_BLUE
#endif
#define HAL_RCOUT_RGBLED_BLUE 1

/* ConfigFuzz: HAL_WITH_DRONECAN */
#ifdef HAL_WITH_DRONECAN
#undef HAL_WITH_DRONECAN
#endif
#define HAL_WITH_DRONECAN 1

/* ConfigFuzz: CONFIG_LWIP_DHCP_RESTORE_LAST_IP */
#ifdef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#undef CONFIG_LWIP_DHCP_RESTORE_LAST_IP
#endif
#define CONFIG_LWIP_DHCP_RESTORE_LAST_IP 1

/* ConfigFuzz: HAL_RALLY_ENABLED */
#ifdef HAL_RALLY_ENABLED
#undef HAL_RALLY_ENABLED
#endif
#define HAL_RALLY_ENABLED 1

/* ConfigFuzz: BENCH_DEFINE_MAP_IMPLICIT */
#ifdef BENCH_DEFINE_MAP_IMPLICIT
#undef BENCH_DEFINE_MAP_IMPLICIT
#endif
#define BENCH_DEFINE_MAP_IMPLICIT 1

/* ConfigFuzz: HAL_GPIO_OUTPUT */
#ifdef HAL_GPIO_OUTPUT
#undef HAL_GPIO_OUTPUT
#endif
#define HAL_GPIO_OUTPUT 1

#endif /* _AP_CONFIG_H_ */
