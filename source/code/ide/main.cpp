#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/sdl_init_settings.hpp"
#include "code/utilities/graphics/imgui/ui/ui_renders.hpp"
#include "code/ide/settings/ide_settings.hpp"
#include "code/ide/settings/ide_settings_getter.hpp"
#include "code/ide/frame/frame_renderer.hpp"
#include "code/ide/frame/frame_logic_updater.hpp"


//other programming editors for inspiration:
// fructure (racket): https://github.com/disconcision/fructure
// lambdu: https://www.lamdu.org/

int main()
{
    
    //lambdas into main application loop
    auto s = Ide_Settings_Getter::Get();
    auto before = [&]()                  {};
    auto logic =  [&]()                  {Frame_Logic_Updater::each_frame(s);};
    auto render = [&](SDL_Window* window){Frame_Renderer::each_frame(s,window);};
    
    return Mechanics::render_each_frame(s.init,before,logic,render);
}
