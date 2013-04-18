//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_GENERIC_MOD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_GENERIC_MOD_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/mod.hpp>
#include <boost/simd/include/functions/simd/selsub.hpp>
#include <boost/simd/include/functions/simd/if_else.hpp>
#include <boost/simd/include/functions/simd/is_nez.hpp>
#include <boost/simd/include/functions/simd/divfloor.hpp>
#include <boost/simd/include/functions/simd/idivfloor.hpp>
#include <boost/simd/include/functions/simd/multiplies.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::mod_, tag::cpu_
                                   , (A0)
                                   , ((generic_<floating_<A0> >))
                                     ((generic_<floating_<A0> >))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::selsub(boost::simd::is_nez(a1),
                                 a0,
                                 boost::simd::divfloor(a0,a1)*a1
                                );
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::mod_, tag::cpu_
                                   , (A0)
                                   , ((generic_<arithmetic_<A0> >))
                                     ((generic_<arithmetic_<A0> >))
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return boost::simd::selsub(boost::simd::is_nez(a1),
                                 a0,
                                 boost::simd::idivfloor(a0,a1)*a1
                                );

    }
  };


} } }

#endif
