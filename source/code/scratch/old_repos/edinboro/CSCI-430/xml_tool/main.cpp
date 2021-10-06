/*
	Name: Trevor Hickey
	Class: CSCI 430 - Compilers
	Assignment 1 and 2
	Description: Parse a subset of the XML markup language
	and store/access data with trees and hash tables.
*/

//STD Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <memory>

//My Classes
#include "classes/program_options/program_options.h"
#include "classes/xml_tree/tree_node.h"
#include "classes/hash_table/hash_table.h"
#include "classes/user_option/user_option.h"

//Bennet Code (Modified)
#include "classes/xml_tokens/xml_tokens.h"
#include "classes/xml_scanner/xml_scanner.h"

//Construct XML Trees
std::vector<Tree_NodeT*> Build_Tree_List(std::vector<std::string> const& files);
Tree_NodeT* Build_Tree(std::string const& file);
void Build_Tree_From_Root(Tree_NodeT* node, XML_ScannerT & scanner);
XML_DatumT Get_Datum(XML_ScannerT & scanner, bool & is_leaf);
XML_ElementT Get_Element(XML_ScannerT & scanner);
std::string Get_Start_Tag(XML_ScannerT & scanner);
std::vector<XML_AttributeT> Build_Attributes(XML_ScannerT & scanner);
XML_DatumT Finish_Single_Tag(XML_ScannerT & scanner,XML_ElementT const& element);
XML_DatumT Finish_Multi_Tag(XML_ScannerT & scanner,XML_ElementT const& element, bool & is_leaf);
void Expect_End_Tag(XML_ScannerT & scanner, XML_DatumT const& datum);
void Build_Tree_From_SubNode(Tree_NodeT* node, XML_ScannerT & scanner, XML_DatumT const& datum);
void Build_Subtree(Tree_NodeT* node, XML_ScannerT & scanner);

//Tree Queries
void Print_Tree(std::vector<Tree_NodeT*> const& xml_trees);
void Print_Height(std::vector<Tree_NodeT*> const& xml_trees);
void Print_Tag(std::vector<Tree_NodeT*> const& xml_trees,std::string const& tag);
void Find_Tag(std::vector<Tree_NodeT*> const& xml_trees,std::string const& tag, std::string const& value);
void Print_Subtree(std::vector<Tree_NodeT*> const& xml_trees,std::string const& tag, std::string const& value);
void Print_Attributes(std::vector<Tree_NodeT*> const& xml_trees,std::string const& tag, std::string const& value);

//Hash Queries

//Proceses User Interaction
void Process_User_Input(std::vector<Tree_NodeT*> const& xml_trees);
void Output_File_Amount(std::vector<Tree_NodeT*> const& xml_trees);
UserOptionT Get_User_Option(void);
void Print_User_Options(void);
void Process_User_Decision(std::vector<Tree_NodeT*> const& xml_trees, UserOptionT const& user_option);

//Proceses Program Options
void Process_Program_Options(std::vector<Tree_NodeT*> xml_trees, std::unique_ptr<Program_OptionsT> const& program_options);

//Routines That Exit Program With Failure
void Check_File_Validity(std::ifstream const& infile,std::string const& file);
void Error_State(XML_ScannerT & scanner);

int main(int argc, char** argv){
	using namespace std;

	//read in program flags and build a tree for each XML file
	unique_ptr<Program_OptionsT> program_options {new Program_OptionsT{argc,argv}};
	vector<Tree_NodeT*> xml_trees {Build_Tree_List(program_options->Get_Files())};
	Tree_NodeT::Set_Indent(program_options->Get_Indent());

	/* run the program either interactively (allowing the user to enter commands),
	 * or process each flag value and exit.  The program will only run interactively
	 * if the "file name" flag is the only flag given a value. */
	if (program_options->Interactive()){
		Process_User_Input(xml_trees);
	}
	else{
		Process_Program_Options(xml_trees,program_options);
	}

	return EXIT_SUCCESS;
}

