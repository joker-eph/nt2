//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.predicates toolbox - is_nlez/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.predicates components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
///
#include <boost/simd/predicates/include/functions/is_nlez.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/simd/include/functions/negate.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/sdk/memory/is_aligned.hpp>
#include <boost/simd/sdk/memory/aligned_type.hpp>
#include <boost/simd/include/functions/load.hpp>


NT2_TEST_CASE_TPL ( is_nlez_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::is_nlez;
  using boost::simd::tag::is_nlez_;
  using boost::simd::load;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_nlez_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_nlez(-boost::simd::Zero<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Half<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Inf<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Minf<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Mone<vT>())[0], boost::simd::False<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Nan<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::One<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Quarter<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Two<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(is_nlez(boost::simd::Zero<vT>())[0], boost::simd::False<sr_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( is_nlez_integer__1_0, BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::is_nlez;
  using boost::simd::tag::is_nlez_;
  using boost::simd::load;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_nlez_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename r_t::value_type vsr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_nlez(boost::simd::One<vT>())[0], vsr_t(true));
  NT2_TEST_EQUAL(is_nlez(boost::simd::Two<vT>())[0], vsr_t(true));
  NT2_TEST_EQUAL(is_nlez(boost::simd::Zero<vT>())[0], vsr_t(false));
} // end of test for integral_
