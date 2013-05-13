//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2013   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_DISPATCH_META_REBIND_HPP_INCLUDED
#define BOOST_DISPATCH_META_REBIND_HPP_INCLUDED

#include <boost/dispatch/meta/enable_if_type.hpp>

namespace boost { namespace dispatch
{
  namespace details
  {
    template<typename T, typename U, typename Enable=void>
    struct rebind_impl
    {
      typedef U type;
    };

    template<typename T, typename U>
    struct rebind_impl< T, U
                      , typename
                        meta::enable_if_type<typename T::template rebind<U>::type>::type
                      >
    {
      typedef typename T::template rebind<U>::type type;
    };

    template<typename T, typename U>
    struct rebind_impl< T, U
                      , typename
                        meta::enable_if_type<typename T::template rebind<U>::other >::type
                      >
    {
      typedef typename T::template rebind<U>::other type;
    };
  }

  namespace meta
  {
    template<typename T, typename U>
    struct rebind : details::rebind_impl<T,U>
    {};
  }
} }

#endif
