/*==============================================================================
  Copyright (c) 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_CONCEPTS_GREATER_THAN_COMPARABLE_HPP_
#define ARGOT_CONCEPTS_GREATER_THAN_COMPARABLE_HPP_

//[description
/*`
GreaterThanComparable is an [argot_gen_concept] that is satisfied by types `T`
for which two lvalue expressions of type `T const` are valid operands to
`operator >` and such an invocation returns a type that is
[contextually_convertible_to_bool]. Types that satisfy this requirement are also
expected to be a proper strict inequality relation, that is to say the operation
should be:
*/
//]

#include <argot/concepts/detail/concepts_preprocessing_helpers.hpp>
#include <argot/concepts/object.hpp>
#include <argot/detail/declval.hpp>
#include <argot/gen/explicit_concept.hpp>
#include <argot/gen/make_concept_map.hpp>

#ifndef ARGOT_GENERATE_PREPROCESSED_CONCEPTS

#include <argot/detail/detection.hpp>

#include <type_traits>

#endif  // ARGOT_GENERATE_PREPROCESSED_CONCEPTS

namespace argot {

#define ARGOT_DETAIL_PREPROCESSED_CONCEPT_HEADER_NAME()                        \
s/greater_than_comparable.h

#ifdef ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER
#include ARGOT_CONCEPTS_DETAIL_PREPROCESSED_HEADER
#else

#include <argot/concepts/detail/preprocess_header_begin.hpp>

ARGOT_CONCEPTS_DETAIL_CREATE_LINE_DIRECTIVE( __LINE__ )

template< class T >
ARGOT_EXPLICIT_CONCEPT( GreaterThanComparable )
(
  Object< T >
);

#include <argot/concepts/detail/preprocess_header_end.hpp>

#endif  // ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER

template< class T >
struct make_concept_map
< GreaterThanComparable< T >
, typename call_detail::detached_fast_enable_if
  < std::is_object_v< T > >::_::template and_
  < !std::is_array_v< T > >::_::template and_
  <    sizeof
       (   ( ARGOT_DECLVAL( T const& ) > ARGOT_DECLVAL( T const& ) )
          ? true : false
       )
    != 0
  >::void_
> {};

} // namespace argot

#endif  // ARGOT_CONCEPTS_GREATER_THAN_COMPARABLE_HPP_
