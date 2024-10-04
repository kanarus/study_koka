// Koka generated module: std/core/sslice, koka version: 3.1.2, platform: 64-bit
#include "std_core_sslice.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static inline void kk_sslice_start_end_borrowx( kk_std_core_sslice__sslice sslice, const uint8_t** start, const uint8_t** end, const uint8_t** sstart, const uint8_t** send, kk_context_t* ctx) {
  kk_ssize_t strlen;
  const uint8_t* s = kk_string_buf_borrow(sslice.str,&strlen,ctx);
  kk_ssize_t slstart = kk_integer_clamp_ssize_t_borrow(sslice.start,ctx);
  kk_ssize_t sllen   = kk_integer_clamp_ssize_t_borrow(sslice.len,ctx);
  *start = s + slstart;
  *end = s + slstart + sllen;
  if (sstart != NULL) *sstart = s;
  if (send != NULL) *send = s + strlen;
  kk_assert_internal(*start >= s && *start <= *end);
  kk_assert_internal(*end >= *start && *end <= s + strlen);
}

static inline void kk_sslice_start_end_borrow( kk_std_core_sslice__sslice sslice, const uint8_t** start, const uint8_t** end, kk_context_t* ctx) {
  kk_sslice_start_end_borrowx(sslice,start,end,NULL,NULL,ctx);
}

kk_integer_t kk_slice_count( kk_std_core_sslice__sslice sslice, kk_context_t* ctx ) {
  // TODO: optimize this by extending kk_string_count
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end, ctx);
  kk_ssize_t count = 0;
  while( start < end && *start != 0 ) {
    const uint8_t* next = kk_utf8_next(start);
    count++;
    start = next;
  }
  kk_std_core_sslice__sslice_drop(sslice,ctx);
  return kk_integer_from_ssize_t(count,ctx);
}

kk_string_t kk_slice_to_string( kk_std_core_sslice__sslice  sslice, kk_context_t* ctx ) {
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end, ctx);
  // is it the full string?
  if (kk_integer_is_zero_borrow(sslice.start) &&
      kk_integer_eq_borrow(sslice.len,kk_integer_from_ssize_t(kk_string_len_borrow(sslice.str,ctx),ctx),ctx)) {
    // TODO: drop sslice and dup sslice.str?
    return sslice.str;
  }
  else {
    // if not, we copy len bytes
    kk_string_t s = kk_string_alloc_dupn_valid_utf8(kk_integer_clamp_ssize_t_borrow(sslice.len,ctx), start, ctx);
    kk_std_core_sslice__sslice_drop(sslice,ctx);
    return s;
  }
}

kk_std_core_sslice__sslice kk_slice_first( kk_string_t str, kk_context_t* ctx ) {
  kk_ssize_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen,ctx);
  const uint8_t* next = (slen > 0 ? kk_utf8_next(s) : s);
  return kk_std_core_sslice__new_Sslice(str, kk_integer_zero, kk_integer_from_ptrdiff_t(next - s,ctx), ctx);
}

kk_std_core_sslice__sslice kk_slice_last( kk_string_t str, kk_context_t* ctx ) {
  kk_ssize_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen,ctx);
  const uint8_t* end = s + slen;
  const uint8_t* prev = (s==end ? s : kk_utf8_prev(end));
  return kk_std_core_sslice__new_Sslice(str, kk_integer_from_ptrdiff_t(prev - s,ctx), kk_integer_from_ptrdiff_t(end - prev,ctx), ctx);
}

kk_std_core_sslice__sslice kk_slice_between( struct kk_std_core_sslice_Sslice slice1, struct kk_std_core_sslice_Sslice slice2, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow( slice1.str, NULL, ctx );
  const uint8_t* s2 = kk_string_buf_borrow( slice2.str, NULL, ctx );
  if (s1 != s2) {
    kk_info_message("between: not equal slices: %p vs. %p\n", s1, s2);
    return kk_std_core_sslice__new_Sslice(kk_string_empty(), kk_integer_zero, kk_integer_min_one, ctx); // invalid slice
  }

  kk_integer_t start;
  kk_integer_t len;
  if (kk_integer_lte_borrow(slice1.start,slice2.start,ctx)) {
    start = kk_integer_dup(slice1.start,ctx);
    len   = kk_integer_sub(kk_integer_dup(slice2.start,ctx),kk_integer_dup(slice1.start,ctx),ctx);
  }
  else  {
    start = kk_integer_dup(slice2.start,ctx);
    len   = kk_integer_sub(kk_integer_dup(slice1.start,ctx),kk_integer_dup(slice2.start,ctx),ctx);
  }
  return kk_std_core_sslice__new_Sslice(slice1.str, start, len, ctx);
}

kk_std_core_types__maybe kk_slice_next( struct kk_std_core_sslice_Sslice slice, kk_context_t* ctx ) {
  if (!kk_integer_is_pos_borrow(slice.len,ctx)) {
    kk_std_core_sslice__sslice_drop(slice,ctx);
    return kk_std_core_types__new_Nothing(ctx);
  }
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(slice, &start, &end, ctx);
  kk_ssize_t clen;
  const kk_char_t c = kk_utf8_read(start,&clen);
  kk_assert_internal(clen > 0 && clen <= kk_integer_clamp_ssize_t_borrow(slice.len,ctx));
  kk_integer_t iclen = kk_integer_min(kk_integer_from_ssize_t(clen,ctx),kk_integer_dup(slice.len,ctx),ctx);
  // TODO: specialize type to avoid boxing
  // note: don't drop slice as we take over all fields
  kk_integer_t istart = kk_integer_add(slice.start,kk_integer_dup(iclen,ctx),ctx);
  kk_integer_t ilen   = kk_integer_sub(slice.len,iclen,ctx);
  kk_std_core_sslice__sslice snext = kk_std_core_sslice__new_Sslice(slice.str, istart, ilen, ctx);
  kk_std_core_types__tuple2 res = kk_std_core_types__new_Tuple2( kk_char_box(c,ctx), kk_std_core_sslice__sslice_box(snext,ctx), ctx);
  return kk_std_core_types__new_Just( kk_std_core_types__tuple2_box(res,ctx), ctx );
}

/* Borrow count */
struct kk_std_core_sslice_Sslice kk_slice_extend_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  kk_ssize_t cnt = kk_integer_clamp_ssize_t_borrow(count,ctx);
  if (cnt==0 || (!kk_integer_is_pos_borrow(slice.len,ctx) && cnt<0)) return slice;
  const uint8_t* s0;
  const uint8_t* s1;
  kk_sslice_start_end_borrow(slice,&s0,&s1,ctx);
  const uint8_t* t  = s1;
  if (cnt >= 0) {
    do {
      t = kk_utf8_next(t);
      cnt--;
    } while (cnt > 0 && *t != 0);
  }
  else {  // cnt < 0
    const uint8_t* sstart = s0 - kk_integer_clamp_ssize_t_borrow(slice.start,ctx);
    do {
      t = kk_utf8_prev(t);
      cnt++;
    } while (cnt < 0 && t > sstart);
  }
  if (t == s1) return slice;  // length is unchanged
  kk_integer_drop(slice.len,ctx);
  return kk_std_core_sslice__new_Sslice(slice.str, slice.start, kk_integer_from_ptrdiff_t(t < s0 ? 0 : (t - s0),ctx), ctx);
}

