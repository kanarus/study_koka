// Koka generated module: std/core/exn, koka version: 3.1.2, platform: 64-bit
#include "std_core_exn.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_std_core_exn__error kk_error_ok( kk_box_t result, kk_context_t* ctx ) {
  return kk_std_core_exn__new_Ok( result, ctx );
}

kk_std_core_exn__error kk_error_from_errno( int err, kk_context_t* ctx ) {
  kk_string_t msg;
  #if defined(__GLIBC__) && !defined(WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
    // GNU version of strerror_r
    char buf[256];
    char* serr = strerror_r(err, buf, 255); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( serr, ctx );
  #elif (/* _POSIX_C_SOURCE >= 200112L ||*/ !defined(WIN32) && (_XOPEN_SOURCE >= 600 || defined(__APPLE__) || defined(__FreeBSD__) || defined(__MUSL__)))
    // XSI version of strerror_r
    char buf[256];
    strerror_r(err, buf, 255); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( buf, ctx );
  #elif defined(_MSC_VER) || (__STDC_VERSION__ >= 201112L || __cplusplus >= 201103L)
    // MSVC, or C/C++ 11
    char buf[256];
    strerror_s(buf, 255, err); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( buf, ctx );
  #else
    // Old style
    msg = kk_string_alloc_from_qutf8( strerror(err), ctx );
  #endif
  return kk_std_core_exn__new_Error( kk_std_core_exn__new_Exception( msg, kk_std_core_exn__new_ExnSystem(kk_reuse_null, 0, kk_integer_from_int(err,ctx), ctx), ctx), ctx );
}


kk_declare_string_literal(, kk_std_core_exn__tag_ExnError, 21, "std/core/exn/ExnError")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnAssert, 22, "std/core/exn/ExnAssert")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnTodo, 20, "std/core/exn/ExnTodo")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnRange, 21, "std/core/exn/ExnRange")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnPattern, 23, "std/core/exn/ExnPattern")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnSystem, 22, "std/core/exn/ExnSystem")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnInternal, 24, "std/core/exn/ExnInternal")

kk_std_core_exn__exception kk_std_core_exn_exception_fs__copy(kk_std_core_exn__exception _this, kk_std_core_types__optional message, kk_std_core_types__optional info, kk_context_t* _ctx) { /* (exception, message : ? string, info : ? exception-info) -> exception */ 
  kk_string_t _x_x100;
  if (kk_std_core_types__is_Optional(message, _ctx)) {
    kk_box_t _box_x0 = message._cons._Optional.value;
    kk_string_t _uniq_message_229 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_message_229, _ctx);
    kk_std_core_types__optional_drop(message, _ctx);
    _x_x100 = _uniq_message_229; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(message, _ctx);
    {
      kk_string_t _x = _this.message;
      kk_string_dup(_x, _ctx);
      _x_x100 = _x; /*string*/
    }
  }
  kk_std_core_exn__exception_info _x_x101;
  if (kk_std_core_types__is_Optional(info, _ctx)) {
    kk_box_t _box_x1 = info._cons._Optional.value;
    kk_std_core_exn__exception_info _uniq_info_236 = kk_std_core_exn__exception_info_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_exn__exception_info_dup(_uniq_info_236, _ctx);
    kk_std_core_types__optional_drop(info, _ctx);
    kk_std_core_exn__exception_drop(_this, _ctx);
    _x_x101 = _uniq_info_236; /*exception-info*/
  }
  else {
    kk_std_core_types__optional_drop(info, _ctx);
    {
      kk_std_core_exn__exception_info _x_0 = _this.info;
      kk_std_core_exn__exception_info_dup(_x_0, _ctx);
      kk_std_core_exn__exception_drop(_this, _ctx);
      _x_x101 = _x_0; /*exception-info*/
    }
  }
  return kk_std_core_exn__new_Exception(_x_x100, _x_x101, _ctx);
}
 
// runtime tag for the effect `:exn`

kk_std_core_hnd__htag kk_std_core_exn__tag_exn;
 
// handler for the effect `:exn`

kk_box_t kk_std_core_exn__handle_exn(kk_std_core_exn__exn hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : exn<e,b>, ret : (res : a) -> e b, action : () -> <exn|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x106 = kk_std_core_hnd__htag_dup(kk_std_core_exn__tag_exn, _ctx); /*hnd/htag<exn>*/
  return kk_std_core_hnd__hhandle(_x_x106, kk_std_core_exn__exn_box(hnd, _ctx), ret, action, _ctx);
}
 
