#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>
#include <iomanip>

int main() {
    pybind11::scoped_interpreter guard{}; // start the interpreter and keep it alive


    pybind11::exec("import random");
    pybind11::exec("import time");
    pybind11::exec("import math");
    pybind11::exec("import numpy");
    
    
    //pybind11::exec("nextafter(100.0, inf)");
    
    pybind11::exec("random.seed()");
    pybind11::exec("bits = random.getrandbits(256)");
    pybind11::exec("bits_hex = hex(bits)");
    pybind11::exec("private_key = bits_hex[2:]");
    std::cout << std::setprecision (18) << pybind11::eval("time.time()").cast<double>() << std::endl;
    auto parsed = pybind11::eval("private_key").cast<std::string>();
    std::cout << parsed << std::endl;
}