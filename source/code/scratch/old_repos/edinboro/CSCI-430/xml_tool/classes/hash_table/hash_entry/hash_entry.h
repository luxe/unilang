#pragma once
#ifndef HASH_ENTRYT_H
#define HASH_ENTRYT_H
#include <string>
#include "../../xml_tree/tree_node.h"

class Hash_EntryT{

public:
	
	Hash_EntryT(std::string const& author_name, Tree_NodeT* node);


private:
	
	std::string author_name;
	Tree_NodeT* node;

};
#endif
