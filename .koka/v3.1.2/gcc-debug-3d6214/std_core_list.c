// Koka generated module: std/core/list, koka version: 3.1.2, platform: 64-bit
#include "std_core_list.h"
 
// Return the head of list if the list is not empty.

kk_std_core_types__maybe kk_std_core_list_head(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1129 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1129->head;
    kk_std_core_types__list _pat_0 = _con_x1129->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_core_types__new_Just(x, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the head of list with a default value in case the list is empty.

kk_box_t kk_std_core_list_default_fs_head(kk_std_core_types__list xs, kk_box_t kkloc_default, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, default : a) -> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1130 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1130->head;
    kk_std_core_types__list _pat_0 = _con_x1130->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_drop(kkloc_default, _ctx);
    return x;
  }
  {
    return kkloc_default;
  }
}
 
// Return the tail of list. Returns the empty list if `xs` is empty.

kk_std_core_types__list kk_std_core_list_tail(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1131 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_0 = _con_x1131->head;
    kk_std_core_types__list xx = _con_x1131->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return xx;
  }
  {
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: length, len

kk_integer_t kk_std_core_list__lift_length_4947(kk_std_core_types__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1132 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _pat_0 = _con_x1132->head;
    kk_std_core_types__list yy = _con_x1132->tail;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ys, _ctx);
    }
    else {
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1133 = kk_integer_add_small_const(acc, 1, _ctx); /*int*/
      ys = yy;
      acc = _x_x1133;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// Element-wise list equality

bool kk_std_core_list__lp__eq__eq__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1134 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1134->head;
    kk_std_core_types__list xx = _con_x1134->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      return false;
    }
    {
      struct kk_std_core_types_Cons* _con_x1135 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1135->head;
      kk_std_core_types__list yy = _con_x1135->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      bool _match_x1054;
      kk_function_t _x_x1136 = kk_function_dup(_implicit_fs__lp__eq__eq__rp_, _ctx); /*(761, 761) -> bool*/
      _match_x1054 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1136, (_x_x1136, x, y, _ctx), _ctx); /*bool*/
      if (_match_x1054) { // tailcall
                          xs = xx;
                          ys = yy;
                          goto kk__tailcall;
      }
      {
        kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
        kk_std_core_types__list_drop(yy, _ctx);
        kk_std_core_types__list_drop(xx, _ctx);
        return false;
      }
    }
  }
  {
    kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return true;
    }
    {
      struct kk_std_core_types_Cons* _con_x1137 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_7 = _con_x1137->head;
      kk_std_core_types__list _pat_8 = _con_x1137->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_8, _ctx);
        kk_box_drop(_pat_7, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return false;
    }
  }
}
 
// Order on lists

kk_std_core_types__order kk_std_core_list_cmp(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1138 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1138->head;
    kk_std_core_types__list xx = _con_x1138->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_function_drop(_implicit_fs_cmp, _ctx);
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1139 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1139->head;
      kk_std_core_types__list yy = _con_x1139->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__order _match_x1053;
      kk_function_t _x_x1140 = kk_function_dup(_implicit_fs_cmp, _ctx); /*(830, 830) -> order*/
      _match_x1053 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1140, (_x_x1140, x, y, _ctx), _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x1053, _ctx)) { // tailcall
                                                          xs = xx;
                                                          ys = yy;
                                                          goto kk__tailcall;
      }
      {
        kk_function_drop(_implicit_fs_cmp, _ctx);
        kk_std_core_types__list_drop(yy, _ctx);
        kk_std_core_types__list_drop(xx, _ctx);
        return _match_x1053;
      }
    }
  }
  {
    kk_function_drop(_implicit_fs_cmp, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1141 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_6 = _con_x1141->head;
      kk_std_core_types__list _pat_7 = _con_x1141->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_7, _ctx);
        kk_box_drop(_pat_6, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list__trmc_take(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1142 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t x = _con_x1142->head;
      kk_std_core_types__list xx = _con_x1142->tail;
      kk_reuse_t _ru_x1065 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1065 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10055 = kk_datatype_null(); /*list<879>*/;
      kk_std_core_types__list _trmc_x10056 = kk_std_core_types__new_Cons(_ru_x1065, 0, x, _trmc_x10055, _ctx); /*list<879>*/;
      kk_field_addr_t _b_x5_10 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10056, _ctx)->tail, _ctx); /*@field-addr<list<879>>*/;
      { // tailcall
        kk_integer_t _x_x1143 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1144 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10056, _ctx)),_b_x5_10,kk_context()); /*ctx<0>*/
        xs = xx;
        n = _x_x1143;
        _acc = _x_x1144;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1145 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1145, KK_OWNED, _ctx);
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_take(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1146 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_take(xs_0, n_0, _x_x1146, _ctx);
}
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_drop(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1147 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t _pat_0 = _con_x1147->head;
      kk_std_core_types__list xx = _con_x1147->tail;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_box_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      { // tailcall
        kk_integer_t _x_x1148 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1148;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return xs;
  }
}
 
// lifted local: reverse-append, reverse-acc

kk_std_core_types__list kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__list acc, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1149 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t x = _con_x1149->head;
    kk_std_core_types__list xx = _con_x1149->tail;
    kk_reuse_t _ru_x1067 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1067 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x1150 = kk_std_core_types__new_Cons(_ru_x1067, 0, x, acc, _ctx); /*list<82>*/
      acc = _x_x1150;
      ys = xx;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__trmc_append(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1151 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1151->head;
    kk_std_core_types__list xx = _con_x1151->tail;
    kk_reuse_t _ru_x1068 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1068 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _trmc_x10057 = kk_datatype_null(); /*list<1016>*/;
    kk_std_core_types__list _trmc_x10058 = kk_std_core_types__new_Cons(_ru_x1068, 0, x, _trmc_x10057, _ctx); /*list<1016>*/;
    kk_field_addr_t _b_x21_26 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10058, _ctx)->tail, _ctx); /*@field-addr<list<1016>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1152 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10058, _ctx)),_b_x21_26,kk_context()); /*ctx<0>*/
      xs = xx;
      _acc = _x_x1152;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1153 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(ys, _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1153, KK_OWNED, _ctx);
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list_append(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1154 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_append(xs_0, ys_0, _x_x1154, _ctx);
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_foldl_10277(kk_function_t f, kk_std_core_types__list xx, kk_box_t _y_x10111, kk_context_t* _ctx) { /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */ 
  return kk_std_core_list_foldl(xx, _y_x10111, f, _ctx);
}
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`


// lift anonymous function
struct kk_std_core_list_foldl_fun1157__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_foldl_fun1157(kk_function_t _fself, kk_box_t _y_x10111_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldl_fun1157(kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_foldl_fun1157__t* _self = kk_function_alloc_as(struct kk_std_core_list_foldl_fun1157__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foldl_fun1157, kk_context());
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foldl_fun1157(kk_function_t _fself, kk_box_t _y_x10111_0, kk_context_t* _ctx) {
  struct kk_std_core_list_foldl_fun1157__t* _self = kk_function_as(struct kk_std_core_list_foldl_fun1157__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1073, 1072) -> 1074 1073 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1072> */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_foldl_10277(f_0, xx_0, _y_x10111_0, _ctx);
}

kk_box_t kk_std_core_list_foldl(kk_std_core_types__list xs, kk_box_t z, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1155 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1155->head;
    kk_std_core_types__list xx_0 = _con_x1155->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10307;
    kk_function_t _x_x1156 = kk_function_dup(f_0, _ctx); /*(1073, 1072) -> 1074 1073*/
    x_0_10307 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1156, (_x_x1156, z, x, _ctx), _ctx); /*1073*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10307, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list_new_foldl_fun1157(f_0, xx_0, _ctx), _ctx);
    }
    { // tailcall
      xs = xx_0;
      z = x_0_10307;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return z;
  }
}
extern kk_box_t kk_std_core_list_foldr_fun1159(kk_function_t _fself, kk_box_t x, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_list_foldr_fun1159__t* _self = kk_function_as(struct kk_std_core_list_foldr_fun1159__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1116, 1117) -> 1118 1117 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, y, x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_list_foldl1_fun1162__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_foldl1_fun1162(kk_function_t _fself, kk_box_t _b_x36, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldl1_fun1162(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_foldl1_fun1162, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_foldl1_fun1162(kk_function_t _fself, kk_box_t _b_x36, kk_box_t _b_x37, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1163 = kk_string_unbox(_b_x36); /*string*/
  kk_std_core_types__optional _x_x1164 = kk_std_core_types__optional_unbox(_b_x37, KK_OWNED, _ctx); /*? exception-info*/
  return kk_std_core_exn_throw(_x_x1163, _x_x1164, _ctx);
}

kk_box_t kk_std_core_list_foldl1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1160 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1160->head;
    kk_std_core_types__list xx = _con_x1160->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_core_list_foldl(xx, x, f, _ctx);
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t _b_x32_38;
    kk_std_core_hnd__htag _x_x1161 = kk_std_core_hnd__htag_dup(kk_std_core_exn__tag_exn, _ctx); /*hnd/htag<exn>*/
    _b_x32_38 = kk_std_core_hnd__evv_index(_x_x1161, _ctx); /*hnd/ev-index*/
    kk_box_t _x_x1165;
    kk_string_t _x_x1166;
    kk_define_string_literal(, _s_x1167, 33, "unexpected Nil in std/core/foldl1", _ctx)
    _x_x1166 = kk_string_dup(_s_x1167, _ctx); /*string*/
    _x_x1165 = kk_string_box(_x_x1166); /*9232*/
    return kk_std_core_hnd__open_at2(_b_x32_38, kk_std_core_list_new_foldl1_fun1162(_ctx), _x_x1165, kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_list_foldr1_fun1170__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_foldr1_fun1170(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldr1_fun1170(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_foldr1_fun1170, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_foldr1_fun1170(kk_function_t _fself, kk_box_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1171 = kk_string_unbox(_b_x46); /*string*/
  kk_std_core_types__optional _x_x1172 = kk_std_core_types__optional_unbox(_b_x47, KK_OWNED, _ctx); /*? exception-info*/
  return kk_std_core_exn_throw(_x_x1171, _x_x1172, _ctx);
}

kk_box_t kk_std_core_list_foldr1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  kk_std_core_types__list xs_0_10010 = kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<1195>*/;
  if (kk_std_core_types__is_Cons(xs_0_10010, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1168 = kk_std_core_types__as_Cons(xs_0_10010, _ctx);
    kk_box_t x = _con_x1168->head;
    kk_std_core_types__list xx = _con_x1168->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs_0_10010, _ctx)) {
      kk_datatype_ptr_free(xs_0_10010, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs_0_10010, _ctx);
    }
    return kk_std_core_list_foldl(xx, x, f, _ctx);
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t _b_x42_48;
    kk_std_core_hnd__htag _x_x1169 = kk_std_core_hnd__htag_dup(kk_std_core_exn__tag_exn, _ctx); /*hnd/htag<exn>*/
    _b_x42_48 = kk_std_core_hnd__evv_index(_x_x1169, _ctx); /*hnd/ev-index*/
    kk_box_t _x_x1173;
    kk_string_t _x_x1174;
    kk_define_string_literal(, _s_x1175, 33, "unexpected Nil in std/core/foldl1", _ctx)
    _x_x1174 = kk_string_dup(_s_x1175, _ctx); /*string*/
    _x_x1173 = kk_string_box(_x_x1174); /*9232*/
    return kk_std_core_hnd__open_at2(_b_x42_48, kk_std_core_list_new_foldr1_fun1170(_ctx), _x_x1173, kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx);
  }
}
 
// split a list at position `n`

kk_std_core_types__tuple2 kk_std_core_list_split(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 
  kk_std_core_types__list _b_x52_54;
  kk_std_core_types__list _x_x1176 = kk_std_core_types__list_dup(xs, _ctx); /*list<1233>*/
  kk_integer_t _x_x1177 = kk_integer_dup(n, _ctx); /*int*/
  _b_x52_54 = kk_std_core_list_take(_x_x1176, _x_x1177, _ctx); /*list<1233>*/
  kk_std_core_types__list _b_x53_55 = kk_std_core_list_drop(xs, n, _ctx); /*list<1233>*/;
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x52_54, _ctx), kk_std_core_types__list_box(_b_x53_55, _ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_drop_while_10278(kk_function_t predicate, kk_std_core_types__list xs, kk_std_core_types__list xx, bool _y_x10122, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10122) {
    kk_std_core_types__list_drop(xs, _ctx);
    return kk_std_core_list_drop_while(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return xs;
  }
}
 
// Drop all initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list_drop_while_fun1181__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xs_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_drop_while_fun1181(kk_function_t _fself, kk_box_t _b_x57, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_drop_while_fun1181(kk_function_t predicate_0, kk_std_core_types__list xs_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_drop_while_fun1181__t* _self = kk_function_alloc_as(struct kk_std_core_list_drop_while_fun1181__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_drop_while_fun1181, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xs_0 = xs_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_drop_while_fun1181(kk_function_t _fself, kk_box_t _b_x57, kk_context_t* _ctx) {
  struct kk_std_core_list_drop_while_fun1181__t* _self = kk_function_as(struct kk_std_core_list_drop_while_fun1181__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (1270) -> 1271 bool */
  kk_std_core_types__list xs_0 = _self->xs_0; /* list<1270> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1270> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xs_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10122_0_59 = kk_bool_unbox(_b_x57); /*bool*/;
  kk_std_core_types__list _x_x1182 = kk_std_core_list__mlift_drop_while_10278(predicate_0, xs_0, xx_0, _y_x10122_0_59, _ctx); /*list<1270>*/
  return kk_std_core_types__list_box(_x_x1182, _ctx);
}

kk_std_core_types__list kk_std_core_list_drop_while(kk_std_core_types__list xs_0, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1178 = kk_std_core_types__as_Cons(xs_0, _ctx);
    kk_box_t x = _con_x1178->head;
    kk_std_core_types__list xx_0 = _con_x1178->tail;
    kk_box_dup(x, _ctx);
    kk_std_core_types__list_dup(xx_0, _ctx);
    bool x_0_10310;
    kk_function_t _x_x1179 = kk_function_dup(predicate_0, _ctx); /*(1270) -> 1271 bool*/
    x_0_10310 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1179, (_x_x1179, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1180 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_drop_while_fun1181(predicate_0, xs_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1180, KK_OWNED, _ctx);
    }
    if (x_0_10310) {
      if kk_likely(kk_datatype_ptr_is_unique(xs_0, _ctx)) {
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_box_drop(x, _ctx);
        kk_datatype_ptr_free(xs_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(xs_0, _ctx);
      }
      { // tailcall
        xs_0 = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return xs_0;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_filter_10279(kk_std_core_types__cctx _acc, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10126, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10126) {
    kk_std_core_types__list _trmc_x10059 = kk_datatype_null(); /*list<1325>*/;
    kk_std_core_types__list _trmc_x10060 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10059, _ctx); /*list<1325>*/;
    kk_field_addr_t _b_x65_68 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10060, _ctx)->tail, _ctx); /*@field-addr<list<1325>>*/;
    kk_std_core_types__cctx _x_x1183 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10060, _ctx)),_b_x65_68,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_filter(xx, pred, _x_x1183, _ctx);
  }
  {
    kk_box_drop(x, _ctx);
    return kk_std_core_list__trmc_filter(xx, pred, _acc, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core_list__trmc_filter_fun1188__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_filter_fun1188(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_filter_fun1188(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_filter_fun1188__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_filter_fun1188__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_filter_fun1188, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_filter_fun1188(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_filter_fun1188__t* _self = kk_function_as(struct kk_std_core_list__trmc_filter_fun1188__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1325>> */
  kk_function_t pred_0 = _self->pred_0; /* (1325) -> 1326 bool */
  kk_box_t x_0 = _self->x_0; /* 1325 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1325> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10126_0_91 = kk_bool_unbox(_b_x73); /*bool*/;
  kk_std_core_types__list _x_x1189 = kk_std_core_list__mlift_trmc_filter_10279(_acc_0, pred_0, x_0, xx_0, _y_x10126_0_91, _ctx); /*list<1325>*/
  return kk_std_core_types__list_box(_x_x1189, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_filter(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1184 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1184->head;
    kk_std_core_types__list xx_0 = _con_x1184->tail;
    kk_reuse_t _ru_x1073 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1073 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10313;
    kk_function_t _x_x1186 = kk_function_dup(pred_0, _ctx); /*(1325) -> 1326 bool*/
    kk_box_t _x_x1185 = kk_box_dup(x_0, _ctx); /*1325*/
    x_1_10313 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1186, (_x_x1186, _x_x1185, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1073,kk_context());
      kk_box_t _x_x1187 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_filter_fun1188(_acc_0, pred_0, x_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1187, KK_OWNED, _ctx);
    }
    if (x_1_10313) {
      kk_std_core_types__list _trmc_x10059_0 = kk_datatype_null(); /*list<1325>*/;
      kk_std_core_types__list _trmc_x10060_0 = kk_std_core_types__new_Cons(_ru_x1073, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10059_0, _ctx); /*list<1325>*/;
      kk_field_addr_t _b_x79_85 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10060_0, _ctx)->tail, _ctx); /*@field-addr<list<1325>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1190 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10060_0, _ctx)),_b_x79_85,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1190;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1073,kk_context());
      kk_box_drop(x_0, _ctx);
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1191 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1191, KK_OWNED, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`

kk_std_core_types__list kk_std_core_list_filter(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1192 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_filter(xs_0, pred_1, _x_x1192, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_filter_map_10280(kk_std_core_types__cctx _acc, kk_function_t pred, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10132, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10132, _ctx)) {
    return kk_std_core_list__trmc_filter_map(xx, pred, _acc, _ctx);
  }
  {
    kk_box_t y = _y_x10132._cons.Just.value;
    kk_std_core_types__list _trmc_x10061 = kk_datatype_null(); /*list<1393>*/;
    kk_std_core_types__list _trmc_x10062 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10061, _ctx); /*list<1393>*/;
    kk_field_addr_t _b_x97_100 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10062, _ctx)->tail, _ctx); /*@field-addr<list<1393>>*/;
    kk_std_core_types__cctx _x_x1193 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10062, _ctx)),_b_x97_100,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_filter_map(xx, pred, _x_x1193, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core_list__trmc_filter_map_fun1198__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_filter_map_fun1198(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_filter_map_fun1198(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_filter_map_fun1198__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_filter_map_fun1198__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_filter_map_fun1198, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_filter_map_fun1198(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_filter_map_fun1198__t* _self = kk_function_as(struct kk_std_core_list__trmc_filter_map_fun1198__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1393>> */
  kk_function_t pred_0 = _self->pred_0; /* (1392) -> 1394 maybe<1393> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1392> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10132_0_123 = kk_std_core_types__maybe_unbox(_b_x107, KK_OWNED, _ctx); /*maybe<1393>*/;
  kk_std_core_types__list _x_x1199 = kk_std_core_list__mlift_trmc_filter_map_10280(_acc_0, pred_0, xx_0, _y_x10132_0_123, _ctx); /*list<1393>*/
  return kk_std_core_types__list_box(_x_x1199, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_filter_map(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1194 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1194, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1195 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1195->head;
    kk_std_core_types__list xx_0 = _con_x1195->tail;
    kk_reuse_t _ru_x1074 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1074 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10316;
    kk_function_t _x_x1196 = kk_function_dup(pred_0, _ctx); /*(1392) -> 1394 maybe<1393>*/
    x_0_10316 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1196, (_x_x1196, x, _ctx), _ctx); /*maybe<1393>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1074,kk_context());
      kk_std_core_types__maybe_drop(x_0_10316, _ctx);
      kk_box_t _x_x1197 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_filter_map_fun1198(_acc_0, pred_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1197, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10316, _ctx)) {
      kk_reuse_drop(_ru_x1074,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t y_0 = x_0_10316._cons.Just.value;
      kk_std_core_types__list _trmc_x10061_0 = kk_datatype_null(); /*list<1393>*/;
      kk_std_core_types__list _trmc_x10062_0 = kk_std_core_types__new_Cons(_ru_x1074, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10061_0, _ctx); /*list<1393>*/;
      kk_field_addr_t _b_x113_119 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10062_0, _ctx)->tail, _ctx); /*@field-addr<list<1393>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1200 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10062_0, _ctx)),_b_x113_119,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1200;
        goto kk__tailcall;
      }
    }
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`

kk_std_core_types__list kk_std_core_list_filter_map(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1201 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_filter_map(xs_0, pred_1, _x_x1201, _ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_foreach_while_10281(kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10138, kk_context_t* _ctx) { /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10138, _ctx)) {
    return kk_std_core_list_foreach_while(xx, action, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10138;
  }
}
 
// Invoke `action` for each element of a list while `action` return `Nothing`


// lift anonymous function
struct kk_std_core_list_foreach_while_fun1205__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_foreach_while_fun1205(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foreach_while_fun1205(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_while_fun1205__t* _self = kk_function_alloc_as(struct kk_std_core_list_foreach_while_fun1205__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foreach_while_fun1205, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foreach_while_fun1205(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_while_fun1205__t* _self = kk_function_as(struct kk_std_core_list_foreach_while_fun1205__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (1453) -> 1455 maybe<1454> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1453> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10138_0_127 = kk_std_core_types__maybe_unbox(_b_x125, KK_OWNED, _ctx); /*maybe<1454>*/;
  kk_std_core_types__maybe _x_x1206 = kk_std_core_list__mlift_foreach_while_10281(action_0, xx_0, _y_x10138_0_127, _ctx); /*maybe<1454>*/
  return kk_std_core_types__maybe_box(_x_x1206, _ctx);
}

kk_std_core_types__maybe kk_std_core_list_foreach_while(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1202 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1202->head;
    kk_std_core_types__list xx_0 = _con_x1202->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10319;
    kk_function_t _x_x1203 = kk_function_dup(action_0, _ctx); /*(1453) -> 1455 maybe<1454>*/
    x_0_10319 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1203, (_x_x1203, x, _ctx), _ctx); /*maybe<1454>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10319, _ctx);
      kk_box_t _x_x1204 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_foreach_while_fun1205(action_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x1204, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10319, _ctx)) { // tailcall
                                                          xs = xx_0;
                                                          goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_0_10319;
    }
  }
}
 
// Find the first element satisfying some predicate


// lift anonymous function
struct kk_std_core_list_find_fun1207__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_list_find_fun1207(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_find_fun1207(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_list_find_fun1207__t* _self = kk_function_alloc_as(struct kk_std_core_list_find_fun1207__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_find_fun1207, kk_context());
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_list_find_fun1210__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_core_list_find_fun1210(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_find_fun1210(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_list_find_fun1210__t* _self = kk_function_alloc_as(struct kk_std_core_list_find_fun1210__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_find_fun1210, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_find_fun1210(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx) {
  struct kk_std_core_list_find_fun1210__t* _self = kk_function_as(struct kk_std_core_list_find_fun1210__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 1515 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x1211;
  bool _y_x10142_131 = kk_bool_unbox(_b_x129); /*bool*/;
  if (_y_x10142_131) {
    _x_x1211 = kk_std_core_types__new_Just(x, _ctx); /*maybe<91>*/
  }
  else {
    kk_box_drop(x, _ctx);
    _x_x1211 = kk_std_core_types__new_Nothing(_ctx); /*maybe<91>*/
  }
  return kk_std_core_types__maybe_box(_x_x1211, _ctx);
}
static kk_std_core_types__maybe kk_std_core_list_find_fun1207(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_list_find_fun1207__t* _self = kk_function_as(struct kk_std_core_list_find_fun1207__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (1515) -> 1516 bool */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  bool x_0_10322;
  kk_box_t _x_x1208 = kk_box_dup(x, _ctx); /*1515*/
  x_0_10322 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, _x_x1208, _ctx), _ctx); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1209 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_find_fun1210(x, _ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x1209, KK_OWNED, _ctx);
  }
  if (x_0_10322) {
    return kk_std_core_types__new_Just(x, _ctx);
  }
  {
    kk_box_drop(x, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

kk_std_core_types__maybe kk_std_core_list_find(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e maybe<a> */ 
  return kk_std_core_list_foreach_while(xs, kk_std_core_list_new_find_fun1207(pred, _ctx), _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1046 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1046) {
    kk_std_core_types__list _trmc_x10063 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10064;
    kk_box_t _x_x1212;
    kk_integer_t _x_x1213 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1212 = kk_integer_box(_x_x1213, _ctx); /*82*/
    _trmc_x10064 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1212, _trmc_x10063, _ctx); /*list<int>*/
    kk_field_addr_t _b_x142_147 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10064, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1214 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1215 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10064, _ctx)),_b_x142_147,kk_context()); /*ctx<0>*/
      lo = _x_x1214;
      _acc = _x_x1215;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1216 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1216, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_context_t* _ctx) { /* (lo : int, hi : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1217 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_list(lo_0, hi_0, _x_x1217, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_map_10283(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_box_t _trmc_x10065, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10066 = kk_datatype_null(); /*list<1969>*/;
  kk_std_core_types__list _trmc_x10067 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10065, _trmc_x10066, _ctx); /*list<1969>*/;
  kk_field_addr_t _b_x158_161 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10067, _ctx)->tail, _ctx); /*@field-addr<list<1969>>*/;
  kk_std_core_types__cctx _x_x1218 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10067, _ctx)),_b_x158_161,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_map(xx, f, _x_x1218, _ctx);
}
 
