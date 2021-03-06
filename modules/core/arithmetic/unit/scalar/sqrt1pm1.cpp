//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - sqrt1pm1/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// modified by jt the 06/04/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/arithmetic/include/functions/sqrt1pm1.hpp>

NT2_TEST_CASE_TPL ( sqrt1pm1_real__1_0,  NT2_REAL_TYPES)
{

  using nt2::sqrt1pm1;
  using nt2::tag::sqrt1pm1_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<sqrt1pm1_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Inf<T>()), nt2::Inf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Minf<T>()), nt2::Nan<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Mone<T>()), nt2::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Nan<T>()), nt2::Nan<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::One<T>()), nt2::Sqrt_2<r_t>()-nt2::One<r_t>(), 2);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for floating_

NT2_TEST_CASE_TPL ( sqrt1pm1_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{

  using nt2::sqrt1pm1;
  using nt2::tag::sqrt1pm1_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<sqrt1pm1_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::One<T>()), nt2::Sqrt_2<r_t>()-nt2::One<r_t>(), 2);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( sqrt1pm1_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{

  using nt2::sqrt1pm1;
  using nt2::tag::sqrt1pm1_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<sqrt1pm1_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Mone<T>()), nt2::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::One<T>()), nt2::Sqrt_2<r_t>()-nt2::One<r_t>(), 2);
  NT2_TEST_ULP_EQUAL(sqrt1pm1(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for signed_int_
