//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 trigonometric toolbox - cosine/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of trigonometric components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/trigonometric/include/functions/cosine.hpp>
#include <nt2/toolbox/trigonometric/functions/scalar/impl/selection_tags.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<cosine_> from trigonometric
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::cosine_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::direct_medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::direct_medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::direct_medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(cosine_<nt2::direct_medium_>,(RS(vT,-20*nt2::Pi<T>(),20*nt2::Pi<T>())))
}

#undef RS
