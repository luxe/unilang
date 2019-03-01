#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"
#include "code/utilities/graphics/imgui/ui/window/window_renderer.hpp"

void each_frame(Window_Settings & f){
    
    Ui_Renders::render_main_menu_bar([](){
        if (ImGui::MenuItem("hello world", "T"))
        {
        }
    });
    
    // for testing
    bool show_demo_window = true;
    ImGui::ShowDemoWindow(&show_demo_window);
    
    Window_Renderer::render(f,[&](){
        
    });
    
    
    
}
int main()
{

    Sdl_Init_Settings s;
    s.main_window.title = "Unilang IDE";
    Window_Settings f;
    
    f.title              = "Function";
    f.menu.title         = "Settings";
    f.menu.shortcut      = "CTRL+F";
    f.position.x         = 20;
    f.position.y         = 38;
    f.position.condition = ImGuiCond_Once;
    f.size.width         = 800;
    f.size.height        = 410;
    f.size.condition     = ImGuiCond_Once;
    f.titlebar           = false;
    f.scrollbar          = true;
    f.has_menu           = false;
    f.move               = true;
    f.resize             = true;
    f.collapse           = true;
    f.nav                = false;
    f.close              = true;
    f.is_open            = false;
    f.focus              = false;
    f.refocus_on_use     = false;
    f.bg_alpha           = 1;
    
    auto before = [](){};
    return Mechanics::render_each_frame(s,before,[&](){
        each_frame(f);
    });
}
