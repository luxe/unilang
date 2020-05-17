//vector functions
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
	return std::find(vec.begin(), vec.end(), str) != vec.end();
}
