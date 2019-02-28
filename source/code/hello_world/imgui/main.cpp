#include "code/utilities/graphics/imgui/mechanics.hpp"

int main()
{

    auto before = [](){};
    auto during = [](){};
    return Mechanics::render_each_frame("hello world",before,during);
}
