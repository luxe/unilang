#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"
#include "code/utilities/graphics/imgui/ui/window/window_renderer.hpp"
#include "code/utilities/graphics/imgui/ui/draw/rectangle_settings.hpp"
#include "code/utilities/graphics/imgui/ui/draw/mouse_events.hpp"
#include "code/utilities/graphics/imgui/ui/draw/mouse_events_checker.hpp"
#include "code/utilities/graphics/imgui/ui/draw/position.hpp"
#include "code/utilities/graphics/imgui/ui/draw/rectangle_drawer.hpp"




struct ide_settings
{
    Sdl_Init_Settings init;
    Window_Settings method_item;
};

//other utilities
Position window_adjusted_position(Position pos)
{
    const ImVec2 screen_Position = ImGui::GetCursorScreenPos();
    Position     p;
    p.x = pos.x + screen_Position.x;
    p.y = pos.y + screen_Position.y;
    return p;
}

//pixel related
struct pixel_settings
{
    Position pos;
    Color color_fill;
};
struct full_color_bitmap_settings
{
    Color color_fill;
    std::vector<Position> pixels;
};



void each_frame(ide_settings & settings){
    
    Ui_Renders::render_main_menu_bar([](){
        if (ImGui::MenuItem("hello world", "T"))
        {
        }
    });
    
    // for testing
    bool show_demo_window = true;
    ImGui::ShowDemoWindow(&show_demo_window);
    
    
    Window_Renderer::render(settings.method_item,[&](){
        
        ImDrawList *draw_list = ImGui::GetWindowDrawList();
        
        Position temp;
        temp.x = 0;
        temp.y = 0;
        auto pos = window_adjusted_position(temp);
        
        Rectangle_Settings rec;
        rec.width     = 1;
        rec.height    = 1;
        rec.thickness = 1;
        rec.rounding  = 0.0;
        rec.color_border.r = 0;
        rec.color_border.g = 0;
        rec.color_border.b = 0;
        rec.color_fill.r = 50;
        rec.color_fill.g = 205;
        rec.color_fill.b = 50;
        
        Rectangle_Drawer::draw_rectangle(draw_list,pos,rec);
        
        /*
        ImGuiTreeNodeFlags flags = 0;
        if (ImGui::CollapsingHeader("Implementations", flags)){
            ImGui::Text("%s", "test");
        }
        if (ImGui::CollapsingHeader("Unit Tests", flags)){
            ImGui::Text("%s", "test");
        }
        if (ImGui::CollapsingHeader("Benchmarks", flags)){
            ImGui::Text("%s", "test");
        }
        */
    });
}


ide_settings get_ide_settings(){
    
    ide_settings settings;
    
    settings.init.main_window.title = "Unilang IDE";
    
    settings.method_item.title              = "Function";
    settings.method_item.menu.title         = "Settings";
    settings.method_item.menu.shortcut      = "CTRL+F";
    settings.method_item.position.x         = 20;
    settings.method_item.position.y         = 38;
    settings.method_item.position.condition = ImGuiCond_Once;
    settings.method_item.size.width         = 800;
    settings.method_item.size.height        = 410;
    settings.method_item.size.condition     = ImGuiCond_Once;
    settings.method_item.titlebar           = false;
    settings.method_item.scrollbar          = true;
    settings.method_item.has_menu           = false;
    settings.method_item.move               = true;
    settings.method_item.resize             = true;
    settings.method_item.collapse           = true;
    settings.method_item.nav                = false;
    settings.method_item.close              = true;
    settings.method_item.is_open            = false;
    settings.method_item.focus              = false;
    settings.method_item.refocus_on_use     = false;
    settings.method_item.bg_alpha           = 1;
    
    return settings;
}


int main()
{
    auto s = get_ide_settings();
    
    auto before = [&](){
        
        //Initial Imgui styling
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowBorderSize = 0;
        style.WindowRounding = 0;
        
    };
    return Mechanics::render_each_frame(s.init,before,[&](){
        each_frame(s);
    });
}
