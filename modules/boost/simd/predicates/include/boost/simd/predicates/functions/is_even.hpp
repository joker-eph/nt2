//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_IS_EVEN_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_IS_EVEN_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_predicates
 * \defgroup boost_simd_predicates_is_even is_even
 *
 * \par Description
 * Returns True<result_type>() or False<result_type>() according a0 is even or not.
 * A floating number is even if it is a  flint
 * and divided by two it is still a flint
 * \par
 * A flint is a 'floating integer' i.e. a floating number
 * representing an integer value
 * \par
 * Be conscious that all sufficiently great floating points values are even...
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/is_even.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::is_even_(A0)>::type
 *     is_even(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of is_even
 *
 * \return an integer value
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 * This is a predicate operation. Such operations return bool in scalar mode,
 * but not in SIMD mode.
 * \par
 * The return type in SIMD mode is the common type of the parameters and is
 * a 'signed boolean' type. This means that in this case True has all its bits
 * sets to one. This is to facilitate masking operations. You are invited to
 * consult the rationale.
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag is_even_ of functor is_even
     *        in namespace boost::simd::tag for toolbox boost.simd.predicates
    **/
    struct is_even_ : ext::elementwise_<is_even_> { typedef ext::elementwise_<is_even_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_even_, is_even, 1)
} }

#endif

// modified by jt the 25/12/2010
