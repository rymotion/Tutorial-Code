#ifndef PASSWORDFILE_H
#define PASSWORDFILE_H 
#include <string>
#include <vector>
#include <fstream>
#include "UserPw.h"

using namespace std;

class PasswordFile : public UserPw{
 public:
	 PasswordFile(string filename);// opens the file and reads the names/passwords in the vector entry
	 vector <UserPw> getFile(); // returns the vector entry 
	 void addpw(UserPw newentry); //this adds a new user/password to entry and writes entry to the file filename
	 bool checkpw(string user, string passwd); // returns true is user exists and password matches\
	 fstream printPw(string filename);
 private:
	 string filename; // the file that contains password information
	 vector <UserPw> entry; // the list of usernames/passwords
};
#endif