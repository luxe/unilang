#include <iostream>
#include "code/utilities/system/mime/mime_xml_creator.hpp"
#include "code/utilities/system/mime/mime_xml_creation_settings.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"

int main(){
    
    //https://askubuntu.com/questions/747467/create-new-filetype-with-existing-extension
    
    Mime_Xml_Creation_Settings settings;
    settings.mime_type = "application/unilang";
    settings.comment = "unilang file";
    settings.file_extension = "unilang";
    
    auto xml_contents = Mime_Xml_Creator::Create(settings);
    
    auto file_name = Full_Path_To_Home_File(".local/share/mime/packages/application-unilang.xml");
    Create_File_Even_If_The_Path_Doesnt_Exist(file_name);
    Write_To_File(file_name,xml_contents);
    
    execute("update-mime-database ~/.local/share/mime");
}