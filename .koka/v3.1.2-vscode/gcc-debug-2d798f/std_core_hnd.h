#pragma once
#ifndef kk_std_core_hnd_H
#define kk_std_core_hnd_H
// Koka generated module: std/core/hnd, koka version: 3.1.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_undiv.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
typedef kk_datatype_ptr_t kk_std_core_hnd__ev_t;
static inline kk_std_core_hnd__ev_t kk_std_core_hnd__ev_dup(kk_std_core_hnd__ev_t _x, kk_context_t* ctx);

typedef struct kk_evv_vector_s {
  struct kk_block_s     _block;
  kk_std_core_hnd__ev_t vec[1];
} *kk_evv_vector_t;


typedef kk_datatype_ptr_t kk_evv_t;   // either a kk_evv_vector_t, or a single evidence

static inline kk_evv_t kk_evv_dup(kk_evv_t evv, kk_context_t* ctx) {
  return kk_datatype_ptr_dup(evv,ctx);
}

static inline void kk_evv_drop(kk_evv_t evv, kk_context_t* ctx) {
  kk_datatype_ptr_drop(evv,ctx);
}

static inline kk_evv_t kk_evv_empty(kk_context_t* ctx) {
  return kk_evv_empty_singleton(ctx);
}

static inline bool kk_evv_is_empty(kk_evv_t evv, kk_context_t* ctx) {  // todo: optimize
  kk_evv_t empty = kk_evv_empty(ctx);
  bool eq = kk_datatype_eq(evv,empty);
  kk_datatype_ptr_drop(empty,ctx);
  return eq;
}

static inline bool kk_evv_is_vector(kk_evv_t evv, kk_context_t* ctx) {
  return kk_datatype_ptr_has_tag(evv,KK_TAG_EVV_VECTOR,ctx);
}

static inline kk_std_core_hnd__ev_t kk_evv_as_ev( kk_evv_t evv, kk_context_t* ctx ) {
  kk_unused_internal(ctx);
  kk_assert_internal(!kk_evv_is_vector(evv,ctx));
  return evv;
}

static inline kk_evv_t kk_ev_as_evv( kk_std_core_hnd__ev_t ev, kk_context_t* ctx ) {
  kk_unused(ctx);
  return ev;
}

static inline kk_evv_vector_t kk_evv_as_vector( kk_evv_t evv, kk_context_t* ctx ) {
  kk_assert_internal(kk_evv_is_vector(evv,ctx));
  return kk_datatype_as_assert(kk_evv_vector_t,evv,KK_TAG_EVV_VECTOR,ctx);
}

static inline kk_std_core_hnd__ev_t kk_evv_at( kk_ssize_t i, kk_context_t* ctx ) {
  kk_evv_t evv = ctx->evv;
  if (!kk_evv_is_vector(evv,ctx)) {  // evv is a single evidence
    kk_assert_internal(i==0);
    return kk_evv_as_ev(kk_evv_dup(evv,ctx),ctx);
  }
  else {  // evv as a vector
    kk_assert_internal(i >= 0 && i < (kk_block_scan_fsize(kk_datatype_as_ptr(evv,ctx))));
    kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
    return kk_std_core_hnd__ev_dup(vec->vec[i],ctx);
  }
}

static inline kk_evv_t kk_evv_get(kk_context_t* ctx) {
  return kk_evv_dup(ctx->evv,ctx);
}

static inline kk_unit_t kk_evv_set(kk_evv_t evv, kk_context_t* ctx) {
  kk_evv_drop(ctx->evv, ctx);
  ctx->evv = evv;
  return kk_Unit;
}

static inline kk_evv_t kk_evv_swap(kk_evv_t evv, kk_context_t* ctx) {
  kk_evv_t evv0 = ctx->evv;
  ctx->evv = evv;
  return evv0;
}

static inline bool kk_evv_eq(kk_evv_t evv1, kk_evv_t evv2, kk_context_t* ctx) {  // TODO:make borrowing
  bool eq = kk_datatype_eq(evv1,evv2);
  kk_evv_drop(evv1,ctx);
  kk_evv_drop(evv2,ctx);
  return eq;
}

static inline kk_evv_t kk_evv_swap_create0(kk_context_t* ctx) {
  return kk_evv_swap(kk_evv_empty(ctx),ctx);
}

static inline kk_evv_t kk_evv_swap_create1(kk_ssize_t i, kk_context_t* ctx) {
  kk_evv_t evv0 = ctx->evv;
  if (kk_evv_is_vector(evv0,ctx)) {
    ctx->evv = kk_evv_at(i, ctx);
    return evv0;
  }
  else {
    kk_assert_internal(i==0);
    return kk_evv_dup(evv0,ctx);  // already a single evidence
  }
}

struct kk_std_core_hnd_Htag;
kk_ssize_t      kk_evv_index( struct kk_std_core_hnd_Htag htag, kk_context_t* ctx );
kk_evv_t        kk_evv_create(kk_evv_t evv, kk_vector_t indices, kk_context_t* ctx);
kk_evv_t        kk_evv_insert(kk_evv_t evv, kk_std_core_hnd__ev_t ev, kk_context_t* ctx);
kk_evv_t        kk_evv_delete(kk_evv_t evv, kk_ssize_t index, bool behind, kk_context_t* ctx);
kk_string_t     kk_evv_show(kk_evv_t evv, kk_context_t* ctx);
kk_unit_t       kk_evv_guard(kk_evv_t evv, kk_context_t* ctx);
kk_evv_t        kk_evv_swap_create( kk_vector_t indices, kk_context_t* ctx );
bool            kk_evv_is_affine(kk_context_t* ctx);

static inline kk_evv_t kk_evv_swap_delete(kk_ssize_t i, bool behind, kk_context_t* ctx) {
  kk_evv_t evv0 = ctx->evv;
  ctx->evv = kk_evv_delete(kk_evv_dup(evv0,ctx), i, behind, ctx);
  return evv0;
}

struct kk_std_core_hnd_yld_s;
typedef int32_t kk_marker_t;

kk_box_t        kk_fatal_resume_final(kk_context_t* ctx);
kk_box_t        kk_yield_cont( kk_function_t next, kk_context_t* ctx );
kk_box_t        kk_yield_extend( kk_function_t next, kk_context_t* ctx );
kk_box_t        kk_yield_final( kk_marker_t m, kk_function_t clause, kk_context_t* ctx );
kk_function_t   kk_yield_to( kk_marker_t m, kk_function_t clause, kk_context_t* ctx );
struct kk_std_core_hnd_yld_s  kk_yield_prompt( kk_marker_t m, kk_context_t* ctx );

kk_datatype_t   kk_yield_capture(kk_context_t* ctx);
kk_box_t        kk_yield_reyield(kk_datatype_t yld, kk_context_t* ctx);




// type declarations

