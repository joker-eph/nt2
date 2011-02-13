//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_REMAINDER_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_COMMON_REMAINDER_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/negate.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/idivfix.hpp>
#include <nt2/include/functions/abs.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::remainder_, tag::cpu_,
                            (A0)(X),
                            ((simd_<arithmetic_<A0>,X>))
                            ((simd_<arithmetic_<A0>,X>))
                           );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::remainder_(tag::simd_<tag::arithmetic_, X> ,
                              tag::simd_<tag::arithmetic_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
//       const A0 a = abs(a0);
//       const A0 b = abs(a1);
//       return sel(b, negate(a-idivfix(a, b)*b, a), a);
      return a0-idivround(a0, a1)*a1; 
    }

  };
} }

#endif
// modified by jt the 04/01/2011
// modified manually by jt the 04/01/2011
