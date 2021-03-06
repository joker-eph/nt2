//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_OPTIMIZE_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_OPTIMIZE_FMA_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/fma.hpp>
#include <boost/simd/operator/functions/plus.hpp>
#include <boost/simd/operator/functions/multiplies.hpp>
#include <boost/dispatch/dsl/category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_ , tag::formal_, (D)(A0)(A1)
                                   , ((node_<A0, boost::simd::tag::multiplies_, mpl::long_<2> , D>))(unspecified_<A1>)
                                   )
  {
    BOOST_DISPATCH_RETURNS(2, (A0 const& a0, A1 const& a1),
      fma(boost::proto::child_c<0>(a0), boost::proto::child_c<1>(a0), a1)
    )
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_ , tag::formal_, (D)(A0)(A1)
                                   , (unspecified_<A0>)((node_<A1, boost::simd::tag::multiplies_, mpl::long_<2> , D>))
                                   )
  {
    BOOST_DISPATCH_RETURNS(2, (A0 const& a0, A1 const& a1),
      fma(boost::proto::child_c<0>(a1), boost::proto::child_c<1>(a1), a0)
    )
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_ , tag::formal_, (D)(A0)(A1)
                                   , ((node_<A0, boost::simd::tag::multiplies_, mpl::long_<2> , D>))((node_<A1, boost::simd::tag::multiplies_, mpl::long_<2> , D>))
                                   )
  {
    BOOST_DISPATCH_RETURNS(2, (A0 const& a0, A1 const& a1),
      fma(boost::proto::child_c<0>(a0), boost::proto::child_c<1>(a0), a1)
    )
  };
} } }

#endif
