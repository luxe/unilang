#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"
#include "code/ide/settings/ide_settings.hpp"
#include "code/ide/settings/ide_settings_getter.hpp"
#include "code/ide/frame/frame_renderer.hpp"


int main()
{
    auto s = Ide_Settings_Getter::Get();
    auto before = [&](){};
    
    return Mechanics::render_each_frame(s.init,before,[&](SDL_Window* window){
        Frame_Renderer::each_frame(s,window);
    });
}
