//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_FDLIBM_FUNCTIONS_SCALAR_IEEE754_ATAN2_HPP_INCLUDED
#define NT2_TOOLBOX_FDLIBM_FUNCTIONS_SCALAR_IEEE754_ATAN2_HPP_INCLUDED
#include <nt2/toolbox/fdlibm/functions/__ieee754_atan2.hpp>
#include <nt2/sdk/meta/upgrade.hpp>

  extern "C"{
    extern double fd___ieee754_atan2 ( double,double );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::fdlibm::tag::__ieee754_atan2_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)
                            )
  {

    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    {
      typedef result_type base;
      typedef typename meta::upgrade<base>::type  type;
      return nt2::fdlibm::__ieee754_atan2(type(a0), type(a1));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::fdlibm::tag::__ieee754_atan2_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_< double_<A0> >)(scalar_< double_<A1> >)
                            )
  {

    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;

    NT2_FUNCTOR_CALL(2)
    { return ::fd___ieee754_atan2(a0, a1); }
  };
} }


#endif