// Apply a function `f` to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core_list__trmc_map_fun1222__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_map_fun1222(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_map_fun1222(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_map_fun1222__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_map_fun1222__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_map_fun1222, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_map_fun1222(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_map_fun1222__t* _self = kk_function_as(struct kk_std_core_list__trmc_map_fun1222__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1969>> */
  kk_function_t f_0 = _self->f_0; /* (1968) -> 1970 1969 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1968> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10065_0_184 = _b_x166; /*1969*/;
  kk_std_core_types__list _x_x1223 = kk_std_core_list__mlift_trmc_map_10283(_acc_0, f_0, xx_0, _trmc_x10065_0_184, _ctx); /*list<1969>*/
  return kk_std_core_types__list_box(_x_x1223, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_map(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1219 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1219->head;
    kk_std_core_types__list xx_0 = _con_x1219->tail;
    kk_reuse_t _ru_x1076 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1076 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10326;
    kk_function_t _x_x1220 = kk_function_dup(f_0, _ctx); /*(1968) -> 1970 1969*/
    x_0_10326 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1220, (_x_x1220, x, _ctx), _ctx); /*1969*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1076,kk_context());
      kk_box_drop(x_0_10326, _ctx);
      kk_box_t _x_x1221 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_map_fun1222(_acc_0, f_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1221, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10066_0 = kk_datatype_null(); /*list<1969>*/;
      kk_std_core_types__list _trmc_x10067_0 = kk_std_core_types__new_Cons(_ru_x1076, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10326, _trmc_x10066_0, _ctx); /*list<1969>*/;
      kk_field_addr_t _b_x172_178 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10067_0, _ctx)->tail, _ctx); /*@field-addr<list<1969>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1224 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10067_0, _ctx)),_b_x172_178,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1224;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1225 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1225, KK_OWNED, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence.

kk_std_core_types__list kk_std_core_list_map(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1226 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_map(xs_0, f_1, _x_x1226, _ctx);
}
 
// Create a list of characters from `lo`  to `hi`  (including `hi`).


// lift anonymous function
struct kk_std_core_list_char_fs_list_fun1229__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_char_fs_list_fun1229(kk_function_t _fself, kk_box_t _b_x187, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_char_fs_new_list_fun1229(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_char_fs_list_fun1229, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_char_fs_list_fun1229(kk_function_t _fself, kk_box_t _b_x187, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_char_t _x_x1230;
  kk_integer_t _x_x1231 = kk_integer_unbox(_b_x187, _ctx); /*int*/
  _x_x1230 = kk_integer_clamp32(_x_x1231,kk_context()); /*char*/
  return kk_char_box(_x_x1230, _ctx);
}

kk_std_core_types__list kk_std_core_list_char_fs_list(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx) { /* (lo : char, hi : char) -> list<char> */ 
  kk_std_core_types__list _b_x185_188;
  kk_integer_t _x_x1227 = kk_integer_from_int(lo,kk_context()); /*int*/
  kk_integer_t _x_x1228 = kk_integer_from_int(hi,kk_context()); /*int*/
  _b_x185_188 = kk_std_core_list_list(_x_x1227, _x_x1228, _ctx); /*list<int>*/
  return kk_std_core_list_map(_b_x185_188, kk_std_core_list_char_fs_new_list_fun1229(_ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_function_fs__mlift_trmc_list_10284(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_box_t _trmc_x10068, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10069 = kk_datatype_null(); /*list<1754>*/;
  kk_std_core_types__list _trmc_x10070 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10068, _trmc_x10069, _ctx); /*list<1754>*/;
  kk_field_addr_t _b_x195_198 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10070, _ctx)->tail, _ctx); /*@field-addr<list<1754>>*/;
  kk_integer_t _x_x1232 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
  kk_std_core_types__cctx _x_x1233 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10070, _ctx)),_b_x195_198,kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(_x_x1232, hi, f, _x_x1233, _ctx);
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_function_fs__trmc_list_fun1237__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
};
static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1237(kk_function_t _fself, kk_box_t _b_x203, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_function_fs__new_trmc_list_fun1237(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1237__t* _self = kk_function_alloc_as(struct kk_std_core_list_function_fs__trmc_list_fun1237__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_function_fs__trmc_list_fun1237, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1237(kk_function_t _fself, kk_box_t _b_x203, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1237__t* _self = kk_function_as(struct kk_std_core_list_function_fs__trmc_list_fun1237__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1754>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 1755 1754 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10068_0_221 = _b_x203; /*1754*/;
  kk_std_core_types__list _x_x1238 = kk_std_core_list_function_fs__mlift_trmc_list_10284(_acc_0, f_0, hi_0, lo_0, _trmc_x10068_0_221, _ctx); /*list<1754>*/
  return kk_std_core_types__list_box(_x_x1238, _ctx);
}

kk_std_core_types__list kk_std_core_list_function_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1043 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1043) {
    kk_box_t x_10329;
    kk_function_t _x_x1235 = kk_function_dup(f_0, _ctx); /*(int) -> 1755 1754*/
    kk_integer_t _x_x1234 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10329 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1235, (_x_x1235, _x_x1234, _ctx), _ctx); /*1754*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10329, _ctx);
      kk_box_t _x_x1236 = kk_std_core_hnd_yield_extend(kk_std_core_list_function_fs__new_trmc_list_fun1237(_acc_0, f_0, hi_0, lo_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1236, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10069_0 = kk_datatype_null(); /*list<1754>*/;
      kk_std_core_types__list _trmc_x10070_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10329, _trmc_x10069_0, _ctx); /*list<1754>*/;
      kk_field_addr_t _b_x209_215 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10070_0, _ctx)->tail, _ctx); /*@field-addr<list<1754>>*/;
      { // tailcall
        kk_integer_t _x_x1239 = kk_integer_add_small_const(lo_0, 1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1240 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10070_0, _ctx)),_b_x209_215,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1239;
        _acc_0 = _x_x1240;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1241 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1241, KK_OWNED, _ctx);
  }
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_function_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1242 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(lo_1, hi_1, f_1, _x_x1242, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_integer_t stride, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1042 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1042) {
    kk_std_core_types__list _trmc_x10071 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10072;
    kk_box_t _x_x1243;
    kk_integer_t _x_x1244 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1243 = kk_integer_box(_x_x1244, _ctx); /*82*/
    _trmc_x10072 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1243, _trmc_x10071, _ctx); /*list<int>*/
    kk_field_addr_t _b_x231_236 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10072, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1245;
      kk_integer_t _x_x1246 = kk_integer_dup(stride, _ctx); /*int*/
      _x_x1245 = kk_integer_add(lo,_x_x1246,kk_context()); /*int*/
      kk_std_core_types__cctx _x_x1247 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10072, _ctx)),_b_x231_236,kk_context()); /*ctx<0>*/
      lo = _x_x1245;
      _acc = _x_x1247;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(stride, _ctx);
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1248 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1248, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1249 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stride_fs__trmc_list(lo_0, hi_0, stride_0, _x_x1249, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_stridefunction_fs__mlift_trmc_list_10285(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_integer_t stride, kk_box_t _trmc_x10073, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10074 = kk_datatype_null(); /*list<1873>*/;
  kk_std_core_types__list _trmc_x10075 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10073, _trmc_x10074, _ctx); /*list<1873>*/;
  kk_field_addr_t _b_x247_250 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10075, _ctx)->tail, _ctx); /*@field-addr<list<1873>>*/;
  kk_integer_t _x_x1250;
  kk_integer_t _x_x1251 = kk_integer_dup(stride, _ctx); /*int*/
  _x_x1250 = kk_integer_add(lo,_x_x1251,kk_context()); /*int*/
  kk_std_core_types__cctx _x_x1252 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10075, _ctx)),_b_x247_250,kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(_x_x1250, hi, stride, f, _x_x1252, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_stridefunction_fs__trmc_list_fun1256__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
  kk_integer_t stride_0;
};
static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1256(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_stridefunction_fs__new_trmc_list_fun1256(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_integer_t stride_0, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1256__t* _self = kk_function_alloc_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1256__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_stridefunction_fs__trmc_list_fun1256, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  _self->stride_0 = stride_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1256(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1256__t* _self = kk_function_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1256__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1873>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 1874 1873 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_integer_t stride_0 = _self->stride_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);kk_integer_dup(stride_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10073_0_273 = _b_x255; /*1873*/;
  kk_std_core_types__list _x_x1257 = kk_std_core_list_stridefunction_fs__mlift_trmc_list_10285(_acc_0, f_0, hi_0, lo_0, stride_0, _trmc_x10073_0_273, _ctx); /*list<1873>*/
  return kk_std_core_types__list_box(_x_x1257, _ctx);
}

kk_std_core_types__list kk_std_core_list_stridefunction_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1040 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1040) {
    kk_box_t x_10332;
    kk_function_t _x_x1254 = kk_function_dup(f_0, _ctx); /*(int) -> 1874 1873*/
    kk_integer_t _x_x1253 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10332 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1254, (_x_x1254, _x_x1253, _ctx), _ctx); /*1873*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10332, _ctx);
      kk_box_t _x_x1255 = kk_std_core_hnd_yield_extend(kk_std_core_list_stridefunction_fs__new_trmc_list_fun1256(_acc_0, f_0, hi_0, lo_0, stride_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1255, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10074_0 = kk_datatype_null(); /*list<1873>*/;
      kk_std_core_types__list _trmc_x10075_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10332, _trmc_x10074_0, _ctx); /*list<1873>*/;
      kk_field_addr_t _b_x261_267 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10075_0, _ctx)->tail, _ctx); /*@field-addr<list<1873>>*/;
      { // tailcall
        kk_integer_t _x_x1258;
        kk_integer_t _x_x1259 = kk_integer_dup(stride_0, _ctx); /*int*/
        _x_x1258 = kk_integer_add(lo_0,_x_x1259,kk_context()); /*int*/
        kk_std_core_types__cctx _x_x1260 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10075_0, _ctx)),_b_x261_267,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1258;
        _acc_0 = _x_x1260;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(stride_0, _ctx);
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1261 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1261, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stridefunction_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_integer_t stride_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1262 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(lo_1, hi_1, stride_1, f_1, _x_x1262, _ctx);
}
 
