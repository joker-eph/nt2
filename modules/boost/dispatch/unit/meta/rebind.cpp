//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/dispatch/meta/as.hpp>
#include <boost/dispatch/meta/rebind.hpp>
#include <vector>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

template<typename T> struct foo
{
  template<typename U> struct rebind
  {
    typedef foo<U> type;
  };
};

NT2_TEST_CASE_TPL( rebind_values, (char)(short)(int)(float)(double))
{
  using boost::dispatch::meta::rebind;

  NT2_TEST_TYPE_IS( (typename rebind<T, void*>::type), void*);
}

NT2_TEST_CASE_TPL( rebind_as, (char)(short)(int)(float)(double))
{
  using boost::dispatch::meta::as_;
  using boost::dispatch::meta::rebind;

  NT2_TEST_TYPE_IS( (typename rebind<as_<T>, void*>::type), as_<void*>);
}

NT2_TEST_CASE_TPL( rebind_allocator, (char)(short)(int)(float)(double))
{
  using std::allocator;
  using boost::dispatch::meta::rebind;

  NT2_TEST_TYPE_IS( (typename rebind<allocator<T>, void*>::type), allocator<void*>);
}

NT2_TEST_CASE_TPL( rebind_foo, (char)(short)(int)(float)(double))
{
  using boost::dispatch::meta::rebind;

  NT2_TEST_TYPE_IS( (typename rebind<foo<T>, void*>::type), foo<void*>);
}
