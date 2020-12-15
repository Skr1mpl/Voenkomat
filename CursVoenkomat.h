#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <functional>
#include <ctime>
#include <time.h>

using namespace std;

int writeDate(int, int);
string writePhoneNumber();
string writeRusWords();
string writeAdress();
string choosePost();

class Roles {
protected:
	string login, password;
public:
	Roles() {};
	Roles(string log, string pass) {
		login = log;
		password = pass;
	}
	virtual string getPass() = 0;
	virtual string getLogin() = 0;
	virtual void changePass(string) = 0;
	virtual void changeLogin(string) = 0;
	virtual void showInforamtion() = 0;
};

class RoleFunc:public Roles {
public:
	RoleFunc() {};
	RoleFunc(string tmp, string tmp1) :Roles(tmp, tmp1) {
	}
	string getPass() {
		return password;
	}
	string getLogin() {
		return login;
	}
	void changePass(string tmp) {
		password = tmp;
	}
	void changeLogin(string tmp) {
		login = tmp;
	}
};

class MainAdmin:public RoleFunc {
private:
	string name;
	string s_name;
	string rank;
public:
	MainAdmin() {
		name = "Нет данных";
		s_name = "Нет данных";
		rank = "Нет данных";
	};
	MainAdmin(string tmp, string tmp1, string tmp2, string tmp3, string tmp4) :RoleFunc(tmp, tmp1) {
		name = tmp2;
		s_name = tmp3;
		rank = tmp4;
	}
	void showInforamtion() {
		cout << " Имя: " << name << endl;
		cout << " Фамилия: " << s_name << endl;
		cout << " Звание: " << rank << endl;
	}
	string getName() {
		return name;
	}
	string getSName() {
		return s_name;
	}
	string getRank() {
		return rank;
	}
	void changeName(string tmp) {
		name = tmp;
	}
	void changeSName(string tmp) {
		s_name = tmp;
	}
	void changeRank(string tmp) {
		rank = tmp;
	}
};

class Admin:public RoleFunc {
private:
	string name;
	string s_name;
	string position;
public:
	Admin() {
		name = "Нет данных";
		s_name = "Нет данных";
		position = "Нет данных";
	}
	Admin(string tmp, string tmp1, string tmp2, string tmp3, string tmp4) :RoleFunc(tmp, tmp1) {
		name = tmp2;
		s_name = tmp3;
		position = tmp4;
	}
	void showInforamtion() {
		cout << " Имя: " << name << endl;
		cout << " Фамилия: " << s_name << endl;
		cout << " Должность: " << position << endl;
	}
	string getName() {
		return name;
	}
	string getSName() {
		return s_name;
	}
	string getPosition() {
		return position;
	}
	void changeName(string tmp) {
		name = tmp;
	}
	void changeSName(string tmp) {
		s_name = tmp;
	}
	void changePosition(string tmp) {
		position = tmp;
	}
};

class Solider {
private:
	int* mas = new int[7];
	string goden;
	string unit;
	string post;
public:
	Solider() {
		goden = "Годен";
		unit = "Нет данных";
		post = "Призывник";
		for (int i = 0; i < 7; i++)
			mas[i] = 0;
	};
	~Solider() {
		delete[]mas;
	}
	int getGodDoc(int i) {
		return mas[i];
	}
	string getGoden() {
		return goden;
	}
	string getPost() {
		return post;
	}
	string getUnit() {
		return unit;
	}
	void setGoden(string tmp) {
		goden = tmp;
	}
	void setUnit(string tmp) {
		unit = tmp;
	}
	void setPost(string tmp) {
		post = tmp;
	}
	void setGodDoc(int i, int a) {
		mas[i] = a;
		int check = 0;
		for (int i = 0; i < 7; i++)
			if (mas[i] == 1) {
				goden = "Не годен"; check = 1; break;
			}
		if (check == 0) goden = "Годен";
	}
	void changeUnit() {
		cout << "Введите военскую часть: ";
		unit = writeAdress();
		system("cls");
	}
	void changePost() {
		post = choosePost();
	}
	void show() {
		cout << "	Заключения врачей." << endl;
		string s;
		if (mas[0] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Терапевт: " << s << endl;
		if (mas[1] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Хирург: " << s << endl;
		if (mas[2] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Невропатолог: " << s << endl;
		if (mas[3] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Психиатр: " << s << endl;
		if (mas[4] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Окулист: " << s << endl;
		if (mas[5] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Оториноларинголог: " << s << endl;
		if (mas[6] == 0) s = "Годен";
		else s = "Не годен";
		cout << "  Стоматолог: " << s << endl;
		cout << " Итоговое обследование: " << goden << endl;
		cout << " Часть: " << unit << endl;
	}
};

class User :public RoleFunc, virtual public Solider {
private:
	string name;
	string s_name;
	string t_name;
	string born_date;
	string phone_number;
	string adress;
public:
	User() {
		name = "Нет данных";
		s_name = "Нет данных";
		t_name = "Нет данных";
		born_date = "Нет данных";
		phone_number = "Нет данных";
		adress = "Нет данных";
	}
	void showInforamtion() {
		cout << "	Логин: " << login << endl;
		cout << " Ф.И.О.: " << name << " " << s_name << " " << t_name << endl;
		cout << " Дата рождения: " << born_date << endl;
		cout << " Номер телефона: " << phone_number << endl;
		cout << " Адресс проживания: " << adress << endl;
		Solider::show();
	}
	string getName() {
		return name;
	}
	string getS_Name() {
		return s_name;
	}
	string getT_Name() {
		return t_name;
	}
	string getPhoneNumber() {
		return phone_number;
	}
	string getAdress() {
		return adress;
	}
	void setName(string tmp) {
		name = tmp;
	}
	void setSName(string tmp) {
		s_name = tmp;
	}
	void setTName(string tmp) {
		t_name = tmp;
	}
	void setBornDate(string tmp) {
		born_date = tmp;
	}
	void setPhone(string tmp) {
		phone_number = tmp;
	}
	void setAdress(string tmp) {
		adress = tmp;
	}
	void changeName() {
		cout << "Введите имя: ";
		name = writeRusWords();
		system("cls");
	}
	void changeS_Name() {
		cout << "Введите фамилию: ";
		s_name = writeRusWords();
		system("cls");
	}
	void changeT_Name() {
		cout << "Введите отчество: ";
		t_name = writeRusWords();
		system("cls");
	}
	void changePhoneNumber() {
		cout << "Введите номер телефона: +375(";
		phone_number = writePhoneNumber();
		system("cls");
	}
	string getBornDate() {
		return born_date;
	}
	void changeBornDate() {
		cout << "Введите год рождения: ";
		int year = writeDate(2020, 4);
		cout << endl;
		cout << "Введите месяц рождения: ";
		int month = writeDate(12, 2);
		cout << endl;
		int d;
		if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
			d = 31;
		}
		else
			if (month == 1) {
				if ((year % 4 == 0) && (year % 100 == 0)) {
					d = 29;
				}
				else
					d = 28;
			}
			else
				d = 30;
		cout << "Введите день рождения: ";
		int day = writeDate(d, 2);
		cout << endl;
		born_date = to_string(day) + "." + to_string(month) + "." + to_string(year);
		system("cls");
	}
	void changeAdress() {
		cout << "Введите адрес проживания: " << endl;
		adress = writeAdress();
		system("cls");
	}
};
