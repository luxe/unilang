#pragma once
#include <vector>
#include <thread>
#include <mutex>

//concatenate vectors
template <typename T>
std::vector<T> operator+(std::vector<T> const& v1, std::vector<T> const& v2){
    std::vector<T> final(v1);
    final.insert(final.end(), v2.begin(), v2.end());
    return final;
}
template <typename T>
std::vector<T>& operator+=(std::vector<T> & v1, std::vector<T> const& v2){
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

template <typename T>
std::vector<T>& Append(std::vector<T> & v1, std::vector<T> const& v2){
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

template <typename T>
std::vector<T>& Thread_Safe_Append(std::vector<T> & v1, std::vector<T> const& v2, std::mutex & mutex){
    const std::lock_guard<std::mutex> lock(mutex);
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

