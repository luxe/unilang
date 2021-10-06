#include "tree_node.h"
#include <algorithm>

unsigned int Tree_NodeT::indent = 4;

//Constructor
Tree_NodeT::Tree_NodeT(XML_DatumT const& node_)
: node{node_}
, parent{nullptr}
{}

//(User Calls) - Observers
void Tree_NodeT::Print(std::ostream & out, unsigned int depth) const{
	using namespace std;
	
		out << Print_Spaces(depth*indent) << "<" << node.element.start_tag;
		
		if (!node.element.attributes.empty()){
			out << " " << Get_Attributes();
		}
		
		if (node.element.single_tag){
			out << "/>" << endl;
		}
		else{
			out << ">" << endl;
			if (node.data != ""){
				out << Print_Spaces((depth+1) * indent) << node.data << endl;
			}
		}
	for (auto it : children){
		it->Print(out,depth+1);
	}
	
		if (!node.element.single_tag){
			out << Print_Spaces(depth*indent) << "</" << node.element.start_tag << ">" << endl;
		}
	
	return;
}

//Transformers
void Tree_NodeT::Set_Parent(Tree_NodeT* node_){
	parent = node_;
	return;
}
void Tree_NodeT::Add_Child(XML_DatumT const& datum){
	
	Tree_NodeT* child = new Tree_NodeT(datum);
	child->Set_Parent(this);
	children.push_back(child);
	
	return;
}
void Tree_NodeT::Add_Child(Tree_NodeT* child){
	
	child->Set_Parent(this);
	children.push_back(child);
	
	return;
}
void Tree_NodeT::Set_Indent(unsigned int const& indent_){
	Tree_NodeT::indent = indent_;
	return;
}
//copy constructor
Tree_NodeT::Tree_NodeT(const Tree_NodeT& src){
	
	Copy_From(src);
}
	
//assignment operator
Tree_NodeT& Tree_NodeT::operator=(const Tree_NodeT& rhs){
	
	//Check for self-assignment
	if (this == &rhs){
		return *this;
	}
	
	//free the old memory
	delete parent;
	parent = nullptr;
	
	for(auto it: children){
		delete it;
	}
	children.clear();
	
	//Copy new memory
	Copy_From(rhs);
	
	return *this;
}
	
//Destructor
Tree_NodeT::~Tree_NodeT(){
	
	for(auto it : children){
		delete it; //HAHA, I used "it" for iterator, but now looK!
	}
	
	return;
}


//Utility functions
std::string Tree_NodeT::Print_Spaces(unsigned int const& amount){
	std::string spaces;
	for (unsigned int i = 0; i < amount; ++i){
		spaces+=" ";
	}
	return spaces;
}
std::string Tree_NodeT::Get_Attributes(void) const{
	
	std::string str;
	for (unsigned int i = 0; i < node.element.attributes.size()-1; ++i){
		str+= node.element.attributes[i].tag + "=" + node.element.attributes[i].value + ' ';
	}
	str+= node.element.attributes[node.element.attributes.size()-1].tag + "=" + node.element.attributes[node.element.attributes.size()-1].value;
	
	return str;
}
void Tree_NodeT::Copy_From(Tree_NodeT const& src){
	using namespace std;
	
	//shallow copy
	node = src.node;
	
	//deep copy
	parent = new Tree_NodeT(*src.parent);
	for(auto it : src.children){
		children.push_back(new Tree_NodeT(*it));
	}
	
	
	return;
}
void Tree_NodeT::Height(std::ostream & out) const{
	
	unsigned int max_height{0};
	Count_Depth(0,max_height);
	
	out << max_height <<'\n';
	return;
}
void Tree_NodeT::Count_Depth(unsigned int depth, unsigned int & max_height) const{
	
	max_height = std::max(max_height,depth);
	for (auto it : children){
		it->Count_Depth(depth+1,max_height);
	}
	
	return;
}
void Tree_NodeT::Print_Tag(std::ostream & out, std::string const& tag) const{
	using namespace std;
	
		if (node.element.start_tag == tag){
			out << "<" << node.element.start_tag;
			if (!node.element.attributes.empty()){
				out << " " << Get_Attributes();
			}
			if (node.element.single_tag){
			out << "/>";
			}
			else{
			out << ">";
			if (node.data != ""){
				out << " " << node.data << '\n';
			}
		}
		}
		for (auto it : children){
			it->Print_Tag(out,tag);
		}
		
	return;
}
void Tree_NodeT::Find_Tag(std::ostream & out, std::string const& tag, std::string const& value) const{
	
	static bool found{false};
	for (auto it = node.element.attributes.begin(); it != node.element.attributes.end() && !found; ++it){
		if (it->tag == tag && it->value == value){
			found = true;
		}
	}
	
	for (auto it = children.begin(); it != children.end() && !found; ++it){
		(*it)->Find_Tag(out,tag,value);
	}
	
	if (!parent){
	out << "The given attribute pair [" << tag << "," << value << "] does ";
	if(!found){out << "not ";}
	out << "exist.\n";
	}
	
	return;
}
void Tree_NodeT::Print_Subtree(std::ostream & out, std::string const& tag, std::string const& value) const{
	
	static bool found{false};
	for (auto it = node.element.attributes.begin(); it != node.element.attributes.end() && !found; ++it){
		if (it->tag == tag && it->value == value){
			found = true;
			Print(out,0);
		}
	}
	
	for (auto it = children.begin(); it != children.end() && !found; ++it){
		(*it)->Print_Subtree(out,tag,value);
	}
	
	return;
}
void Tree_NodeT::Print_Attributes(std::ostream & out, std::string const& tag, std::string const& value) const{
	
	static bool found{false};
	for (auto it = node.element.attributes.begin(); it != node.element.attributes.end() && !found; ++it){
		if (it->tag == tag && it->value == value){
			found = true;
			
			out << node.element.start_tag << ":";
			if (!node.element.attributes.empty()){
				out << " " << Get_Attributes();
			}
			out << '\n';
		
		}
	}
	
	for (auto it = children.begin(); it != children.end() && !found; ++it){
		(*it)->Print_Attributes(out,tag,value);
	}
	
	return;
}