// Apply a function `f` to each character in a string


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1263__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1263(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1263(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1263__t* _self = kk_function_alloc_as(struct kk_std_core_list_string_fs_map_fun1263__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_string_fs_map_fun1263, kk_context());
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1263(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1263__t* _self = kk_function_as(struct kk_std_core_list_string_fs_map_fun1263__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (char) -> 1922 char */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  kk_char_t _x_x1264;
  kk_char_t _x_x1265 = kk_char_unbox(_b_x276, KK_OWNED, _ctx); /*char*/
  _x_x1264 = kk_function_call(kk_char_t, (kk_function_t, kk_char_t, kk_context_t*), f, (f, _x_x1265, _ctx), _ctx); /*char*/
  return kk_char_box(_x_x1264, _ctx);
}


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1267__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1267(kk_function_t _fself, kk_box_t _b_x280, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1267(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_string_fs_map_fun1267, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1267(kk_function_t _fself, kk_box_t _b_x280, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1268;
  kk_std_core_types__list _x_x1269 = kk_std_core_types__list_unbox(_b_x280, KK_OWNED, _ctx); /*list<char>*/
  _x_x1268 = kk_std_core_string_listchar_fs_string(_x_x1269, _ctx); /*string*/
  return kk_string_box(_x_x1268);
}

kk_string_t kk_std_core_list_string_fs_map(kk_string_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<e> (s : string, f : (char) -> e char) -> e string */ 
  kk_std_core_types__list _b_x274_277 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
  kk_std_core_types__list x_10335 = kk_std_core_list_map(_b_x274_277, kk_std_core_list_string_fs_new_map_fun1263(f, _ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10335, _ctx);
    kk_box_t _x_x1266 = kk_std_core_hnd_yield_extend(kk_std_core_list_string_fs_new_map_fun1267(_ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x1266);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10335, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_map_indexed_4949_10286(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10018, kk_std_core_types__list yy, kk_box_t _trmc_x10076, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10018 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10077 = kk_datatype_null(); /*list<2069>*/;
  kk_std_core_types__list _trmc_x10078 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10076, _trmc_x10077, _ctx); /*list<2069>*/;
  kk_field_addr_t _b_x287_290 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10078, _ctx)->tail, _ctx); /*@field-addr<list<2069>>*/;
  kk_std_core_types__cctx _x_x1270 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10078, _ctx)),_b_x287_290,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_map_indexed_4949(f, yy, i_0_10018, _x_x1270, _ctx);
}
 
// lifted local: map-indexed, map-idx


// lift anonymous function
struct kk_std_core_list__trmc_lift_map_indexed_4949_fun1275__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10018_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_lift_map_indexed_4949_fun1275(kk_function_t _fself, kk_box_t _b_x295, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_map_indexed_4949_fun1275(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10018_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_map_indexed_4949_fun1275__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_map_indexed_4949_fun1275__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_map_indexed_4949_fun1275, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10018_0 = i_0_10018_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_map_indexed_4949_fun1275(kk_function_t _fself, kk_box_t _b_x295, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_map_indexed_4949_fun1275__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_map_indexed_4949_fun1275__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2069>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2068) -> 2070 2069 */
  kk_integer_t i_0_10018_0 = _self->i_0_10018_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2068> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10018_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10076_0_313 = _b_x295; /*2069*/;
  kk_std_core_types__list _x_x1276 = kk_std_core_list__mlift_trmc_lift_map_indexed_4949_10286(_acc_0, f_0, i_0_10018_0, yy_0, _trmc_x10076_0_313, _ctx); /*list<2069>*/
  return kk_std_core_types__list_box(_x_x1276, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_map_indexed_4949(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1271 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1271->head;
    kk_std_core_types__list yy_0 = _con_x1271->tail;
    kk_reuse_t _ru_x1077 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1077 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10018_0;
    kk_integer_t _x_x1272 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10018_0 = kk_integer_add_small_const(_x_x1272, 1, _ctx); /*int*/
    kk_box_t x_10337;
    kk_function_t _x_x1273 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2068) -> 2070 2069*/
    x_10337 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1273, (_x_x1273, i, y, _ctx), _ctx); /*2069*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1077,kk_context());
      kk_box_drop(x_10337, _ctx);
      kk_box_t _x_x1274 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_map_indexed_4949_fun1275(_acc_0, f_0, i_0_10018_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1274, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10077_0 = kk_datatype_null(); /*list<2069>*/;
      kk_std_core_types__list _trmc_x10078_0 = kk_std_core_types__new_Cons(_ru_x1077, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10337, _trmc_x10077_0, _ctx); /*list<2069>*/;
      kk_field_addr_t _b_x301_307 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10078_0, _ctx)->tail, _ctx); /*@field-addr<list<2069>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1277 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10078_0, _ctx)),_b_x301_307,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10018_0;
        _acc_0 = _x_x1277;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1278 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1278, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed, map-idx

kk_std_core_types__list kk_std_core_list__lift_map_indexed_4949(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1279 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_map_indexed_4949(f_1, ys_0, i_0, _x_x1279, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_map_peek_4950_10287(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list yy, kk_box_t _trmc_x10079, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10080 = kk_datatype_null(); /*list<2121>*/;
  kk_std_core_types__list _trmc_x10081 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10079, _trmc_x10080, _ctx); /*list<2121>*/;
  kk_field_addr_t _b_x319_322 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10081, _ctx)->tail, _ctx); /*@field-addr<list<2121>>*/;
  kk_std_core_types__cctx _x_x1280 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10081, _ctx)),_b_x319_322,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_map_peek_4950(f, yy, _x_x1280, _ctx);
}
 
// lifted local: map-peek, mappeek


// lift anonymous function
struct kk_std_core_list__trmc_lift_map_peek_4950_fun1285__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_lift_map_peek_4950_fun1285(kk_function_t _fself, kk_box_t _b_x327, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_map_peek_4950_fun1285(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_map_peek_4950_fun1285__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_map_peek_4950_fun1285__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_map_peek_4950_fun1285, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_map_peek_4950_fun1285(kk_function_t _fself, kk_box_t _b_x327, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_map_peek_4950_fun1285__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_map_peek_4950_fun1285__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2121>> */
  kk_function_t f_0 = _self->f_0; /* (value : 2120, rest : list<2120>) -> 2122 2121 */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2120> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10079_0_345 = _b_x327; /*2121*/;
  kk_std_core_types__list _x_x1286 = kk_std_core_list__mlift_trmc_lift_map_peek_4950_10287(_acc_0, f_0, yy_0, _trmc_x10079_0_345, _ctx); /*list<2121>*/
  return kk_std_core_types__list_box(_x_x1286, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_map_peek_4950(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1281 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1281->head;
    kk_std_core_types__list yy_0 = _con_x1281->tail;
    kk_reuse_t _ru_x1078 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1078 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_box_t x_10340;
    kk_function_t _x_x1283 = kk_function_dup(f_0, _ctx); /*(value : 2120, rest : list<2120>) -> 2122 2121*/
    kk_std_core_types__list _x_x1282 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2120>*/
    x_10340 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1283, (_x_x1283, y, _x_x1282, _ctx), _ctx); /*2121*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1078,kk_context());
      kk_box_drop(x_10340, _ctx);
      kk_box_t _x_x1284 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_map_peek_4950_fun1285(_acc_0, f_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1284, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10080_0 = kk_datatype_null(); /*list<2121>*/;
      kk_std_core_types__list _trmc_x10081_0 = kk_std_core_types__new_Cons(_ru_x1078, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10340, _trmc_x10080_0, _ctx); /*list<2121>*/;
      kk_field_addr_t _b_x333_339 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10081_0, _ctx)->tail, _ctx); /*@field-addr<list<2121>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1287 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10081_0, _ctx)),_b_x333_339,kk_context()); /*ctx<0>*/
        ys = yy_0;
        _acc_0 = _x_x1287;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1288 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1288, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-peek, mappeek

kk_std_core_types__list kk_std_core_list__lift_map_peek_4950(kk_function_t f_1, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1289 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_map_peek_4950(f_1, ys_0, _x_x1289, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_map_indexed_peek_4951_10288(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10021, kk_std_core_types__list yy, kk_box_t _trmc_x10082, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10021 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10083 = kk_datatype_null(); /*list<2183>*/;
  kk_std_core_types__list _trmc_x10084 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10082, _trmc_x10083, _ctx); /*list<2183>*/;
  kk_field_addr_t _b_x351_354 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10084, _ctx)->tail, _ctx); /*@field-addr<list<2183>>*/;
  kk_std_core_types__cctx _x_x1290 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10084, _ctx)),_b_x351_354,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_map_indexed_peek_4951(f, yy, i_0_10021, _x_x1290, _ctx);
}
 
// lifted local: map-indexed-peek, mapidx


