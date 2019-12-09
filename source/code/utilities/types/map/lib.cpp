#include "code/utilities/types/map/lib.hpp"

long Get_Value_Add_Zero_If_Missing(std::map<long,long> & m, long const& key){
    if (Exists_In_Map(m,key)){
        return m[key];
    }
    m[key] = 0;
    return m[key];
}
