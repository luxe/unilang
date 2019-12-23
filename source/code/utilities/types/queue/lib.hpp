#pragma once
#include <queue>

template <typename T>
T Pop_Front(std::queue<T> & q){
    T x = q.front();
    q.pop();
    return x;
}