//Constructing XML Trees
std::vector<Tree_NodeT*> Build_Tree_List(std::vector<std::string> const& files){
	using namespace std;

	//we might have more than one xml file, so lets
	//read them all in and store the trees in a vector
	vector<Tree_NodeT*> xml_trees;
	for(auto file : files){
		xml_trees.push_back(Build_Tree(file));
	}

	return xml_trees;
}
Tree_NodeT* Build_Tree(std::string const& file){
	using namespace std;

	//create scanner
	ifstream infile{file,ifstream::in};
	Check_File_Validity(infile,file);
	XML_ScannerT scanner{infile};
	scanner.Analysis();

	//create root node
	XML_DatumT root_data;
	root_data.element.start_tag = file;
	root_data.element.single_tag = false;
	Tree_NodeT* root = new Tree_NodeT(root_data);

	//recursively create all the root's subtrees
	while(Valid_Token(scanner.Token())){
		Build_Tree_From_Root(root,scanner);
	}

	return root;
}
void Build_Tree_From_Root(Tree_NodeT* node, XML_ScannerT & scanner){

	//get datum
	bool is_leaf{true};
	XML_DatumT datum {Get_Datum(scanner,is_leaf)};
	Tree_NodeT* sub_tree = new Tree_NodeT(datum);
	
	//add leaf node
	if(is_leaf){
		node->Add_Child(sub_tree);
	}

	//add subtree
	else{
		Build_Tree_From_SubNode(sub_tree,scanner,datum);
		node->Add_Child(sub_tree);
	}

	return;
}
void Build_Tree_From_SubNode(Tree_NodeT* node, XML_ScannerT & scanner, XML_DatumT const& datum){
	
	while (TokenT::START == scanner.Token() && Valid_Token(scanner.Token())){
		Build_Subtree(node,scanner);
	}
	
	Expect_End_Tag(scanner,datum);
	return;
}
void Build_Subtree(Tree_NodeT* node, XML_ScannerT & scanner){
	
	//get datum
	bool is_leaf{true};
	XML_DatumT datum {Get_Datum(scanner,is_leaf)};
	Tree_NodeT* sub_tree = new Tree_NodeT(datum);
	
	//add leaf node
	if(is_leaf){
		node->Add_Child(sub_tree);
	}
	
	//add subtree
	else{
		Build_Tree_From_SubNode(sub_tree,scanner,datum);
		node->Add_Child(sub_tree);
	}
	
	return;
}
void Expect_End_Tag(XML_ScannerT & scanner, XML_DatumT const& datum){

	if (TokenT::END == scanner.Token()){
		scanner.Analysis();
		if(TokenT::NAME == scanner.Token() && datum.element.start_tag == scanner.Value()){
			scanner.Analysis();
			if(TokenT::CLOSE == scanner.Token()){
				scanner.Analysis();
			}
			else{
				Error_State(scanner);
			}
		}
		else{
			Error_State(scanner);
		}
	}
	return;
}
XML_DatumT Get_Datum(XML_ScannerT & scanner, bool & is_leaf){

	//get element
	XML_ElementT element{Get_Element(scanner)};
	XML_DatumT datum;

	if (element.single_tag){
		datum = Finish_Single_Tag(scanner,element);
	}
	else{
		datum = Finish_Multi_Tag(scanner,element,is_leaf);
	}

	return datum;
}
XML_ElementT Get_Element(XML_ScannerT & scanner){

	//get start tag and attributes
	std::string start_tag = Get_Start_Tag(scanner);
	std::vector<XML_AttributeT> attributes = Build_Attributes(scanner);
	bool single_tag;

	switch (scanner.Token()){

		//single tag
		case TokenT::SLASH: single_tag = true; break;

		//not a single tag
		case TokenT::CLOSE: single_tag = false; break;
		default: Error_State(scanner);
	}

	return XML_ElementT{start_tag,attributes,single_tag};
}
std::string Get_Start_Tag(XML_ScannerT & scanner){

	std::string start_tag;
	if (TokenT::START == scanner.Token()){
		start_tag = scanner.Value();
	}
	else{
		Error_State(scanner);
	}

	return start_tag;
}
std::vector<XML_AttributeT> Build_Attributes(XML_ScannerT & scanner){
	using namespace std;

	vector<XML_AttributeT> attributes;
	XML_AttributeT attribute;
	scanner.Analysis();

	while (TokenT::NAME == scanner.Token()){
		attribute.tag = scanner.Value();
		scanner.Analysis();
		if (TokenT::EQ == scanner.Token()){
			scanner.Analysis();
			if (TokenT::VALUE == scanner.Token()){
				attribute.value = scanner.Value();
				
				//remove the quotes
				if (attribute.value[0] == '"' && attribute.value[attribute.value.length()-1] == '"'){
					attribute.value = attribute.value.substr(0, attribute.value.size()-1);
					attribute.value.erase(0,1);
				}
				else{
					Error_State(scanner);
				}
				
				attributes.push_back(attribute);
			}
			else{
				Error_State(scanner);
			}
		}
		else{
			Error_State(scanner);
		}
		scanner.Analysis();
	}

	return attributes;
}
XML_DatumT Finish_Single_Tag(XML_ScannerT & scanner,XML_ElementT const& element){

	XML_DatumT node{element,""};
	scanner.Analysis();
	if (TokenT::CLOSE != scanner.Token()){
		Error_State(scanner);
	}
	scanner.Analysis();

	return node;
}
XML_DatumT Finish_Multi_Tag(XML_ScannerT & scanner,XML_ElementT const& element, bool & is_leaf){

	XML_DatumT datum;
	bool correct_path{false};
	datum = XML_DatumT{element,""};
	scanner.Analysis();

	if(TokenT::END == scanner.Token()){
		correct_path = true;
		Expect_End_Tag(scanner,datum);
	}
	else if(TokenT::DATA == scanner.Token()){
		datum.data = scanner.Value();
		scanner.Analysis();
		if (TokenT::END == scanner.Token()){
			correct_path = true;
			Expect_End_Tag(scanner,datum);
		}
		else if(TokenT::START == scanner.Token()){
			correct_path = true;
			is_leaf = false;
		}
	}
	else if(TokenT::START == scanner.Token()){
		correct_path = true;
		is_leaf = false;
	}

	//decide if best path was teken
	if (!correct_path){
		Error_State(scanner);
	}

	return datum;
}

