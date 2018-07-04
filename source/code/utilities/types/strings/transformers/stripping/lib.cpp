#include "code/utilities/types/strings/transformers/stripping/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/char/lib.hpp"
#include <algorithm>

//stripping
   std::string Strip_Out_Data_Between_First_Set_Of_Double_Quotes(std::string const& str){
           std::string return_str;
           int count = 0;
           for (auto const& it: str){
                   if (count == 1){
                           if (it != '"'){
                                return_str +=it;
                           }
                   }else if(count == 2){
                           break;
                   }
                   
                   if (it == '"'){++count;}
           }
           
           return return_str;
   }
   std::string Strip_Out_Data_Between_First_Set_Of_Single_Quotes(std::string const& str){
           std::string return_str;
           int count = 0;
           for (auto const& it: str){
                   if (count == 1){
                           if (it != '\''){
                                return_str +=it;
                           }
                   }else if(count == 2){
                           break;
                   }
                   
                   if (it == '\''){++count;}
           }
           
           return return_str;
   }
std::string Strip_Out_Data_Between_First_Set_Of_Square_Brackets(std::string & str){
        std::string new_str;
        std::string brackets;
        
        bool in_brackets = false;
        for (auto it: str){
                if (it == '['){
                        in_brackets = true;
                        brackets += it;
                }
                else if(it == ']'){
                        if (in_brackets){
                                in_brackets = false;
                                brackets += it;
                        }
                        else{
                                new_str += it;
                        }
                }
                else{
                        if (in_brackets){
                          brackets += it;
                        }
                        else{
                          new_str += it;
                        }
                }
        }
        
        str = new_str;
        return brackets;
}



std::string Strip_Out_From_End_Until_Char_Is_Found(std::string const& str, char const& c){
        std::string return_str;
        for (auto it=str.rbegin(); it!=str.rend(); ++it){
                if (*it == c){
                        break;
                }else{
                        return_str = *it + return_str;
                }
        }
        return return_str;
}
std::string Strip_Out_From_Front_Until_Char_Is_Found(std::string const& str, char const& c){
        std::string return_str;
        for (auto it=str.begin(); it!=str.end(); ++it){
                if (*it == c){
                        break;
                }else{
                        return_str += *it;
                }
        }
        return return_str;
}

std::string Strip_Out_From_Front_Until_Number_Is_Found(std::string const& str){
        std::string return_str;
        for (auto it=str.begin(); it!=str.end(); ++it){
                if (Is_A_Numeric_Character(*it)){
                        break;
                }else{
                        return_str += *it;
                }
        }
        return return_str;
}
std::string Strip_Out_All_Numbers(std::string const& str){
        std::string return_str;
        for (auto it=str.begin(); it!=str.end(); ++it){
                if (Is_A_Numeric_Character(*it)){
                        return_str += *it;
                }
        }
        return return_str;
}

std::string Get_File_Name_From_File_Path(std::string const& file_path){
        return Strip_Out_From_End_Until_Char_Is_Found(file_path,'/');
}
std::string Get_File_Path_Without_The_Filename(std::string file_path){
        auto file_name = Get_File_Name_From_File_Path(file_path);
        Remove_Last_N_Chars(file_path,file_name.size());
        return file_path;
}
