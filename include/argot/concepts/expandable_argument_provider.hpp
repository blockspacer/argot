/*==============================================================================
  Copyright (c) 2017, 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_CONCEPTS_EXPANDABLE_ARGUMENT_PROVIDER_HPP_
#define ARGOT_CONCEPTS_EXPANDABLE_ARGUMENT_PROVIDER_HPP_

#include <argot/concepts/argument_provider.hpp>
#include <argot/concepts/detail/concepts_preprocessing_helpers.hpp>
#include <argot/gen/explicit_concept.hpp>
#include <argot/gen/make_concept_map.hpp>

namespace argot {
namespace expandable_argument_provider_detail {

template< class Provider >
struct all_provisions_are_expandables;

}

// TODO(mattcalabrese) Implement this purely via the concepts

#define ARGOT_DETAIL_PREPROCESSED_CONCEPT_HEADER_NAME()                        \
s/expandable_argument_provider.h

#ifdef ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER
#include ARGOT_CONCEPTS_DETAIL_PREPROCESSED_HEADER
#else

#include <argot/concepts/detail/preprocess_header_begin.hpp>

ARGOT_CONCEPTS_DETAIL_CREATE_LINE_DIRECTIVE( __LINE__ )

template< class Provider >
ARGOT_EXPLICIT_CONCEPT( ExpandableArgumentProvider )
(
  ArgumentProvider< Provider >/*
, TransparentRequirement
  < expandable_argument_provider_detail::all_provisions_are_providers >*/
);

#include <argot/concepts/detail/preprocess_header_end.hpp>

#endif  // ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER

} // namespace argot

#ifndef ARGOT_GENERATE_PREPROCESSED_CONCEPTS

#include <argot/detail/detection.hpp>
#include <argot/concepts/expandable_argument_provider/detail/is_expandable_argument_provider.hpp>

namespace argot {

// TODO(mattcalabrese) Perform each ArgumentProvider check separately in SFINAE
template< class Provider >
struct make_concept_map
< ExpandableArgumentProvider< Provider >
, call_detail::fast_enable_if_t
  < expandable_argument_provider_detail
    ::is_expandable_argument_provider_v< Provider >
  >
> {};

} // namespace argot

#endif  // ARGOT_GENERATE_PREPROCESSED_CONCEPTS

#endif  // ARGOT_CONCEPTS_EXPANDABLE_ARGUMENT_PROVIDER_HPP_