/* Borrow count */
struct kk_std_core_sslice_Sslice kk_slice_advance_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  const kk_ssize_t cnt0 = kk_integer_clamp_ssize_t_borrow(count,ctx);
  kk_ssize_t cnt = cnt0;
  if (cnt==0) return slice;
  const uint8_t* sstart;
  const uint8_t* s0;
  const uint8_t* s1;
  const uint8_t* send;
  kk_sslice_start_end_borrowx(slice,&s0,&s1,&sstart,&send,ctx);
  // advance the start
  const uint8_t* t0  = s0;
  if (cnt >= 0) {
    while (cnt > 0 && t0 < send) {
      t0 = kk_utf8_next(t0);
      cnt--;
    }
  }
  else {  // cnt < 0
    while (cnt < 0 && t0 > sstart) {
      t0 = kk_utf8_prev(t0);
      cnt++;
    }
  }
  if (t0 == s0 && cnt0 > 0) return slice;  // start is unchanged
  // "t0" points to the new start, now advance the end by the same amount of codepoints
  const uint8_t* t1 = s1;
  cnt = cnt0;
  if (cnt >= 0) {
    while (cnt > 0 && t1 < send) {
      t1 = kk_utf8_next(t1);
      cnt--;
    }
  }
  else {  // cnt < 0
    while (cnt < 0 && t1 > sstart) {
      t1 = kk_utf8_prev(t1);
      cnt++;
    }
  }
  // t1 points to the new end
  kk_assert_internal(t1 >= t0);
  const kk_ssize_t in_len = kk_integer_clamp_ssize_t_borrow(slice.len, ctx);
  kk_ssize_t new_len = (t1-t0);
  // kk_info_message("Here %d %d %d t: %d %d s: %d %d, st: %d %d\n", in_len, cnt0, new_len, t1, t0, s1, s0, sstart, send);
  kk_assert_internal(t1 <= send && t0 >= sstart);
  kk_integer_drop(slice.start,ctx);
  kk_integer_drop(slice.len,ctx);
  return kk_std_core_sslice__new_Sslice(slice.str, kk_integer_from_ptrdiff_t(t0 - sstart,ctx),
                                          kk_integer_from_ptrdiff_t(new_len, ctx), ctx);
}

/* Borrow iupto */
struct kk_std_core_sslice_Sslice kk_slice_common_prefix_borrow( kk_string_t str1, kk_string_t str2, kk_integer_t iupto, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow(str1,NULL,ctx);
  const uint8_t* s2 = kk_string_buf_borrow(str2,NULL,ctx);
  kk_ssize_t upto = kk_integer_clamp_ssize_t_borrow(iupto,ctx);
  kk_ssize_t count;
  for(count = 0; count < upto && *s1 != 0 && *s2 != 0; count++, s1++, s2++ ) {
    if (*s1 != *s2) break;
  }
  kk_string_drop(str2,ctx);
  return kk_std_core_sslice__new_Sslice(str1, kk_integer_zero, kk_integer_from_ssize_t(count,ctx), ctx);
}


kk_std_core_sslice__sslice kk_std_core_sslice_sslice_fs__copy(kk_std_core_sslice__sslice _this, kk_std_core_types__optional str, kk_std_core_types__optional start, kk_std_core_types__optional len, kk_context_t* _ctx) { /* (sslice, str : ? string, start : ? int, len : ? int) -> sslice */ 
  kk_string_t _x_x191;
  if (kk_std_core_types__is_Optional(str, _ctx)) {
    kk_box_t _box_x0 = str._cons._Optional.value;
    kk_string_t _uniq_str_143 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_str_143, _ctx);
    kk_std_core_types__optional_drop(str, _ctx);
    _x_x191 = _uniq_str_143; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(str, _ctx);
    {
      kk_string_t _x = _this.str;
      kk_string_dup(_x, _ctx);
      _x_x191 = _x; /*string*/
    }
  }
  kk_integer_t _x_x192;
  if (kk_std_core_types__is_Optional(start, _ctx)) {
    kk_box_t _box_x1 = start._cons._Optional.value;
    kk_integer_t _uniq_start_150 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_start_150, _ctx);
    kk_std_core_types__optional_drop(start, _ctx);
    _x_x192 = _uniq_start_150; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(start, _ctx);
    {
      kk_integer_t _x_0 = _this.start;
      kk_integer_dup(_x_0, _ctx);
      _x_x192 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x193;
  if (kk_std_core_types__is_Optional(len, _ctx)) {
    kk_box_t _box_x2 = len._cons._Optional.value;
    kk_integer_t _uniq_len_157 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_len_157, _ctx);
    kk_std_core_types__optional_drop(len, _ctx);
    kk_std_core_sslice__sslice_drop(_this, _ctx);
    _x_x193 = _uniq_len_157; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(len, _ctx);
    {
      kk_integer_t _x_1 = _this.len;
      kk_integer_dup(_x_1, _ctx);
      kk_std_core_sslice__sslice_drop(_this, _ctx);
      _x_x193 = _x_1; /*int*/
    }
  }
  return kk_std_core_sslice__new_Sslice(_x_x191, _x_x192, _x_x193, _ctx);
}
 
// O(n). Copy the `slice` argument into a fresh string.
// Takes O(1) time if the slice covers the entire string.

kk_string_t kk_std_core_sslice_string(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> string */ 
  return kk_slice_to_string(slice_0,kk_context());
}
 
// Equality based on contents of the slice
// O(`n`+`m`) where `n` and `m` are the lengths of the two strings

bool kk_std_core_sslice__lp__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  {
    kk_string_t s1 = slice1.str;
    kk_integer_t start1 = slice1.start;
    kk_integer_t len1 = slice1.len;
    kk_string_t s2 = slice2.str;
    kk_integer_t start2 = slice2.start;
    kk_integer_t len2 = slice2.len;
    kk_integer_dup(len1, _ctx);
    kk_integer_dup(len2, _ctx);
    kk_string_dup(s1, _ctx);
    kk_string_dup(s2, _ctx);
    kk_integer_dup(start1, _ctx);
    kk_integer_dup(start2, _ctx);
    bool _match_x186 = kk_box_eq((kk_string_box(s1)),(kk_string_box(s2))); /*bool*/;
    if (_match_x186) {
      bool _match_x187;
      bool _brw_x190 = kk_integer_eq_borrow(start1,start2,kk_context()); /*bool*/;
      kk_integer_drop(start1, _ctx);
      kk_integer_drop(start2, _ctx);
      _match_x187 = _brw_x190; /*bool*/
      if (_match_x187) {
        bool _match_x188;
        bool _brw_x189 = kk_integer_eq_borrow(len1,len2,kk_context()); /*bool*/;
        kk_integer_drop(len1, _ctx);
        kk_integer_drop(len2, _ctx);
        _match_x188 = _brw_x189; /*bool*/
        if (_match_x188) {
          kk_std_core_sslice__sslice_drop(slice2, _ctx);
          kk_std_core_sslice__sslice_drop(slice1, _ctx);
          return true;
        }
        {
          kk_string_t _x_x194 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
          kk_string_t _x_x195 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
          return kk_string_is_eq(_x_x194,_x_x195,kk_context());
        }
      }
      {
        kk_integer_drop(len2, _ctx);
        kk_integer_drop(len1, _ctx);
        kk_string_t _x_x196 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
        kk_string_t _x_x197 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
        return kk_string_is_eq(_x_x196,_x_x197,kk_context());
      }
    }
    {
      kk_integer_drop(start2, _ctx);
      kk_integer_drop(start1, _ctx);
      kk_integer_drop(len2, _ctx);
      kk_integer_drop(len1, _ctx);
      kk_string_t _x_x198 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
      kk_string_t _x_x199 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
      return kk_string_is_eq(_x_x198,_x_x199,kk_context());
    }
  }
}
 
// Equality of slices at the same offset and length on an equal string
// (The strings do not have to be referentially identical though)

