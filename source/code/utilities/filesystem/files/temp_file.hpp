#include <string>
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/files/deleting/lib.hpp"

// sometimes you need to temporarily store a string in a file
// so other tools can reference that file
// we use RAII to clean it up afterwards
class Temp_File {
    public:
    Temp_File(std::string const& path, std::string const& content){
        file_name = path;
        Write_To_File(file_name,content);
    }
    
    ~Temp_File(){
        Delete_File(file_name);
    }
    
    private:
        std::string file_name;
};