//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_INCBPS_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTION_SCALAR_INCBPS_HPP_INCLUDED

//   extern "C"{
//     extern float cephes_incbpsf ( float,float,float );
//   }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( cephes::tag::incbps_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_< arithmetic_<A0> >)(scalar_< arithmetic_<A1> >)(scalar_< arithmetic_<A2> >)
                            )
  {

    typedef typename meta::result_of<meta::floating(A0)>::type result_type;

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_RETURN_TYPE(3)::type type;
      ignore_unused(a0);
      ignore_unused(a1);
      ignore_unused(a2);
      return 0; //nt2::cephes::incbps(float(a0), float(a1), float(a2));
    }
  };
} }


// /////////////////////////////////////////////////////////////////////////////
// // Implementation when type A0 is float
// /////////////////////////////////////////////////////////////////////////////
// NT2_REGISTER_DISPATCH(cephes::tag::incbps_, tag::cpu_,
//                         (A0)(A1)(A2),
//                         (float_<A0>)(float_<A1>)(float_<A2>)
//                        )

// namespace nt2 { namespace ext
// {
//   template<class Dummy>
//   struct call<cephes::tag::incbps_(tag::float_,tag::float_,tag::float_),
//               tag::cpu_, Dummy> : callable
//   {
//     template<class Sig> struct result;
//     template<class This,class A0, class A1, class A2>
//     struct result<This(A0, A1, A2)> : meta::result_of<meta::floating(A0)>{};

//     NT2_FUNCTOR_CALL(3){ return cephes_incbpsf(a0, a1, a2); }
//   };
// } }

#endif