bool kk_std_core_sslice__lp__eq__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  {
    kk_string_t s1 = slice1.str;
    kk_integer_t start1 = slice1.start;
    kk_integer_t len1 = slice1.len;
    kk_string_t s2 = slice2.str;
    kk_integer_t start2 = slice2.start;
    kk_integer_t len2 = slice2.len;
    bool _match_x182;
    bool _brw_x185 = kk_integer_eq_borrow(start1,start2,kk_context()); /*bool*/;
    kk_integer_drop(start1, _ctx);
    kk_integer_drop(start2, _ctx);
    _match_x182 = _brw_x185; /*bool*/
    if (_match_x182) {
      bool _match_x183;
      bool _brw_x184 = kk_integer_eq_borrow(len1,len2,kk_context()); /*bool*/;
      kk_integer_drop(len1, _ctx);
      kk_integer_drop(len2, _ctx);
      _match_x183 = _brw_x184; /*bool*/
      if (_match_x183) {
        return kk_string_is_eq(s1,s2,kk_context());
      }
      {
        kk_string_drop(s2, _ctx);
        kk_string_drop(s1, _ctx);
        return false;
      }
    }
    {
      kk_string_drop(s2, _ctx);
      kk_string_drop(s1, _ctx);
      kk_integer_drop(len2, _ctx);
      kk_integer_drop(len1, _ctx);
      return false;
    }
  }
}
 
// O(n). Return the number of characters in a string slice

kk_integer_t kk_std_core_sslice_count(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> int */ 
  return kk_slice_count(slice_0,kk_context());
}

kk_std_core_sslice__sslice kk_std_core_sslice_first1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_first(s,kk_context());
}

kk_std_core_sslice__sslice kk_std_core_sslice_last1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_last(s,kk_context());
}
 
// If the slice is not empty,
// return the first character, and a new slice that is advanced by 1.

kk_std_core_types__maybe kk_std_core_sslice_next(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> maybe<(char, sslice)> */ 
  return kk_slice_next(slice_0,kk_context());
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_sslice__mlift_foreach_while_10115(kk_function_t action, kk_std_core_sslice__sslice rest, kk_std_core_types__maybe _y_x10092, kk_context_t* _ctx) { /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10092, _ctx)) {
    return kk_std_core_sslice_foreach_while(rest, action, _ctx);
  }
  {
    kk_std_core_sslice__sslice_drop(rest, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10092;
  }
}
 
// Apply a function for each character in a string slice.
// If `action` returns `Just`, the function returns immediately with that result.


