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

/* ConfigFuzz Test #607 */

/* ConfigFuzz: MODE_THROW_ENABLED */
#ifdef MODE_THROW_ENABLED
#undef MODE_THROW_ENABLED
#endif
#define MODE_THROW_ENABLED 1

/* ConfigFuzz: RPMMAX */
#ifdef RPMMAX
#undef RPMMAX
#endif
#define RPMMAX 2

/* ConfigFuzz: AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN */
#ifdef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#undef AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN
#endif
#define AP_NOTIFY_GPIO_LED_RGB_BLUE_PIN 0

/* ConfigFuzz: CONFIG_LWIP_PPP_SUPPORT */
#ifdef CONFIG_LWIP_PPP_SUPPORT
#undef CONFIG_LWIP_PPP_SUPPORT
#endif
#define CONFIG_LWIP_PPP_SUPPORT 1

#endif /* _AP_CONFIG_H_ */
