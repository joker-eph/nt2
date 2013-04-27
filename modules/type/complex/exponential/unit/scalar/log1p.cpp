//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.exponential toolbox - log1p/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of exponential components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
///
#include <nt2/exponential/include/functions/log1p.hpp>
#include <nt2/include/functions/log.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/constant/constant.hpp>
#include <nt2/include/constants/log_2.hpp>


NT2_TEST_CASE_TPL ( log1p_real__1_0,  NT2_REAL_TYPES)
{

  using nt2::log1p;
  using nt2::tag::log1p_;
  typedef std::complex<T> cT;
  typedef typename nt2::meta::call<log1p_(cT)>::type r_t;
  typedef typename nt2:: meta::as_complex<T>::type wished_r_t;

  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;

  // specific values tests
  NT2_TEST_ULP_EQUAL(nt2::log1p(nt2::Inf<cT>()),   cT(nt2::Inf<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(nt2::Minf<cT>()),  cT(nt2::Inf<T>(), nt2::Pi<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(nt2::Mone<cT>()),  cT(nt2::Minf<T>(), nt2::Zero<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(nt2::Nan<cT>()),   cT(nt2::Nan<T>(), nt2::Zero<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(cT(nt2::Nan<T>(),nt2::Nan<T>())),  cT(nt2::Nan<T>(), nt2::Nan<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(nt2::One<cT>()),   cT(nt2::Log_2<T>(), nt2::Zero<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(nt2::Zero<cT>()),  cT(nt2::Zero<T>(), nt2::Zero<T>()), 0.5);
  NT2_TEST_ULP_EQUAL(nt2::log1p(cT(nt2::Zero<T>(), nt2::One<T>())),cT(nt2::log(nt2::Sqrt_2<T>()), nt2::Pio_2<T>()/2), 0.5);
} // end of test for floating_

