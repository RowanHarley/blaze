//=================================================================================================
/*!
//  \file blaze/math/simd/BasicTypes.h
//  \brief Header file for the basic SIMD types
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_SIMD_BASICTYPES_H_
#define _BLAZE_MATH_SIMD_BASICTYPES_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/typetraits/IsSIMDType.h>
#include <blaze/system/Inline.h>
#include <blaze/system/Vectorization.h>
#include <blaze/util/Complex.h>
#include <blaze/util/TrueType.h>
#include <blaze/util/Types.h>


namespace blaze {

//=================================================================================================
//
//  BASIC SIMD TYPES
//
//=================================================================================================

//*************************************************************************************************
/*!\class blaze::simd_int8_t
// \brief SIMD type for 8-bit integral data values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_int8_t {
   BLAZE_ALWAYS_INLINE simd_int8_t() noexcept : value( 0 ) {}
   BLAZE_ALWAYS_INLINE simd_int8_t( int8_t v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int8_t operator[]( size_t /*i*/ ) const noexcept { return value; }
   int8_t value;
   enum : size_t { size = 1UL };
};
#elif BLAZE_AVX2_MODE
struct simd_int8_t {
   BLAZE_ALWAYS_INLINE simd_int8_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_int8_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int8_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int8_t*>( &value )[i]; }
   __m256i value;  // Contains 32 8-bit integral data values
   enum : size_t { size = 32UL };
};
#elif BLAZE_SSE2_MODE
struct simd_int8_t {
   BLAZE_ALWAYS_INLINE simd_int8_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_int8_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int8_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int8_t*>( &value )[i]; }
   __m128i value;  // Contains 16 8-bit integral data values
   enum : size_t { size = 16UL };
};
#else
struct simd_int8_t {
   BLAZE_ALWAYS_INLINE simd_int8_t() noexcept : value( 0 ) {}
   BLAZE_ALWAYS_INLINE simd_int8_t( int8_t v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int8_t operator[]( size_t /*i*/ ) const noexcept { return value; }
   int8_t value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_int16_t
// \brief SIMD type for 16-bit integral data values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_int16_t {
   BLAZE_ALWAYS_INLINE simd_int16_t() noexcept : value( 0 ) {}
   BLAZE_ALWAYS_INLINE simd_int16_t( int16_t v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int16_t operator[]( size_t /*i*/ ) const noexcept { return value; }
   int16_t value;
   enum : size_t { size = 1UL };
};
#elif BLAZE_AVX2_MODE
struct simd_int16_t {
   BLAZE_ALWAYS_INLINE simd_int16_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_int16_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int16_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int16_t*>( &value )[i]; }
   __m256i value;  // Contains 16 16-bit integral data values
   enum : size_t { size = 16UL };
};
#elif BLAZE_SSE2_MODE
struct simd_int16_t {
   BLAZE_ALWAYS_INLINE simd_int16_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_int16_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int16_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int16_t*>( &value )[i]; }
   __m128i value;  // Contains 8 16-bit integral data values
   enum : size_t { size = 8UL };
};
#else
struct simd_int16_t {
   BLAZE_ALWAYS_INLINE simd_int16_t() noexcept : value( 0 ) {}
   BLAZE_ALWAYS_INLINE simd_int16_t( int16_t v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int16_t operator[]( size_t /*i*/ ) const noexcept { return value; }
   int16_t value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_int32_t
// \brief SIMD type for 32-bit integral data values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_int32_t {
   BLAZE_ALWAYS_INLINE simd_int32_t() noexcept : value( _mm512_setzero_epi32() ) {}
   BLAZE_ALWAYS_INLINE simd_int32_t( __m512i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int32_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int32_t*>( &value )[i]; }
   __m512i value;  // Contains 16 32-bit integral data values
   enum : size_t { size = 16UL };
};
#elif BLAZE_AVX2_MODE
struct simd_int32_t {
   BLAZE_ALWAYS_INLINE simd_int32_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_int32_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int32_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int32_t*>( &value )[i]; }
   __m256i value;  // Contains 8 32-bit integral data values
   enum : size_t { size = 8UL };
};
#elif BLAZE_SSE2_MODE
struct simd_int32_t {
   BLAZE_ALWAYS_INLINE simd_int32_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_int32_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int32_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int32_t*>( &value )[i]; }
   __m128i value;  // Contains 4 32-bit integral data values
   enum : size_t { size = 4UL };
};
#else
struct simd_int32_t {
   BLAZE_ALWAYS_INLINE simd_int32_t() noexcept : value( 0 ) {}
   BLAZE_ALWAYS_INLINE simd_int32_t( int32_t v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int32_t operator[]( size_t /*i*/ ) const noexcept { return value; }
   int32_t value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_int64_t
// \brief SIMD type for 64-bit integral data values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_int64_t {
   BLAZE_ALWAYS_INLINE simd_int64_t() noexcept : value( _mm512_setzero_epi32() ) {}
   BLAZE_ALWAYS_INLINE simd_int64_t( __m512i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int64_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int64_t*>( &value )[i]; }
   __m512i value;  // Contains 8 64-bit integral data values
   enum : size_t { size = 8UL };
};
#elif BLAZE_AVX2_MODE
struct simd_int64_t {
   BLAZE_ALWAYS_INLINE simd_int64_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_int64_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int64_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int64_t*>( &value )[i]; }
   __m256i value;  // Contains 4 64-bit integral data values
   enum : size_t { size = 4UL };
};
#elif BLAZE_SSE2_MODE
struct simd_int64_t {
   BLAZE_ALWAYS_INLINE simd_int64_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_int64_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int64_t operator[]( size_t i ) const noexcept { return reinterpret_cast<const int64_t*>( &value )[i]; }
   __m128i value;  // Contains 2 64-bit integral data values
   enum : size_t { size = 2UL };
};
#else
struct simd_int64_t {
   BLAZE_ALWAYS_INLINE simd_int64_t() noexcept : value( 0L ) {}
   BLAZE_ALWAYS_INLINE simd_int64_t( int64_t v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE int64_t operator[]( size_t /*i*/ ) const noexcept { return value; }
   int64_t value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_float_t
// \brief SIMD type for 32-bit single precision floating point data values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_float_t {
   BLAZE_ALWAYS_INLINE simd_float_t() noexcept : value( _mm512_setzero_ps() ) {}
   BLAZE_ALWAYS_INLINE simd_float_t( __m512 v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE float operator[]( size_t i ) const noexcept { return reinterpret_cast<const float*>( &value )[i]; }
   __m512 value;  // Contains 16 32-bit single precision floating point values
   enum : size_t { size = 16UL };
};
#elif BLAZE_AVX_MODE
struct simd_float_t {
   BLAZE_ALWAYS_INLINE simd_float_t() noexcept : value( _mm256_setzero_ps() ) {}
   BLAZE_ALWAYS_INLINE simd_float_t( __m256 v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE float operator[]( size_t i ) const noexcept { return reinterpret_cast<const float*>( &value )[i]; }
   __m256 value;  // Contains 8 32-bit single precision floating point values
   enum : size_t { size = 8UL };
};
#elif BLAZE_SSE_MODE
struct simd_float_t {
   BLAZE_ALWAYS_INLINE simd_float_t() noexcept : value( _mm_setzero_ps() ) {}
   BLAZE_ALWAYS_INLINE simd_float_t( __m128 v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE float operator[]( size_t i ) const noexcept { return reinterpret_cast<const float*>( &value )[i]; }
   __m128 value;  // Contains 4 32-bit single precision floating point values
   enum : size_t { size = 4UL };
};
#else
struct simd_float_t {
   BLAZE_ALWAYS_INLINE simd_float_t() noexcept : value( 0.0F ) {}
   BLAZE_ALWAYS_INLINE simd_float_t( float v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE float operator[]( size_t /*i*/ ) const noexcept { return value; }
   float value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_double_t
// \brief SIMD type for 64-bit double precision floating point data values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_double_t {
   BLAZE_ALWAYS_INLINE simd_double_t() noexcept : value( _mm512_setzero_pd() ) {}
   BLAZE_ALWAYS_INLINE simd_double_t( __m512d v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE double operator[]( size_t i ) const noexcept { return reinterpret_cast<const double*>( &value )[i]; }
   __m512d value;  // Contains 8 64-bit double precision floating point values
   enum : size_t { size = 8UL };
};
#elif BLAZE_AVX_MODE
struct simd_double_t {
   BLAZE_ALWAYS_INLINE simd_double_t() noexcept : value( _mm256_setzero_pd() ) {}
   BLAZE_ALWAYS_INLINE simd_double_t( __m256d v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE double operator[]( size_t i ) const noexcept { return reinterpret_cast<const double*>( &value )[i]; }
   __m256d value;  // Contains 4 64-bit double precision floating point values
   enum : size_t { size = 4UL };
};
#elif BLAZE_SSE2_MODE
struct simd_double_t {
   BLAZE_ALWAYS_INLINE simd_double_t() noexcept : value( _mm_setzero_pd() ) {}
   BLAZE_ALWAYS_INLINE simd_double_t( __m128d v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE double operator[]( size_t i ) const noexcept { return reinterpret_cast<const double*>( &value )[i]; }
   __m128d value;  // Contains 2 64-bit double precision floating point values
   enum : size_t { size = 2UL };
};
#else
struct simd_double_t {
   BLAZE_ALWAYS_INLINE simd_double_t() noexcept : value( 0.0 ) {}
   BLAZE_ALWAYS_INLINE simd_double_t( double v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE double operator[]( size_t /*i*/ ) const noexcept { return value; }
   double value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_cint8_t
// \brief SIMD type for 8-bit integral complex values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_cint8_t {
   BLAZE_ALWAYS_INLINE simd_cint8_t() noexcept : value( 0, 0 ) {}
   BLAZE_ALWAYS_INLINE simd_cint8_t( complex<int8_t> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int8_t> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<int8_t> value;
   enum : size_t { size = 1UL };
};
#elif BLAZE_AVX2_MODE
struct simd_cint8_t {
   BLAZE_ALWAYS_INLINE simd_cint8_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_cint8_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int8_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int8_t>*>( &value )[i]; }
   __m256i value;  // Contains 16 8-bit integral complex values
   enum : size_t { size = 16UL };
};
#elif BLAZE_SSE2_MODE
struct simd_cint8_t {
   BLAZE_ALWAYS_INLINE simd_cint8_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_cint8_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int8_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int8_t>*>( &value )[i]; }
   __m128i value;  // Contains 8 8-bit integral complex values
   enum : size_t { size = 8UL };
};
#else
struct simd_cint8_t {
   BLAZE_ALWAYS_INLINE simd_cint8_t() noexcept : value( 0, 0 ) {}
   BLAZE_ALWAYS_INLINE simd_cint8_t( complex<int8_t> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int8_t> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<int8_t> value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_cint16_t
// \brief SIMD type for 16-bit integral complex values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_cint16_t {
   BLAZE_ALWAYS_INLINE constexpr simd_cint16_t() noexcept : value( 0, 0 ) {}
   BLAZE_ALWAYS_INLINE constexpr simd_cint16_t( complex<int16_t> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE constexpr complex<int16_t> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<int16_t> value;
   enum : size_t { size = 1UL };
};
#elif BLAZE_AVX2_MODE
struct simd_cint16_t {
   BLAZE_ALWAYS_INLINE simd_cint16_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_cint16_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int16_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int16_t>*>( &value )[i]; }
   __m256i value;  // Contains 8 16-bit integral complex values
   enum : size_t { size = 8UL };
};
#elif BLAZE_SSE2_MODE
struct simd_cint16_t {
   BLAZE_ALWAYS_INLINE simd_cint16_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_cint16_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int16_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int16_t>*>( &value )[i]; }
   __m128i value;  // Contains 4 16-bit integral complex values
   enum : size_t { size = 4UL };
};
#else
struct simd_cint16_t {
   BLAZE_ALWAYS_INLINE constexpr simd_cint16_t() noexcept : value( 0, 0 ) {}
   BLAZE_ALWAYS_INLINE constexpr simd_cint16_t( complex<int16_t> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE constexpr complex<int16_t> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<int16_t> value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_cint32_t
// \brief SIMD type for 32-bit integral complex values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_cint32_t {
   BLAZE_ALWAYS_INLINE simd_cint32_t() noexcept : value( _mm512_setzero_epi32() ) {}
   BLAZE_ALWAYS_INLINE simd_cint32_t( __m512i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int32_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int32_t>*>( &value )[i]; }
   __m512i value;  // Contains 8 32-bit integral complex values
   enum : size_t { size = 8UL };
};
#elif BLAZE_AVX2_MODE
struct simd_cint32_t {
   BLAZE_ALWAYS_INLINE simd_cint32_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_cint32_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int32_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int32_t>*>( &value )[i]; }
   __m256i value;  // Contains 4 32-bit integral complex values
   enum : size_t { size = 4UL };
};
#elif BLAZE_SSE2_MODE
struct simd_cint32_t {
   BLAZE_ALWAYS_INLINE simd_cint32_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_cint32_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int32_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int32_t>*>( &value )[i]; }
   __m128i value;  // Contains 2 32-bit integral complex values
   enum : size_t { size = 2UL };
};
#else
struct simd_cint32_t {
   BLAZE_ALWAYS_INLINE simd_cint32_t() noexcept : value( 0, 0 ) {}
   BLAZE_ALWAYS_INLINE simd_cint32_t( complex<int32_t> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int32_t> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<int32_t> value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_cint64_t
// \brief SIMD type for 64-bit integral complex values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_cint64_t {
   BLAZE_ALWAYS_INLINE simd_cint64_t() noexcept : value( _mm512_setzero_epi32() ) {}
   BLAZE_ALWAYS_INLINE simd_cint64_t( __m512i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int64_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int64_t>*>( &value )[i]; }
   __m512i value;  // Contains 4 64-bit integral complex values
   enum : size_t { size = 4UL };
};
#elif BLAZE_AVX2_MODE
struct simd_cint64_t {
   BLAZE_ALWAYS_INLINE simd_cint64_t() noexcept : value( _mm256_setzero_si256() ) {}
   BLAZE_ALWAYS_INLINE simd_cint64_t( __m256i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int64_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int64_t>*>( &value )[i]; }
   __m256i value;  // Contains 2 64-bit integral complex values
   enum : size_t { size = 2UL };
};
#elif BLAZE_SSE2_MODE
struct simd_cint64_t {
   BLAZE_ALWAYS_INLINE simd_cint64_t() noexcept : value( _mm_setzero_si128() ) {}
   BLAZE_ALWAYS_INLINE simd_cint64_t( __m128i v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int64_t> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<int64_t>*>( &value )[i]; }
   __m128i value;  // Contains 1 64-bit integral complex values
   enum : size_t { size = 1UL };
};
#else
struct simd_cint64_t {
   BLAZE_ALWAYS_INLINE simd_cint64_t() noexcept : value( 0L, 0L ) {}
   BLAZE_ALWAYS_INLINE simd_cint64_t( complex<int64_t> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<int64_t> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<int64_t> value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_cfloat_t
// \brief SIMD type for 32-bit single precision complex values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_cfloat_t {
   BLAZE_ALWAYS_INLINE simd_cfloat_t() noexcept : value( _mm512_setzero_ps() ) {}
   BLAZE_ALWAYS_INLINE simd_cfloat_t( __m512 v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<float> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<float>*>( &value )[i]; }
   __m512 value;  // Contains 8 32-bit single precision complex values
   enum : size_t { size = 8UL };
};
#elif BLAZE_AVX_MODE
struct simd_cfloat_t {
   BLAZE_ALWAYS_INLINE simd_cfloat_t() noexcept : value( _mm256_setzero_ps() ) {}
   BLAZE_ALWAYS_INLINE simd_cfloat_t( __m256 v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<float> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<float>*>( &value )[i]; }
   __m256 value;  // Contains 4 32-bit single precision complex values
   enum : size_t { size = 4UL };
};
#elif BLAZE_SSE_MODE
struct simd_cfloat_t {
   BLAZE_ALWAYS_INLINE simd_cfloat_t() noexcept : value( _mm_setzero_ps() ) {}
   BLAZE_ALWAYS_INLINE simd_cfloat_t( __m128 v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<float> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<float>*>( &value )[i]; }
   __m128 value;  // Contains 2 32-bit single precision complex values
   enum : size_t { size = 2UL };
};
#else
struct simd_cfloat_t {
   BLAZE_ALWAYS_INLINE simd_cfloat_t() noexcept : value( 0.0F, 0.0F ) {}
   BLAZE_ALWAYS_INLINE simd_cfloat_t( complex<float> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<float> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<float> value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\class blaze::simd_cdouble_t
// \brief SIMD type for 64-bit double precision complex values.
// \ingroup simd
*/
/*! \cond BLAZE_INTERNAL */
#if BLAZE_MIC_MODE
struct simd_cdouble_t {
   BLAZE_ALWAYS_INLINE simd_cdouble_t() noexcept : value( _mm512_setzero_pd() ) {}
   BLAZE_ALWAYS_INLINE simd_cdouble_t( __m512d v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<double> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<double>*>( &value )[i]; }
   __m512d value;  // Contains 4 64-bit double precision complex value
   enum : size_t { size = 4UL };
};
#elif BLAZE_AVX_MODE
struct simd_cdouble_t {
   BLAZE_ALWAYS_INLINE simd_cdouble_t() noexcept : value( _mm256_setzero_pd() ) {}
   BLAZE_ALWAYS_INLINE simd_cdouble_t( __m256d v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<double> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<double>*>( &value )[i]; }
   __m256d value;  // Contains 2 64-bit double precision complex value
   enum : size_t { size = 2UL };
};
#elif BLAZE_SSE2_MODE
struct simd_cdouble_t {
   BLAZE_ALWAYS_INLINE simd_cdouble_t() noexcept : value( _mm_setzero_pd() ) {}
   BLAZE_ALWAYS_INLINE simd_cdouble_t( __m128d v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<double> operator[]( size_t i ) const noexcept { return reinterpret_cast<const complex<double>*>( &value )[i]; }
   __m128d value;  // Contains 1 64-bit double precision complex value
   enum : size_t { size = 1UL };
};
#else
struct simd_cdouble_t {
   BLAZE_ALWAYS_INLINE simd_cdouble_t() noexcept : value( 0.0, 0.0 ) {}
   BLAZE_ALWAYS_INLINE simd_cdouble_t( complex<double> v ) noexcept : value( v ) {}
   BLAZE_ALWAYS_INLINE complex<double> operator[]( size_t /*i*/ ) const noexcept { return value; }
   complex<double> value;
   enum : size_t { size = 1UL };
};
#endif
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISSIMDTYPE SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template<> struct IsSIMDType< simd_int8_t   > : public TrueType {};
template<> struct IsSIMDType< simd_int16_t  > : public TrueType {};
template<> struct IsSIMDType< simd_int32_t  > : public TrueType {};
template<> struct IsSIMDType< simd_int64_t  > : public TrueType {};
template<> struct IsSIMDType< simd_float_t  > : public TrueType {};
template<> struct IsSIMDType< simd_double_t > : public TrueType {};

template<> struct IsSIMDType< simd_cint8_t   > : public TrueType {};
template<> struct IsSIMDType< simd_cint16_t  > : public TrueType {};
template<> struct IsSIMDType< simd_cint32_t  > : public TrueType {};
template<> struct IsSIMDType< simd_cint64_t  > : public TrueType {};
template<> struct IsSIMDType< simd_cfloat_t  > : public TrueType {};
template<> struct IsSIMDType< simd_cdouble_t > : public TrueType {};
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
