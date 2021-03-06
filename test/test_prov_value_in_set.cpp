/*==============================================================================
  Copyright (c) 2016, 2017, 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <argot/concepts/same_type.hpp>
#include <argot/gen/concept_ensure.hpp>
#include <argot/detail/constexpr_test.hpp>
#include <argot/discriminated_union.hpp>
#include <argot/prov/value_in_set.hpp>
#include <argot/prov_traits/provide.hpp>
#include <argot/receiver/return_single_argument_value.hpp>
#include <argot/variant_traits/index_of.hpp>

#include <cstddef>
#include <type_traits>

namespace {

namespace prov = argot::prov;
namespace prov_traits = argot::prov_traits;
namespace receiver = argot::receiver;
namespace variant_traits = argot::variant_traits;

using argot::SameType;

using argot::discriminated_union;
using prov::value_in_set;
using prov::value_in_set_fn;

// TODO(mattcalabrese) Test non-dynamic and test defaults
ARGOT_REGISTER_CONSTEXPR_TEST( test_dynamic )
{
  using int_type = short;

  using object_type
    = decltype( value_in_set< int_type, -3, -2, -1, 0, 1 > );

  auto constexpr object = value_in_set< int_type, -3, -2, -1, 0, 1 >;

  ARGOT_CONCEPT_ENSURE
  ( SameType
    < object_type
    , value_in_set_fn< int_type, -3, -2, -1, 0, 1 > const
    >
  );

  auto provider_neg_3 = object( int_type{ -3 } );
  auto provider_neg_2 = object( int_type{ -2 } );
  auto provider_neg_1 = object( int_type{ -1 } );
  auto provider_0 = object( int_type{ 0 } );
  auto provider_1 = object( int_type{ 1 } );

  // -3
  {
    // lvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( provider_neg_3
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 0 );
    }

    // rvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( std::move( provider_neg_3 )
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 0 );
    }

  }

  // -2
  {
    // lvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( provider_neg_2
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 1 );
    }

    // rvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( std::move( provider_neg_2 )
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 1 );
    }
  }

  // -1
  {
    // lvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( provider_neg_1
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 2 );
    }

    // rvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( std::move( provider_neg_1 )
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 2 );
    }
  }

  // 0
  {
    // lvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( provider_0
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 3 );
    }

    // rvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( std::move( provider_0 )
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 3 );
    }
  }

  // 1
  {
    // lvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( provider_1
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 4 );
    }

    // rvalue provision
    {
      decltype( auto ) provision_result
        = prov_traits::provide
          ( std::move( provider_1 )
          , receiver::return_single_argument_value()
          );

      using provision_result_type = decltype( provision_result );

      ARGOT_CONCEPT_ENSURE
      ( SameType
        < provision_result_type
        , discriminated_union
          < std::integral_constant< short, -3 >
          , std::integral_constant< short, -2 >
          , std::integral_constant< short, -1 >
          , std::integral_constant< short, 0 >
          , std::integral_constant< short, 1 >
          >
        >
      );

      ARGOT_TEST_EQ( variant_traits::index_of( provision_result ), 4 );
    }
  }

  return 0;
}

ARGOT_EXECUTE_TESTS();

}  // namespace
