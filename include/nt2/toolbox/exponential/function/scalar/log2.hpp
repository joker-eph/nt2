//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_LOG2_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_LOG2_HPP_INCLUDED

#include <nt2/toolbox/exponential/function/scalar/impl/logs.hpp>
//  MIGRATION WARNING you have to provide the file for the previous include from
//  nt2/core/numeric/function/details/scalar/impl/logs.hpp
//  of the old nt2

namespace nt2 { namespace functors
{

  //  no special validate for log2

  /////////////////////////////////////////////////////////////////////////////
  // Compute log2(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is float
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<log2_,tag::scalar_(tag::arithmetic_),float,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      return impl::logarithm<A0, tag::not_simd_type>::log2(a0);
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is double
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<log2_,tag::scalar_(tag::arithmetic_),double,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
       return ::log2(a0);
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<log2_,tag::scalar_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      return ::log2(type(a0));
    }
  };

} }

#endif
/// Revised by jt the 13/11/2010