// lift anonymous function
struct kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10021_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296(kk_function_t _fself, kk_box_t _b_x359, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_map_indexed_peek_4951_fun1296(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10021_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10021_0 = i_0_10021_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296(kk_function_t _fself, kk_box_t _b_x359, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_map_indexed_peek_4951_fun1296__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2183>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2182, rest : list<2182>) -> 2184 2183 */
  kk_integer_t i_0_10021_0 = _self->i_0_10021_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2182> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10021_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10082_0_377 = _b_x359; /*2183*/;
  kk_std_core_types__list _x_x1297 = kk_std_core_list__mlift_trmc_lift_map_indexed_peek_4951_10288(_acc_0, f_0, i_0_10021_0, yy_0, _trmc_x10082_0_377, _ctx); /*list<2183>*/
  return kk_std_core_types__list_box(_x_x1297, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_map_indexed_peek_4951(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1291 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1291->head;
    kk_std_core_types__list yy_0 = _con_x1291->tail;
    kk_reuse_t _ru_x1079 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1079 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10021_0;
    kk_integer_t _x_x1292 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10021_0 = kk_integer_add_small_const(_x_x1292, 1, _ctx); /*int*/
    kk_box_t x_10343;
    kk_function_t _x_x1294 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2182, rest : list<2182>) -> 2184 2183*/
    kk_std_core_types__list _x_x1293 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2182>*/
    x_10343 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1294, (_x_x1294, i, y, _x_x1293, _ctx), _ctx); /*2183*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1079,kk_context());
      kk_box_drop(x_10343, _ctx);
      kk_box_t _x_x1295 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_map_indexed_peek_4951_fun1296(_acc_0, f_0, i_0_10021_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1295, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10083_0 = kk_datatype_null(); /*list<2183>*/;
      kk_std_core_types__list _trmc_x10084_0 = kk_std_core_types__new_Cons(_ru_x1079, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10343, _trmc_x10083_0, _ctx); /*list<2183>*/;
      kk_field_addr_t _b_x365_371 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10084_0, _ctx)->tail, _ctx); /*@field-addr<list<2183>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1298 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10084_0, _ctx)),_b_x365_371,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10021_0;
        _acc_0 = _x_x1298;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1299 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1299, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed-peek, mapidx

kk_std_core_types__list kk_std_core_list__lift_map_indexed_peek_4951(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1300 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_map_indexed_peek_4951(f_1, ys_0, i_0, _x_x1300, _ctx);
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list__trmc_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_x1035 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1035) {
    kk_std_core_types__list _trmc_x10085 = kk_datatype_null(); /*list<2235>*/;
    kk_std_core_types__list _trmc_x10086;
    kk_box_t _x_x1301 = kk_box_dup(x, _ctx); /*2235*/
    _trmc_x10086 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1301, _trmc_x10085, _ctx); /*list<2235>*/
    kk_field_addr_t _b_x383_388 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10086, _ctx)->tail, _ctx); /*@field-addr<list<2235>>*/;
    { // tailcall
      kk_integer_t _x_x1302 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1303 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10086, _ctx)),_b_x383_388,kk_context()); /*ctx<0>*/
      n = _x_x1302;
      _acc = _x_x1303;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(x, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1304 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1304, KK_OWNED, _ctx);
  }
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list_replicate(kk_box_t x_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (x : a, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1305 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_replicate(x_0, n_0, _x_x1305, _ctx);
}
 
// Remove those elements of a list that satisfy the given predicate `pred`.
// For example: `remove([1,2,3],odd?) == [2]`


// lift anonymous function
struct kk_std_core_list_remove_fun1306__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static bool kk_std_core_list_remove_fun1306(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_remove_fun1306(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_list_remove_fun1306__t* _self = kk_function_alloc_as(struct kk_std_core_list_remove_fun1306__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_remove_fun1306, kk_context());
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_list_remove_fun1308__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_remove_fun1308(kk_function_t _fself, kk_box_t _b_x395, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_remove_fun1308(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_remove_fun1308, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_remove_fun1308(kk_function_t _fself, kk_box_t _b_x395, kk_context_t* _ctx) {
  kk_unused(_fself);
  bool _y_x10173_397 = kk_bool_unbox(_b_x395); /*bool*/;
  bool _x_x1309;
  if (_y_x10173_397) {
    _x_x1309 = false; /*bool*/
  }
  else {
    _x_x1309 = true; /*bool*/
  }
  return kk_bool_box(_x_x1309);
}
static bool kk_std_core_list_remove_fun1306(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_list_remove_fun1306__t* _self = kk_function_as(struct kk_std_core_list_remove_fun1306__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (2269) -> 2270 bool */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  bool x_0_10346 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, x, _ctx), _ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1307 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_remove_fun1308(_ctx), _ctx); /*2978*/
    return kk_bool_unbox(_x_x1307);
  }
  if (x_0_10346) {
    return false;
  }
  {
    return true;
  }
}

kk_std_core_types__list kk_std_core_list_remove(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  return kk_std_core_list_filter(xs, kk_std_core_list_new_remove_fun1306(pred, _ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_partition_acc_10290(kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10175, kk_context_t* _ctx) { /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_x10175) {
    kk_std_core_types__list _cctx_x2361;
    kk_std_core_types__list _x_x1310 = kk_datatype_null(); /*list<2413>*/
    _cctx_x2361 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1310, _ctx); /*list<2413>*/
    kk_field_addr_t _cctx_x2362 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2361, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
    kk_std_core_types__list _b_x404_414 = _cctx_x2361; /*list<2413>*/;
    kk_field_addr_t _b_x405_415 = _cctx_x2362; /*@field-addr<list<2413>>*/;
    kk_std_core_types__cctx _own_x1032;
    kk_std_core_types__cctx _x_x1311 = kk_cctx_create((kk_std_core_types__list_box(_b_x404_414, _ctx)),_b_x405_415,kk_context()); /*cctx<0,1>*/
    _own_x1032 = kk_cctx_compose(acc1,_x_x1311,kk_context()); /*cctx<371,373>*/
    kk_std_core_types__tuple2 _brw_x1033 = kk_std_core_list_partition_acc(xx, pred, _own_x1032, acc2, _ctx); /*(list<266>, list<266>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1033;
  }
  {
    kk_std_core_types__list _cctx_x2404;
    kk_std_core_types__list _x_x1312 = kk_datatype_null(); /*list<2413>*/
    _cctx_x2404 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1312, _ctx); /*list<2413>*/
    kk_field_addr_t _cctx_x2405 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2404, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
    kk_std_core_types__list _b_x412_416 = _cctx_x2404; /*list<2413>*/;
    kk_field_addr_t _b_x413_417 = _cctx_x2405; /*@field-addr<list<2413>>*/;
    kk_std_core_types__cctx _own_x1030;
    kk_std_core_types__cctx _x_x1313 = kk_cctx_create((kk_std_core_types__list_box(_b_x412_416, _ctx)),_b_x413_417,kk_context()); /*cctx<0,1>*/
    _own_x1030 = kk_cctx_compose(acc2,_x_x1313,kk_context()); /*cctx<371,373>*/
    kk_std_core_types__tuple2 _brw_x1031 = kk_std_core_list_partition_acc(xx, pred, acc1, _own_x1030, _ctx); /*(list<266>, list<266>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1031;
  }
}


// lift anonymous function
struct kk_std_core_list_partition_acc_fun1321__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx acc1_0;
  kk_std_core_types__cctx acc2_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_partition_acc_fun1321(kk_function_t _fself, kk_box_t _b_x425, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_partition_acc_fun1321(kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_partition_acc_fun1321__t* _self = kk_function_alloc_as(struct kk_std_core_list_partition_acc_fun1321__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_partition_acc_fun1321, kk_context());
  _self->acc1_0 = acc1_0;
  _self->acc2_0 = acc2_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_partition_acc_fun1321(kk_function_t _fself, kk_box_t _b_x425, kk_context_t* _ctx) {
  struct kk_std_core_list_partition_acc_fun1321__t* _self = kk_function_as(struct kk_std_core_list_partition_acc_fun1321__t*, _fself, _ctx);
  kk_std_core_types__cctx acc1_0 = _self->acc1_0; /* ctx<list<2413>> */
  kk_std_core_types__cctx acc2_0 = _self->acc2_0; /* ctx<list<2413>> */
  kk_function_t pred_0 = _self->pred_0; /* (2413) -> 2414 bool */
  kk_box_t x_0 = _self->x_0; /* 2413 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2413> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(acc1_0, _ctx);kk_std_core_types__cctx_dup(acc2_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10175_0_453 = kk_bool_unbox(_b_x425); /*bool*/;
  kk_std_core_types__tuple2 _x_x1322 = kk_std_core_list__mlift_partition_acc_10290(acc1_0, acc2_0, pred_0, x_0, xx_0, _y_x10175_0_453, _ctx); /*(list<2413>, list<2413>)*/
  return kk_std_core_types__tuple2_box(_x_x1322, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list_partition_acc(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x422_442;
    kk_box_t _x_x1314 = kk_cctx_apply(acc1_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x422_442 = kk_std_core_types__list_unbox(_x_x1314, KK_OWNED, _ctx); /*list<2413>*/
    kk_std_core_types__list _b_x423_443;
    kk_box_t _x_x1315 = kk_cctx_apply(acc2_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x423_443 = kk_std_core_types__list_unbox(_x_x1315, KK_OWNED, _ctx); /*list<2413>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x422_442, _ctx), kk_std_core_types__list_box(_b_x423_443, _ctx), _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1316 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1316->head;
    kk_std_core_types__list xx_0 = _con_x1316->tail;
    kk_reuse_t _ru_x1080 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1080 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10349;
    kk_function_t _x_x1318 = kk_function_dup(pred_0, _ctx); /*(2413) -> 2414 bool*/
    kk_box_t _x_x1317 = kk_box_dup(x_0, _ctx); /*2413*/
    x_1_10349 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1318, (_x_x1318, _x_x1317, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1080,kk_context());
      kk_box_t _x_x1319;
      kk_function_t _x_x1320;
      kk_function_dup(pred_0, _ctx);
      _x_x1320 = kk_std_core_list_new_partition_acc_fun1321(acc1_0, acc2_0, pred_0, x_0, xx_0, _ctx); /*(2977) -> 2979 2978*/
      _x_x1319 = kk_std_core_hnd_yield_extend(_x_x1320, _ctx); /*2978*/
      return kk_std_core_types__tuple2_unbox(_x_x1319, KK_OWNED, _ctx);
    }
    if (x_1_10349) {
      kk_std_core_types__list _cctx_x2361_0;
      kk_std_core_types__list _x_x1323 = kk_datatype_null(); /*list<2413>*/
      _cctx_x2361_0 = kk_std_core_types__new_Cons(_ru_x1080, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1323, _ctx); /*list<2413>*/
      kk_field_addr_t _cctx_x2362_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2361_0, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
      kk_std_core_types__list _b_x432_449 = _cctx_x2361_0; /*list<2413>*/;
      kk_field_addr_t _b_x433_450 = _cctx_x2362_0; /*@field-addr<list<2413>>*/;
      kk_std_core_types__cctx _own_x1029;
      kk_std_core_types__cctx _x_x1324 = kk_cctx_create((kk_std_core_types__list_box(_b_x432_449, _ctx)),_b_x433_450,kk_context()); /*cctx<0,1>*/
      _own_x1029 = kk_cctx_compose(acc1_0,_x_x1324,kk_context()); /*cctx<371,373>*/
      { // tailcall
        xs = xx_0;
        acc1_0 = _own_x1029;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _cctx_x2404_0;
      kk_std_core_types__list _x_x1325 = kk_datatype_null(); /*list<2413>*/
      _cctx_x2404_0 = kk_std_core_types__new_Cons(_ru_x1080, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1325, _ctx); /*list<2413>*/
      kk_field_addr_t _cctx_x2405_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2404_0, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
      kk_std_core_types__list _b_x440_451 = _cctx_x2404_0; /*list<2413>*/;
      kk_field_addr_t _b_x441_452 = _cctx_x2405_0; /*@field-addr<list<2413>>*/;
      kk_std_core_types__cctx _own_x1028;
      kk_std_core_types__cctx _x_x1326 = kk_cctx_create((kk_std_core_types__list_box(_b_x440_451, _ctx)),_b_x441_452,kk_context()); /*cctx<0,1>*/
      _own_x1028 = kk_cctx_compose(acc2_0,_x_x1326,kk_context()); /*cctx<371,373>*/
      { // tailcall
        xs = xx_0;
        acc2_0 = _own_x1028;
        goto kk__tailcall;
      }
    }
  }
}
 
// Lookup the first element satisfying some predicate


// lift anonymous function
struct kk_std_core_list_lookup_fun1328__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_list_lookup_fun1328(kk_function_t _fself, kk_box_t _b_x458, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_lookup_fun1328(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_list_lookup_fun1328__t* _self = kk_function_alloc_as(struct kk_std_core_list_lookup_fun1328__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_lookup_fun1328, kk_context());
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_list_lookup_fun1331__t {
  struct kk_function_s _base;
  kk_box_t _b_x458;
};
static kk_std_core_types__maybe kk_std_core_list_lookup_fun1331(kk_function_t _fself, bool _y_x10181, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_lookup_fun1331(kk_box_t _b_x458, kk_context_t* _ctx) {
  struct kk_std_core_list_lookup_fun1331__t* _self = kk_function_alloc_as(struct kk_std_core_list_lookup_fun1331__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_lookup_fun1331, kk_context());
  _self->_b_x458 = _b_x458;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_core_list_lookup_fun1331(kk_function_t _fself, bool _y_x10181, kk_context_t* _ctx) {
  struct kk_std_core_list_lookup_fun1331__t* _self = kk_function_as(struct kk_std_core_list_lookup_fun1331__t*, _fself, _ctx);
  kk_box_t _b_x458 = _self->_b_x458; /* 1453 */
  kk_drop_match(_self, {kk_box_dup(_b_x458, _ctx);}, {}, _ctx)
  if (_y_x10181) {
    kk_box_t _x_x1332;
    kk_std_core_types__tuple2 _match_x1023 = kk_std_core_types__tuple2_unbox(_b_x458, KK_OWNED, _ctx); /*(2578, 2579)*/;
    {
      kk_box_t _x_0 = _match_x1023.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(_match_x1023, _ctx);
      _x_x1332 = _x_0; /*2579*/
    }
    return kk_std_core_types__new_Just(_x_x1332, _ctx);
  }
  {
    kk_box_drop(_b_x458, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_core_list_lookup_fun1334__t {
  struct kk_function_s _base;
  kk_function_t next_10353;
};
static kk_box_t kk_std_core_list_lookup_fun1334(kk_function_t _fself, kk_box_t _b_x455, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_lookup_fun1334(kk_function_t next_10353, kk_context_t* _ctx) {
  struct kk_std_core_list_lookup_fun1334__t* _self = kk_function_alloc_as(struct kk_std_core_list_lookup_fun1334__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_lookup_fun1334, kk_context());
  _self->next_10353 = next_10353;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_lookup_fun1334(kk_function_t _fself, kk_box_t _b_x455, kk_context_t* _ctx) {
  struct kk_std_core_list_lookup_fun1334__t* _self = kk_function_as(struct kk_std_core_list_lookup_fun1334__t*, _fself, _ctx);
  kk_function_t next_10353 = _self->next_10353; /* (bool) -> 2580 maybe<2579> */
  kk_drop_match(_self, {kk_function_dup(next_10353, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x1335;
  bool _x_x1336 = kk_bool_unbox(_b_x455); /*bool*/
  _x_x1335 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, bool, kk_context_t*), next_10353, (next_10353, _x_x1336, _ctx), _ctx); /*maybe<2579>*/
  return kk_std_core_types__maybe_box(_x_x1335, _ctx);
}
static kk_std_core_types__maybe kk_std_core_list_lookup_fun1328(kk_function_t _fself, kk_box_t _b_x458, kk_context_t* _ctx) {
  struct kk_std_core_list_lookup_fun1328__t* _self = kk_function_as(struct kk_std_core_list_lookup_fun1328__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (2578) -> 2580 bool */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  bool x_10352;
  kk_box_t _x_x1329;
  kk_std_core_types__tuple2 _match_x1024;
  kk_box_t _x_x1330 = kk_box_dup(_b_x458, _ctx); /*1453*/
  _match_x1024 = kk_std_core_types__tuple2_unbox(_x_x1330, KK_OWNED, _ctx); /*(2578, 2579)*/
  {
    kk_box_t _x = _match_x1024.fst;
    kk_box_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1024, _ctx);
    _x_x1329 = _x; /*2578*/
  }
  x_10352 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, _x_x1329, _ctx), _ctx); /*bool*/
  kk_function_t next_10353 = kk_std_core_list_new_lookup_fun1331(_b_x458, _ctx); /*(bool) -> 2580 maybe<2579>*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1333 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_lookup_fun1334(next_10353, _ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x1333, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_std_core_types__maybe, (kk_function_t, bool, kk_context_t*), next_10353, (next_10353, x_10352, _ctx), _ctx);
  }
}

kk_std_core_types__maybe kk_std_core_list_lookup(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<(a, b)>, pred : (a) -> e bool) -> e maybe<b> */ 
  return kk_std_core_list_foreach_while(xs, kk_std_core_list_new_lookup_fun1328(pred, _ctx), _ctx);
}
 
// monadic lift

kk_integer_t kk_std_core_list__mlift_index_of_acc_10292(kk_integer_t idx, kk_function_t pred, kk_std_core_types__list xx, bool _y_x10184, kk_context_t* _ctx) { /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */ 
  if (_y_x10184) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(pred, _ctx);
    return idx;
  }
  {
    kk_integer_t _x_x1337 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/
    return kk_std_core_list_index_of_acc(xx, pred, _x_x1337, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_list_index_of_acc_fun1341__t {
  struct kk_function_s _base;
  kk_integer_t idx_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_index_of_acc_fun1341(kk_function_t _fself, kk_box_t _b_x464, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_index_of_acc_fun1341(kk_integer_t idx_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_index_of_acc_fun1341__t* _self = kk_function_alloc_as(struct kk_std_core_list_index_of_acc_fun1341__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_index_of_acc_fun1341, kk_context());
  _self->idx_0 = idx_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_index_of_acc_fun1341(kk_function_t _fself, kk_box_t _b_x464, kk_context_t* _ctx) {
  struct kk_std_core_list_index_of_acc_fun1341__t* _self = kk_function_as(struct kk_std_core_list_index_of_acc_fun1341__t*, _fself, _ctx);
  kk_integer_t idx_0 = _self->idx_0; /* int */
  kk_function_t pred_0 = _self->pred_0; /* (2625) -> 2626 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2625> */
  kk_drop_match(_self, {kk_integer_dup(idx_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10184_0_466 = kk_bool_unbox(_b_x464); /*bool*/;
  kk_integer_t _x_x1342 = kk_std_core_list__mlift_index_of_acc_10292(idx_0, pred_0, xx_0, _y_x10184_0_466, _ctx); /*int*/
  return kk_integer_box(_x_x1342, _ctx);
}

kk_integer_t kk_std_core_list_index_of_acc(kk_std_core_types__list xs, kk_function_t pred_0, kk_integer_t idx_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1338 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1338->head;
    kk_std_core_types__list xx_0 = _con_x1338->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10356;
    kk_function_t _x_x1339 = kk_function_dup(pred_0, _ctx); /*(2625) -> 2626 bool*/
    x_0_10356 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1339, (_x_x1339, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1340 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_index_of_acc_fun1341(idx_0, pred_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_integer_unbox(_x_x1340, _ctx);
    }
    if (x_0_10356) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(pred_0, _ctx);
      return idx_0;
    }
    { // tailcall
      kk_integer_t _x_x1343 = kk_integer_add_small_const(idx_0, 1, _ctx); /*int*/
      xs = xx_0;
      idx_0 = _x_x1343;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_integer_drop(idx_0, _ctx);
    return kk_integer_from_small(-1);
  }
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_foreach_10293(kk_function_t action, kk_std_core_types__list xx, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 
  kk_std_core_list_foreach(xx, action, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list


// lift anonymous function
struct kk_std_core_list_foreach_fun1347__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_foreach_fun1347(kk_function_t _fself, kk_box_t _b_x468, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foreach_fun1347(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_fun1347__t* _self = kk_function_alloc_as(struct kk_std_core_list_foreach_fun1347__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foreach_fun1347, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foreach_fun1347(kk_function_t _fself, kk_box_t _b_x468, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_fun1347__t* _self = kk_function_as(struct kk_std_core_list_foreach_fun1347__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (2691) -> 2692 () */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2691> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_470 = kk_Unit;
  kk_unit_unbox(_b_x468);
  kk_unit_t _x_x1348 = kk_Unit;
  kk_std_core_list__mlift_foreach_10293(action_0, xx_0, wild___0_470, _ctx);
  return kk_unit_box(_x_x1348);
}

kk_unit_t kk_std_core_list_foreach(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1344 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1344->head;
    kk_std_core_types__list xx_0 = _con_x1344->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_unit_t x_0_10359 = kk_Unit;
    kk_function_t _x_x1345 = kk_function_dup(action_0, _ctx); /*(2691) -> 2692 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1345, (_x_x1345, x, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1346 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_foreach_fun1347(action_0, xx_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x1346); return kk_Unit;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_map_while_10294(kk_std_core_types__cctx _acc, kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10192, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10192, _ctx)) {
    kk_box_t y = _y_x10192._cons.Just.value;
    kk_std_core_types__list _trmc_x10087 = kk_datatype_null(); /*list<2754>*/;
    kk_std_core_types__list _trmc_x10088 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10087, _ctx); /*list<2754>*/;
    kk_field_addr_t _b_x476_481 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10088, _ctx)->tail, _ctx); /*@field-addr<list<2754>>*/;
    kk_std_core_types__cctx _x_x1349 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10088, _ctx)),_b_x476_481,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_map_while(xx, action, _x_x1349, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    kk_box_t _x_x1350 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1350, KK_OWNED, _ctx);
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core_list__trmc_map_while_fun1355__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_map_while_fun1355(kk_function_t _fself, kk_box_t _b_x490, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_map_while_fun1355(kk_std_core_types__cctx _acc_0, kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_map_while_fun1355__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_map_while_fun1355__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_map_while_fun1355, kk_context());
  _self->_acc_0 = _acc_0;
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_map_while_fun1355(kk_function_t _fself, kk_box_t _b_x490, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_map_while_fun1355__t* _self = kk_function_as(struct kk_std_core_list__trmc_map_while_fun1355__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2754>> */
  kk_function_t action_0 = _self->action_0; /* (2753) -> 2755 maybe<2754> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2753> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10192_0_510 = kk_std_core_types__maybe_unbox(_b_x490, KK_OWNED, _ctx); /*maybe<2754>*/;
  kk_std_core_types__list _x_x1356 = kk_std_core_list__mlift_trmc_map_while_10294(_acc_0, action_0, xx_0, _y_x10192_0_510, _ctx); /*list<2754>*/
  return kk_std_core_types__list_box(_x_x1356, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_map_while(kk_std_core_types__list xs, kk_function_t action_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    kk_box_t _x_x1351 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1351, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1352 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1352->head;
    kk_std_core_types__list xx_0 = _con_x1352->tail;
    kk_reuse_t _ru_x1083 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1083 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10362;
    kk_function_t _x_x1353 = kk_function_dup(action_0, _ctx); /*(2753) -> 2755 maybe<2754>*/
    x_0_10362 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1353, (_x_x1353, x, _ctx), _ctx); /*maybe<2754>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1083,kk_context());
      kk_std_core_types__maybe_drop(x_0_10362, _ctx);
      kk_box_t _x_x1354 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_map_while_fun1355(_acc_0, action_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1354, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10362, _ctx)) {
      kk_box_t y_0 = x_0_10362._cons.Just.value;
      kk_std_core_types__list _trmc_x10087_0 = kk_datatype_null(); /*list<2754>*/;
      kk_std_core_types__list _trmc_x10088_0 = kk_std_core_types__new_Cons(_ru_x1083, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10087_0, _ctx); /*list<2754>*/;
      kk_field_addr_t _b_x496_504 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10088_0, _ctx)->tail, _ctx); /*@field-addr<list<2754>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1357 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10088_0, _ctx)),_b_x496_504,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1357;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1083,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      kk_box_t _x_x1358 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1358, KK_OWNED, _ctx);
    }
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`

kk_std_core_types__list kk_std_core_list_map_while(kk_std_core_types__list xs_0, kk_function_t action_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1359 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_map_while(xs_0, action_1, _x_x1359, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_foreach_indexed_10296_fun1362__t {
  struct kk_function_s _base;
  kk_ref_t i;
};
static kk_unit_t kk_std_core_list__mlift_foreach_indexed_10296_fun1362(kk_function_t _fself, kk_integer_t _y_x10200, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_foreach_indexed_10296_fun1362(kk_ref_t i, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_foreach_indexed_10296_fun1362__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_foreach_indexed_10296_fun1362__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_foreach_indexed_10296_fun1362, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_std_core_list__mlift_foreach_indexed_10296_fun1362(kk_function_t _fself, kk_integer_t _y_x10200, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_foreach_indexed_10296_fun1362__t* _self = kk_function_as(struct kk_std_core_list__mlift_foreach_indexed_10296_fun1362__t*, _fself, _ctx);
  kk_ref_t i = _self->i; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_ref_dup(i, _ctx);}, {}, _ctx)
  kk_integer_t _b_x518_520 = kk_integer_add_small_const(_y_x10200, 1, _ctx); /*int*/;
  kk_unit_t _brw_x1017 = kk_Unit;
  kk_ref_set_borrow(i,(kk_integer_box(_b_x518_520, _ctx)),kk_context());
  kk_ref_drop(i, _ctx);
  _brw_x1017; return kk_Unit;
}


// lift anonymous function
struct kk_std_core_list__mlift_foreach_indexed_10296_fun1364__t {
  struct kk_function_s _base;
  kk_function_t next_10366;
};
static kk_box_t kk_std_core_list__mlift_foreach_indexed_10296_fun1364(kk_function_t _fself, kk_box_t _b_x522, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_foreach_indexed_10296_fun1364(kk_function_t next_10366, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_foreach_indexed_10296_fun1364__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_foreach_indexed_10296_fun1364__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_foreach_indexed_10296_fun1364, kk_context());
  _self->next_10366 = next_10366;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_foreach_indexed_10296_fun1364(kk_function_t _fself, kk_box_t _b_x522, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_foreach_indexed_10296_fun1364__t* _self = kk_function_as(struct kk_std_core_list__mlift_foreach_indexed_10296_fun1364__t*, _fself, _ctx);
  kk_function_t next_10366 = _self->next_10366; /* (int) -> <local<2864>|2871> () */
  kk_drop_match(_self, {kk_function_dup(next_10366, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1365 = kk_Unit;
  kk_integer_t _x_x1366 = kk_integer_unbox(_b_x522, _ctx); /*int*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), next_10366, (next_10366, _x_x1366, _ctx), _ctx);
  return kk_unit_box(_x_x1365);
}

kk_unit_t kk_std_core_list__mlift_foreach_indexed_10296(kk_ref_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 
  kk_integer_t x_10365;
  kk_box_t _x_x1360;
  kk_ref_t _x_x1361 = kk_ref_dup(i, _ctx); /*local-var<2864,int>*/
  _x_x1360 = kk_ref_get(_x_x1361,kk_context()); /*294*/
  x_10365 = kk_integer_unbox(_x_x1360, _ctx); /*int*/
  kk_function_t next_10366 = kk_std_core_list__new_mlift_foreach_indexed_10296_fun1362(i, _ctx); /*(int) -> <local<2864>|2871> ()*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10365, _ctx);
    kk_box_t _x_x1363 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_foreach_indexed_10296_fun1364(next_10366, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x1363); return kk_Unit;
  }
  {
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), next_10366, (next_10366, x_10365, _ctx), _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_foreach_indexed_10297_fun1368__t {
  struct kk_function_s _base;
  kk_ref_t i;
};
static kk_box_t kk_std_core_list__mlift_foreach_indexed_10297_fun1368(kk_function_t _fself, kk_box_t _b_x525, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_foreach_indexed_10297_fun1368(kk_ref_t i, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_foreach_indexed_10297_fun1368__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_foreach_indexed_10297_fun1368__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_foreach_indexed_10297_fun1368, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_foreach_indexed_10297_fun1368(kk_function_t _fself, kk_box_t _b_x525, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_foreach_indexed_10297_fun1368__t* _self = kk_function_as(struct kk_std_core_list__mlift_foreach_indexed_10297_fun1368__t*, _fself, _ctx);
  kk_ref_t i = _self->i; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_ref_dup(i, _ctx);}, {}, _ctx)
  kk_unit_t wild___527 = kk_Unit;
  kk_unit_unbox(_b_x525);
  kk_unit_t _x_x1369 = kk_Unit;
  kk_std_core_list__mlift_foreach_indexed_10296(i, wild___527, _ctx);
  return kk_unit_box(_x_x1369);
}

kk_unit_t kk_std_core_list__mlift_foreach_indexed_10297(kk_function_t action, kk_ref_t i, kk_box_t x, kk_integer_t j, kk_context_t* _ctx) { /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, x : a, j : int) -> <local<h>|e> () */ 
  kk_unit_t x_0_10369 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), action, (action, j, x, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1367 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_foreach_indexed_10297_fun1368(i, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x1367); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_foreach_indexed_10296(i, x_0_10369, _ctx); return kk_Unit;
  }
}
 
// Invoke `action` for each element of a list, passing also the position of the element.


// lift anonymous function
struct kk_std_core_list_foreach_indexed_fun1371__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_ref_t loc;
};
static kk_unit_t kk_std_core_list_foreach_indexed_fun1371(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foreach_indexed_fun1371(kk_function_t action, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_indexed_fun1371__t* _self = kk_function_alloc_as(struct kk_std_core_list_foreach_indexed_fun1371__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foreach_indexed_fun1371, kk_context());
  _self->action = action;
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_list_foreach_indexed_fun1375__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_ref_t loc;
  kk_box_t x;
};
static kk_box_t kk_std_core_list_foreach_indexed_fun1375(kk_function_t _fself, kk_box_t _b_x533, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foreach_indexed_fun1375(kk_function_t action, kk_ref_t loc, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_indexed_fun1375__t* _self = kk_function_alloc_as(struct kk_std_core_list_foreach_indexed_fun1375__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foreach_indexed_fun1375, kk_context());
  _self->action = action;
  _self->loc = loc;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foreach_indexed_fun1375(kk_function_t _fself, kk_box_t _b_x533, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_indexed_fun1375__t* _self = kk_function_as(struct kk_std_core_list_foreach_indexed_fun1375__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* (int, 2870) -> 2871 () */
  kk_ref_t loc = _self->loc; /* local-var<2864,int> */
  kk_box_t x = _self->x; /* 2870 */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);kk_ref_dup(loc, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1376 = kk_Unit;
  kk_integer_t _x_x1377 = kk_integer_unbox(_b_x533, _ctx); /*int*/
  kk_std_core_list__mlift_foreach_indexed_10297(action, loc, x, _x_x1377, _ctx);
  return kk_unit_box(_x_x1376);
}
static kk_unit_t kk_std_core_list_foreach_indexed_fun1371(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_list_foreach_indexed_fun1371__t* _self = kk_function_as(struct kk_std_core_list_foreach_indexed_fun1371__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* (int, 2870) -> 2871 () */
  kk_ref_t loc = _self->loc; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_integer_t x_0_10374;
  kk_box_t _x_x1372;
  kk_ref_t _x_x1373 = kk_ref_dup(loc, _ctx); /*local-var<2864,int>*/
  _x_x1372 = kk_ref_get(_x_x1373,kk_context()); /*294*/
  x_0_10374 = kk_integer_unbox(_x_x1372, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10374, _ctx);
    kk_box_t _x_x1374 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_foreach_indexed_fun1375(action, loc, x, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x1374); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_foreach_indexed_10297(action, loc, x, x_0_10374, _ctx); return kk_Unit;
  }
}

kk_unit_t kk_std_core_list_foreach_indexed(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<2864,int>*/;
  kk_unit_t res = kk_Unit;
  kk_function_t _x_x1370;
  kk_ref_dup(loc, _ctx);
  _x_x1370 = kk_std_core_list_new_foreach_indexed_fun1371(action, loc, _ctx); /*(x : 2870) -> <local<2864>|2871> ()*/
  kk_std_core_list_foreach(xs, _x_x1370, _ctx);
  kk_box_t _x_x1378 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*9564*/
  kk_unit_unbox(_x_x1378); return kk_Unit;
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__trmc_lift_intersperse_4952(kk_box_t sep, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1379 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1379->head;
    kk_std_core_types__list yy = _con_x1379->tail;
    kk_reuse_t _ru_x1084 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1084 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10089;
    kk_std_core_types__list _x_x1380 = kk_datatype_null(); /*list<2937>*/
    _trmc_x10089 = kk_std_core_types__new_Cons(_ru_x1084, 0, y, _x_x1380, _ctx); /*list<2937>*/
    kk_field_addr_t _b_x545_550 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10089, _ctx)->tail, _ctx); /*@field-addr<list<2937>>*/;
    { // tailcall
      kk_box_t _x_x1381 = kk_box_dup(sep, _ctx); /*2937*/
      kk_std_core_types__cctx _x_x1382;
      kk_box_t _x_x1383;
      kk_std_core_types__list _x_x1384 = kk_std_core_types__new_Cons(kk_reuse_null, 0, sep, _trmc_x10089, _ctx); /*list<82>*/
      _x_x1383 = kk_std_core_types__list_box(_x_x1384, _ctx); /*0*/
      _x_x1382 = kk_cctx_extend_linear(_acc,_x_x1383,_b_x545_550,kk_context()); /*ctx<0>*/
      sep = _x_x1381;
      ys = yy;
      _acc = _x_x1382;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(sep, _ctx);
    kk_box_t _x_x1385 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1385, KK_OWNED, _ctx);
  }
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__lift_intersperse_4952(kk_box_t sep_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1386 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_intersperse_4952(sep_0, ys_0, _x_x1386, _ctx);
}
 
// Insert a separator `sep`  between all elements of a list `xs` .

kk_std_core_types__list kk_std_core_list_intersperse(kk_std_core_types__list xs, kk_box_t sep, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1387 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1387->head;
    kk_std_core_types__list xx = _con_x1387->tail;
    kk_reuse_t _ru_x1085 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1085 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _x_x1388 = kk_std_core_list__lift_intersperse_4952(sep, xx, _ctx); /*list<2937>*/
    return kk_std_core_types__new_Cons(_ru_x1085, 0, x, _x_x1388, _ctx);
  }
  {
    kk_box_drop(sep, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1390 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x556 = _con_x1390->head;
    kk_std_core_types__list _pat_1 = _con_x1390->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x556);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1391 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x557 = _con_x1391->head;
    kk_std_core_types__list _pat_3 = _con_x1391->tail;
    struct kk_std_core_types_Cons* _con_x1392 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x558 = _con_x1392->head;
    kk_std_core_types__list _pat_4 = _con_x1392->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x557);
      kk_string_t y = kk_string_unbox(_box_x558);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1393 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<832>*/
    return kk_string_join(_x_x1393,kk_context());
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_joinsep(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1395 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x559 = _con_x1395->head;
    kk_std_core_types__list _pat_1 = _con_x1395->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x559);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_string_drop(sep, _ctx);
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1396 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x560 = _con_x1396->head;
    kk_std_core_types__list _pat_3 = _con_x1396->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1397 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x561 = _con_x1397->head;
      kk_std_core_types__list _pat_4 = _con_x1397->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1398 = kk_string_dup(sep, _ctx); /*string*/
        kk_string_t _x_x1399 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1398,_x_x1399,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x560);
          kk_string_t y = kk_string_unbox(_box_x561);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          kk_string_drop(sep, _ctx);
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1401 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<832>*/
    return kk_string_join_with(_x_x1401,sep,kk_context());
  }
}
 
// monadic lift

kk_string_t kk_std_core_list__mlift_show_10298(kk_std_core_types__list _y_x10205, kk_context_t* _ctx) { /* forall<e> (list<string>) -> e string */ 
  kk_string_t _x_x1402;
  kk_define_string_literal(, _s_x1403, 1, "[", _ctx)
  _x_x1402 = kk_string_dup(_s_x1403, _ctx); /*string*/
  kk_string_t _x_x1404;
  kk_string_t _x_x1405;
  if (kk_std_core_types__is_Nil(_y_x10205, _ctx)) {
    _x_x1405 = kk_string_empty(); /*string*/
    goto _match_x1406;
  }
  {
    struct kk_std_core_types_Cons* _con_x1408 = kk_std_core_types__as_Cons(_y_x10205, _ctx);
    kk_box_t _box_x562 = _con_x1408->head;
    kk_std_core_types__list _pat_1 = _con_x1408->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x562);
      if kk_likely(kk_datatype_ptr_is_unique(_y_x10205, _ctx)) {
        kk_datatype_ptr_free(_y_x10205, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(_y_x10205, _ctx);
      }
      _x_x1405 = x; /*string*/
      goto _match_x1406;
    }
  }
  if (kk_std_core_types__is_Cons(_y_x10205, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1409 = kk_std_core_types__as_Cons(_y_x10205, _ctx);
    kk_box_t _box_x563 = _con_x1409->head;
    kk_std_core_types__list _pat_3 = _con_x1409->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1410 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x564 = _con_x1410->head;
      kk_std_core_types__list _pat_4 = _con_x1410->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1411;
        kk_define_string_literal(, _s_x1412, 1, ",", _ctx)
        _x_x1411 = kk_string_dup(_s_x1412, _ctx); /*string*/
        kk_string_t _x_x1413 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1411,_x_x1413,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x563);
          kk_string_t y = kk_string_unbox(_box_x564);
          if kk_likely(kk_datatype_ptr_is_unique(_y_x10205, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(_y_x10205, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_y_x10205, _ctx);
          }
          _x_x1405 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
          goto _match_x1406;
        }
      }
    }
  }
  {
    kk_vector_t _x_x1415 = kk_std_core_vector_unvlist(_y_x10205, _ctx); /*vector<832>*/
    kk_string_t _x_x1416;
    kk_define_string_literal(, _s_x1417, 1, ",", _ctx)
    _x_x1416 = kk_string_dup(_s_x1417, _ctx); /*string*/
    _x_x1405 = kk_string_join_with(_x_x1415,_x_x1416,kk_context()); /*string*/
  }
  _match_x1406: ;
  kk_string_t _x_x1418;
  kk_define_string_literal(, _s_x1419, 1, "]", _ctx)
  _x_x1418 = kk_string_dup(_s_x1419, _ctx); /*string*/
  _x_x1404 = kk_std_core_types__lp__plus__plus__rp_(_x_x1405, _x_x1418, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1402, _x_x1404, _ctx);
}
 
// Show a list


// lift anonymous function
struct kk_std_core_list_show_fun1420__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_show;
};
static kk_box_t kk_std_core_list_show_fun1420(kk_function_t _fself, kk_box_t _b_x567, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1420(kk_function_t _implicit_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1420__t* _self = kk_function_alloc_as(struct kk_std_core_list_show_fun1420__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_show_fun1420, kk_context());
  _self->_implicit_fs_show = _implicit_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_show_fun1420(kk_function_t _fself, kk_box_t _b_x567, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1420__t* _self = kk_function_as(struct kk_std_core_list_show_fun1420__t*, _fself, _ctx);
  kk_function_t _implicit_fs_show = _self->_implicit_fs_show; /* (3123) -> 3124 string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _x_x1421 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, _b_x567, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1421);
}


// lift anonymous function
struct kk_std_core_list_show_fun1423__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_show_fun1423(kk_function_t _fself, kk_box_t _b_x571, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1423(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_show_fun1423, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_show_fun1423(kk_function_t _fself, kk_box_t _b_x571, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__list _y_x10205_576 = kk_std_core_types__list_unbox(_b_x571, KK_OWNED, _ctx); /*list<string>*/;
  kk_string_t _x_x1424 = kk_std_core_list__mlift_show_10298(_y_x10205_576, _ctx); /*string*/
  return kk_string_box(_x_x1424);
}

kk_string_t kk_std_core_list_show(kk_std_core_types__list xs, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */ 
  kk_std_core_types__list x_10376 = kk_std_core_list_map(xs, kk_std_core_list_new_show_fun1420(_implicit_fs_show, _ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10376, _ctx);
    kk_box_t _x_x1422 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_show_fun1423(_ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x1422);
  }
  {
    kk_string_t _x_x1425;
    kk_define_string_literal(, _s_x1426, 1, "[", _ctx)
    _x_x1425 = kk_string_dup(_s_x1426, _ctx); /*string*/
    kk_string_t _x_x1427;
    kk_string_t _x_x1428;
    if (kk_std_core_types__is_Nil(x_10376, _ctx)) {
      _x_x1428 = kk_string_empty(); /*string*/
      goto _match_x1429;
    }
    {
      struct kk_std_core_types_Cons* _con_x1431 = kk_std_core_types__as_Cons(x_10376, _ctx);
      kk_box_t _box_x572 = _con_x1431->head;
      kk_std_core_types__list _pat_1_0 = _con_x1431->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_0 = kk_string_unbox(_box_x572);
        if kk_likely(kk_datatype_ptr_is_unique(x_10376, _ctx)) {
          kk_datatype_ptr_free(x_10376, _ctx);
        }
        else {
          kk_string_dup(x_0, _ctx);
          kk_datatype_ptr_decref(x_10376, _ctx);
        }
        _x_x1428 = x_0; /*string*/
        goto _match_x1429;
      }
    }
    if (kk_std_core_types__is_Cons(x_10376, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1432 = kk_std_core_types__as_Cons(x_10376, _ctx);
      kk_box_t _box_x573 = _con_x1432->head;
      kk_std_core_types__list _pat_3 = _con_x1432->tail;
      if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1433 = kk_std_core_types__as_Cons(_pat_3, _ctx);
        kk_box_t _box_x574 = _con_x1433->head;
        kk_std_core_types__list _pat_4 = _con_x1433->tail;
        if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
          kk_string_t _x_x1434;
          kk_define_string_literal(, _s_x1435, 1, ",", _ctx)
          _x_x1434 = kk_string_dup(_s_x1435, _ctx); /*string*/
          kk_string_t _x_x1436 = kk_string_empty(); /*string*/
          if (kk_string_is_eq(_x_x1434,_x_x1436,kk_context())) {
            kk_string_t x_0_0 = kk_string_unbox(_box_x573);
            kk_string_t y = kk_string_unbox(_box_x574);
            if kk_likely(kk_datatype_ptr_is_unique(x_10376, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
                kk_datatype_ptr_free(_pat_3, _ctx);
              }
              else {
                kk_string_dup(y, _ctx);
                kk_datatype_ptr_decref(_pat_3, _ctx);
              }
              kk_datatype_ptr_free(x_10376, _ctx);
            }
            else {
              kk_string_dup(x_0_0, _ctx);
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(x_10376, _ctx);
            }
            _x_x1428 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
            goto _match_x1429;
          }
        }
      }
    }
    {
      kk_vector_t _x_x1438 = kk_std_core_vector_unvlist(x_10376, _ctx); /*vector<832>*/
      kk_string_t _x_x1439;
      kk_define_string_literal(, _s_x1440, 1, ",", _ctx)
      _x_x1439 = kk_string_dup(_s_x1440, _ctx); /*string*/
      _x_x1428 = kk_string_join_with(_x_x1438,_x_x1439,kk_context()); /*string*/
    }
    _match_x1429: ;
    kk_string_t _x_x1441;
    kk_define_string_literal(, _s_x1442, 1, "]", _ctx)
    _x_x1441 = kk_string_dup(_s_x1442, _ctx); /*string*/
    _x_x1427 = kk_std_core_types__lp__plus__plus__rp_(_x_x1428, _x_x1441, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1425, _x_x1427, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__trmc_zip(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1443 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1443->head;
    kk_std_core_types__list xx = _con_x1443->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1444 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1444->head;
      kk_std_core_types__list yy = _con_x1444->tail;
      kk_reuse_t _ru_x1099 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1099 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__list _trmc_x10091 = kk_datatype_null(); /*list<(3222, 3223)>*/;
      kk_std_core_types__list _trmc_x10092;
      kk_box_t _x_x1445;
      kk_std_core_types__tuple2 _x_x1446 = kk_std_core_types__new_Tuple2(x, y, _ctx); /*(129, 130)*/
      _x_x1445 = kk_std_core_types__tuple2_box(_x_x1446, _ctx); /*82*/
      _trmc_x10092 = kk_std_core_types__new_Cons(_ru_x1099, 0, _x_x1445, _trmc_x10091, _ctx); /*list<(3222, 3223)>*/
      kk_field_addr_t _b_x586_593 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10092, _ctx)->tail, _ctx); /*@field-addr<list<(3222, 3223)>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1447 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10092, _ctx)),_b_x586_593,kk_context()); /*ctx<0>*/
        xs = xx;
        ys = yy;
        _acc = _x_x1447;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      kk_box_t _x_x1448 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1448, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_box_t _x_x1449 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1449, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list_zip(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
  kk_std_core_types__cctx _x_x1450 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_zip(xs_0, ys_0, _x_x1450, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_zipwith_10299(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10093, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core_types__list _trmc_x10094 = kk_datatype_null(); /*list<3290>*/;
  kk_std_core_types__list _trmc_x10095 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10093, _trmc_x10094, _ctx); /*list<3290>*/;
  kk_field_addr_t _b_x606_609 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10095, _ctx)->tail, _ctx); /*@field-addr<list<3290>>*/;
  kk_std_core_types__cctx _x_x1451 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10095, _ctx)),_b_x606_609,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_zipwith(xx, yy, f, _x_x1451, _ctx);
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core_list__trmc_zipwith_fun1456__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_zipwith_fun1456(kk_function_t _fself, kk_box_t _b_x614, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_zipwith_fun1456(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_zipwith_fun1456__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_zipwith_fun1456__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_zipwith_fun1456, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_zipwith_fun1456(kk_function_t _fself, kk_box_t _b_x614, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_zipwith_fun1456__t* _self = kk_function_as(struct kk_std_core_list__trmc_zipwith_fun1456__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3290>> */
  kk_function_t f_0 = _self->f_0; /* (3288, 3289) -> 3291 3290 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3288> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3289> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10093_0_636 = _b_x614; /*3290*/;
  kk_std_core_types__list _x_x1457 = kk_std_core_list__mlift_trmc_zipwith_10299(_acc_0, f_0, xx_0, yy_0, _trmc_x10093_0_636, _ctx); /*list<3290>*/
  return kk_std_core_types__list_box(_x_x1457, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_zipwith(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1452 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1452->head;
    kk_std_core_types__list xx_0 = _con_x1452->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1453 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1453->head;
      kk_std_core_types__list yy_0 = _con_x1453->tail;
      kk_reuse_t _ru_x1101 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1101 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_box_t x_0_10379;
      kk_function_t _x_x1454 = kk_function_dup(f_0, _ctx); /*(3288, 3289) -> 3291 3290*/
      x_0_10379 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1454, (_x_x1454, x, y, _ctx), _ctx); /*3290*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1101,kk_context());
        kk_box_drop(x_0_10379, _ctx);
        kk_box_t _x_x1455 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_zipwith_fun1456(_acc_0, f_0, xx_0, yy_0, _ctx), _ctx); /*2978*/
        return kk_std_core_types__list_unbox(_x_x1455, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10094_0 = kk_datatype_null(); /*list<3290>*/;
        kk_std_core_types__list _trmc_x10095_0 = kk_std_core_types__new_Cons(_ru_x1101, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10379, _trmc_x10094_0, _ctx); /*list<3290>*/;
        kk_field_addr_t _b_x620_628 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10095_0, _ctx)->tail, _ctx); /*@field-addr<list<3290>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x1458 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10095_0, _ctx)),_b_x620_628,kk_context()); /*ctx<0>*/
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _x_x1458;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(f_0, _ctx);
      kk_box_t _x_x1459 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1459, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1460 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1460, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list_zipwith(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  kk_std_core_types__cctx _x_x1461 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_zipwith(xs_0, ys_0, f_1, _x_x1461, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_zipwith_indexed_4953_10300(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10029, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10096, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctx<list<c>>, f : (int, a, b) -> e c, i@0@10029 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core_types__list _trmc_x10097 = kk_datatype_null(); /*list<3373>*/;
  kk_std_core_types__list _trmc_x10098 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10096, _trmc_x10097, _ctx); /*list<3373>*/;
  kk_field_addr_t _b_x642_645 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10098, _ctx)->tail, _ctx); /*@field-addr<list<3373>>*/;
  kk_std_core_types__cctx _x_x1462 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10098, _ctx)),_b_x642_645,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_zipwith_indexed_4953(f, i_0_10029, xx, yy, _x_x1462, _ctx);
}
 
// lifted local: zipwith-indexed, zipwith-iter


// lift anonymous function
struct kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10029_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468(kk_function_t _fself, kk_box_t _b_x650, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_zipwith_indexed_4953_fun1468(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10029_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10029_0 = i_0_10029_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468(kk_function_t _fself, kk_box_t _b_x650, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_zipwith_indexed_4953_fun1468__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3373>> */
  kk_function_t f_0 = _self->f_0; /* (int, 3371, 3372) -> 3374 3373 */
  kk_integer_t i_0_10029_0 = _self->i_0_10029_0; /* int */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3371> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3372> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10029_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10096_0_672 = _b_x650; /*3373*/;
  kk_std_core_types__list _x_x1469 = kk_std_core_list__mlift_trmc_lift_zipwith_indexed_4953_10300(_acc_0, f_0, i_0_10029_0, xx_0, yy_0, _trmc_x10096_0_672, _ctx); /*list<3373>*/
  return kk_std_core_types__list_box(_x_x1469, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_zipwith_indexed_4953(kk_function_t f_0, kk_integer_t i, kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1463 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1463->head;
    kk_std_core_types__list xx_0 = _con_x1463->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1464 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1464->head;
      kk_std_core_types__list yy_0 = _con_x1464->tail;
      kk_reuse_t _ru_x1103 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1103 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_integer_t i_0_10029_0;
      kk_integer_t _x_x1465 = kk_integer_dup(i, _ctx); /*int*/
      i_0_10029_0 = kk_integer_add_small_const(_x_x1465, 1, _ctx); /*int*/
      kk_box_t x_0_10382;
      kk_function_t _x_x1466 = kk_function_dup(f_0, _ctx); /*(int, 3371, 3372) -> 3374 3373*/
      x_0_10382 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1466, (_x_x1466, i, x, y, _ctx), _ctx); /*3373*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1103,kk_context());
        kk_box_drop(x_0_10382, _ctx);
        kk_box_t _x_x1467 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_zipwith_indexed_4953_fun1468(_acc_0, f_0, i_0_10029_0, xx_0, yy_0, _ctx), _ctx); /*2978*/
        return kk_std_core_types__list_unbox(_x_x1467, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10097_0 = kk_datatype_null(); /*list<3373>*/;
        kk_std_core_types__list _trmc_x10098_0 = kk_std_core_types__new_Cons(_ru_x1103, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10382, _trmc_x10097_0, _ctx); /*list<3373>*/;
        kk_field_addr_t _b_x656_664 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10098_0, _ctx)->tail, _ctx); /*@field-addr<list<3373>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x1470 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10098_0, _ctx)),_b_x656_664,kk_context()); /*ctx<0>*/
          i = i_0_10029_0;
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _x_x1470;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_integer_drop(i, _ctx);
      kk_function_drop(f_0, _ctx);
      kk_box_t _x_x1471 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1471, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1472 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1472, KK_OWNED, _ctx);
  }
}
 
// lifted local: zipwith-indexed, zipwith-iter

kk_std_core_types__list kk_std_core_list__lift_zipwith_indexed_4953(kk_function_t f_1, kk_integer_t i_0, kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
  kk_std_core_types__cctx _x_x1473 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_zipwith_indexed_4953(f_1, i_0, xs_0, ys_0, _x_x1473, _ctx);
}
 
// lifted local: unzip, iter
// todo: implement TRMC for multiple results

kk_std_core_types__tuple2 kk_std_core_list__lift_unzip_4954(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx) { /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1474 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x673 = _con_x1474->head;
    kk_std_core_types__tuple2 _pat_0 = kk_std_core_types__tuple2_unbox(_box_x673, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1474->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_reuse_t _ru_x1104 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_drop(_box_x673, _ctx);
      _ru_x1104 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3433;
    kk_std_core_types__list _x_x1475 = kk_datatype_null(); /*list<3402>*/
    _cctx_x3433 = kk_std_core_types__new_Cons(_ru_x1104, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1475, _ctx); /*list<3402>*/
    kk_field_addr_t _cctx_x3434 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3433, _ctx)->tail, _ctx); /*@field-addr<list<3402>>*/;
    kk_std_core_types__list _cctx_x3473;
    kk_std_core_types__list _x_x1476 = kk_datatype_null(); /*list<3403>*/
    _cctx_x3473 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1476, _ctx); /*list<3403>*/
    kk_field_addr_t _cctx_x3474 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3473, _ctx)->tail, _ctx); /*@field-addr<list<3403>>*/;
    kk_std_core_types__list _b_x686_694 = _cctx_x3433; /*list<3402>*/;
    kk_field_addr_t _b_x687_695 = _cctx_x3434; /*@field-addr<list<3402>>*/;
    kk_std_core_types__list _b_x688_696 = _cctx_x3473; /*list<3403>*/;
    kk_field_addr_t _b_x689_697 = _cctx_x3474; /*@field-addr<list<3403>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1477;
      kk_std_core_types__cctx _x_x1478 = kk_cctx_create((kk_std_core_types__list_box(_b_x686_694, _ctx)),_b_x687_695,kk_context()); /*cctx<0,1>*/
      _x_x1477 = kk_cctx_compose(acc1,_x_x1478,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1479;
      kk_std_core_types__cctx _x_x1480 = kk_cctx_create((kk_std_core_types__list_box(_b_x688_696, _ctx)),_b_x689_697,kk_context()); /*cctx<0,1>*/
      _x_x1479 = kk_cctx_compose(acc2,_x_x1480,kk_context()); /*cctx<371,373>*/
      ys = xx;
      acc1 = _x_x1477;
      acc2 = _x_x1479;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1481 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1482 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple2(_x_x1481, _x_x1482, _ctx);
  }
}
 
// lifted local: unzip3, iter
// todo: implement TRMC for multiple results

kk_std_core_types__tuple3 kk_std_core_list__lift_unzip3_4955(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1485 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x702 = _con_x1485->head;
    kk_std_core_types__tuple3 _pat_0 = kk_std_core_types__tuple3_unbox(_box_x702, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1485->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_box_t z = _pat_0.thd;
    kk_reuse_t _ru_x1105 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_box_drop(_box_x702, _ctx);
      _ru_x1105 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3624;
    kk_std_core_types__list _x_x1486 = kk_datatype_null(); /*list<3592>*/
    _cctx_x3624 = kk_std_core_types__new_Cons(_ru_x1105, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1486, _ctx); /*list<3592>*/
    kk_field_addr_t _cctx_x3625 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3624, _ctx)->tail, _ctx); /*@field-addr<list<3592>>*/;
    kk_std_core_types__list _cctx_x3664;
    kk_std_core_types__list _x_x1487 = kk_datatype_null(); /*list<3593>*/
    _cctx_x3664 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1487, _ctx); /*list<3593>*/
    kk_field_addr_t _cctx_x3665 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3664, _ctx)->tail, _ctx); /*@field-addr<list<3593>>*/;
    kk_std_core_types__list _cctx_x3704;
    kk_std_core_types__list _x_x1488 = kk_datatype_null(); /*list<3594>*/
    _cctx_x3704 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1488, _ctx); /*list<3594>*/
    kk_field_addr_t _cctx_x3705 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3704, _ctx)->tail, _ctx); /*@field-addr<list<3594>>*/;
    kk_std_core_types__list _b_x721_733 = _cctx_x3624; /*list<3592>*/;
    kk_field_addr_t _b_x722_734 = _cctx_x3625; /*@field-addr<list<3592>>*/;
    kk_std_core_types__list _b_x723_735 = _cctx_x3664; /*list<3593>*/;
    kk_field_addr_t _b_x724_736 = _cctx_x3665; /*@field-addr<list<3593>>*/;
    kk_std_core_types__list _b_x725_737 = _cctx_x3704; /*list<3594>*/;
    kk_field_addr_t _b_x726_738 = _cctx_x3705; /*@field-addr<list<3594>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1489;
      kk_std_core_types__cctx _x_x1490 = kk_cctx_create((kk_std_core_types__list_box(_b_x721_733, _ctx)),_b_x722_734,kk_context()); /*cctx<0,1>*/
      _x_x1489 = kk_cctx_compose(acc1,_x_x1490,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1491;
      kk_std_core_types__cctx _x_x1492 = kk_cctx_create((kk_std_core_types__list_box(_b_x723_735, _ctx)),_b_x724_736,kk_context()); /*cctx<0,1>*/
      _x_x1491 = kk_cctx_compose(acc2,_x_x1492,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1493;
      kk_std_core_types__cctx _x_x1494 = kk_cctx_create((kk_std_core_types__list_box(_b_x725_737, _ctx)),_b_x726_738,kk_context()); /*cctx<0,1>*/
      _x_x1493 = kk_cctx_compose(acc3,_x_x1494,kk_context()); /*cctx<371,373>*/
      ys = xx;
      acc1 = _x_x1489;
      acc2 = _x_x1491;
      acc3 = _x_x1493;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1495 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1496 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1497 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple3(_x_x1495, _x_x1496, _x_x1497, _ctx);
  }
}
 
// lifted local: unzip4, iter
// todo: implement TRMC for multiple results

kk_std_core_types__tuple4 kk_std_core_list__lift_unzip4_4956(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_std_core_types__cctx acc4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1501 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x745 = _con_x1501->head;
    kk_std_core_types__tuple4 _pat_0 = kk_std_core_types__tuple4_unbox(_box_x745, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x1502 = kk_std_core_types__as_Tuple4(_pat_0, _ctx);
    kk_std_core_types__list xx = _con_x1501->tail;
    kk_box_t x = _con_x1502->fst;
    kk_box_t y = _con_x1502->snd;
    kk_box_t z = _con_x1502->thd;
    kk_box_t w = _con_x1502->field4;
    kk_reuse_t _ru_x1106 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(w, _ctx);
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_box_drop(_box_x745, _ctx);
      _ru_x1106 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(w, _ctx);
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3895;
    kk_std_core_types__list _x_x1503 = kk_datatype_null(); /*list<3862>*/
    _cctx_x3895 = kk_std_core_types__new_Cons(_ru_x1106, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1503, _ctx); /*list<3862>*/
    kk_field_addr_t _cctx_x3896 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3895, _ctx)->tail, _ctx); /*@field-addr<list<3862>>*/;
    kk_std_core_types__list _cctx_x3935;
    kk_std_core_types__list _x_x1504 = kk_datatype_null(); /*list<3863>*/
    _cctx_x3935 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1504, _ctx); /*list<3863>*/
    kk_field_addr_t _cctx_x3936 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3935, _ctx)->tail, _ctx); /*@field-addr<list<3863>>*/;
    kk_std_core_types__list _cctx_x3975;
    kk_std_core_types__list _x_x1505 = kk_datatype_null(); /*list<3864>*/
    _cctx_x3975 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1505, _ctx); /*list<3864>*/
    kk_field_addr_t _cctx_x3976 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3975, _ctx)->tail, _ctx); /*@field-addr<list<3864>>*/;
    kk_std_core_types__list _cctx_x4015;
    kk_std_core_types__list _x_x1506 = kk_datatype_null(); /*list<3865>*/
    _cctx_x4015 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), w, _x_x1506, _ctx); /*list<3865>*/
    kk_field_addr_t _cctx_x4016 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4015, _ctx)->tail, _ctx); /*@field-addr<list<3865>>*/;
    kk_std_core_types__list _b_x770_786 = _cctx_x3895; /*list<3862>*/;
    kk_field_addr_t _b_x771_787 = _cctx_x3896; /*@field-addr<list<3862>>*/;
    kk_std_core_types__list _b_x772_788 = _cctx_x3935; /*list<3863>*/;
    kk_field_addr_t _b_x773_789 = _cctx_x3936; /*@field-addr<list<3863>>*/;
    kk_std_core_types__list _b_x774_790 = _cctx_x3975; /*list<3864>*/;
    kk_field_addr_t _b_x775_791 = _cctx_x3976; /*@field-addr<list<3864>>*/;
    kk_std_core_types__list _b_x776_792 = _cctx_x4015; /*list<3865>*/;
    kk_field_addr_t _b_x777_793 = _cctx_x4016; /*@field-addr<list<3865>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1507;
      kk_std_core_types__cctx _x_x1508 = kk_cctx_create((kk_std_core_types__list_box(_b_x770_786, _ctx)),_b_x771_787,kk_context()); /*cctx<0,1>*/
      _x_x1507 = kk_cctx_compose(acc1,_x_x1508,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1509;
      kk_std_core_types__cctx _x_x1510 = kk_cctx_create((kk_std_core_types__list_box(_b_x772_788, _ctx)),_b_x773_789,kk_context()); /*cctx<0,1>*/
      _x_x1509 = kk_cctx_compose(acc2,_x_x1510,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1511;
      kk_std_core_types__cctx _x_x1512 = kk_cctx_create((kk_std_core_types__list_box(_b_x774_790, _ctx)),_b_x775_791,kk_context()); /*cctx<0,1>*/
      _x_x1511 = kk_cctx_compose(acc3,_x_x1512,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1513;
      kk_std_core_types__cctx _x_x1514 = kk_cctx_create((kk_std_core_types__list_box(_b_x776_792, _ctx)),_b_x777_793,kk_context()); /*cctx<0,1>*/
      _x_x1513 = kk_cctx_compose(acc4,_x_x1514,kk_context()); /*cctx<371,373>*/
      ys = xx;
      acc1 = _x_x1507;
      acc2 = _x_x1509;
      acc3 = _x_x1511;
      acc4 = _x_x1513;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1515 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1516 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1517 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1518 = kk_cctx_apply(acc4,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1515, _x_x1516, _x_x1517, _x_x1518, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_lift_span_4957_10301(kk_std_core_types__list acc, kk_function_t predicate, kk_box_t y, kk_std_core_types__list ys, kk_std_core_types__list yy, bool _y_x10218, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_x10218) {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_std_core_types__list _x_x1523 = kk_std_core_types__new_Cons(kk_reuse_null, 0, y, acc, _ctx); /*list<82>*/
    return kk_std_core_list__lift_span_4957(predicate, yy, _x_x1523, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_box_drop(y, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_std_core_types__list _b_x802_804 = kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__new_Nil(_ctx), acc, _ctx); /*list<4264>*/;
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x802_804, _ctx), kk_std_core_types__list_box(ys, _ctx), _ctx);
  }
}
 
// lifted local: span, span-acc
// todo: implement TRMC with multiple results to avoid the reverse


// lift anonymous function
struct kk_std_core_list__lift_span_4957_fun1528__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_0;
  kk_function_t predicate_0;
  kk_box_t y_0;
  kk_std_core_types__list ys_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__lift_span_4957_fun1528(kk_function_t _fself, kk_box_t _b_x807, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_span_4957_fun1528(kk_std_core_types__list acc_0, kk_function_t predicate_0, kk_box_t y_0, kk_std_core_types__list ys_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_span_4957_fun1528__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_span_4957_fun1528__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_span_4957_fun1528, kk_context());
  _self->acc_0 = acc_0;
  _self->predicate_0 = predicate_0;
  _self->y_0 = y_0;
  _self->ys_0 = ys_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_span_4957_fun1528(kk_function_t _fself, kk_box_t _b_x807, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_span_4957_fun1528__t* _self = kk_function_as(struct kk_std_core_list__lift_span_4957_fun1528__t*, _fself, _ctx);
  kk_std_core_types__list acc_0 = _self->acc_0; /* list<4264> */
  kk_function_t predicate_0 = _self->predicate_0; /* (4264) -> 4265 bool */
  kk_box_t y_0 = _self->y_0; /* 4264 */
  kk_std_core_types__list ys_0 = _self->ys_0; /* list<4264> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<4264> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(y_0, _ctx);kk_std_core_types__list_dup(ys_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  bool _y_x10218_0_817 = kk_bool_unbox(_b_x807); /*bool*/;
  kk_std_core_types__tuple2 _x_x1529 = kk_std_core_list__mlift_lift_span_4957_10301(acc_0, predicate_0, y_0, ys_0, yy_0, _y_x10218_0_817, _ctx); /*(list<4264>, list<4264>)*/
  return kk_std_core_types__tuple2_box(_x_x1529, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__lift_span_4957(kk_function_t predicate_0, kk_std_core_types__list ys_0, kk_std_core_types__list acc_0, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1524 = kk_std_core_types__as_Cons(ys_0, _ctx);
    kk_box_t y_0 = _con_x1524->head;
    kk_std_core_types__list yy_0 = _con_x1524->tail;
    kk_box_dup(y_0, _ctx);
    kk_std_core_types__list_dup(yy_0, _ctx);
    bool x_10385;
    kk_function_t _x_x1526 = kk_function_dup(predicate_0, _ctx); /*(4264) -> 4265 bool*/
    kk_box_t _x_x1525 = kk_box_dup(y_0, _ctx); /*4264*/
    x_10385 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1526, (_x_x1526, _x_x1525, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1527 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_span_4957_fun1528(acc_0, predicate_0, y_0, ys_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__tuple2_unbox(_x_x1527, KK_OWNED, _ctx);
    }
    if (x_10385) {
      kk_reuse_t _ru_x1107 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys_0, _ctx)) {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_box_drop(y_0, _ctx);
        _ru_x1107 = (kk_datatype_ptr_reuse(ys_0, _ctx));
      }
      else {
        kk_datatype_ptr_decref(ys_0, _ctx);
      }
      { // tailcall
        kk_std_core_types__list _x_x1530 = kk_std_core_types__new_Cons(_ru_x1107, 0, y_0, acc_0, _ctx); /*list<82>*/
        ys_0 = yy_0;
        acc_0 = _x_x1530;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(yy_0, _ctx);
      kk_box_drop(y_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_std_core_types__list _b_x808_813 = kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<4264>*/;
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x808_813, _ctx), kk_std_core_types__list_box(ys_0, _ctx), _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_std_core_types__list _b_x810_815 = kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<4264>*/;
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x810_815, _ctx), kk_std_core_types__list_box(ys_0, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_take_while_10302(kk_std_core_types__cctx _acc, kk_function_t predicate, kk_box_t x, kk_std_core_types__list xx, bool _y_x10223, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10223) {
    kk_std_core_types__list _trmc_x10099 = kk_datatype_null(); /*list<4313>*/;
    kk_std_core_types__list _trmc_x10100 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10099, _ctx); /*list<4313>*/;
    kk_field_addr_t _b_x823_828 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10100, _ctx)->tail, _ctx); /*@field-addr<list<4313>>*/;
    kk_std_core_types__cctx _x_x1531 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10100, _ctx)),_b_x823_828,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_take_while(xx, predicate, _x_x1531, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_box_drop(x, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_box_t _x_x1532 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1532, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__trmc_take_while_fun1537__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t predicate_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_take_while_fun1537(kk_function_t _fself, kk_box_t _b_x835, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_take_while_fun1537(kk_std_core_types__cctx _acc_0, kk_function_t predicate_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_take_while_fun1537__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_take_while_fun1537__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_take_while_fun1537, kk_context());
  _self->_acc_0 = _acc_0;
  _self->predicate_0 = predicate_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_take_while_fun1537(kk_function_t _fself, kk_box_t _b_x835, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_take_while_fun1537__t* _self = kk_function_as(struct kk_std_core_list__trmc_take_while_fun1537__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4313>> */
  kk_function_t predicate_0 = _self->predicate_0; /* (4313) -> 4314 bool */
  kk_box_t x_0 = _self->x_0; /* 4313 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4313> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10223_0_857 = kk_bool_unbox(_b_x835); /*bool*/;
  kk_std_core_types__list _x_x1538 = kk_std_core_list__mlift_trmc_take_while_10302(_acc_0, predicate_0, x_0, xx_0, _y_x10223_0_857, _ctx); /*list<4313>*/
  return kk_std_core_types__list_box(_x_x1538, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_take_while(kk_std_core_types__list xs, kk_function_t predicate_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1533 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1533->head;
    kk_std_core_types__list xx_0 = _con_x1533->tail;
    kk_reuse_t _ru_x1108 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1108 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10388;
    kk_function_t _x_x1535 = kk_function_dup(predicate_0, _ctx); /*(4313) -> 4314 bool*/
    kk_box_t _x_x1534 = kk_box_dup(x_0, _ctx); /*4313*/
    x_1_10388 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1535, (_x_x1535, _x_x1534, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1108,kk_context());
      kk_box_t _x_x1536 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_take_while_fun1537(_acc_0, predicate_0, x_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1536, KK_OWNED, _ctx);
    }
    if (x_1_10388) {
      kk_std_core_types__list _trmc_x10099_0 = kk_datatype_null(); /*list<4313>*/;
      kk_std_core_types__list _trmc_x10100_0 = kk_std_core_types__new_Cons(_ru_x1108, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10099_0, _ctx); /*list<4313>*/;
      kk_field_addr_t _b_x841_849 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10100_0, _ctx)->tail, _ctx); /*@field-addr<list<4313>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1539 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10100_0, _ctx)),_b_x841_849,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1539;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1108,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_box_t _x_x1540 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1540, KK_OWNED, _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_box_t _x_x1541 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1541, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`

kk_std_core_types__list kk_std_core_list_take_while(kk_std_core_types__list xs_0, kk_function_t predicate_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1542 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_take_while(xs_0, predicate_1, _x_x1542, _ctx);
}
 
// Concatenate all strings in a list in reverse order

kk_string_t kk_std_core_list_reverse_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  kk_std_core_types__list xs_0_10038 = kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Nil(xs_0_10038, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1544 = kk_std_core_types__as_Cons(xs_0_10038, _ctx);
    kk_box_t _box_x858 = _con_x1544->head;
    kk_std_core_types__list _pat_1 = _con_x1544->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x858);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10038, _ctx)) {
        kk_datatype_ptr_free(xs_0_10038, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_0_10038, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1545 = kk_std_core_types__as_Cons(xs_0_10038, _ctx);
    kk_box_t _box_x859 = _con_x1545->head;
    kk_std_core_types__list _pat_3 = _con_x1545->tail;
    struct kk_std_core_types_Cons* _con_x1546 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x860 = _con_x1546->head;
    kk_std_core_types__list _pat_4 = _con_x1546->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x859);
      kk_string_t y = kk_string_unbox(_box_x860);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10038, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_0_10038, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_0_10038, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1547 = kk_std_core_vector_unvlist(xs_0_10038, _ctx); /*vector<832>*/
    return kk_string_join(_x_x1547,kk_context());
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__trmc_lift_concat_4958(kk_std_core_types__list ys, kk_std_core_types__list zss, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1551 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1551->head;
    kk_std_core_types__list yy = _con_x1551->tail;
    kk_reuse_t _ru_x1112 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1112 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10101 = kk_datatype_null(); /*list<4411>*/;
    kk_std_core_types__list _trmc_x10102 = kk_std_core_types__new_Cons(_ru_x1112, 0, y, _trmc_x10101, _ctx); /*list<4411>*/;
    kk_field_addr_t _b_x866_872 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10102, _ctx)->tail, _ctx); /*@field-addr<list<4411>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1552 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10102, _ctx)),_b_x866_872,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc = _x_x1552;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zss, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1553 = kk_std_core_types__as_Cons(zss, _ctx);
    kk_box_t _box_x867 = _con_x1553->head;
    kk_std_core_types__list zzs = _con_x1553->tail;
    kk_std_core_types__list zs = kk_std_core_types__list_unbox(_box_x867, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(zss, _ctx)) {
      kk_datatype_ptr_free(zss, _ctx);
    }
    else {
      kk_std_core_types__list_dup(zs, _ctx);
      kk_std_core_types__list_dup(zzs, _ctx);
      kk_datatype_ptr_decref(zss, _ctx);
    }
    { // tailcall
      ys = zs;
      zss = zzs;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1554 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1554, KK_OWNED, _ctx);
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__lift_concat_4958(kk_std_core_types__list ys_0, kk_std_core_types__list zss_0, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1555 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_concat_4958(ys_0, zss_0, _x_x1555, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_flatmap_4959_10303(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list zz, kk_std_core_types__list ys_1_10045, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10045 : list<b>) -> e list<b> */ 
  return kk_std_core_list__trmc_lift_flatmap_4959(f, ys_1_10045, zz, _acc, _ctx);
}
 
// lifted local: flatmap, flatmap-pre


// lift anonymous function
struct kk_std_core_list__trmc_lift_flatmap_4959_fun1561__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list zz_0;
};
static kk_box_t kk_std_core_list__trmc_lift_flatmap_4959_fun1561(kk_function_t _fself, kk_box_t _b_x885, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_flatmap_4959_fun1561(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list zz_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_4959_fun1561__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_flatmap_4959_fun1561__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_flatmap_4959_fun1561, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->zz_0 = zz_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_flatmap_4959_fun1561(kk_function_t _fself, kk_box_t _b_x885, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_4959_fun1561__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_flatmap_4959_fun1561__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4487>> */
  kk_function_t f_0 = _self->f_0; /* (4486) -> 4488 list<4487> */
  kk_std_core_types__list zz_0 = _self->zz_0; /* list<4486> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(zz_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list ys_1_10045_0_897 = kk_std_core_types__list_unbox(_b_x885, KK_OWNED, _ctx); /*list<4487>*/;
  kk_std_core_types__list _x_x1562 = kk_std_core_list__mlift_trmc_lift_flatmap_4959_10303(_acc_0, f_0, zz_0, ys_1_10045_0_897, _ctx); /*list<4487>*/
  return kk_std_core_types__list_box(_x_x1562, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_flatmap_4959(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__list zs, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1556 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1556->head;
    kk_std_core_types__list yy = _con_x1556->tail;
    kk_reuse_t _ru_x1114 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1114 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10103 = kk_datatype_null(); /*list<4487>*/;
    kk_std_core_types__list _trmc_x10104 = kk_std_core_types__new_Cons(_ru_x1114, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10103, _ctx); /*list<4487>*/;
    kk_field_addr_t _b_x883_890 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10104, _ctx)->tail, _ctx); /*@field-addr<list<4487>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1557 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10104, _ctx)),_b_x883_890,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc_0 = _x_x1557;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1558 = kk_std_core_types__as_Cons(zs, _ctx);
    kk_box_t z = _con_x1558->head;
    kk_std_core_types__list zz_0 = _con_x1558->tail;
    if kk_likely(kk_datatype_ptr_is_unique(zs, _ctx)) {
      kk_datatype_ptr_free(zs, _ctx);
    }
    else {
      kk_box_dup(z, _ctx);
      kk_std_core_types__list_dup(zz_0, _ctx);
      kk_datatype_ptr_decref(zs, _ctx);
    }
    kk_std_core_types__list x_10391;
    kk_function_t _x_x1559 = kk_function_dup(f_0, _ctx); /*(4486) -> 4488 list<4487>*/
    x_10391 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_box_t, kk_context_t*), _x_x1559, (_x_x1559, z, _ctx), _ctx); /*list<4487>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_10391, _ctx);
      kk_box_t _x_x1560 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_flatmap_4959_fun1561(_acc_0, f_0, zz_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1560, KK_OWNED, _ctx);
    }
    { // tailcall
      ys = x_10391;
      zs = zz_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1563 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1563, KK_OWNED, _ctx);
  }
}
 
// lifted local: flatmap, flatmap-pre

kk_std_core_types__list kk_std_core_list__lift_flatmap_4959(kk_function_t f_1, kk_std_core_types__list ys_0, kk_std_core_types__list zs_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1564 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_flatmap_4959(f_1, ys_0, zs_0, _x_x1564, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_flatmap_maybe_10304(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10235, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10235, _ctx)) {
    kk_box_t y = _y_x10235._cons.Just.value;
    kk_std_core_types__list _trmc_x10105 = kk_datatype_null(); /*list<4558>*/;
    kk_std_core_types__list _trmc_x10106 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10105, _ctx); /*list<4558>*/;
    kk_field_addr_t _b_x903_906 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10106, _ctx)->tail, _ctx); /*@field-addr<list<4558>>*/;
    kk_std_core_types__cctx _x_x1565 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10106, _ctx)),_b_x903_906,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_flatmap_maybe(xx, f, _x_x1565, _ctx);
  }
  {
    return kk_std_core_list__trmc_flatmap_maybe(xx, f, _acc, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core_list__trmc_flatmap_maybe_fun1569__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_flatmap_maybe_fun1569(kk_function_t _fself, kk_box_t _b_x911, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_flatmap_maybe_fun1569(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_flatmap_maybe_fun1569__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_flatmap_maybe_fun1569__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_flatmap_maybe_fun1569, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_flatmap_maybe_fun1569(kk_function_t _fself, kk_box_t _b_x911, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_flatmap_maybe_fun1569__t* _self = kk_function_as(struct kk_std_core_list__trmc_flatmap_maybe_fun1569__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4558>> */
  kk_function_t f_0 = _self->f_0; /* (4557) -> 4559 maybe<4558> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4557> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10235_0_929 = kk_std_core_types__maybe_unbox(_b_x911, KK_OWNED, _ctx); /*maybe<4558>*/;
  kk_std_core_types__list _x_x1570 = kk_std_core_list__mlift_trmc_flatmap_maybe_10304(_acc_0, f_0, xx_0, _y_x10235_0_929, _ctx); /*list<4558>*/
  return kk_std_core_types__list_box(_x_x1570, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_flatmap_maybe(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1566 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1566->head;
    kk_std_core_types__list xx_0 = _con_x1566->tail;
    kk_reuse_t _ru_x1116 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1116 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10394;
    kk_function_t _x_x1567 = kk_function_dup(f_0, _ctx); /*(4557) -> 4559 maybe<4558>*/
    x_0_10394 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1567, (_x_x1567, x, _ctx), _ctx); /*maybe<4558>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1116,kk_context());
      kk_std_core_types__maybe_drop(x_0_10394, _ctx);
      kk_box_t _x_x1568 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_flatmap_maybe_fun1569(_acc_0, f_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1568, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10394, _ctx)) {
      kk_box_t y_0 = x_0_10394._cons.Just.value;
      kk_std_core_types__list _trmc_x10105_0 = kk_datatype_null(); /*list<4558>*/;
      kk_std_core_types__list _trmc_x10106_0 = kk_std_core_types__new_Cons(_ru_x1116, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10105_0, _ctx); /*list<4558>*/;
      kk_field_addr_t _b_x917_923 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10106_0, _ctx)->tail, _ctx); /*@field-addr<list<4558>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1571 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10106_0, _ctx)),_b_x917_923,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1571;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1116,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1572 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1572, KK_OWNED, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.

kk_std_core_types__list kk_std_core_list_flatmap_maybe(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1573 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_flatmap_maybe(xs_0, f_1, _x_x1573, _ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__trmc_concat_maybe(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1574 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x930 = _con_x1574->head;
    kk_std_core_types__list xx = _con_x1574->tail;
    kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x930, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1117 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_box_drop(_box_x930, _ctx);
      _ru_x1117 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Just(x, _ctx)) {
      kk_box_t y = x._cons.Just.value;
      kk_std_core_types__list _trmc_x10107 = kk_datatype_null(); /*list<4612>*/;
      kk_std_core_types__list _trmc_x10108 = kk_std_core_types__new_Cons(_ru_x1117, 0, y, _trmc_x10107, _ctx); /*list<4612>*/;
      kk_field_addr_t _b_x936_941 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10108, _ctx)->tail, _ctx); /*@field-addr<list<4612>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1575 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10108, _ctx)),_b_x936_941,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x1575;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1117,kk_context());
      { // tailcall
        xs = xx;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x1576 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1576, KK_OWNED, _ctx);
  }
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list_concat_maybe(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1577 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_concat_maybe(xs_0, _x_x1577, _ctx);
}
 
// Return the last element of a list (or `Nothing` for the empty list)

kk_std_core_types__maybe kk_std_core_list_last(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1578 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list _pat_0 = _con_x1578->tail;
    if (kk_std_core_types__is_Nil(_pat_0, _ctx)) {
      kk_box_t x = _con_x1578->head;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_box_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__new_Just(x, _ctx);
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1579 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_2 = _con_x1579->head;
    kk_std_core_types__list xx = _con_x1579->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list__trmc_init(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1580 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list xx = _con_x1580->tail;
    if (kk_std_core_types__is_Cons(xx, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1581 = kk_std_core_types__as_Cons(xx, _ctx);
      kk_box_t x = _con_x1580->head;
      kk_reuse_t _ru_x1120 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1120 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10109 = kk_datatype_null(); /*list<4685>*/;
      kk_std_core_types__list _trmc_x10110 = kk_std_core_types__new_Cons(_ru_x1120, 0, x, _trmc_x10109, _ctx); /*list<4685>*/;
      kk_field_addr_t _b_x952_957 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10110, _ctx)->tail, _ctx); /*@field-addr<list<4685>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1582 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10110, _ctx)),_b_x952_957,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x1582;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_box_t _x_x1583 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1583, KK_OWNED, _ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list_init(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1584 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_init(xs_0, _x_x1584, _ctx);
}
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.

kk_std_core_types__maybe kk_std_core_list__index(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1585 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1585->head;
    kk_std_core_types__list xx = _con_x1585->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool _match_x1004 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x1004) {
      kk_box_drop(x, _ctx);
      { // tailcall
        kk_integer_t _x_x1586 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1586;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      bool _match_x1005;
      bool _brw_x1006 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x1005 = _brw_x1006; /*bool*/
      if (_match_x1005) {
        return kk_std_core_types__new_Just(x, _ctx);
      }
      {
        kk_box_drop(x, _ctx);
        return kk_std_core_types__new_Nothing(_ctx);
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_all_10305(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10241, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10241) {
    return kk_std_core_list_all(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return false;
  }
}
 
// Do all elements satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list_all_fun1590__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_all_fun1590(kk_function_t _fself, kk_box_t _b_x964, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_all_fun1590(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_all_fun1590__t* _self = kk_function_alloc_as(struct kk_std_core_list_all_fun1590__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_all_fun1590, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_all_fun1590(kk_function_t _fself, kk_box_t _b_x964, kk_context_t* _ctx) {
  struct kk_std_core_list_all_fun1590__t* _self = kk_function_as(struct kk_std_core_list_all_fun1590__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (4801) -> 4802 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4801> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10241_0_966 = kk_bool_unbox(_b_x964); /*bool*/;
  bool _x_x1591 = kk_std_core_list__mlift_all_10305(predicate_0, xx_0, _y_x10241_0_966, _ctx); /*bool*/
  return kk_bool_box(_x_x1591);
}

bool kk_std_core_list_all(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1587 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1587->head;
    kk_std_core_types__list xx_0 = _con_x1587->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10397;
    kk_function_t _x_x1588 = kk_function_dup(predicate_0, _ctx); /*(4801) -> 4802 bool*/
    x_0_10397 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1588, (_x_x1588, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1589 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_all_fun1590(predicate_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_bool_unbox(_x_x1589);
    }
    if (x_0_10397) { // tailcall
                     xs = xx_0;
                     goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return true;
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_any_10306(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10245, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10245) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return true;
  }
  {
    return kk_std_core_list_any(xx, predicate, _ctx);
  }
}
 
// Are there any elements in a list that satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list_any_fun1595__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list_any_fun1595(kk_function_t _fself, kk_box_t _b_x968, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_any_fun1595(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list_any_fun1595__t* _self = kk_function_alloc_as(struct kk_std_core_list_any_fun1595__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_any_fun1595, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_any_fun1595(kk_function_t _fself, kk_box_t _b_x968, kk_context_t* _ctx) {
  struct kk_std_core_list_any_fun1595__t* _self = kk_function_as(struct kk_std_core_list_any_fun1595__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (4839) -> 4840 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4839> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10245_0_970 = kk_bool_unbox(_b_x968); /*bool*/;
  bool _x_x1596 = kk_std_core_list__mlift_any_10306(predicate_0, xx_0, _y_x10245_0_970, _ctx); /*bool*/
  return kk_bool_box(_x_x1596);
}

bool kk_std_core_list_any(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1592 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1592->head;
    kk_std_core_types__list xx_0 = _con_x1592->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10400;
    kk_function_t _x_x1593 = kk_function_dup(predicate_0, _ctx); /*(4839) -> 4840 bool*/
    x_0_10400 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1593, (_x_x1593, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1594 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_any_fun1595(predicate_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_bool_unbox(_x_x1594);
    }
    if (x_0_10400) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return true;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return false;
  }
}
 
// Return the sum of a list of integers


// lift anonymous function
struct kk_std_core_list_sum_fun1598__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_sum_fun1598(kk_function_t _fself, kk_box_t _b_x974, kk_box_t _b_x975, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_sum_fun1598(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_sum_fun1598, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_sum_fun1598(kk_function_t _fself, kk_box_t _b_x974, kk_box_t _b_x975, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x_x1599;
  kk_integer_t _x_x1600 = kk_integer_unbox(_b_x974, _ctx); /*int*/
  kk_integer_t _x_x1601 = kk_integer_unbox(_b_x975, _ctx); /*int*/
  _x_x1599 = kk_std_core_int__lp__plus__rp_(_x_x1600, _x_x1601, _ctx); /*int*/
  return kk_integer_box(_x_x1599, _ctx);
}

kk_integer_t kk_std_core_list_sum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<int>) -> int */ 
  kk_box_t _x_x1597 = kk_std_core_list_foldl(xs, kk_integer_box(kk_integer_from_small(0), _ctx), kk_std_core_list_new_sum_fun1598(_ctx), _ctx); /*1073*/
  return kk_integer_unbox(_x_x1597, _ctx);
}
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)


// lift anonymous function
struct kk_std_core_list_minimum_fun1604__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_minimum_fun1604(kk_function_t _fself, kk_box_t _b_x984, kk_box_t _b_x985, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_minimum_fun1604(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_minimum_fun1604, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_minimum_fun1604(kk_function_t _fself, kk_box_t _b_x984, kk_box_t _b_x985, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x_x1605;
  kk_integer_t _x_x1606 = kk_integer_unbox(_b_x984, _ctx); /*int*/
  kk_integer_t _x_x1607 = kk_integer_unbox(_b_x985, _ctx); /*int*/
  _x_x1605 = kk_std_core_int_min(_x_x1606, _x_x1607, _ctx); /*int*/
  return kk_integer_box(_x_x1605, _ctx);
}

kk_integer_t kk_std_core_list_minimum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x979 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_4871 = kk_integer_unbox(_box_x979, _ctx);
      kk_integer_dup(_uniq_default_4871, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_4871;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1602 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x980 = _con_x1602->head;
    kk_std_core_types__list xx = _con_x1602->tail;
    kk_integer_t x = kk_integer_unbox(_box_x980, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    kk_box_t _x_x1603 = kk_std_core_list_foldl(xx, kk_integer_box(x, _ctx), kk_std_core_list_new_minimum_fun1604(_ctx), _ctx); /*1073*/
    return kk_integer_unbox(_x_x1603, _ctx);
  }
}
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)


// lift anonymous function
struct kk_std_core_list_maximum_fun1610__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_maximum_fun1610(kk_function_t _fself, kk_box_t _b_x994, kk_box_t _b_x995, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_maximum_fun1610(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_maximum_fun1610, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_maximum_fun1610(kk_function_t _fself, kk_box_t _b_x994, kk_box_t _b_x995, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x_x1611;
  kk_integer_t _x_x1612 = kk_integer_unbox(_b_x994, _ctx); /*int*/
  kk_integer_t _x_x1613 = kk_integer_unbox(_b_x995, _ctx); /*int*/
  _x_x1611 = kk_std_core_int_max(_x_x1612, _x_x1613, _ctx); /*int*/
  return kk_integer_box(_x_x1611, _ctx);
}

kk_integer_t kk_std_core_list_maximum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x989 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_4901 = kk_integer_unbox(_box_x989, _ctx);
      kk_integer_dup(_uniq_default_4901, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_4901;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1608 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x990 = _con_x1608->head;
    kk_std_core_types__list xx = _con_x1608->tail;
    kk_integer_t x = kk_integer_unbox(_box_x990, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    kk_box_t _x_x1609 = kk_std_core_list_foldl(xx, kk_integer_box(x, _ctx), kk_std_core_list_new_maximum_fun1610(_ctx), _ctx); /*1073*/
    return kk_integer_unbox(_x_x1609, _ctx);
  }
}
 
// Join a list of strings with newlines

kk_string_t kk_std_core_list_unlines(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1617 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x999 = _con_x1617->head;
    kk_std_core_types__list _pat_1 = _con_x1617->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x999);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1618 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1000 = _con_x1618->head;
    kk_std_core_types__list _pat_3 = _con_x1618->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1619 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1001 = _con_x1619->head;
      kk_std_core_types__list _pat_4 = _con_x1619->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1620;
        kk_define_string_literal(, _s_x1621, 1, "\n", _ctx)
        _x_x1620 = kk_string_dup(_s_x1621, _ctx); /*string*/
        kk_string_t _x_x1622 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1620,_x_x1622,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x1000);
          kk_string_t y = kk_string_unbox(_box_x1001);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1624 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<832>*/
    kk_string_t _x_x1625;
    kk_define_string_literal(, _s_x1626, 1, "\n", _ctx)
    _x_x1625 = kk_string_dup(_s_x1626, _ctx); /*string*/
    return kk_string_join_with(_x_x1624,_x_x1625,kk_context());
  }
}

// initialization
void kk_std_core_list__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_list__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
