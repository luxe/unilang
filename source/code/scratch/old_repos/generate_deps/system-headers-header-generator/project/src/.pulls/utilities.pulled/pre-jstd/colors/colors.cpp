//base colorizing string functions
std::string colorize(std::string const& message, int const& background, int const& forground) {
	return std::string("\x1b[38;5;" + std::to_string(forground) + ";48;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
std::string colorize_forground(std::string const& message, int const& background) {
	return std::string("\x1b[38;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
std::string colorize_background(std::string const& message, int const& forground) {
	return std::string("\x1b[48;5;" + std::to_string(forground) + "m" + message + "\x1b[0m");
}

//specific colorizing string functions
std::string Green_String(std::string const& str){
	return colorize_forground(str, 118);
}
std::string Red_String(std::string const& str){
	return colorize_forground(str, 1);
}
std::string Gold_String(std::string const& str){
	return colorize_forground(str, 3);
}
std::string Blue_String(std::string const& str){
	return colorize_forground(str, 4);
}
std::string Teal_String(std::string const& str){
	return colorize_forground(str, 6);
}
std::string White_String(std::string const& str){
	return colorize_forground(str, 7);
}
std::string Black_String(std::string const& str){
	return colorize_forground(str, 16);
}
std::string Purple_String(std::string const& str){
	return colorize_forground(str, 5);
}

//output string through std::cout
void Green_Message(std::string const& str){

	std::cout << Green_String(str);
	return;
}
void Red_Message(std::string const& str){

	std::cout << Red_String(str);
	return;
}
void Gold_Message(std::string const& str){

	std::cout << Gold_String(str);
	return;
}
void Blue_Message(std::string const& str){

	std::cout << Blue_String(str);
	return;
}
void Teal_Message(std::string const& str){

	std::cout << Teal_String(str);
	return;
}
void White_Message(std::string const& str){

	std::cout << White_String(str);
	return;
}
void Black_Message(std::string const& str){

	std::cout << Black_String(str);
	return;
}
void Purple_Message(std::string const& str){

	std::cout << Purple_String(str);
	return;
}

//output string through std::cout and flush
void Green_Message_And_Flush(std::string const& str){
	Green_Message(str);
	std::cout.flush();
	return;
}
void Red_Message_And_Flush(std::string const& str){
	Red_Message(str);
	std::cout.flush();
	return;
}
void Gold_Message_And_Flush(std::string const& str){
	Gold_Message(str);
	std::cout.flush();
	return;
}
void Blue_Message_And_Flush(std::string const& str){
	Blue_Message(str);
	std::cout.flush();
	return;
}
void Teal_Message_And_Flush(std::string const& str){
	Teal_Message(str);
	std::cout.flush();
	return;
}
void White_Message_And_Flush(std::string const& str){
	White_Message(str);
	std::cout.flush();
	return;
}
void Black_Message_And_Flush(std::string const& str){
	Black_Message(str);
	std::cout.flush();
	return;
}
void Purple_Message_And_Flush(std::string const& str){
	Purple_Message(str);
	std::cout.flush();
	return;
}

//output through std::cerr
void Green_Error_Message(std::string const& str){

	std::cerr << Green_String(str);
	return;
}
void Red_Error_Message(std::string const& str){

	std::cerr << Red_String(str);
	return;
}
void Gold_Error_Message(std::string const& str){

	std::cerr << Gold_String(str);
	return;
}
void Blue_Error_Message(std::string const& str){

	std::cerr << Blue_String(str);
	return;
}
void Teal_Error_Message(std::string const& str){

	std::cerr << Teal_String(str);
	return;
}
void White_Error_Message(std::string const& str){

	std::cerr << White_String(str);
	return;
}
void Black_Error_Message(std::string const& str){

	std::cerr << Black_String(str);
	return;
}
void Purple_Error_Message(std::string const& str){

	std::cerr << Purple_String(str);
	return;
}

//output string through std::cerr and flush
void Green_Error_Message_And_Flush(std::string const& str){
	Green_Error_Message(str);
	std::cerr.flush();
	return;
}
void Red_Error_Message_And_Flush(std::string const& str){
	Red_Error_Message(str);
	std::cerr.flush();
	return;
}
void Gold_Error_Message_And_Flush(std::string const& str){
	Gold_Error_Message(str);
	std::cerr.flush();
	return;
}
void Blue_Error_Message_And_Flush(std::string const& str){
	Blue_Error_Message(str);
	std::cerr.flush();
	return;
}
void Teal_Error_Message_And_Flush(std::string const& str){
	Teal_Error_Message(str);
	std::cerr.flush();
	return;
}
void White_Error_Message_And_Flush(std::string const& str){
	White_Error_Message(str);
	std::cerr.flush();
	return;
}
void Black_Error_Message_And_Flush(std::string const& str){
	Black_Error_Message(str);
	std::cerr.flush();
	return;
}
void Purple_Error_Message_And_Flush(std::string const& str){
	Purple_Error_Message(str);
	std::cerr.flush();
	return;
}

////////////////////////////////////////// SAME, BUT FOR WSTRING //////////////////////////////////////////////////////////////

//wstring support
std::wstring colorize(std::wstring const& message, int const& background, int const& forground) {
	return std::wstring(L"\x1b[38;5;" + std::to_wstring(forground) + L";48;5;" + std::to_wstring(background) + L"m" + message + L"\x1b[0m");
}
std::wstring colorize_forground(std::wstring const& message, int const& background) {
	return std::wstring(L"\x1b[38;5;" + std::to_wstring(background) + L"m" + message + L"\x1b[0m");
}
std::wstring colorize_background(std::wstring const& message, int const& forground) {
	return std::wstring(L"\x1b[48;5;" + std::to_wstring(forground) + L"m" + message + L"\x1b[0m");
}

//specific colorizing wstring functions
std::wstring Green_String(std::wstring const& str){
	return colorize_forground(str, 118);
}
std::wstring Red_String(std::wstring const& str){
	return colorize_forground(str, 1);
}
std::wstring Gold_String(std::wstring const& str){
	return colorize_forground(str, 3);
}
std::wstring Blue_String(std::wstring const& str){
	return colorize_forground(str, 4);
}
std::wstring Teal_String(std::wstring const& str){
	return colorize_forground(str, 6);
}
std::wstring White_String(std::wstring const& str){
	return colorize_forground(str, 7);
}
std::wstring Black_String(std::wstring const& str){
	return colorize_forground(str, 16);
}

//output wstring through std::wcout
void Green_Message(std::wstring const& str){

	std::wcout << Green_String(str);
	return;
}
void Red_Message(std::wstring const& str){

	std::wcout << Red_String(str);
	return;
}
void Gold_Message(std::wstring const& str){

	std::wcout << Gold_String(str);
	return;
}
void Blue_Message(std::wstring const& str){

	std::wcout << Blue_String(str);
	return;
}
void Teal_Message(std::wstring const& str){

	std::wcout << Teal_String(str);
	return;
}
void White_Message(std::wstring const& str){

	std::wcout << White_String(str);
	return;
}
void Black_Message(std::wstring const& str){

	std::wcout << Black_String(str);
	return;
}

//output wstring through std::wcout and flush
void Green_Message_And_Flush(std::wstring const& str){
	Green_Message(str);
	std::wcout.flush();
	return;
}
void Red_Message_And_Flush(std::wstring const& str){
	Red_Message(str);
	std::wcout.flush();
	return;
}
void Gold_Message_And_Flush(std::wstring const& str){
	Gold_Message(str);
	std::wcout.flush();
	return;
}
void Blue_Message_And_Flush(std::wstring const& str){
	Blue_Message(str);
	std::wcout.flush();
	return;
}
void Teal_Message_And_Flush(std::wstring const& str){
	Teal_Message(str);
	std::wcout.flush();
	return;
}
void White_Message_And_Flush(std::wstring const& str){
	White_Message(str);
	std::wcout.flush();
	return;
}
void Black_Message_And_Flush(std::wstring const& str){
	Black_Message(str);
	std::wcout.flush();
	return;
}

//output through std::wcerr
void Green_Error_Message(std::wstring const& str){

	std::wcerr << Green_String(str);
	return;
}
void Red_Error_Message(std::wstring const& str){

	std::wcerr << Red_String(str);
	return;
}
void Gold_Error_Message(std::wstring const& str){

	std::wcerr << Gold_String(str);
	return;
}
void Blue_Error_Message(std::wstring const& str){

	std::wcerr << Blue_String(str);
	return;
}
void Teal_Error_Message(std::wstring const& str){

	std::wcerr << Teal_String(str);
	return;
}
void White_Error_Message(std::wstring const& str){

	std::wcerr << White_String(str);
	return;
}
void Black_Error_Message(std::wstring const& str){

	std::wcerr << Black_String(str);
	return;
}

//output wstring through std::wcerr and flush
void Green_Error_Message_And_Flush(std::wstring const& str){
	Green_Error_Message(str);
	std::wcerr.flush();
	return;
}
void Red_Error_Message_And_Flush(std::wstring const& str){
	Red_Error_Message(str);
	std::wcerr.flush();
	return;
}
void Gold_Error_Message_And_Flush(std::wstring const& str){
	Gold_Error_Message(str);
	std::wcerr.flush();
	return;
}
void Blue_Error_Message_And_Flush(std::wstring const& str){
	Blue_Error_Message(str);
	std::wcerr.flush();
	return;
}
void Teal_Error_Message_And_Flush(std::wstring const& str){
	Teal_Error_Message(str);
	std::wcerr.flush();
	return;
}
void White_Error_Message_And_Flush(std::wstring const& str){
	White_Error_Message(str);
	std::wcerr.flush();
	return;
}
void Black_Error_Message_And_Flush(std::wstring const& str){
	Black_Error_Message(str);
	std::wcerr.flush();
	return;
}