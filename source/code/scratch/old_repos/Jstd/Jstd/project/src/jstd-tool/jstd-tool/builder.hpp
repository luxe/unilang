#pragma once
#include "program_options.hpp"
#include "build_stats.hpp"
#include <boost/filesystem.hpp>
#include <vector>
#include <string>

//3rd Party
#include <gmpxx.h>

class Builder{

public:
	static void Build_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time);
private:

static void Perform_Timed_Builds(Program_Options const& program_options, std::time_t const& last_run_time);
static void Perform_Builds(Program_Options const& program_options, Build_Stats & stats);
static void Start_The_Builds(Program_Options const& program_options, boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
static void Build_Pre_Compiled_Header(boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
static void Remove_Pragma_Once_To_Avoid_Warning(std::string const& file);
static void Re_Add_Pragma_Once(std::string const& file);
static void Build_Header_That_Is_Looked_For_But_Doesnt_Need_Included_In_Code_But_Needs_To_Be_Specified_In_Command_Line(std::string const& file_name);
static void Build_Header_Only_File(boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
static void Build_Libraries(Program_Options const& program_options, boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats);
static std::string Get_Directory_Of_File(std::string const& path);
static std::string Get_Just_File_Name(std::string const& path);
static std::string Convert_To_Suitable_File_Name(std::string str,boost::filesystem::path const& built_library);
};
