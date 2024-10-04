// Koka generated module: std/core, koka version: 3.1.2, platform: 64-bit
#include "std_core.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_box_t kk_main_console( kk_function_t action, kk_context_t* ctx ) {
  return kk_function_call(kk_box_t,(kk_function_t,kk_unit_t,kk_context_t*),action,(action,kk_Unit,ctx),ctx);
}



kk_std_core__stream kk_std_core_stream_fs__copy(kk_std_core__stream _this, kk_std_core_types__optional head, kk_std_core_types__optional tail, kk_context_t* _ctx) { /* forall<a> (stream<a>, head : ? a, tail : ? (stream<a>)) -> stream<a> */ 
  kk_box_t _x_x69;
  if (kk_std_core_types__is_Optional(head, _ctx)) {
    kk_box_t _uniq_head_220 = head._cons._Optional.value;
    kk_box_dup(_uniq_head_220, _ctx);
    kk_std_core_types__optional_drop(head, _ctx);
    _x_x69 = _uniq_head_220; /*244*/
  }
  else {
    kk_std_core_types__optional_drop(head, _ctx);
    {
      struct kk_std_core_Next* _con_x70 = kk_std_core__as_Next(_this, _ctx);
      kk_box_t _x = _con_x70->head;
      kk_box_dup(_x, _ctx);
      _x_x69 = _x; /*244*/
    }
  }
  kk_std_core__stream _x_x71;
  if (kk_std_core_types__is_Optional(tail, _ctx)) {
    kk_box_t _box_x0 = tail._cons._Optional.value;
    kk_std_core__stream _uniq_tail_231 = kk_std_core__stream_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core__stream_dup(_uniq_tail_231, _ctx);
    kk_std_core_types__optional_drop(tail, _ctx);
    kk_std_core__stream_drop(_this, _ctx);
    _x_x71 = _uniq_tail_231; /*stream<244>*/
  }
  else {
    kk_std_core_types__optional_drop(tail, _ctx);
    {
      struct kk_std_core_Next* _con_x72 = kk_std_core__as_Next(_this, _ctx);
      kk_box_t _pat_0_1 = _con_x72->head;
      kk_std_core__stream _x_0 = _con_x72->tail;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_box_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core__stream_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x71 = _x_0; /*stream<244>*/
    }
  }
  return kk_std_core__new_Next(kk_reuse_null, 0, _x_x69, _x_x71, _ctx);
}
 
// Compose two functions `f` and `g`.


