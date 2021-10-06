#pragma once
#include <cstdlib>
#include <string>
#include <iostream>

//+-----------------------+
//| Exiting with messages |
//+-----------------------+
void Exit_With_Success(std::string const& success_message);
void Exit_With_Error(std::string const& error_message);

//usual colorful ways to exit
void Exit_With_Green_Success(std::string const& success_message);
void Exit_With_Red_Error(std::string const& error_message);

//other colorful ways to exit
void Exit_With_Gold_Message_Success(std::string const& message);
void Exit_With_Blue_Message_Success(std::string const& message);
void Exit_With_Teal_Message_Success(std::string const& message);
void Exit_With_White_Message_Success(std::string const& message);
void Exit_With_Black_Message_Success(std::string const& message);

void Exit_With_Gold_Message_Error(std::string const& message);
void Exit_With_Blue_Message_Error(std::string const& message);
void Exit_With_Teal_Message_Error(std::string const& message);
void Exit_With_White_Message_Error(std::string const& message);
void Exit_With_Black_Message_Error(std::string const& message);

//+-----------------------------+
//| Exiting Based on Conditions |
//+-----------------------------+
void Exit_If_Not_Equal(int const& x, int const& y);
void Exit_If_Not_Equal(std::string const& x, std::string const& y);

//+--------------------------+
//| Exiting without messages |
//+--------------------------+
void Exit_With_Success();
void Exit_With_Successfuly();
void Exit_With_Error();
void Exit_With_Erroneously();

//+-------------------------+
//| Exiting from bool value |
//+-------------------------+
void Exit_Based_On_Bool_Value(bool const& b);
