#pragma once
#include <algorithm>
#include <utility>

//A type trait to test that a type exists in a type
//(enable the function only if the type passed in is a container with iterators)
template <typename T>
struct has_iterator_type
{
  typedef char yes[1];
  typedef char no[2];

  template <typename C> static yes& test(typename C::iterator*);
  template <typename> static no& test(...);

  static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

namespace{

	// Non-modifying sequence operations
	template<class Container, class UnaryPredicate>
	auto all_of(Container & c, UnaryPredicate const& p)
	{return std::all_of(c.begin(), c.end(), p);}

	template<class Container, class UnaryPredicate>
	auto any_of(Container & c, UnaryPredicate const& p)
	{return std::any_of(c.begin(), c.end(), p);}

	template<class Container, class UnaryPredicate>
	auto none_of(Container & c, UnaryPredicate const& p)
	{return std::none_of(c.begin(), c.end(), p);}

	template<class Container, class UnaryFunction>
	auto for_each(Container & c, UnaryFunction const& f)
	{return std::for_each(c.begin(), c.end(), f);}

	template< class Container, class T>
	auto count(Container & c, T const& value)
	{return std::count(c.begin(), c.end(), value);}

	template< class Container, class UnaryPredicate>
	auto count_if(Container & c, UnaryPredicate const& p)
	{return std::count_if(c.begin(), c.end(), p);}

	template<class Container, class InputIt>
	auto mismatch( Container & c, InputIt const& i)
	{return std::mismatch(c.begin(), c.end(), i);}

	template<class Container, class InputIt2, class BinaryPredicate>
	auto mismatch( Container & c, InputIt2 const& i,BinaryPredicate const& p )
	{return std::mismatch(c.begin(), c.end(), i, p);}

	template<class Container1, class Container2>
	auto mismatch( Container1 & c1, Container2 & c2)
	{return std::mismatch(c1.begin(), c1.end(), c2.begin(),c2.end());}

	template<class Container1, class Container2, class BinaryPredicate>
	auto mismatch( Container1 & c1, Container2 & c2,BinaryPredicate p )
	{return std::mismatch(c1.begin(), c1.end(), c2.begin(),c2.end(), p);}

	template<class Container, class InputIt2, typename B = bool>
	typename std::enable_if<!has_iterator_type<InputIt2>::value,B>::type equal( Container & c, InputIt2 f)
	{return std::equal(c.begin(), c.end(), f);}

	template<class Container, class InputIt2, class BinaryPredicate>
	auto equal( Container & c, InputIt2 f,BinaryPredicate p )
	{return std::equal(c.begin(), c.end(), f, p);}

	template<class Container1, class Container2, typename B = bool>
	typename std::enable_if<has_iterator_type<Container2>::value,B>::type equal( Container1 & c1, Container2 & c2)
	{return std::equal(c1.begin(), c1.end(), c2.begin(),c2.end());}

