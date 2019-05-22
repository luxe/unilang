#include "mail_sender.hpp"

void Mail_Sender::Send(Members const& members, std::string const& message) {

	std::cout << "sending to: " << members.Get_String_Of_All_Member_Emails() << std::endl;
	//send the message via email
	std::string return_message = exec("echo \"" + message + "\" | mail \"" + members.Get_String_Of_All_Member_Emails() + "\"");

	return;
}
void Mail_Sender::Send(std::map<std::string,Member>::iterator const& member, std::string const& message) {

	//send the message via email
	std::string return_message = exec("echo \"" + message + "\" | mail \"" + member->first + "\"");

	return;
}