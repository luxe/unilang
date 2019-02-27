#include "imgui.h"
#include "imgui_internal.h"
#include "examples/imgui_impl_sdl.h"
#include "examples/imgui_impl_opengl3.h"
#include <GL/gl3w.h>
#include "SDL.h"
#include <cstdlib>
#include <iostream>
#include "code/utilities/graphics/imgui/mechanics.hpp"

bool user_asked_to_quit(SDL_Window *window, SDL_Event event)
{
    if (event.type == SDL_QUIT)
    {
        return true;
    }
    if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
        && event.window.windowID == SDL_GetWindowID(window))
    {
        return true;
    }
    return false;
}

bool poll_for_events(SDL_Window *window)
{
    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your
    // inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those
    // two flags.
    SDL_Event event;
    bool      done = false;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);
        done = user_asked_to_quit(window, event);
    }
    return done;
}

void render_frame(SDL_Window *window, SDL_GLContext &gl_context, ImGuiIO &io, ImVec4 &clear_color)
{
    // Rendering
    ImGui::Render();
    SDL_GL_MakeCurrent(window, gl_context);
    glViewport(0, 0, (int) io.DisplaySize.x, (int) io.DisplaySize.y);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

void clean_up_resources(SDL_GLContext &gl_context, SDL_Window *window)
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

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
    while (!poll_for_events(window))
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        render_frame(window, gl_context, io, clear_color);
    }

    clean_up_resources(gl_context, window);
    return EXIT_SUCCESS;
}
