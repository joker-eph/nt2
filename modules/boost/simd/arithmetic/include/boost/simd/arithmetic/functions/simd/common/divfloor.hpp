//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_DIVFLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_SIMD_COMMON_DIVFLOOR_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/divfloor.hpp>
#include <boost/simd/include/functions/simd/divceil.hpp>
#include <boost/simd/include/functions/simd/divs.hpp>
#include <boost/simd/include/functions/simd/floor.hpp>
#include <boost/simd/include/functions/simd/unary_minus.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divfloor_, tag::cpu_, (A0)(X)
                                   , ((simd_<arithmetic_<A0>,X>))
                                     ((simd_<arithmetic_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return -boost::simd::divceil(-a0,a1); }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divfloor_, tag::cpu_, (A0)(X)
                                   , ((simd_<unsigned_<A0>,X>))
                                     ((simd_<unsigned_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return boost::simd::rdivide(a0,a1); }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divfloor_, tag::cpu_, (A0)(X)
                                   , ((simd_<floating_<A0>,X>))((simd_<floating_<A0>,X>))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return boost::simd::floor(a0/a1); }
  };
} } }

#endif
