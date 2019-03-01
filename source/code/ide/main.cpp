#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"

void during_func(){
    
    Ui_Renders::render_main_menu_bar([](){
        if (ImGui::MenuItem("hello world", "T"))
        {
        }
    });
    
    // for testing
    bool show_demo_window = true;
    ImGui::ShowDemoWindow(&show_demo_window);
    
    
    
}
int main()
{

    Sdl_Init_Settings s;
    s.main_window.title = "Unilang IDE";
    
    auto before = [](){};
    auto during = during_func;
    return Mechanics::render_each_frame(s,before,during);
}
