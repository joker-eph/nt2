//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_GENERIC_REMAINDER_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_GENERIC_REMAINDER_HPP_INCLUDED
#include <boost/simd/arithmetic/functions/remainder.hpp>
#include <boost/simd/include/functions/simd/abs.hpp>
#include <boost/simd/include/functions/simd/idivround.hpp>
#include <boost/simd/include/functions/simd/divround.hpp>
#include <boost/simd/include/functions/simd/multiplies.hpp>
#include <boost/simd/include/functions/simd/minus.hpp>

/////////////////////////////////////////////////////////////////////////////
// The remainder() function computes the remainder of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded to the nearest
// integer.  If the boost::simd::absolute value of x-n*y is 0.5, n is chosen to be even.
// The drem function is just an alias for the same thing.
/////////////////////////////////////////////////////////////////////////////

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::remainder_, tag::cpu_
                                   , (A0)
                                   , (generic_< arithmetic_<A0> >)
                                     (generic_< arithmetic_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return a0-boost::simd::multiplies(idivround(a0, a1), a1);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::remainder_, tag::cpu_
                                   , (A0)
                                   , (generic_< floating_<A0> >)
                                     (generic_< floating_<A0> >)
                                   )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return a0-divround(a0, a1)*a1;
    }
  };
} } }

#endif
