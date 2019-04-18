#include <iostream>
#include <string>
#include "code/bazel_refresh/bazel_refresher.hpp"
#include "code/utilities/locale/lib.hpp"


int main(int argc, char** argv){
    Set_English_UTF8_Locale();
    Bazel_Refresher::Refresh();
}