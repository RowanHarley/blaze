//=================================================================================================
/*!
//  \file blaze/math/views/Row.h
//  \brief Header file for all restructuring row functions
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

#ifndef _BLAZE_MATH_VIEWS_ROW_H_
#define _BLAZE_MATH_VIEWS_ROW_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/Matrix.h>
#include <blaze/math/traits/RowExprTrait.h>
#include <blaze/math/typetraits/IsComputation.h>
#include <blaze/math/typetraits/IsMatConjExpr.h>
#include <blaze/math/typetraits/IsMatEvalExpr.h>
#include <blaze/math/typetraits/IsMatForEachExpr.h>
#include <blaze/math/typetraits/IsMatImagExpr.h>
#include <blaze/math/typetraits/IsMatMatAddExpr.h>
#include <blaze/math/typetraits/IsMatMatMultExpr.h>
#include <blaze/math/typetraits/IsMatMatSubExpr.h>
#include <blaze/math/typetraits/IsMatScalarDivExpr.h>
#include <blaze/math/typetraits/IsMatScalarMultExpr.h>
#include <blaze/math/typetraits/IsMatSerialExpr.h>
#include <blaze/math/typetraits/IsMatTransExpr.h>
#include <blaze/math/typetraits/IsTransExpr.h>
#include <blaze/math/typetraits/IsVecTVecMultExpr.h>
#include <blaze/util/DisableIf.h>
#include <blaze/util/EnableIf.h>
#include <blaze/util/logging/FunctionTrace.h>
#include <blaze/util/mpl/Or.h>
#include <blaze/util/Types.h>


namespace blaze {

//=================================================================================================
//
//  GLOBAL FUNCTION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Creating a view on a specific row of the given matrix.
// \ingroup views
//
// \param matrix The matrix containing the row.
// \param index The index of the row.
// \return View on the specified row of the matrix.
// \exception std::invalid_argument Invalid row access index.
//
// This function returns an expression representing the specified row of the given matrix.

   \code
   using blaze::rowMajor;

   typedef blaze::DynamicMatrix<double,rowMajor>     DenseMatrix;
   typedef blaze::CompressedMatrix<double,rowMajor>  SparseMatrix;

   DenseMatrix D;
   SparseMatrix S;
   // ... Resizing and initialization

   // Creating a view on the 3rd row of the dense matrix D
   blaze::DenseRow<DenseMatrix> = row( D, 3UL );

   // Creating a view on the 4th row of the sparse matrix S
   blaze::SparseRow<SparseMatrix> = row( S, 4UL );
   \endcode
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline DisableIf_< Or< IsComputation<MT>, IsTransExpr<MT> >, RowExprTrait_<MT> >
   row( Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return RowExprTrait_<MT>( ~matrix, index );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Creating a view on a specific row of the given constant matrix.
// \ingroup views
//
// \param matrix The constant matrix containing the row.
// \param index The index of the row.
// \return View on the specified row of the matrix.
// \exception std::invalid_argument Invalid row access index.
//
// This function returns an expression representing the specified row of the given matrix.

   \code
   using blaze::rowMajor;

   typedef blaze::DynamicMatrix<double,rowMajor>     DenseMatrix;
   typedef blaze::CompressedMatrix<double,rowMajor>  SparseMatrix;

   DenseMatrix D;
   SparseMatrix S;
   // ... Resizing and initialization

   // Creating a view on the 3rd row of the dense matrix D
   blaze::DenseRow<DenseMatrix> = row( D, 3UL );

   // Creating a view on the 4th row of the sparse matrix S
   blaze::SparseRow<SparseMatrix> = row( S, 4UL );
   \endcode
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline DisableIf_< Or< IsComputation<MT>, IsTransExpr<MT> >, RowExprTrait_<const MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return RowExprTrait_<const MT>( ~matrix, index );
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL RESTRUCTURING OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix/matrix addition.
// \ingroup views
//
// \param matrix The constant matrix/matrix addition.
// \param index The index of the row.
// \return View on the specified row of the addition.
//
// This function returns an expression representing the specified row of the given matrix/matrix
// addition.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatMatAddExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return row( (~matrix).leftOperand(), index ) + row( (~matrix).rightOperand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix/matrix subtraction.
// \ingroup views
//
// \param matrix The constant matrix/matrix subtraction.
// \param index The index of the row.
// \return View on the specified row of the subtraction.
//
// This function returns an expression representing the specified row of the given matrix/matrix
// subtraction.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatMatSubExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return row( (~matrix).leftOperand(), index ) - row( (~matrix).rightOperand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix/matrix multiplication.
// \ingroup views
//
// \param matrix The constant matrix/matrix multiplication.
// \param index The index of the row.
// \return View on the specified row of the multiplication.
//
// This function returns an expression representing the specified row of the given matrix/matrix
// multiplication.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatMatMultExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return row( (~matrix).leftOperand(), index ) * (~matrix).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given outer product.
// \ingroup views
//
// \param matrix The constant outer product.
// \param index The index of the row.
// \return View on the specified row of the outer product.
//
// This function returns an expression representing the specified row of the given outer product.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsVecTVecMultExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return (~matrix).leftOperand()[index] * (~matrix).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix/scalar multiplication.
// \ingroup views
//
// \param matrix The constant matrix/scalar multiplication.
// \param index The index of the row.
// \return View on the specified row of the multiplication.
//
// This function returns an expression representing the specified row of the given matrix/scalar
// multiplication.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatScalarMultExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return row( (~matrix).leftOperand(), index ) * (~matrix).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix/scalar division.
// \ingroup views
//
// \param matrix The constant matrix/scalar division.
// \param index The index of the row.
// \return View on the specified row of the division.
//
// This function returns an expression representing the specified row of the given matrix/scalar
// division.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatScalarDivExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return row( (~matrix).leftOperand(), index ) / (~matrix).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix \a conj operation.
// \ingroup views
//
// \param matrix The constant matrix \a conj operation.
// \param index The index of the row.
// \return View on the specified row of the \a conj operation.
//
// This function returns an expression representing the specified row of the given matrix
// \a conj operation.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatConjExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return conj( row( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix \a imag operation.
// \ingroup views
//
// \param matrix The constant matrix \a imag operation.
// \param index The index of the row.
// \return View on the specified row of the \a imag operation.
//
// This function returns an expression representing the specified row of the given matrix
// \a imag operation.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatImagExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return imag( row( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix custom operation.
// \ingroup views
//
// \param matrix The constant matrix custom operation.
// \param index The index of the row.
// \return View on the specified row of the custom operation.
//
// This function returns an expression representing the specified row of the given matrix
// custom operation.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatForEachExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return forEach( row( (~matrix).operand(), index ), (~matrix).operation() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix evaluation operation.
// \ingroup views
//
// \param matrix The constant matrix evaluation operation.
// \param index The index of the row.
// \return View on the specified row of the evaluation operation.
//
// This function returns an expression representing the specified row of the given matrix
// evaluation operation.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatEvalExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return eval( row( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix serialization operation.
// \ingroup views
//
// \param matrix The constant matrix serialization operation.
// \param index The index of the row.
// \return View on the specified row of the serialization operation.
//
// This function returns an expression representing the specified row of the given matrix
// serialization operation.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatSerialExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return serial( row( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific row of the given matrix transpose operation.
// \ingroup views
//
// \param matrix The constant matrix transpose operation.
// \param index The index of the row.
// \return View on the specified row of the transpose operation.
//
// This function returns an expression representing the specified row of the given matrix
// transpose operation.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline EnableIf_< IsMatTransExpr<MT>, RowExprTrait_<MT> >
   row( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return trans( column( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
