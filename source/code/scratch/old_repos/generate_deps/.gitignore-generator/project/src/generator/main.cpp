// generates portions of code for the symsource

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "utilities.hpp"

// utilities
void Print_Char_N_Times(char const& ch, int const& amount);

struct Node {

	Node(std::string const& name_in)
	  : name(name_in)
	  {
		  ltrim(name);
	}

	void Print(int depth = 0) const{

		std::cout << depth <<  " ";
		Print_Char_N_Times('\t', depth);
		std::cout <<  name << '\n';
		for (auto const& it: children) {
			it.Print(depth+1);
		}
		return;
	}

	void Print_Constants(std::ofstream & outfile) const{

		for (auto const& it: children) {
			it.Print_Constants(outfile);
		}
		if (children.empty()) {
			outfile << "std::vector<bool> NO_";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << ", YES_";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << ";\n";
		}
		return;
	}

	void Print_Groupings(std::ofstream & outfile) const{

		for (auto const& it: children) {
			it.Print_Groupings(outfile);
		}
		if (children.empty()) {
			outfile << "std::vector<bool> NO_";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << ", YES_";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << ";\n";
		}
		return;
	}

	void Print_Calls(std::ofstream & outfile) const{

		for (auto const& it: children) {
			it.Print_Calls(outfile);
		}
		if (children.empty()) {
			outfile << "if (All_Are_False(NO_";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << ") and Any_Are_True(YES_";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << "))\n";
			outfile << "{Print_Vector(outfile,constant::";
			outfile << string_replace_all(As_All_Capital_Letters_With_Spaces_As_Underscores(name), "+", "PLUS");
			outfile << ");}\n";
		}

		return;
	}

	std::string name;
	std::vector<Node> children;
};

// used for building the tree
Node Go_Deeper(int & i, unsigned int depth, std::vector<std::string> const& lines);
unsigned int Depth(std::string const& line);

// used for printing the tree
void Print(std::vector<Node> const& root);

void Create_Generated_Grouping_Names(std::vector<Node> const& root, std::string const& file_name);
void Fill_Generated_Grouping_Names(std::vector<Node> const& root, std::string const& file_name);
void Generate_Calls(std::vector<Node> const& root, std::string const& file_name);



int main() {

	std::ifstream infile("categories.txt");
	std::string line;
	std::vector<std::string> lines;
	std::getline(infile, line);
	while (infile) {
		lines.push_back(line);
		std::getline(infile, line);
	}

	std::vector<Node> root;
	for (int i =0; i <lines.size(); ++i ) {
		root.push_back(Go_Deeper(i, 0, lines));
	}

	//Print(root);

	Create_Generated_Grouping_Names(root, "generated_grouping_names.hpp");
	Fill_Generated_Grouping_Names(root, "generated_groupings.hpp");
	Generate_Calls(root, "generated_calls.hpp");


	return EXIT_SUCCESS;
}

// used for building the tree
Node Go_Deeper(int & i, unsigned int depth, std::vector<std::string> const& lines) {
	Node node(lines[i]);
	if (lines.size() > i+1) {
		while (lines.size() > i+1 and Depth(lines[i+1]) == depth+1) {
			node.children.push_back(Go_Deeper(++i, depth+1, lines));
		}

	}

	return node;

}
unsigned int Depth(std::string const& line) {
	unsigned int depth = 0;
	for (auto const& it: line) {
		if (it != '\t') {
			return depth;
		}else{
			++depth;
		}
	}
	return depth;
}

// used for printing the tree
void Print(std::vector<Node> const& root) {
	for (auto const& it: root) {
		std::cout <<  "|| ";it.Print();
	}
	return;
}

// utilities
void Print_Char_N_Times(char const& ch, int const& amount) {
	for (int i =0; i < amount; ++i) {
		std::cout <<  ch;
	}
}

void Create_Generated_Grouping_Names(std::vector<Node> const& root, std::string const& file_name) {
	std::ofstream outfile(file_name);

	for (auto const& it: root) {
		it.Print_Constants(outfile);
	}

	return;
}
void Fill_Generated_Grouping_Names(std::vector<Node> const& root, std::string const& file_name) {
	std::ofstream outfile(file_name);

	for (auto const& it: root) {
		it.Print_Groupings(outfile);
	}

	return;
}
void Generate_Calls(std::vector<Node> const& root, std::string const& file_name) {
	std::ofstream outfile(file_name);

	for (auto const& it: root) {
		it.Print_Calls(outfile);
	}

	return;
}



