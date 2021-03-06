/*==============================================================================
  Copyright (c) 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
# line 46 "../../concepts/persistent_thenable.hpp"
template< class Fut, class FutPackager, class Exec >
struct PersistentThenable { using ArgotDetailConceptSpec = PersistentThenable ; static bool constexpr argot_gen_detail_is_auto_concept_v = false; template< class ArgotDetailSelf > using argot_gen_detail_is_modeled_impl = ::argot::concept_detail::is_modeled_impl< ArgotDetailSelf >; using requirements = typename ::argot::requires_detail::requires_impl< PersistentFuture< Fut > , Thenable< Fut, FutPackager, Exec > >::type; struct assertion : ::argot::deduced_concept_assertion< ArgotDetailConceptSpec > {}; };
template< class Fut, class FutPackager, class Exec >
struct make_concept_map
< PersistentThenable< Fut, FutPackager, Exec >
, typename ::argot::requires_< Thenable< Fut, FutPackager, Exec > >::_::template and_< PersistentForgetfulThenable< Fut, Exec > >::_::template and_< Not< IntrinsicPersistentThenable< Fut, FutPackager, Exec > > >::_::template ARGOT_RESULT
<>
>
{
template< class ExecP, class Fun >
static constexpr auto
then( Fut const& self, ExecP&& exec, Fun&& fun )
{
auto [ task, fut ]
= packager_traits::package
< FutPackager, fut_traits::value_type_t< Fut >&& > 
( static_cast< ::argot::detail_forward::direct_identity_t< ExecP >&& >( exec )
, static_cast< ::argot::detail_forward::direct_identity_t< Fun >&& >( fun )
);
access_raw_concept_map< PersistentForgetfulThenable< Fut, Exec > >
::forgetful_then
( self, static_cast< ::argot::detail_forward::direct_identity_t< ExecP >&& >( exec ), ARGOT_MOVE( task ) );
return ARGOT_MOVE( fut );
}
};
template< class Fut, class FutPackager, class Exec >
struct make_concept_map
< PersistentThenable< Fut, FutPackager, Exec >
, typename ::argot::requires_< IntrinsicPersistentThenable< Fut, FutPackager, Exec > >::_::template ARGOT_RESULT<>
>
{
template< class ExecP, class Fun >
static constexpr auto
then( Fut const& self, ExecP&& exec, Fun&& fun )
{
return access_raw_concept_map
< IntrinsicPersistentThenable< Fut, FutPackager, Exec > >
::then( self
, static_cast< ::argot::detail_forward::direct_identity_t< ExecP >&& >( exec )
, static_cast< ::argot::detail_forward::direct_identity_t< Fun >&& >( fun )
);
}
};
# undef ARGOT_DETAIL_PREPROCESSED_CONCEPT_HEADER_NAME
