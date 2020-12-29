#include "code/utilities/graphics/imgui/loop/mechanics.hpp"
#include "code/utilities/graphics/imgui/ui_renders.hpp"
#include "code/tools/ide/settings/ide_settings.hpp"
#include "code/tools/ide/settings/ide_settings_getter.hpp"
#include "code/utilities/graphics/imgui/render/frame_renderer.hpp"
#include "code/tools/ide/frame/frame_logic_updater.hpp"
#include "code/utilities/data_structures/graphics/objects/frame_elements.hpp"
#include "code/utilities/peripheral/pc/pc_input_state_getter.hpp"
#include "code/tools/ide/global_actions/global_action_handler.hpp"
#include "code/tools/ide/program_options/program_options.hpp"


//other programming editors for inspiration:
// fructure (racket): https://github.com/disconcision/fructure
// lambdu: https://www.lamdu.org/
//https://en.wikipedia.org/wiki/DRAKON
//https://www.jetbrains.com/mps/

//similarity to other projects:
// Haxe
// OneLang
// Felleisen's A Programmable Programming Language
//http://andescotia.com/products/marten/
//https://divan.dev/posts/visual_programming_go/

//community:
//https://www.reddit.com/r/nosyntax/



//optional thread pool on drawing grid
//label button
//use it set growth bool
//maybe reorganize all draw things (functions with the objects / mouse under label)
int main(int argc, char** argv)
{
    
    Program_Options po(argc,argv);
    std::cout << po.File() << std::endl;
    
    //lambdas into main application loop
    auto s = Ide_Settings_Getter::Get();
    Frame_Elements elements;
    auto before = [&]()                  {};
    auto logic =  [&](SDL_Window* window) {
    
        elements = Frame_Logic_Updater::each_frame(s,window);
    
    };
    auto render = [&](SDL_Window* window) {
        
        Frame_Renderer::Render(s.desktop.background,elements);
        
        //this is handled here because for some reason blocking on an OS window during logic update causes a double key-press.  
        //so for example, ctrl+s to save will be triggered twice, and the window will pop up twice.  Maybe I should do something with futures/async,
        //but as far as I can tell, having this here instead of logic is the easiest fix.
        Global_Action_Handler::Handle(s, window);
        
       //bool flag = true;
       //ImGui::ShowDemoWindow(&flag);
	};
    
    return Mechanics::render_each_frame(s.desktop.init,before,logic,render);
}
