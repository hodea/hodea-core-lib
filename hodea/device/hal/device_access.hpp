// Copyright (c) 2017, Franz Hollerer. All rights reserved.
// This code is licensed under the MIT License (MIT).
// See LICENSE file for full details.

/**
 * Types and classes supporting low level access to peripheral devices.
 *
 * \author f.hollerer@gmx.net
 */
#if !defined _HODEA_HAL_DEVICE_ACCESS_HPP_
#define _HODEA_HAL_DEVICE_ACCESS_HPP_

#include <hodea/device/hal/device_properties.hpp>

#if defined HODEA_DERIVED_CONFIG_BRAND_STM32
#include <hodea/device/stm32/device_access.hpp>
#elif defined HODEA_DERIVED_CONFIG_BRAND_IMX_M4
#include <hodea/device/imx_m4/device_access.hpp>
#else
#error "Unsupported device."
#endif

#endif /*!_HODEA_HAL_DEVICE_ACCESS_HPP_ */
