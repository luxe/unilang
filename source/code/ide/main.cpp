#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"

int main()
{

    Sdl_Init_Settings s;
    s.main_window.title = "Unilang IDE";
    
    auto before = [](){};
    auto during = [](){};
    return Mechanics::render_each_frame(s,before,during);
}
