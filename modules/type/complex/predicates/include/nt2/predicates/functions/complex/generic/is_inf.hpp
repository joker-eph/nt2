//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_PREDICATES_FUNCTIONS_COMPLEX_GENERIC_IS_INF_HPP_INCLUDED
#define NT2_PREDICATES_FUNCTIONS_COMPLEX_GENERIC_IS_INF_HPP_INCLUDED
#include <nt2/predicates/functions/is_inf.hpp>
#include <nt2/include/functions/is_inf.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/logical_or.hpp>
#include <nt2/include/functions/logical_andnot.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/imaginary.hpp>
#include <nt2/sdk/simd/logical.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>

namespace nt2 { namespace ext
{
  // complex
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::is_inf_, tag::cpu_, (A0)
                            , (generic_< complex_< arithmetic_<A0> > >)
                            )
  {
    typedef typename  meta::as_real<A0>::type rA0;
    typedef typename meta::as_logical<rA0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      //C99 standard:A complex or imaginary value with at least one infinite part
      //is regarded as an infinity (even if its other part is a NaN).
      return logical_or(is_inf(nt2::imag(a0)),is_inf(nt2::real(a0)));
    }
  };

  // imaginary
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::is_inf_, tag::cpu_, (A0),
                              (generic_< imaginary_< arithmetic_<A0> > > )
                            )
  {
    typedef typename  meta::as_real<A0>::type rA0;
    typedef typename meta::as_logical<rA0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return is_inf(nt2::imag(a0));
    }
  };
  // dry
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::is_inf_, tag::cpu_, (A0),
                              (generic_< dry_< arithmetic_<A0> > > )
                            )
  {
    typedef typename  meta::as_real<A0>::type rA0;
    typedef typename meta::as_logical<rA0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return is_inf(nt2::real(a0));
    }
  };

} }

#endif
