//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_ERROR_ASSERT_AS_EXCEPTIONS_HPP_INCLUDED
#define NT2_SDK_ERROR_ASSERT_AS_EXCEPTIONS_HPP_INCLUDED

/*!
 * \file
 * \brief Defines macros and functions controlling runtime assertions
 */

#if defined(NT2_ASSERTS_AS_EXCEPTIONS) && !defined(BOOST_ENABLE_ASSERT_HANDLER)
#error BOOST_ENABLE_ASSERT_HANDLER must be defined to use NT2_ASSERTS_AS_EXCEPTIONS
#endif

#if (defined(NT2_ASSERTS_AS_EXCEPTIONS) && !defined(BOOST_NO_EXCEPTIONS))
#include <nt2/sdk/error/exception.hpp>
#include <iosfwd>
#include <sstream>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <boost/exception/all.hpp>
#include <boost/throw_exception.hpp>

namespace nt2
{
  /**
  * @brief Runtime assertion exception
  *
  * assert_exception is thrown when a runtime assertion triggers while the
  * preprocessor symbol NT2_ASSERTS_AS_EXCEPTIONS is defined.
  *
  * @usage
  * @include assert_exception.cpp
  **/
  struct BOOST_SYMBOL_VISIBLE assert_exception : nt2::exception
  {
    /**
    * Builds an assert_exception from the actual runtime assertion message
    **/
    assert_exception(std::string const& msg) : nt2::exception(msg) {}
  };
}

namespace boost
{
  // INTERNAL ONLY
  // Define a BOOST_ASSERT handler for the NT2_ASSERTS_AS_EXCEPTIONS mode.
  extern inline
  void assertion_failed ( char const* expr, char const* fn
                        , char const* f, long l
                        )
  {
    std::ostringstream ss;
    ss << f << ':' << l << ": " << fn << ": Assertion " << expr << " failed.";

    #ifndef BOOST_EXCEPTION_DISABLE
    ::boost::throw_exception
    ( ::boost::enable_error_info( ::nt2::assert_exception(ss.str()) )
      << ::boost::throw_function(fn)
      << ::boost::throw_file(f)
      << ::boost::throw_line(l)
    );
    #else
    ::boost::throw_exception( ::nt2::assert_exception(ss.str()) );
    #endif
  }

  // INTERNAL ONLY
  // Define a BOOST_ASSERT_MSG handler for the NT2_ASSERTS_AS_EXCEPTIONS mode.
  extern inline
  void assertion_failed_msg ( char const* expr, char const* msg
                            , char const* fn, char const* f, long l
                            )
  {
    std::ostringstream ss;
    ss  << f << ':' << l << ": " << fn << ": Assertion "
        << expr << " failed.\n\t" << msg;

    #ifndef BOOST_EXCEPTION_DISABLE
    ::boost::throw_exception( ::boost::enable_error_info( ::nt2::assert_exception(ss.str()) ) <<
        ::boost::throw_function(fn) <<
        ::boost::throw_file(f) <<
        ::boost::throw_line(l)
    );
    #else
    ::boost::throw_exception( ::nt2::assert_exception(ss.str()) );
    #endif
  }
}

#endif

#endif