// lift anonymous function
struct kk_std_core_o_fun73__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t g;
};
static kk_box_t kk_std_core_o_fun73(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_o_fun73(kk_function_t f, kk_function_t g, kk_context_t* _ctx) {
  struct kk_std_core_o_fun73__t* _self = kk_function_alloc_as(struct kk_std_core_o_fun73__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_o_fun73, kk_context());
  _self->f = f;
  _self->g = g;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_o_fun73(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_o_fun73__t* _self = kk_function_as(struct kk_std_core_o_fun73__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (284) -> 276 277 */
  kk_function_t g = _self->g; /* (275) -> 276 284 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_function_dup(g, _ctx);}, {}, _ctx)
  kk_box_t x_0_10077 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), g, (g, x, _ctx), _ctx); /*284*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_0_10077, _ctx);
    return kk_std_core_hnd_yield_extend(f, _ctx);
  }
  {
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x_0_10077, _ctx), _ctx);
  }
}

kk_function_t kk_std_core_o(kk_function_t f, kk_function_t g, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (a) -> e b, g : (c) -> e a) -> ((x : c) -> e b) */ 
  return kk_std_core_new_o_fun73(f, g, _ctx);
}
extern kk_box_t kk_std_core_const_fun74(kk_function_t _fself, kk_box_t ___wildcard_x103__6, kk_context_t* _ctx) {
  struct kk_std_core_const_fun74__t* _self = kk_function_as(struct kk_std_core_const_fun74__t*, _fself, _ctx);
  kk_box_t kkloc_default = _self->kkloc_default; /* 330 */
  kk_drop_match(_self, {kk_box_dup(kkloc_default, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x103__6, _ctx);
  return kkloc_default;
}
 
// monadic lift

kk_unit_t kk_std_core__mlift_while_10071(kk_function_t action, kk_function_t predicate, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, wild_ : ()) -> <div|e> () */ 
  kk_std_core_while(predicate, action, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift_while_10072_fun77__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_function_t predicate_0;
};
static kk_box_t kk_std_core__mlift_while_10072_fun77(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift_while_10072_fun77(kk_function_t action_0, kk_function_t predicate_0, kk_context_t* _ctx) {
  struct kk_std_core__mlift_while_10072_fun77__t* _self = kk_function_alloc_as(struct kk_std_core__mlift_while_10072_fun77__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__mlift_while_10072_fun77, kk_context());
  _self->action_0 = action_0;
  _self->predicate_0 = predicate_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__mlift_while_10072_fun77(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  struct kk_std_core__mlift_while_10072_fun77__t* _self = kk_function_as(struct kk_std_core__mlift_while_10072_fun77__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* () -> <div|370> () */
  kk_function_t predicate_0 = _self->predicate_0; /* () -> <div|370> bool */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_function_dup(predicate_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_4 = kk_Unit;
  kk_unit_unbox(_b_x2);
  kk_unit_t _x_x78 = kk_Unit;
  kk_std_core__mlift_while_10071(action_0, predicate_0, wild___0_4, _ctx);
  return kk_unit_box(_x_x78);
}

kk_unit_t kk_std_core__mlift_while_10072(kk_function_t action_0, kk_function_t predicate_0, bool _y_x10027, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, bool) -> <div|e> () */ 
  if (_y_x10027) {
    kk_unit_t x_10079 = kk_Unit;
    kk_function_t _x_x75 = kk_function_dup(action_0, _ctx); /*() -> <div|370> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x_x75, (_x_x75, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x76 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift_while_10072_fun77(action_0, predicate_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x76); return kk_Unit;
    }
    {
      kk_std_core__mlift_while_10071(action_0, predicate_0, x_10079, _ctx); return kk_Unit;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// The `while` fun executes `action`  as long as `pred`  is `true`.


// lift anonymous function
struct kk_std_core_while_fun81__t {
  struct kk_function_s _base;
  kk_function_t action_1;
  kk_function_t predicate_1;
};
static kk_box_t kk_std_core_while_fun81(kk_function_t _fself, kk_box_t _b_x6, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun81(kk_function_t action_1, kk_function_t predicate_1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun81__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun81__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_while_fun81, kk_context());
  _self->action_1 = action_1;
  _self->predicate_1 = predicate_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_while_fun81(kk_function_t _fself, kk_box_t _b_x6, kk_context_t* _ctx) {
  struct kk_std_core_while_fun81__t* _self = kk_function_as(struct kk_std_core_while_fun81__t*, _fself, _ctx);
  kk_function_t action_1 = _self->action_1; /* () -> <div|370> () */
  kk_function_t predicate_1 = _self->predicate_1; /* () -> <div|370> bool */
  kk_drop_match(_self, {kk_function_dup(action_1, _ctx);kk_function_dup(predicate_1, _ctx);}, {}, _ctx)
  bool _y_x10027_0_11 = kk_bool_unbox(_b_x6); /*bool*/;
  kk_unit_t _x_x82 = kk_Unit;
  kk_std_core__mlift_while_10072(action_1, predicate_1, _y_x10027_0_11, _ctx);
  return kk_unit_box(_x_x82);
}


// lift anonymous function
struct kk_std_core_while_fun85__t {
  struct kk_function_s _base;
  kk_function_t action_1;
  kk_function_t predicate_1;
};
static kk_box_t kk_std_core_while_fun85(kk_function_t _fself, kk_box_t _b_x8, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun85(kk_function_t action_1, kk_function_t predicate_1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun85__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun85__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_while_fun85, kk_context());
  _self->action_1 = action_1;
  _self->predicate_1 = predicate_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_while_fun85(kk_function_t _fself, kk_box_t _b_x8, kk_context_t* _ctx) {
  struct kk_std_core_while_fun85__t* _self = kk_function_as(struct kk_std_core_while_fun85__t*, _fself, _ctx);
  kk_function_t action_1 = _self->action_1; /* () -> <div|370> () */
  kk_function_t predicate_1 = _self->predicate_1; /* () -> <div|370> bool */
  kk_drop_match(_self, {kk_function_dup(action_1, _ctx);kk_function_dup(predicate_1, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_12 = kk_Unit;
  kk_unit_unbox(_b_x8);
  kk_unit_t _x_x86 = kk_Unit;
  kk_std_core__mlift_while_10071(action_1, predicate_1, wild___1_12, _ctx);
  return kk_unit_box(_x_x86);
}

kk_unit_t kk_std_core_while(kk_function_t predicate_1, kk_function_t action_1, kk_context_t* _ctx) { /* forall<e> (predicate : () -> <div|e> bool, action : () -> <div|e> ()) -> <div|e> () */ 
  kk__tailcall: ;
  bool x_0_10081;
  kk_function_t _x_x79 = kk_function_dup(predicate_1, _ctx); /*() -> <div|370> bool*/
  x_0_10081 = kk_function_call(bool, (kk_function_t, kk_context_t*), _x_x79, (_x_x79, _ctx), _ctx); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x80 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun81(action_1, predicate_1, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x80); return kk_Unit;
  }
  if (x_0_10081) {
    kk_unit_t x_1_10084 = kk_Unit;
    kk_function_t _x_x83 = kk_function_dup(action_1, _ctx); /*() -> <div|370> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x_x83, (_x_x83, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x84 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun85(action_1, predicate_1, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x84); return kk_Unit;
    }
    { // tailcall
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(predicate_1, _ctx);
    kk_function_drop(action_1, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_box_t kk_std_core_range_fs__mlift_fold_10073(kk_integer_t end, kk_function_t f, kk_integer_t start, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (end : int, f : (int, a) -> e a, start : int, x : a) -> e a */ 
  kk_integer_t _x_x88 = kk_integer_add_small_const(start, 1, _ctx); /*int*/
  return kk_std_core_range_fs_fold(_x_x88, end, x, f, _ctx);
}
 
// Fold over the integers between [`start`,`end`] (including `end`).


// lift anonymous function
struct kk_std_core_range_fs_fold_fun91__t {
  struct kk_function_s _base;
  kk_integer_t end_0;
  kk_function_t f_0;
  kk_integer_t start_0;
};
static kk_box_t kk_std_core_range_fs_fold_fun91(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs_new_fold_fun91(kk_integer_t end_0, kk_function_t f_0, kk_integer_t start_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_fun91__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs_fold_fun91__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs_fold_fun91, kk_context());
  _self->end_0 = end_0;
  _self->f_0 = f_0;
  _self->start_0 = start_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs_fold_fun91(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_fun91__t* _self = kk_function_as(struct kk_std_core_range_fs_fold_fun91__t*, _fself, _ctx);
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_function_t f_0 = _self->f_0; /* (int, 588) -> 589 588 */
  kk_integer_t start_0 = _self->start_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(end_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(start_0, _ctx);}, {}, _ctx)
  return kk_std_core_range_fs__mlift_fold_10073(end_0, f_0, start_0, x_1, _ctx);
}

kk_box_t kk_std_core_range_fs_fold(kk_integer_t start_0, kk_integer_t end_0, kk_box_t init, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,e> (start : int, end : int, init : a, f : (int, a) -> e a) -> e a */ 
  kk__tailcall: ;
  bool _match_x59 = kk_integer_gt_borrow(start_0,end_0,kk_context()); /*bool*/;
  if (_match_x59) {
    kk_integer_drop(start_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    return init;
  }
  {
    kk_box_t x_0_10087;
    kk_function_t _x_x90 = kk_function_dup(f_0, _ctx); /*(int, 588) -> 589 588*/
    kk_integer_t _x_x89 = kk_integer_dup(start_0, _ctx); /*int*/
    x_0_10087 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x90, (_x_x90, _x_x89, init, _ctx), _ctx); /*588*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10087, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_range_fs_new_fold_fun91(end_0, f_0, start_0, _ctx), _ctx);
    }
    { // tailcall
      kk_integer_t _x_x92 = kk_integer_add_small_const(start_0, 1, _ctx); /*int*/
      start_0 = _x_x92;
      init = x_0_10087;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_box_t kk_std_core_range_fs__mlift_fold_while_10074(kk_integer_t end, kk_function_t f, kk_box_t init, kk_integer_t start, kk_std_core_types__maybe _y_x10035, kk_context_t* _ctx) { /* forall<a,e> (end : int, f : (int, a) -> e maybe<a>, init : a, start : int, maybe<a>) -> e a */ 
  if (kk_std_core_types__is_Just(_y_x10035, _ctx)) {
    kk_box_t x = _y_x10035._cons.Just.value;
    kk_box_drop(init, _ctx);
    kk_integer_t _x_x94 = kk_integer_add_small_const(start, 1, _ctx); /*int*/
    return kk_std_core_range_fs_fold_while(_x_x94, end, x, f, _ctx);
  }
  {
    kk_integer_drop(start, _ctx);
    kk_function_drop(f, _ctx);
    kk_integer_drop(end, _ctx);
    return init;
  }
}
 
// Fold over the integers between [`start`,`end`] (including `end`) or until `f` returns `Nothing`


// lift anonymous function
struct kk_std_core_range_fs_fold_while_fun98__t {
  struct kk_function_s _base;
  kk_integer_t end_0;
  kk_function_t f_0;
  kk_box_t init_0;
  kk_integer_t start_0;
};
static kk_box_t kk_std_core_range_fs_fold_while_fun98(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs_new_fold_while_fun98(kk_integer_t end_0, kk_function_t f_0, kk_box_t init_0, kk_integer_t start_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_while_fun98__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs_fold_while_fun98__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs_fold_while_fun98, kk_context());
  _self->end_0 = end_0;
  _self->f_0 = f_0;
  _self->init_0 = init_0;
  _self->start_0 = start_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs_fold_while_fun98(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_while_fun98__t* _self = kk_function_as(struct kk_std_core_range_fs_fold_while_fun98__t*, _fself, _ctx);
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_function_t f_0 = _self->f_0; /* (int, 685) -> 686 maybe<685> */
  kk_box_t init_0 = _self->init_0; /* 685 */
  kk_integer_t start_0 = _self->start_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(end_0, _ctx);kk_function_dup(f_0, _ctx);kk_box_dup(init_0, _ctx);kk_integer_dup(start_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x99 = kk_std_core_types__maybe_unbox(_b_x14, KK_OWNED, _ctx); /*maybe<685>*/
  return kk_std_core_range_fs__mlift_fold_while_10074(end_0, f_0, init_0, start_0, _x_x99, _ctx);
}

kk_box_t kk_std_core_range_fs_fold_while(kk_integer_t start_0, kk_integer_t end_0, kk_box_t init_0, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,e> (start : int, end : int, init : a, f : (int, a) -> e maybe<a>) -> e a */ 
  kk__tailcall: ;
  bool _match_x57 = kk_integer_gt_borrow(start_0,end_0,kk_context()); /*bool*/;
  if (_match_x57) {
    kk_integer_drop(start_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    return init_0;
  }
  {
    kk_std_core_types__maybe x_0_10090;
    kk_function_t _x_x97 = kk_function_dup(f_0, _ctx); /*(int, 685) -> 686 maybe<685>*/
    kk_integer_t _x_x95 = kk_integer_dup(start_0, _ctx); /*int*/
    kk_box_t _x_x96 = kk_box_dup(init_0, _ctx); /*685*/
    x_0_10090 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x97, (_x_x97, _x_x95, _x_x96, _ctx), _ctx); /*maybe<685>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10090, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_range_fs_new_fold_while_fun98(end_0, f_0, init_0, start_0, _ctx), _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10090, _ctx)) {
      kk_box_t x_1 = x_0_10090._cons.Just.value;
      kk_box_drop(init_0, _ctx);
      { // tailcall
        kk_integer_t _x_x100 = kk_integer_add_small_const(start_0, 1, _ctx); /*int*/
        start_0 = _x_x100;
        init_0 = x_1;
        goto kk__tailcall;
      }
    }
    {
      kk_integer_drop(start_0, _ctx);
      kk_function_drop(f_0, _ctx);
      kk_integer_drop(end_0, _ctx);
      return init_0;
    }
  }
}
 
// monadic lift

kk_unit_t kk_std_core_range_fs__mlift_lift_for_1256_10075(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int, wild_ : ()) -> e () */ 
  kk_integer_t i_0_10009 = kk_integer_add_small_const(i, 1, _ctx); /*int*/;
  kk_std_core_range_fs__lift_for_1256(action, end, i_0_10009, _ctx); return kk_Unit;
}
 
// lifted local: range/for, rep


// lift anonymous function
struct kk_std_core_range_fs__lift_for_1256_fun108__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_integer_t end_0;
  kk_integer_t i_0;
};
static kk_box_t kk_std_core_range_fs__lift_for_1256_fun108(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs__new_lift_for_1256_fun108(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_1256_fun108__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs__lift_for_1256_fun108__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs__lift_for_1256_fun108, kk_context());
  _self->action_0 = action_0;
  _self->end_0 = end_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs__lift_for_1256_fun108(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_1256_fun108__t* _self = kk_function_as(struct kk_std_core_range_fs__lift_for_1256_fun108__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (int) -> 862 () */
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_integer_t i_0 = _self->i_0; /* int */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_integer_dup(end_0, _ctx);kk_integer_dup(i_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_20 = kk_Unit;
  kk_unit_unbox(_b_x18);
  kk_unit_t _x_x109 = kk_Unit;
  kk_std_core_range_fs__mlift_lift_for_1256_10075(action_0, end_0, i_0, wild___0_20, _ctx);
  return kk_unit_box(_x_x109);
}

kk_unit_t kk_std_core_range_fs__lift_for_1256(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int) -> e () */ 
  kk__tailcall: ;
  bool _match_x55 = kk_integer_lte_borrow(i_0,end_0,kk_context()); /*bool*/;
  if (_match_x55) {
    kk_unit_t x_10093 = kk_Unit;
    kk_function_t _x_x106 = kk_function_dup(action_0, _ctx); /*(int) -> 862 ()*/
    kk_integer_t _x_x105 = kk_integer_dup(i_0, _ctx); /*int*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x106, (_x_x106, _x_x105, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x107 = kk_std_core_hnd_yield_extend(kk_std_core_range_fs__new_lift_for_1256_fun108(action_0, end_0, i_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x107); return kk_Unit;
    }
    {
      kk_integer_t i_0_10009_0 = kk_integer_add_small_const(i_0, 1, _ctx); /*int*/;
      { // tailcall
        i_0 = i_0_10009_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
extern kk_unit_t kk_std_core_repeat_fun113(kk_function_t _fself, kk_integer_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_repeat_fun113__t* _self = kk_function_as(struct kk_std_core_repeat_fun113__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> 900 () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_integer_drop(i_0, _ctx);
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_range_fs__mlift_lift_for_while_1257_10076(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_std_core_types__maybe _y_x10047, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10047, _ctx)) {
    kk_integer_t i_0_10018 = kk_integer_add_small_const(i, 1, _ctx); /*int*/;
    return kk_std_core_range_fs__lift_for_while_1257(action, end, i_0_10018, _ctx);
  }
  {
    kk_box_t x = _y_x10047._cons.Just.value;
    kk_integer_drop(i, _ctx);
    kk_integer_drop(end, _ctx);
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Just(x, _ctx);
  }
}
 
// lifted local: range/for-while, rep


// lift anonymous function
struct kk_std_core_range_fs__lift_for_while_1257_fun117__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_integer_t end_0;
  kk_integer_t i_0;
};
static kk_box_t kk_std_core_range_fs__lift_for_while_1257_fun117(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs__new_lift_for_while_1257_fun117(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_while_1257_fun117__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs__lift_for_while_1257_fun117__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs__lift_for_while_1257_fun117, kk_context());
  _self->action_0 = action_0;
  _self->end_0 = end_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs__lift_for_while_1257_fun117(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_while_1257_fun117__t* _self = kk_function_as(struct kk_std_core_range_fs__lift_for_while_1257_fun117__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (int) -> 962 maybe<961> */
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_integer_t i_0 = _self->i_0; /* int */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_integer_dup(end_0, _ctx);kk_integer_dup(i_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10047_0_24 = kk_std_core_types__maybe_unbox(_b_x22, KK_OWNED, _ctx); /*maybe<961>*/;
  kk_std_core_types__maybe _x_x118 = kk_std_core_range_fs__mlift_lift_for_while_1257_10076(action_0, end_0, i_0, _y_x10047_0_24, _ctx); /*maybe<961>*/
  return kk_std_core_types__maybe_box(_x_x118, _ctx);
}

kk_std_core_types__maybe kk_std_core_range_fs__lift_for_while_1257(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_x53 = kk_integer_lte_borrow(i_0,end_0,kk_context()); /*bool*/;
  if (_match_x53) {
    kk_std_core_types__maybe x_0_10096;
    kk_function_t _x_x115 = kk_function_dup(action_0, _ctx); /*(int) -> 962 maybe<961>*/
    kk_integer_t _x_x114 = kk_integer_dup(i_0, _ctx); /*int*/
    x_0_10096 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_integer_t, kk_context_t*), _x_x115, (_x_x115, _x_x114, _ctx), _ctx); /*maybe<961>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10096, _ctx);
      kk_box_t _x_x116 = kk_std_core_hnd_yield_extend(kk_std_core_range_fs__new_lift_for_while_1257_fun117(action_0, end_0, i_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x116, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10096, _ctx)) {
      kk_integer_t i_0_10018_0 = kk_integer_add_small_const(i_0, 1, _ctx); /*int*/;
      { // tailcall
        i_0 = i_0_10018_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t x_1 = x_0_10096._cons.Just.value;
      kk_integer_drop(i_0, _ctx);
      kk_integer_drop(end_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return kk_std_core_types__new_Just(x_1, _ctx);
    }
  }
  {
    kk_integer_drop(i_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Used by the compiler to wrap main console applications

kk_box_t kk_std_core_main_console(kk_function_t main, kk_context_t* _ctx) { /* forall<a,e> (main : () -> e a) -> e a */ 
  return kk_main_console(main,kk_context());
}
 
// Return the host environment: `dotnet`, `browser`, `webworker`, `node`, or `libc`.

kk_string_t kk_std_core_host(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_get_host(kk_context());
}
 
// The default exception handler


// lift anonymous function
struct kk_std_core__default_exn_fun120__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun120(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun120(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun120, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_core__default_exn_fun121__t {
  struct kk_function_s _base;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core__default_exn_fun121(kk_function_t _fself, kk_function_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun121(kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun121__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun121__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun121, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core__default_exn_fun122__t {
  struct kk_function_s _base;
  kk_function_t _b_x27;
};
static kk_unit_t kk_std_core__default_exn_fun122(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x28, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun122(kk_function_t _b_x27, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun122__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun122__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun122, kk_context());
  _self->_b_x27 = _b_x27;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_std_core__default_exn_fun122(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x28, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun122__t* _self = kk_function_as(struct kk_std_core__default_exn_fun122__t*, _fself, _ctx);
  kk_function_t _b_x27 = _self->_b_x27; /* (hnd/resume-result<3225,3228>) -> 3227 3228 */
  kk_drop_match(_self, {kk_function_dup(_b_x27, _ctx);}, {}, _ctx)
  kk_box_t _x_x123 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x27, (_b_x27, _b_x28, _ctx), _ctx); /*3228*/
  kk_unit_unbox(_x_x123); return kk_Unit;
}
static kk_box_t kk_std_core__default_exn_fun121(kk_function_t _fself, kk_function_t _b_x27, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun121__t* _self = kk_function_as(struct kk_std_core__default_exn_fun121__t*, _fself, _ctx);
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_t ___wildcard_x638__45_43 = kk_std_core__new_default_exn_fun122(_b_x27, _ctx); /*(hnd/resume-result<1169,()>) -> <console/console|1180> ()*/;
  kk_function_drop(___wildcard_x638__45_43, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x124;
  kk_define_string_literal(, _s_x125, 20, "uncaught exception: ", _ctx)
  _x_x124 = kk_string_dup(_s_x125, _ctx); /*string*/
  kk_std_core_console_prints(_x_x124, _ctx);
  kk_unit_t _x_x126 = kk_Unit;
  kk_string_t _x_x127 = kk_std_core_exn_show(x, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x127, _ctx);
  return kk_unit_box(_x_x126);
}
static kk_box_t kk_std_core__default_exn_fun120(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_datatype_ptr_dropn(___wildcard_x638__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core__new_default_exn_fun121(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core__default_exn_fun130__t {
  struct kk_function_s _base;
  kk_function_t _b_x29_40;
};
static kk_box_t kk_std_core__default_exn_fun130(kk_function_t _fself, int32_t _b_x30, kk_std_core_hnd__ev _b_x31, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun130(kk_function_t _b_x29_40, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun130__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun130__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun130, kk_context());
  _self->_b_x29_40 = _b_x29_40;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__default_exn_fun130(kk_function_t _fself, int32_t _b_x30, kk_std_core_hnd__ev _b_x31, kk_box_t _b_x32, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun130__t* _self = kk_function_as(struct kk_std_core__default_exn_fun130__t*, _fself, _ctx);
  kk_function_t _b_x29_40 = _self->_b_x29_40; /* (m : hnd/marker<<console/console|1180>,()>, hnd/ev<exn>, x : exception) -> <console/console|1180> 1169 */
  kk_drop_match(_self, {kk_function_dup(_b_x29_40, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x131 = kk_std_core_exn__exception_unbox(_b_x32, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x29_40, (_b_x29_40, _b_x30, _b_x31, _x_x131, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core__default_exn_fun132__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun132(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun132(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun132, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core__default_exn_fun132(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_unit_t _x_44 = kk_Unit;
  kk_unit_unbox(_b_x36);
  return kk_unit_box(_x_44);
}


// lift anonymous function
struct kk_std_core__default_exn_fun133__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core__default_exn_fun133(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun133(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun133__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun133__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun133, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__default_exn_fun133(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun133__t* _self = kk_function_as(struct kk_std_core__default_exn_fun133__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> <exn,console/console|1180> () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_unit_t _x_x134 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx);
  return kk_unit_box(_x_x134);
}

kk_unit_t kk_std_core__default_exn(kk_function_t action, kk_context_t* _ctx) { /* forall<e> (action : () -> <exn,console/console|e> ()) -> <console/console|e> () */ 
  kk_box_t _x_x119;
  kk_function_t _b_x29_40 = kk_std_core__new_default_exn_fun120(_ctx); /*(m : hnd/marker<<console/console|1180>,()>, hnd/ev<exn>, x : exception) -> <console/console|1180> 1169*/;
  kk_std_core_exn__exn _x_x128;
  kk_std_core_hnd__clause1 _x_x129 = kk_std_core_hnd__new_Clause1(kk_std_core__new_default_exn_fun130(_b_x29_40, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x128 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x129, _ctx); /*exn<14,15>*/
  _x_x119 = kk_std_core_exn__handle_exn(_x_x128, kk_std_core__new_default_exn_fun132(_ctx), kk_std_core__new_default_exn_fun133(action, _ctx), _ctx); /*2547*/
  kk_unit_unbox(_x_x119); return kk_Unit;
}

kk_ref_t kk_std_core_unique_count;
 
// Returns a unique integer (modulo 32-bits).

kk_integer_t kk_std_core_unique(kk_context_t* _ctx) { /* () -> ndet int */ 
  kk_integer_t u;
  kk_box_t _x_x135;
  kk_ref_t _x_x136 = kk_ref_dup(kk_std_core_unique_count, _ctx); /*ref<global,int>*/
  _x_x135 = kk_ref_get(_x_x136,kk_context()); /*2459*/
  u = kk_integer_unbox(_x_x135, _ctx); /*int*/
  kk_integer_t _b_x50_52;
  kk_integer_t _x_x137 = kk_integer_dup(u, _ctx); /*int*/
  _b_x50_52 = kk_integer_add_small_const(_x_x137, 1, _ctx); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_ref_set_borrow(kk_std_core_unique_count,(kk_integer_box(_b_x50_52, _ctx)),kk_context());
  return u;
}

// initialization
void kk_std_core__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_core_unique_count = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*ref<global,int>*/
  }
}

// termination
void kk_std_core__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_ref_drop(kk_std_core_unique_count, _ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
