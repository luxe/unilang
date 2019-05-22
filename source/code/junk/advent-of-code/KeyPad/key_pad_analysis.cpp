#include "key_pad_analysis.hpp"






//creators
 std::vector<std::vector<int>> Key_Pad_Analysis::Create_Square() {
    return Create_A_Square_Vector(3,0);
}
 std::vector<std::vector<int>> Key_Pad_Analysis::Create_Diamond() {
    return Create_A_Square_Vector(5,0);
}
 std::pair<int,int> Key_Pad_Analysis::Create_Square_Start() {
    return {1,1};
}
 std::pair<int,int> Key_Pad_Analysis::Create_Diamond_Start() {
    return {0,2};
}