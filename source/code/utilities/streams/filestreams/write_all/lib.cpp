#include "code/utilities/streams/filestreams/write_all/lib.hpp"

void Write_Each_Line_Of_Vector_Into_File(std::string const& file, std::vector<std::string> const& vec){
    std::ofstream out(file);
    for (auto const& it: vec){
        out << it << '\n';
    }
    out.close();
}
void Write_Byte_Vec_To_Binary_File(std::string const& file, std::vector<std::uint8_t> const& vec){
    std::ofstream output_file(file, std::ios::out | std::ios::binary);
    output_file.write(reinterpret_cast<const char*>(vec.data()), vec.size());
}