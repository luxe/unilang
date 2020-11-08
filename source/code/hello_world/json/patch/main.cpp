#include <iostream>
#include "nlohmann/json.hpp"
#include "code/utilities/formats/json/patching/json_patch_builder.hpp"




int main(){
    
    nlohmann::json patches;
    Json_Patch_Builder::Add_Test_Patch(patches,"/a/b/c","foo");
    Json_Patch_Builder::Add_Remove_Patch(patches,"/a/b/c");
    Json_Patch_Builder::Add_Add_Patch(patches,"/a/b/c",std::vector<std::string>{"foo", "bar"});
    Json_Patch_Builder::Add_Replace_Patch(patches,"/a/b/c",42);
    Json_Patch_Builder::Add_Move_Patch(patches,"/a/b/c","/a/b/d");
    Json_Patch_Builder::Add_Copy_Patch(patches,"/a/b/d","/a/b/e");
    
    std::cout << patches.dump(2) << std::endl;
}