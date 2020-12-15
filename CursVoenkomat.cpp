#include "CursVoenkomat.h"
#include "Files.h"
#include "Checks.h"
#include "ShowMenu.h"
#include "FuncMenu.h"

int main() {
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string login = "ilya", password = "12345ilya";
	createFiles();
    int nMainAdmins = 0;
    int nAdmins = 0;
    int nUsers = 0;
    fillSize(nMainAdmins, nAdmins, nUsers);
    MainAdmin* mainadmins = new MainAdmin[nMainAdmins];
    Admin* admins = new Admin[nAdmins];
    User* users = new User[nUsers];
    fillClasses(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
    while (true) {
        int choose = chooseMainMenu();
        if (choose == 0) {
            string log, pass;
            int check = 0;
            string s = writeLoginAndPass(log, pass, "Вход");
            if (s == "-1") continue;
            if (log == login && pass == password) {
                check = openMainAdminMenu(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
            }
            for(int i = 0 ; i < nMainAdmins; i++)
                if(log == mainadmins[i].getLogin() && pass == mainadmins[i].getPass()){
                    check = openMainAdminMenu(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
                    break;
                }
            for (int i = 0; i < nAdmins; i++)
                if (log == admins[i].getLogin() && pass == admins[i].getPass()) {
                    check = openAdminMenu(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
                    break;
                }
            for (int i = 0; i < nUsers; i++)
                if (log == users[i].getLogin() && pass == users[i].getPass()) {
                    check = openUserMenu(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers, i);
                    break;
                }
            if (check == 4) break;
            else
                if (check == 3) continue;
            cout << "Вы ввели неверный логин или пароль." << endl;
            system("pause");
            system("cls");
        }
        else
            if (choose == 1) {
                string log, pass;
                int check = 0;
                string s = writeLoginAndPass(log, pass, "Регистрация");
                if (log == login) {
                    check = 1;
                }
                for (int i = 0; i < nMainAdmins; i++)
                    if (log == mainadmins[i].getLogin()) {
                        check = 1;
                        break;
                    }
                for (int i = 0; i < nAdmins; i++)
                    if (log == admins[i].getLogin()) {
                        check = 1;
                        break;
                    }
                for (int i = 0; i < nUsers; i++)
                    if (log == users[i].getLogin()) {
                        check = 1;
                        break;
                    }
                if (check == 1) {
                    cout << "Такой логин уже существует." << endl;
                    system("pause");
                    system("cls");
                    continue;
                }
                User user;
                user.changeLogin(log);
                user.changePass(pass);
                changeSizeUsers(users, nUsers);
                users[nUsers - 1] = user;
            }
            else
                break;
    }
    fillFiles(mainadmins, admins, users, nMainAdmins, nAdmins, nUsers);
}

int writeDate(int ch, int siz) {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                }
            }
            else
                if (key == 13 && str.length() <= siz && stoi(str) <= ch && str.length() != 0) break;
                else
                    if (key >= '0' && key <= '9' && str.length() < siz) {
                        str = str + (char)key;
                        cout << (char)key;
                    }
    }
    return stoi(str);
}

string writePhoneNumber() {
    string str;
    while (true) {
        int key;
        key = _getch();
        if (key == 224) {
            key = _getch();
        }
        else
            if (key == 8) {
                if (str.length() != 0) {
                    cout << '\b' << " " << '\b';
                    str.erase(str.length() - 1);
                    if (str.length() == 1) cout << '\b' << " " << '\b';
                }
            }
            else
                if (key == 13 && str.length() == 9) break;
                else
                    if (key >= '0' && key <= '9' && str.length() < 9) {
                        str = str + (char)key;
                        cout << (char)key;
                        if (str.length() == 2) cout << ")";
                    }
    }
    return str;
}

string writeRusWords() {
    string word;
    int Knopka;
    char symbol;
    while (true) {
        Knopka = _getch();
        if (Knopka == 8) {
            if (word.length() != 0) {
                cout << '\b' << " " << '\b';
                word.erase(word.length() - 1);
            }
        }
        else
            if (Knopka == 13 && word.length() != 0) break;
            else {
                symbol = (char)Knopka;
                if ((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я')) {
                    word = word + symbol;
                    cout << symbol;
                }
            }
    }
    cout << endl;
    return word;
}

string writeAdress() {
    string word;
    int Knopka;
    char symbol;
    while (true) {
        Knopka = _getch();
        if (Knopka == 8) {
            if (word.length() != 0) {
                cout << '\b' << " " << '\b';
                word.erase(word.length() - 1);
            }
        }
        else
            if (Knopka == 13 && word.length() != 0) break;
            else {
                symbol = (char)Knopka;
                if ((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я') || (symbol >= '0' && symbol <= '9') || (symbol == ' ' && word.length() != 0) || symbol == '№') {
                    word = word + symbol;
                    cout << symbol;
                }
            }
    }
    cout << endl;
    return word;
}

string choosePost() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> Призывник " << endl; setColor(15, 0); }
        else cout << " Призывник " << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Солдат " << endl; setColor(15, 0); }
        else cout << " Солдат " << endl;

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) {
            system("cls");
            if (choose_menu == 0) return "Призывник";
            else
                if (choose_menu == 1) return "Солдат";
        }
        system("cls");
    }
}