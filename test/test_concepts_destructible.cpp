/*==============================================================================
  Copyright (c) 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <argot/concepts/destructible.hpp>

#include <argot/gen/concept_ensure.hpp>
#include <argot/gen/not.hpp>

#include "regularity_archetypes.hpp"

namespace {

using argot::Not;
using argot::Destructible;

ARGOT_CONCEPT_ENSURE( Destructible< int > );
ARGOT_CONCEPT_ENSURE( Destructible< int const > );
ARGOT_CONCEPT_ENSURE( Destructible< int volatile > );
ARGOT_CONCEPT_ENSURE( Destructible< int volatile const > );

ARGOT_CONCEPT_ENSURE( Destructible< int[5] > );

ARGOT_CONCEPT_ENSURE( Destructible< argot_test::trivial_destructor > );
ARGOT_CONCEPT_ENSURE( Destructible< argot_test::nothrow_destructor > );
ARGOT_CONCEPT_ENSURE( Destructible< argot_test::exceptional_destructor > );
ARGOT_CONCEPT_ENSURE( Not< Destructible< argot_test::no_destructor > > );

ARGOT_CONCEPT_ENSURE( Not< Destructible< int& > > );

ARGOT_CONCEPT_ENSURE( Not< Destructible< void > > );

ARGOT_CONCEPT_ENSURE( Not< Destructible< int() > > );

ARGOT_CONCEPT_ENSURE( Not< Destructible< int()& > > );

ARGOT_CONCEPT_ENSURE( Not< Destructible< int()& noexcept > > );

ARGOT_CONCEPT_ENSURE( Not< Destructible< int[] > > );

} // namespace
