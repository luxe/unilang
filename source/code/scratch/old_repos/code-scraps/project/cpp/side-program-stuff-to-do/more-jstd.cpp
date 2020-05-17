#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

//transform
std::string& Remove_All_Control_Characters(std::string & str);
std::string& Remove_All_Printable_Characters(std::string & str);
std::string& Remove_All_Space_Characters(std::string & str);
std::string& Remove_All_Blank_Characters(std::string & str);
std::string& Remove_All_Graphical_Characters(std::string & str);
std::string& Remove_All_Punctuation_Characters(std::string & str);
std::string& Remove_All_Alphanumeric_Characters(std::string & str);
std::string& Remove_All_Alpha_Characters(std::string & str);
std::string& Remove_All_Uppercase_Characters(std::string & str);
std::string& Remove_All_Lowercase_Characters(std::string & str);
std::string& Remove_All_Digit_Characters(std::string & str);
std::string& Remove_All_Hexidecimal_Characters(std::string & str);

//copies


//as removed...
std::string As_All_Control_Characters_Removed(std::string str);
std::string As_All_Printable_Characters_Removed(std::string str);
std::string As_All_Space_Characters_Removed(std::string str);
std::string As_All_Blank_Characters_Removed(std::string str);
std::string As_All_Graphical_Characters_Removed(std::string str);
std::string As_All_Punctuation_Characters_Removed(std::string str);
std::string As_All_Alphanumeric_Characters_Removed(std::string str);
std::string As_All_Alpha_Characters_Removed(std::string str);
std::string As_All_Uppercase_Characters_Removed(std::string str);
std::string As_All_Lowercase_Characters_Removed(std::string str);
std::string As_All_Digit_Characters_Removed(std::string str);
std::string As_All_Hexidecimal_Characters_Removed(std::string str);




int main(){

    std::string cleanString = "";
    std::string input = "hello world how are you";
    
    input.erase(std::remove_if(input.begin(), input.end(),
    std::ptr_fun<int, int>(std::isspace)), input.end());
    
    /*
    for ( int i=0; i <= input.length(); i++) {
        char cha = input[cha];

        // now, if there is punctuation or a space, then remove it
        if (ispunct(cha) || isspace(cha)) {
            //remove the punctuation or space
            input.erase(cha);
            // = cleanString;
        }
    }
    */
    
    std::cout << input << std::endl;
    std::cout << cleanString << std::endl;
    
    
}
