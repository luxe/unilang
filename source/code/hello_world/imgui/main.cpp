#include "imgui.h"
#include "imgui_internal.h"
#include "examples/imgui_impl_sdl.h"
//#include "examples/imgui_impl_opengl3.h"
#include <GL/gl3w.h>
#include "SDL.h"
#include <cstdlib>
#include <iostream>
#include "code/utilities/graphics/imgui/mechanics.hpp"

int main()
{

    // set up GL and SDL
    Mechanics::setup_sdl();
    auto          glsl_version = Mechanics::decide_sdl_glsl_version();
    auto          window       = Mechanics::create_main_window("hello world");
    SDL_GLContext gl_context   = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1); // Enable vsync
    gl3wInit();

    // Setup Dear ImGui binding
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version.c_str());

    // clear frame color
    //(not sure if this is important)
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // customize imgui overall look
    // (maybe move to overall settings)
    ImGui::StyleColorsLight();
    ImGuiStyle &style      = ImGui::GetStyle();
    style.FrameBorderSize  = 1;
    style.PopupBorderSize  = 1;
    style.WindowBorderSize = 1;

    // render each frame until we decide to exit
    while (!Mechanics::poll_for_events(window))
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        Mechanics::render_frame(window, gl_context, io, clear_color);
    }

    Mechanics::clean_up_resources(gl_context, window);
    return EXIT_SUCCESS;
}
