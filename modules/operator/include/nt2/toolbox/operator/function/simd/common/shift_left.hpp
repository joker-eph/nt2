//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_SHIFT_LEFT_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_SHIFT_LEFT_HPP_INCLUDED

#include <nt2/sdk/simd/native_cast.hpp>
#include <nt2/sdk/meta/as_integer.hpp>

#include <boost/mpl/logical.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/is_same.hpp>

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION_IF ( tag::shift_left_, tag::cpu_,
                                  (A0)(A1)(X),
                                  ( boost::mpl::and_<
                                    boost::mpl::not_< boost::is_same<A0, A1> >
                                  , boost::mpl::equal_to
                                                < boost::mpl::sizeof_<A0>
                                                , boost::mpl::sizeof_<A1>
                                                >
                                 >),
                                  (tag::shift_left_ ( simd_<arithmetic_<A0>,X>
                                                    , simd_<integer_<A1>,X>
                                                    )
                                  ),
                                  ((simd_<arithmetic_<A0>,X>))
                                  ((simd_<integer_<A1>,X>))
                                )
  {
    typedef A0 result_type;
    
    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_integer<A0>::type int_type;
      return  simd::
              native_cast<A0>(shift_left(simd::native_cast<int_type>(a0), a1));
    }
  };
} }

#endif