//Tree Queries
void Print_Tree(std::vector<Tree_NodeT*> const& xml_trees){

	for (auto const& tree : xml_trees){
		tree->Print(std::cout);
	}

	return;
}
void Print_Height(std::vector<Tree_NodeT*> const& xml_trees){

	for (auto const& tree : xml_trees){
		tree->Height(std::cout);
	}

	return;
}
void Print_Tag(std::vector<Tree_NodeT*> const& xml_trees, std::string const& tag){

	for (auto const& tree : xml_trees){
		tree->Print_Tag(std::cout,tag);
	}

	return;
}
void Find_Tag(std::vector<Tree_NodeT*> const& xml_trees, std::string const& tag, std::string const& value){

	for (auto const& tree : xml_trees){
		tree->Find_Tag(std::cout,tag,value);
	}

	return;
}
void Print_Subtree(std::vector<Tree_NodeT*> const& xml_trees, std::string const& tag, std::string const& value){

	for (auto const& tree : xml_trees){
		tree->Print_Subtree(std::cout,tag,value);
	}

	return;
}
void Print_Attributes(std::vector<Tree_NodeT*> const& xml_trees, std::string const& tag, std::string const& value){

	for (auto const& tree : xml_trees){
		tree->Print_Attributes(std::cout,tag,value);
	}

	return;
}

