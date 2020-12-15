#include "FuncMenu.h"
#include "Files.h"

int openMainAdminMenu(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers) {
	while (true) {
		int choose = chooseMainAdminMenu();
		if (choose == 0) {
			while (true) {
				int choose1 = chooseRole();
				if (choose1 == 3) break;
				if (choose1 == 0) {
					for (int i = 0; i < nMainAdmins; i++) {
						cout << "Логин: " << mainadmins[i].getLogin() << endl;
						cout << "Пароль: " << mainadmins[i].getPass() << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}else
					if (choose1 == 1) {
						for (int i = 0; i < nAdmins; i++) {
							cout << "Логин: " << admins[i].getLogin() << endl;
							cout << "Пароль: " << admins[i].getPass() << endl;
							cout << endl;
						}
						system("pause");
						system("cls");
					}else
						if (choose1 == 2) {
							for (int i = 0; i < nUsers; i++) {
								cout << "Логин: " << users[i].getLogin() << endl;
								cout << "Пароль: " << users[i].getPass() << endl;
								cout << endl;
							}
							system("pause");
							system("cls");
						}
			}
		}else
			if (choose == 1) {
				while (true) {
					int choose1 = chooseRole();
					if (choose1 == 3) break;
					if (choose1 == 0) {
						while (true) {
							int choose2 = chooseMainAdmins(mainadmins, nMainAdmins);
							if (choose2 == nMainAdmins) break;
							openRedMenuMainAdmin(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers, choose2);
						}
					}
					else
						if (choose1 == 1) {
							while (true) {
								int choose2 = chooseAdmins(admins, nAdmins);
								if (choose2 == nAdmins) break;
								openRedMenuAdmin(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers, choose2);
							}
						}
						else
							if (choose1 == 2) {
								while (true) {
									int choose2 = chooseUsers(users, nUsers);
									if (choose2 == nUsers) break;
									openRedMenuUser(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers, choose2);
								}
							}
				}
				fillFiles(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
			}else
				if (choose == 2) {
					string log, pass, s;
					s = writeLoginAndPass(log, pass, "Зарегестрировать");
					if (s == "-1") continue;
					int check = 0;
					for (int i = 0; i < nMainAdmins; i++)
						if (s == mainadmins[i].getLogin() && i != choose) {
							check = 1;
							break;
						}
					for (int i = 0; i < nAdmins; i++)
						if (s == admins[i].getLogin()) {
							check = 1;
							break;
						}
					for (int i = 0; i < nUsers; i++)
						if (s == users[i].getLogin()) {
							check = 1;
							break;
						}
					if (s == "ilya") check = 1;
					if (check == 1) cout << "Так логин уже существует!!!" << endl;
					else { 
						cout << "Аккаунт создан" << endl;
						changeSizeUsers(users, nUsers);
						users[nUsers - 1].changeLogin(log);
						users[nUsers - 1].changePass(pass);
					}
					system("pause");
					system("cls");
					fillFiles(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
				}
				else
					if (choose == 3) {
						openMenuUser(users, nUsers);
						fillFiles(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
					}
					else
						if (choose == 4) return 3;
						else return 4;
	}
	return 0;
}

int openAdminMenu(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers) {
	while (true) {
		int choose = chooseAdminMenu();
		if (choose == 0) {
			while (true) {
				int choose1 = chooseRole();
				if (choose1 == 3) break;
				if (choose1 == 0) {
					for (int i = 0; i < nMainAdmins; i++) {
						mainadmins[i].showInforamtion();
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose1 == 1) {
						for (int i = 0; i < nAdmins; i++) {
							admins[i].showInforamtion();
							cout << endl;
						}
						system("pause");
						system("cls");
					}
					else
						if (choose1 == 2) {
							for (int i = 0; i < nUsers; i++) {
								cout << " Имя: " << users[i].getName() << endl;
								cout << " Фамилия: " << users[i].getS_Name() << endl;
								cout << " Отчество: " << users[i].getT_Name() << endl;
								cout << " Статус: " << users[i].getPost() << endl;
								cout << endl;
							}
							system("pause");
							system("cls");
						}
			}
		}
		else
			if (choose == 1) {
				openMenuUser(users, nUsers);
				fillFiles(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
			}
			else
				if (choose == 2) return 3;
				else return 4;
	}
	return 0;
}

int openUserMenu(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers, int ch) {
	while (true) {
		int choose = chooseUserMenu();
		if (choose == 0) {
			while (true) {
				int choose1 = chooseRole();
				if (choose1 == 3) break;
				if (choose1 == 0) {
					for (int i = 0; i < nMainAdmins; i++) {
						mainadmins[i].showInforamtion();
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose1 == 1) {
						for (int i = 0; i < nAdmins; i++) {
							admins[i].showInforamtion();
							cout << endl;
						}
						system("pause");
						system("cls");
					}
					else
						if (choose1 == 2) {
							for (int i = 0; i < nUsers; i++) {
								cout << " Имя: " << users[i].getName() << endl;
								cout << " Фамилия: " << users[i].getS_Name() << endl;
								cout << " Отчество: " << users[i].getT_Name() << endl;
								cout << " Статус: " << users[i].getPost() << endl;
								cout << endl;
							}
							system("pause");
							system("cls");
						}
			}
		}
		else
			if (choose == 1) {
				users[ch].showInforamtion();
				cout << endl;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) return 3;
				else return 4;
	}
	return 0;
}

void openRedMenuMainAdmin(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers, int& choose) {
	while (true) {
		int choose1 = chooseWhatRedMainAdmin(mainadmins, choose);
		if (choose1 == 0) {
			cout << "Введите логин: ";
			string s = writeEngWords();
			int check = 0;
			for (int i = 0; i < nMainAdmins; i++)
				if (s == mainadmins[i].getLogin() && i != choose) {
					check = 1;
					break;
				}
			for (int i = 0; i < nAdmins; i++)
				if (s == admins[i].getLogin()) {
					check = 1;
					break;
				}
			for (int i = 0; i < nUsers; i++)
				if (s == users[i].getLogin()) {
					check = 1;
					break;
				}
			if (s == "ilya") check = 1;
			if (check == 1) cout << "Так логин уже существует!!!" << endl;
			else { cout << "Логин изменен" << endl; mainadmins[choose].changeLogin(s); }
			system("pause");
			system("cls");
		}else
			if (choose1 == 1) {
				cout << "Введите пароль: ";
				string s = writeEngWords();
				cout << "Пароль изменен" << endl;
				mainadmins[choose].changePass(s);
				system("pause");
				system("cls");
			}else
				if (choose1 == 2) {
					cout << "Введите имя: ";
					string s = writeRusWords();
					cout << "Имя изменено" << endl;
					mainadmins[choose].changeName(s);
					system("pause");
					system("cls");
				}else
					if (choose1 == 3) {
						cout << "Введите фамилию: ";
						string s = writeRusWords();
						cout << "Фамилия изменена" << endl;
						mainadmins[choose].changeSName(s);
						system("pause");
						system("cls");
					}
					else
						if (choose1 == 4) {
							cout << "Введите звание: ";
							string s = writeRusWords();
							cout << "Звание изменено" << endl;
							mainadmins[choose].changeRank(s);
							system("pause");
							system("cls");
						}
						else break;
	}
}

void openRedMenuAdmin(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers, int& choose) {
	while (true) {
		int choose1 = chooseWhatRedAdmin(admins, choose);
		if (choose1 == 0) {
			cout << "Введите логин: ";
			string s = writeEngWords();
			int check = 0;
			for (int i = 0; i < nMainAdmins; i++)
				if (s == mainadmins[i].getLogin() && i != choose) {
					check = 1;
					break;
				}
			for (int i = 0; i < nAdmins; i++)
				if (s == admins[i].getLogin()) {
					check = 1;
					break;
				}
			for (int i = 0; i < nUsers; i++)
				if (s == users[i].getLogin()) {
					check = 1;
					break;
				}
			if (s == "ilya") check = 1;
			if (check == 1) cout << "Так логин уже существует!!!" << endl;
			else { cout << "Логин изменен" << endl; admins[choose].changeLogin(s); }
			system("pause");
			system("cls");
		}
		else
			if (choose1 == 1) {
				cout << "Введите пароль: ";
				string s = writeEngWords();
				cout << "Пароль изменен" << endl;
				admins[choose].changePass(s);
				system("pause");
				system("cls");
			}
			else
				if (choose1 == 2) {
					cout << "Введите имя: ";
					string s = writeRusWords();
					cout << "Имя изменено" << endl;
					admins[choose].changeName(s);
					system("pause");
					system("cls");
				}
				else
					if (choose1 == 3) {
						cout << "Введите фамилию: ";
						string s = writeRusWords();
						cout << "Фамилия изменена" << endl;
						admins[choose].changeSName(s);
						system("pause");
						system("cls");
					}
					else
						if (choose1 == 4) {
							cout << "Введите должность: ";
							string s = writeRusWords();
							cout << "Должность изменена" << endl;
							admins[choose].changePosition(s);
							system("pause");
							system("cls");
						}
						else 
							if (choose1 == 5) {
								int choose2 = chooseRole();
								if (choose2 == 1 || choose2 == 3) continue;
								else
									if (choose2 == 0) {
										changeSizeMainAdmins(mainadmins, nMainAdmins);
										mainadmins[nMainAdmins - 1].changeLogin(admins[choose].getLogin());
										mainadmins[nMainAdmins - 1].changePass(admins[choose].getPass());
										for (int i = choose; i < nAdmins - 1; i++)
											admins[i] = admins[i + 1];
										nAdmins--;
										break;
									}
									else
										if (choose2 == 2) {
											changeSizeUsers(users, nUsers);
											users[nUsers - 1].changeLogin(admins[choose].getLogin());
											users[nUsers - 1].changePass(admins[choose].getPass());
											for (int i = choose; i < nAdmins - 1; i++)
												admins[i] = admins[i + 1];
											nAdmins--;
											break;
										}
							}
							else break;
	}
}

void openRedMenuUser(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers, int& choose) {
	while (true) {
		int choose1 = chooseWhatRedUser(users, choose);
		if (choose1 == 0) {
			cout << "Введите логин: ";
			string s = writeEngWords();
			int check = 0;
			for (int i = 0; i < nMainAdmins; i++)
				if (s == mainadmins[i].getLogin() && i != choose) {
					check = 1;
					break;
				}
			for (int i = 0; i < nAdmins; i++)
				if (s == admins[i].getLogin()) {
					check = 1;
					break;
				}
			for (int i = 0; i < nUsers; i++)
				if (s == users[i].getLogin()) {
					check = 1;
					break;
				}
			if (s == "ilya") check = 1;
			if (check == 1) cout << "Так логин уже существует!!!" << endl;
			else { cout << "Логин изменен" << endl; users[choose].changeLogin(s); }
			system("pause");
			system("cls");
		}
		else
			if (choose1 == 1) {
				cout << "Введите пароль: ";
				string s = writeEngWords();
				cout << "Пароль изменен" << endl;
				users[choose].changePass(s);
				system("pause");
				system("cls");
			}
			else
				if (choose1 == 2) {
					users[choose].changeName();
				}
				else
					if (choose1 == 3) {
						users[choose].changeS_Name();
					}
					else
						if (choose1 == 4) {
							users[choose].changeT_Name();
						}
						else 
							if (choose1 == 5) {
								int choose2 = chooseRole();
								if (choose2 == 2 || choose2 == 3) continue;
								else
									if (choose2 == 0) {
										changeSizeMainAdmins(mainadmins, nMainAdmins);
										mainadmins[nMainAdmins - 1].changeLogin(users[choose].getLogin());
										mainadmins[nMainAdmins - 1].changePass(users[choose].getPass());
										for (int i = choose; i < nUsers - 1; i++)
											users[i] = users[i + 1];
										nUsers--;
										break;
									}else
										if (choose2 == 1) {
											changeSizeAdmins(admins, nAdmins);
											admins[nAdmins - 1].changeLogin(users[choose].getLogin());
											admins[nAdmins - 1].changePass(users[choose].getPass());
											for (int i = choose; i < nUsers - 1; i++)
												users[i] = users[i + 1];
											nUsers--;
											break;
										}
							}
							else break;
	}
}

void openMenuUser(User*& users, int& nUsers) {
	while (true) {
		int choose = chooseMenuUser();
		if (choose == 0) {
			for (int i = 0; i < nUsers; i++) {
				users[i].showInforamtion();
				cout << endl;
			}
			system("pause");
			system("cls");
		}else
			if (choose == 1) {
				while (true) {
					int choose1 = chooseUsers(users, nUsers);
					if (choose1 == nUsers) break;
					while (true) {
						int choose2 = chooseWhatRedSolider(users, choose1);
						if (choose2 == 0) {
							users[choose1].changeName();
						}else
							if (choose2 == 1) {
								users[choose1].changeS_Name();
							}else
								if (choose2 == 2) {
									users[choose1].changeT_Name();
								}else
									if (choose2 == 3) {
										users[choose1].changeBornDate();
									}else
										if (choose2 == 4) {
											users[choose1].changePhoneNumber();
										}else
											if (choose2 == 5) {
												users[choose1].changeAdress();
											}else
												if (choose2 == 6) {
													users[choose1].changeUnit();
												}else
													if (choose2 == 7) {
														users[choose1].changePost();
													}else
														if (choose2 == 8) {
															openMenuRedDoc(users, choose1);
														}
														else
															break;
					}
				}
			}else
				if (choose == 2) {
					while (true) {
						int choose1 = chooseHowSearch();
						if (choose1 == 0) {
							cout << "Введите логин по которому искать: ";
							string s = writeEngWords();
							cout << endl;
							int check = 0;
							for (int i = 0; i < nUsers; i++) {
								string s1 = users[i].getLogin();
								if (s.length() <= s1.length()) {
									int check_string = -1;
									for (int j = 0; j < s.length(); j++)
										if (s[j] != tolower(s1[j]) && s[j] != toupper(s1[j])) { check_string = 0; break; }
									if (check_string == -1) {
										users[i].showInforamtion();
										cout << endl;
										check = 1;
									}
								}
							}
							if (check == 0) cout << "Пользователей с таким логином нет!" << endl;
							system("pause");
							system("cls");
						}else
							if (choose1 == 1) {
								cout << "Введите фамилию по которой искать: ";
								string s = writeRusWords();
								cout << endl;
								int check = 0;
								for (int i = 0; i < nUsers; i++) {
									string s1 = users[i].getS_Name();
									if (s.length() <= s1.length()) {
										int check_string = -1;
										for (int j = 0; j < s.length(); j++)
											if (s[j] != s1[j]) {
												check_string = 0; 
												break; 
											}
										if (check_string == -1) {
											users[i].showInforamtion();
											cout << endl;
											check = 1;
										}
									}
								}
								if (check == 0) cout << "Пользователей с такой фамилией нет!" << endl;
								system("pause");
								system("cls");
							}else
								if (choose1 == 2) {
									cout << "Введите год по которому искать: ";
									string year = to_string(writeDate(2020, 4));
									cout << endl;
									for (int i = 0; i < nUsers; i++) {
										string s = users[i].getBornDate();
										if (year[0] == s[s.length() - 4] && year[1] == s[s.length() - 3] && year[2] == s[s.length() - 2] && year[3] == s[s.length() - 1]) {
											users[i].showInforamtion();
											cout << endl;
										}
									}
									system("pause");
									system("cls");
								}
								else
									break;
					}
				}
				else
					if (choose == 3) {
						while (true) {
							int choose1 = chooseHowSort();
							if (choose1 == 2) break;
							int choose2 = chooseUpOrDown();
							if (choose1 == 1) {
								for (int i = 0; i < nUsers; i++)
									for (int j = 0; j < nUsers - 1; i++) {
										if (choose2 == 0 && users[j].getS_Name() > users[j + 1].getS_Name()) {
											User us;
											us = users[j];
											users[j] = users[j + 1];
											users[j + 1] = us;
										}
										else
											if (choose2 == 1 && users[j].getS_Name() < users[j + 1].getS_Name()) {
												User us;
												us = users[j];
												users[j] = users[j + 1];
												users[j + 1] = us;
											}
									}
							}
							else
								if (choose1 == 0) {
									for (int i = 0; i < nUsers; i++)
										for (int j = 0; j < nUsers - 1; i++) {
											if (choose2 == 0 && users[j].getLogin() > users[j + 1].getLogin()) {
												User us;
												us = users[j];
												users[j] = users[j + 1];
												users[j + 1] = us;
											}
											else
												if (choose2 == 1 && users[j].getLogin() < users[j + 1].getLogin()) {
													User us;
													us = users[j];
													users[j] = users[j + 1];
													users[j + 1] = us;
												}
										}
								}
						}
					}
					else break;
	}
}

void openMenuRedDoc(User*& users, int& choose) {
	while (true) {
		int choose1 = chooseDoc(users, choose);
		if (choose1 == 7) break;
		users[choose].setGodDoc(choose1, godOrNot());
	}
}