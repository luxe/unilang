#include <tbb/cache_aligned_allocator.h>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int, tbb::cache_aligned_allocator<int>> v;
    v.resize(1000);
    std::iota(v.begin(), v.end(), 0);
    std::cout << v[500] << "\n";
}
