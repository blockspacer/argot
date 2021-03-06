/*==============================================================================
  Copyright (c) 2017, 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_CONCEPTS_BOOL_OR_CONSTANT_HPP_
#define ARGOT_CONCEPTS_BOOL_OR_CONSTANT_HPP_

//[description
/*`
BoolOrConstant is an [argot_gen_concept] that is satisfied only by `bool`,
`std::false_type`, and `std::true_type`.
*/
//]

#include <argot/concepts/detail/concepts_preprocessing_helpers.hpp>
#include <argot/concepts/type_or_constant.hpp>

namespace argot {

template< class Type >
using BoolOrConstant = TypeOrConstant< Type, bool >;

} // namespace argot

#endif  // ARGOT_CONCEPTS_BOOL_OR_CONSTANT_HPP_
