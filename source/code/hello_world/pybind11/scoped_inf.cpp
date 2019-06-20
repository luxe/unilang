#include <pybind11/embed.h>

//https://github.com/pybind/pybind11/issues/1813
int main() {
    pybind11::scoped_interpreter guard{};
    while (true){
        //can't ctrl+C
    }
}