#include "code/utilities/formats/encryption/SHA1/lib.hpp"
#include <iostream>
int main(){
    
    std::cout << sha1("ilovepittsburgh") << std::endl;
    exit(0);
    
    
    
    
    for (char i = 0; i < 127; ++i){
    for (char i1 = 0; i1 < 127; ++i1){
    for (char i2 = 0; i2 < 127; ++i2){
    for (char i3 = 0; i3 < 127; ++i3){
    for (char i4 = 0; i4 < 127; ++i4){
    for (char i5 = 0; i5 < 127; ++i5){
    for (char i6 = 0; i6 < 127; ++i6){
    for (char i7 = 0; i7 < 127; ++i7){
    for (char i8 = 0; i8 < 127; ++i8){
    for (char i9 = 0; i9 < 127; ++i9){
            
        std::string str = "ilove";
        str += (char)i;
        str += (char)i1;
        str += (char)i2;
        str += (char)i3;
        str += (char)i4;
        str += (char)i5;
        str += (char)i6;
        str += (char)i7;
        str += (char)i8;
        str += (char)i9;
        if (sha1(str) == "9d722e1cc349443fc0898b56782e6cd61cc9b2bc"){
            std::cout << str << std::endl;
        }
    }}}}}}}}}}
    
}