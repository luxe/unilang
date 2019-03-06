#pragma once
#include <string>


//Language specific:
static const std::string LANGUAGE_NAME = "UniLang";
static const std::string LANGUAGE_FILE_EXTENSION = "UniLang";

//Style specific:

//colors
static const std::string ENTIRE_THEME_BACKGROUND_COLOR = "#000000";
static const std::string ENTIRE_THEME_FOREGROUND_COLOR = "#FFFFFF";
static const std::string LINE_HIGHTLIGHT_COLOR = "#45252B";
static const std::string SELECTION_COLOR = "#45252B";
static const std::string CARRET_COLOR = "#ddbb88";
static const std::string INVISIBLE_COLORS = "#FFFFFF";

//file name paths
static const std::string THEME_FILE = LANGUAGE_NAME + "/default.tmTheme";
static const std::string LANGUAGE_FILE = "User/" + LANGUAGE_NAME + ".tmLanguage";

//uuid
static const std::string THEME_UUID = "D8D5E82E-3D5B-46B5-B38E-8C841C21347D";
static const std::string LANGUAGE_UUID = "112dad9d-558e-4ab2-a4cc-c5f1ffa80ee6";