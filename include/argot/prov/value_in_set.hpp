/*==============================================================================
  Copyright (c) 2016, 2017, 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_PROV_VALUE_IN_SET_HPP_
#define ARGOT_PROV_VALUE_IN_SET_HPP_

//[description
/*`
prov::value_in_set is used to "convert" a run-time value to its corresponding
`std::integral_constant` when the value is one of a finite set of possible
values that are known at compile-time.

It takes a type that is a valid SwitchCondition, followed by a variadic list of
unique values of that type, all as explicit template arguments, and also takes
in /value/ and a Default. It returns an ArgumentProvider that provides the
/value/ as a `std::integral_constant` instantiation if the value is a member of
the set, otherwise the resultant ArgumentProvider provides whatever the Default
provides. If a Default parameter is not explicitly passed as an argument, it
defaults to argot::default_unreachable. The ArgumentProvider is a
/persistent default/ for `ValueType`.

[note If the set of possible values is a contiguous range of values, prefer
      using prov::value_in_range instead, as it will likely have better
      compile-time performance and may have better run-time performance.
]

[global_function_object_template_designator]
*/
//]

#include <argot/basic_result_of.hpp>
#include <argot/case/case_set.hpp>
#include <argot/concepts/convertible_to_type_or_constant.hpp>
#include <argot/concepts/default.hpp>
#include <argot/concepts/sinkable.hpp>
#include <argot/concepts/std_integral_constant.hpp>
#include <argot/concepts/switch_condition.hpp>
#include <argot/default_.hpp>
#include <argot/detail/forward.hpp>
#include <argot/gen/concept_assert.hpp>
#include <argot/gen/is_modeled.hpp>
#include <argot/gen/requires.hpp>
#include <argot/detail/move.hpp>
#include <argot/prov/switch_.hpp>
#include <argot/detail/remove_cvref.hpp>

#include <type_traits>

//[docs
/*`
[synopsis_heading]
*/

namespace argot::prov {

template< class ValueType, ValueType... Values >
struct value_in_set_fn
{
//<-
  ARGOT_CONCEPT_ASSERT( SwitchCondition< ValueType > );
// TODO(mattcalabrese) Make sure no duplicates.
//->
  template< class Type, class Def = argot::default_unreachable_t
          , ARGOT_REQUIRES
            ( ConvertibleToTypeOrConstant< Type, ValueType > )
            ( Default< detail_argot::remove_cvref_t< Def > > )
            ( Sinkable< Def&& > )
            ()
          >
  [[nodiscard]]
  constexpr auto operator ()( Type&& value, Def&& def = {} ) const//=;
  //<-
  {
    if constexpr
    ( ARGOT_IS_MODELED
      ( StdIntegralConstant< detail_argot::remove_cvref_t< Type > > )
    )
      return prov::switch_
      ( std::integral_constant
        < ValueType, detail_argot::remove_cvref_t< Type >::value >()
      , argot::case_set< Values... >.as_constant
      , ARGOT_FORWARD( Def )( def )
      );
    else
    {
      ValueType const typed_value = ARGOT_FORWARD( Type )( value );

      return prov::switch_( typed_value
                          , argot::case_set< Values... >.as_constant
                          , ARGOT_FORWARD( Def )( def )
                          );
    }
  }
  //->
};

// TODO(mattcalabrese) Make sure no duplicates.
template< class ValueType, ValueType... Values >
ARGOT_REQUIRES( SwitchCondition< ValueType > )
< value_in_set_fn< ValueType, Values... > > constexpr value_in_set{};

// TODO(mattcalabrese) Result of calculators

} // namespace (argot::prov)

/*`
[table Explicit Template Parameters
 [[Parameter][Requirement][Description]]
 [[`class ValueType`]
  [A SwitchCondition type]
  [The value_type of the `std::integral_constant` to be provided]
 ]
 [[`ValueType... Values`]
  [Unique values of type `ValueType`]
  [The set of possible `std::integral_constant` instantations to be provided
  ]
 ]
]

[table Function Parameters
 [[Parameter][Requirement][Description]]
 [[`Index index`]
  [A value of the /index/ type of `ValueType`, or `std::integral_constant` of
   `ValueType`, where the value is one of the values of `Values...` )
  ]
  [The value that is to be provided in the form of a `std::integral_constant`
   instantiation
  ]
 ]
]

[provider_properties_heading]

[table Resultant Provider
 [[Property][Dynamic Index][Static Index in Range][Static Index Not in Range]]
 [[Logical Provision]
  [The /value/ as a `std::integral_constant` instantiation or what `Def`
   provides when passed /value/
  ]
  [The /value/ as a `std::integral_constant` instantiation]
  [What `Def` provides when passed /value/]
 ]
 [[Possible Argument Types]
  [[itemized_list [```( std::integral_constant< ValueType, Values > )...```]]
   [itemized_list [[~The possible argument list kinds of `Def`]]]
  ]
  [[itemized_list [```( std::integral_constant< ValueType, index.value > )```]]]
  [[itemized_list [[~The possible argument list kinds of `Def`]]]]
 ]
]
*/

//]

#endif  // ARGOT_PROV_VALUE_IN_SET_HPP_