//Processing User Interaction
void Process_User_Input(std::vector<Tree_NodeT*> const& xml_trees){

	Output_File_Amount(xml_trees);
	UserOptionT user_option{Get_User_Option()};

	//continue processing trees by user request
	//exit program if selected by the user
	while(true){
		Process_User_Decision(xml_trees,user_option);
		user_option = Get_User_Option();
	}

	return;
}
void Process_User_Decision(std::vector<Tree_NodeT*> const& xml_trees, UserOptionT const& user_option){
	using namespace std;
	std::string tag;
	std::string value;

	switch(user_option){
		case UserOptionT::PRINT:
			Print_Tree(xml_trees);
			break;

		case UserOptionT::HEIGHT:
			Print_Height(xml_trees);
			break;

		case UserOptionT::PRINT_TAG:
			cout << "tag => ";
			cin >> tag;
			Print_Tag(xml_trees,tag);
			break;

		case UserOptionT::FIND:
			cout << "tag => ";
			cin >> tag;
			cout << "value => ";
			cin >> value;
			Find_Tag(xml_trees,tag,value);
			break;

		case UserOptionT::PRINT_SUB_TREE:
			cout << "tag => ";
			cin >> tag;
			cout << "value => ";
			cin >> value;
			Print_Subtree(xml_trees,tag,value);
			break;

		case UserOptionT::PRINT_ATTRIBUTES:
			cout << "tag => ";
			cin >> tag;
			cout << "value => ";
			cin >> value;
			Print_Attributes(xml_trees,tag,value);
			break;

		case UserOptionT::EXIT:
			exit(EXIT_SUCCESS);
			break;

		default:;
	}

	return;
}
void Output_File_Amount(std::vector<Tree_NodeT*> const& xml_trees){
	using namespace std;

	cout << '[' << xml_trees.size() << " XML file";
	if (xml_trees.size() > 1){cout << "s";}
	cout << " read in.]\n";

	return;
}
UserOptionT Get_User_Option(void){
	using namespace std;

	UserOptionT user_option{UserOptionT::INVALID};

	Print_User_Options();
	int input;
	cin >> input;
	user_option = UserOptionT(input);
	while (UserOptionT::INVALID == user_option){
		cout << "Invalid Entry.\n";
		Print_User_Options();
		cin >> input;
		user_option = UserOptionT(input);
	}

	return user_option;
}
void Print_User_Options(void){
	using namespace std;

	cout << "Type the number that corresponds the to command you would like to processes.\n";
	cout << "\t 1. Print" << '\n';
	cout << "\t 2. Height" << '\n';
	cout << "\t 3. Print_Tag" << '\n';
	cout << "\t 4. Find" << '\n';
	cout << "\t 5. Print Subtree" << '\n';
	cout << "\t 6. Print Attributes" << '\n';
	cout << "\t 7. Exit Program" << '\n';
	cout << "number => ";
	return;
}

//Processing Program Options
void Process_Program_Options(std::vector<Tree_NodeT*> xml_trees, std::unique_ptr<Program_OptionsT> const& program_options){

	if (program_options->Print()){
		Print_Tree(xml_trees);
	}
	if (program_options->Height()){
		Print_Height(xml_trees);
	}
	for (auto const& tag : program_options->Get_Tags()){
		Print_Tag(xml_trees,tag);
	}
	for (auto const& pair : program_options->Get_Finds()){
		Find_Tag(xml_trees,pair.first,pair.second);
	}
	for (auto const& pair : program_options->Get_Subtrees()){
		Print_Subtree(xml_trees,pair.first,pair.second);
	}
	for (auto const& pair : program_options->Get_Attributes()){
		Print_Attributes(xml_trees,pair.first,pair.second);
	}

	return;
}

//Routines That Exit Program With Failure
void Error_State(XML_ScannerT & scanner){

	std::cerr << "BAD XML\n";
	scanner.Analysis(); //shhhhhhhhh.. don't tell the compiler
	exit(EXIT_FAILURE);

	return;
}
void Check_File_Validity(std::ifstream const& infile,std::string const& file){

	if (!infile.is_open()){
		std::cerr << "ERROR: could not open file: " << file << '\n';
		exit(EXIT_FAILURE);
	}

	return;
}


