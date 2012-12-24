#include <iostream>
#include <algorithm>
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

template<typename BinFunc>
BOOST_CONCEPT_REQUIRES(
	((boost::BinaryFunction<BinFunc, void, int&, int&>)),
	(void))
do_something_to_two_values (int& value1, int& value2, BinFunc func)
{
	func(value1, value2);
}

int main() {
	using namespace boost;
	using namespace boost::lambda;

	print_result(10, (_1*2));

	int value1 = 40;
	int value2 = 80;

	do_something_to_two_values(value1, value2, std::swap<int>);

	std::cout << value1 << std::endl;
	std::cout << value2 << std::endl;

	return 0;
}
