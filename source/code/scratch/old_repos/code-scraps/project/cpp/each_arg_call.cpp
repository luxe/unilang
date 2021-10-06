#include <iostream>
#include <string>

template <class F, class... Args>
void for_each_arg(F f, Args&&... args)
{
    [](...){}((f(std::forward<Args>(args)), 0)...);
}

int main()
{
    for_each_arg(printf, "!\n", " World", "Hello");
}
