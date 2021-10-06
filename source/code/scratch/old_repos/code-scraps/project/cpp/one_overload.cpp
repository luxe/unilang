#include <cmath>
#include <functional>

template<typename R, typename ...A>
auto h(R f(A...)) -> std::function<R(A...)>
{
    return std::function<R(A...)>(f);
}


int only_one_overload(int a,  int b) {
	return a + b;
}

int main() {

	auto s = h<double, double>(std::sin);
	auto p = h<double, double, double>(std::pow);
	auto x = h(only_one_overload);

	//auto a = g(std::sin);

	//double (*s)(double) = std::sin;
	//double (*p)(double, double) = std::pow;
	//void (&h)() = bar::f;

	//g();
	//h();
}
