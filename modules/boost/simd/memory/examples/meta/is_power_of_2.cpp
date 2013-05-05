#include <boost/simd/meta/is_power_of_2.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/int.hpp>

int main()
{
  using boost::mpl::int_;

  BOOST_MPL_ASSERT    (( boost::simd::meta::is_power_of_2< int_<2> >::type  ));
  BOOST_MPL_ASSERT    (( boost::simd::meta::is_power_of_2< int_<32> >::type ));
  BOOST_MPL_ASSERT_NOT(( boost::simd::meta::is_power_of_2< int_<0> >::type  ));
  BOOST_MPL_ASSERT_NOT(( boost::simd::meta::is_power_of_2< int_<6> >::type  ));
}
