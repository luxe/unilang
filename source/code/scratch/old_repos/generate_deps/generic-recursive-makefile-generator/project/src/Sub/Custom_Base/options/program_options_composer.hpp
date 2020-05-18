#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include "program_options.hpp"
#include "composed_program_options.hpp"

class Program_Options_Composer{






public: static Composed_Program_Options Compose(Program_Options const& program_options) ;
};