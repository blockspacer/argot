/*==============================================================================
  Copyright (c) 2018 Matt Calabrese

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef ARGOT_CONCEPTS_HPP_
#define ARGOT_CONCEPTS_HPP_

#include <argot/concepts/allocator.hpp>
#include <argot/concepts/argot_invocable.hpp>
#include <argot/concepts/argot_invocable_before_reduction.hpp>
#include <argot/concepts/argot_invocable_with_persistent_reduction.hpp>
#include <argot/concepts/argot_invocable_with_reduction.hpp>
#include <argot/concepts/argument_list_kinds.hpp>
#include <argot/concepts/argument_provider.hpp>
#include <argot/concepts/argument_provider_generator_with.hpp>
#include <argot/concepts/argument_provider_generator_with_each.hpp>
#include <argot/concepts/argument_provider_generator_with_kinds.hpp>
#include <argot/concepts/argument_provider_to.hpp>
#include <argot/concepts/argument_receiver.hpp>
#include <argot/concepts/argument_receiver_of.hpp>
#include <argot/concepts/argument_receiver_of_kinds.hpp>
#include <argot/concepts/argument_receiver_of_lifted_call.hpp>
#include <argot/concepts/argument_receiver_of_lifted_persistent_call.hpp>
#include <argot/concepts/argument_type.hpp>
#include <argot/concepts/argument_types.hpp>
#include <argot/concepts/assignable.hpp>
#include <argot/concepts/basic_callable_with.hpp>
#include <argot/concepts/bool_or_constant.hpp>
#include <argot/concepts/can_default_to_reference_to.hpp>
#include <argot/concepts/can_default_to_value_of.hpp>
#include <argot/concepts/case_labels.hpp>
#include <argot/concepts/class.hpp>
#include <argot/concepts/class_type.hpp>
#include <argot/concepts/comparable.hpp>
#include <argot/concepts/composable.hpp>
#include <argot/concepts/composable_with_persistent_provision.hpp>
#include <argot/concepts/composable_with_provision.hpp>
#include <argot/concepts/concurrent_argument_provider.hpp>
#include <argot/concepts/concurrent_argument_provider_to.hpp>
#include <argot/concepts/concurrent_can_default_to_value_of.hpp>
#include <argot/concepts/concurrent_expandable.hpp>
#include <argot/concepts/constructible.hpp>
#include <argot/concepts/constructible_with_each.hpp>
#include <argot/concepts/constructible_with_kinds.hpp>
#include <argot/concepts/contextually_convertible_to_bool.hpp>
#include <argot/concepts/convertible.hpp>
#include <argot/concepts/convertible_to_type_or_constant.hpp>
#include <argot/concepts/copy_assignable.hpp>
#include <argot/concepts/copy_constructible.hpp>
#include <argot/concepts/core_union.hpp>
#include <argot/concepts/decay_sinkable.hpp>
#include <argot/concepts/default.hpp>
#include <argot/concepts/default_constructible.hpp>
#include <argot/concepts/default_for_type.hpp>
#include <argot/concepts/destructible.hpp>
#include <argot/concepts/equality_comparable.hpp>
#include <argot/concepts/equatable.hpp>
#include <argot/concepts/exception.hpp>
#include <argot/concepts/exceptional_argument_provider.hpp>
#include <argot/concepts/exceptional_persistent_argument_provider.hpp>
#include <argot/concepts/exceptional_persistent_switch_body_case.hpp>
#include <argot/concepts/exceptional_persistent_switch_body_default_for_type.hpp>
#include <argot/concepts/exceptional_switch_body_case.hpp>
#include <argot/concepts/exceptional_switch_body_default_for_type.hpp>
#include <argot/concepts/execution_context.hpp>
#include <argot/concepts/executor.hpp>
#include <argot/concepts/expandable.hpp>
#include <argot/concepts/expandable_argument_provider.hpp>
#include <argot/concepts/explicitly_convertible.hpp>
#include <argot/concepts/false.hpp>
#include <argot/concepts/forgetful_then_providable.hpp>
#include <argot/concepts/forgetful_thenable.hpp>
#include <argot/concepts/future.hpp>
#include <argot/concepts/future_packager.hpp>
#include <argot/concepts/greater.hpp>
#include <argot/concepts/greater_equal.hpp>
#include <argot/concepts/greater_equal_comparable.hpp>
#include <argot/concepts/greater_than_comparable.hpp>
#include <argot/concepts/hashable.hpp>
#include <argot/concepts/higher_order_argument_provider.hpp>
#include <argot/concepts/higher_order_concurrent_argument_provider.hpp>
#include <argot/concepts/higher_order_expandable.hpp>
#include <argot/concepts/higher_order_future.hpp>
#include <argot/concepts/higher_order_persistent_argument_provider.hpp>
#include <argot/concepts/homogeneous_return_value_reducer.hpp>
#include <argot/concepts/immediate_executor.hpp>
#include <argot/concepts/inequality_comparable.hpp>
#include <argot/concepts/instantiation_of.hpp>
#include <argot/concepts/intrinsic_persistent_thenable.hpp>
#include <argot/concepts/intrinsic_thenable.hpp>
#include <argot/concepts/invocable_from_provision_without_reduction.hpp>
#include <argot/concepts/invocable_object_with.hpp>
#include <argot/concepts/invocable_object_with_each.hpp>
#include <argot/concepts/invocable_object_with_kinds.hpp>
#include <argot/concepts/invocable_with.hpp>
#include <argot/concepts/invocable_with_each.hpp>
#include <argot/concepts/invocable_with_kinds.hpp>
#include <argot/concepts/invoker.hpp>
#include <argot/concepts/less.hpp>
#include <argot/concepts/less_equal.hpp>
#include <argot/concepts/less_equal_comparable.hpp>
#include <argot/concepts/less_than_comparable.hpp>
#include <argot/concepts/liftable_call.hpp>
#include <argot/concepts/liftable_persistent_call.hpp>
#include <argot/concepts/lvalue_reference.hpp>
#include <argot/concepts/move_assignable.hpp>
#include <argot/concepts/move_constructible.hpp>
#include <argot/concepts/net_executor.hpp>
#include <argot/concepts/nothrow_constructible.hpp>
#include <argot/concepts/nothrow_copy_assignable.hpp>
#include <argot/concepts/nothrow_copy_constructible.hpp>
#include <argot/concepts/nothrow_default_constructible.hpp>
#include <argot/concepts/nothrow_destructible.hpp>
#include <argot/concepts/nothrow_equality_comparable.hpp>
#include <argot/concepts/nothrow_greater_equal_comparable.hpp>
#include <argot/concepts/nothrow_greater_than_comparable.hpp>
#include <argot/concepts/nothrow_hashable.hpp>
#include <argot/concepts/nothrow_inequality_comparable.hpp>
#include <argot/concepts/nothrow_less_equal_comparable.hpp>
#include <argot/concepts/nothrow_less_than_comparable.hpp>
#include <argot/concepts/nothrow_move_assignable.hpp>
#include <argot/concepts/nothrow_move_constructible.hpp>
#include <argot/concepts/nothrow_swappable.hpp>
#include <argot/concepts/object.hpp>
#include <argot/concepts/optional_like.hpp>
#include <argot/concepts/parameter_type.hpp>
#include <argot/concepts/persistent_argument_provider.hpp>
#include <argot/concepts/persistent_argument_provider_generator_with.hpp>
#include <argot/concepts/persistent_argument_provider_generator_with_each.hpp>
#include <argot/concepts/persistent_argument_provider_generator_with_kinds.hpp>
#include <argot/concepts/persistent_argument_provider_to.hpp>
#include <argot/concepts/persistent_composable.hpp>
#include <argot/concepts/persistent_composable_with_persistent_provision.hpp>
#include <argot/concepts/persistent_concurrent_argument_provider.hpp>
#include <argot/concepts/persistent_concurrent_argument_provider_to.hpp>
#include <argot/concepts/persistent_default_for_type.hpp>
#include <argot/concepts/persistent_exceptional_default.hpp>
#include <argot/concepts/persistent_expandable_argument_provider.hpp>
#include <argot/concepts/persistent_forgetful_then_providable.hpp>
#include <argot/concepts/persistent_forgetful_thenable.hpp>
#include <argot/concepts/persistent_future.hpp>
#include <argot/concepts/persistent_invocable_object_with.hpp>
#include <argot/concepts/persistent_invocable_object_with_each.hpp>
#include <argot/concepts/persistent_invocable_object_with_kinds.hpp>
#include <argot/concepts/persistent_return_value_reducer.hpp>
#include <argot/concepts/persistent_return_value_reducer_of.hpp>
#include <argot/concepts/persistent_switch_body_case.hpp>
#include <argot/concepts/persistent_switch_body_default_for_type.hpp>
#include <argot/concepts/persistent_switch_body_for_type.hpp>
#include <argot/concepts/persistent_then_providable.hpp>
#include <argot/concepts/persistent_thenable.hpp>
#include <argot/concepts/potentially_invocable.hpp>
#include <argot/concepts/potentially_invocable_object.hpp>
#include <argot/concepts/reference.hpp>
#include <argot/concepts/return_type.hpp>
#include <argot/concepts/return_value_reducer.hpp>
#include <argot/concepts/return_value_reducer_of.hpp>
#include <argot/concepts/rvalue.hpp>
#include <argot/concepts/rvalue_reference.hpp>
#include <argot/concepts/same_type.hpp>
#include <argot/concepts/same_value.hpp>
#include <argot/concepts/sinkable.hpp>
#include <argot/concepts/std_integral_constant.hpp>
#include <argot/concepts/stlab_executor.hpp>
#include <argot/concepts/swappable.hpp>
#include <argot/concepts/switch_body.hpp>
#include <argot/concepts/switch_body_case.hpp>
#include <argot/concepts/switch_body_default.hpp>
#include <argot/concepts/switch_body_default_for_type.hpp>
#include <argot/concepts/switch_body_for_type.hpp>
#include <argot/concepts/switch_condition.hpp>
#include <argot/concepts/switch_condition_or_constant.hpp>
#include <argot/concepts/switchable.hpp>
#include <argot/concepts/then_providable.hpp>
#include <argot/concepts/thenable.hpp>
#include <argot/concepts/transformation_with.hpp>
#include <argot/concepts/trivially_constructible.hpp>
#include <argot/concepts/trivially_copy_assignable.hpp>
#include <argot/concepts/trivially_copy_constructible.hpp>
#include <argot/concepts/trivially_default_constructible.hpp>
#include <argot/concepts/trivially_destructible.hpp>
#include <argot/concepts/trivially_move_assignable.hpp>
#include <argot/concepts/trivially_move_constructible.hpp>
#include <argot/concepts/true.hpp>
#include <argot/concepts/tuple_index.hpp>
#include <argot/concepts/tuple_like.hpp>
#include <argot/concepts/type_or_constant.hpp>
#include <argot/concepts/unhandled_switchable_value.hpp>
#include <argot/concepts/union.hpp>
#include <argot/concepts/union_index.hpp>
#include <argot/concepts/union_like.hpp>
#include <argot/concepts/unqualified_object.hpp>
#include <argot/concepts/valid.hpp>
#include <argot/concepts/variant_index.hpp>
#include <argot/concepts/variant_like.hpp>
#include <argot/concepts/volatile_object.hpp>

#endif  // ARGOT_CONCEPTS_HPP_