// type std/core/hnd/evv
struct kk_std_core_hnd__evv_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core_hnd__evv;
static inline kk_std_core_hnd__evv kk_std_core_hnd__evv_dup(kk_std_core_hnd__evv _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_std_core_hnd__evv_drop(kk_std_core_hnd__evv _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_core_hnd__evv_box(kk_std_core_hnd__evv _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core_hnd__evv kk_std_core_hnd__evv_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value type std/core/hnd/htag
struct kk_std_core_hnd_Htag {
  kk_string_t tagname;
};
typedef struct kk_std_core_hnd_Htag kk_std_core_hnd__htag;
static inline kk_std_core_hnd__htag kk_std_core_hnd__new_Htag(kk_string_t tagname, kk_context_t* _ctx) {
  kk_std_core_hnd__htag _con = { tagname };
  return _con;
}
static inline bool kk_std_core_hnd__is_Htag(kk_std_core_hnd__htag x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_hnd__htag kk_std_core_hnd__htag_dup(kk_std_core_hnd__htag _x, kk_context_t* _ctx) {
  kk_string_dup(_x.tagname, _ctx);
  return _x;
}
static inline void kk_std_core_hnd__htag_drop(kk_std_core_hnd__htag _x, kk_context_t* _ctx) {
  kk_string_drop(_x.tagname, _ctx);
}
static inline kk_box_t kk_std_core_hnd__htag_box(kk_std_core_hnd__htag _x, kk_context_t* _ctx) {
  return kk_string_box(_x.tagname);
}
static inline kk_std_core_hnd__htag kk_std_core_hnd__htag_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_core_hnd__new_Htag(kk_string_unbox(_x), _ctx);
}

// value type std/core/hnd/marker
struct kk_std_core_hnd_marker_s {
  kk_value_tag_t _tag;
  union {
    
  } _cons;
};
typedef struct kk_std_core_hnd_marker_s kk_std_core_hnd__marker;
static inline kk_std_core_hnd__marker kk_std_core_hnd__marker_dup(kk_std_core_hnd__marker _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_std_core_hnd__marker_drop(kk_std_core_hnd__marker _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_core_hnd__marker_box(kk_std_core_hnd__marker _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core_hnd__marker, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_core_hnd__marker kk_std_core_hnd__marker_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_core_hnd__marker _unbox;
  kk_valuetype_unbox(kk_std_core_hnd__marker, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// type std/core/hnd/ev
struct kk_std_core_hnd__ev_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_core_hnd__ev;
struct kk_std_core_hnd_Ev {
  struct kk_std_core_hnd__ev_s _base;
  kk_std_core_hnd__htag htag;
  kk_box_t hnd;
  kk_evv_t hevv;
  int32_t marker;
};
static inline kk_std_core_hnd__ev kk_std_core_hnd__base_Ev(struct kk_std_core_hnd_Ev* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_core_hnd__ev kk_std_core_hnd__new_Ev(kk_reuse_t _at, int32_t _cpath, kk_std_core_hnd__htag htag, int32_t marker, kk_box_t hnd, kk_evv_t hevv, kk_context_t* _ctx) {
  struct kk_std_core_hnd_Ev* _con = kk_block_alloc_at_as(struct kk_std_core_hnd_Ev, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->htag = htag;
  _con->hnd = hnd;
  _con->hevv = hevv;
  _con->marker = marker;
  return kk_std_core_hnd__base_Ev(_con, _ctx);
}
static inline struct kk_std_core_hnd_Ev* kk_std_core_hnd__as_Ev(kk_std_core_hnd__ev x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_core_hnd_Ev*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_core_hnd__is_Ev(kk_std_core_hnd__ev x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_hnd__ev kk_std_core_hnd__ev_dup(kk_std_core_hnd__ev _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_core_hnd__ev_drop(kk_std_core_hnd__ev _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_core_hnd__ev_box(kk_std_core_hnd__ev _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_core_hnd__ev kk_std_core_hnd__ev_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type std/core/hnd/clause0
struct kk_std_core_hnd_Clause0 {
  kk_function_t clause;
};
typedef struct kk_std_core_hnd_Clause0 kk_std_core_hnd__clause0;
static inline kk_std_core_hnd__clause0 kk_std_core_hnd__new_Clause0(kk_function_t clause, kk_context_t* _ctx) {
  kk_std_core_hnd__clause0 _con = { clause };
  return _con;
}
static inline bool kk_std_core_hnd__is_Clause0(kk_std_core_hnd__clause0 x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_hnd__clause0 kk_std_core_hnd__clause0_dup(kk_std_core_hnd__clause0 _x, kk_context_t* _ctx) {
  kk_function_dup(_x.clause, _ctx);
  return _x;
}
static inline void kk_std_core_hnd__clause0_drop(kk_std_core_hnd__clause0 _x, kk_context_t* _ctx) {
  kk_function_drop(_x.clause, _ctx);
}
static inline kk_box_t kk_std_core_hnd__clause0_box(kk_std_core_hnd__clause0 _x, kk_context_t* _ctx) {
  return kk_function_box(_x.clause, _ctx);
}
static inline kk_std_core_hnd__clause0 kk_std_core_hnd__clause0_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_core_hnd__new_Clause0(kk_function_unbox(_x, _ctx), _ctx);
}

// value type std/core/hnd/clause1
struct kk_std_core_hnd_Clause1 {
  kk_function_t clause;
};
typedef struct kk_std_core_hnd_Clause1 kk_std_core_hnd__clause1;
static inline kk_std_core_hnd__clause1 kk_std_core_hnd__new_Clause1(kk_function_t clause, kk_context_t* _ctx) {
  kk_std_core_hnd__clause1 _con = { clause };
  return _con;
}
static inline bool kk_std_core_hnd__is_Clause1(kk_std_core_hnd__clause1 x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_hnd__clause1 kk_std_core_hnd__clause1_dup(kk_std_core_hnd__clause1 _x, kk_context_t* _ctx) {
  kk_function_dup(_x.clause, _ctx);
  return _x;
}
static inline void kk_std_core_hnd__clause1_drop(kk_std_core_hnd__clause1 _x, kk_context_t* _ctx) {
  kk_function_drop(_x.clause, _ctx);
}
static inline kk_box_t kk_std_core_hnd__clause1_box(kk_std_core_hnd__clause1 _x, kk_context_t* _ctx) {
  return kk_function_box(_x.clause, _ctx);
}
static inline kk_std_core_hnd__clause1 kk_std_core_hnd__clause1_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_core_hnd__new_Clause1(kk_function_unbox(_x, _ctx), _ctx);
}

// value type std/core/hnd/clause2
struct kk_std_core_hnd_Clause2 {
  kk_function_t clause;
};
typedef struct kk_std_core_hnd_Clause2 kk_std_core_hnd__clause2;
static inline kk_std_core_hnd__clause2 kk_std_core_hnd__new_Clause2(kk_function_t clause, kk_context_t* _ctx) {
  kk_std_core_hnd__clause2 _con = { clause };
  return _con;
}
static inline bool kk_std_core_hnd__is_Clause2(kk_std_core_hnd__clause2 x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_hnd__clause2 kk_std_core_hnd__clause2_dup(kk_std_core_hnd__clause2 _x, kk_context_t* _ctx) {
  kk_function_dup(_x.clause, _ctx);
  return _x;
}
static inline void kk_std_core_hnd__clause2_drop(kk_std_core_hnd__clause2 _x, kk_context_t* _ctx) {
  kk_function_drop(_x.clause, _ctx);
}
static inline kk_box_t kk_std_core_hnd__clause2_box(kk_std_core_hnd__clause2 _x, kk_context_t* _ctx) {
  return kk_function_box(_x.clause, _ctx);
}
static inline kk_std_core_hnd__clause2 kk_std_core_hnd__clause2_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_core_hnd__new_Clause2(kk_function_unbox(_x, _ctx), _ctx);
}

// value type std/core/hnd/resume-result
struct kk_std_core_hnd_Deep {
  kk_box_t result;
};
struct kk_std_core_hnd_Shallow {
  kk_box_t result;
};
struct kk_std_core_hnd_Finalize {
  kk_box_t result;
};
struct kk_std_core_hnd_resume_result_s {
  kk_value_tag_t _tag;
  union {
    struct kk_std_core_hnd_Deep Deep;
    struct kk_std_core_hnd_Shallow Shallow;
    struct kk_std_core_hnd_Finalize Finalize;
  } _cons;
};
typedef struct kk_std_core_hnd_resume_result_s kk_std_core_hnd__resume_result;
static inline kk_std_core_hnd__resume_result kk_std_core_hnd__new_Deep(kk_box_t result, kk_context_t* _ctx) {
  kk_std_core_hnd__resume_result _con;
  _con._tag = kk_value_tag(1);
  _con._cons.Deep.result = result;
  return _con;
}
static inline kk_std_core_hnd__resume_result kk_std_core_hnd__new_Shallow(kk_box_t result, kk_context_t* _ctx) {
  kk_std_core_hnd__resume_result _con;
  _con._tag = kk_value_tag(2);
  _con._cons.Shallow.result = result;
  return _con;
}
static inline kk_std_core_hnd__resume_result kk_std_core_hnd__new_Finalize(kk_box_t result, kk_context_t* _ctx) {
  kk_std_core_hnd__resume_result _con;
  _con._tag = kk_value_tag(3);
  _con._cons.Finalize.result = result;
  return _con;
}
static inline bool kk_std_core_hnd__is_Deep(kk_std_core_hnd__resume_result x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(1)));
}
static inline bool kk_std_core_hnd__is_Shallow(kk_std_core_hnd__resume_result x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(2)));
}
static inline bool kk_std_core_hnd__is_Finalize(kk_std_core_hnd__resume_result x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(3)));
}
static inline kk_std_core_hnd__resume_result kk_std_core_hnd__resume_result_dup(kk_std_core_hnd__resume_result _x, kk_context_t* _ctx) {
  if (kk_std_core_hnd__is_Deep(_x, _ctx)) { kk_box_dup(_x._cons.Deep.result, _ctx); }
  else if (kk_std_core_hnd__is_Shallow(_x, _ctx)) { kk_box_dup(_x._cons.Shallow.result, _ctx); }
  else { kk_box_dup(_x._cons.Finalize.result, _ctx); }
  return _x;
}
static inline void kk_std_core_hnd__resume_result_drop(kk_std_core_hnd__resume_result _x, kk_context_t* _ctx) {
  if (kk_std_core_hnd__is_Deep(_x, _ctx)) { kk_box_drop(_x._cons.Deep.result, _ctx); }
  else if (kk_std_core_hnd__is_Shallow(_x, _ctx)) { kk_box_drop(_x._cons.Shallow.result, _ctx); }
  else { kk_box_drop(_x._cons.Finalize.result, _ctx); }
}
static inline kk_box_t kk_std_core_hnd__resume_result_box(kk_std_core_hnd__resume_result _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core_hnd__resume_result, _box, _x, 2 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_core_hnd__resume_result kk_std_core_hnd__resume_result_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_core_hnd__resume_result _unbox;
  kk_valuetype_unbox(kk_std_core_hnd__resume_result, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value type std/core/hnd/resume-context
struct kk_std_core_hnd_Resume_context {
  kk_function_t k;
};
typedef struct kk_std_core_hnd_Resume_context kk_std_core_hnd__resume_context;
static inline kk_std_core_hnd__resume_context kk_std_core_hnd__new_Resume_context(kk_function_t k, kk_context_t* _ctx) {
  kk_std_core_hnd__resume_context _con = { k };
  return _con;
}
static inline bool kk_std_core_hnd__is_Resume_context(kk_std_core_hnd__resume_context x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_hnd__resume_context kk_std_core_hnd__resume_context_dup(kk_std_core_hnd__resume_context _x, kk_context_t* _ctx) {
  kk_function_dup(_x.k, _ctx);
  return _x;
}
static inline void kk_std_core_hnd__resume_context_drop(kk_std_core_hnd__resume_context _x, kk_context_t* _ctx) {
  kk_function_drop(_x.k, _ctx);
}
static inline kk_box_t kk_std_core_hnd__resume_context_box(kk_std_core_hnd__resume_context _x, kk_context_t* _ctx) {
  return kk_function_box(_x.k, _ctx);
}
static inline kk_std_core_hnd__resume_context kk_std_core_hnd__resume_context_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_core_hnd__new_Resume_context(kk_function_unbox(_x, _ctx), _ctx);
}

// type std/core/hnd/yield-info
struct kk_std_core_hnd__yield_info_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core_hnd__yield_info;
static inline kk_std_core_hnd__yield_info kk_std_core_hnd__yield_info_dup(kk_std_core_hnd__yield_info _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_std_core_hnd__yield_info_drop(kk_std_core_hnd__yield_info _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_core_hnd__yield_info_box(kk_std_core_hnd__yield_info _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core_hnd__yield_info kk_std_core_hnd__yield_info_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value type std/core/hnd/yld
struct kk_std_core_hnd_Pure {
  kk_box_t _unused;
};
struct kk_std_core_hnd_YieldingFinal {
  kk_box_t _unused;
};
struct kk_std_core_hnd_Yielding {
  kk_box_t _unused;
};
struct kk_std_core_hnd_Yield {
  kk_function_t clause;
  kk_function_t cont;
};
struct kk_std_core_hnd_yld_s {
  kk_value_tag_t _tag;
  union {
    struct kk_std_core_hnd_Pure Pure;
    struct kk_std_core_hnd_YieldingFinal YieldingFinal;
    struct kk_std_core_hnd_Yielding Yielding;
    struct kk_std_core_hnd_Yield Yield;
    kk_box_t _fields[2];
  } _cons;
};
typedef struct kk_std_core_hnd_yld_s kk_std_core_hnd__yld;
static inline kk_std_core_hnd__yld kk_std_core_hnd__new_Pure(kk_context_t* _ctx) {
  kk_std_core_hnd__yld _con;
  _con._tag = kk_value_tag(1);
  _con._cons._fields[0] = kk_box_null();
  _con._cons._fields[1] = kk_box_null();
  return _con;
}
static inline kk_std_core_hnd__yld kk_std_core_hnd__new_YieldingFinal(kk_context_t* _ctx) {
  kk_std_core_hnd__yld _con;
  _con._tag = kk_value_tag(2);
  _con._cons._fields[0] = kk_box_null();
  _con._cons._fields[1] = kk_box_null();
  return _con;
}
static inline kk_std_core_hnd__yld kk_std_core_hnd__new_Yielding(kk_context_t* _ctx) {
  kk_std_core_hnd__yld _con;
  _con._tag = kk_value_tag(3);
  _con._cons._fields[0] = kk_box_null();
  _con._cons._fields[1] = kk_box_null();
  return _con;
}
static inline kk_std_core_hnd__yld kk_std_core_hnd__new_Yield(kk_function_t clause, kk_function_t cont, kk_context_t* _ctx) {
  kk_std_core_hnd__yld _con;
  _con._tag = kk_value_tag(4);
  _con._cons.Yield.clause = clause;
  _con._cons.Yield.cont = cont;
  return _con;
}
static inline bool kk_std_core_hnd__is_Pure(kk_std_core_hnd__yld x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(1)));
}
static inline bool kk_std_core_hnd__is_YieldingFinal(kk_std_core_hnd__yld x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(2)));
}
static inline bool kk_std_core_hnd__is_Yielding(kk_std_core_hnd__yld x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(3)));
}
static inline bool kk_std_core_hnd__is_Yield(kk_std_core_hnd__yld x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(4)));
}
static inline kk_std_core_hnd__yld kk_std_core_hnd__yld_dup(kk_std_core_hnd__yld _x, kk_context_t* _ctx) {
  if (kk_std_core_hnd__is_Yield(_x, _ctx)) {
    kk_function_dup(_x._cons.Yield.clause, _ctx);
    kk_function_dup(_x._cons.Yield.cont, _ctx);
  }
  return _x;
}
static inline void kk_std_core_hnd__yld_drop(kk_std_core_hnd__yld _x, kk_context_t* _ctx) {
  if (kk_std_core_hnd__is_Yield(_x, _ctx)) {
    kk_function_drop(_x._cons.Yield.clause, _ctx);
    kk_function_drop(_x._cons.Yield.cont, _ctx);
  }
}
static inline kk_box_t kk_std_core_hnd__yld_box(kk_std_core_hnd__yld _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core_hnd__yld, _box, _x, 3 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_core_hnd__yld kk_std_core_hnd__yld_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_core_hnd__yld _unbox;
  kk_valuetype_unbox(kk_std_core_hnd__yld, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `tagname` constructor field of the `:htag` type.

static inline kk_string_t kk_std_core_hnd_htag_fs_tagname(kk_std_core_hnd__htag htag, kk_context_t* _ctx) { /* forall<a> (htag : htag<a>) -> string */ 
  {
    kk_string_t _x = htag.tagname;
    return kk_string_dup(_x, _ctx);
  }
}

kk_std_core_hnd__htag kk_std_core_hnd_htag_fs__copy(kk_std_core_hnd__htag _this, kk_std_core_types__optional tagname, kk_context_t* _ctx); /* forall<a> (htag<a>, tagname : ? string) -> htag<a> */ 
 
// Automatically generated. Retrieves the `htag` constructor field of the `:ev` type.

static inline kk_std_core_hnd__htag kk_std_core_hnd_ev_fs_htag(kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<a> (ev : ev<a>) -> htag<a> */ 
  {
    struct kk_std_core_hnd_Ev* _con_x271 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_std_core_hnd__htag _x = _con_x271->htag;
    return kk_std_core_hnd__htag_dup(_x, _ctx);
  }
}

kk_std_core_hnd__ev kk_std_core_hnd_ev_fs__copy(kk_std_core_hnd__ev _this, kk_std_core_types__optional htag, int32_t marker, kk_box_t hnd, kk_evv_t hevv, kk_context_t* _ctx); /* forall<a,e,b> (ev<a>, htag : ? (htag<a>), marker : marker<e,b>, hnd : a<e,b>, hevv : evv<e>) -> ev<a> */ 
 
// Automatically generated. Retrieves the `clause` constructor field of the `:clause0` type.

static inline kk_function_t kk_std_core_hnd_clause0_fs_clause(kk_std_core_hnd__clause0 clause0, kk_context_t* _ctx) { /* forall<a,b,e,c> (clause0 : clause0<a,b,e,c>) -> ((marker<e,c>, ev<b>) -> e a) */ 
  {
    kk_function_t _x = clause0.clause;
    return kk_function_dup(_x, _ctx);
  }
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause0_fs__copy(kk_std_core_hnd__clause0 _this, kk_std_core_types__optional clause, kk_context_t* _ctx); /* forall<a,b,e,c> (clause0<a,b,e,c>, clause : ? ((marker<e,c>, ev<b>) -> e a)) -> clause0<a,b,e,c> */ 
 
// Automatically generated. Retrieves the `clause` constructor field of the `:clause1` type.

static inline kk_function_t kk_std_core_hnd_clause1_fs_clause(kk_std_core_hnd__clause1 clause1, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (clause1 : clause1<a,b,c,e,d>) -> ((marker<e,d>, ev<c>, a) -> e b) */ 
  {
    kk_function_t _x = clause1.clause;
    return kk_function_dup(_x, _ctx);
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause1_fs__copy(kk_std_core_hnd__clause1 _this, kk_std_core_types__optional clause, kk_context_t* _ctx); /* forall<a,b,c,e,d> (clause1<a,b,c,e,d>, clause : ? ((marker<e,d>, ev<c>, a) -> e b)) -> clause1<a,b,c,e,d> */ 
 
// Automatically generated. Retrieves the `clause` constructor field of the `:clause2` type.

static inline kk_function_t kk_std_core_hnd_clause2_fs_clause(kk_std_core_hnd__clause2 clause2, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (clause2 : clause2<a,b,c,d,e,a1>) -> ((marker<e,a1>, ev<d>, a, b) -> e c) */ 
  {
    kk_function_t _x = clause2.clause;
    return kk_function_dup(_x, _ctx);
  }
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause2_fs__copy(kk_std_core_hnd__clause2 _this, kk_std_core_types__optional clause, kk_context_t* _ctx); /* forall<a,b,c,d,e,a1> (clause2<a,b,c,d,e,a1>, clause : ? ((marker<e,a1>, ev<d>, a, b) -> e c)) -> clause2<a,b,c,d,e,a1> */ 
 
// Automatically generated. Tests for the `Deep` constructor of the `:resume-result` type.

static inline bool kk_std_core_hnd_is_deep(kk_std_core_hnd__resume_result resume_result, kk_context_t* _ctx) { /* forall<a,b> (resume-result : resume-result<a,b>) -> bool */ 
  if (kk_std_core_hnd__is_Deep(resume_result, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Shallow` constructor of the `:resume-result` type.

static inline bool kk_std_core_hnd_is_shallow(kk_std_core_hnd__resume_result resume_result, kk_context_t* _ctx) { /* forall<a,b> (resume-result : resume-result<a,b>) -> bool */ 
  if (kk_std_core_hnd__is_Shallow(resume_result, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Finalize` constructor of the `:resume-result` type.

static inline bool kk_std_core_hnd_is_finalize(kk_std_core_hnd__resume_result resume_result, kk_context_t* _ctx) { /* forall<a,b> (resume-result : resume-result<a,b>) -> bool */ 
  if (kk_std_core_hnd__is_Finalize(resume_result, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `k` constructor field of the `:resume-context` type.

static inline kk_function_t kk_std_core_hnd_resume_context_fs_k(kk_std_core_hnd__resume_context _this, kk_context_t* _ctx) { /* forall<a,e,e1,b> (resume-context<a,e,e1,b>) -> ((resume-result<a,b>) -> e b) */ 
  {
    kk_function_t _x = _this.k;
    return kk_function_dup(_x, _ctx);
  }
}

kk_std_core_hnd__resume_context kk_std_core_hnd_resume_context_fs__copy(kk_std_core_hnd__resume_context _this, kk_std_core_types__optional k, kk_context_t* _ctx); /* forall<a,e,e1,b> (resume-context<a,e,e1,b>, k : ? ((resume-result<a,b>) -> e b)) -> resume-context<a,e,e1,b> */ 
 
// Automatically generated. Tests for the `Pure` constructor of the `:yld` type.

static inline bool kk_std_core_hnd_is_pure(kk_std_core_hnd__yld yld, kk_context_t* _ctx) { /* forall<a,b,e> (yld : yld<e,a,b>) -> bool */ 
  if (kk_std_core_hnd__is_Pure(yld, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `YieldingFinal` constructor of the `:yld` type.

static inline bool kk_std_core_hnd_is_yieldingFinal(kk_std_core_hnd__yld yld, kk_context_t* _ctx) { /* forall<a,b,e> (yld : yld<e,a,b>) -> bool */ 
  if (kk_std_core_hnd__is_YieldingFinal(yld, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Yielding` constructor of the `:yld` type.

static inline bool kk_std_core_hnd_is_yielding(kk_std_core_hnd__yld yld, kk_context_t* _ctx) { /* forall<a,b,e> (yld : yld<e,a,b>) -> bool */ 
  if (kk_std_core_hnd__is_Yielding(yld, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Yield` constructor of the `:yld` type.

static inline bool kk_std_core_hnd_is_yield(kk_std_core_hnd__yld yld, kk_context_t* _ctx) { /* forall<a,b,e> (yld : yld<e,a,b>) -> bool */ 
  if (kk_std_core_hnd__is_Yield(yld, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// _Internal_ hidden constructor for creating handler tags

static inline kk_std_core_hnd__htag kk_std_core_hnd__new_htag(kk_string_t tag, kk_context_t* _ctx) { /* forall<a> (tag : string) -> htag<a> */ 
  return kk_std_core_hnd__new_Htag(tag, _ctx);
}
 
// Show a handler tag.

static inline kk_string_t kk_std_core_hnd_htag_fs_show(kk_std_core_hnd__htag _pat_x126__20, kk_context_t* _ctx) { /* forall<a> (htag<a>) -> string */ 
  {
    kk_string_t tag = _pat_x126__20.tagname;
    return tag;
  }
}

bool kk_std_core_hnd_eq_marker(int32_t x, int32_t y, kk_context_t* _ctx); /* forall<a,b,e,e1> (x : marker<e,a>, y : marker<e1,b>) -> bool */ 

bool kk_std_core_hnd_ev_fs__lp__eq__eq__rp_(kk_std_core_hnd__ev _pat_x141__18, kk_std_core_hnd__ev _pat_x141__37, kk_context_t* _ctx); /* forall<a> (ev<a>, ev<a>) -> bool */ 

int32_t kk_std_core_hnd_fresh_marker(kk_context_t* _ctx); /* forall<a,e> () -> marker<e,a> */ 

int32_t kk_std_core_hnd_fresh_marker_named(kk_context_t* _ctx); /* forall<a,e> () -> marker<e,a> */ 

kk_evv_t kk_std_core_hnd_evv_insert(kk_evv_t evv, kk_std_core_hnd__ev ev, kk_context_t* _ctx); /* forall<e,e1,a> (evv : evv<e>, ev : ev<a>) -> e evv<e1> */ 

kk_string_t kk_std_core_hnd_evv_show(kk_evv_t evv, kk_context_t* _ctx); /* forall<e> (evv : evv<e>) -> string */ 

bool kk_std_core_hnd_evv_eq(kk_evv_t evv0, kk_evv_t evv1, kk_context_t* _ctx); /* forall<e> (evv0 : evv<e>, evv1 : evv<e>) -> bool */ 

kk_ssize_t kk_std_core_hnd__evv_index(kk_std_core_hnd__htag htag, kk_context_t* _ctx); /* forall<e,a> (htag : htag<a>) -> e ev-index */ 

kk_evv_t kk_std_core_hnd_evv_get(kk_context_t* _ctx); /* forall<e> () -> e evv<e> */ 

bool kk_std_core_hnd__evv_is_affine(kk_context_t* _ctx); /* () -> bool */ 

kk_evv_t kk_std_core_hnd_evv_swap_delete(kk_ssize_t i, bool behind, kk_context_t* _ctx); /* forall<e,e1> (i : ev-index, behind : bool) -> e1 evv<e> */ 

kk_evv_t kk_std_core_hnd_evv_swap_create(kk_vector_t indices, kk_context_t* _ctx); /* forall<e> (indices : vector<ev-index>) -> e evv<e> */ 

kk_box_t kk_std_core_hnd_yield_extend(kk_function_t next, kk_context_t* _ctx); /* forall<a,b,e> (next : (a) -> e b) -> e b */ 

static inline kk_box_t kk_std_core_hnd_yield_bind(kk_box_t x, kk_function_t next, kk_context_t* _ctx) { /* forall<a,b,e> (x : a, next : (a) -> e b) -> e b */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_extend(next, _ctx);
  }
  {
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), next, (next, x, _ctx), _ctx);
  }
}

static inline kk_box_t kk_std_core_hnd_yield_bind2(kk_box_t x, kk_function_t extend, kk_function_t next, kk_context_t* _ctx) { /* forall<a,b,e> (x : a, extend : (a) -> e b, next : (a) -> e b) -> e b */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    kk_function_drop(next, _ctx);
    return kk_std_core_hnd_yield_extend(extend, _ctx);
  }
  {
    kk_function_drop(extend, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), next, (next, x, _ctx), _ctx);
  }
}

kk_box_t kk_std_core_hnd_yield_cont(kk_function_t f, kk_context_t* _ctx); /* forall<a,e,b> (f : forall<c> ((c) -> e a, c) -> e b) -> e b */ 

kk_std_core_hnd__yld kk_std_core_hnd_yield_prompt(int32_t m, kk_context_t* _ctx); /* forall<a,e,b> (m : marker<e,b>) -> yld<e,a,b> */ 

kk_function_t kk_std_core_hnd_yield_to_prim(int32_t m, kk_function_t clause, kk_context_t* _ctx); /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e (() -> a) */ 

kk_box_t kk_std_core_hnd_yield_to_final(int32_t m, kk_function_t clause, kk_context_t* _ctx); /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e a */ 

kk_box_t kk_std_core_hnd_yield_to(int32_t m, kk_function_t clause, kk_context_t* _ctx); /* forall<a,e,b> (m : marker<e,b>, clause : ((resume-result<a,b>) -> e b) -> e b) -> e a */ 

kk_std_core_hnd__yield_info kk_std_core_hnd_yield_capture(kk_context_t* _ctx); /* forall<e> () -> e yield-info */ 

kk_box_t kk_std_core_hnd_unsafe_reyield(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx); /* forall<a,e> (yld : yield-info) -> e a */ 

kk_unit_t kk_std_core_hnd_guard(kk_evv_t w, kk_context_t* _ctx); /* forall<e> (w : evv<e>) -> e () */ 

kk_box_t kk_std_core_hnd_resume_final(kk_context_t* _ctx); /* forall<a> () -> a */ 

kk_box_t kk_std_core_hnd_prompt(kk_evv_t w0, kk_evv_t w1, kk_std_core_hnd__ev ev, int32_t m, kk_function_t ret, kk_box_t result, kk_context_t* _ctx); /* forall<a,e,b,c> (w0 : evv<e>, w1 : evv<e>, ev : ev<b>, m : marker<e,c>, ret : (a) -> e c, result : a) -> e c */ 

kk_box_t kk_std_core_hnd__hhandle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : () -> e1 a) -> e c */ 

kk_box_t kk_std_core_hnd__named_handle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : (ev<b>) -> e1 a) -> e c */ 

kk_box_t kk_std_core_hnd_mask_at1(kk_ssize_t i, bool behind, kk_function_t action, kk_box_t x, kk_context_t* _ctx); /* forall<a,b,e,e1> (i : ev-index, behind : bool, action : (a) -> e b, x : a) -> e1 b */ 

kk_box_t kk_std_core_hnd__mask_at(kk_ssize_t i, bool behind, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,e1> (i : ev-index, behind : bool, action : () -> e a) -> e1 a */ 
 
// mask for builtin effects without a handler or evidence (like `:st` or `:local`)

static inline kk_box_t kk_std_core_hnd__mask_builtin(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1> (action : () -> e a) -> e1 a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_prompt_local_var(kk_ref_t loc, kk_box_t res, kk_context_t* _ctx); /* forall<a,b,h> (loc : local-var<h,a>, res : b) -> <div,local<h>> b */ 

static inline kk_box_t kk_std_core_hnd_local_var(kk_box_t init, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e,h> (init : a, action : (l : local-var<h,a>) -> <local<h>|e> b) -> <local<h>|e> b */ 
  kk_ref_t loc = kk_ref_alloc(init,kk_context()); /*local-var<4361,4358>*/;
  kk_box_t res;
  kk_ref_t _x_x327 = kk_ref_dup(loc, _ctx); /*local-var<4361,4358>*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_ref_t, kk_context_t*), action, (action, _x_x327, _ctx), _ctx); /*4359*/
  return kk_std_core_hnd_prompt_local_var(loc, res, _ctx);
}

kk_box_t kk_std_core_hnd_finally_prompt(kk_function_t fin, kk_box_t res, kk_context_t* _ctx); /* forall<a,e> (fin : () -> e (), res : a) -> e a */ 

static inline kk_box_t kk_std_core_hnd_finally(kk_function_t fin, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (fin : () -> e (), action : () -> e a) -> e a */ 
  kk_box_t _x_x331 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4502*/
  return kk_std_core_hnd_finally_prompt(fin, _x_x331, _ctx);
}

kk_box_t kk_std_core_hnd_initially_prompt(kk_function_t init, kk_box_t res, kk_context_t* _ctx); /* forall<a,e> (init : (int) -> e (), res : a) -> e a */ 

kk_box_t kk_std_core_hnd_initially(kk_function_t init, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (init : (int) -> e (), action : () -> e a) -> e a */ 

static inline kk_box_t kk_std_core_hnd_resume(kk_std_core_hnd__resume_context r, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e,e1,b> (r : resume-context<a,e,e1,b>, x : a) -> e b */ 
  {
    kk_function_t _x = r.k;
    kk_std_core_hnd__resume_result _x_x345 = kk_std_core_hnd__new_Deep(x, _ctx); /*hnd/resume-result<74,75>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _x, (_x, _x_x345, _ctx), _ctx);
  }
}

static inline kk_box_t kk_std_core_hnd_resume_shallow(kk_std_core_hnd__resume_context r, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e,e1,b> (r : resume-context<a,e,e1,b>, x : a) -> e1 b */ 
  {
    kk_function_t _x = r.k;
    kk_std_core_hnd__resume_result _x_x346 = kk_std_core_hnd__new_Shallow(x, _ctx); /*hnd/resume-result<74,75>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _x, (_x, _x_x346, _ctx), _ctx);
  }
}

static inline kk_box_t kk_std_core_hnd_finalize(kk_std_core_hnd__resume_context r, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e,e1,b> (r : resume-context<a,e,e1,b>, x : b) -> e b */ 
  {
    kk_function_t _x = r.k;
    kk_std_core_hnd__resume_result _x_x347 = kk_std_core_hnd__new_Finalize(x, _ctx); /*hnd/resume-result<74,75>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _x, (_x, _x_x347, _ctx), _ctx);
  }
}

static inline kk_box_t kk_std_core_hnd__perform1(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,c,e> (ev : ev<c>, op : forall<e1,d> (c<e1,d>) -> clause1<a,b,c,e1,d>, x : a) -> e b */ 
  {
    struct kk_std_core_hnd_Ev* _con_x348 = kk_std_core_hnd__as_Ev(ev, _ctx);
    int32_t m = _con_x348->marker;
    kk_box_t h = _con_x348->hnd;
    kk_box_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x245 = kk_function_call(kk_std_core_hnd__clause1, (kk_function_t, kk_box_t, kk_context_t*), op, (op, h, _ctx), _ctx); /*hnd/clause1<4989,4990,4991,832,833>*/;
    {
      kk_function_t f = _match_x245.clause;
      return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), f, (f, m, ev, x, _ctx), _ctx);
    }
  }
}

kk_evv_t kk_std_core_hnd_evv_swap_with(kk_std_core_hnd__ev ev, kk_context_t* _ctx); /* forall<a,e> (ev : ev<a>) -> evv<e> */ 

kk_box_t kk_std_core_hnd_under1x(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx); /* forall<a,b,e,c> (ev : ev<c>, op : (a) -> e b, x : a) -> e b */ 


// lift anonymous function
struct kk_std_core_hnd_under1_fun356__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
extern kk_box_t kk_std_core_hnd_under1_fun356(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_under1_fun356(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1_fun356__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under1_fun356__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under1_fun356, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_box_t kk_std_core_hnd_under1(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,c> (ev : ev<c>, op : (a) -> e b, x : a) -> e b */ 
  kk_evv_t w0;
  kk_evv_t _x_x354;
  {
    struct kk_std_core_hnd_Ev* _con_x355 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x355->hevv;
    kk_evv_dup(w, _ctx);
    _x_x354 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x354,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*5225*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under1_fun356(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw1(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,e,e1,c,d> (op : (x : a, r : resume-context<b,e,e1,d>) -> e d) -> clause1<a,b,c,e,d> */ 

static inline kk_box_t kk_std_core_hnd_get(kk_ref_t ref, kk_context_t* _ctx) { /* forall<a,h> (ref : ref<h,a>) -> <read<h>,div> a */ 
  return kk_ref_get(ref,kk_context());
}

kk_box_t kk_std_core_hnd_protect_check(kk_ref_t resumed, kk_function_t k, kk_box_t res, kk_context_t* _ctx); /* forall<a,e,b> (resumed : ref<global,bool>, k : (resume-result<a,b>) -> e b, res : b) -> e b */ 

kk_box_t kk_std_core_hnd_protect(kk_box_t x, kk_function_t clause, kk_function_t k, kk_context_t* _ctx); /* forall<a,b,e,c> (x : a, clause : (x : a, k : (b) -> e c) -> e c, k : (resume-result<b,c>) -> e c) -> e c */ 
 
// generic control clause


// lift anonymous function
struct kk_std_core_hnd_clause_control1_fun366__t {
  struct kk_function_s _base;
  kk_function_t clause;
};
extern kk_box_t kk_std_core_hnd_clause_control1_fun366(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x623__16, kk_box_t x, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_control1_fun366(kk_function_t clause, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun366__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control1_fun366__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control1_fun366, kk_context());
  _self->clause = clause;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control1_fun367__t {
  struct kk_function_s _base;
  kk_function_t clause;
  kk_box_t x;
};
extern kk_box_t kk_std_core_hnd_clause_control1_fun367(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_control1_fun367(kk_function_t clause, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun367__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control1_fun367__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control1_fun367, kk_context());
  _self->clause = clause;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control1(kk_function_t clause, kk_context_t* _ctx) { /* forall<a,b,e,c,d> (clause : (x : a, k : (b) -> e d) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control1_fun366(clause, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail1(kk_function_t op, kk_context_t* _ctx); /* forall<e,a,b,c,d> (op : (c) -> e d) -> clause1<c,d,b,e,a> */ 
 
// tail-resumptive clause that does not itself invoke operations
// (these can be executed 'in-place' without setting the correct evidence vector)


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop1_fun372__t {
  struct kk_function_s _base;
  kk_function_t op;
};
extern kk_box_t kk_std_core_hnd_clause_tail_noop1_fun372(kk_function_t _fself, int32_t ___wildcard_x633__14, kk_std_core_hnd__ev ___wildcard_x633__17, kk_box_t x, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_tail_noop1_fun372(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop1_fun372__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop1_fun372__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop1_fun372, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail_noop1(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d> (op : (c) -> e d) -> clause1<c,d,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail_noop1_fun372(op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never1(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,e,c,d> (op : (a) -> e d) -> clause1<a,b,c,e,d> */ 
 
//inline extern cast-hnd( h : h<e1,r> ) : e h<e,r> { inline "#1"//inline extern cast-marker( m : marker<e1,r> ) : e marker<e,r> { inline "#1"

static inline kk_box_t kk_std_core_hnd__perform0(kk_std_core_hnd__ev ev, kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b> (ev : ev<b>, op : forall<e1,c> (b<e1,c>) -> clause0<a,b,e1,c>) -> e a */ 
  {
    struct kk_std_core_hnd_Ev* _con_x375 = kk_std_core_hnd__as_Ev(ev, _ctx);
    int32_t m = _con_x375->marker;
    kk_box_t h = _con_x375->hnd;
    kk_box_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x239 = kk_function_call(kk_std_core_hnd__clause0, (kk_function_t, kk_box_t, kk_context_t*), op, (op, h, _ctx), _ctx); /*hnd/clause0<5931,5933,1009,1010>*/;
    {
      kk_function_t f = _match_x239.clause;
      return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), f, (f, m, ev, _ctx), _ctx);
    }
  }
}


// lift anonymous function
struct kk_std_core_hnd_under0_fun378__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
extern kk_box_t kk_std_core_hnd_under0_fun378(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_under0_fun378(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun378__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under0_fun378__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under0_fun378, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under0_fun381__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
extern kk_box_t kk_std_core_hnd_under0_fun381(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_under0_fun381(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun381__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under0_fun381__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under0_fun381, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_box_t kk_std_core_hnd_under0(kk_std_core_hnd__ev ev, kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b> (ev : ev<b>, op : () -> e a) -> e a */ 
  kk_evv_t w0;
  kk_evv_t _x_x376;
  {
    struct kk_std_core_hnd_Ev* _con_x377 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x377->hevv;
    kk_evv_dup(w, _ctx);
    _x_x376 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x376,kk_context()); /*hnd/evv<_5955>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx); /*6017*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under0_fun378(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return y;
  }
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control_raw0(kk_function_t op, kk_context_t* _ctx); /* forall<a,e,e1,b,c> (op : (resume-context<a,e,e1,c>) -> e c) -> clause0<a,b,e,c> */ 

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control0(kk_function_t op, kk_context_t* _ctx); /* forall<a,e,b,c> (op : ((a) -> e c) -> e c) -> clause0<a,b,e,c> */ 

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_tail0(kk_function_t op, kk_context_t* _ctx); /* forall<e,a,b,c> (op : () -> e c) -> clause0<c,b,e,a> */ 


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop0_fun395__t {
  struct kk_function_s _base;
  kk_function_t op;
};
extern kk_box_t kk_std_core_hnd_clause_tail_noop0_fun395(kk_function_t _fself, int32_t ___wildcard_x679__14, kk_std_core_hnd__ev ___wildcard_x679__17, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_tail_noop0_fun395(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop0_fun395__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop0_fun395__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop0_fun395, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause0 kk_std_core_hnd_clause_tail_noop0(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c> (op : () -> e c) -> clause0<c,b,e,a> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_tail_noop0_fun395(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_value_fun396__t {
  struct kk_function_s _base;
  kk_box_t v;
};
extern kk_box_t kk_std_core_hnd_clause_value_fun396(kk_function_t _fself, int32_t ___wildcard_x682__14, kk_std_core_hnd__ev ___wildcard_x682__17, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_value_fun396(kk_box_t v, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_value_fun396__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_value_fun396__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_value_fun396, kk_context());
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause0 kk_std_core_hnd_clause_value(kk_box_t v, kk_context_t* _ctx) { /* forall<a,e,b,c> (v : a) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_value_fun396(v, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_never0(kk_function_t op, kk_context_t* _ctx); /* forall<a,e,b,c> (op : () -> e c) -> clause0<a,b,e,c> */ 

kk_box_t kk_std_core_hnd_under2(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx); /* forall<a,b,c,e,d> (ev : ev<d>, op : (a, b) -> e c, x1 : a, x2 : b) -> e c */ 

kk_box_t kk_std_core_hnd_protect2(kk_box_t x1, kk_box_t x2, kk_function_t clause, kk_function_t k, kk_context_t* _ctx); /* forall<a,b,c,e,d> (x1 : a, x2 : b, clause : (x : a, x : b, k : (c) -> e d) -> e d, k : (resume-result<c,d>) -> e d) -> e d */ 


// lift anonymous function
struct kk_std_core_hnd_clause_control2_fun409__t {
  struct kk_function_s _base;
  kk_function_t clause;
};
extern kk_box_t kk_std_core_hnd_clause_control2_fun409(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x711__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_control2_fun409(kk_function_t clause, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun409__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control2_fun409__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control2_fun409, kk_context());
  _self->clause = clause;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control2_fun410__t {
  struct kk_function_s _base;
  kk_function_t clause;
  kk_box_t x1;
  kk_box_t x2;
};
extern kk_box_t kk_std_core_hnd_clause_control2_fun410(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_control2_fun410(kk_function_t clause, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun410__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control2_fun410__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control2_fun410, kk_context());
  _self->clause = clause;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause2 kk_std_core_hnd_clause_control2(kk_function_t clause, kk_context_t* _ctx) { /* forall<a,b,c,e,d,a1> (clause : (x1 : a, x2 : b, k : (c) -> e a1) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_control2_fun409(clause, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_control_raw2(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,e,e1,d,a1> (op : (x1 : a, x2 : b, r : resume-context<c,e,e1,a1>) -> e a1) -> clause2<a,b,c,d,e,a1> */ 


// lift anonymous function
struct kk_std_core_hnd_clause_tail2_fun414__t {
  struct kk_function_s _base;
  kk_function_t op;
};
extern kk_box_t kk_std_core_hnd_clause_tail2_fun414(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_tail2_fun414(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail2_fun414__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail2_fun414__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail2_fun414, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause2 kk_std_core_hnd_clause_tail2(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1> (op : (c, d) -> e a1) -> clause2<c,d,a1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_tail2_fun414(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop2_fun415__t {
  struct kk_function_s _base;
  kk_function_t op;
};
extern kk_box_t kk_std_core_hnd_clause_tail_noop2_fun415(kk_function_t _fself, int32_t ___wildcard_x721__14, kk_std_core_hnd__ev ___wildcard_x721__17, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_tail_noop2_fun415(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop2_fun415__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop2_fun415__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop2_fun415, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause2 kk_std_core_hnd_clause_tail_noop2(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1> (op : (c, d) -> e a1) -> clause2<c,d,a1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_tail_noop2_fun415(op, _ctx), _ctx);
}

static inline kk_box_t kk_std_core_hnd__perform2(kk_std_core_hnd__ev evx, kk_function_t op, kk_box_t x, kk_box_t y, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (evx : ev<d>, op : forall<e1,a1> (d<e1,a1>) -> clause2<a,b,c,d,e1,a1>, x : a, y : b) -> e c */ 
  {
    struct kk_std_core_hnd_Ev* _con_x416 = kk_std_core_hnd__as_Ev(evx, _ctx);
    int32_t m = _con_x416->marker;
    kk_box_t h = _con_x416->hnd;
    kk_box_dup(h, _ctx);
    kk_std_core_hnd__clause2 _match_x230 = kk_function_call(kk_std_core_hnd__clause2, (kk_function_t, kk_box_t, kk_context_t*), op, (op, h, _ctx), _ctx); /*hnd/clause2<7088,7089,7090,7092,1249,1250>*/;
    {
      kk_function_t f = _match_x230.clause;
      return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), f, (f, m, evx, x, y, _ctx), _ctx);
    }
  }
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_never2(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,e,d,a1> (op : (a, b) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
 
// For interal use

static inline kk_box_t kk_std_core_hnd_xperform1(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,c> (ev : ev<c>, op : forall<e1,d> (c<e1,d>) -> clause1<a,b,c,e1,d>, x : a) -> e b */ 
  {
    struct kk_std_core_hnd_Ev* _con_x419 = kk_std_core_hnd__as_Ev(ev, _ctx);
    int32_t m = _con_x419->marker;
    kk_box_t h = _con_x419->hnd;
    kk_box_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x229 = kk_function_call(kk_std_core_hnd__clause1, (kk_function_t, kk_box_t, kk_context_t*), op, (op, h, _ctx), _ctx); /*hnd/clause1<7262,7263,7265,1291,1292>*/;
    {
      kk_function_t f = _match_x229.clause;
      return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), f, (f, m, ev, x, _ctx), _ctx);
    }
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw3(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,d,e,e1,a1,b1> (op : (x1 : a, x2 : b, x3 : c, r : resume-context<d,e,e1,b1>) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control3(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,d,e,a1,b1> (op : (x1 : a, x2 : b, x3 : c, k : (d) -> e b1) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 


// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun426__t {
  struct kk_function_s _base;
  kk_function_t op;
};
extern kk_box_t kk_std_core_hnd_clause_tail3_fun426(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_tail3_fun426(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun426__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun426__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun426, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail3(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1> (op : (c, d, a1) -> e b1) -> clause1<(c, d, a1),b1,b,e,a> */ 
  return kk_std_core_hnd_clause_tail1(kk_std_core_hnd_new_clause_tail3_fun426(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop3_fun427__t {
  struct kk_function_s _base;
  kk_function_t op;
};
extern kk_box_t kk_std_core_hnd_clause_tail_noop3_fun427(kk_function_t _fself, int32_t _b_x126, kk_std_core_hnd__ev _b_x127, kk_box_t _b_x128, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_hnd_new_clause_tail_noop3_fun427(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop3_fun427__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop3_fun427__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop3_fun427, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail_noop3(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1> (op : (c, d, a1) -> e b1) -> clause1<(c, d, a1),b1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail_noop3_fun427(op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never3(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,d,e,a1,b1> (op : (a, b, c) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 

static inline kk_box_t kk_std_core_hnd__perform3(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (ev : ev<a1>, op : forall<e1,b1> (a1<e1,b1>) -> clause1<(a, b, c),d,a1,e1,b1>, x1 : a, x2 : b, x3 : c) -> e d */ 
  {
    struct kk_std_core_hnd_Ev* _con_x430 = kk_std_core_hnd__as_Ev(ev, _ctx);
    int32_t m = _con_x430->marker;
    kk_box_t h = _con_x430->hnd;
    kk_box_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x223 = kk_function_call(kk_std_core_hnd__clause1, (kk_function_t, kk_box_t, kk_context_t*), op, (op, h, _ctx), _ctx); /*hnd/clause1<(7769, 7770, 7771),7772,7774,1447,1448>*/;
    {
      kk_function_t _fun_unbox_x144 = _match_x223.clause;
      kk_box_t _x_x431;
      kk_std_core_types__tuple3 _x_x432 = kk_std_core_types__new_Tuple3(x1, x2, x3, _ctx); /*(136, 137, 138)*/
      _x_x431 = kk_std_core_types__tuple3_box(_x_x432, _ctx); /*45*/
      return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x144, (_fun_unbox_x144, m, ev, _x_x431, _ctx), _ctx);
    }
  }
}

kk_box_t kk_std_core_hnd_under3(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx); /* forall<a,b,c,d,e,a1> (ev : ev<a1>, op : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e d */ 

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control4(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,d,a1,e,b1,c1> (op : (x1 : a, x2 : b, x3 : c, x4 : d, k : (a1) -> e c1) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail4(kk_function_t op, kk_context_t* _ctx); /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail_noop4(kk_function_t op, kk_context_t* _ctx); /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never4(kk_function_t op, kk_context_t* _ctx); /* forall<a,b,c,d,a1,e,b1,c1> (op : (a, b, c, d) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 

static inline kk_box_t kk_std_core_hnd__perform4(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1> (ev : ev<b1>, op : forall<e1,c1> (b1<e1,c1>) -> clause1<(a, b, c, d),a1,b1,e1,c1>, x1 : a, x2 : b, x3 : c, x4 : d) -> e a1 */ 
  {
    struct kk_std_core_hnd_Ev* _con_x450 = kk_std_core_hnd__as_Ev(ev, _ctx);
    int32_t m = _con_x450->marker;
    kk_box_t h = _con_x450->hnd;
    kk_box_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x216 = kk_function_call(kk_std_core_hnd__clause1, (kk_function_t, kk_box_t, kk_context_t*), op, (op, h, _ctx), _ctx); /*hnd/clause1<(8342, 8343, 8344, 8345),8346,8348,1603,1604>*/;
    {
      kk_function_t _fun_unbox_x189 = _match_x216.clause;
      kk_box_t _x_x451;
      kk_std_core_types__tuple4 _x_x452 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x1, x2, x3, x4, _ctx); /*(145, 146, 147, 148)*/
      _x_x451 = kk_std_core_types__tuple4_box(_x_x452, _ctx); /*45*/
      return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x189, (_fun_unbox_x189, m, ev, _x_x451, _ctx), _ctx);
    }
  }
}

kk_box_t kk_std_core_hnd_under4(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx); /* forall<a,b,c,d,a1,e,b1> (ev : ev<b1>, op : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e a1 */ 

static inline kk_box_t kk_std_core_hnd__open_none0(kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (f : () -> e a) -> e1 a */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<8526>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*8524*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

static inline kk_box_t kk_std_core_hnd__open_none1(kk_function_t f, kk_box_t x1, kk_context_t* _ctx) { /* forall<a,b,e,e1> (f : (a) -> e b, x1 : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<8582>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x1, _ctx), _ctx); /*8580*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

static inline kk_box_t kk_std_core_hnd__open_none2(kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<8649>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*8647*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

static inline kk_box_t kk_std_core_hnd__open_none3(kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<8727>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*8725*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

static inline kk_box_t kk_std_core_hnd__open_none4(kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<8816>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*8814*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

kk_box_t kk_std_core_hnd_open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx); /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 

kk_box_t kk_std_core_hnd__open_at0(kk_ssize_t i, kk_function_t f, kk_context_t* _ctx); /* forall<a,e,e1> (i : ev-index, f : () -> e a) -> e1 a */ 

kk_box_t kk_std_core_hnd__open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx); /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 

kk_box_t kk_std_core_hnd__open_at2(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx); /* forall<a,b,c,e,e1> (i : ev-index, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 

kk_box_t kk_std_core_hnd__open_at3(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx); /* forall<a,b,c,d,e,e1> (i : ev-index, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 

kk_box_t kk_std_core_hnd__open_at4(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx); /* forall<a,b,c,d,a1,e,e1> (i : ev-index, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 

kk_box_t kk_std_core_hnd_open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx); /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 

kk_box_t kk_std_core_hnd__open0(kk_vector_t indices, kk_function_t f, kk_context_t* _ctx); /* forall<a,e,e1> (indices : vector<ev-index>, f : () -> e a) -> e1 a */ 

kk_box_t kk_std_core_hnd__open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx); /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 

kk_box_t kk_std_core_hnd__open2(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx); /* forall<a,b,c,e,e1> (indices : vector<ev-index>, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 

kk_box_t kk_std_core_hnd__open3(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx); /* forall<a,b,c,d,e,e1> (indices : vector<ev-index>, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 

kk_box_t kk_std_core_hnd__open4(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx); /* forall<a,b,c,d,a1,e,e1> (indices : vector<ev-index>, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 

kk_std_core_types__either kk_std_core_hnd_try_finalize_prompt(kk_box_t res, kk_context_t* _ctx); /* forall<a,e> (res : a) -> e either<yield-info,a> */ 

static inline kk_std_core_types__either kk_std_core_hnd_unsafe_try_finalize(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> e a) -> e either<yield-info,a> */ 
  kk_box_t _x_x481 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*10295*/
  return kk_std_core_hnd_try_finalize_prompt(_x_x481, _ctx);
}

void kk_std_core_hnd__init(kk_context_t* _ctx);


void kk_std_core_hnd__done(kk_context_t* _ctx);

#endif // header
