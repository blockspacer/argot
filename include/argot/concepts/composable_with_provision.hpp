/*==============================================================================
  Copyright (c) 2017, 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_CONCEPTS_COMPOSABLE_WITH_PROVISION_HPP_
#define ARGOT_CONCEPTS_COMPOSABLE_WITH_PROVISION_HPP_

#include <argot/concepts/argument_provider.hpp>
#include <argot/concepts/detail/concepts_preprocessing_helpers.hpp>
#include <argot/concepts/persistent_composable.hpp>
#include <argot/gen/auto_concept.hpp>
#include <argot/gen/make_concept_map.hpp>
#include <argot/gen/transparent_requirement.hpp>

#ifndef ARGOT_GENERATE_PREPROCESSED_CONCEPTS

#include <argot/prov_traits/argument_list_kinds_of_destructive.hpp>
#include <argot/receiver_traits/argument_list_kinds.hpp>
#include <argot/receiver_traits/argument_types.hpp>
#include <argot/detail/remove_cvref.hpp>

#endif  // ARGOT_GENERATE_PREPROCESSED_CONCEPTS

namespace argot {
namespace composable_with_provision_detail {

template< class Ps, class... Transformations >
struct composable_wih_provision_requirements_impl_impl;

template< class... P, class... Transformations >
struct composable_wih_provision_requirements_impl_impl
< receiver_traits::argument_types_t< P... >, Transformations... >
{
  // TODO(mattcalabrese) Make sure result is a valid argument type
  template< template< class... > class Reqs >
  using expand_requirements
    = Reqs< PersistentComposable< P, Transformations... >... >;
};

template< class Kinds, class... Transformations >
struct composable_wih_provision_requirements_impl;

template< class... Kinds, class... Transformations >
struct composable_wih_provision_requirements_impl
< receiver_traits::argument_list_kinds_t< Kinds... >, Transformations... >
{
  template< template< class... > class Reqs >
  using expand_requirements
    = Reqs< TransparentRequirement
            < composable_wih_provision_requirements_impl_impl
              < Kinds, Transformations... >
            >...
          >;
};

template< class Provider, class... Transformations >
struct composable_wih_provision_requirements
{
  template< template< class... > class Reqs >
  using expand_requirements
    = Reqs< TransparentRequirement
            < composable_wih_provision_requirements_impl
              < prov_traits::argument_list_kinds_of_destructive_t< Provider >
              , Transformations...
              >
            >
          >;
};

} // namespace argot(::composable_with_provision_detail)

#define ARGOT_DETAIL_PREPROCESSED_CONCEPT_HEADER_NAME()                        \
s/composable_with_provision.h

#ifdef ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER
#include ARGOT_CONCEPTS_DETAIL_PREPROCESSED_HEADER
#else

#include <argot/concepts/detail/preprocess_header_begin.hpp>

ARGOT_CONCEPTS_DETAIL_CREATE_LINE_DIRECTIVE( __LINE__ )

template< class Provider, class... Transformations >
ARGOT_AUTO_CONCEPT( ComposableWithProvision )
(
  ArgumentProvider< Provider >
, TransparentRequirement
  < composable_with_provision_detail::composable_wih_provision_requirements
    < Provider, Transformations... >
  >
);

#include <argot/concepts/detail/preprocess_header_end.hpp>

#endif  // ARGOT_CONCEPTS_DETAIL_SHOULD_INCLUDE_PREPROCESSED_HEADER

} // namespace argot

#endif  // ARGOT_CONCEPTS_COMPOSABLE_WITH_PROVISION_HPP_
