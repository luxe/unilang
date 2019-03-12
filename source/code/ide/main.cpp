#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"
#include "code/utilities/graphics/imgui/ui/window/window_renderer.hpp"
#include "code/utilities/graphics/imgui/ui/draw/rectangle/rectangle_settings.hpp"
#include "code/utilities/graphics/imgui/ui/draw/mouse_events/mouse_events.hpp"
#include "code/utilities/graphics/imgui/ui/draw/mouse_events/mouse_events_checker.hpp"
#include "code/utilities/graphics/imgui/ui/draw/position.hpp"
#include "code/utilities/graphics/imgui/ui/draw/rectangle/rectangle_drawer.hpp"
#include "code/utilities/graphics/imgui/ui/draw/pixel/pixel_settings.hpp"
#include "code/utilities/graphics/imgui/ui/draw/pixel/pixel_drawer.hpp"
#include "code/utilities/graphics/imgui/ui/draw/full_color_bitmap/full_color_bitmap_drawer.hpp"
#include "code/utilities/graphics/imgui/ui/draw/text/text_to_bitmap.hpp"
#include "code/utilities/graphics/imgui/ui/draw/label/label_settings.hpp"
#include "code/utilities/graphics/imgui/ui/draw/imgui_type_utility.hpp"
#include "code/transcompilers/unilang/tokens/get_tokens.hpp"
#include "code/transcompilers/unilang/language-and-theme-creator/font/unilang_font.hpp"
#include "code/utilities/types/char/lib.hpp"

struct ide_settings
{
    Sdl_Init_Settings init;
    All_Language_Tokens tokens;
    std::vector<Character_Segment> unilang_font;
    std::unordered_map<int,Character_Segment> unilang_font_lookup;
    Window_Settings method_item;
    
    Label_Settings test_label;
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

Position window_adjusted_position_top_left_corner()
{
    Position temp;
    temp.x = 0;
    temp.y = 0;
    auto pos = window_adjusted_position(temp);
    return pos;
}


void draw_structured_label(){
}


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
        
        auto pos = window_adjusted_position_top_left_corner();
        pos.x += 10;
        pos.y += 10;
        
        auto bitmap = Text_To_Bitmap::Convert(settings.unilang_font_lookup,settings.test_label.message);
        
        //some pixel guessing
        const auto EXPECTED_MONOSPACE_CHAR_WIDTH = 6;
        const auto EXPECTED_MONOSPACE_FITTING_HEIGHT = 15;
        const auto SOME_BUFFER_SPACE = 3;

        settings.test_label.box_regular.width     = (settings.test_label.message.size() * EXPECTED_MONOSPACE_CHAR_WIDTH) + SOME_BUFFER_SPACE;
        settings.test_label.box_regular.height    = EXPECTED_MONOSPACE_FITTING_HEIGHT;
        
        settings.test_label.box_highlighted.width     = (settings.test_label.message.size() * EXPECTED_MONOSPACE_CHAR_WIDTH) + SOME_BUFFER_SPACE;
        settings.test_label.box_highlighted.height    = EXPECTED_MONOSPACE_FITTING_HEIGHT;
        
        
        
        
        
        pos.y -= 10;
        pos.x -= 2;
        
        auto events = Mouse_Events_Checker::search_for_mouse_events_in_rectangle(pos,settings.test_label.box_regular);
        if (events.hovered){
            settings.test_label.is_hovered = true;
            bitmap.color_fill = settings.test_label.text_highlighted;
        }
        else{
            settings.test_label.is_hovered = false;
            bitmap.color_fill = settings.test_label.text_regular;
        }
        
        if (settings.test_label.is_hovered){
            Rectangle_Drawer::draw_rectangle(draw_list,pos,settings.test_label.box_highlighted);
        }else{
            Rectangle_Drawer::draw_rectangle(draw_list,pos,settings.test_label.box_regular);
        }
        pos.y += 10;
        pos.x += 2;
        Full_Color_Bitmap_Drawer::Draw(draw_list,pos,bitmap);
        
        
        
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
    settings.init.main_window.maximized = false;
    
    settings.tokens = Get_Tokens::Get();
    settings.unilang_font = Unilang_Font::Get();
    
    for (auto const& it: settings.unilang_font){
        settings.unilang_font_lookup[static_cast<int>(it.glyph_index)] = it;
    }
    
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
    
    
    settings.test_label.message = "abcdefghijklmnopqrstuvwxyz(){}[]!@#$%^&*1234567890-iiiijijijijijijijij";
    
    settings.test_label.box_regular.thickness = 1;
    settings.test_label.box_regular.rounding  = 0.0;
    settings.test_label.box_regular.color_border = Imgui_Type_Utility::Black();
    settings.test_label.box_regular.color_fill = Imgui_Type_Utility::White();
    
    settings.test_label.box_highlighted.thickness = 1;
    settings.test_label.box_highlighted.rounding  = 0.0;
    settings.test_label.box_highlighted.color_border = Imgui_Type_Utility::Black();
    settings.test_label.box_highlighted.color_fill = Imgui_Type_Utility::Black();
        

    settings.test_label.text_regular = Imgui_Type_Utility::Black();
    settings.test_label.text_highlighted = Imgui_Type_Utility::White();
    
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
