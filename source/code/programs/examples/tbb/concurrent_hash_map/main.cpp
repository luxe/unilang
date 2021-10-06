#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fmt/format.h>
#include <tbb/concurrent_hash_map.h> // For concurrent hash map.

int main(){
    
    using namespace std;

    tbb::concurrent_hash_map<int, string> dict;
    typedef tbb::concurrent_hash_map<int, string>::accessor dictAccessor; // See notes on accessor below.   

    fmt::print("  - Insert key, method 1:\n");   
    dict.insert({1,"k1"});
    fmt::print("    - 1: k1\n");

    fmt::print("  - Insert key, method 2:\n");
    dict.emplace(2,"k2");
    fmt::print("    - 2: k2\n");

    string result;

    {
        fmt::print("  - Read an existing key:\n");   
        dictAccessor accessor;
        const auto isFound = dict.find(accessor, 2);
        // The accessor functions as:
        // (a) a fine-grained per-key lock (released when it goes out of scope).
        // (b) a method to read the value.
        // (c) a method to insert or update the value.
        if (isFound == true) {
            fmt::print("    - {}: {}\n", accessor->first, accessor->second);
        }
    }

    {
        fmt::print("  - Atomically insert or update a key:\n");  
        dictAccessor accessor;
        const auto itemIsNew = dict.insert(accessor, 4);
        // The accessor functions as:
        // (a) a fine-grained per-key lock (released when it goes out of scope).
        // (b) a method to read the value.
        // (c) a method to insert or update the value.
        if (itemIsNew == true) {
            fmt::print("    - Insert.\n");
            accessor->second = "k4";
        }
        else {
            fmt::print("    - Update.\n");
            accessor->second = accessor->second + "+update";
        }
        fmt::print("    - {}: {}\n", accessor->first, accessor->second);     
    }

    {
        fmt::print("  - Atomically insert or update a key:\n");          
        dictAccessor accessor;
        const auto itemIsNew = dict.insert(accessor, 4);
        // The accessor functions as:
        // (a) a fine-grained per-key lock which is released when it goes out of scope.
        // (b) a method to read the value.
        // (c) a method to insert or update the value.
        if (itemIsNew == true) {
            fmt::print("    - Insert.\n");
            accessor->second = "k4";
        }
        else {
            fmt::print("    - Update.\n");
            accessor->second = accessor->second + "+update";
        }
        fmt::print("    - {}: {}\n", accessor->first, accessor->second);     
    }

    {
        fmt::print("  - Read the final state of the key:\n");            
        dictAccessor accessor;
        const auto isFound = dict.find(accessor, 4);
        fmt::print("    - {}: {}\n", accessor->first, accessor->second);
    }
    
}