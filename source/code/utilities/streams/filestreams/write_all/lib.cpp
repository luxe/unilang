#include "code/utilities/streams/filestreams/write_all/lib.hpp"

void Write_Each_Line_Of_Vector_Into_File(std::string const& file, std::vector<std::string> const& vec){
    std::ofstream out(file);
    for (auto const& it: vec){
        out << it << '\n';
    }
    out.close();
}