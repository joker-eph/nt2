//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYPERBOLIC_FUNCTIONS_GENERIC_ASECH_HPP_INCLUDED
#define NT2_HYPERBOLIC_FUNCTIONS_GENERIC_ASECH_HPP_INCLUDED

#include <nt2/hyperbolic/functions/asech.hpp>
#include <nt2/include/functions/acosh.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/if_else.hpp>
#include <nt2/include/functions/if_else_allbits.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/constants/nan.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::asech_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return nt2::if_else(nt2::is_eqz(a0), nt2::Inf<result_type>(),
                          if_else_nan(nt2::eq(a0, nt2::One<A0>()),
                                      nt2::Zero<result_type>()));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::asech_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return nt2::acosh(nt2::rec(a0));
    }
  };
} }

#endif
