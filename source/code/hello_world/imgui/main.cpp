#include "imgui.h"
#include "imgui_internal.h"
#include "examples/imgui_impl_sdl.h"
#include "examples/imgui_impl_opengl3.h"
#include <GL/gl3w.h>
#include "SDL.h"
#include <cstdlib>
#include <iostream>

void setup_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
    {
        std::cerr << "We weren't able to initialize SDL.\n";
        std::cerr << "Something is incompatible with your display.\n";
        std::cerr << "Here is the SDL error:\n";
        std::cerr << SDL_GetError() << '\n';
        exit(EXIT_FAILURE);
    }
}

std::string decide_sdl_glsl_version()
{
    std::string version;

#if __APPLE__
    // GL 3.2 Core + GLSL 150
    version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    // GL 3.0 + GLSL 130
    version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    return version;
}

SDL_Window *create_main_window(std::string const &window_name)
{
    // Setup window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    SDL_Window *window = SDL_CreateWindow(window_name.c_str(),
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1280,
                                          720,
                                          SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    return window;
}

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
    setup_sdl();
    auto          glsl_version = decide_sdl_glsl_version();
    auto          window       = create_main_window("hello world");
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
