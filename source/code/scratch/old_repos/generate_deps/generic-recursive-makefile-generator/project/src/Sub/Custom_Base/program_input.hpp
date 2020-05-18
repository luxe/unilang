#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "root_settings.hpp"
#include "composed_program_options.hpp"

class Program_Input{








public: Program_Input(Root_Settings const& settings, Composed_Program_Options const& options);
             
public:
    Root_Settings settings;
    Composed_Program_Options options;
};