// lift anonymous function
struct kk_std_core_sslice_foreach_while_fun204__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_sslice__sslice rest_0;
};
static kk_box_t kk_std_core_sslice_foreach_while_fun204(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_foreach_while_fun204(kk_function_t action_0, kk_std_core_sslice__sslice rest_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_foreach_while_fun204__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_foreach_while_fun204__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_foreach_while_fun204, kk_context());
  _self->action_0 = action_0;
  _self->rest_0 = rest_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_foreach_while_fun204(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx) {
  struct kk_std_core_sslice_foreach_while_fun204__t* _self = kk_function_as(struct kk_std_core_sslice_foreach_while_fun204__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (c : char) -> 442 maybe<441> */
  kk_std_core_sslice__sslice rest_0 = _self->rest_0; /* sslice/sslice */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_sslice__sslice_dup(rest_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10092_0_13 = kk_std_core_types__maybe_unbox(_b_x11, KK_OWNED, _ctx); /*maybe<441>*/;
  kk_std_core_types__maybe _x_x205 = kk_std_core_sslice__mlift_foreach_while_10115(action_0, rest_0, _y_x10092_0_13, _ctx); /*maybe<441>*/
  return kk_std_core_types__maybe_box(_x_x205, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_foreach_while(kk_std_core_sslice__sslice slice_0, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x180 = kk_std_core_sslice_next(slice_0, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x180, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x7 = _match_x180._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1 = kk_std_core_types__tuple2_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_box_t _box_x8 = _pat_1.fst;
    kk_box_t _box_x9 = _pat_1.snd;
    kk_std_core_sslice__sslice rest_0 = kk_std_core_sslice__sslice_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_char_t c = kk_char_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest_0, _ctx);
    kk_std_core_types__maybe_drop(_match_x180, _ctx);
    kk_std_core_types__maybe x_10124;
    kk_function_t _x_x202 = kk_function_dup(action_0, _ctx); /*(c : char) -> 442 maybe<441>*/
    x_10124 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_char_t, kk_context_t*), _x_x202, (_x_x202, c, _ctx), _ctx); /*maybe<441>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10124, _ctx);
      kk_box_t _x_x203 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_new_foreach_while_fun204(action_0, rest_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x203, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_10124, _ctx)) { // tailcall
                                                        slice_0 = rest_0;
                                                        goto kk__tailcall;
    }
    {
      kk_std_core_sslice__sslice_drop(rest_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_10124;
    }
  }
}
 
// Apply a function for each character in a string slice.


// lift anonymous function
struct kk_std_core_sslice_foreach_fun209__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_std_core_types__maybe kk_std_core_sslice_foreach_fun209(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_foreach_fun209(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_sslice_foreach_fun209__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_foreach_fun209__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_foreach_fun209, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_sslice_foreach_fun211__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_foreach_fun211(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_foreach_fun211(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_foreach_fun211, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_foreach_fun211(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_box_drop(_b_x15, _ctx);
  return kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx);
}
static kk_std_core_types__maybe kk_std_core_sslice_foreach_fun209(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_sslice_foreach_fun209__t* _self = kk_function_as(struct kk_std_core_sslice_foreach_fun209__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* (c : char) -> 517 () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_unit_t x_0_10130 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), action, (action, c, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x210 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_new_foreach_fun211(_ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x210, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_core_sslice_foreach_fun213__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_foreach_fun213(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_foreach_fun213(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_foreach_fun213, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_foreach_fun213(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__maybe wild___0_0_21 = kk_std_core_types__maybe_unbox(_b_x19, KK_OWNED, _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(wild___0_0_21, _ctx);
  return kk_unit_box(kk_Unit);
}

kk_unit_t kk_std_core_sslice_foreach(kk_std_core_sslice__sslice slice_0, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 
  kk_std_core_types__maybe x_10127 = kk_std_core_sslice_foreach_while(slice_0, kk_std_core_sslice_new_foreach_fun209(action, _ctx), _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(x_10127, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x212 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_new_foreach_fun213(_ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x212); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// Invoke a function for each character in a string


// lift anonymous function
struct kk_std_core_sslice_string_fs_foreach_fun216__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_std_core_types__maybe kk_std_core_sslice_string_fs_foreach_fun216(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_string_fs_new_foreach_fun216(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_sslice_string_fs_foreach_fun216__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_string_fs_foreach_fun216__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_string_fs_foreach_fun216, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_sslice_string_fs_foreach_fun218__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_string_fs_foreach_fun218(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_string_fs_new_foreach_fun218(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_string_fs_foreach_fun218, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_string_fs_foreach_fun218(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_box_drop(_b_x23, _ctx);
  return kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx);
}
static kk_std_core_types__maybe kk_std_core_sslice_string_fs_foreach_fun216(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_sslice_string_fs_foreach_fun216__t* _self = kk_function_as(struct kk_std_core_sslice_string_fs_foreach_fun216__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* (c : char) -> 539 () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_unit_t x_0_10137 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), action, (action, c, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x217 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_string_fs_new_foreach_fun218(_ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x217, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_core_sslice_string_fs_foreach_fun220__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_string_fs_foreach_fun220(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_string_fs_new_foreach_fun220(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_string_fs_foreach_fun220, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_string_fs_foreach_fun220(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__maybe wild___0_0_29 = kk_std_core_types__maybe_unbox(_b_x27, KK_OWNED, _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(wild___0_0_29, _ctx);
  return kk_unit_box(kk_Unit);
}

kk_unit_t kk_std_core_sslice_string_fs_foreach(kk_string_t s, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */ 
  kk_std_core_sslice__sslice slice_0_10005;
  kk_string_t _x_x214 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x215 = kk_string_len_int(s,kk_context()); /*int*/
  slice_0_10005 = kk_std_core_sslice__new_Sslice(_x_x214, kk_integer_from_small(0), _x_x215, _ctx); /*sslice/sslice*/
  kk_std_core_types__maybe x_10134 = kk_std_core_sslice_foreach_while(slice_0_10005, kk_std_core_sslice_string_fs_new_foreach_fun216(action, _ctx), _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(x_10134, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x219 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_string_fs_new_foreach_fun220(_ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x219); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun223__t {
  struct kk_function_s _base;
  kk_ref_t cnt;
};
static kk_unit_t kk_std_core_sslice_pred_fs__mlift_count_10122_fun223(kk_function_t _fself, kk_integer_t _y_x10103, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_count_10122_fun223(kk_ref_t cnt, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun223__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun223__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__mlift_count_10122_fun223, kk_context());
  _self->cnt = cnt;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_std_core_sslice_pred_fs__mlift_count_10122_fun223(kk_function_t _fself, kk_integer_t _y_x10103, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun223__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun223__t*, _fself, _ctx);
  kk_ref_t cnt = _self->cnt; /* local-var<638,int> */
  kk_drop_match(_self, {kk_ref_dup(cnt, _ctx);}, {}, _ctx)
  kk_integer_t _b_x37_39 = kk_integer_add_small_const(_y_x10103, 1, _ctx); /*int*/;
  kk_unit_t _brw_x174 = kk_Unit;
  kk_ref_set_borrow(cnt,(kk_integer_box(_b_x37_39, _ctx)),kk_context());
  kk_ref_drop(cnt, _ctx);
  _brw_x174; return kk_Unit;
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun225__t {
  struct kk_function_s _base;
  kk_function_t next_1_10144;
};
static kk_box_t kk_std_core_sslice_pred_fs__mlift_count_10122_fun225(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_count_10122_fun225(kk_function_t next_1_10144, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun225__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun225__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__mlift_count_10122_fun225, kk_context());
  _self->next_1_10144 = next_1_10144;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__mlift_count_10122_fun225(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun225__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun225__t*, _fself, _ctx);
  kk_function_t next_1_10144 = _self->next_1_10144; /* (int) -> <local<638>|642> () */
  kk_drop_match(_self, {kk_function_dup(next_1_10144, _ctx);}, {}, _ctx)
  kk_unit_t _x_x226 = kk_Unit;
  kk_integer_t _x_x227 = kk_integer_unbox(_b_x41, _ctx); /*int*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), next_1_10144, (next_1_10144, _x_x227, _ctx), _ctx);
  return kk_unit_box(_x_x226);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_count_10122_fun229__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_pred_fs__mlift_count_10122_fun229(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_count_10122_fun229(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_pred_fs__mlift_count_10122_fun229, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__mlift_count_10122_fun229(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_unit_t _c_x10105_46 = kk_Unit;
  kk_unit_unbox(_b_x44);
  return kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__mlift_count_10122(kk_ref_t cnt, bool _y_x10102, kk_context_t* _ctx) { /* forall<_a,h,e> (cnt : local-var<h,int>, bool) -> <local<h>|e> maybe<_a> */ 
  kk_unit_t x_10141 = kk_Unit;
  if (_y_x10102) {
    kk_integer_t x_0_10143;
    kk_box_t _x_x221;
    kk_ref_t _x_x222 = kk_ref_dup(cnt, _ctx); /*local-var<638,int>*/
    _x_x221 = kk_ref_get(_x_x222,kk_context()); /*1909*/
    x_0_10143 = kk_integer_unbox(_x_x221, _ctx); /*int*/
    kk_function_t next_1_10144 = kk_std_core_sslice_pred_fs__new_mlift_count_10122_fun223(cnt, _ctx); /*(int) -> <local<638>|642> ()*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10143, _ctx);
      kk_box_t _x_x224 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_mlift_count_10122_fun225(next_1_10144, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x224);
    }
    else {
      kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), next_1_10144, (next_1_10144, x_0_10143, _ctx), _ctx);
    }
  }
  else {
    kk_ref_drop(cnt, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x228 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_mlift_count_10122_fun229(_ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x228, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Count the number of times a predicate is true for each character in a string


// lift anonymous function
struct kk_std_core_sslice_pred_fs_count_fun234__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_sslice_pred_fs_count_fun234(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs_new_count_fun234(kk_ref_t loc, kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun234__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs_count_fun234__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs_count_fun234, kk_context());
  _self->loc = loc;
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_sslice_pred_fs_count_fun236__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_core_sslice_pred_fs_count_fun236(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs_new_count_fun236(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun236__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs_count_fun236__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs_count_fun236, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs_count_fun236(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun236__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs_count_fun236__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<638,int> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x237;
  bool _x_x238 = kk_bool_unbox(_b_x52); /*bool*/
  _x_x237 = kk_std_core_sslice_pred_fs__mlift_count_10122(loc, _x_x238, _ctx); /*maybe<_505>*/
  return kk_std_core_types__maybe_box(_x_x237, _ctx);
}
static kk_std_core_types__maybe kk_std_core_sslice_pred_fs_count_fun234(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun234__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs_count_fun234__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<638,int> */
  kk_function_t pred = _self->pred; /* (char) -> 642 bool */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_function_dup(pred, _ctx);}, {}, _ctx)
  bool x_0_10152 = kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), pred, (pred, c, _ctx), _ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x235 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs_new_count_fun236(loc, _ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x235, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_sslice_pred_fs__mlift_count_10122(loc, x_0_10152, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs_count_fun241__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_core_sslice_pred_fs_count_fun241(kk_function_t _fself, kk_box_t _b_x57, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs_new_count_fun241(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun241__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs_count_fun241__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs_count_fun241, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs_count_fun241(kk_function_t _fself, kk_box_t _b_x57, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun241__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs_count_fun241__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<638,int> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x57, _ctx);
  return kk_ref_get(loc,kk_context());
}

kk_integer_t kk_std_core_sslice_pred_fs_count(kk_string_t s, kk_function_t pred, kk_context_t* _ctx) { /* forall<e> (s : string, pred : (char) -> e bool) -> e int */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<638,int>*/;
  kk_std_core_sslice__sslice slice_0_10010;
  kk_string_t _x_x231 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x232 = kk_string_len_int(s,kk_context()); /*int*/
  slice_0_10010 = kk_std_core_sslice__new_Sslice(_x_x231, kk_integer_from_small(0), _x_x232, _ctx); /*sslice/sslice*/
  kk_std_core_types__maybe x_10150;
  kk_function_t _x_x233;
  kk_ref_dup(loc, _ctx);
  _x_x233 = kk_std_core_sslice_pred_fs_new_count_fun234(loc, pred, _ctx); /*(c : char) -> <local<638>|642> maybe<_505>*/
  x_10150 = kk_std_core_sslice_foreach_while(slice_0_10010, _x_x233, _ctx); /*maybe<_505>*/
  kk_std_core_types__maybe_drop(x_10150, _ctx);
  kk_integer_t res;
  kk_box_t _x_x239;
  if (kk_yielding(kk_context())) {
    kk_function_t _x_x240;
    kk_ref_dup(loc, _ctx);
    _x_x240 = kk_std_core_sslice_pred_fs_new_count_fun241(loc, _ctx); /*(2977) -> 2979 1927*/
    _x_x239 = kk_std_core_hnd_yield_extend(_x_x240, _ctx); /*2978*/
  }
  else {
    kk_ref_t _x_x242 = kk_ref_dup(loc, _ctx); /*local-var<638,int>*/
    _x_x239 = kk_ref_get(_x_x242,kk_context()); /*2978*/
  }
  res = kk_integer_unbox(_x_x239, _ctx); /*int*/
  kk_box_t _x_x243 = kk_std_core_hnd_prompt_local_var(loc, kk_integer_box(res, _ctx), _ctx); /*9564*/
  return kk_integer_unbox(_x_x243, _ctx);
}
 
// O(`count`). Advance the start position of a string slice by `count` characters
// up to the end of the string.
// A negative `count` advances the start position backwards upto the first position
// in a string.
// Maintains the character count of the original slice upto the end of the string.
// For example:
//
// * `"abc".first.advance(1).string == "b"`,
// * `"abc".first.advance(3).string == ""`,
// * `"abc".last.advance(-1).string == "b"`.
//

kk_std_core_sslice__sslice kk_std_core_sslice_advance(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_advance_borrow(slice_0,count_0,kk_context());
}
 
// O(`count`). Extend a string slice by `count` characters up to the end of the string.
// A negative `count` shrinks the slice up to the empty slice.
// For example:
//
// * `"abc".first.extend(1).string == "ab"`
// * `"abc".last.extend(-1).string == ""`
//

kk_std_core_sslice__sslice kk_std_core_sslice_extend(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_extend_borrow(slice_0,count_0,kk_context());
}
 
// O(`n`). The first `n` (default = `1`) characters in a string.

kk_std_core_sslice__sslice kk_std_core_sslice_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : ? int) -> sslice */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  bool _match_x165;
  kk_integer_t _brw_x168;
  if (kk_std_core_types__is_Optional(n, _ctx)) {
    kk_box_t _box_x67 = n._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x67, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    _brw_x168 = _uniq_n_665; /*int*/
  }
  else {
    _brw_x168 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x169 = kk_integer_eq_borrow(_brw_x168,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x168, _ctx);
  _match_x165 = _brw_x169; /*bool*/
  if (_match_x165) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_integer_t _brw_x166;
    kk_integer_t _x_x244;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x68 = n._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x68, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x244 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x244 = kk_integer_from_small(1); /*int*/
    }
    _brw_x166 = kk_integer_add_small_const(_x_x244, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x167 = kk_std_core_sslice_extend(slice_0, _brw_x166, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x166, _ctx);
    return _brw_x167;
  }
}
 
// O(`n`). The last `n` (default = `1`) characters in a string

kk_std_core_sslice__sslice kk_std_core_sslice_last(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : ? int) -> sslice */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_last1(s, _ctx); /*sslice/sslice*/;
  bool _match_x157;
  kk_integer_t _brw_x163;
  if (kk_std_core_types__is_Optional(n, _ctx)) {
    kk_box_t _box_x69 = n._cons._Optional.value;
    kk_integer_t _uniq_n_697 = kk_integer_unbox(_box_x69, _ctx);
    kk_integer_dup(_uniq_n_697, _ctx);
    _brw_x163 = _uniq_n_697; /*int*/
  }
  else {
    _brw_x163 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x164 = kk_integer_eq_borrow(_brw_x163,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x163, _ctx);
  _match_x157 = _brw_x164; /*bool*/
  if (_match_x157) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice _own_x159;
    kk_integer_t _brw_x160;
    kk_integer_t _x_x245;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x70 = n._cons._Optional.value;
      kk_integer_t _uniq_n_697_0 = kk_integer_unbox(_box_x70, _ctx);
      kk_integer_dup(_uniq_n_697_0, _ctx);
      _x_x245 = _uniq_n_697_0; /*int*/
    }
    else {
      _x_x245 = kk_integer_from_small(1); /*int*/
    }
    _brw_x160 = kk_integer_sub((kk_integer_from_small(1)),_x_x245,kk_context()); /*int*/
    kk_std_core_sslice__sslice _brw_x161 = kk_std_core_sslice_advance(slice_0, _brw_x160, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x160, _ctx);
    _own_x159 = _brw_x161; /*sslice/sslice*/
    kk_integer_t _brw_x158;
    kk_integer_t _x_x246;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x71 = n._cons._Optional.value;
      kk_integer_t _uniq_n_697_1 = kk_integer_unbox(_box_x71, _ctx);
      kk_integer_dup(_uniq_n_697_1, _ctx);
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x246 = _uniq_n_697_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x246 = kk_integer_from_small(1); /*int*/
    }
    _brw_x158 = kk_integer_add_small_const(_x_x246, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x162 = kk_std_core_sslice_extend(_own_x159, _brw_x158, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x158, _ctx);
    return _brw_x162;
  }
}
 
// O(1). Return the string slice from the end of `slice` argument
// to the end of the string.

kk_std_core_sslice__sslice kk_std_core_sslice_after(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  {
    kk_string_t s = slice_0.str;
    kk_integer_t start = slice_0.start;
    kk_integer_t len = slice_0.len;
    kk_integer_t x_0_10020;
    kk_string_t _x_x247 = kk_string_dup(s, _ctx); /*string*/
    x_0_10020 = kk_string_len_int(_x_x247,kk_context()); /*int*/
    kk_integer_t y_0_10021;
    kk_integer_t _x_x248 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x249 = kk_integer_dup(len, _ctx); /*int*/
    y_0_10021 = kk_integer_add(_x_x248,_x_x249,kk_context()); /*int*/
    kk_integer_t _x_x250 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x251 = kk_integer_sub(x_0_10020,y_0_10021,kk_context()); /*int*/
    return kk_std_core_sslice__new_Sslice(s, _x_x250, _x_x251, _ctx);
  }
}
 
// Convert the first character of a string to uppercase.

kk_string_t kk_std_core_sslice_capitalize(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0_1;
  kk_string_t _x_x252 = kk_string_dup(s, _ctx); /*string*/
  slice_0_1 = kk_std_core_sslice_first1(_x_x252, _ctx); /*sslice/sslice*/
  kk_std_core_sslice__sslice slice_0_0_10028;
  bool _match_x150;
  kk_integer_t _brw_x155;
  kk_std_core_types__optional _match_x154 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x154, _ctx)) {
    kk_box_t _box_x72 = _match_x154._cons._Optional.value;
    kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x72, _ctx);
    kk_integer_dup(_uniq_n_665_0, _ctx);
    kk_std_core_types__optional_drop(_match_x154, _ctx);
    _brw_x155 = _uniq_n_665_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x154, _ctx);
    _brw_x155 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x156 = kk_integer_eq_borrow(_brw_x155,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x155, _ctx);
  _match_x150 = _brw_x156; /*bool*/
  if (_match_x150) {
    slice_0_0_10028 = slice_0_1; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x152;
    kk_integer_t _x_x253;
    kk_std_core_types__optional _match_x151 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x151, _ctx)) {
      kk_box_t _box_x73 = _match_x151._cons._Optional.value;
      kk_integer_t _uniq_n_665_0_0 = kk_integer_unbox(_box_x73, _ctx);
      kk_integer_dup(_uniq_n_665_0_0, _ctx);
      kk_std_core_types__optional_drop(_match_x151, _ctx);
      _x_x253 = _uniq_n_665_0_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x151, _ctx);
      _x_x253 = kk_integer_from_small(1); /*int*/
    }
    _brw_x152 = kk_integer_add_small_const(_x_x253, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x153 = kk_std_core_sslice_extend(slice_0_1, _brw_x152, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x152, _ctx);
    slice_0_0_10028 = _brw_x153; /*sslice/sslice*/
  }
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_string_t _x_x254;
  kk_string_t _x_x255;
  kk_std_core_sslice__sslice _x_x256;
  bool _match_x143;
  kk_integer_t _brw_x148;
  kk_std_core_types__optional _match_x147 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x147, _ctx)) {
    kk_box_t _box_x74 = _match_x147._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x74, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x147, _ctx);
    _brw_x148 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x147, _ctx);
    _brw_x148 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x149 = kk_integer_eq_borrow(_brw_x148,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x148, _ctx);
  _match_x143 = _brw_x149; /*bool*/
  if (_match_x143) {
    _x_x256 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x145;
    kk_integer_t _x_x257;
    kk_std_core_types__optional _match_x144 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x144, _ctx)) {
      kk_box_t _box_x75 = _match_x144._cons._Optional.value;
      kk_integer_t _uniq_n_665_1 = kk_integer_unbox(_box_x75, _ctx);
      kk_integer_dup(_uniq_n_665_1, _ctx);
      kk_std_core_types__optional_drop(_match_x144, _ctx);
      _x_x257 = _uniq_n_665_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x144, _ctx);
      _x_x257 = kk_integer_from_small(1); /*int*/
    }
    _brw_x145 = kk_integer_add_small_const(_x_x257, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x146 = kk_std_core_sslice_extend(slice_0, _brw_x145, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x145, _ctx);
    _x_x256 = _brw_x146; /*sslice/sslice*/
  }
  _x_x255 = kk_std_core_sslice_string(_x_x256, _ctx); /*string*/
  _x_x254 = kk_std_core_string_to_upper(_x_x255, _ctx); /*string*/
  kk_string_t _x_x258;
  kk_std_core_sslice__sslice _x_x259;
  {
    kk_string_t s_1 = slice_0_0_10028.str;
    kk_integer_t start = slice_0_0_10028.start;
    kk_integer_t len = slice_0_0_10028.len;
    kk_integer_t x_1_10035;
    kk_string_t _x_x260 = kk_string_dup(s_1, _ctx); /*string*/
    x_1_10035 = kk_string_len_int(_x_x260,kk_context()); /*int*/
    kk_integer_t y_1_10036;
    kk_integer_t _x_x261 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x262 = kk_integer_dup(len, _ctx); /*int*/
    y_1_10036 = kk_integer_add(_x_x261,_x_x262,kk_context()); /*int*/
    kk_integer_t _x_x263 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x264 = kk_integer_sub(x_1_10035,y_1_10036,kk_context()); /*int*/
    _x_x259 = kk_std_core_sslice__new_Sslice(s_1, _x_x263, _x_x264, _ctx); /*sslice/sslice*/
  }
  _x_x258 = kk_std_core_sslice_string(_x_x259, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x254, _x_x258, _ctx);
}
 
