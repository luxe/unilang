#include "code/utilities/types/strings/observers/path/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include "code/utilities/types/general/lib.hpp"
#include <boost/range/adaptor/reversed.hpp> 

std::string Get_File_Extension(std::string const& str){
    std::string extension;

    for (auto const& it : boost::adaptors::reverse(str)){
        if (it == '.'){
            break;
        }else{
            extension=it+extension;
        }
    }

    return extension;
}
bool File_Has_Extension(std::string const& path_to_file, std::string const& file_extension){
	return Get_File_Extension(path_to_file) == file_extension;
}
bool File_Has_Extension(std::string const& path_to_file){
	return Contains(path_to_file,'.');
}

std::string Get_File_Name(std::string const& str){
    std::string filename;
    
    for (auto const& it : boost::adaptors::reverse(str)){
        if (it == '/'){
            break;
        }else{
            filename=it+filename;
        }
    }
    
    return filename;
}