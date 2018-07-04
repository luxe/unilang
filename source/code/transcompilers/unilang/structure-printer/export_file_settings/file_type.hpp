#pragma once

//what the particular exported file represents
//should we make this a struct of bools instead?
enum class File_Type

//main
{INTERFACE
,IMPLEMENTATION
,DATA

//combined
,DATA_AND_INTERFACE
,INTERFACE_AND_IMPLEMENTATION
,ALL

};