// An empty slice

kk_std_core_sslice__sslice kk_std_core_sslice_empty;
 
// An invalid slice

kk_std_core_sslice__sslice kk_std_core_sslice_invalid;
 
// Return the first character of a string as a string (or the empty string)

kk_string_t kk_std_core_sslice_head(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x269;
  bool _match_x130;
  kk_integer_t _brw_x135;
  kk_std_core_types__optional _match_x134 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x134, _ctx)) {
    kk_box_t _box_x76 = _match_x134._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x76, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x134, _ctx);
    _brw_x135 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x134, _ctx);
    _brw_x135 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x136 = kk_integer_eq_borrow(_brw_x135,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x135, _ctx);
  _match_x130 = _brw_x136; /*bool*/
  if (_match_x130) {
    _x_x269 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x132;
    kk_integer_t _x_x270;
    kk_std_core_types__optional _match_x131 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x131, _ctx)) {
      kk_box_t _box_x77 = _match_x131._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x77, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(_match_x131, _ctx);
      _x_x270 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x131, _ctx);
      _x_x270 = kk_integer_from_small(1); /*int*/
    }
    _brw_x132 = kk_integer_add_small_const(_x_x270, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x133 = kk_std_core_sslice_extend(slice_0, _brw_x132, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x132, _ctx);
    _x_x269 = _brw_x133; /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x269, _ctx);
}
 
