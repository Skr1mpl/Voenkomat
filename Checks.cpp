#include "Checks.h"

void setColor(int text, int background) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

string encryptPass(string pass) {
	string encrypt;
	for (int i = 0; i < pass.length(); i++) {
		char c = pass[i];
		c = c + '*' + ')';
		encrypt.push_back(c);
	}
	return encrypt;
}

string deencryptPass(string encrypt) {
	string deencrypt;
	for (int i = 0; i < encrypt.length(); i++) {
		char c = encrypt[i];
		c = c - '*' - ')';
		deencrypt.push_back(c);
	}
	return deencrypt;
}

string writeLoginAndPass(string& login, string& password, string reg_or_signin) {
    int schet = 0;
    string password1 = "";
    writeRegOrLog(0, login, password1, reg_or_signin);
    while (true) {
        int keyboard_button;
        char symbol;
        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if ((keyboard_button == 80 && schet == 2)) {
                writeRegOrLog(3, login, password1, reg_or_signin);
                while (true) {
                    keyboard_button = _getch();
                    if (keyboard_button == 224) {
                        keyboard_button = _getch();
                        if (keyboard_button == 72) {
                            writeRegOrLog(1, login, password1, reg_or_signin);
                            break;
                        }
                    }
                    else
                        if (keyboard_button == 13) {
                            login = "-1";
                            password = "-1";
                            system("cls");
                            return "-1";
                        }
                }
            }
            else
                if (keyboard_button == 80 && schet == 0) {
                    writeRegOrLog(1, login, password1, reg_or_signin);
                    schet = 1;
                }
                else
                    if (keyboard_button == 72 && schet == 1) {
                        writeRegOrLog(0, login, password1, reg_or_signin);
                        schet = 0;
                    }
                    else
                        if ((keyboard_button == 80 && schet == 1) || (keyboard_button == 72 && schet == 3)) {
                            writeRegOrLog(2, login, password1, reg_or_signin);
                            schet = 2;
                            while (true) {
                                keyboard_button = _getch();
                                if (keyboard_button == 13) {
                                    system("cls");
                                    return "1";
                                }
                                else
                                    if (keyboard_button == 224) {
                                        keyboard_button = _getch();
                                        if (keyboard_button == 72) { writeRegOrLog(1, login, password1, reg_or_signin); schet = 1; break; }
                                        else
                                            if (keyboard_button == 80) { writeRegOrLog(3, login, password1, reg_or_signin); schet = 3; break; }
                                    }
                            }
                        }
        }
        else
            if ((keyboard_button == 8 && login.length() > 0 && schet == 0) || (keyboard_button == 8 && password.length() > 0 && schet == 1)) {
                system("cls");
                if (schet == 0 && login.length() != 0) {
                    login.erase(login.length() - 1);
                    writeRegOrLog(0, login, password1, reg_or_signin);
                }
                else
                    if (schet == 1 && password.length() != 0) {
                        password.erase(password.length() - 1);
                        password1.erase(password1.length() - 1);
                        writeRegOrLog(1, login, password1, reg_or_signin);
                    }
            }
            else
                if (keyboard_button == 13 && schet == 3) { system("cls"); return "-1"; }
                else
                    if (keyboard_button == 13 && schet == 2) { system("cls"); return "1"; }
                    else
                        if (schet != 3 && schet != 2)
                            if ((keyboard_button >= 'a' && keyboard_button <= 'z') || (keyboard_button >= 'A' && keyboard_button <= 'Z') || (keyboard_button >= '0' && keyboard_button <= '9')) {
                                if (schet == 0) {
                                    symbol = (char)keyboard_button;
                                    login = login + symbol;
                                    writeRegOrLog(0, login, password1, reg_or_signin);
                                }
                                else {
                                    symbol = (char)keyboard_button;
                                    password = password + symbol;
                                    password1 = password1 + "*";
                                    writeRegOrLog(1, login, password1, reg_or_signin);
                                }
                            }
    }
}

void writeRegOrLog(int n, string login, string password, string reg_or_signin) {
    system("cls");
    if (n == 0) {
        cout << "Выберите стрелочками что вводить или выйти" << endl;
        setColor(2, 0);
        cout << " -> Введите Логин: " << login << endl;
        setColor(15, 0);
        cout << "Введите Пароль: " << password << endl;
        cout << reg_or_signin << endl;
        cout << "Выход в главное меню" << endl;
    }
    else
        if (n == 1) {
            cout << "Выберите стрелочками что вводить или выйти" << endl;
            cout << "Введите Логин: " << login << endl;
            setColor(2, 0);
            cout << " -> Введите Пароль: " << password << endl;
            setColor(15, 0);
            cout << reg_or_signin << endl;
            cout << "Выход в главное меню" << endl;
        }
        else
            if (n == 2) {
                cout << "Выберите стрелочками что вводить или выйти" << endl;
                cout << "Введите Логин: " << login << endl;
                cout << "Введите Пароль: " << password << endl;
                setColor(2, 0);
                cout << " -> " << reg_or_signin << endl;
                setColor(15, 0);
                cout << "Выход в главное меню" << endl;
            }
            else
                if (n == 3) {
                    cout << "Выберите стрелочками что вводить или выйти" << endl;
                    cout << "Введите Логин: " << login << endl;
                    cout << "Введите Пароль: " << password << endl;
                    cout << reg_or_signin << endl;
                    setColor(2, 0);
                    cout << " -> Выход в главное меню" << endl;
                    setColor(15, 0);
                }
}

string writeEngWords() {
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
                if (key == 13 && str.length() != 0) break;
                else
                    if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')) {
                        str = str + (char)key;
                        cout << (char)key;
                    }
    }
    return str;
}

int godOrNot() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 2) % 2;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Годен" << endl; setColor(15, 0); }
        else cout << " Годен" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Не годен" << endl; setColor(15, 0); }
        else cout << " Не годен" << endl;

        keyboard_button = _getch();
        if (keyboard_button == 224) {
            keyboard_button = _getch();
            if (keyboard_button == 72) choose_menu--;
            if (keyboard_button == 80) choose_menu++;
        }
        if (keyboard_button == 13) { system("cls"); return choose_menu; }
        system("cls");
    }
}
