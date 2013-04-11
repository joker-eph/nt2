//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_GENERIC_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_GENERIC_AVERAGE_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/average.hpp>
#include <boost/simd/include/constants/half.hpp>
#include <boost/simd/include/functions/simd/shrai.hpp>
#include <boost/simd/include/functions/simd/bitwise_and.hpp>
#include <boost/simd/include/functions/simd/bitwise_xor.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::average_, tag::cpu_
                                   , (A0)
                                   , (generic_< arithmetic_<A0> >)
                                     (generic_< arithmetic_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::bitwise_and(a0, a1)+
        (boost::simd::shrai(boost::simd::bitwise_xor(a0, a1), 1));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::average_, tag::cpu_
                                   , (A0)
                                   , (generic_< floating_<A0> >)
                                     (generic_< floating_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return (a0+a1)*boost::simd::Half<result_type>();
    }
  };
} } }


#endif
