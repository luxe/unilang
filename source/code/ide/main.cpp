#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"
#include "code/ide/settings/ide_settings.hpp"
#include "code/ide/settings/ide_settings_getter.hpp"
#include "code/ide/frame/frame_renderer.hpp"


int main()
{
    auto s = Ide_Settings_Getter::Get();
    auto before = [&](){
        
        //Initial Imgui styling
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowBorderSize = 0;
        style.WindowRounding = 0;
        
        //Initial ImGui Mouse settings
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDrawCursor = true;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        
        ImGui::SetMouseCursor(ImGuiMouseCursor_None); 
    
    };
    return Mechanics::render_each_frame(s.init,before,[&](SDL_Window* window){
        Frame_Renderer::each_frame(s,window);
    });
}
