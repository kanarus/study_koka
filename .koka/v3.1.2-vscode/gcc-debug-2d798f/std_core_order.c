// Koka generated module: std/core/order, koka version: 3.1.2, platform: 64-bit
#include "std_core_order.h"

bool kk_std_core_order__lp__eq__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x17;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x17 = kk_integer_from_small(-1); /*int*/
    goto _match_x19;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x17 = kk_integer_from_small(0); /*int*/
    goto _match_x19;
  }
  {
    _brw_x17 = kk_integer_from_small(1); /*int*/
  }
  _match_x19: ;
  kk_integer_t _brw_x16;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x16 = kk_integer_from_small(-1); /*int*/
    goto _match_x20;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x16 = kk_integer_from_small(0); /*int*/
    goto _match_x20;
  }
  {
    _brw_x16 = kk_integer_from_small(1); /*int*/
  }
  _match_x20: ;
  bool _brw_x18 = kk_integer_eq_borrow(_brw_x17,_brw_x16,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x17, _ctx);
  kk_integer_drop(_brw_x16, _ctx);
  return _brw_x18;
}

bool kk_std_core_order__lp__excl__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x14;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x14 = kk_integer_from_small(-1); /*int*/
    goto _match_x21;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x14 = kk_integer_from_small(0); /*int*/
    goto _match_x21;
  }
  {
    _brw_x14 = kk_integer_from_small(1); /*int*/
  }
  _match_x21: ;
  kk_integer_t _brw_x13;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x13 = kk_integer_from_small(-1); /*int*/
    goto _match_x22;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x13 = kk_integer_from_small(0); /*int*/
    goto _match_x22;
  }
  {
    _brw_x13 = kk_integer_from_small(1); /*int*/
  }
  _match_x22: ;
  bool _brw_x15 = kk_integer_neq_borrow(_brw_x14,_brw_x13,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x14, _ctx);
  kk_integer_drop(_brw_x13, _ctx);
  return _brw_x15;
}

bool kk_std_core_order__lp__gt__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x11;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x11 = kk_integer_from_small(-1); /*int*/
    goto _match_x23;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x11 = kk_integer_from_small(0); /*int*/
    goto _match_x23;
  }
  {
    _brw_x11 = kk_integer_from_small(1); /*int*/
  }
  _match_x23: ;
  kk_integer_t _brw_x10;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x10 = kk_integer_from_small(-1); /*int*/
    goto _match_x24;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x10 = kk_integer_from_small(0); /*int*/
    goto _match_x24;
  }
  {
    _brw_x10 = kk_integer_from_small(1); /*int*/
  }
  _match_x24: ;
  bool _brw_x12 = kk_integer_gte_borrow(_brw_x11,_brw_x10,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x11, _ctx);
  kk_integer_drop(_brw_x10, _ctx);
  return _brw_x12;
}

bool kk_std_core_order__lp__lt__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x8;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x8 = kk_integer_from_small(-1); /*int*/
    goto _match_x25;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x8 = kk_integer_from_small(0); /*int*/
    goto _match_x25;
  }
  {
    _brw_x8 = kk_integer_from_small(1); /*int*/
  }
  _match_x25: ;
  kk_integer_t _brw_x7;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x7 = kk_integer_from_small(-1); /*int*/
    goto _match_x26;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x7 = kk_integer_from_small(0); /*int*/
    goto _match_x26;
  }
  {
    _brw_x7 = kk_integer_from_small(1); /*int*/
  }
  _match_x26: ;
  bool _brw_x9 = kk_integer_lte_borrow(_brw_x8,_brw_x7,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x8, _ctx);
  kk_integer_drop(_brw_x7, _ctx);
  return _brw_x9;
}

bool kk_std_core_order__lp__gt__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x5;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x5 = kk_integer_from_small(-1); /*int*/
    goto _match_x27;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x5 = kk_integer_from_small(0); /*int*/
    goto _match_x27;
  }
  {
    _brw_x5 = kk_integer_from_small(1); /*int*/
  }
  _match_x27: ;
  kk_integer_t _brw_x4;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x4 = kk_integer_from_small(-1); /*int*/
    goto _match_x28;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x4 = kk_integer_from_small(0); /*int*/
    goto _match_x28;
  }
  {
    _brw_x4 = kk_integer_from_small(1); /*int*/
  }
  _match_x28: ;
  bool _brw_x6 = kk_integer_gt_borrow(_brw_x5,_brw_x4,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x5, _ctx);
  kk_integer_drop(_brw_x4, _ctx);
  return _brw_x6;
}

bool kk_std_core_order__lp__lt__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x2;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x2 = kk_integer_from_small(-1); /*int*/
    goto _match_x29;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x2 = kk_integer_from_small(0); /*int*/
    goto _match_x29;
  }
  {
    _brw_x2 = kk_integer_from_small(1); /*int*/
  }
  _match_x29: ;
  kk_integer_t _brw_x1;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x1 = kk_integer_from_small(-1); /*int*/
    goto _match_x30;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x1 = kk_integer_from_small(0); /*int*/
    goto _match_x30;
  }
  {
    _brw_x1 = kk_integer_from_small(1); /*int*/
  }
  _match_x30: ;
  bool _brw_x3 = kk_integer_lt_borrow(_brw_x2,_brw_x1,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x2, _ctx);
  kk_integer_drop(_brw_x1, _ctx);
  return _brw_x3;
}
 
// Given a comparison function, we can order 2 elements.

kk_std_core_types__order2 kk_std_core_order_order2(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a> (x : a, y : a, ?cmp : (a, a) -> order) -> order2<a> */ 
  kk_std_core_types__order _match_x0;
  kk_function_t _x_x33 = kk_function_dup(_implicit_fs_cmp, _ctx); /*(243, 243) -> order*/
  kk_box_t _x_x31 = kk_box_dup(x, _ctx); /*243*/
  kk_box_t _x_x32 = kk_box_dup(y, _ctx); /*243*/
  _match_x0 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x33, (_x_x33, _x_x31, _x_x32, _ctx), _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x0, _ctx)) {
    kk_box_drop(y, _ctx);
    return kk_std_core_types__new_Eq2(x, _ctx);
  }
  if (kk_std_core_types__is_Lt(_match_x0, _ctx)) {
    return kk_std_core_types__new_Lt2(x, y, _ctx);
  }
  {
    return kk_std_core_types__new_Gt2(y, x, _ctx);
  }
}

// initialization
void kk_std_core_order__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_int__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_order__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_int__done(_ctx);
  kk_std_core_types__done(_ctx);
}
