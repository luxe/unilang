#include <iostream>
#include "code/utilities/system/mime/mime_xml_creator.hpp"
#include "code/utilities/system/mime/mime_xml_creation_settings.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"

void Create_Mime_Xml(){

    //create mime xml
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

void Create_Desktop_File(){

    //create desktop file
    std::string x;
    x += "[Desktop Entry]\n";
    x += "Name=Unilang\n";
    x += "Exec=gedit\n";
    x += "MimeType=application/unilang\n";
    x += "Terminal=false\n";
    x += "Type=Application\n";
    
    auto file_name = Full_Path_To_Home_File(".local/share/applications/unilang.desktop");
    Create_File_Even_If_The_Path_Doesnt_Exist(file_name);
    Write_To_File(file_name,x);
    
    execute("update-desktop-database ~/.local/share/applications");
}


int main(){
    
    //https://askubuntu.com/questions/747467/create-new-filetype-with-existing-extension
    
    Create_Mime_Xml();
    Create_Desktop_File();
}