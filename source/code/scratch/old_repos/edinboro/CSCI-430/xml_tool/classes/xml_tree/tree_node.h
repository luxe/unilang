#pragma once
#ifndef TREE_NODE_T_H
#define TREE_NODE_T_H

#include <vector>
#include <string>
#include <iostream>
#include "xml_datum/xml_datum.h"

class Tree_NodeT{
public:

	//Constructor
	explicit Tree_NodeT(XML_DatumT const& node);
	explicit Tree_NodeT(void){}
	
	// (User Calls) - Observers
	void Print(std::ostream & out, unsigned int depth=0) const;
	void Height(std::ostream & out) const;
	void Print_Tag(std::ostream & out, std::string const& tag) const;
	void Find_Tag(std::ostream & out, std::string const& tag, std::string const& value) const;
	void Print_Subtree(std::ostream & out, std::string const& tag, std::string const& value) const;
	void Print_Attributes(std::ostream & out, std::string const& tag, std::string const& value) const;
		
	//Transformers
	void Set_Parent(Tree_NodeT* node);
	void Add_Child(XML_DatumT const& datum);
	void Add_Child(Tree_NodeT* child);
	
	static void Set_Indent(unsigned int const& indent);
	
	//copy constructor
	Tree_NodeT(const Tree_NodeT& src);
	
	//assignment operator
	Tree_NodeT& operator=(const Tree_NodeT& rhs);
	
	//Destructor
	~Tree_NodeT();
	
protected:
private:
	
	//data
	XML_DatumT node;
	static unsigned int indent;
	
	//links
	std::vector<Tree_NodeT*> children;
	Tree_NodeT* parent;
	
	//utility functions
	static std::string Print_Spaces(unsigned int const& amount);
	std::string Get_Attributes(void) const;
	void Copy_From(Tree_NodeT const& src);
	void Count_Depth(unsigned int depth, unsigned int & max_height) const;
};
#endif

