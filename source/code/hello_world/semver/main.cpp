#include "include/semver.hpp"

int main(){
    constexpr semver::version v1{1, 4, 3};
    constexpr semver::version v2{1, 2, 4, semver::prerelease::alpha, 10};
    static_assert(v1 != v2);
    static_assert(v1 > v2);
    static_assert(v1 >= v2);
    static_assert(v2 < v1);
    static_assert(v2 <= v1);
}