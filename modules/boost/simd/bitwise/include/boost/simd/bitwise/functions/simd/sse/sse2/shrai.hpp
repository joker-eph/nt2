//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_BITWISE_FUNCTIONS_SIMD_SSE_SSE2_SHRAI_HPP_INCLUDED
#define BOOST_SIMD_BITWISE_FUNCTIONS_SIMD_SSE_SSE2_SHRAI_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT
#include <boost/simd/bitwise/functions/shrai.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/include/functions/simd/is_gtz.hpp>
#include <boost/simd/include/functions/simd/if_else.hpp>
#include <boost/simd/include/functions/simd/group.hpp>
#include <boost/simd/include/functions/simd/split.hpp>
#include <boost/simd/include/functions/simd/make.hpp>
#include <boost/simd/bitwise/functions/simd/common/shrai.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shrai_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      typedef typename dispatch::meta::as_integer<A0,signed>::type sint;
      sint const that = _mm_srai_epi32(bitwise_cast<sint>(a0), a1);
      return bitwise_cast<A0>(that);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shrai_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      typedef typename dispatch::meta::as_integer<A0,signed>::type sint;
      sint const that = _mm_srai_epi16(bitwise_cast<sint>(a0), a1);
      return bitwise_cast<A0>(that);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shrai_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<int8_<A0>,boost::simd::tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0                                              result_type;
    typedef typename meta::make_dependent<int16_t,A0>::type sub_t;
    typedef native<sub_t, boost::simd::tag::sse_>           gen_t;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      gen_t a0h, a0l;
      boost::fusion::tie(a0l, a0h) = split(a0);
      return bitwise_cast<A0>(group(shrai(a0l, a1),shrai(a0h, a1)));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shrai_, boost::simd::tag::sse2_
                            , (A0)(A1)
                            , ((simd_<int64_<A0>,boost::simd::tag::sse_>))
                              (scalar_< integer_<A1> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return make<A0>(shrai(a0[0], a1), shrai(a0[1], a1));
    }
  };
} } }

#endif
#endif
