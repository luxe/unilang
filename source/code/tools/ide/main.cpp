#include "code/utilities/graphics/imgui/mechanics.hpp"
#include "code/utilities/graphics/imgui/ui_renders.hpp"
#include "code/tools/ide/settings/ide_settings.hpp"
#include "code/tools/ide/settings/ide_settings_getter.hpp"
#include "code/utilities/graphics/imgui/render/frame_renderer.hpp"
#include "code/tools/ide/frame/frame_logic_updater.hpp"
#include "code/utilities/data_structures/graphics/objects/frame_elements.hpp"
#include "code/utilities/graphics/imgui/render/frame_renderer.hpp"
#include "code/tools/ide/frame/fullscreener.hpp"


//other programming editors for inspiration:
// fructure (racket): https://github.com/disconcision/fructure
// lambdu: https://www.lamdu.org/
//https://en.wikipedia.org/wiki/DRAKON



//optional thread pool on drawing grid
//label button
//use it set growth bool
//maybe reorganize all draw things (functions with the objects / mouse under label)
int main()
{
    
    //lambdas into main application loop
    auto s = Ide_Settings_Getter::Get();
    Frame_Elements elements;
    auto before = [&]()                  {};
    auto logic =  [&]()                  {elements = Frame_Logic_Updater::each_frame(s);};
    auto render = [&](SDL_Window* window){
		Fullscreener::Possibly_Fullscreen(s,window);
        Frame_Renderer::Render(s.background,elements);
	};
    
    return Mechanics::render_each_frame(s.init,before,logic,render);
}
