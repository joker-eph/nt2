//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.operator toolbox - logical_or/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/operator/include/functions/logical_or.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( logical_or_integer__2_0,  BOOST_SIMD_INTEGRAL_TYPES)
{

  using boost::simd::logical_or;
  using boost::simd::tag::logical_or_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<logical_or_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::simd::logical<T> wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(logical_or(boost::simd::One<T>(), boost::simd::One<T>()), r_t(true));
  NT2_TEST_EQUAL(logical_or(boost::simd::One<T>(),boost::simd::Zero<T>()), r_t(true));
  NT2_TEST_EQUAL(logical_or(boost::simd::Zero<T>(), boost::simd::Zero<T>()), r_t(false));
} // end of test for integer_

NT2_TEST_CASE_TPL ( logical_or_real__2_0,  BOOST_SIMD_REAL_TYPES)
{

  using boost::simd::logical_or;
  using boost::simd::tag::logical_or_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<logical_or_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::simd::logical<T> wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );

  std::cout << nt2::type_id<r_t> () << std::endl;
  std::cout << nt2::type_id<wished_r_t> () << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(logical_or(boost::simd::Inf<T>(), boost::simd::Inf<T>()), r_t(true));
  NT2_TEST_EQUAL(logical_or(boost::simd::Minf<T>(), boost::simd::Minf<T>()), r_t(true));
  NT2_TEST_EQUAL(logical_or(boost::simd::Nan<T>(), boost::simd::Nan<T>()), r_t(true));
  NT2_TEST_EQUAL(logical_or(boost::simd::One<T>(),boost::simd::Zero<T>()), r_t(true));
  NT2_TEST_EQUAL(logical_or(boost::simd::Zero<T>(), boost::simd::Zero<T>()), r_t(false));
} // end of test for floating_
