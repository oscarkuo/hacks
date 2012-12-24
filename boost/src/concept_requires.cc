#include <iostream>
#include <boost/concept_check.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/concept/requires.hpp>

template<typename UnaFunc>
BOOST_CONCEPT_REQUIRES(
	((boost::UnaryFunction<UnaFunc, int, int>)),
	(void))
print_result (int value, UnaFunc func)
{
	std::cout << func(value) << std::endl;
}

int main() {
	using namespace boost;
	using namespace boost::lambda;

	print_result(10, (_1*2));
	return 0;
}
