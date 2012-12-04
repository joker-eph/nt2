//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTIONS_FMA_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTIONS_FMA_HPP_INCLUDED

#include <boost/simd/toolbox/arithmetic/functions/fma.hpp>

namespace nt2
{
  namespace tag
  {
    using boost::simd::tag::fma_;
  }

  using boost::simd::fma;
  using boost::simd::fam;
  using boost::simd::madd;
  using boost::simd::amul;
}

#endif
