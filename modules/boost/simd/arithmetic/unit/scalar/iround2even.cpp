//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - iround2even/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
///
#include <boost/simd/arithmetic/include/functions/iround2even.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

#include <boost/simd/constant/constant.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/minf.hpp>
#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/include/constants/nan.hpp>

NT2_TEST_CASE_TPL ( iround2even_real__1_0,  BOOST_SIMD_REAL_TYPES)
{

  using boost::simd::iround2even;
  using boost::simd::tag::iround2even_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<iround2even_(T)>::type r_t;
  typedef iT wished_r_t;


  // return type conformity test
   NT2_TEST_TYPE_IS( r_t, wished_r_t );


  // specific values tests
  NT2_TEST_ULP_EQUAL(iround2even(T(1.4)), 1, 0);
  NT2_TEST_ULP_EQUAL(iround2even(T(1.5)), 2, 0);
  NT2_TEST_ULP_EQUAL(iround2even(T(1.6)), 2, 0);
  NT2_TEST_ULP_EQUAL(iround2even(T(2.5)), 2, 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Half<T>()), boost::simd::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Inf<T>()), boost::simd::Inf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Mhalf<T>()), boost::simd::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Minf<T>()), boost::simd::Minf<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Mone<T>()), boost::simd::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Nan<T>()), boost::simd::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::One<T>()), boost::simd::One<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Zero<T>()), boost::simd::Zero<r_t>(), 0);
} // end of test for floating_

NT2_TEST_CASE_TPL ( iround2even_unsigned_int__1_0,  BOOST_SIMD_UNSIGNED_TYPES)
{

  using boost::simd::iround2even;
  using boost::simd::tag::iround2even_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<iround2even_(T)>::type r_t;
  typedef iT wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  // specific values tests
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::One<T>()), boost::simd::One<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Zero<T>()), boost::simd::Zero<r_t>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( iround2even_signed_int__1_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{

  using boost::simd::iround2even;
  using boost::simd::tag::iround2even_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<iround2even_(T)>::type r_t;
  typedef iT wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  // specific values tests
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Mone<T>()), boost::simd::Mone<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::One<T>()), boost::simd::One<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(iround2even(boost::simd::Zero<T>()), boost::simd::Zero<T>(), 0);
} // end of test for signed_int_
