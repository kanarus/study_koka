// Koka generated module: hello, koka version: 3.1.2, platform: 64-bit
#include "hello.h"


// lift anonymous function
struct kk_hello_hello_ten_fun325__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static bool kk_hello_hello_ten_fun325(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_hello_ten_fun325(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_hello_hello_ten_fun325__t* _self = kk_function_alloc_as(struct kk_hello_hello_ten_fun325__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_hello_ten_fun325, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_hello_hello_ten_fun325(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_hello_hello_ten_fun325__t* _self = kk_function_as(struct kk_hello_hello_ten_fun325__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<581,int> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_integer_t _brw_x300;
  kk_box_t _x_x326 = kk_ref_get(loc,kk_context()); /*1000*/
  _brw_x300 = kk_integer_unbox(_x_x326, _ctx); /*int*/
  bool _brw_x301 = kk_integer_lt_borrow(_brw_x300,(kk_integer_from_small(10)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x300, _ctx);
  return _brw_x301;
}


// lift anonymous function
struct kk_hello_hello_ten_fun328__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_unit_t kk_hello_hello_ten_fun328(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_hello_ten_fun328(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_hello_hello_ten_fun328__t* _self = kk_function_alloc_as(struct kk_hello_hello_ten_fun328__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_hello_ten_fun328, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_hello_hello_ten_fun328(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_hello_hello_ten_fun328__t* _self = kk_function_as(struct kk_hello_hello_ten_fun328__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<581,int> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x329;
  kk_define_string_literal(, _s_x330, 5, "hello", _ctx)
  _x_x329 = kk_string_dup(_s_x330, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x329, _ctx);
  kk_integer_t x_10002;
  kk_box_t _x_x331;
  kk_ref_t _x_x332 = kk_ref_dup(loc, _ctx); /*local-var<581,int>*/
  _x_x331 = kk_ref_get(_x_x332,kk_context()); /*1000*/
  x_10002 = kk_integer_unbox(_x_x331, _ctx); /*int*/
  kk_integer_t _b_x6_9 = kk_integer_add_small_const(x_10002, 1, _ctx); /*int*/;
  kk_unit_t _brw_x299 = kk_Unit;
  kk_ref_set_borrow(loc,(kk_integer_box(_b_x6_9, _ctx)),kk_context());
  kk_ref_drop(loc, _ctx);
  _brw_x299; return kk_Unit;
}

kk_unit_t kk_hello_hello_ten(kk_context_t* _ctx) { /* () -> <console/console,div> () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<581,int>*/;
  kk_unit_t res = kk_Unit;
  kk_function_t _x_x324;
  kk_ref_dup(loc, _ctx);
  _x_x324 = kk_hello_new_hello_ten_fun325(loc, _ctx); /*() -> <div,local<581>,console/console> bool*/
  kk_function_t _x_x327;
  kk_ref_dup(loc, _ctx);
  _x_x327 = kk_hello_new_hello_ten_fun328(loc, _ctx); /*() -> <div,local<581>,console/console> ()*/
  kk_std_core_while(_x_x324, _x_x327, _ctx);
  kk_box_t _x_x333 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*3004*/
  kk_unit_unbox(_x_x333); return kk_Unit;
}
 
// runtime tag for the effect `:is-verbose`

kk_std_core_hnd__htag kk_hello__tag_is_verbose;
 
// handler for the effect `:is-verbose`

kk_box_t kk_hello__handle_is_verbose(kk_hello__is_verbose hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : is-verbose<e,b>, ret : (res : a) -> e b, action : () -> <is-verbose|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x336 = kk_std_core_hnd__htag_dup(kk_hello__tag_is_verbose, _ctx); /*hnd/htag<hello/is-verbose>*/
  return kk_std_core_hnd__hhandle(_x_x336, kk_hello__is_verbose_box(hnd, _ctx), ret, action, _ctx);
}
 
// Call the `val is-verbose` operation of the effect `:is-verbose`
 
// runtime tag for the effect `:log`

kk_std_core_hnd__htag kk_hello__tag_log;
 
// handler for the effect `:log`

kk_box_t kk_hello__handle_log(kk_hello__log hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : log<e,b>, ret : (res : a) -> e b, action : () -> <log|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x343 = kk_std_core_hnd__htag_dup(kk_hello__tag_log, _ctx); /*hnd/htag<hello/log>*/
  return kk_std_core_hnd__hhandle(_x_x343, kk_hello__log_box(hnd, _ctx), ret, action, _ctx);
}


// lift anonymous function
struct kk_hello_log_fun361__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_hello_log_fun361(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx);
static kk_function_t kk_hello_new_log_fun361(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_hello_log_fun361__t* _self = kk_function_alloc_as(struct kk_hello_log_fun361__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_log_fun361, kk_context());
  _self->msg = msg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_log_fun361(kk_function_t _fself, kk_box_t _b_x59, kk_context_t* _ctx) {
  struct kk_hello_log_fun361__t* _self = kk_function_as(struct kk_hello_log_fun361__t*, _fself, _ctx);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg, _ctx);}, {}, _ctx)
  bool _y_x10018_61 = kk_bool_unbox(_b_x59); /*bool*/;
  kk_unit_t _x_x362 = kk_Unit;
  kk_string_t _x_x363;
  if (_y_x10018_61) {
    kk_string_t _x_x364;
    kk_define_string_literal(, _s_x365, 8, "[DEBUG] ", _ctx)
    _x_x364 = kk_string_dup(_s_x365, _ctx); /*string*/
    _x_x363 = kk_std_core_types__lp__plus__plus__rp_(_x_x364, msg, _ctx); /*string*/
  }
  else {
    kk_string_t _x_x366;
    kk_define_string_literal(, _s_x367, 8, "[INFO ] ", _ctx)
    _x_x366 = kk_string_dup(_s_x367, _ctx); /*string*/
    _x_x363 = kk_std_core_types__lp__plus__plus__rp_(_x_x366, msg, _ctx); /*string*/
  }
  kk_std_core_console_printsln(_x_x363, _ctx);
  return kk_unit_box(_x_x362);
}

kk_unit_t kk_hello_log(kk_string_t msg, kk_context_t* _ctx) { /* (msg : string) -> <console/console,is-verbose> () */ 
  kk_std_core_hnd__ev ev_10059 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/is-verbose>*/;
  bool x_10056;
  kk_box_t _x_x357;
  {
    struct kk_std_core_hnd_Ev* _con_x358 = kk_std_core_hnd__as_Ev(ev_10059, _ctx);
    kk_box_t _box_x52 = _con_x358->hnd;
    int32_t m = _con_x358->marker;
    kk_hello__is_verbose h = kk_hello__is_verbose_unbox(_box_x52, KK_BORROWED, _ctx);
    kk_hello__is_verbose_dup(h, _ctx);
    {
      struct kk_hello__Hnd_is_verbose* _con_x359 = kk_hello__as_Hnd_is_verbose(h, _ctx);
      kk_integer_t _pat_0 = _con_x359->_cfc;
      kk_std_core_hnd__clause0 _val_is_verbose_0 = _con_x359->_val_is_verbose;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_val_is_verbose_0, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x55 = _val_is_verbose_0.clause;
        _x_x357 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x55, (_fun_unbox_x55, m, ev_10059, _ctx), _ctx); /*1005*/
      }
    }
  }
  x_10056 = kk_bool_unbox(_x_x357); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x360 = kk_std_core_hnd_yield_extend(kk_hello_new_log_fun361(msg, _ctx), _ctx); /*3003*/
    kk_unit_unbox(_x_x360); return kk_Unit;
  }
  {
    kk_string_t _x_x368;
    if (x_10056) {
      kk_string_t _x_x369;
      kk_define_string_literal(, _s_x370, 8, "[DEBUG] ", _ctx)
      _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
      _x_x368 = kk_std_core_types__lp__plus__plus__rp_(_x_x369, msg, _ctx); /*string*/
    }
    else {
      kk_string_t _x_x371;
      kk_define_string_literal(, _s_x372, 8, "[INFO ] ", _ctx)
      _x_x371 = kk_string_dup(_s_x372, _ctx); /*string*/
      _x_x368 = kk_std_core_types__lp__plus__plus__rp_(_x_x371, msg, _ctx); /*string*/
    }
    kk_std_core_console_printsln(_x_x368, _ctx); return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_hello__mlift_serve_10040(kk_unit_t wild__, kk_context_t* _ctx) { /* (wild_ : ()) -> log () */ 
  kk_std_core_hnd__ev ev_10063 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/log>*/;
  kk_box_t _x_x373;
  {
    struct kk_std_core_hnd_Ev* _con_x374 = kk_std_core_hnd__as_Ev(ev_10063, _ctx);
    kk_box_t _box_x62 = _con_x374->hnd;
    int32_t m = _con_x374->marker;
    kk_hello__log h = kk_hello__log_unbox(_box_x62, KK_BORROWED, _ctx);
    kk_hello__log_dup(h, _ctx);
    {
      struct kk_hello__Hnd_log* _con_x375 = kk_hello__as_Hnd_log(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x375->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x375->_fun_log_debug;
      kk_std_core_hnd__clause1 _fun_log_info = _con_x375->_fun_log_info;
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
        kk_function_t _fun_unbox_x66 = _fun_log_info.clause;
        kk_box_t _x_x376;
        kk_string_t _x_x377;
        kk_define_string_literal(, _s_x378, 17, "Server is running", _ctx)
        _x_x377 = kk_string_dup(_s_x378, _ctx); /*string*/
        _x_x376 = kk_string_box(_x_x377); /*1009*/
        _x_x373 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x66, (_fun_unbox_x66, m, ev_10063, _x_x376, _ctx), _ctx); /*1010*/
      }
    }
  }
  kk_unit_unbox(_x_x373); return kk_Unit;
}


// lift anonymous function
struct kk_hello_serve_fun386__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_serve_fun386(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_hello_new_serve_fun386(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_serve_fun386, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_serve_fun386(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_unit_t _x_x387 = kk_Unit;
  kk_unit_t _x_x388 = kk_Unit;
  kk_unit_unbox(_b_x79);
  kk_hello__mlift_serve_10040(_x_x388, _ctx);
  return kk_unit_box(_x_x387);
}

kk_unit_t kk_hello_serve(kk_integer_t port, kk_context_t* _ctx) { /* (port : int) -> log () */ 
  kk_integer_drop(port, _ctx);
  kk_std_core_hnd__ev ev_10069 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/log>*/;
  kk_unit_t x_10066 = kk_Unit;
  kk_box_t _x_x379;
  {
    struct kk_std_core_hnd_Ev* _con_x380 = kk_std_core_hnd__as_Ev(ev_10069, _ctx);
    kk_box_t _box_x70 = _con_x380->hnd;
    int32_t m = _con_x380->marker;
    kk_hello__log h = kk_hello__log_unbox(_box_x70, KK_BORROWED, _ctx);
    kk_hello__log_dup(h, _ctx);
    {
      struct kk_hello__Hnd_log* _con_x381 = kk_hello__as_Hnd_log(h, _ctx);
      kk_integer_t _pat_0 = _con_x381->_cfc;
      kk_std_core_hnd__clause1 _fun_log_debug = _con_x381->_fun_log_debug;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x381->_fun_log_info;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_log_debug, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x74 = _fun_log_debug.clause;
        kk_box_t _x_x382;
        kk_string_t _x_x383;
        kk_define_string_literal(, _s_x384, 34, "Server is preparing for running...", _ctx)
        _x_x383 = kk_string_dup(_s_x384, _ctx); /*string*/
        _x_x382 = kk_string_box(_x_x383); /*1009*/
        _x_x379 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x74, (_fun_unbox_x74, m, ev_10069, _x_x382, _ctx), _ctx); /*1010*/
      }
    }
  }
  kk_unit_unbox(_x_x379);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x385 = kk_std_core_hnd_yield_extend(kk_hello_new_serve_fun386(_ctx), _ctx); /*3003*/
    kk_unit_unbox(_x_x385); return kk_Unit;
  }
  {
    kk_std_core_hnd__ev ev_0_10072 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/log>*/;
    kk_box_t _x_x389;
    {
      struct kk_std_core_hnd_Ev* _con_x390 = kk_std_core_hnd__as_Ev(ev_0_10072, _ctx);
      kk_box_t _box_x80 = _con_x390->hnd;
      int32_t m_0 = _con_x390->marker;
      kk_hello__log h_0 = kk_hello__log_unbox(_box_x80, KK_BORROWED, _ctx);
      kk_hello__log_dup(h_0, _ctx);
      {
        struct kk_hello__Hnd_log* _con_x391 = kk_hello__as_Hnd_log(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x391->_cfc;
        kk_std_core_hnd__clause1 _pat_1_2 = _con_x391->_fun_log_debug;
        kk_std_core_hnd__clause1 _fun_log_info = _con_x391->_fun_log_info;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_log_info, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x84 = _fun_log_info.clause;
          kk_box_t _x_x392;
          kk_string_t _x_x393;
          kk_define_string_literal(, _s_x394, 17, "Server is running", _ctx)
          _x_x393 = kk_string_dup(_s_x394, _ctx); /*string*/
          _x_x392 = kk_string_box(_x_x393); /*1009*/
          _x_x389 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x84, (_fun_unbox_x84, m_0, ev_0_10072, _x_x392, _ctx), _ctx); /*1010*/
        }
      }
    }
    kk_unit_unbox(_x_x389); return kk_Unit;
  }
}
 
// runtime tag for the effect `:throw-string`

kk_std_core_hnd__htag kk_hello__tag_throw_string;
 
// handler for the effect `:throw-string`

kk_box_t kk_hello__handle_throw_string(kk_hello__throw_string hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : throw-string<e,b>, ret : (res : a) -> e b, action : () -> <throw-string|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x397 = kk_std_core_hnd__htag_dup(kk_hello__tag_throw_string, _ctx); /*hnd/htag<hello/throw-string>*/
  return kk_std_core_hnd__hhandle(_x_x397, kk_hello__throw_string_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:get`

kk_std_core_hnd__htag kk_hello__tag_get;
 
// handler for the effect `:get`

kk_box_t kk_hello__handle_get(kk_hello__get hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e,c> (hnd : get<a,e,c>, ret : (res : b) -> e c, action : () -> <get<a>|e> b) -> e c */ 
  kk_std_core_hnd__htag _x_x403 = kk_std_core_hnd__htag_dup(kk_hello__tag_get, _ctx); /*forall<a> hnd/htag<hello/get<a>>*/
  return kk_std_core_hnd__hhandle(_x_x403, kk_hello__get_box(hnd, _ctx), ret, action, _ctx);
}

kk_integer_t kk_hello_safe_div(kk_integer_t m, kk_integer_t n, kk_context_t* _ctx) { /* (m : int, n : int) -> throw-string int */ 
  bool _match_x296 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x296) {
    kk_integer_drop(n, _ctx);
    kk_integer_drop(m, _ctx);
    kk_std_core_hnd__ev ev_10082 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/throw-string>*/;
    kk_box_t _x_x407;
    {
      struct kk_std_core_hnd_Ev* _con_x408 = kk_std_core_hnd__as_Ev(ev_10082, _ctx);
      kk_box_t _box_x114 = _con_x408->hnd;
      int32_t m_0 = _con_x408->marker;
      kk_hello__throw_string h = kk_hello__throw_string_unbox(_box_x114, KK_BORROWED, _ctx);
      kk_hello__throw_string_dup(h, _ctx);
      {
        struct kk_hello__Hnd_throw_string* _con_x409 = kk_hello__as_Hnd_throw_string(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x409->_cfc;
        kk_std_core_hnd__clause1 _ctl_throw_string = _con_x409->_ctl_throw_string;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_ctl_throw_string, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x118 = _ctl_throw_string.clause;
          kk_box_t _x_x410;
          kk_string_t _x_x411;
          kk_define_string_literal(, _s_x412, 13, "zero division", _ctx)
          _x_x411 = kk_string_dup(_s_x412, _ctx); /*string*/
          _x_x410 = kk_string_box(_x_x411); /*1009*/
          _x_x407 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x118, (_fun_unbox_x118, m_0, ev_10082, _x_x410, _ctx), _ctx); /*1010*/
        }
      }
    }
    return kk_integer_unbox(_x_x407, _ctx);
  }
  {
    return kk_integer_div(m,n,kk_context());
  }
}
 
// monadic lift

kk_unit_t kk_hello__mlift_report_get_mn_and_div_10041(kk_integer_t m, kk_integer_t n, kk_integer_t result, kk_context_t* _ctx) { /* (m : int, n : int, result : int) -> <throw-string,console/console,get<int>> () */ 
  kk_string_t _x_x413;
  kk_string_t _x_x414 = kk_std_core_int_show(m, _ctx); /*string*/
  kk_string_t _x_x415;
  kk_string_t _x_x416;
  kk_define_string_literal(, _s_x417, 3, " / ", _ctx)
  _x_x416 = kk_string_dup(_s_x417, _ctx); /*string*/
  kk_string_t _x_x418;
  kk_string_t _x_x419 = kk_std_core_int_show(n, _ctx); /*string*/
  kk_string_t _x_x420;
  kk_string_t _x_x421;
  kk_define_string_literal(, _s_x422, 3, " = ", _ctx)
  _x_x421 = kk_string_dup(_s_x422, _ctx); /*string*/
  kk_string_t _x_x423 = kk_std_core_int_show(result, _ctx); /*string*/
  _x_x420 = kk_std_core_types__lp__plus__plus__rp_(_x_x421, _x_x423, _ctx); /*string*/
  _x_x418 = kk_std_core_types__lp__plus__plus__rp_(_x_x419, _x_x420, _ctx); /*string*/
  _x_x415 = kk_std_core_types__lp__plus__plus__rp_(_x_x416, _x_x418, _ctx); /*string*/
  _x_x413 = kk_std_core_types__lp__plus__plus__rp_(_x_x414, _x_x415, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x413, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_hello__mlift_report_get_mn_and_div_10042_fun425__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello__mlift_report_get_mn_and_div_10042_fun425(kk_function_t _fself, kk_box_t _b_x126, kk_box_t _b_x127, kk_context_t* _ctx);
static kk_function_t kk_hello__new_mlift_report_get_mn_and_div_10042_fun425(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello__mlift_report_get_mn_and_div_10042_fun425, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello__mlift_report_get_mn_and_div_10042_fun425(kk_function_t _fself, kk_box_t _b_x126, kk_box_t _b_x127, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x_x426;
  kk_integer_t _x_x427 = kk_integer_unbox(_b_x126, _ctx); /*int*/
  kk_integer_t _x_x428 = kk_integer_unbox(_b_x127, _ctx); /*int*/
  _x_x426 = kk_hello_safe_div(_x_x427, _x_x428, _ctx); /*int*/
  return kk_integer_box(_x_x426, _ctx);
}


// lift anonymous function
struct kk_hello__mlift_report_get_mn_and_div_10042_fun434__t {
  struct kk_function_s _base;
  kk_integer_t m;
  kk_integer_t n;
};
static kk_box_t kk_hello__mlift_report_get_mn_and_div_10042_fun434(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_hello__new_mlift_report_get_mn_and_div_10042_fun434(kk_integer_t m, kk_integer_t n, kk_context_t* _ctx) {
  struct kk_hello__mlift_report_get_mn_and_div_10042_fun434__t* _self = kk_function_alloc_as(struct kk_hello__mlift_report_get_mn_and_div_10042_fun434__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello__mlift_report_get_mn_and_div_10042_fun434, kk_context());
  _self->m = m;
  _self->n = n;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello__mlift_report_get_mn_and_div_10042_fun434(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  struct kk_hello__mlift_report_get_mn_and_div_10042_fun434__t* _self = kk_function_as(struct kk_hello__mlift_report_get_mn_and_div_10042_fun434__t*, _fself, _ctx);
  kk_integer_t m = _self->m; /* int */
  kk_integer_t n = _self->n; /* int */
  kk_drop_match(_self, {kk_integer_dup(m, _ctx);kk_integer_dup(n, _ctx);}, {}, _ctx)
  kk_integer_t result_135 = kk_integer_unbox(_b_x133, _ctx); /*int*/;
  kk_unit_t _x_x435 = kk_Unit;
  kk_hello__mlift_report_get_mn_and_div_10041(m, n, result_135, _ctx);
  return kk_unit_box(_x_x435);
}

kk_unit_t kk_hello__mlift_report_get_mn_and_div_10042(kk_integer_t m, kk_integer_t n, kk_context_t* _ctx) { /* (m : int, n : int) -> <get<int>,console/console,throw-string> () */ 
  kk_ssize_t _b_x122_128 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_integer_t x_10085;
  kk_box_t _x_x424;
  kk_box_t _x_x429;
  kk_integer_t _x_x430 = kk_integer_dup(m, _ctx); /*int*/
  _x_x429 = kk_integer_box(_x_x430, _ctx); /*1000*/
  kk_box_t _x_x431;
  kk_integer_t _x_x432 = kk_integer_dup(n, _ctx); /*int*/
  _x_x431 = kk_integer_box(_x_x432, _ctx); /*1001*/
  _x_x424 = kk_std_core_hnd__open_at2(_b_x122_128, kk_hello__new_mlift_report_get_mn_and_div_10042_fun425(_ctx), _x_x429, _x_x431, _ctx); /*1002*/
  x_10085 = kk_integer_unbox(_x_x424, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10085, _ctx);
    kk_box_t _x_x433 = kk_std_core_hnd_yield_extend(kk_hello__new_mlift_report_get_mn_and_div_10042_fun434(m, n, _ctx), _ctx); /*3003*/
    kk_unit_unbox(_x_x433); return kk_Unit;
  }
  {
    kk_hello__mlift_report_get_mn_and_div_10041(m, n, x_10085, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_hello__mlift_report_get_mn_and_div_10043_fun439__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello__mlift_report_get_mn_and_div_10043_fun439(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello__new_mlift_report_get_mn_and_div_10043_fun439(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello__mlift_report_get_mn_and_div_10043_fun439, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello__mlift_report_get_mn_and_div_10043_fun439(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_hnd__ev ev_10089 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/get<int>>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x440 = kk_std_core_hnd__as_Ev(ev_10089, _ctx);
    kk_box_t _box_x136 = _con_x440->hnd;
    int32_t m_0 = _con_x440->marker;
    kk_hello__get h = kk_hello__get_unbox(_box_x136, KK_BORROWED, _ctx);
    kk_hello__get_dup(h, _ctx);
    {
      struct kk_hello__Hnd_get* _con_x441 = kk_hello__as_Hnd_get(h, _ctx);
      kk_integer_t _pat_0 = _con_x441->_cfc;
      kk_std_core_hnd__clause0 _ctl_get = _con_x441->_ctl_get;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_get, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x139 = _ctl_get.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x139, (_fun_unbox_x139, m_0, ev_10089, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_hello__mlift_report_get_mn_and_div_10043_fun443__t {
  struct kk_function_s _base;
  kk_integer_t m;
};
static kk_box_t kk_hello__mlift_report_get_mn_and_div_10043_fun443(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx);
static kk_function_t kk_hello__new_mlift_report_get_mn_and_div_10043_fun443(kk_integer_t m, kk_context_t* _ctx) {
  struct kk_hello__mlift_report_get_mn_and_div_10043_fun443__t* _self = kk_function_alloc_as(struct kk_hello__mlift_report_get_mn_and_div_10043_fun443__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello__mlift_report_get_mn_and_div_10043_fun443, kk_context());
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello__mlift_report_get_mn_and_div_10043_fun443(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx) {
  struct kk_hello__mlift_report_get_mn_and_div_10043_fun443__t* _self = kk_function_as(struct kk_hello__mlift_report_get_mn_and_div_10043_fun443__t*, _fself, _ctx);
  kk_integer_t m = _self->m; /* int */
  kk_drop_match(_self, {kk_integer_dup(m, _ctx);}, {}, _ctx)
  kk_integer_t n_149 = kk_integer_unbox(_b_x147, _ctx); /*int*/;
  kk_unit_t _x_x444 = kk_Unit;
  kk_hello__mlift_report_get_mn_and_div_10042(m, n_149, _ctx);
  return kk_unit_box(_x_x444);
}

kk_unit_t kk_hello__mlift_report_get_mn_and_div_10043(kk_integer_t m, kk_context_t* _ctx) { /* (m : int) -> <get<int>,console/console,throw-string> () */ 
  kk_unit_t ___0 = kk_Unit;
  kk_string_t _x_x436;
  kk_define_string_literal(, _s_x437, 13, "`get` for `n`", _ctx)
  _x_x436 = kk_string_dup(_s_x437, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x436, _ctx);
  kk_ssize_t _b_x142_144 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10087;
  kk_box_t _x_x438 = kk_std_core_hnd__open_at0(_b_x142_144, kk_hello__new_mlift_report_get_mn_and_div_10043_fun439(_ctx), _ctx); /*1000*/
  x_10087 = kk_integer_unbox(_x_x438, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10087, _ctx);
    kk_box_t _x_x442 = kk_std_core_hnd_yield_extend(kk_hello__new_mlift_report_get_mn_and_div_10043_fun443(m, _ctx), _ctx); /*3003*/
    kk_unit_unbox(_x_x442); return kk_Unit;
  }
  {
    kk_hello__mlift_report_get_mn_and_div_10042(m, x_10087, _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_hello_report_get_mn_and_div_fun448__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_report_get_mn_and_div_fun448(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_report_get_mn_and_div_fun448(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_report_get_mn_and_div_fun448, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_report_get_mn_and_div_fun448(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_hnd__ev ev_10094 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/get<int>>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x449 = kk_std_core_hnd__as_Ev(ev_10094, _ctx);
    kk_box_t _box_x150 = _con_x449->hnd;
    int32_t m = _con_x449->marker;
    kk_hello__get h = kk_hello__get_unbox(_box_x150, KK_BORROWED, _ctx);
    kk_hello__get_dup(h, _ctx);
    {
      struct kk_hello__Hnd_get* _con_x450 = kk_hello__as_Hnd_get(h, _ctx);
      kk_integer_t _pat_0 = _con_x450->_cfc;
      kk_std_core_hnd__clause0 _ctl_get = _con_x450->_ctl_get;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_get, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x153 = _ctl_get.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x153, (_fun_unbox_x153, m, ev_10094, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_hello_report_get_mn_and_div_fun452__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_report_get_mn_and_div_fun452(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_hello_new_report_get_mn_and_div_fun452(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_report_get_mn_and_div_fun452, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_report_get_mn_and_div_fun452(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_unit_t _x_x453 = kk_Unit;
  kk_integer_t _x_x454 = kk_integer_unbox(_b_x161, _ctx); /*int*/
  kk_hello__mlift_report_get_mn_and_div_10043(_x_x454, _ctx);
  return kk_unit_box(_x_x453);
}


// lift anonymous function
struct kk_hello_report_get_mn_and_div_fun458__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_report_get_mn_and_div_fun458(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_report_get_mn_and_div_fun458(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_report_get_mn_and_div_fun458, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_report_get_mn_and_div_fun458(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_hnd__ev ev_0_10099 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<hello/get<int>>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x459 = kk_std_core_hnd__as_Ev(ev_0_10099, _ctx);
    kk_box_t _box_x162 = _con_x459->hnd;
    int32_t m_1 = _con_x459->marker;
    kk_hello__get h_0 = kk_hello__get_unbox(_box_x162, KK_BORROWED, _ctx);
    kk_hello__get_dup(h_0, _ctx);
    {
      struct kk_hello__Hnd_get* _con_x460 = kk_hello__as_Hnd_get(h_0, _ctx);
      kk_integer_t _pat_0_3 = _con_x460->_cfc;
      kk_std_core_hnd__clause0 _ctl_get_0 = _con_x460->_ctl_get;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_integer_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_get_0, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x165 = _ctl_get_0.clause;
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x165, (_fun_unbox_x165, m_1, ev_0_10099, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_hello_report_get_mn_and_div_fun462__t {
  struct kk_function_s _base;
  kk_integer_t x_10091;
};
static kk_box_t kk_hello_report_get_mn_and_div_fun462(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_hello_new_report_get_mn_and_div_fun462(kk_integer_t x_10091, kk_context_t* _ctx) {
  struct kk_hello_report_get_mn_and_div_fun462__t* _self = kk_function_alloc_as(struct kk_hello_report_get_mn_and_div_fun462__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_report_get_mn_and_div_fun462, kk_context());
  _self->x_10091 = x_10091;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_report_get_mn_and_div_fun462(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx) {
  struct kk_hello_report_get_mn_and_div_fun462__t* _self = kk_function_as(struct kk_hello_report_get_mn_and_div_fun462__t*, _fself, _ctx);
  kk_integer_t x_10091 = _self->x_10091; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_10091, _ctx);}, {}, _ctx)
  kk_integer_t n_189 = kk_integer_unbox(_b_x173, _ctx); /*int*/;
  kk_unit_t _x_x463 = kk_Unit;
  kk_hello__mlift_report_get_mn_and_div_10042(x_10091, n_189, _ctx);
  return kk_unit_box(_x_x463);
}


// lift anonymous function
struct kk_hello_report_get_mn_and_div_fun465__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_report_get_mn_and_div_fun465(kk_function_t _fself, kk_box_t _b_x178, kk_box_t _b_x179, kk_context_t* _ctx);
static kk_function_t kk_hello_new_report_get_mn_and_div_fun465(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_report_get_mn_and_div_fun465, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_report_get_mn_and_div_fun465(kk_function_t _fself, kk_box_t _b_x178, kk_box_t _b_x179, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_integer_t _x_x466;
  kk_integer_t _x_x467 = kk_integer_unbox(_b_x178, _ctx); /*int*/
  kk_integer_t _x_x468 = kk_integer_unbox(_b_x179, _ctx); /*int*/
  _x_x466 = kk_hello_safe_div(_x_x467, _x_x468, _ctx); /*int*/
  return kk_integer_box(_x_x466, _ctx);
}


// lift anonymous function
struct kk_hello_report_get_mn_and_div_fun474__t {
  struct kk_function_s _base;
  kk_integer_t x_0_10096;
  kk_integer_t x_10091;
};
static kk_box_t kk_hello_report_get_mn_and_div_fun474(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx);
static kk_function_t kk_hello_new_report_get_mn_and_div_fun474(kk_integer_t x_0_10096, kk_integer_t x_10091, kk_context_t* _ctx) {
  struct kk_hello_report_get_mn_and_div_fun474__t* _self = kk_function_alloc_as(struct kk_hello_report_get_mn_and_div_fun474__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_report_get_mn_and_div_fun474, kk_context());
  _self->x_0_10096 = x_0_10096;
  _self->x_10091 = x_10091;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_report_get_mn_and_div_fun474(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx) {
  struct kk_hello_report_get_mn_and_div_fun474__t* _self = kk_function_as(struct kk_hello_report_get_mn_and_div_fun474__t*, _fself, _ctx);
  kk_integer_t x_0_10096 = _self->x_0_10096; /* int */
  kk_integer_t x_10091 = _self->x_10091; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_0_10096, _ctx);kk_integer_dup(x_10091, _ctx);}, {}, _ctx)
  kk_integer_t result_190 = kk_integer_unbox(_b_x185, _ctx); /*int*/;
  kk_unit_t _x_x475 = kk_Unit;
  kk_hello__mlift_report_get_mn_and_div_10041(x_10091, x_0_10096, result_190, _ctx);
  return kk_unit_box(_x_x475);
}

kk_unit_t kk_hello_report_get_mn_and_div(kk_context_t* _ctx) { /* () -> <console/console,get<int>,throw-string> () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x445;
  kk_define_string_literal(, _s_x446, 13, "`get` for `m`", _ctx)
  _x_x445 = kk_string_dup(_s_x446, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x445, _ctx);
  kk_ssize_t _b_x156_158 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_integer_t x_10091;
  kk_box_t _x_x447 = kk_std_core_hnd__open_at0(_b_x156_158, kk_hello_new_report_get_mn_and_div_fun448(_ctx), _ctx); /*1000*/
  x_10091 = kk_integer_unbox(_x_x447, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10091, _ctx);
    kk_box_t _x_x451 = kk_std_core_hnd_yield_extend(kk_hello_new_report_get_mn_and_div_fun452(_ctx), _ctx); /*3003*/
    kk_unit_unbox(_x_x451); return kk_Unit;
  }
  {
    kk_unit_t ___0 = kk_Unit;
    kk_string_t _x_x455;
    kk_define_string_literal(, _s_x456, 13, "`get` for `n`", _ctx)
    _x_x455 = kk_string_dup(_s_x456, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x455, _ctx);
    kk_ssize_t _b_x168_170 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_integer_t x_0_10096;
    kk_box_t _x_x457 = kk_std_core_hnd__open_at0(_b_x168_170, kk_hello_new_report_get_mn_and_div_fun458(_ctx), _ctx); /*1000*/
    x_0_10096 = kk_integer_unbox(_x_x457, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10096, _ctx);
      kk_box_t _x_x461 = kk_std_core_hnd_yield_extend(kk_hello_new_report_get_mn_and_div_fun462(x_10091, _ctx), _ctx); /*3003*/
      kk_unit_unbox(_x_x461); return kk_Unit;
    }
    {
      kk_ssize_t _b_x174_180 = (KK_IZ(1)); /*hnd/ev-index*/;
      kk_integer_t x_1_10101;
      kk_box_t _x_x464;
      kk_box_t _x_x469;
      kk_integer_t _x_x470 = kk_integer_dup(x_10091, _ctx); /*int*/
      _x_x469 = kk_integer_box(_x_x470, _ctx); /*1000*/
      kk_box_t _x_x471;
      kk_integer_t _x_x472 = kk_integer_dup(x_0_10096, _ctx); /*int*/
      _x_x471 = kk_integer_box(_x_x472, _ctx); /*1001*/
      _x_x464 = kk_std_core_hnd__open_at2(_b_x174_180, kk_hello_new_report_get_mn_and_div_fun465(_ctx), _x_x469, _x_x471, _ctx); /*1002*/
      x_1_10101 = kk_integer_unbox(_x_x464, _ctx); /*int*/
      if (kk_yielding(kk_context())) {
        kk_integer_drop(x_1_10101, _ctx);
        kk_box_t _x_x473 = kk_std_core_hnd_yield_extend(kk_hello_new_report_get_mn_and_div_fun474(x_0_10096, x_10091, _ctx), _ctx); /*3003*/
        kk_unit_unbox(_x_x473); return kk_Unit;
      }
      {
        kk_string_t _x_x476;
        kk_string_t _x_x477 = kk_std_core_int_show(x_10091, _ctx); /*string*/
        kk_string_t _x_x478;
        kk_string_t _x_x479;
        kk_define_string_literal(, _s_x480, 3, " / ", _ctx)
        _x_x479 = kk_string_dup(_s_x480, _ctx); /*string*/
        kk_string_t _x_x481;
        kk_string_t _x_x482 = kk_std_core_int_show(x_0_10096, _ctx); /*string*/
        kk_string_t _x_x483;
        kk_string_t _x_x484;
        kk_define_string_literal(, _s_x485, 3, " = ", _ctx)
        _x_x484 = kk_string_dup(_s_x485, _ctx); /*string*/
        kk_string_t _x_x486 = kk_std_core_int_show(x_1_10101, _ctx); /*string*/
        _x_x483 = kk_std_core_types__lp__plus__plus__rp_(_x_x484, _x_x486, _ctx); /*string*/
        _x_x481 = kk_std_core_types__lp__plus__plus__rp_(_x_x482, _x_x483, _ctx); /*string*/
        _x_x478 = kk_std_core_types__lp__plus__plus__rp_(_x_x479, _x_x481, _ctx); /*string*/
        _x_x476 = kk_std_core_types__lp__plus__plus__rp_(_x_x477, _x_x478, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x476, _ctx); return kk_Unit;
      }
    }
  }
}


// lift anonymous function
struct kk_hello_to_maybe_fun488__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_to_maybe_fun488(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x623__16, kk_string_t x, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun488(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_to_maybe_fun488, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_hello_to_maybe_fun489__t {
  struct kk_function_s _base;
  kk_string_t x;
};
static kk_box_t kk_hello_to_maybe_fun489(kk_function_t _fself, kk_function_t _b_x200, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun489(kk_string_t x, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun489__t* _self = kk_function_alloc_as(struct kk_hello_to_maybe_fun489__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_to_maybe_fun489, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_hello_to_maybe_fun490__t {
  struct kk_function_s _base;
  kk_function_t _b_x200;
};
static kk_std_core_types__maybe kk_hello_to_maybe_fun490(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x201, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun490(kk_function_t _b_x200, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun490__t* _self = kk_function_alloc_as(struct kk_hello_to_maybe_fun490__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_to_maybe_fun490, kk_context());
  _self->_b_x200 = _b_x200;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_hello_to_maybe_fun490(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x201, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun490__t* _self = kk_function_as(struct kk_hello_to_maybe_fun490__t*, _fself, _ctx);
  kk_function_t _b_x200 = _self->_b_x200; /* (hnd/resume-result<3775,3777>) -> 3776 3777 */
  kk_drop_match(_self, {kk_function_dup(_b_x200, _ctx);}, {}, _ctx)
  kk_box_t _x_x491 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x200, (_b_x200, _b_x201, _ctx), _ctx); /*3777*/
  return kk_std_core_types__maybe_unbox(_x_x491, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_hello_to_maybe_fun492__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_hello_to_maybe_fun492(kk_function_t _fself, kk_string_t msg, kk_function_t resume, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun492(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_to_maybe_fun492, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_hello_to_maybe_fun492(kk_function_t _fself, kk_string_t msg, kk_function_t resume, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_function_drop(resume, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_std_core_console_printsln(msg, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}


// lift anonymous function
struct kk_hello_to_maybe_fun493__t {
  struct kk_function_s _base;
  kk_function_t _b_x192_217;
};
static kk_box_t kk_hello_to_maybe_fun493(kk_function_t _fself, kk_box_t _b_x194, kk_function_t _b_x195, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun493(kk_function_t _b_x192_217, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun493__t* _self = kk_function_alloc_as(struct kk_hello_to_maybe_fun493__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_to_maybe_fun493, kk_context());
  _self->_b_x192_217 = _b_x192_217;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_hello_to_maybe_fun496__t {
  struct kk_function_s _base;
  kk_function_t _b_x195;
};
static kk_std_core_types__maybe kk_hello_to_maybe_fun496(kk_function_t _fself, kk_box_t _b_x196, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun496(kk_function_t _b_x195, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun496__t* _self = kk_function_alloc_as(struct kk_hello_to_maybe_fun496__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_to_maybe_fun496, kk_context());
  _self->_b_x195 = _b_x195;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_hello_to_maybe_fun496(kk_function_t _fself, kk_box_t _b_x196, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun496__t* _self = kk_function_as(struct kk_hello_to_maybe_fun496__t*, _fself, _ctx);
  kk_function_t _b_x195 = _self->_b_x195; /* (3776) -> 3777 3778 */
  kk_drop_match(_self, {kk_function_dup(_b_x195, _ctx);}, {}, _ctx)
  kk_box_t _x_x497 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x195, (_b_x195, _b_x196, _ctx), _ctx); /*3778*/
  return kk_std_core_types__maybe_unbox(_x_x497, KK_OWNED, _ctx);
}
static kk_box_t kk_hello_to_maybe_fun493(kk_function_t _fself, kk_box_t _b_x194, kk_function_t _b_x195, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun493__t* _self = kk_function_as(struct kk_hello_to_maybe_fun493__t*, _fself, _ctx);
  kk_function_t _b_x192_217 = _self->_b_x192_217; /* (msg : string, resume : (1754) -> console/console maybe<1775>) -> console/console maybe<1775> */
  kk_drop_match(_self, {kk_function_dup(_b_x192_217, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x494;
  kk_string_t _x_x495 = kk_string_unbox(_b_x194); /*string*/
  _x_x494 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_string_t, kk_function_t, kk_context_t*), _b_x192_217, (_b_x192_217, _x_x495, kk_hello_new_to_maybe_fun496(_b_x195, _ctx), _ctx), _ctx); /*maybe<1775>*/
  return kk_std_core_types__maybe_box(_x_x494, _ctx);
}


// lift anonymous function
struct kk_hello_to_maybe_fun498__t {
  struct kk_function_s _base;
  kk_function_t _b_x193_218;
};
static kk_box_t kk_hello_to_maybe_fun498(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x197, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun498(kk_function_t _b_x193_218, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun498__t* _self = kk_function_alloc_as(struct kk_hello_to_maybe_fun498__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_to_maybe_fun498, kk_context());
  _self->_b_x193_218 = _b_x193_218;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_to_maybe_fun498(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x197, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun498__t* _self = kk_function_as(struct kk_hello_to_maybe_fun498__t*, _fself, _ctx);
  kk_function_t _b_x193_218 = _self->_b_x193_218; /* (hnd/resume-result<1754,maybe<1775>>) -> console/console maybe<1775> */
  kk_drop_match(_self, {kk_function_dup(_b_x193_218, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x499 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x193_218, (_b_x193_218, _b_x197, _ctx), _ctx); /*maybe<1775>*/
  return kk_std_core_types__maybe_box(_x_x499, _ctx);
}
static kk_box_t kk_hello_to_maybe_fun489(kk_function_t _fself, kk_function_t _b_x200, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun489__t* _self = kk_function_as(struct kk_hello_to_maybe_fun489__t*, _fself, _ctx);
  kk_string_t x = _self->x; /* string */
  kk_drop_match(_self, {kk_string_dup(x, _ctx);}, {}, _ctx)
  kk_function_t k_219 = kk_hello_new_to_maybe_fun490(_b_x200, _ctx); /*(hnd/resume-result<1754,maybe<1775>>) -> console/console maybe<1775>*/;
  kk_string_t _b_x191_216 = x; /*string*/;
  kk_function_t _b_x192_217 = kk_hello_new_to_maybe_fun492(_ctx); /*(msg : string, resume : (1754) -> console/console maybe<1775>) -> console/console maybe<1775>*/;
  kk_function_t _b_x193_218 = k_219; /*(hnd/resume-result<1754,maybe<1775>>) -> console/console maybe<1775>*/;
  return kk_std_core_hnd_protect(kk_string_box(_b_x191_216), kk_hello_new_to_maybe_fun493(_b_x192_217, _ctx), kk_hello_new_to_maybe_fun498(_b_x193_218, _ctx), _ctx);
}
static kk_box_t kk_hello_to_maybe_fun488(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x623__16, kk_string_t x, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_datatype_ptr_dropn(___wildcard_x623__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_hello_new_to_maybe_fun489(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_hello_to_maybe_fun502__t {
  struct kk_function_s _base;
  kk_function_t _b_x202_213;
};
static kk_box_t kk_hello_to_maybe_fun502(kk_function_t _fself, int32_t _b_x203, kk_std_core_hnd__ev _b_x204, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun502(kk_function_t _b_x202_213, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun502__t* _self = kk_function_alloc_as(struct kk_hello_to_maybe_fun502__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_to_maybe_fun502, kk_context());
  _self->_b_x202_213 = _b_x202_213;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_to_maybe_fun502(kk_function_t _fself, int32_t _b_x203, kk_std_core_hnd__ev _b_x204, kk_box_t _b_x205, kk_context_t* _ctx) {
  struct kk_hello_to_maybe_fun502__t* _self = kk_function_as(struct kk_hello_to_maybe_fun502__t*, _fself, _ctx);
  kk_function_t _b_x202_213 = _self->_b_x202_213; /* (m : hnd/marker<console/console,maybe<1775>>, hnd/ev<hello/throw-string>, x : string) -> console/console 1754 */
  kk_drop_match(_self, {kk_function_dup(_b_x202_213, _ctx);}, {}, _ctx)
  kk_string_t _x_x503 = kk_string_unbox(_b_x205); /*string*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_string_t, kk_context_t*), _b_x202_213, (_b_x202_213, _b_x203, _b_x204, _x_x503, _ctx), _ctx);
}


// lift anonymous function
struct kk_hello_to_maybe_fun504__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_to_maybe_fun504(kk_function_t _fself, kk_box_t _b_x209, kk_context_t* _ctx);
static kk_function_t kk_hello_new_to_maybe_fun504(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_to_maybe_fun504, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_to_maybe_fun504(kk_function_t _fself, kk_box_t _b_x209, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_box_t x_0_220 = _b_x209; /*1775*/;
  kk_std_core_types__maybe _x_x505 = kk_std_core_types__new_Just(x_0_220, _ctx); /*maybe<3788>*/
  return kk_std_core_types__maybe_box(_x_x505, _ctx);
}

kk_std_core_types__maybe kk_hello_to_maybe(kk_function_t action, kk_context_t* _ctx) { /* forall<a> (action : () -> <throw-string,console/console> a) -> console/console maybe<a> */ 
  kk_box_t _x_x487;
  kk_function_t _b_x202_213 = kk_hello_new_to_maybe_fun488(_ctx); /*(m : hnd/marker<console/console,maybe<1775>>, hnd/ev<hello/throw-string>, x : string) -> console/console 1754*/;
  kk_hello__throw_string _x_x500;
  kk_std_core_hnd__clause1 _x_x501 = kk_std_core_hnd__new_Clause1(kk_hello_new_to_maybe_fun502(_b_x202_213, _ctx), _ctx); /*hnd/clause1<1015,1016,1017,1018,1019>*/
  _x_x500 = kk_hello__new_Hnd_throw_string(kk_reuse_null, 0, kk_integer_from_small(3), _x_x501, _ctx); /*hello/throw-string<38,39>*/
  _x_x487 = kk_hello__handle_throw_string(_x_x500, kk_hello_new_to_maybe_fun504(_ctx), action, _ctx); /*1063*/
  return kk_std_core_types__maybe_unbox(_x_x487, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun507__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_hello_use_get_and_div_fun507(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x672__16, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun507(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun507, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun509__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_use_get_and_div_fun509(kk_function_t _fself, kk_function_t _b_x230, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun509(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun509, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun510__t {
  struct kk_function_s _base;
  kk_function_t _b_x230;
};
static kk_std_core_types__list kk_hello_use_get_and_div_fun510(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x231, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun510(kk_function_t _b_x230, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun510__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun510__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun510, kk_context());
  _self->_b_x230 = _b_x230;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__list kk_hello_use_get_and_div_fun510(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x231, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun510__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun510__t*, _fself, _ctx);
  kk_function_t _b_x230 = _self->_b_x230; /* (hnd/resume-result<3003,3005>) -> 3004 3005 */
  kk_drop_match(_self, {kk_function_dup(_b_x230, _ctx);}, {}, _ctx)
  kk_box_t _x_x511 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x230, (_b_x230, _b_x231, _ctx), _ctx); /*3005*/
  return kk_std_core_types__list_unbox(_x_x511, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun512__t {
  struct kk_function_s _base;
};
static kk_std_core_types__list kk_hello_use_get_and_div_fun512(kk_function_t _fself, kk_unit_t ___wildcard_x672__55, kk_function_t r, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun512(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun512, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_std_core_types__list kk_hello_use_get_and_div_fun512(kk_function_t _fself, kk_unit_t ___wildcard_x672__55, kk_function_t r, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__list xs_10008;
  kk_function_t _x_x513 = kk_function_dup(r, _ctx); /*(int) -> console/console list<()>*/
  xs_10008 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_integer_t, kk_context_t*), _x_x513, (_x_x513, kk_integer_from_small(1), _ctx), _ctx); /*list<()>*/
  kk_std_core_types__list ys_10009 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_integer_t, kk_context_t*), r, (r, kk_integer_from_small(0), _ctx), _ctx); /*list<()>*/;
  return kk_std_core_list_append(xs_10008, ys_10009, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun514__t {
  struct kk_function_s _base;
  kk_function_t _b_x222_267;
};
static kk_box_t kk_hello_use_get_and_div_fun514(kk_function_t _fself, kk_box_t _b_x224, kk_function_t _b_x225, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun514(kk_function_t _b_x222_267, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun514__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun514__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun514, kk_context());
  _self->_b_x222_267 = _b_x222_267;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun517__t {
  struct kk_function_s _base;
  kk_function_t _b_x225;
};
static kk_std_core_types__list kk_hello_use_get_and_div_fun517(kk_function_t _fself, kk_integer_t _b_x226, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun517(kk_function_t _b_x225, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun517__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun517__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun517, kk_context());
  _self->_b_x225 = _b_x225;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__list kk_hello_use_get_and_div_fun517(kk_function_t _fself, kk_integer_t _b_x226, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun517__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun517__t*, _fself, _ctx);
  kk_function_t _b_x225 = _self->_b_x225; /* (3004) -> 3005 3006 */
  kk_drop_match(_self, {kk_function_dup(_b_x225, _ctx);}, {}, _ctx)
  kk_box_t _x_x518 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x225, (_b_x225, kk_integer_box(_b_x226, _ctx), _ctx), _ctx); /*3006*/
  return kk_std_core_types__list_unbox(_x_x518, KK_OWNED, _ctx);
}
static kk_box_t kk_hello_use_get_and_div_fun514(kk_function_t _fself, kk_box_t _b_x224, kk_function_t _b_x225, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun514__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun514__t*, _fself, _ctx);
  kk_function_t _b_x222_267 = _self->_b_x222_267; /* ((), r : (int) -> console/console list<()>) -> console/console list<()> */
  kk_drop_match(_self, {kk_function_dup(_b_x222_267, _ctx);}, {}, _ctx)
  kk_std_core_types__list _x_x515;
  kk_unit_t _x_x516 = kk_Unit;
  kk_unit_unbox(_b_x224);
  _x_x515 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_unit_t, kk_function_t, kk_context_t*), _b_x222_267, (_b_x222_267, _x_x516, kk_hello_new_use_get_and_div_fun517(_b_x225, _ctx), _ctx), _ctx); /*list<()>*/
  return kk_std_core_types__list_box(_x_x515, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun519__t {
  struct kk_function_s _base;
  kk_function_t _b_x223_268;
};
static kk_box_t kk_hello_use_get_and_div_fun519(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x227, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun519(kk_function_t _b_x223_268, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun519__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun519__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun519, kk_context());
  _self->_b_x223_268 = _b_x223_268;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_use_get_and_div_fun519(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x227, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun519__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun519__t*, _fself, _ctx);
  kk_function_t _b_x223_268 = _self->_b_x223_268; /* (hnd/resume-result<int,list<()>>) -> console/console list<()> */
  kk_drop_match(_self, {kk_function_dup(_b_x223_268, _ctx);}, {}, _ctx)
  kk_std_core_types__list _x_x520 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x223_268, (_b_x223_268, _b_x227, _ctx), _ctx); /*list<()>*/
  return kk_std_core_types__list_box(_x_x520, _ctx);
}
static kk_box_t kk_hello_use_get_and_div_fun509(kk_function_t _fself, kk_function_t _b_x230, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_function_t k_280 = kk_hello_new_use_get_and_div_fun510(_b_x230, _ctx); /*(hnd/resume-result<int,list<()>>) -> console/console list<()>*/;
  kk_unit_t _b_x221_266 = kk_Unit;
  kk_function_t _b_x222_267 = kk_hello_new_use_get_and_div_fun512(_ctx); /*((), r : (int) -> console/console list<()>) -> console/console list<()>*/;
  kk_function_t _b_x223_268 = k_280; /*(hnd/resume-result<int,list<()>>) -> console/console list<()>*/;
  return kk_std_core_hnd_protect(kk_unit_box(_b_x221_266), kk_hello_new_use_get_and_div_fun514(_b_x222_267, _ctx), kk_hello_new_use_get_and_div_fun519(_b_x223_268, _ctx), _ctx);
}
static kk_integer_t kk_hello_use_get_and_div_fun507(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x672__16, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_datatype_ptr_dropn(___wildcard_x672__16, (KK_I32(3)), _ctx);
  kk_box_t _x_x508 = kk_std_core_hnd_yield_to(m, kk_hello_new_use_get_and_div_fun509(_ctx), _ctx); /*3003*/
  return kk_integer_unbox(_x_x508, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun523__t {
  struct kk_function_s _base;
  kk_function_t _b_x232_263;
};
static kk_box_t kk_hello_use_get_and_div_fun523(kk_function_t _fself, int32_t _b_x233, kk_std_core_hnd__ev _b_x234, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun523(kk_function_t _b_x232_263, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun523__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun523__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun523, kk_context());
  _self->_b_x232_263 = _b_x232_263;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_use_get_and_div_fun523(kk_function_t _fself, int32_t _b_x233, kk_std_core_hnd__ev _b_x234, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun523__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun523__t*, _fself, _ctx);
  kk_function_t _b_x232_263 = _self->_b_x232_263; /* (m : hnd/marker<console/console,list<()>>, hnd/ev<hello/get<int>>) -> console/console int */
  kk_drop_match(_self, {kk_function_dup(_b_x232_263, _ctx);}, {}, _ctx)
  kk_integer_t _x_x524 = kk_function_call(kk_integer_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _b_x232_263, (_b_x232_263, _b_x233, _b_x234, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x524, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun525__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_use_get_and_div_fun525(kk_function_t _fself, kk_box_t _b_x259, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun525(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun525, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_hello_use_get_and_div_fun525(kk_function_t _fself, kk_box_t _b_x259, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_unit_t x_281 = kk_Unit;
  kk_unit_unbox(_b_x259);
  kk_unit_t _b_x235_269 = kk_Unit;
  x_281;
  kk_std_core_types__list _b_x236_270 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
  kk_std_core_types__list _x_x526 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x235_269), _b_x236_270, _ctx); /*list<1024>*/
  return kk_std_core_types__list_box(_x_x526, _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun527__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_use_get_and_div_fun527(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun527(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun527, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun529__t {
  struct kk_function_s _base;
};
static kk_box_t kk_hello_use_get_and_div_fun529(kk_function_t _fself, int32_t _b_x249, kk_std_core_hnd__ev _b_x250, kk_box_t _b_x251, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun529(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun529, _ctx)
  return kk_function_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun530__t {
  struct kk_function_s _base;
  kk_string_t x_0_285;
};
static kk_box_t kk_hello_use_get_and_div_fun530(kk_function_t _fself, kk_function_t _b_x246, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun530(kk_string_t x_0_285, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun530__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun530__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun530, kk_context());
  _self->x_0_285 = x_0_285;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun531__t {
  struct kk_function_s _base;
  kk_function_t _b_x246;
};
static kk_unit_t kk_hello_use_get_and_div_fun531(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x247, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun531(kk_function_t _b_x246, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun531__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun531__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun531, kk_context());
  _self->_b_x246 = _b_x246;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_hello_use_get_and_div_fun531(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x247, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun531__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun531__t*, _fself, _ctx);
  kk_function_t _b_x246 = _self->_b_x246; /* (hnd/resume-result<3994,3996>) -> 3995 3996 */
  kk_drop_match(_self, {kk_function_dup(_b_x246, _ctx);}, {}, _ctx)
  kk_box_t _x_x532 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x246, (_b_x246, _b_x247, _ctx), _ctx); /*3996*/
  kk_unit_unbox(_x_x532); return kk_Unit;
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun533__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_hello_use_get_and_div_fun533(kk_function_t _fself, kk_string_t msg, kk_function_t resume_0, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun533, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_unit_t kk_hello_use_get_and_div_fun533(kk_function_t _fself, kk_string_t msg, kk_function_t resume_0, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_function_drop(resume_0, _ctx);
  kk_string_t _x_x534;
  kk_string_t _x_x535;
  kk_define_string_literal(, _s_x536, 7, "Fatal: ", _ctx)
  _x_x535 = kk_string_dup(_s_x536, _ctx); /*string*/
  _x_x534 = kk_std_core_types__lp__plus__plus__rp_(_x_x535, msg, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x534, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun537__t {
  struct kk_function_s _base;
  kk_function_t _b_x238_278;
};
static kk_box_t kk_hello_use_get_and_div_fun537(kk_function_t _fself, kk_box_t _b_x240, kk_function_t _b_x241, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun537(kk_function_t _b_x238_278, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun537__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun537__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun537, kk_context());
  _self->_b_x238_278 = _b_x238_278;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_hello_use_get_and_div_fun540__t {
  struct kk_function_s _base;
  kk_function_t _b_x241;
};
static kk_unit_t kk_hello_use_get_and_div_fun540(kk_function_t _fself, kk_box_t _b_x242, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun540(kk_function_t _b_x241, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun540__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun540__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun540, kk_context());
  _self->_b_x241 = _b_x241;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_hello_use_get_and_div_fun540(kk_function_t _fself, kk_box_t _b_x242, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun540__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun540__t*, _fself, _ctx);
  kk_function_t _b_x241 = _self->_b_x241; /* (3995) -> 3996 3997 */
  kk_drop_match(_self, {kk_function_dup(_b_x241, _ctx);}, {}, _ctx)
  kk_box_t _x_x541 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x241, (_b_x241, _b_x242, _ctx), _ctx); /*3997*/
  kk_unit_unbox(_x_x541); return kk_Unit;
}
static kk_box_t kk_hello_use_get_and_div_fun537(kk_function_t _fself, kk_box_t _b_x240, kk_function_t _b_x241, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun537__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun537__t*, _fself, _ctx);
  kk_function_t _b_x238_278 = _self->_b_x238_278; /* (msg : string, resume@0 : (1994) -> <console/console,hello/get<int>> ()) -> <console/console,hello/get<int>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x238_278, _ctx);}, {}, _ctx)
  kk_unit_t _x_x538 = kk_Unit;
  kk_string_t _x_x539 = kk_string_unbox(_b_x240); /*string*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_string_t, kk_function_t, kk_context_t*), _b_x238_278, (_b_x238_278, _x_x539, kk_hello_new_use_get_and_div_fun540(_b_x241, _ctx), _ctx), _ctx);
  return kk_unit_box(_x_x538);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun542__t {
  struct kk_function_s _base;
  kk_function_t _b_x239_279;
};
static kk_box_t kk_hello_use_get_and_div_fun542(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x243, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun542(kk_function_t _b_x239_279, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun542__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun542__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun542, kk_context());
  _self->_b_x239_279 = _b_x239_279;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_use_get_and_div_fun542(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x243, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun542__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun542__t*, _fself, _ctx);
  kk_function_t _b_x239_279 = _self->_b_x239_279; /* (hnd/resume-result<1994,()>) -> <console/console,hello/get<int>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x239_279, _ctx);}, {}, _ctx)
  kk_unit_t _x_x543 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x239_279, (_b_x239_279, _b_x243, _ctx), _ctx);
  return kk_unit_box(_x_x543);
}
static kk_box_t kk_hello_use_get_and_div_fun530(kk_function_t _fself, kk_function_t _b_x246, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun530__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun530__t*, _fself, _ctx);
  kk_string_t x_0_285 = _self->x_0_285; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_285, _ctx);}, {}, _ctx)
  kk_function_t k_0_282 = kk_hello_new_use_get_and_div_fun531(_b_x246, _ctx); /*(hnd/resume-result<1994,()>) -> <console/console,hello/get<int>> ()*/;
  kk_string_t _b_x237_277 = x_0_285; /*string*/;
  kk_function_t _b_x238_278 = kk_hello_new_use_get_and_div_fun533(_ctx); /*(msg : string, resume@0 : (1994) -> <console/console,hello/get<int>> ()) -> <console/console,hello/get<int>> ()*/;
  kk_function_t _b_x239_279 = k_0_282; /*(hnd/resume-result<1994,()>) -> <console/console,hello/get<int>> ()*/;
  return kk_std_core_hnd_protect(kk_string_box(_b_x237_277), kk_hello_new_use_get_and_div_fun537(_b_x238_278, _ctx), kk_hello_new_use_get_and_div_fun542(_b_x239_279, _ctx), _ctx);
}
static kk_box_t kk_hello_use_get_and_div_fun529(kk_function_t _fself, int32_t _b_x249, kk_std_core_hnd__ev _b_x250, kk_box_t _b_x251, kk_context_t* _ctx) {
  kk_unused(_fself);
  int32_t m_0_283 = _b_x249; /*hnd/marker<<console/console,hello/get<int>>,()>*/;
  kk_std_core_hnd__ev ___wildcard_x623__16_284 = _b_x250; /*hnd/ev<hello/throw-string>*/;
  kk_datatype_ptr_dropn(___wildcard_x623__16_284, (KK_I32(3)), _ctx);
  kk_string_t x_0_285 = kk_string_unbox(_b_x251); /*string*/;
  return kk_std_core_hnd_yield_to(m_0_283, kk_hello_new_use_get_and_div_fun530(x_0_285, _ctx), _ctx);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun544__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_hello_use_get_and_div_fun544(kk_function_t _fself, kk_unit_t _x, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun544(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun544, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_unit_t kk_hello_use_get_and_div_fun544(kk_function_t _fself, kk_unit_t _x, kk_context_t* _ctx) {
  kk_unused(_fself);
  _x; return kk_Unit;
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun545__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_hello_use_get_and_div_fun545(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun545(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello_use_get_and_div_fun545, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_unit_t kk_hello_use_get_and_div_fun545(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_hello_report_get_mn_and_div(_ctx); return kk_Unit;
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun546__t {
  struct kk_function_s _base;
  kk_function_t _b_x253_272;
};
static kk_box_t kk_hello_use_get_and_div_fun546(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun546(kk_function_t _b_x253_272, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun546__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun546__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun546, kk_context());
  _self->_b_x253_272 = _b_x253_272;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_use_get_and_div_fun546(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun546__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun546__t*, _fself, _ctx);
  kk_function_t _b_x253_272 = _self->_b_x253_272; /* (()) -> <console/console,hello/get<int>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x253_272, _ctx);}, {}, _ctx)
  kk_unit_t _x_x547 = kk_Unit;
  kk_unit_t _x_x548 = kk_Unit;
  kk_unit_unbox(_b_x255);
  kk_function_call(kk_unit_t, (kk_function_t, kk_unit_t, kk_context_t*), _b_x253_272, (_b_x253_272, _x_x548, _ctx), _ctx);
  return kk_unit_box(_x_x547);
}


// lift anonymous function
struct kk_hello_use_get_and_div_fun549__t {
  struct kk_function_s _base;
  kk_function_t _b_x254_273;
};
static kk_box_t kk_hello_use_get_and_div_fun549(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_hello_new_use_get_and_div_fun549(kk_function_t _b_x254_273, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun549__t* _self = kk_function_alloc_as(struct kk_hello_use_get_and_div_fun549__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_hello_use_get_and_div_fun549, kk_context());
  _self->_b_x254_273 = _b_x254_273;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_hello_use_get_and_div_fun549(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_hello_use_get_and_div_fun549__t* _self = kk_function_as(struct kk_hello_use_get_and_div_fun549__t*, _fself, _ctx);
  kk_function_t _b_x254_273 = _self->_b_x254_273; /* () -> <console/console,hello/get<int>,hello/throw-string> () */
  kk_drop_match(_self, {kk_function_dup(_b_x254_273, _ctx);}, {}, _ctx)
  kk_unit_t _x_x550 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _b_x254_273, (_b_x254_273, _ctx), _ctx);
  return kk_unit_box(_x_x550);
}
static kk_box_t kk_hello_use_get_and_div_fun527(kk_function_t _fself, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_hello__throw_string _b_x252_271;
  kk_std_core_hnd__clause1 _x_x528 = kk_std_core_hnd__new_Clause1(kk_hello_new_use_get_and_div_fun529(_ctx), _ctx); /*hnd/clause1<1015,1016,1017,1018,1019>*/
  _b_x252_271 = kk_hello__new_Hnd_throw_string(kk_reuse_null, 0, kk_integer_from_small(3), _x_x528, _ctx); /*hello/throw-string<<console/console,hello/get<int>>,()>*/
  kk_function_t _b_x253_272 = kk_hello_new_use_get_and_div_fun544(_ctx); /*(()) -> <console/console,hello/get<int>> ()*/;
  kk_function_t _b_x254_273 = kk_hello_new_use_get_and_div_fun545(_ctx); /*() -> <console/console,hello/get<int>,hello/throw-string> ()*/;
  return kk_hello__handle_throw_string(_b_x252_271, kk_hello_new_use_get_and_div_fun546(_b_x253_272, _ctx), kk_hello_new_use_get_and_div_fun549(_b_x254_273, _ctx), _ctx);
}

kk_std_core_types__list kk_hello_use_get_and_div(kk_context_t* _ctx) { /* () -> console/console list<()> */ 
  kk_box_t _x_x506;
  kk_function_t _b_x232_263 = kk_hello_new_use_get_and_div_fun507(_ctx); /*(m : hnd/marker<console/console,list<()>>, hnd/ev<hello/get<int>>) -> console/console int*/;
  kk_hello__get _x_x521;
  kk_std_core_hnd__clause0 _x_x522 = kk_std_core_hnd__new_Clause0(kk_hello_new_use_get_and_div_fun523(_b_x232_263, _ctx), _ctx); /*hnd/clause0<1010,1011,1012,1013>*/
  _x_x521 = kk_hello__new_Hnd_get(kk_reuse_null, 0, kk_integer_from_small(3), _x_x522, _ctx); /*hello/get<8,9,10>*/
  _x_x506 = kk_hello__handle_get(_x_x521, kk_hello_new_use_get_and_div_fun525(_ctx), kk_hello_new_use_get_and_div_fun527(_ctx), _ctx); /*1213*/
  return kk_std_core_types__list_unbox(_x_x506, KK_OWNED, _ctx);
}
extern kk_string_t kk_hello_main_fun552(kk_function_t _fself, kk_box_t _b_x288, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_unit_t _x_x553 = kk_Unit;
  kk_unit_unbox(_b_x288);
  return kk_std_core_tuple_unit_fs_show(_x_x553, _ctx);
}

// initialization
void kk_hello__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
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
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x334;
    kk_define_string_literal(, _s_x335, 16, "is-verbose@hello", _ctx)
    _x_x334 = kk_string_dup(_s_x335, _ctx); /*string*/
    kk_hello__tag_is_verbose = kk_std_core_hnd__new_Htag(_x_x334, _ctx); /*hnd/htag<hello/is-verbose>*/
  }
  {
    kk_string_t _x_x341;
    kk_define_string_literal(, _s_x342, 9, "log@hello", _ctx)
    _x_x341 = kk_string_dup(_s_x342, _ctx); /*string*/
    kk_hello__tag_log = kk_std_core_hnd__new_Htag(_x_x341, _ctx); /*hnd/htag<hello/log>*/
  }
  {
    kk_string_t _x_x395;
    kk_define_string_literal(, _s_x396, 18, "throw-string@hello", _ctx)
    _x_x395 = kk_string_dup(_s_x396, _ctx); /*string*/
    kk_hello__tag_throw_string = kk_std_core_hnd__new_Htag(_x_x395, _ctx); /*hnd/htag<hello/throw-string>*/
  }
  {
    kk_string_t _x_x401;
    kk_define_string_literal(, _s_x402, 9, "get@hello", _ctx)
    _x_x401 = kk_string_dup(_s_x402, _ctx); /*string*/
    kk_hello__tag_get = kk_std_core_hnd__new_Htag(_x_x401, _ctx); /*forall<a> hnd/htag<hello/get<a>>*/
  }
}

// termination
void kk_hello__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_hello__tag_get, _ctx);
  kk_std_core_hnd__htag_drop(kk_hello__tag_throw_string, _ctx);
  kk_std_core_hnd__htag_drop(kk_hello__tag_log, _ctx);
  kk_std_core_hnd__htag_drop(kk_hello__tag_is_verbose, _ctx);
  kk_std_core__done(_ctx);
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
  kk_std_core_types__done(_ctx);
}
