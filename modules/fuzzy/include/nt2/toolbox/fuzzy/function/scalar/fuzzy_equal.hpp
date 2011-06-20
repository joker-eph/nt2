//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTION_SCALAR_FUZZY_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTION_SCALAR_FUZZY_EQUAL_HPP_INCLUDED

#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/dist.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::fuzzy_equal_, tag::cpu_,
                             (A0)(A1)(A2),
                             (fundamental_<A0>)(fundamental_<A1>)(fundamental_<A2>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::fuzzy_equal_(tag::fundamental_,tag::fundamental_,tag::fundamental_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)> {typedef bool type; };

    NT2_FUNCTOR_CALL(3)
    {
      return nt2::dist(a0, a1) <= a2*nt2::max(nt2::abs(a0),nt2::abs(a1));
    }

  };
} }

#endif
