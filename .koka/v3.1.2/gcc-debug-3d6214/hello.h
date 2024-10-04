#pragma once
#ifndef kk_hello_H
#define kk_hello_H
// Koka generated module: hello, koka version: 3.1.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"

// type declarations

// type hello/get
struct kk_hello__get_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_hello__get;
struct kk_hello__Hnd_get {
  struct kk_hello__get_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _ctl_get;
};
static inline kk_hello__get kk_hello__base_Hnd_get(struct kk_hello__Hnd_get* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_hello__get kk_hello__new_Hnd_get(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _ctl_get, kk_context_t* _ctx) {
  struct kk_hello__Hnd_get* _con = kk_block_alloc_at_as(struct kk_hello__Hnd_get, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_ctl_get = _ctl_get;
  return kk_hello__base_Hnd_get(_con, _ctx);
}
static inline struct kk_hello__Hnd_get* kk_hello__as_Hnd_get(kk_hello__get x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_hello__Hnd_get*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_hello__is_Hnd_get(kk_hello__get x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_hello__get kk_hello__get_dup(kk_hello__get _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_hello__get_drop(kk_hello__get _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_hello__get_box(kk_hello__get _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_hello__get kk_hello__get_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type hello/is-verbose
struct kk_hello__is_verbose_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_hello__is_verbose;
struct kk_hello__Hnd_is_verbose {
  struct kk_hello__is_verbose_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _val_is_verbose;
};
static inline kk_hello__is_verbose kk_hello__base_Hnd_is_verbose(struct kk_hello__Hnd_is_verbose* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_hello__is_verbose kk_hello__new_Hnd_is_verbose(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _val_is_verbose, kk_context_t* _ctx) {
  struct kk_hello__Hnd_is_verbose* _con = kk_block_alloc_at_as(struct kk_hello__Hnd_is_verbose, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_val_is_verbose = _val_is_verbose;
  return kk_hello__base_Hnd_is_verbose(_con, _ctx);
}
static inline struct kk_hello__Hnd_is_verbose* kk_hello__as_Hnd_is_verbose(kk_hello__is_verbose x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_hello__Hnd_is_verbose*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_hello__is_Hnd_is_verbose(kk_hello__is_verbose x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_hello__is_verbose kk_hello__is_verbose_dup(kk_hello__is_verbose _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_hello__is_verbose_drop(kk_hello__is_verbose _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_hello__is_verbose_box(kk_hello__is_verbose _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_hello__is_verbose kk_hello__is_verbose_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type hello/log
struct kk_hello__log_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_hello__log;
struct kk_hello__Hnd_log {
  struct kk_hello__log_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_log_debug;
  kk_std_core_hnd__clause1 _fun_log_info;
};
static inline kk_hello__log kk_hello__base_Hnd_log(struct kk_hello__Hnd_log* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_hello__log kk_hello__new_Hnd_log(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_log_debug, kk_std_core_hnd__clause1 _fun_log_info, kk_context_t* _ctx) {
  struct kk_hello__Hnd_log* _con = kk_block_alloc_at_as(struct kk_hello__Hnd_log, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_log_debug = _fun_log_debug;
  _con->_fun_log_info = _fun_log_info;
  return kk_hello__base_Hnd_log(_con, _ctx);
}
static inline struct kk_hello__Hnd_log* kk_hello__as_Hnd_log(kk_hello__log x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_hello__Hnd_log*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_hello__is_Hnd_log(kk_hello__log x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_hello__log kk_hello__log_dup(kk_hello__log _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_hello__log_drop(kk_hello__log _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_hello__log_box(kk_hello__log _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_hello__log kk_hello__log_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type hello/throw-string
struct kk_hello__throw_string_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_hello__throw_string;
struct kk_hello__Hnd_throw_string {
  struct kk_hello__throw_string_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _ctl_throw_string;
};
static inline kk_hello__throw_string kk_hello__base_Hnd_throw_string(struct kk_hello__Hnd_throw_string* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_hello__throw_string kk_hello__new_Hnd_throw_string(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _ctl_throw_string, kk_context_t* _ctx) {
  struct kk_hello__Hnd_throw_string* _con = kk_block_alloc_at_as(struct kk_hello__Hnd_throw_string, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_ctl_throw_string = _ctl_throw_string;
  return kk_hello__base_Hnd_throw_string(_con, _ctx);
}
static inline struct kk_hello__Hnd_throw_string* kk_hello__as_Hnd_throw_string(kk_hello__throw_string x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_hello__Hnd_throw_string*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_hello__is_Hnd_throw_string(kk_hello__throw_string x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_hello__throw_string kk_hello__throw_string_dup(kk_hello__throw_string _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_hello__throw_string_drop(kk_hello__throw_string _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_hello__throw_string_box(kk_hello__throw_string _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_hello__throw_string kk_hello__throw_string_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:get` type.

static inline kk_integer_t kk_hello_get_fs__cfc(kk_hello__get get_0, kk_context_t* _ctx) { /* forall<a,e,b> (get : get<a,e,b>) -> int */ 
  {
    struct kk_hello__Hnd_get* _con_x315 = kk_hello__as_Hnd_get(get_0, _ctx);
    kk_integer_t _x = _con_x315->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@ctl-get` constructor field of the `:get` type.

static inline kk_std_core_hnd__clause0 kk_hello_get_fs__ctl_get(kk_hello__get get_0, kk_context_t* _ctx) { /* forall<a,e,b> (get : get<a,e,b>) -> hnd/clause0<a,get<a>,e,b> */ 
  {
    struct kk_hello__Hnd_get* _con_x316 = kk_hello__as_Hnd_get(get_0, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x316->_ctl_get;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:is-verbose` type.

static inline kk_integer_t kk_hello_is_verbose_fs__cfc(kk_hello__is_verbose _this, kk_context_t* _ctx) { /* forall<e,a> (is-verbose<e,a>) -> int */ 
  {
    struct kk_hello__Hnd_is_verbose* _con_x317 = kk_hello__as_Hnd_is_verbose(_this, _ctx);
    kk_integer_t _x = _con_x317->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@val-is-verbose` constructor field of the `:is-verbose` type.

static inline kk_std_core_hnd__clause0 kk_hello_is_verbose_fs__val_is_verbose(kk_hello__is_verbose _this, kk_context_t* _ctx) { /* forall<e,a> (is-verbose<e,a>) -> hnd/clause0<bool,is-verbose,e,a> */ 
  {
    struct kk_hello__Hnd_is_verbose* _con_x318 = kk_hello__as_Hnd_is_verbose(_this, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x318->_val_is_verbose;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:log` type.

static inline kk_integer_t kk_hello_log_fs__cfc(kk_hello__log log_0, kk_context_t* _ctx) { /* forall<e,a> (log : log<e,a>) -> int */ 
  {
    struct kk_hello__Hnd_log* _con_x319 = kk_hello__as_Hnd_log(log_0, _ctx);
    kk_integer_t _x = _con_x319->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@fun-log-debug` constructor field of the `:log` type.

static inline kk_std_core_hnd__clause1 kk_hello_log_fs__fun_log_debug(kk_hello__log log_0, kk_context_t* _ctx) { /* forall<e,a> (log : log<e,a>) -> hnd/clause1<string,(),log,e,a> */ 
  {
    struct kk_hello__Hnd_log* _con_x320 = kk_hello__as_Hnd_log(log_0, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x320->_fun_log_debug;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@fun-log-info` constructor field of the `:log` type.

static inline kk_std_core_hnd__clause1 kk_hello_log_fs__fun_log_info(kk_hello__log log_0, kk_context_t* _ctx) { /* forall<e,a> (log : log<e,a>) -> hnd/clause1<string,(),log,e,a> */ 
  {
    struct kk_hello__Hnd_log* _con_x321 = kk_hello__as_Hnd_log(log_0, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x321->_fun_log_info;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:throw-string` type.

static inline kk_integer_t kk_hello_throw_string_fs__cfc(kk_hello__throw_string _this, kk_context_t* _ctx) { /* forall<e,a> (throw-string<e,a>) -> int */ 
  {
    struct kk_hello__Hnd_throw_string* _con_x322 = kk_hello__as_Hnd_throw_string(_this, _ctx);
    kk_integer_t _x = _con_x322->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `@ctl-throw-string` constructor field of the `:throw-string` type.

static inline kk_std_core_hnd__clause1 kk_hello_throw_string_fs__ctl_throw_string(kk_hello__throw_string _this, kk_context_t* _ctx) { /* forall<e,a,b> (throw-string<e,a>) -> hnd/clause1<string,b,throw-string,e,a> */ 
  {
    struct kk_hello__Hnd_throw_string* _con_x323 = kk_hello__as_Hnd_throw_string(_this, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x323->_ctl_throw_string;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}

kk_unit_t kk_hello_hello_ten(kk_context_t* _ctx); /* () -> <console/console,div> () */ 

extern kk_std_core_hnd__htag kk_hello__tag_is_verbose;

kk_box_t kk_hello__handle_is_verbose(kk_hello__is_verbose hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : is-verbose<e,b>, ret : (res : a) -> e b, action : () -> <is-verbose|e> a) -> e b */ 
 
// select `@val-is-verbose` operation out of effect `:is-verbose`

static inline kk_std_core_hnd__clause0 kk_hello__select_val_is_verbose(kk_hello__is_verbose hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : is-verbose<e,a>) -> hnd/clause0<bool,is-verbose,e,a> */ 
  {
    struct kk_hello__Hnd_is_verbose* _con_x337 = kk_hello__as_Hnd_is_verbose(hnd, _ctx);
    kk_std_core_hnd__clause0 _val_is_verbose_0 = _con_x337->_val_is_verbose;
    return kk_std_core_hnd__clause0_dup(_val_is_verbose_0, _ctx);
  }
}
 
// Call the `val is-verbose` operation of the effect `:is-verbose`

static inline bool kk_hello__val_is_verbose(kk_context_t* _ctx) { /* () -> is-verbose bool */ 
  kk_std_core_hnd__ev ev_10047 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/is-verbose>*/;
  kk_box_t _x_x338;
  {
    struct kk_std_core_hnd_Ev* _con_x339 = kk_std_core_hnd__as_Ev(ev_10047, _ctx);
    kk_box_t _box_x22 = _con_x339->hnd;
    int32_t m = _con_x339->marker;
    kk_hello__is_verbose h = kk_hello__is_verbose_unbox(_box_x22, KK_BORROWED, _ctx);
    kk_hello__is_verbose_dup(h, _ctx);
    {
      struct kk_hello__Hnd_is_verbose* _con_x340 = kk_hello__as_Hnd_is_verbose(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x340->_cfc;
      kk_std_core_hnd__clause0 _val_is_verbose_0 = _con_x340->_val_is_verbose;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_val_is_verbose_0, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x25 = _val_is_verbose_0.clause;
        _x_x338 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x25, (_fun_unbox_x25, m, ev_10047, _ctx), _ctx); /*1005*/
      }
    }
  }
  return kk_bool_unbox(_x_x338);
}

extern kk_std_core_hnd__htag kk_hello__tag_log;

kk_box_t kk_hello__handle_log(kk_hello__log hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : log<e,b>, ret : (res : a) -> e b, action : () -> <log|e> a) -> e b */ 
 
// select `log-debug` operation out of effect `:log`

static inline kk_std_core_hnd__clause1 kk_hello__select_log_debug(kk_hello__log hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : log<e,a>) -> hnd/clause1<string,(),log,e,a> */ 
  {
    struct kk_hello__Hnd_log* _con_x344 = kk_hello__as_Hnd_log(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_log_debug = _con_x344->_fun_log_debug;
    return kk_std_core_hnd__clause1_dup(_fun_log_debug, _ctx);
  }
}
 
// Call the `fun log-debug` operation of the effect `:log`

static inline kk_unit_t kk_hello_log_debug(kk_string_t msg, kk_context_t* _ctx) { /* (msg : string) -> log () */ 
  kk_std_core_hnd__ev ev_10050 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/log>*/;
  kk_box_t _x_x345;
  {
    struct kk_std_core_hnd_Ev* _con_x346 = kk_std_core_hnd__as_Ev(ev_10050, _ctx);
    kk_box_t _box_x36 = _con_x346->hnd;
    int32_t m = _con_x346->marker;
    kk_hello__log h = kk_hello__log_unbox(_box_x36, KK_BORROWED, _ctx);
    kk_hello__log_dup(h, _ctx);
    {
      struct kk_hello__Hnd_log* _con_x347 = kk_hello__as_Hnd_log(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x347->_cfc;
      kk_std_core_hnd__clause1 _fun_log_debug = _con_x347->_fun_log_debug;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x347->_fun_log_info;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_log_debug, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x40 = _fun_log_debug.clause;
        _x_x345 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x40, (_fun_unbox_x40, m, ev_10050, kk_string_box(msg), _ctx), _ctx); /*1010*/
      }
    }
  }
  kk_unit_unbox(_x_x345); return kk_Unit;
}
 
// select `log-info` operation out of effect `:log`

static inline kk_std_core_hnd__clause1 kk_hello__select_log_info(kk_hello__log hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : log<e,a>) -> hnd/clause1<string,(),log,e,a> */ 
  {
    struct kk_hello__Hnd_log* _con_x348 = kk_hello__as_Hnd_log(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_log_info = _con_x348->_fun_log_info;
    return kk_std_core_hnd__clause1_dup(_fun_log_info, _ctx);
  }
}
 
// Call the `fun log-info` operation of the effect `:log`

static inline kk_unit_t kk_hello_log_info(kk_string_t msg, kk_context_t* _ctx) { /* (msg : string) -> log () */ 
  kk_std_core_hnd__ev ev_10053 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/log>*/;
  kk_box_t _x_x349;
  {
    struct kk_std_core_hnd_Ev* _con_x350 = kk_std_core_hnd__as_Ev(ev_10053, _ctx);
    kk_box_t _box_x44 = _con_x350->hnd;
    int32_t m = _con_x350->marker;
    kk_hello__log h = kk_hello__log_unbox(_box_x44, KK_BORROWED, _ctx);
    kk_hello__log_dup(h, _ctx);
    {
      struct kk_hello__Hnd_log* _con_x351 = kk_hello__as_Hnd_log(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x351->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x351->_fun_log_debug;
      kk_std_core_hnd__clause1 _fun_log_info = _con_x351->_fun_log_info;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_log_info, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x48 = _fun_log_info.clause;
        _x_x349 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x48, (_fun_unbox_x48, m, ev_10053, kk_string_box(msg), _ctx), _ctx); /*1010*/
      }
    }
  }
  kk_unit_unbox(_x_x349); return kk_Unit;
}
 
// monadic lift

static inline kk_unit_t kk_hello__mlift_log_10039(kk_string_t msg, bool _y_x10018, kk_context_t* _ctx) { /* (msg : string, bool) -> is-verbose () */ 
  kk_string_t _x_x352;
  if (_y_x10018) {
    kk_string_t _x_x353;
    kk_define_string_literal(, _s_x354, 8, "[DEBUG] ", _ctx)
    _x_x353 = kk_string_dup(_s_x354, _ctx); /*string*/
    _x_x352 = kk_std_core_types__lp__plus__plus__rp_(_x_x353, msg, _ctx); /*string*/
  }
  else {
    kk_string_t _x_x355;
    kk_define_string_literal(, _s_x356, 8, "[INFO ] ", _ctx)
    _x_x355 = kk_string_dup(_s_x356, _ctx); /*string*/
    _x_x352 = kk_std_core_types__lp__plus__plus__rp_(_x_x355, msg, _ctx); /*string*/
  }
  kk_std_core_console_printsln(_x_x352, _ctx); return kk_Unit;
}

kk_unit_t kk_hello_log(kk_string_t msg, kk_context_t* _ctx); /* (msg : string) -> <console/console,is-verbose> () */ 

kk_unit_t kk_hello__mlift_serve_10040(kk_unit_t wild__, kk_context_t* _ctx); /* (wild_ : ()) -> log () */ 

kk_unit_t kk_hello_serve(kk_integer_t port, kk_context_t* _ctx); /* (port : int) -> log () */ 

extern kk_std_core_hnd__htag kk_hello__tag_throw_string;

kk_box_t kk_hello__handle_throw_string(kk_hello__throw_string hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : throw-string<e,b>, ret : (res : a) -> e b, action : () -> <throw-string|e> a) -> e b */ 
 
// select `throw-string` operation out of effect `:throw-string`

static inline kk_std_core_hnd__clause1 kk_hello__select_throw_string(kk_hello__throw_string hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : throw-string<e,b>) -> hnd/clause1<string,a,throw-string,e,b> */ 
  {
    struct kk_hello__Hnd_throw_string* _con_x398 = kk_hello__as_Hnd_throw_string(hnd, _ctx);
    kk_std_core_hnd__clause1 _ctl_throw_string = _con_x398->_ctl_throw_string;
    return kk_std_core_hnd__clause1_dup(_ctl_throw_string, _ctx);
  }
}
 
// Call the `ctl throw-string` operation of the effect `:throw-string`

static inline kk_box_t kk_hello_throw_string(kk_string_t msg, kk_context_t* _ctx) { /* forall<a> (msg : string) -> throw-string a */ 
  kk_std_core_hnd__ev ev_10076 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/throw-string>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x399 = kk_std_core_hnd__as_Ev(ev_10076, _ctx);
    kk_box_t _box_x97 = _con_x399->hnd;
    int32_t m = _con_x399->marker;
    kk_hello__throw_string h = kk_hello__throw_string_unbox(_box_x97, KK_BORROWED, _ctx);
    kk_hello__throw_string_dup(h, _ctx);
    {
      struct kk_hello__Hnd_throw_string* _con_x400 = kk_hello__as_Hnd_throw_string(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x400->_cfc;
      kk_std_core_hnd__clause1 _ctl_throw_string = _con_x400->_ctl_throw_string;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_ctl_throw_string, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x101 = _ctl_throw_string.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x101, (_fun_unbox_x101, m, ev_10076, kk_string_box(msg), _ctx), _ctx);
      }
    }
  }
}

extern kk_std_core_hnd__htag kk_hello__tag_get;

kk_box_t kk_hello__handle_get(kk_hello__get hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,b,e,c> (hnd : get<a,e,c>, ret : (res : b) -> e c, action : () -> <get<a>|e> b) -> e c */ 
 
// select `get` operation out of effect `:get`

static inline kk_std_core_hnd__clause0 kk_hello__select_get(kk_hello__get hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : get<a,e,b>) -> hnd/clause0<a,get<a>,e,b> */ 
  {
    struct kk_hello__Hnd_get* _con_x404 = kk_hello__as_Hnd_get(hnd, _ctx);
    kk_std_core_hnd__clause0 _ctl_get = _con_x404->_ctl_get;
    return kk_std_core_hnd__clause0_dup(_ctl_get, _ctx);
  }
}
 
// Call the `ctl get` operation of the effect `:get`

static inline kk_box_t kk_hello_get(kk_context_t* _ctx) { /* forall<a> () -> (get<a>) a */ 
  kk_std_core_hnd__ev ev_10080 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/get<1302>>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x405 = kk_std_core_hnd__as_Ev(ev_10080, _ctx);
    kk_box_t _box_x113 = _con_x405->hnd;
    int32_t m = _con_x405->marker;
    kk_hello__get h = kk_hello__get_unbox(_box_x113, KK_BORROWED, _ctx);
    kk_hello__get_dup(h, _ctx);
    {
      struct kk_hello__Hnd_get* _con_x406 = kk_hello__as_Hnd_get(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x406->_cfc;
      kk_std_core_hnd__clause0 _ctl_get = _con_x406->_ctl_get;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_get, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t f = _ctl_get.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), f, (f, m, ev_10080, _ctx), _ctx);
      }
    }
  }
}

kk_integer_t kk_hello_safe_div(kk_integer_t m, kk_integer_t n, kk_context_t* _ctx); /* (m : int, n : int) -> throw-string int */ 

kk_unit_t kk_hello__mlift_report_get_mn_and_div_10041(kk_integer_t m, kk_integer_t n, kk_integer_t result, kk_context_t* _ctx); /* (m : int, n : int, result : int) -> <throw-string,console/console,get<int>> () */ 

kk_unit_t kk_hello__mlift_report_get_mn_and_div_10042(kk_integer_t m, kk_integer_t n, kk_context_t* _ctx); /* (m : int, n : int) -> <get<int>,console/console,throw-string> () */ 

kk_unit_t kk_hello__mlift_report_get_mn_and_div_10043(kk_integer_t m, kk_context_t* _ctx); /* (m : int) -> <get<int>,console/console,throw-string> () */ 

kk_unit_t kk_hello_report_get_mn_and_div(kk_context_t* _ctx); /* () -> <console/console,get<int>,throw-string> () */ 

kk_std_core_types__maybe kk_hello_to_maybe(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> <throw-string,console/console> a) -> console/console maybe<a> */ 

kk_std_core_types__list kk_hello_use_get_and_div(kk_context_t* _ctx); /* () -> console/console list<()> */ 


// lift anonymous function
struct kk_hello_main_fun552__t {
  struct kk_function_s _base;
};
extern kk_string_t kk_hello_main_fun552(kk_function_t _fself, kk_box_t _b_x288, kk_context_t* _ctx);
static inline kk_function_t kk_hello_new_main_fun552(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_main_fun552, _ctx)
  return kk_function_dup(_fself,kk_context());
}


static inline kk_unit_t kk_hello_main(kk_context_t* _ctx) { /* () -> console/console () */ 
  kk_std_core_types__list x_10010 = kk_hello_use_get_and_div(_ctx); /*list<()>*/;
  kk_string_t _x_x551 = kk_std_core_list_show(x_10010, kk_hello_new_main_fun552(_ctx), _ctx); /*string*/
  kk_std_core_console_printsln(_x_x551, _ctx); return kk_Unit;
}

void kk_hello__init(kk_context_t* _ctx);


void kk_hello__done(kk_context_t* _ctx);

#endif // header
