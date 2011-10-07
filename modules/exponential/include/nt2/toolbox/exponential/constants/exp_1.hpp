//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II       
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI       
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_CONSTANTS_EXP_1_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_CONSTANTS_EXP_1_HPP_INCLUDED
/*!
 * \file
**/
#include <nt2/sdk/constant/constant.hpp>
/*!
 * \ingroup expon_constant
 * \defgroup expon_constant_exp_1 Exp_1 constant
 *
 * \par Description
 * Constant exp_1 : \f$e = \exp(1)\f$ constant.
 * \par
 * The value of this constant is type dependant. This means that for different
 * types it does not represent the same mathematical number.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/exp_1.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::exp_1_(A0)>::type
 *     exp_1();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Exp_1
 * 
 * \return type T value
 *  
 *  
**/

namespace nt2
{
  NT2_MAKE_STD_CONSTANT(Exp_1        ,0x4005bf0a8b145769LL,0x402df854, 2)
}

#endif
