#pragma once
#include "utilities.hpp"
#include "systems.hpp"

class Key_Pad_Analysis{





//creators
public: static std::vector<std::vector<int>> Create_Square() ;
public: static std::vector<std::vector<int>> Create_Diamond() ;
public: static std::pair<int,int> Create_Square_Start() ;
public: static std::pair<int,int> Create_Diamond_Start() ;};