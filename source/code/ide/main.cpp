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
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        
        
        // io.KeyMap[ImGuiKey_Tab] = SDLK_TAB;                 // Keyboard mapping. ImGui will use those indices to peek into the io.KeyDown[] array.
        // io.KeyMap[ImGuiKey_LeftArrow] = SDL_SCANCODE_LEFT;
        // io.KeyMap[ImGuiKey_RightArrow] = SDL_SCANCODE_RIGHT;
        // io.KeyMap[ImGuiKey_UpArrow] = SDL_SCANCODE_UP;
        // io.KeyMap[ImGuiKey_DownArrow] = SDL_SCANCODE_DOWN;
        // io.KeyMap[ImGuiKey_Home] = SDL_SCANCODE_HOME;
        // io.KeyMap[ImGuiKey_End] = SDL_SCANCODE_END;
        // io.KeyMap[ImGuiKey_Delete] = SDLK_DELETE;
        // io.KeyMap[ImGuiKey_Backspace] = SDLK_BACKSPACE;
        // io.KeyMap[ImGuiKey_Enter] = SDLK_RETURN;
        // io.KeyMap[ImGuiKey_Escape] = SDLK_ESCAPE;
        //io.KeyMap[ImGuiKey_A] = SDLK_a;
        // io.KeyMap[ImGuiKey_C] = SDLK_c;
        // io.KeyMap[ImGuiKey_V] = SDLK_v;
        // io.KeyMap[ImGuiKey_X] = SDLK_x;
        // io.KeyMap[ImGuiKey_Y] = SDLK_y;
        // io.KeyMap[ImGuiKey_Z] = SDLK_z;
        
        
        //io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
        
        ImGui::SetMouseCursor(ImGuiMouseCursor_None); //put inside main loop
    
    };
    return Mechanics::render_each_frame(s.init,before,[&](SDL_Window* window){
        Frame_Renderer::each_frame(s,window);
    });
}
