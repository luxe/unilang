#include <sqlitelib.h>
#include "code/utilities/filesystem/paths/lib.hpp"

int main(){
    using namespace sqlitelib;
    auto db = Sqlite(Full_Path_For_Tmp_File("test.db").c_str());
}