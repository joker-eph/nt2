//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 hyperbolic toolbox - csch/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of hyperbolic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 20/02/2011
/// modified by jt the 17/04/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/functions/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/hyperbolic/include/csch.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/exponential/include/constants.hpp>
#include <nt2/toolbox/libc/include/sinh.hpp>
#include <nt2/include/functions/rec.hpp>
extern "C" { long double cephes_sinhl(long double); }

NT2_TEST_CASE_TPL ( csch_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::csch;
  using nt2::tag::csch_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<csch_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(csch(-nt2::Zero<T>()), -nt2::Inf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(csch(nt2::Inf<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(csch(nt2::Minf<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(csch(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(csch(nt2::Zero<T>()), nt2::Inf<r_t>(), 0.5);
} // end of test for real_

NT2_TEST_CASE_TPL ( csch_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::csch;
  using nt2::tag::csch_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<csch_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(csch(nt2::Zero<T>()), nt2::Nan<r_t>(), 0.5);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( csch_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::csch;
  using nt2::tag::csch_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<csch_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(csch(nt2::Zero<T>()), nt2::Nan<r_t>(), 0.5);
} // end of test for signed_int_
