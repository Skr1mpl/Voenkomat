#pragma once
#include "CursVoenkomat.h"
#include "Checks.h"

int chooseMainMenu(); 
int chooseMainAdminMenu();
int chooseRole();
int chooseMainAdmins(MainAdmin*&, int&);
int chooseWhatRedMainAdmin(MainAdmin*&, int&);
int chooseAdmins(Admin*&, int&);
int chooseWhatRedAdmin(Admin*&, int&);
int chooseUsers(User*&, int&);
int chooseWhatRedUser(User*&, int&);
int chooseMenuUser();
int chooseWhatRedSolider(User*&, int&);
int chooseDoc(User*&, int&);
int chooseHowSearch();
int chooseHowSort();
int chooseUpOrDown();
int chooseAdminMenu();
int chooseUserMenu();
