/*==============================================================================
  Copyright (c) 2016, 2017, 2018, 2019 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_PROV_DEFAULT_TO_VALUE_OF_HPP_
#define ARGOT_PROV_DEFAULT_TO_VALUE_OF_HPP_

//[description
/*`
prov::default_to_value_of is a facility for binding arguments by value into an
ArgumentProvider. For each argument that is /not/ an ArgumentProvider, that
argument is passed during provision. For each argument that /is/ an
ArgumentProvider, that ArgumentProvider is expanded in-place in the argument
list during provision.

[global_function_object_designator]
*/
//]

#include <argot/basic_result_of.hpp>
#include <argot/concepts/argument_provider.hpp>
#include <argot/concepts/sinkable.hpp>
#include <argot/detail/conditional.hpp>
#include <argot/detail/forward.hpp>
#include <argot/detail/sink.hpp>
#include <argot/gen/is_modeled.hpp>
#include <argot/gen/requires.hpp>
#include <argot/prov/group.hpp>
#include <argot/prov/value_of.hpp>

//[docs
/*`
[synopsis_heading]
*/

namespace argot::prov {

struct default_to_value_of_fn
{
  //<-
 private:
  struct provider_forwarder
  {
    template< class T >
    static constexpr decltype( auto ) run( T&& arg ) noexcept
    {
      return call_detail::forward_and_sink< T >( arg );
    }
  };

  struct provider_maker
  {
    template< class T >
    static constexpr auto run( T&& arg ) noexcept
    {
      return prov::value_of( call_detail::forward_and_sink< T >( arg ) );
    }
  };
 public:
 //->
  template< class... P
          , ARGOT_REQUIRES
            ( Sinkable< P&& >... )
            ()
          >
  [[nodiscard]]
  constexpr auto operator ()( P&&... args ) const//=;
  //<-
  {
    return prov::group
    ( argot_detail::conditional
      < is_modeled_v< ArgumentProvider< detail_argot::remove_cvref_t< P > > > >
      ::template apply< provider_forwarder, provider_maker >
      ::run( ARGOT_FORWARD( P )( args ) )...
    );
  } //->
} inline constexpr default_to_value_of{};

template< class... P >
using result_of_default_to_value_of//= = ``[see_prologue_result_of]``;
//<-
  = basic_result_of< default_to_value_of_fn const&, P... >; //->

template< class... P >
using result_of_default_to_value_of_t//= = ``[see_prologue_result_of]``;
//<-
  = basic_result_of_t< default_to_value_of_fn const&, P... >; //->

} // namespace (argot::prov)

/*`
[table Parameters
 [[Parameter][Requirement][Description]]
 [[`P&&... args`]
  [Each of `P&&...` is Sinkable.]
  [The entities that will be contained]
 ]
]

[provider_properties_heading]

[table Resultant Provider
 [[Property][Description]]
 [[Logical Provision]
  [For each entity that is /not/ an ArgumentProvider, a reference to each of the
   objects that was captured, in-place in the argument list. For each entity
   that /is/ an ArgumentProvider, the arguments that ArgumentProvider provides,
   in-place in the argument list.
  ]
 ]
 [[Possible Argument Types of Destructive Provision]
  [ //TODO(mattcalabrese) Describe]
 ]
 [[Possible Argument Types of Persistent Provision]
  [ //TODO(mattcalabrese) Describe]
 ]
]
*/

//]

#endif  // ARGOT_PROV_DEFAULT_TO_VALUE_OF_HPP_
