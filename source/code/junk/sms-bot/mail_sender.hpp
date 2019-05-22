#pragma once
#include <iostream>
#include <string>
#include <map>
#include "members.hpp"
#include "member.hpp"
#include "utilities.hpp"

/*	
	Mail_Sender requires that the following things be set up a certain way:
	software needed:
		sudo apt-get install msmtp-mta
		sudo apt-get install heirloom-mailx

	vim ~/.msmtprc

	#Gmail account
	-----------------------------------------------------------------------------------
	defaults
	#change the location of the log file to any desired location.
	logfile ~/msmtp.log
	account gmail
	auth on
	host smtp.gmail.com
	from <yourmail@gmail.com>
	auth on
	tls on
	tls_trust_file /usr/share/ca-certificates/mozilla/Equifax_Secure_CA.crt
	user <yourmail@gmail.com>
	password <your-password>
	port 587
	#set gmail as your default mail server.
	account default : gmail
	-----------------------------------------------------------------------------------
	chmod 600 .msmtprc

// vim ~/.mailrc
// set sendmail="/usr/bin/msmtp"
// set message-sendmail-extra-arguments="-a gmail"

*/

class Mail_Sender {
	Mail_Sender()=delete;
	public: static void Send(Members const& members, std::string const& message);
	public: static void Send(std::map<std::string,Member>::iterator const& member, std::string const& message);
};