// Return the tail of a string (or the empty string)

kk_string_t kk_std_core_sslice_tail(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice slice_0_10049;
  bool _match_x123;
  kk_integer_t _brw_x128;
  kk_std_core_types__optional _match_x127 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x127, _ctx)) {
    kk_box_t _box_x78 = _match_x127._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x78, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x127, _ctx);
    _brw_x128 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x127, _ctx);
    _brw_x128 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x129 = kk_integer_eq_borrow(_brw_x128,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x128, _ctx);
  _match_x123 = _brw_x129; /*bool*/
  if (_match_x123) {
    slice_0_10049 = slice_0_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x125;
    kk_integer_t _x_x271;
    kk_std_core_types__optional _match_x124 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x124, _ctx)) {
      kk_box_t _box_x79 = _match_x124._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x79, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(_match_x124, _ctx);
      _x_x271 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x124, _ctx);
      _x_x271 = kk_integer_from_small(1); /*int*/
    }
    _brw_x125 = kk_integer_add_small_const(_x_x271, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x126 = kk_std_core_sslice_extend(slice_0_0, _brw_x125, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x125, _ctx);
    slice_0_10049 = _brw_x126; /*sslice/sslice*/
  }
  kk_std_core_sslice__sslice _x_x272;
  {
    kk_string_t s_0 = slice_0_10049.str;
    kk_integer_t start = slice_0_10049.start;
    kk_integer_t len = slice_0_10049.len;
    kk_integer_t x_0_10056;
    kk_string_t _x_x273 = kk_string_dup(s_0, _ctx); /*string*/
    x_0_10056 = kk_string_len_int(_x_x273,kk_context()); /*int*/
    kk_integer_t y_0_10057;
    kk_integer_t _x_x274 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x275 = kk_integer_dup(len, _ctx); /*int*/
    y_0_10057 = kk_integer_add(_x_x274,_x_x275,kk_context()); /*int*/
    kk_integer_t _x_x276 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x277 = kk_integer_sub(x_0_10056,y_0_10057,kk_context()); /*int*/
    _x_x272 = kk_std_core_sslice__new_Sslice(s_0, _x_x276, _x_x277, _ctx); /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x272, _ctx);
}
 
// Return the common prefix of two strings (upto `upto` characters (default is minimum length of the two strings))

kk_std_core_sslice__sslice kk_std_core_sslice_common_prefix(kk_string_t s, kk_string_t t, kk_std_core_types__optional upto, kk_context_t* _ctx) { /* (s : string, t : string, upto : ? int) -> sslice */ 
  kk_integer_t _brw_x121;
  if (kk_std_core_types__is_Optional(upto, _ctx)) {
    kk_box_t _box_x80 = upto._cons._Optional.value;
    kk_integer_t _uniq_upto_901 = kk_integer_unbox(_box_x80, _ctx);
    _brw_x121 = kk_integer_dup(_uniq_upto_901, _ctx); /*int*/
  }
  else {
    _brw_x121 = kk_integer_from_small(-1); /*int*/
  }
  kk_std_core_sslice__sslice _brw_x122 = kk_slice_common_prefix_borrow(s,t,_brw_x121,kk_context()); /*sslice/sslice*/;
  kk_integer_drop(_brw_x121, _ctx);
  return _brw_x122;
}
 
// Truncate a string to `count` characters.

