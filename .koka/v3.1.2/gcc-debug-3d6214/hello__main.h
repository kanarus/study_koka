#pragma once
#ifndef kk_hello__main_H
#define kk_hello__main_H
// Koka generated module: hello/@main, koka version: 3.1.2, platform: 64-bit
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
#include "hello.h"

// type declarations

// value declarations


// lift anonymous function
struct kk_hello__main__expr_fun11__t {
  struct kk_function_s _base;
};
extern kk_string_t kk_hello__main__expr_fun11(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static inline kk_function_t kk_hello__main__new_expr_fun11(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello__main__expr_fun11, _ctx)
  return kk_function_dup(_fself,kk_context());
}


static inline kk_unit_t kk_hello__main__expr(kk_context_t* _ctx) { /* () -> console/console () */ 
  kk_std_core_types__list x_10010 = kk_hello_use_get_and_div(_ctx); /*list<()>*/;
  kk_string_t _x_x10 = kk_std_core_list_show(x_10010, kk_hello__main__new_expr_fun11(_ctx), _ctx); /*string*/
  kk_std_core_console_printsln(_x_x10, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_hello__main__main_fun14__t {
  struct kk_function_s _base;
};
extern kk_string_t kk_hello__main__main_fun14(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static inline kk_function_t kk_hello__main__new_main_fun14(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_hello__main__main_fun14, _ctx)
  return kk_function_dup(_fself,kk_context());
}


static inline kk_unit_t kk_hello__main__main(kk_context_t* _ctx) { /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 
  kk_std_core_types__list x_10010 = kk_hello_use_get_and_div(_ctx); /*list<()>*/;
  kk_string_t _x_x13 = kk_std_core_list_show(x_10010, kk_hello__main__new_main_fun14(_ctx), _ctx); /*string*/
  kk_std_core_console_printsln(_x_x13, _ctx); return kk_Unit;
}

void kk_hello__main__init(kk_context_t* _ctx);


void kk_hello__main__done(kk_context_t* _ctx);

#endif // header
