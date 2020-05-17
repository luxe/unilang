
template<int B, int N>
struct Pow {
    // recursive call and recombination.
    enum{ value = B*Pow<B, N-1>::value };
};
 
template< int B >
struct Pow<B, 0> {
    // ''N == 0'' condition of termination.
    enum{ value = 1 };
};

constexpr int pow(int B, int N){
	return (N == 0) ? 0 : B*pow(B,N-1);
}
