/*==============================================================================
  Copyright (c) 2016, 2017, 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_DETAIL_UNREACHABLE_HPP_
#define ARGOT_DETAIL_UNREACHABLE_HPP_

#include <boost/assert.hpp>

#define ARGOT_DETAIL_UNREACHABLE_FALLBACK()                                    \
/*::std::quick_exit( EXIT_FAILURE )*/                                          \
( static_cast< void >( BOOST_ASSERT( false ) )                                 \
, static_cast< void >( ::std::exit( EXIT_FAILURE ) )                           \
)

#ifdef __has_builtin
#if __has_builtin( __builtin_unreachable )
#define ARGOT_DETAIL_UNREACHABLE()                                             \
( static_cast< void >( BOOST_ASSERT( false ) )                                 \
, static_cast< void >( __builtin_unreachable() )                               \
)
#else
#include <cstdlib>
#define ARGOT_DETAIL_UNREACHABLE() ARGOT_DETAIL_UNREACHABLE_FALLBACK()
#endif
#else
#include <cstdlib>
#define ARGOT_DETAIL_UNREACHABLE() ARGOT_DETAIL_UNREACHABLE_FALLBACK()
#endif

#endif  // ARGOT_DETAIL_UNREACHABLE_HPP_