// Throw an exception with a specified message.

kk_box_t kk_std_core_exn_throw(kk_string_t message, kk_std_core_types__optional info, kk_context_t* _ctx) { /* forall<a> (message : string, info : ? exception-info) -> exn a */ 
  kk_std_core_hnd__ev ev_10033 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x110 = kk_std_core_hnd__as_Ev(ev_10033, _ctx);
    kk_box_t _box_x18 = _con_x110->hnd;
    int32_t m = _con_x110->marker;
    kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_core_exn__exn_dup(h, _ctx);
    {
      struct kk_std_core_exn__Hnd_exn* _con_x111 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x111->_cfc;
      kk_std_core_hnd__clause1 _brk_throw_exn = _con_x111->_brk_throw_exn;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x22 = _brk_throw_exn.clause;
        kk_box_t _x_x112;
        kk_std_core_exn__exception _x_x113;
        kk_std_core_exn__exception_info _x_x114;
        if (kk_std_core_types__is_Optional(info, _ctx)) {
          kk_box_t _box_x26 = info._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_473 = kk_std_core_exn__exception_info_unbox(_box_x26, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_473, _ctx);
          kk_std_core_types__optional_drop(info, _ctx);
          _x_x114 = _uniq_info_473; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(info, _ctx);
          _x_x114 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x113 = kk_std_core_exn__new_Exception(message, _x_x114, _ctx); /*exception*/
        _x_x112 = kk_std_core_exn__exception_box(_x_x113, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22, (_fun_unbox_x22, m, ev_10033, _x_x112, _ctx), _ctx);
      }
    }
  }
}
 
// Raise a pattern match exception. This is function is used internally by the
// compiler to generate error messages on pattern match failures.

kk_box_t kk_std_core_exn_error_pattern(kk_string_t location, kk_string_t definition, kk_context_t* _ctx) { /* forall<a> (location : string, definition : string) -> exn a */ 
  kk_string_t message_10003;
  kk_string_t _x_x115 = kk_string_dup(location, _ctx); /*string*/
  kk_string_t _x_x116;
  kk_string_t _x_x117;
  kk_define_string_literal(, _s_x118, 2, ": ", _ctx)
  _x_x117 = kk_string_dup(_s_x118, _ctx); /*string*/
  kk_string_t _x_x119;
  kk_string_t _x_x120 = kk_string_dup(definition, _ctx); /*string*/
  kk_string_t _x_x121;
  kk_define_string_literal(, _s_x122, 23, ": pattern match failure", _ctx)
  _x_x121 = kk_string_dup(_s_x122, _ctx); /*string*/
  _x_x119 = kk_std_core_types__lp__plus__plus__rp_(_x_x120, _x_x121, _ctx); /*string*/
  _x_x116 = kk_std_core_types__lp__plus__plus__rp_(_x_x117, _x_x119, _ctx); /*string*/
  message_10003 = kk_std_core_types__lp__plus__plus__rp_(_x_x115, _x_x116, _ctx); /*string*/
  kk_std_core_hnd__ev ev_10036 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x123 = kk_std_core_hnd__as_Ev(ev_10036, _ctx);
    kk_box_t _box_x27 = _con_x123->hnd;
    int32_t m = _con_x123->marker;
    kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x27, KK_BORROWED, _ctx);
    kk_std_core_exn__exn_dup(h, _ctx);
    {
      struct kk_std_core_exn__Hnd_exn* _con_x124 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x124->_cfc;
      kk_std_core_hnd__clause1 _brk_throw_exn = _con_x124->_brk_throw_exn;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x31 = _brk_throw_exn.clause;
        kk_box_t _x_x125;
        kk_std_core_exn__exception _x_x126;
        kk_std_core_exn__exception_info _x_x127 = kk_std_core_exn__new_ExnPattern(kk_reuse_null, 0, location, definition, _ctx); /*exception-info*/
        _x_x126 = kk_std_core_exn__new_Exception(message_10003, _x_x127, _ctx); /*exception*/
        _x_x125 = kk_std_core_exn__exception_box(_x_x126, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x31, (_fun_unbox_x31, m, ev_10036, _x_x125, _ctx), _ctx);
      }
    }
  }
}
 
// Catch any exception raised in `action` and handle it.
// Use `on-exn` or `on-exit` when appropriate.