	template<class Container1, class Container2, class BinaryPredicate>
	auto equal( Container1 & c1, Container2 & c2,BinaryPredicate p )
	{return std::equal(c1.begin(), c1.end(), c2.begin(),c2.end(), p);}
/*
	template< class Container, class T >
	typename Container::iterator find( Container & c, T const& value )
	{ return std::find(c.begin(),c.end(),value);}

	template< class Container, class UnaryPredicate >
	typename Container::iterator find_if( Container & c, UnaryPredicate p )
	{ return std::find_if(c.begin(),c.end(),p);}

	template< class Container, class UnaryPredicate >
	typename Container::iterator find_if_not( Container & c, UnaryPredicate p )
	{ return std::find_if_not(c.begin(),c.end(),p);}

	template< class Container1, class Container2>
	typename Container1::iterator find_end(Container1 & c1, Container2 & c2)
	{return std::find_end(c1.begin(),c1.end(),c2.begin(),c2.begin());}

	template< class Container1, class Container2, class BinaryPredicate>
	typename Container1::iterator find_end(Container1 & c1, Container2 & c2, BinaryPredicate p)
	{return std::find_end(c1.begin(),c1.end(),c2.begin(),c2.begin(),p);}

	template< class Container1, class Container2 >
	typename Container1::iterator find_first_of( Container1 & c1, Container2 & c2)
	{ return std::find_first_of(c1.begin(),c1.end(),c2.begin(),c2.begin());}

	//template< class InputIt, class ForwardIt >
	//InputIt find_first_of( InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last );

	template< class Container1, class Container2, class BinaryPredicate >
	typename Container1::iterator find_first_of( Container1 & c1, Container2 & c2, BinaryPredicate p )
	{ return std::find_first_of(c1.begin(),c1.end(),c2.begin(),c2.begin(),p);}

	//template< class InputIt, class ForwardIt, class BinaryPredicate >
	//InputIt find_first_of( InputIt first, InputIt last,ForwardIt s_first, ForwardIt s_last, BinaryPredicate p );

	template< class Container >
	typename Container::iterator adjacent_find( Container & c )
	{return std::adjacent_find(c.begin(),c.end());}

	template< class Container, class BinaryPredicate >
	typename Container::iterator adjacent_find( Container & c, BinaryPredicate p )
	{return std::adjacent_find(c.begin(),c.end(),p);}

	template< class Container1, class Container2 >
	typename Container1::iterator search( Container1 & c1, Container2 & c2)
	{return std::search(c1.begin(),c1.end(),c2.begin(),c2.begin());}

	template< class Container1, class Container2, class BinaryPredicate >
	typename Container1::iterator search( Container1 & c1, Container2 & c2, BinaryPredicate p )
	{return std::search(c1.begin(),c1.end(),c2.begin(),c2.begin(),p);}

	template< class Container, class Size, class T >
	typename Container::iterator search_n(Container & c, Size count, T const& value )
	{return std::search_n(c.begin(),c.end(),count,value);}

	template< class Container, class Size, class T, class BinaryPredicate >
	typename Container::iterator search_n(Container & c, Size count, T const& value, BinaryPredicate p )
	{return std::search_n(c.begin(),c.end(),count,value,p);}

	//Modifying sequence operations
	template< class Container, class OutputIt >
	OutputIt copy( Container & c, OutputIt i )
	{return std::copy(c.begin(),c.end(),i);}

	template< class Container, class OutputIt, class UnaryPredicate >
	OutputIt copy_if( Container & c,OutputIt i,UnaryPredicate p )
	{return std::copy(c.begin(),c.end(),i,p);}

	template< class Container, class Size, class OutputIt >
	OutputIt copy_n( Container & c, Size count, OutputIt result )
	{return std::copy_n(c.begin(),count,result);}

	template< class Container, class BidirIt2 >
	typename Container::iterator copy_backward( Container & c, BidirIt2 i )
	{return std::copy_backward(c.begin(),c.end(),i);}

	template< class Container, class OutputIt >
	OutputIt move(Container & c, OutputIt i)
	{return std::move(c.begin(), c.end(), i);}

	template< class Container, class BidirIt2 >
	BidirIt2 move_backward( Container & c, BidirIt2 i )
	{return std::move_backward(c.begin(), c.end(), i);}

	template< class Container, class T >
	void fill(Container & c, T const& value )
	{return std::fill(c.begin(), c.end(), value);}

	template< class Container, class Size, class T >
	void fill_n( Container & c, Size count, T const& value )
	{return std::fill_n(c.begin(), count, value);}

	template< class Container, class Size, class T >
	typename Container::iterator fill_n( Container & c, Size count, T const& value )
	{return std::fill_n(c.begin(), count, value);}

	template<class Container, class OutputIt, class UnaryOperation >
	OutputIt transform(Container & c, OutputIt i, UnaryOperation unary_op )
	{return std::transform(c.begin(), c.end(), i, unary_op);}

	template<class Container, class InputIt2, class OutputIt, class BinaryOperation >
	OutputIt transform(Container & c, InputIt2 i,OutputIt o, BinaryOperation binary_op )
	{return std::transform(c.begin(), c.end(), i, o, binary_op);}

	template<class Container1, class Container2, class OutputIt, class BinaryOperation >
	OutputIt transform(Container1 & c1, Container2 & c2, OutputIt o, BinaryOperation binary_op )
	{return std::transform(c1.begin(), c1.end(), c2.begin(), o, binary_op);}

	template< class Container, class Generator >
	void generate( Container & c, Generator g )
	{return std::generate(c.begin(),c.end(),g);}

	template< class Container, class Size, class Generator >
	void generate_n(Container & c, Size count, Generator g )
	{return std::generate_n(c.begin(),count,g);}

	template< class Container, class Size, class Generator >
	typename Container::iterator generate_n(Container & c, Size count, Generator g )
	{return std::generate_n(c.begin(),count,g);}

	template< class Container, class T >
	typename Container::iterator remove(Container & c, T const& value )
	{return std::remove(c.begin(),c.end(),value);}

	template< class Container, class UnaryPredicate >
	typename Container::iterator remove_if(Container & c, UnaryPredicate p )
	{return std::remove_if(c.begin(),c.end(),p);}

	template< class Container, class OutputIt, class T >
	OutputIt remove_copy(Container & c, OutputIt i, T const& value )
	{return std::remove_copy(c.begin(),c.end(),i,value);}

	template< class Container, class OutputIt, class UnaryPredicate >
	OutputIt remove_copy_if(Container & c, OutputIt i, UnaryPredicate p )
	{return std::remove_copy(c.begin(),c.end(),i,p);}

	template< class Container, class T >
	void replace(Container & c, T const& old_value, T const& new_value )
	{return std::replace(c.begin(),c.end(),old_value,new_value);}

	template< class Container, class UnaryPredicate, class T >
	void replace_if(Container & c,UnaryPredicate p, T const& new_value );
	{return std::replace_if(c.begin(),c.end(),p,new_value);}

	template< class Container, class OutputIt, class T >
	OutputIt replace_copy(Container & c, OutputIt i, T const& old_value, T const& new_value )
	{return std::replace_copy(c.begin(),c.end(),i,old_value,new_value);}

	template<class Container, class OutputIt, class UnaryPredicate, class T >
	OutputIt replace_copy_if(Container & c, OutputIt i, UnaryPredicate p, T const& new_value );
	{return std::replace_copy_if(c.begin(),c.end(),i,p,new_value);}

	//swap

	template< class Container1, class Container2 >
	typename Container1::iterator swap_ranges( Container1 & c1, Container1 & c2)
	{return std::swap_ranges(c1.begin(), c1.end(), c2.begin());}

	//iter_swap

	template< class Container>
	void reverse(Container c)
	{return std::reverse(c.begin(),c.end());}

	template< class Container1, class Container2>
	Container2::iterator reverse_copy(Container1 & c1, Container2 & c2)
	{return std::reverse_copy(c1.begin(),c1.end(),c2.begin());}

	template< class Container>
	void rotate(Container & c, Container::iterator & i)
	{return std::roatate(c.begin(),i,c.end());}

	template< class Container>
	Container::iterator rotate(Container & c, Container::iterator & i)
	{return std::roatate(c.begin(),i,c.end());}

	template< class Container1, class Container2>
	Container2::iterator rotate_copy(Container1 & c1, Container::iterator & i, Container2 & c2)
	{ return std::rotate_copy(c1.begin(),i,c.end(),c2.begin());}

	//add the appropiate C++14 attribute specifiers for the "random_shuffle" functions
	//[[deprecated("potentially uses c rand and friends which is discourged in modern C++")]]

	//old way of shuffling
	template< class Container >
	void random_shuffle(Container & c)
	{ return std::random_shuffle(c.begin(),c.end());}

	template< class Container, class RandomFunc >
	void random_shuffle(Container & c, RandomFunc& r )
	{ return std::random_shuffle(c.begin(),c.end(),r);}

	template< class Container, class RandomFunc >
	void random_shuffle(Container & c, RandomFunc&& r )
	{ return std::random_shuffle(c.begin(),c.end(),r);}

	//new way of shuffling
	template< class Container, class URNG >
	void shuffle(Container & c, URNG&& g )
	{ return std::shuffle(c.begin(),c.end(),g);}
	//---

	template< class Container>
	Container::iterator unique(Container & c)
	{return std::unique(c.begin(),c.end());}

	template< class Container, class BinaryPredicate >
	Container::iterator unique(Container & c, BinaryPredicate p )
	{return std::unique(c.begin(),c.end(),p);}

	template< class Container, class OutputIt >
	OutputIt unique_copy(Container & c, OutputIt d_first )
	{ return std::unique_copy(c.begin(),c.end(),d_first);}

	template< class Container, class OutputIt, class BinaryPredicate >
	OutputIt unique_copy(Container & c, OutputIt d_first, BinaryPredicate p )
	{ return std::unique_copy(c.begin(),c.end(),d_first,p);}

	template< class Container, class UnaryPredicate >
	bool is_partitioned(Container & c, UnaryPredicate p )
	{ return std::is_partitioned(c.begin(),c.end(),p);}

	//unfinished
	template< class BidirIt, class UnaryPredicate >
	BidirectionalIterator partition( BidirIt first, BidirIt last, UnaryPredicate p )
	{ return std::partition();}

	template< class ForwardIt, class UnaryPredicate >
	ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p )
	{ return std::partition();}

	template< class InputIt, class OutputIt1, class OutputIt2, class UnaryPredicate >
	std::pair<OutputIt1, OutputIt2> partition_copy( InputIt first, InputIt last, OutputIt1 d_first_true, OutputIt2 d_first_false, UnaryPredicate p )
	{ return std::partition_copy();}

	template< class BidirIt, class UnaryPredicate >
	BidirIt stable_partition( BidirIt first, BidirIt last, UnaryPredicate p )
	{ return std::stable_partition();}

	template< class ForwardIt, class UnaryPredicate >
	ForwardIt partition_point( ForwardIt first, ForwardIt last, UnaryPredicate p )
	{ return std::partition_point();}

	template< class ForwardIt >
	bool is_sorted( ForwardIt first, ForwardIt last )
	{ return std::is_sorted();}

	template< class ForwardIt, class Compare >
	bool is_sorted( ForwardIt first, ForwardIt last, Compare comp )
	{ return std::is_sorted();}

	template< class ForwardIt >
	ForwardIt is_sorted_until( ForwardIt first, ForwardIt last )
	{ return std::is_sorted_until();}

	template< class ForwardIt, class Compare >
	ForwardIt is_sorted_until( ForwardIt first, ForwardIt last, Compare comp )
	{ return std::is_sorted_until();}

	template< class RandomIt >
	void sort( RandomIt first, RandomIt last )
	{ return std::sort();}

	template< class RandomIt, class Compare >
	void sort( RandomIt first, RandomIt last, Compare comp )
	{ return std::sort();}

	template< class RandomIt >
	void partial_sort( RandomIt first, RandomIt middle, RandomIt last )
	{ return std::partial_sort();}

	template< class RandomIt, class Compare >
	void partial_sort( RandomIt first, RandomIt middle, RandomIt last, Compare comp )
	{ return std::partial_sort();}

	template< class InputIt, class RandomIt >
	RandomIt partial_sort_copy( InputIt first, InputIt last, RandomIt d_first, RandomIt d_last )
	{ return std::partial_sort_copy();}

	template< class InputIt, class RandomIt, class Compare >
	RandomIt partial_sort_copy( InputIt first, InputIt last, RandomIt d_first, RandomIt d_last, Compare comp )
	{ return std::partial_sort_copy();}

	template< class RandomIt >
	void stable_sort( RandomIt first, RandomIt last )
	{ return std::stable_sort();}

	template< class RandomIt, class Compare >
	void stable_sort( RandomIt first, RandomIt last, Compare comp )
	{ return std::stable_sort();}

	template< class RandomIt >
	void nth_element( RandomIt first, RandomIt nth, RandomIt last )
	{ return std::nth_element();}

	template< class RandomIt, class Compare >
	void nth_element( RandomIt first, RandomIt nth, RandomIt last, Compare comp )
	{ return std::nth_element();}

	template< class ForwardIt, class T >
	ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value )
	{ return std::lower_bound();}

	template< class ForwardIt, class T, class Compare >
	ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp )
	{ return std::lower_bound();}

	template< class ForwardIt, class T >
	ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value )
	{ return std::upper_bound();}

	template< class ForwardIt, class T, class Compare >
	ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp )
	{ return std::upper_bound();}

	template< class ForwardIt, class T >
	bool binary_search( ForwardIt first, ForwardIt last, const T& value )
	{ return std::binary_search();}

	template< class ForwardIt, class T, class Compare >
	bool binary_search( ForwardIt first, ForwardIt last, const T& value, Compare comp )
	{ return std::binary_search();}

	template< class ForwardIt, class T >
	std::pair<ForwardIt,ForwardIt> equal_range( ForwardIt first, ForwardIt last, const T& value )
	{ return std::equal_range();}

	template< class ForwardIt, class T, class Compare >
	std::pair<ForwardIt,ForwardIt> equal_range( ForwardIt first, ForwardIt last, const T& value, Compare comp )
	{ return std::equal_range();}

	template< class InputIt1, class InputIt2, class OutputIt >
	OutputIt merge( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first )
	{ return std::merge();}

	template< class InputIt1, class InputIt2, class OutputIt, class Compare>
	OutputIt merge( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first, Compare comp )
	{ return std::merge();}

	template< class BidirIt >
	void inplace_merge( BidirIt first, BidirIt middle, BidirIt last )
	{ return std::implace_merge();}

	template< class BidirIt, class Compare>
	void inplace_merge( BidirIt first, BidirIt middle, BidirIt last, Compare comp )
	{ return std::implace_merge();}

	template< class InputIt1, class InputIt2 >
	bool includes( InputIt1 first1, InputIt1 last1,InputIt2 first2, InputIt2 last2 )
	{ return std::includes();}

	template< class InputIt1, class InputIt2 >
	bool includes( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp )
	{ return std::includes();}

	template< class InputIt1, class InputIt2, class OutputIt >
	OutputIt set_difference( InputIt1 first1, InputIt1 last1,InputIt2 first2, InputIt2 last2,OutputIt d_first )
	{ return std::set_difference();}

	template< class InputIt1, class InputIt2, class OutputIt, class Compare >
	OutputIt set_difference( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first, Compare comp )
	{ return std::set_difference();}

	template< class InputIt1, class InputIt2, class OutputIt >
	OutputIt set_intersection( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first )
	{ return std::set_intersection();}

	template< class InputIt1, class InputIt2,class OutputIt, class Compare >
	OutputIt set_intersection( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2,OutputIt d_first, Compare comp )
	{return std::set_intersection();}

	template< class InputIt1, class InputIt2, class OutputIt >
	OutputIt set_symmetric_difference( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first )
	{return std::set_symmetric_difference();}

	template< class InputIt1, class InputIt2, class OutputIt, class Compare >
	OutputIt set_symmetric_difference( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first, Compare comp )
	{return std::set_symmetric_difference();}

	template< class InputIt1, class InputIt2, class OutputIt >
	OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first )
	{ return std::set_union();}

	template< class InputIt1, class InputIt2, class OutputIt, class Compare >
	OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2,OutputIt d_first, Compare comp )
	{return std::set_union();}

	template< class RandomIt >
	bool is_heap( RandomIt first, RandomIt last )
	{return std::is_heap();}

	template< class RandomIt, class Compare >
	bool is_heap( RandomIt first, RandomIt last, Compare comp )
	{return std::is_heap();}

	template< class RandomIt >
	RandomIt is_heap_until( RandomIt first, RandomIt last )
	{return std::is_heap_until();}

	template< class RandomIt, class Compare >
	RandomIt is_heap_until( RandomIt first, RandomIt last, Compare comp )
	{return std::is_heap_until();}

	template< class RandomIt >
	void make_heap( RandomIt first, RandomIt last )
	{return std::make_heap();}

	template< class RandomIt, class Compare >
	void make_heap( RandomIt first, RandomIt last,Compare comp )
	{return std::make_heap();}

        template< class RandomIt >
	void push_heap( RandomIt first, RandomIt last )
	{return std::push_heap();}

	template< class RandomIt, class Compare >
	void push_heap( RandomIt first, RandomIt last,Compare comp )
	{return std::push_heap();}

        template< class RandomIt >
	void pop_heap( RandomIt first, RandomIt last )
	{return std::pop_heap();}

	template< class RandomIt, class Compare >
	void pop_heap( RandomIt first, RandomIt last, Compare comp )
	{return std::pop_heap();}

	template< class RandomIt >
	void sort_heap( RandomIt first, RandomIt last )
	{return std::sort_heap();}

	template< class RandomIt, class Compare >
	void sort_heap( RandomIt first, RandomIt last, Compare comp )
	{return std::sort_heap();}

	//max

	template< class ForwardIt >
	ForwardIt max_element( ForwardIt first, ForwardIt last )
	{return std::max_element();}

	template< class ForwardIt, class Compare >
	ForwardIt max_element( ForwardIt first, ForwardIt last, Compare comp )
	{return std::max_element();}

	//min

	template< class ForwardIt >
	ForwardIt min_element( ForwardIt first, ForwardIt last )
	{return std::min_element();}

	template< class ForwardIt, class Compare >
	ForwardIt min_element( ForwardIt first, ForwardIt last, Compare comp )
	{return std::min_element();}

	//min-max

	template< class ForwardIt >
	std::pair<ForwardIt,ForwardIt> minmax_element( ForwardIt first, ForwardIt last )
	{return std::minmax_element();}

	template< class ForwardIt, class Compare >
	std::pair<ForwardIt,ForwardIt> minmax_element( ForwardIt first, ForwardIt last, Compare comp )
	{return std::minmax_element();}

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{ return std::lexicographical_compare();}

	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp )
	{ return std::lexicographical_compare();}

	template< class ForwardIt1, class ForwardIt2 >
	bool is_permutation( ForwardIt1 first1, ForwardIt1 last1,ForwardIt2 first2 )
	{ return std::is_permutation();}

	template< class ForwardIt1, class ForwardIt2, class BinaryPredicate >
	bool is_permutation( ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, BinaryPredicate p )
	{return std::is_permutation();}

	template< class ForwardIt1, class ForwardIt2 >
	bool is_permutation( ForwardIt1 first1, ForwardIt1 last1,ForwardIt2 first2, ForwardIt2 last2 )
	{return std::is_permutation();}

	template< class ForwardIt1, class ForwardIt2, class BinaryPredicate >
	bool is_permutation( ForwardIt1 first1, ForwardIt1 last2,ForwardIt2 first1, ForwardIt2 last2,BinaryPredicate p )
	{return std::is_permutation();}

        template< class BidirIt >
	bool next_permutation( BidirIt first, BidirIt last )
	{return std::next_permutation();}

	template< class BidirIt, class Compare >
	bool next_permutation( BidirIt first, BidirIt last, Compare comp )
	{return std::next_permutation();}

	template< class BidirIt >
	bool prev_permutation( BidirIt first, BidirIt last)
	{return std::prev_permutation();}

	template< class BidirIt, class Compare >
	bool prev_permutation( BidirIt first, BidirIt last, Compare comp)
	{return std::prev_permutation();}

	template< class ForwardIterator, class T >
	void iota( ForwardIterator first, ForwardIterator last, T value )
	{return std::iota();}

	template< class InputIt, class T >
	T accumulate( InputIt first, InputIt last, T init )
	{return std::accumulate();}

	template< class InputIt, class T, class BinaryOperation >
	T accumulate( InputIt first, InputIt last, T init,BinaryOperation op )
	{return std::accumulate();}

	template< class InputIt1, class InputIt2, class T >
	T inner_product( InputIt1 first1, InputIt1 last1, InputIt2 first2, T value )
	{return std::inner_product();}

	template<class InputIt1,class InputIt2,class T,class BinaryOperation1,class BinaryOperation2>
	T inner_product( InputIt1 first1, InputIt1 last1,InputIt2 first2, T value, BinaryOperation1 op1,BinaryOperation2 op2 )
	{return std::inner_product();}

	template< class InputIt, class OutputIt >
	OutputIt adjacent_difference( InputIt first, InputIt last, OutputIt d_first )
	{return std::adjacent_difference();}

	template< class InputIt, class OutputIt, class BinaryOperation >
	OutputIt adjacent_difference( InputIt first, InputIt last, OutputIt d_first,BinaryOperation op )
	{return std::adjacent_difference();}

	template< class InputIt, class OutputIt >
	OutputIt partial_sum( InputIt first, InputIt last, OutputIt d_first )
	{return std::partial_sum();}

	template< class InputIt, class OutputIt, class BinaryOperation >
	OutputIt partial_sum( InputIt first, InputIt last, OutputIt d_first, BinaryOperation op )
	{return std::partial_sum();}
*/
	//qsort
	//bsearch

}


