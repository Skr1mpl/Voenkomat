#pragma once
#include "CursVoenkomat.h"
#include "ShowMenu.h"

int openMainAdminMenu(MainAdmin*&, Admin*&, User*&, int&, int&, int&);
int openAdminMenu(MainAdmin*&, Admin*&, User*&, int&, int&, int&);
int openUserMenu(MainAdmin*&, Admin*&, User*&, int&, int&, int&, int);
void openRedMenuMainAdmin(MainAdmin*&, Admin*&, User*&, int&, int&, int&, int&);
void openRedMenuAdmin(MainAdmin*&, Admin*&, User*&, int&, int&, int&, int&);
void openRedMenuUser(MainAdmin*&, Admin*&, User*&, int&, int&, int&, int&);
void openMenuUser(User*&, int&);
void openMenuRedDoc(User*&, int&);

