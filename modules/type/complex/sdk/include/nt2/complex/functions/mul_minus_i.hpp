//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef NT2_COMPLEX_FUNCTIONS_MUL_MINUS_I_HPP_INCLUDED
#define NT2_COMPLEX_FUNCTIONS_MUL_MINUS_I_HPP_INCLUDED
#include <nt2/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

#include <nt2/sdk/complex/complex.hpp>

/*!
 * \ingroup nt2_complex
 * \defgroup nt2_complex_mul_minus_i mul_minus_i
 *
 * \par Description
 * return the complex multiplied by -i (i*i == -1)
 * i.e. (nt2::imag(a0), -nt2::real(a0))
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/mul_minus_i.hpp>
 * \endcode
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *     template <class A0>
 *     meta::call<tag::mul_minus_i_(A0)>::type
 *     mul_minus_i(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the first parameter of mul_minus_i
 *
 * \return a mul_minus_i value
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the input vectors' elements
 * \par
 *
**/

namespace nt2
{
  namespace tag
  {
    /*!
     * \brief Define the tag mul_minus_i_ of functor mul_minus_i
     *        in namespace nt2::tag for toolbox complex
    **/
    struct mul_minus_i_ : ext::elementwise_<mul_minus_i_> { typedef ext::elementwise_<mul_minus_i_> parent; };
  }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::mul_minus_i_, mul_minus_i, 1)
}

#endif