kk_string_t kk_std_core_sslice_string_fs_truncate(kk_string_t s, kk_integer_t count_0, kk_context_t* _ctx) { /* (s : string, count : int) -> string */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x280;
  kk_std_core_sslice__sslice _own_x112;
  bool _match_x113;
  kk_integer_t _brw_x118;
  kk_std_core_types__optional _match_x117 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x117, _ctx)) {
    kk_box_t _box_x81 = _match_x117._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x81, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x117, _ctx);
    _brw_x118 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x117, _ctx);
    _brw_x118 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x119 = kk_integer_eq_borrow(_brw_x118,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x118, _ctx);
  _match_x113 = _brw_x119; /*bool*/
  if (_match_x113) {
    _own_x112 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x115;
    kk_integer_t _x_x281;
    kk_std_core_types__optional _match_x114 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x114, _ctx)) {
      kk_box_t _box_x82 = _match_x114._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x82, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(_match_x114, _ctx);
      _x_x281 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x114, _ctx);
      _x_x281 = kk_integer_from_small(1); /*int*/
    }
    _brw_x115 = kk_integer_add_small_const(_x_x281, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x116 = kk_std_core_sslice_extend(slice_0, _brw_x115, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x115, _ctx);
    _own_x112 = _brw_x116; /*sslice/sslice*/
  }
  kk_integer_t _brw_x111 = kk_integer_add_small_const(count_0, -1, _ctx); /*int*/;
  kk_std_core_sslice__sslice _brw_x120 = kk_std_core_sslice_extend(_own_x112, _brw_x111, _ctx); /*sslice/sslice*/;
  kk_integer_drop(_brw_x111, _ctx);
  _x_x280 = _brw_x120; /*sslice/sslice*/
  return kk_std_core_sslice_string(_x_x280, _ctx);
}
 
// Gets up to (`end`-`start`) characters from the slice beginning from `start`.
// If either start or end is negative, returns the original slice

kk_std_core_sslice__sslice kk_std_core_sslice_subslice(kk_std_core_sslice__sslice slice_0, kk_integer_t start, kk_integer_t end, kk_context_t* _ctx) { /* (slice : sslice, start : int, end : int) -> sslice */ 
  bool _match_x107 = kk_integer_lt_borrow(start,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x107) {
    kk_integer_drop(start, _ctx);
    kk_integer_drop(end, _ctx);
    return slice_0;
  }
  {
    bool _match_x108 = kk_integer_lt_borrow(end,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x108) {
      kk_integer_drop(start, _ctx);
      kk_integer_drop(end, _ctx);
      return slice_0;
    }
    {
      kk_std_core_sslice__sslice slice_0_0_10068 = kk_std_core_sslice_advance(slice_0, start, _ctx); /*sslice/sslice*/;
      kk_integer_t _brw_x109 = kk_integer_sub(end,start,kk_context()); /*int*/;
      kk_std_core_sslice__sslice _brw_x110;
      kk_std_core_sslice__sslice _x_x282;
      kk_string_t _x_x283;
      {
        kk_string_t _x = slice_0_0_10068.str;
        kk_string_dup(_x, _ctx);
        _x_x283 = _x; /*string*/
      }
      kk_integer_t _x_x284;
      {
        kk_integer_t _x_0 = slice_0_0_10068.start;
        kk_integer_dup(_x_0, _ctx);
        kk_std_core_sslice__sslice_drop(slice_0_0_10068, _ctx);
        _x_x284 = _x_0; /*int*/
      }
      _x_x282 = kk_std_core_sslice__new_Sslice(_x_x283, _x_x284, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
      _brw_x110 = kk_std_core_sslice_extend(_x_x282, _brw_x109, _ctx); /*sslice/sslice*/
      kk_integer_drop(_brw_x109, _ctx);
      return _brw_x110;
    }
  }
}
 
// Gets a slice that only includes up to n characters from the start of the slice.

kk_std_core_sslice__sslice kk_std_core_sslice_take(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx) { /* (slice : sslice, n : int) -> sslice */ 
  bool _match_x105 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x105) {
    kk_integer_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice _brw_x106;
    kk_std_core_sslice__sslice _x_x285;
    kk_string_t _x_x286;
    {
      kk_string_t _x = slice_0.str;
      kk_string_dup(_x, _ctx);
      _x_x286 = _x; /*string*/
    }
    kk_integer_t _x_x287;
    {
      kk_integer_t _x_0 = slice_0.start;
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_sslice__sslice_drop(slice_0, _ctx);
      _x_x287 = _x_0; /*int*/
    }
    _x_x285 = kk_std_core_sslice__new_Sslice(_x_x286, _x_x287, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
    _brw_x106 = kk_std_core_sslice_extend(_x_x285, n, _ctx); /*sslice/sslice*/
    kk_integer_drop(n, _ctx);
    return _brw_x106;
  }
}
 
// Gets a slice that drops the first n characters, shrinking the length of the slice by n accordingly.
// If the slice does not have n characters, then the slice is shrunk to an empty slice.
//
// If maintaining the length of the slice is important, use `advance` instead.

kk_std_core_sslice__sslice kk_std_core_sslice_drop(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx) { /* (slice : sslice, n : int) -> sslice */ 
  bool _match_x102 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x102) {
    kk_integer_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice slice_0_0_10076;
    kk_std_core_sslice__sslice _x_x288 = kk_std_core_sslice__sslice_dup(slice_0, _ctx); /*sslice/sslice*/
    slice_0_0_10076 = kk_std_core_sslice_advance(_x_x288, n, _ctx); /*sslice/sslice*/
    kk_integer_t x_10079 = kk_std_core_sslice_count(slice_0, _ctx); /*int*/;
    kk_integer_t _brw_x103 = kk_integer_sub(x_10079,n,kk_context()); /*int*/;
    kk_std_core_sslice__sslice _brw_x104;
    kk_std_core_sslice__sslice _x_x289;
    kk_string_t _x_x290;
    {
      kk_string_t _x = slice_0_0_10076.str;
      kk_string_dup(_x, _ctx);
      _x_x290 = _x; /*string*/
    }
    kk_integer_t _x_x291;
    {
      kk_integer_t _x_0 = slice_0_0_10076.start;
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_sslice__sslice_drop(slice_0_0_10076, _ctx);
      _x_x291 = _x_0; /*int*/
    }
    _x_x289 = kk_std_core_sslice__new_Sslice(_x_x290, _x_x291, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
    _brw_x104 = kk_std_core_sslice_extend(_x_x289, _brw_x103, _ctx); /*sslice/sslice*/
    kk_integer_drop(_brw_x103, _ctx);
    return _brw_x104;
  }
}
 
// Return the first character of a string (or `Nothing` for the empty string).


// lift anonymous function
struct kk_std_core_sslice_head_char_fun295__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_core_sslice_head_char_fun295(kk_function_t _fself, kk_char_t _b_x83, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_head_char_fun295(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_head_char_fun295, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_core_sslice_head_char_fun295(kk_function_t _fself, kk_char_t _b_x83, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_std_core_types__new_Just(kk_char_box(_b_x83, _ctx), _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_head_char(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<char> */ 
  kk_std_core_sslice__sslice _x_x292;
  kk_string_t _x_x293 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x294 = kk_string_len_int(s,kk_context()); /*int*/
  _x_x292 = kk_std_core_sslice__new_Sslice(_x_x293, kk_integer_from_small(0), _x_x294, _ctx); /*sslice/sslice*/
  return kk_std_core_sslice_foreach_while(_x_x292, kk_std_core_sslice_new_head_char_fun295(_ctx), _ctx);
}
 
// O(n). If it occurs, return the position of substring `sub` in `s`, tupled with
// the position just following the substring `sub`.

kk_std_core_types__maybe kk_std_core_sslice_find(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  kk_integer_t i;
  kk_ssize_t _x_x296;
  kk_string_t _x_x297 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x298 = kk_string_dup(sub, _ctx); /*string*/
  _x_x296 = kk_string_index_of1(_x_x297,_x_x298,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x296,kk_context()); /*int*/
  bool _match_x101 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x101) {
    kk_string_drop(sub, _ctx);
    kk_string_drop(s, _ctx);
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x84_85;
    kk_integer_t _x_x299 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
    kk_integer_t _x_x300 = kk_string_len_int(sub,kk_context()); /*int*/
    _b_x84_85 = kk_std_core_sslice__new_Sslice(s, _x_x299, _x_x300, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x84_85, _ctx), _ctx);
  }
}
 
// Return the last index of substring `sub` in `s` if it occurs.

kk_std_core_types__maybe kk_std_core_sslice_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  kk_integer_t i;
  kk_ssize_t _x_x301;
  kk_string_t _x_x302 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x303 = kk_string_dup(sub, _ctx); /*string*/
  _x_x301 = kk_string_last_index_of1(_x_x302,_x_x303,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x301,kk_context()); /*int*/
  bool _match_x100 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x100) {
    kk_string_drop(sub, _ctx);
    kk_string_drop(s, _ctx);
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x86_87;
    kk_integer_t _x_x304 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
    kk_integer_t _x_x305 = kk_string_len_int(sub,kk_context()); /*int*/
    _b_x86_87 = kk_std_core_sslice__new_Sslice(s, _x_x304, _x_x305, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x86_87, _ctx), _ctx);
  }
}
 
