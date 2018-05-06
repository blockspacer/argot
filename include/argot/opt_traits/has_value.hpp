/*==============================================================================
  Copyright (c) 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_OPT_TRAITS_HAS_VALUE_HPP_
#define ARGOT_OPT_TRAITS_HAS_VALUE_HPP_

#include <argot/basic_result_ofs.hpp>
#include <argot/concepts/optional_like.hpp>
#include <argot/gen/access_raw_concept_map.hpp>
#include <argot/gen/requires.hpp>

namespace argot::opt_traits {

struct has_value_fn
{
  template< class T, ARGOT_REQUIRES( OptionalLike< T > )() >
  constexpr bool operator ()( T const& opt ) const
  {
    return access_raw_concept_map< OptionalLike< T > >::has_value( opt );
  }
};

template< class T >
using result_of_has_value_t
  = basic_result_of_t< has_value_fn const&, T >;

template< class T >
using result_of_has_value
  = basic_result_of< has_value_fn const&, T >;

}  // namespace (argot::opt_traits)

#endif  // ARGOT_OPT_TRAITS_HAS_VALUE_HPP_
