//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_FDTRC_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_FDTRC_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>

  extern "C"{
    extern float cephes_fdtrcf ( int,int,float );
    extern double cephes_fdtrc ( int,int,double );
    extern long double cephes_fdtrcl ( int,int,long double );
  }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::fdtrc_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)(scalar_< arithmetic_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_RETURN_TYPE(3)::type type;
      return nt2::cephes::fdtrc((a0), (a1), type(a2));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::fdtrc_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< double_<A0> >)(scalar_< double_<A1> >)(scalar_< double_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    { return cephes_fdtrc(a0, a1, a2); }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is float
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::fdtrc_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< float_<A0> >)(scalar_< float_<A1> >)(scalar_< float_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    { return cephes_fdtrcf(a0, a1, a2); }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A2 is long double
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::fdtrc_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (long_double_<A0>)(long_double_<A1>)(long_double_<A2>)
                            )
  {

    typedef typename meta::result_of<meta::floating(A2)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    { return cephes_fdtrcl(a0, a1, a2); }
  };
} }


#endif
