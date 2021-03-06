// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * Utilities to make use of scoped enums more convenient.
 *
 * \author f.hollerer@hodea.org
 */
#if !defined HODEA_SCOPED_ENUM_OR_OPERATOR_HPP
#define HODEA_SCOPED_ENUM_OR_OPERATOR_HPP

#include <type_traits>

/**
 * Cast enum to its underlying type.
 */
template <
    typename T,
    typename = typename std::enable_if<std::is_enum<T>::value>::type,
    typename T_underlying = typename std::underlying_type<T>::type 
    >
constexpr T_underlying enum_to_underlying(T e) noexcept
{
    return static_cast<T_underlying>(e);
}

/**
 * Provide or operator in order to use scoped enums for bitmasks.
 */
#define DEFINE_SCOPED_ENUM_OR_OPERATOR(Enum) \
static inline constexpr Enum operator |(Enum lhs, Enum rhs)             \
{                                                                       \
    return static_cast<Enum>(                                           \
                enum_to_underlying(lhs) | enum_to_underlying(rhs)       \
                );                                                      \
}


#endif /*!HODEA_SCOPED_ENUM_OR_OPERATOR_HPP */
