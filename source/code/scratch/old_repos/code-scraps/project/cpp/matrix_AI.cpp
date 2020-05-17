/*
	Hickey, Pool, Rhodes
	12/5/2012
	CSCI 370
*/

//STD Libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>

//constants
int RADIUS = 2;
const int THRESHOLD = 10;

//type definitions
typedef std::vector<std::vector<char> > MatrixT;


//functions
std::string Get_File(void);
MatrixT Get_Matrix(std::string const& file_name);
MatrixT Create_Blank(MatrixT const& original);
void Perform_Laplace(MatrixT const& original,MatrixT & changed);
void Identify_Circles(MatrixT & changed);
void Print_Circle_Centers(MatrixT const& changed);
void Output(MatrixT const& matrix);

int main(){

	//get file name
	std::string file_name(Get_File());

	//get matrix from file
	MatrixT original(Get_Matrix(file_name));
	MatrixT changed (Create_Blank(original));
	
	//perform edge detection
	Perform_Laplace(original,changed);
	
	//identify circles
	Identify_Circles(changed);
	
	//output the picture with results
	Output(changed);
	Print_Circle_Centers(changed);

	return EXIT_SUCCESS;
}

std::string Get_File(void){
	std::string file_name;

	std::cout << "Enter input file: ";
	std::cin >> file_name;

	return file_name;
}
MatrixT Get_Matrix(std::string const& file_name){

	std::ifstream infile(file_name.c_str());
	MatrixT matrix;
	std::vector<char> row;

	int width;
	int height;
	char c;
	infile >> width >> height;
	std::cout << width << ' ' << height << std::endl;

	for (int i(0); i < height; ++i){
		for (int i(0); i < width; ++i){
			infile >> c;
			row.push_back(c);
		}
		matrix.push_back(row);
		row.clear();
	}

	return matrix;
}
MatrixT Create_Blank(MatrixT const& original){
	MatrixT changed = original;
	
	for(int j=0; j < changed.size(); j++){
		for(int k=0; k<changed[0].size(); k++){
          changed[j][k] = ' ';
		}
	}
	
	return changed;
}
void Perform_Laplace(MatrixT const& original,MatrixT & changed){
	
	int value;
	
	for(int j=1; j< changed.size()-1; j++){
		for(int k=1; k<changed[0].size()-1; k++){
			value = original[j-1][k-1] * 1  +
			original[j][k-1]           * 1  +
			original[j+1][k-1]         * 1  +
			original[j-1][k]           * 1  +
			original[j][k]             * -8 +
			original[j+1][k]           * 1  +
			original[j-1][k+1]         * 1  +
			original[j][k+1]           * 1  +
			original[j+1][k+1]         * 1;
			if(abs(float(value)) >=THRESHOLD) {
				changed[j][k] = '#';
			}
		}
	}
	
	return;
}
void Identify_Circles(MatrixT & changed){
	
	int x,y,count;
	int width = changed[0].size();
	int height = changed.size();
	
	
	for(; RADIUS < width-1; RADIUS++){
		for(int j = RADIUS; j < (height-RADIUS); j++) {
			for(int k=RADIUS; k < (width-RADIUS); k++) {
				count = 0;
				for (int theta = 0; theta < 360; theta += 30) {
					y = int(k + RADIUS * cos(float(theta) / 57.2958));
					x = int(j + RADIUS *sin(float(theta) / 57.2958));
					if (changed[x][y] == '#'){
						++count;
					}
				}
				if(float (count) / 12 >= 0.75) {
					if(changed[j][k-1] != '*'){
						changed[j][k] = '*';
					}
					break;
				}
			}
		}
	}
	
	return;
}
void Print_Circle_Centers(MatrixT const& changed){
	
	for (int j = 0; j < changed.size(); j++) {
		for(int k = 0; k < changed[0].size(); k++){
			if(changed[j][k] == '*'){
				std::cout << "Circle found at (" << k+1 << ", " << j+1  << ")" << std::endl;
			}
		}
	}
	
	
	return;
}
void Output(MatrixT const& matrix){
	for (int j = 0; j < matrix.size(); j++) {
		for(int k = 0; k < matrix[0].size(); k++){
			std::cout << matrix[j][k];;
		}
		std::cout << '\n';
	}
	return;
}







