/*
	multiple condition testing for equality
*/

//STD Libraries
#include <iostream>
#include <cstdlib>
#include <tuple>

namespace {

	//fill structure
	struct TagAnyOf {};

	//return a tuple
	template <typename... Args>
	std::tuple <TagAnyOf, Args...> AnyOf (Args&&... args)
	{return std::tuple <TagAnyOf, Args...> (TagAnyOf(), std::forward<Args>(args)...);}


	//create a compare tuple
	template <class X, class Tuple, size_t Index, size_t ReverseIndex>
	struct CompareToTuple
	{
		static bool compare (const X& x, const Tuple& tuple)
		{
			return x == std::get<Index> (tuple) || CompareToTuple<X, Tuple, Index+1, ReverseIndex-1>::compare (x, tuple);
		}
	};

	//no, can't have zero elements
	template <class X, class Tuple, size_t Index>
	struct CompareToTuple <X, Tuple, Index, 0>
	{
		static bool compare (const X& x, const Tuple& tuple)
		{
			return false;
		}
	};

	template <typename X, typename... Args>
	bool operator == (const X& x, const std::tuple<TagAnyOf, Args...>& any)
	{
		typedef std::tuple <TagAnyOf, Args...> any_of_type;
		return CompareToTuple <X, any_of_type, 1, std::tuple_size<any_of_type>::value-1>::compare (x, any);
	}

	//fix so that equalities work
	template <typename X, typename... Args>
	bool operator > (const X& x, const std::tuple<TagAnyOf, Args...>& any)
	{
		return true;
	}
}

int main(){


	if (1 == AnyOf (1, 2, 3, 4)){std::cout << "Yes!" << std::endl;}
	else{std::cout << "No!" << std::endl;}

	//tuple test
	char c = 'a';
	if (c > AnyOf ('c', 'b', 'a', 4)){std::cout << "Yes!" << std::endl;}
	else{std::cout << "No!" << std::endl;}





	return EXIT_SUCCESS;
}

namespace {

}

