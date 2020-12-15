#pragma once
#include "CursVoenkomat.h"
#include "Checks.h"
void createFiles();
void fillSize(int&, int&, int&);
void fillClasses(MainAdmin*&, Admin*&, User*&, int&, int&, int&);
void fillFiles(MainAdmin*&, Admin*&, User*&, int&, int&, int&);
void changeSizeUsers(User*&, int&);
void changeSizeAdmins(Admin*&, int&);
void changeSizeMainAdmins(MainAdmin*&, int&);



ostream& operator<<(ostream&, MainAdmin&);
istream& operator>>(istream&, MainAdmin&);
istream& operator>>(istream&, Admin&);
ostream& operator<<(ostream&, Admin&);
ostream& operator<<(ostream&, User&);
istream& operator>>(istream&, User&);