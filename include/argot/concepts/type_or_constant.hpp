/*==============================================================================
  Copyright (c) 2017, 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_CONCEPTS_TYPE_OR_CONSTANT_HPP_
#define ARGOT_CONCEPTS_TYPE_OR_CONSTANT_HPP_

//[description
/*`
TypeOrConstant is an [argot_gen_concept] that is satisfied by two arguments that
are the same type, and it is also satisfied when the second argument is a
`std::integral_constant` specialization whose `value_type` is the same as the
first argument type to TypeOrConstant.
*/
//]

#include <argot/concepts/detail/concepts_preprocessing_helpers.hpp>
#include <argot/gen/explicit_concept.hpp>
#include <argot/gen/make_concept_map.hpp>

#ifndef ARGOT_GENERATE_PREPROCESSED_CONCEPTS

#include <type_traits>

#endif  // ARGOT_GENERATE_PREPROCESSED_CONCEPTS

namespace argot {

#define ARGOT_DETAIL_PREPROCESSED_CONCEPT_HEADER_NAME()                        \
s/type_or_constant.h

#ifdef ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER
#include ARGOT_CONCEPTS_DETAIL_PREPROCESSED_HEADER
#else

#include <argot/concepts/detail/preprocess_header_begin.hpp>

ARGOT_CONCEPTS_DETAIL_CREATE_LINE_DIRECTIVE( __LINE__ )

template< class Type, class ExpectedValueType >
ARGOT_EXPLICIT_CONCEPT( TypeOrConstant )
(
);

#include <argot/concepts/detail/preprocess_header_end.hpp>

#endif  // ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER

template< class ExpectedValueType >
struct make_concept_map
< TypeOrConstant< ExpectedValueType, ExpectedValueType > > {};

template< class ExpectedValueType, ExpectedValueType Value >
struct make_concept_map
< TypeOrConstant
  < std::integral_constant< ExpectedValueType, Value >, ExpectedValueType >
> {};

} // namespace argot

#endif  // ARGOT_CONCEPTS_TYPE_OR_CONSTANT_HPP_
