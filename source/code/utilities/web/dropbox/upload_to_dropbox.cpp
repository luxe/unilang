#include "code/utilities/web/dropbox/dropbox_uploader.hpp"
#include "code/utilities/secret/secret_getter.hpp"
#include "code/utilities/web/dropbox/dropbox_upload_settings.hpp"
#include <iostream>

int main(){
    
    Dropbox_Upload_Settings settings;
    settings.access_token = Secret_Getter::Unilang_Dropbox_Access_Key();
    settings.local_file_path = "/home/laptop/Desktop/tenor.gif";
    settings.docker_file_path = "yup.gif";
    settings.strategy = Upload_To_Dropbox_Strategy::CURL_LIB;
    Dropbox_Uploader::Upload(settings);
}
