#include "code/utilities/exits/lib.hpp"
#include "code/utilities/colors/lib.hpp"

void Exit_With_Success(std::string const& success_message){
	std::cout << success_message << '\n';
	exit(EXIT_SUCCESS);
}
void Exit_With_Error(std::string const& error_message){
	std::cerr << error_message << '\n';
	exit(EXIT_FAILURE);
}

void Exit_With_Green_Success(std::string const& success_message){
	Green_Message(success_message +'\n');
	exit(EXIT_SUCCESS);
}
void Exit_With_Red_Error(std::string const& error_message){
	Red_Message(error_message + '\n');
	exit(EXIT_FAILURE);
}

void Exit_With_Gold_Message_Success(std::string const& message){
	Gold_Message(message + '\n');
	exit(EXIT_SUCCESS);
}
void Exit_With_Blue_Message_Success(std::string const& message){
	Blue_Message(message + '\n');
	exit(EXIT_SUCCESS);
}
void Exit_With_Teal_Message_Success(std::string const& message){
	Teal_Message(message + '\n');
	exit(EXIT_SUCCESS);
}
void Exit_With_White_Message_Success(std::string const& message){
	White_Message(message + '\n');
	exit(EXIT_SUCCESS);
}
void Exit_With_Black_Message_Success(std::string const& message){
	Black_Message(message + '\n');
	exit(EXIT_SUCCESS);
}

void Exit_With_Gold_Message_Error(std::string const& message){
	Gold_Error_Message(message + '\n');
	exit(EXIT_FAILURE);
}
void Exit_With_Blue_Message_Error(std::string const& message){
	Blue_Error_Message(message + '\n');
	exit(EXIT_FAILURE);
}
void Exit_With_Teal_Message_Error(std::string const& message){
	Teal_Error_Message(message + '\n');
	exit(EXIT_FAILURE);
}
void Exit_With_White_Message_Error(std::string const& message){
	White_Error_Message(message + '\n');
	exit(EXIT_FAILURE);
}
void Exit_With_Black_Message_Error(std::string const& message){
	Black_Error_Message(message + '\n');
	exit(EXIT_FAILURE);
}

//+--------------------------+
//| Exiting without messages |
//+--------------------------+
void Exit_With_Success(){
	exit(EXIT_SUCCESS);
}
void Exit_With_Successfuly(){
	exit(EXIT_SUCCESS);
}
void Exit_With_Error(){
	exit(EXIT_FAILURE);
}
void Exit_With_Erroneously(){
	exit(EXIT_FAILURE);
}

//+-------------------------+
//| Exiting from bool value |
//+-------------------------+
void Exit_Based_On_Bool_Value(bool const& b){
	if (b){
		exit(EXIT_SUCCESS);
	}else{
		exit(EXIT_FAILURE);
	}
}
