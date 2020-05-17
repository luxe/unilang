#!/usr/bin/env bash
#run automatically by the build system

#PRE: a file name is passed into the function
#POST: if the file already exists, nothing will happen.
#      else the file will be created with quotes and the user will be notified

#this function will take one parameter which is a file to 
#create if the file doesn't already exist.
#if the file doen't, it will be created, 
#and an empty string will be added to the file
#the user will also be notified of the creation of the file.
function create_file_if_it_doesnt_exist {
	if [ ! -f $1 ];  then 
		echo "\"\"" >> $1; 
		echo "created " $1;
	fi
}

#create the files automatically and fill them with quotes,
#so the system can still build
create_file_if_it_doesnt_exist ideone_username.hpp
create_file_if_it_doesnt_exist ideone_password.hpp
create_file_if_it_doesnt_exist paste_bin_username.hpp
create_file_if_it_doesnt_exist paste_bin_password.hpp
