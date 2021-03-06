//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SWAR_FUNCTIONS_SIMD_COMMON_ARITH_HPP_INCLUDED
#define BOOST_SIMD_SWAR_FUNCTIONS_SIMD_COMMON_ARITH_HPP_INCLUDED

#include <boost/simd/swar/functions/arith.hpp>
#include <boost/simd/include/functions/simd/plus.hpp>
#include <boost/simd/include/functions/simd/multiplies.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::arith_, tag::cpu_
                                    , (X)(T)
                                    , ((target_< simd_< arithmetic_<T>,X> >))
                                    )
  {
    typedef typename T::type result_type;

    result_type operator()(T const& ) const
    {
      result_type that;
      for(std::size_t i=0;i<result_type::static_size;++i) that[i] = i;
      return that;
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::arith_, tag::cpu_
                                      , (A0)(X)(T)
                                      , (scalar_< arithmetic_<A0> >)
                                        ((target_< simd_< arithmetic_<T>,X> >))
                                      )
  {
    typedef typename T::type result_type;

    result_type operator()(A0 const& a0, T const& ) const
    {
      const result_type tmp =  boost::simd::arith<result_type>();
      return plus(tmp, a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::arith_, tag::cpu_
                                      , (A0)(X)(T)
                                      , ((simd_< arithmetic_<A0>, X >))
                                        ((target_< simd_< arithmetic_<T>,X> >))
                                      )
  {
    typedef typename T::type result_type;

    result_type operator()(A0 const& a0, T const& ) const
    {
      return bitwise_cast<result_type>(a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::arith_, tag::cpu_
                                      , (A0)(A1)(X)(T)
                                      , (scalar_< arithmetic_<A0> >)
                                        (scalar_< arithmetic_<A1> >)
                                        ((target_< simd_< arithmetic_<T>,X> >))
                                      )
  {
    typedef typename T::type result_type;

    result_type operator()(A0 const& a0, A1 const& a1, T const& ) const
    {
      const result_type tmp = boost::simd::arith<result_type>();
      return plus(multiplies(tmp, a1), a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::arith_, tag::cpu_
                                      , (A0)(A1)(X)(T)
                                      , ((simd_< arithmetic_<A0>, X >))
                                        (generic_< arithmetic_<A1> >)
                                        ((target_< simd_< arithmetic_<T>,X> >))
                                      )
  {
    typedef typename T::type result_type;

    result_type operator()(A0 const& a0, A1 const& a1, T const& ) const
    {
      return bitwise_cast<result_type>(a0);
    }
  };
} } }

#endif