// lift anonymous function
struct kk_std_core_exn_exn_fs_try_fun128__t {
  struct kk_function_s _base;
  kk_function_t hndl;
};
static kk_box_t kk_std_core_exn_exn_fs_try_fun128(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_exn_fs_new_try_fun128(kk_function_t hndl, kk_context_t* _ctx) {
  struct kk_std_core_exn_exn_fs_try_fun128__t* _self = kk_function_alloc_as(struct kk_std_core_exn_exn_fs_try_fun128__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_exn_fs_try_fun128, kk_context());
  _self->hndl = hndl;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_exn_fs_try_fun129__t {
  struct kk_function_s _base;
  kk_function_t hndl;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core_exn_exn_fs_try_fun129(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_exn_fs_new_try_fun129(kk_function_t hndl, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_exn_fs_try_fun129__t* _self = kk_function_alloc_as(struct kk_std_core_exn_exn_fs_try_fun129__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_exn_fs_try_fun129, kk_context());
  _self->hndl = hndl;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_exn_fs_try_fun129(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx) {
  struct kk_std_core_exn_exn_fs_try_fun129__t* _self = kk_function_as(struct kk_std_core_exn_exn_fs_try_fun129__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 638 637 */
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x638__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_exn__exception, kk_context_t*), hndl, (hndl, x, _ctx), _ctx);
}
static kk_box_t kk_std_core_exn_exn_fs_try_fun128(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_exn_fs_try_fun128__t* _self = kk_function_as(struct kk_std_core_exn_exn_fs_try_fun128__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 638 637 */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x638__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_exn_exn_fs_new_try_fun129(hndl, x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_exn_fs_try_fun132__t {
  struct kk_function_s _base;
  kk_function_t _b_x35_39;
};
static kk_box_t kk_std_core_exn_exn_fs_try_fun132(kk_function_t _fself, int32_t _b_x36, kk_std_core_hnd__ev _b_x37, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_exn_fs_new_try_fun132(kk_function_t _b_x35_39, kk_context_t* _ctx) {
  struct kk_std_core_exn_exn_fs_try_fun132__t* _self = kk_function_alloc_as(struct kk_std_core_exn_exn_fs_try_fun132__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_exn_fs_try_fun132, kk_context());
  _self->_b_x35_39 = _b_x35_39;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_exn_fs_try_fun132(kk_function_t _fself, int32_t _b_x36, kk_std_core_hnd__ev _b_x37, kk_box_t _b_x38, kk_context_t* _ctx) {
  struct kk_std_core_exn_exn_fs_try_fun132__t* _self = kk_function_as(struct kk_std_core_exn_exn_fs_try_fun132__t*, _fself, _ctx);
  kk_function_t _b_x35_39 = _self->_b_x35_39; /* (m : hnd/marker<638,637>, hnd/ev<exn>, x : exception) -> 638 625 */
  kk_drop_match(_self, {kk_function_dup(_b_x35_39, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x133 = kk_std_core_exn__exception_unbox(_b_x38, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x35_39, (_b_x35_39, _b_x36, _b_x37, _x_x133, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_exn_fs_try_fun134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_exn_fs_try_fun134(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_exn_fs_new_try_fun134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_exn_fs_try_fun134, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_exn_fs_try_fun134(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  kk_unused(_fself);
  return _x;
}

kk_box_t kk_std_core_exn_exn_fs_try(kk_function_t action, kk_function_t hndl, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 
  kk_function_t _b_x35_39 = kk_std_core_exn_exn_fs_new_try_fun128(hndl, _ctx); /*(m : hnd/marker<638,637>, hnd/ev<exn>, x : exception) -> 638 625*/;
  kk_std_core_exn__exn _x_x130;
  kk_std_core_hnd__clause1 _x_x131 = kk_std_core_hnd__new_Clause1(kk_std_core_exn_exn_fs_new_try_fun132(_b_x35_39, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x130 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x131, _ctx); /*exn<14,15>*/
  return kk_std_core_exn__handle_exn(_x_x130, kk_std_core_exn_exn_fs_new_try_fun134(_ctx), action, _ctx);
}
 
// Transform an exception effect to an  `:error` type.


// lift anonymous function
struct kk_std_core_exn_try_fun136__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_try_fun136(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun136(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_try_fun136, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_core_exn_try_fun137__t {
  struct kk_function_s _base;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core_exn_try_fun137(kk_function_t _fself, kk_function_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun137(kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun137__t* _self = kk_function_alloc_as(struct kk_std_core_exn_try_fun137__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_try_fun137, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_try_fun138__t {
  struct kk_function_s _base;
  kk_function_t _b_x42;
};
static kk_std_core_exn__error kk_std_core_exn_try_fun138(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x43, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun138(kk_function_t _b_x42, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun138__t* _self = kk_function_alloc_as(struct kk_std_core_exn_try_fun138__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_try_fun138, kk_context());
  _self->_b_x42 = _b_x42;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_exn__error kk_std_core_exn_try_fun138(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x43, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun138__t* _self = kk_function_as(struct kk_std_core_exn_try_fun138__t*, _fself, _ctx);
  kk_function_t _b_x42 = _self->_b_x42; /* (hnd/resume-result<3225,3228>) -> 3227 3228 */
  kk_drop_match(_self, {kk_function_dup(_b_x42, _ctx);}, {}, _ctx)
  kk_box_t _x_x139 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x42, (_b_x42, _b_x43, _ctx), _ctx); /*3228*/
  return kk_std_core_exn__error_unbox(_x_x139, KK_OWNED, _ctx);
}
static kk_box_t kk_std_core_exn_try_fun137(kk_function_t _fself, kk_function_t _b_x42, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun137__t* _self = kk_function_as(struct kk_std_core_exn_try_fun137__t*, _fself, _ctx);
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_t ___wildcard_x638__45_61 = kk_std_core_exn_new_try_fun138(_b_x42, _ctx); /*(hnd/resume-result<625,error<677>>) -> 678 error<677>*/;
  kk_function_drop(___wildcard_x638__45_61, _ctx);
  kk_std_core_exn__error _x_x140 = kk_std_core_exn__new_Error(x, _ctx); /*error<6>*/
  return kk_std_core_exn__error_box(_x_x140, _ctx);
}
static kk_box_t kk_std_core_exn_try_fun136(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_datatype_ptr_dropn(___wildcard_x638__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_exn_new_try_fun137(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_try_fun143__t {
  struct kk_function_s _base;
  kk_function_t _b_x44_57;
};
static kk_box_t kk_std_core_exn_try_fun143(kk_function_t _fself, int32_t _b_x45, kk_std_core_hnd__ev _b_x46, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun143(kk_function_t _b_x44_57, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun143__t* _self = kk_function_alloc_as(struct kk_std_core_exn_try_fun143__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_try_fun143, kk_context());
  _self->_b_x44_57 = _b_x44_57;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_try_fun143(kk_function_t _fself, int32_t _b_x45, kk_std_core_hnd__ev _b_x46, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun143__t* _self = kk_function_as(struct kk_std_core_exn_try_fun143__t*, _fself, _ctx);
  kk_function_t _b_x44_57 = _self->_b_x44_57; /* (m : hnd/marker<678,error<677>>, hnd/ev<exn>, x : exception) -> 678 625 */
  kk_drop_match(_self, {kk_function_dup(_b_x44_57, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x144 = kk_std_core_exn__exception_unbox(_b_x47, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x44_57, (_b_x44_57, _b_x45, _b_x46, _x_x144, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_try_fun145__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_try_fun145(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun145(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_try_fun145, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_try_fun145(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_exn__error _x_62 = kk_std_core_exn__error_unbox(_b_x53, KK_OWNED, _ctx); /*error<677>*/;
  return kk_std_core_exn__error_box(_x_62, _ctx);
}


// lift anonymous function
struct kk_std_core_exn_try_fun146__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core_exn_try_fun146(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun146(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun146__t* _self = kk_function_alloc_as(struct kk_std_core_exn_try_fun146__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_try_fun146, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_try_fun149__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_try_fun149(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_try_fun149(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_try_fun149, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_try_fun149(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_box_t _y_x10020_63 = _b_x49; /*677*/;
  kk_std_core_exn__error _x_x150 = kk_std_core_exn__new_Ok(_y_x10020_63, _ctx); /*error<6>*/
  return kk_std_core_exn__error_box(_x_x150, _ctx);
}
static kk_box_t kk_std_core_exn_try_fun146(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_exn_try_fun146__t* _self = kk_function_as(struct kk_std_core_exn_try_fun146__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> <exn|678> 677 */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_box_t x_0_10041 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*677*/;
  kk_std_core_exn__error _x_x147;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_0_10041, _ctx);
    kk_box_t _x_x148 = kk_std_core_hnd_yield_extend(kk_std_core_exn_new_try_fun149(_ctx), _ctx); /*2978*/
    _x_x147 = kk_std_core_exn__error_unbox(_x_x148, KK_OWNED, _ctx); /*error<677>*/
  }
  else {
    _x_x147 = kk_std_core_exn__new_Ok(x_0_10041, _ctx); /*error<677>*/
  }
  return kk_std_core_exn__error_box(_x_x147, _ctx);
}

kk_std_core_exn__error kk_std_core_exn_try(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a) -> e error<a> */ 
  kk_box_t _x_x135;
  kk_function_t _b_x44_57 = kk_std_core_exn_new_try_fun136(_ctx); /*(m : hnd/marker<678,error<677>>, hnd/ev<exn>, x : exception) -> 678 625*/;
  kk_std_core_exn__exn _x_x141;
  kk_std_core_hnd__clause1 _x_x142 = kk_std_core_hnd__new_Clause1(kk_std_core_exn_new_try_fun143(_b_x44_57, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x141 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x142, _ctx); /*exn<14,15>*/
  _x_x135 = kk_std_core_exn__handle_exn(_x_x141, kk_std_core_exn_new_try_fun145(_ctx), kk_std_core_exn_new_try_fun146(action, _ctx), _ctx); /*373*/
  return kk_std_core_exn__error_unbox(_x_x135, KK_OWNED, _ctx);
}
 
// _Deprecated_; use `try` instead. Catch an exception raised by `throw` and handle it.
// Use `on-exn` or `on-exit` when appropriate.


// lift anonymous function
struct kk_std_core_exn_catch_fun151__t {
  struct kk_function_s _base;
  kk_function_t hndl;
};
static kk_box_t kk_std_core_exn_catch_fun151(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_catch_fun151(kk_function_t hndl, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun151__t* _self = kk_function_alloc_as(struct kk_std_core_exn_catch_fun151__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_catch_fun151, kk_context());
  _self->hndl = hndl;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_catch_fun152__t {
  struct kk_function_s _base;
  kk_function_t hndl;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core_exn_catch_fun152(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_catch_fun152(kk_function_t hndl, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun152__t* _self = kk_function_alloc_as(struct kk_std_core_exn_catch_fun152__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_catch_fun152, kk_context());
  _self->hndl = hndl;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_catch_fun152(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun152__t* _self = kk_function_as(struct kk_std_core_exn_catch_fun152__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 708 707 */
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x638__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_exn__exception, kk_context_t*), hndl, (hndl, x, _ctx), _ctx);
}
static kk_box_t kk_std_core_exn_catch_fun151(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun151__t* _self = kk_function_as(struct kk_std_core_exn_catch_fun151__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 708 707 */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x638__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_exn_new_catch_fun152(hndl, x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_catch_fun155__t {
  struct kk_function_s _base;
  kk_function_t _b_x64_68;
};
static kk_box_t kk_std_core_exn_catch_fun155(kk_function_t _fself, int32_t _b_x65, kk_std_core_hnd__ev _b_x66, kk_box_t _b_x67, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_catch_fun155(kk_function_t _b_x64_68, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun155__t* _self = kk_function_alloc_as(struct kk_std_core_exn_catch_fun155__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_catch_fun155, kk_context());
  _self->_b_x64_68 = _b_x64_68;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_catch_fun155(kk_function_t _fself, int32_t _b_x65, kk_std_core_hnd__ev _b_x66, kk_box_t _b_x67, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun155__t* _self = kk_function_as(struct kk_std_core_exn_catch_fun155__t*, _fself, _ctx);
  kk_function_t _b_x64_68 = _self->_b_x64_68; /* (m : hnd/marker<708,707>, hnd/ev<exn>, x : exception) -> 708 625 */
  kk_drop_match(_self, {kk_function_dup(_b_x64_68, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x156 = kk_std_core_exn__exception_unbox(_b_x67, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x64_68, (_b_x64_68, _b_x65, _b_x66, _x_x156, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_catch_fun157__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_catch_fun157(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_new_catch_fun157(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_catch_fun157, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_catch_fun157(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  kk_unused(_fself);
  return _x;
}

kk_box_t kk_std_core_exn_catch(kk_function_t action, kk_function_t hndl, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 
  kk_function_t _b_x64_68 = kk_std_core_exn_new_catch_fun151(hndl, _ctx); /*(m : hnd/marker<708,707>, hnd/ev<exn>, x : exception) -> 708 625*/;
  kk_std_core_exn__exn _x_x153;
  kk_std_core_hnd__clause1 _x_x154 = kk_std_core_hnd__new_Clause1(kk_std_core_exn_new_catch_fun155(_b_x64_68, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x153 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x154, _ctx); /*exn<14,15>*/
  return kk_std_core_exn__handle_exn(_x_x153, kk_std_core_exn_new_catch_fun157(_ctx), action, _ctx);
}
 
// Transform an `:error` type back to an `exn` effect.

kk_box_t kk_std_core_exn_untry(kk_std_core_exn__error err, kk_context_t* _ctx) { /* forall<a> (err : error<a>) -> exn a */ 
  if (kk_std_core_exn__is_Error(err, _ctx)) {
    kk_std_core_exn__exception exn_0 = err._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn_0, _ctx);
    kk_std_core_exn__error_drop(err, _ctx);
    kk_std_core_hnd__ev ev_10045 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x158 = kk_std_core_hnd__as_Ev(ev_10045, _ctx);
      kk_box_t _box_x69 = _con_x158->hnd;
      int32_t m = _con_x158->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x69, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      {
        struct kk_std_core_exn__Hnd_exn* _con_x159 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x159->_cfc;
        kk_std_core_hnd__clause1 _brk_throw_exn = _con_x159->_brk_throw_exn;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x73 = _brk_throw_exn.clause;
          return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x73, (_fun_unbox_x73, m, ev_10045, kk_std_core_exn__exception_box(exn_0, _ctx), _ctx), _ctx);
        }
      }
    }
  }
  {
    kk_box_t x_0 = err._cons.Ok.result;
    return x_0;
  }
}
 
// Transform an `:error` type to an `:either` value.

kk_std_core_types__either kk_std_core_exn_either(kk_std_core_exn__error t, kk_context_t* _ctx) { /* forall<a> (t : error<a>) -> either<exception,a> */ 
  if (kk_std_core_exn__is_Error(t, _ctx)) {
    kk_std_core_exn__exception exn_0 = t._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn_0, _ctx);
    kk_std_core_exn__error_drop(t, _ctx);
    return kk_std_core_types__new_Left(kk_std_core_exn__exception_box(exn_0, _ctx), _ctx);
  }
  {
    kk_box_t x = t._cons.Ok.result;
    return kk_std_core_types__new_Right(x, _ctx);
  }
}

kk_box_t kk_std_core_exn_exn_error_range(kk_context_t* _ctx) { /* forall<a> () -> exn a */ 
  kk_std_core_hnd__ev ev_10050 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x161 = kk_std_core_hnd__as_Ev(ev_10050, _ctx);
    kk_box_t _box_x79 = _con_x161->hnd;
    int32_t m = _con_x161->marker;
    kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x79, KK_BORROWED, _ctx);
    kk_std_core_exn__exn_dup(h, _ctx);
    {
      struct kk_std_core_exn__Hnd_exn* _con_x162 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x162->_cfc;
      kk_std_core_hnd__clause1 _brk_throw_exn = _con_x162->_brk_throw_exn;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x83 = _brk_throw_exn.clause;
        kk_box_t _x_x163;
        kk_std_core_exn__exception _x_x164;
        kk_string_t _x_x165;
        kk_define_string_literal(, _s_x166, 18, "index out-of-range", _ctx)
        _x_x165 = kk_string_dup(_s_x166, _ctx); /*string*/
        _x_x164 = kk_std_core_exn__new_Exception(_x_x165, kk_std_core_exn__new_ExnRange(_ctx), _ctx); /*exception*/
        _x_x163 = kk_std_core_exn__exception_box(_x_x164, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x83, (_fun_unbox_x83, m, ev_10050, _x_x163, _ctx), _ctx);
      }
    }
  }
}

// initialization
void kk_std_core_exn__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_std_core_exn__tag_ExnError, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnAssert, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnTodo, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnRange, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnPattern, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnSystem, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnInternal, _ctx)
  {
    kk_string_t _x_x104;
    kk_define_string_literal(, _s_x105, 7, "exn@exn", _ctx)
    _x_x104 = kk_string_dup(_s_x105, _ctx); /*string*/
    kk_std_core_exn__tag_exn = kk_std_core_hnd__new_Htag(_x_x104, _ctx); /*hnd/htag<exn>*/
  }
}

// termination
void kk_std_core_exn__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_std_core_exn__tag_exn, _ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