// Is `pre`  a prefix of `s`? If so, returns a slice
// of `s` following `pre` up to the end of `s`.

kk_std_core_types__maybe kk_std_core_sslice_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx) { /* (s : string, pre : string) -> maybe<sslice> */ 
  bool _match_x99;
  kk_string_t _x_x306 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x307 = kk_string_dup(pre, _ctx); /*string*/
  _match_x99 = kk_string_starts_with(_x_x306,_x_x307,kk_context()); /*bool*/
  if (_match_x99) {
    kk_integer_t x_10085;
    kk_string_t _x_x308 = kk_string_dup(s, _ctx); /*string*/
    x_10085 = kk_string_len_int(_x_x308,kk_context()); /*int*/
    kk_integer_t y_10086;
    kk_string_t _x_x309 = kk_string_dup(pre, _ctx); /*string*/
    y_10086 = kk_string_len_int(_x_x309,kk_context()); /*int*/
    kk_std_core_sslice__sslice _b_x88_89;
    kk_integer_t _x_x310 = kk_string_len_int(pre,kk_context()); /*int*/
    kk_integer_t _x_x311 = kk_integer_sub(x_10085,y_10086,kk_context()); /*int*/
    _b_x88_89 = kk_std_core_sslice__new_Sslice(s, _x_x310, _x_x311, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x88_89, _ctx), _ctx);
  }
  {
    kk_string_drop(s, _ctx);
    kk_string_drop(pre, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

bool kk_std_core_sslice_xends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> bool */ 
  return kk_string_ends_with(s,post,kk_context());
}
 
// Does string `s`  end with `post`?
// If so, returns a slice of `s` from the start up to the `post` string at the end.

kk_std_core_types__maybe kk_std_core_sslice_ends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> maybe<sslice> */ 
  bool _match_x98;
  kk_string_t _x_x312 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x313 = kk_string_dup(post, _ctx); /*string*/
  _match_x98 = kk_std_core_sslice_xends_with(_x_x312, _x_x313, _ctx); /*bool*/
  if (_match_x98) {
    kk_integer_t x_10087;
    kk_string_t _x_x314 = kk_string_dup(s, _ctx); /*string*/
    x_10087 = kk_string_len_int(_x_x314,kk_context()); /*int*/
    kk_integer_t y_10088 = kk_string_len_int(post,kk_context()); /*int*/;
    kk_std_core_sslice__sslice _b_x90_91;
    kk_integer_t _x_x315 = kk_integer_sub(x_10087,y_10088,kk_context()); /*int*/
    _b_x90_91 = kk_std_core_sslice__new_Sslice(s, kk_integer_from_small(0), _x_x315, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x90_91, _ctx), _ctx);
  }
  {
    kk_string_drop(s, _ctx);
    kk_string_drop(post, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Trim off a substring `sub` while `s` starts with that string.

kk_string_t kk_std_core_sslice_trim_left(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_x96;
  kk_string_t _x_x316 = kk_string_dup(sub, _ctx); /*string*/
  kk_string_t _x_x317 = kk_string_empty(); /*string*/
  _match_x96 = kk_string_is_eq(_x_x316,_x_x317,kk_context()); /*bool*/
  if (_match_x96) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  {
    kk_std_core_types__maybe _match_x97;
    kk_string_t _x_x319 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x320 = kk_string_dup(sub, _ctx); /*string*/
    _match_x97 = kk_std_core_sslice_starts_with(_x_x319, _x_x320, _ctx); /*maybe<sslice/sslice>*/
    if (kk_std_core_types__is_Just(_match_x97, _ctx)) {
      kk_box_t _box_x92 = _match_x97._cons.Just.value;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__sslice_unbox(_box_x92, KK_BORROWED, _ctx);
      kk_string_drop(s, _ctx);
      kk_std_core_sslice__sslice_dup(slice_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x97, _ctx);
      { // tailcall
        kk_string_t _x_x321 = kk_std_core_sslice_string(slice_0, _ctx); /*string*/
        s = _x_x321;
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(sub, _ctx);
      return s;
    }
  }
}
 
// Trim off a substring `sub` while `s` ends with that string.

kk_string_t kk_std_core_sslice_trim_right(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_x94;
  kk_string_t _x_x322 = kk_string_dup(sub, _ctx); /*string*/
  kk_string_t _x_x323 = kk_string_empty(); /*string*/
  _match_x94 = kk_string_is_eq(_x_x322,_x_x323,kk_context()); /*bool*/
  if (_match_x94) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  {
    kk_std_core_types__maybe _match_x95;
    kk_string_t _x_x325 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x326 = kk_string_dup(sub, _ctx); /*string*/
    _match_x95 = kk_std_core_sslice_ends_with(_x_x325, _x_x326, _ctx); /*maybe<sslice/sslice>*/
    if (kk_std_core_types__is_Just(_match_x95, _ctx)) {
      kk_box_t _box_x93 = _match_x95._cons.Just.value;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__sslice_unbox(_box_x93, KK_BORROWED, _ctx);
      kk_string_drop(s, _ctx);
      kk_std_core_sslice__sslice_dup(slice_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x95, _ctx);
      { // tailcall
        kk_string_t _x_x327 = kk_std_core_sslice_string(slice_0, _ctx); /*string*/
        s = _x_x327;
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(sub, _ctx);
      return s;
    }
  }
}

// initialization
void kk_std_core_sslice__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_string__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x265 = kk_string_empty(); /*string*/
    kk_std_core_sslice_empty = kk_std_core_sslice__new_Sslice(_x_x265, kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*sslice/sslice*/
  }
  {
    kk_string_t _x_x267 = kk_string_empty(); /*string*/
    kk_std_core_sslice_invalid = kk_std_core_sslice__new_Sslice(_x_x267, kk_integer_from_small(-1), kk_integer_from_small(0), _ctx); /*sslice/sslice*/
  }
}

// termination
void kk_std_core_sslice__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_sslice__sslice_drop(kk_std_core_sslice_invalid, _ctx);
  kk_std_core_sslice__sslice_drop(kk_std_core_sslice_empty, _ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
