/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_ERRORS_WARNING_HPP_INCLUDED
#define NT2_SDK_ERRORS_WARNING_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Compile-time warning
// Documentation: http://nt2.lri.fr/sdk/errors/warning.html
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/config/compiler.hpp>
#include <boost/preprocessor/stringize.hpp>

////////////////////////////////////////////////////////////////////////////////
// Activate only in VERBOSE MODE
////////////////////////////////////////////////////////////////////////////////
#if defined(NT2_VERBOSE)
#if defined(NT2_COMPILER_MSVC)
////////////////////////////////////////////////////////////////////////////////
// #pragma message on MSVC is dim so we add some info
////////////////////////////////////////////////////////////////////////////////
#define NT2_WARNING_LOCATION __FILE__ "(" BOOST_PP_STRINGIZE(__LINE__) ") : "
#define NT2_WARN(exp) (NT2_WARNING_LOCATION "[NT2 WARNING] -- " exp)
#define NT2_WARNING(X) __pragma( (message NT2_WARN(X)) )
#elif defined(NT2_COMPILER_GNU_C)
////////////////////////////////////////////////////////////////////////////////
// #pragma message on g++ just need a call to _Pragma
////////////////////////////////////////////////////////////////////////////////
#define NT2_WARN(exp) "[NT2 WARNING] -- " #exp
#define NT2_WARNING(X) _Pragma( BOOST_PP_STRINGIZE(message NT2_WARN(X)) )
#endif
#else
////////////////////////////////////////////////////////////////////////////////
// In non-VERBOSE MODE, NT2_WARNING is no-op
////////////////////////////////////////////////////////////////////////////////
#define NT2_WARNING(X)
#endif

#endif
