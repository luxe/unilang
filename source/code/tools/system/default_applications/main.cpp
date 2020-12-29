#include <iostream>
#include "code/utilities/system/mime/mime_xml_creator.hpp"
#include "code/utilities/system/mime/mime_xml_creation_settings.hpp"

int main(){
    
    Mime_Xml_Creation_Settings settings;
    settings.mime_type = "application/unilang";
    settings.comment = "unilang file";
    settings.file_extension = "unilang";
    
    std::cout << Mime_Xml_Creator::Create(settings);
}