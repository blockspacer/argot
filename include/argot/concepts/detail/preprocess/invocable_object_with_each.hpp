/*==============================================================================
  Copyright (c) 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
# line 27 "../../concepts/invocable_object_with_each.hpp"
template< class Invocable, class... ArgumentListKinds >
struct InvocableObjectWithEach { static bool constexpr argot_gen_detail_is_auto_concept_v = true; template< class ArgotDetailSelf > using argot_gen_detail_is_modeled_impl = ::argot::auto_concept_detail::is_modeled_impl< ArgotDetailSelf >; using requirements = typename ::argot::requires_detail::requires_impl< UnqualifiedObject< Invocable > , InvocableWithEach< Invocable&&, ArgumentListKinds... > >::type; struct assertion : requirements::assertion {}; };
# undef ARGOT_DETAIL_PREPROCESSED_CONCEPT_HEADER_NAME
