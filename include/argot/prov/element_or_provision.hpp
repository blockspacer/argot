/*==============================================================================
  Copyright (c) 2017, 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_PROV_ELEMENT_OR_PROVISION_HPP_
#define ARGOT_PROV_ELEMENT_OR_PROVISION_HPP_

#include <argot/basic_result_of.hpp>
#include <argot/concepts/argument_provider.hpp>
#include <argot/concepts/argument_receiver_of_kinds.hpp>
#include <argot/concepts/optional_like.hpp>
#include <argot/concepts/persistent_argument_provider.hpp>
#include <argot/concepts/reference.hpp>
#include <argot/concepts/sinkable.hpp>
#include <argot/concepts/volatile_object.hpp>
#include <argot/detail/sink.hpp>
#include <argot/forward.hpp>
#include <argot/gen/concept_assert.hpp>
#include <argot/gen/make_concept_map.hpp>
#include <argot/gen/not.hpp>
#include <argot/gen/requires.hpp>
#include <argot/move.hpp>
#include <argot/no_unique_address.hpp>
#include <argot/opt_traits/get.hpp>
#include <argot/opt_traits/has_value.hpp>
#include <argot/prov_traits/argument_list_kinds_of_destructive.hpp>
#include <argot/prov_traits/argument_list_kinds_of_persistent.hpp>
#include <argot/receiver_traits/argument_list_kinds.hpp>
#include <argot/receiver_traits/argument_types.hpp>
#include <argot/receiver_traits/branch_to_provision.hpp>
#include <argot/receiver_traits/receive_branch.hpp>
#include <argot/remove_cvref.hpp>

#include <memory>
#include <type_traits>

namespace argot {
namespace prov {

struct element_or_provision_fn
{
  template< class Opt, class Provider >
  struct impl
  {
    ARGOT_CONCEPT_ASSERT( OptionalLike< remove_cvref_t< Opt > > );
    ARGOT_CONCEPT_ASSERT( Not< VolatileObject< remove_cvref_t< Opt > > > );
    ARGOT_CONCEPT_ASSERT( Reference< Opt > );
    ARGOT_CONCEPT_ASSERT( ArgumentProvider< Provider > );

    std::remove_reference_t< Opt >* opt;
    ARGOT_NO_UNIQUE_ADDRESS Provider provider;
  };

  template< class Opt, class Provider
          , ARGOT_REQUIRES( OptionalLike< remove_cvref_t< Opt > > )
                          ( Not< VolatileObject< remove_cvref_t< Opt > > > )
                          ( ArgumentProvider< remove_cvref_t< Provider > > )
                          ( Sinkable< Provider&& > )
                          ()
          >
  [[nodiscard]]
  constexpr auto operator ()( Opt&& opt, Provider&& provider ) const
  {
    return impl< Opt&&, remove_cvref_t< Provider > >
    { std::addressof( opt ), ARGOT_FORWARD_AND_SINK( Provider )( provider ) };
  }
} inline constexpr element_or_provision{};

template< class Opt, class Provider >
using result_of_element_or_provision
  = basic_result_of< element_or_provision_fn const&, Opt, Provider >;

template< class Opt, class Provider >
using result_of_element_or_provision_t
  = basic_result_of_t< element_or_provision_fn const&, Opt, Provider >;

}  // namespace argot(::prov)

template< class Opt, class Provider >
struct make_concept_map
< ArgumentProvider< prov::element_or_provision_fn::impl< Opt, Provider > > >
{
  template
  < class Receiver
  , ARGOT_REQUIRES
    ( ArgumentReceiverOfKinds
      < Receiver
      , receiver_traits::concatenate_argument_list_kinds_t
        < receiver_traits::argument_list_kinds_t
          < receiver_traits::argument_types_t
            < opt_traits::result_of_get_t< Opt&& > >
          >
        , prov_traits::argument_list_kinds_of_destructive_t< Provider >
        >
      >
    )
    ()
  >
  static constexpr decltype( auto )
  provide( prov::element_or_provision_fn::impl< Opt, Provider >&& self
         , Receiver&& receiver
         )
  {
    return   opt_traits::has_value( *self.opt )
           ? receiver_traits::receive_branch
             ( ARGOT_MOVE( receiver )
             , receiver_traits::argument_list_kinds()
             , prov_traits::argument_list_kinds_of_destructive_t< Provider >{}
             , opt_traits::get( ARGOT_FORWARD( Opt )( *self.opt ) )
             )
           : receiver_traits::branch_to_provision
             ( ARGOT_MOVE( receiver )
             , receiver_traits::argument_list_kinds_t
               < receiver_traits::argument_types_t
                 < opt_traits::result_of_get_t< Opt&& > >
               >{}
             , receiver_traits::argument_list_kinds()
             , ARGOT_MOVE( self.provider )
             );
  }
};

template< class Opt, class Provider >
struct make_concept_map
< PersistentArgumentProvider
  < prov::element_or_provision_fn::impl< Opt, Provider > >
, ARGOT_REQUIRES( PersistentArgumentProvider< Provider > )<>
>
{
  template
  < class Receiver
  , ARGOT_REQUIRES
    ( ArgumentReceiverOfKinds
      < Receiver
      , receiver_traits::concatenate_argument_list_kinds_t
        < receiver_traits::argument_list_kinds_t
          < receiver_traits::argument_types_t
            < opt_traits::result_of_get_t< Opt const& > >
          >
        , prov_traits::argument_list_kinds_of_persistent_t< Provider >
        >
      >
    )
    ()
  >
  static constexpr decltype( auto )
  provide( prov::element_or_provision_fn::impl< Opt, Provider > const& self
         , Receiver&& receiver
         )
  {
    return   opt_traits::has_value( *self.opt )
           ? receiver_traits::receive_branch
             ( ARGOT_MOVE( receiver )
             , receiver_traits::argument_list_kinds()
             , prov_traits::argument_list_kinds_of_persistent_t< Provider >{}
             , opt_traits::get( *self.opt )
             )
           : receiver_traits::branch_to_provision
             ( ARGOT_MOVE( receiver )
             , receiver_traits::argument_list_kinds_t
               < receiver_traits::argument_types_t
                 < opt_traits::result_of_get_t< Opt const& > >
               >{}
             , receiver_traits::argument_list_kinds()
             , self.provider
             );
  }
};

}  // namespace argot

#endif  // ARGOT_PROV_ELEMENT_OR_PROVISION_HPP_