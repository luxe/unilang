#include <algorithm>
#include <utility>

template <typename A, typename B>
void test2(A a, B b){
    return;
}
template <typename Function>
void test(Function function){
  return;
}

struct Sum {
    Sum() { sum = 0; }
    void operator()(int n) { sum += n; }
 
    int sum;
};

int main(){
    std::vector<int> i;
    test(std::for_each<decltype(i)::iterator,std::equal_to<int>>);
}
