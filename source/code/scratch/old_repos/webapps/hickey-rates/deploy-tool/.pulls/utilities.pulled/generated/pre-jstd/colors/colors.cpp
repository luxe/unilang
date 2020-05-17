//color functions
std::string colorize(std::string const& message, int const& background, int const& forground) {
	return std::string("\x1b[38;5;" + std::to_string(forground) + ";48;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
std::string colorize_forground(std::string const& message, int const& background) {
	return std::string("\x1b[38;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
std::string colorize_background(std::string const& message, int const& forground) {
	return std::string("\x1b[48;5;" + std::to_string(forground) + "m" + message + "\x1b[0m");
}
void Green_Message(std::string const& str){

	std::cout << colorize_forground(str, 118);
	return;
}
void Red_Message(std::string const& str){

	std::cerr << colorize_forground(str, 1);
	return;
}
void Exit_With_Error_Message(std::string const& str){
	Red_Message(str);
	exit(EXIT_SUCCESS);
	return;
}
