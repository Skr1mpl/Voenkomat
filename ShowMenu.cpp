#include "ShowMenu.h"

int chooseMainMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 3) % 3;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> ����� � �������" << endl; setColor(15, 0); }
        else cout << " ����� � �������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ������� ����� �������" << endl; setColor(15, 0); }
        else cout << " ������� ����� �������" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int chooseMainAdminMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "   ����������� ������� �������������!" << endl;
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 6) % 6;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> �������� ���������� ���� ���������" << endl; setColor(15, 0); }
        else cout << " �������� ���������� ���� ���������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ������������� ��������" << endl; setColor(15, 0); }
        else cout << " ������������� ��������" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ���������� ��������" << endl; setColor(15, 0); }
        else { cout << " ���������� ��������" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> ���� �����������/��������" << endl; setColor(15, 0); }
        else { cout << " ���� �����������/��������" << endl; }

        if (choose_menu == 4) { setColor(2, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 5) { setColor(2, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int chooseRole() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 4) % 4;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> ������� ���������������" << endl; setColor(15, 0); }
        else cout << " ������� ���������������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ���������������" << endl; setColor(15, 0); }
        else cout << " ���������������" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> �������������" << endl; setColor(15, 0); }
        else { cout << " �������������" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> ��������� �����" << endl; setColor(15, 0); }
        else { cout << " ��������� �����" << endl; }

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

int chooseMainAdmins(MainAdmin*& mainadmins, int& nMainAdmins) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� �������� ��������������" << endl;
        choose_menu = (choose_menu + (nMainAdmins + 1)) % (nMainAdmins + 1);

        for (int i = 0; i < nMainAdmins; i++)
            if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << mainadmins[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << mainadmins[i].getLogin() << endl; }

        if (choose_menu == nMainAdmins) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseWhatRedMainAdmin(MainAdmin*& mainadmins, int& choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ��� �������������" << endl;
        choose_menu = (choose_menu + 6) % 6;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> �����: " << mainadmins[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " �����: " << mainadmins[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ������: " << mainadmins[choose].getPass() << endl; setColor(15, 0); }
        else cout << " ������: " << mainadmins[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ���: " << mainadmins[choose].getName() << endl; setColor(15, 0); }
        else cout << " ���: " << mainadmins[choose].getName() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> �������: " << mainadmins[choose].getSName() << endl; setColor(15, 0); }
        else cout << " �������: " << mainadmins[choose].getSName() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> ������: " << mainadmins[choose].getRank() << endl; setColor(15, 0); }
        else cout << " ������: " << mainadmins[choose].getRank() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseAdmins(Admin*& admins, int& nAdmins) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ��������������" << endl;
        choose_menu = (choose_menu + (nAdmins + 1)) % (nAdmins + 1);

        for (int i = 0; i < nAdmins; i++)
            if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << admins[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << admins[i].getLogin() << endl; }

        if (choose_menu == nAdmins) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseWhatRedAdmin(Admin*& admin, int& choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ��� �������������" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> �����: " << admin[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " �����: " << admin[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ������: " << admin[choose].getPass() << endl; setColor(15, 0); }
        else cout << " ������: " << admin[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ���: " << admin[choose].getName() << endl; setColor(15, 0); }
        else cout << " ���: " << admin[choose].getName() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> �������: " << admin[choose].getSName() << endl; setColor(15, 0); }
        else cout << " �������: " << admin[choose].getSName() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> ���������: " << admin[choose].getPosition() << endl; setColor(15, 0); }
        else cout << " ���������: " << admin[choose].getPosition() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> �����: �����" << endl; setColor(15, 0); }
        else cout << " �����: �����" << endl;

        if (choose_menu == 6) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseUsers(User*& users, int& nUsers) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ������������" << endl;
        choose_menu = (choose_menu + (nUsers + 1)) % (nUsers + 1);

        for (int i = 0; i < nUsers; i++)
            if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << users[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << users[i].getLogin() << endl; }

        if (choose_menu == nUsers) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseWhatRedUser(User*& users, int& choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ��� �������������" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> �����: " << users[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " �����: " << users[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ������: " << users[choose].getPass() << endl; setColor(15, 0); }
        else cout << " ������: " << users[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ���: " << users[choose].getName() << endl; setColor(15, 0); }
        else cout << " ���: " << users[choose].getName() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> �������: " << users[choose].getS_Name() << endl; setColor(15, 0); }
        else cout << " �������: " << users[choose].getS_Name() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> ��������: " << users[choose].getT_Name() << endl; setColor(15, 0); }
        else cout << " ��������: " << users[choose].getT_Name() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> �����: ������������" << endl; setColor(15, 0); }
        else cout << " �����: ������������" << endl;

        if (choose_menu == 6) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseMenuUser() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 5) % 5;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> �������� ���� ����������" << endl; setColor(15, 0); }
        else cout << " �������� ���� ����������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ������������� ����������" << endl; setColor(15, 0); }
        else cout << " ������������� ����������" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ����� ����������" << endl; setColor(15, 0); }
        else { cout << " ����� ����������" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> ������������� ����������" << endl; setColor(15, 0); }
        else { cout << " ������������� ����������" << endl; }

        if (choose_menu == 4) { setColor(2, 0); cout << " -> ��������� �����" << endl; setColor(15, 0); }
        else { cout << " ��������� �����" << endl; }

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

int chooseWhatRedSolider(User*& users, int& choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� ��� �������������" << endl;
        choose_menu = (choose_menu + 10) % 10;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> ���: " << users[choose].getName() << endl; setColor(15, 0); }
        else cout << " ���: " << users[choose].getName() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> �������: " << users[choose].getS_Name() << endl; setColor(15, 0); }
        else cout << " �������: " << users[choose].getS_Name() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ��������: " << users[choose].getT_Name() << endl; setColor(15, 0); }
        else cout << " ��������: " << users[choose].getT_Name() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> ���� ��������: " << users[choose].getBornDate() << endl; setColor(15, 0); }
        else cout << " ���� ��������: " << users[choose].getBornDate() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> ����� ��������: " << users[choose].getPhoneNumber() << endl; setColor(15, 0); }
        else cout << " ����� ��������: " << users[choose].getPhoneNumber() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> �����: " << users[choose].getAdress() << endl; setColor(15, 0); }
        else cout << " �����: " << users[choose].getAdress() << endl;

        if (choose_menu == 6) { setColor(2, 0); cout << " -> �������� �����: " << users[choose].getUnit() << endl; setColor(15, 0); }
        else cout << " �������� �����: " << users[choose].getUnit() << endl;

        if (choose_menu == 7) { setColor(2, 0); cout << " -> ������ " << users[choose].getPost() << endl; setColor(15, 0); }
        else cout << " ������ " << users[choose].getPost() << endl;

        if (choose_menu == 8) { setColor(2, 0); cout << " -> ���������� ������ " << endl; setColor(15, 0); }
        else cout << " ���������� ������ " << endl;

        if (choose_menu == 9) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseDoc(User*& users, int& choose) {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� �����" << endl;
        choose_menu = (choose_menu + 8) % 8;

        for (int i = 0; i < 7; i++) {
            string s;
            int k = users[choose].getGodDoc(i);
            if (k == 0) s = "�����";
            else s = "�� �����";
            if (i == choose_menu) {
                setColor(2, 0);
                cout << " -> " << i + 1 << " - " << s << endl;
                setColor(15, 0);
            }
            else { cout << " " << i + 1 << " - " << s << endl; }
        }
        if (choose_menu == 7) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseHowSearch() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� �����" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> �� ������" << endl; setColor(15, 0); }
        else cout << " �� ������" << endl;
        
        if (choose_menu == 1) { setColor(2, 0); cout << " -> �� �������" << endl; setColor(15, 0); }
        else cout << " �� �������" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> �� ���� ��������" << endl; setColor(15, 0); }
        else cout << " �� ���� ��������" << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseHowSort() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� �����" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> �� ������" << endl; setColor(15, 0); }
        else cout << " �� ������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> �� �������" << endl; setColor(15, 0); }
        else cout << " �� �������" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> �������� �����" << endl; setColor(15, 0); }
        else cout << " �������� �����" << endl;

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

int chooseUpOrDown() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "����������� ����� � ���� �������� �����" << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> �� �����������" << endl; setColor(15, 0); }
        else cout << " �� �����������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> �� ��������" << endl; setColor(15, 0); }
        else cout << " �� ��������" << endl;

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

int chooseAdminMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "   ����������� �������������!" << endl;
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 4) % 4;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> �������� ���������� ���� ���������" << endl; setColor(15, 0); }
        else cout << " �������� ���������� ���� ���������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> ���� �����������/��������" << endl; setColor(15, 0); }
        else { cout << " ���� �����������/��������" << endl; }

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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

int chooseUserMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "   ����������� ������������!" << endl;
        cout << "����������� ����� � ���� �������� ����� ����" << endl;
        choose_menu = (choose_menu + 6) % 6;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> �������� ���������� ���� ���������" << endl; setColor(15, 0); }
        else cout << " �������� ���������� ���� ���������" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> �������� ����� ����������" << endl; setColor(15, 0); }
        else { cout << " �������� ����� ����������" << endl; }

        if (choose_menu == 2) { setColor(2, 0); cout << " -> ����� � ������� ����" << endl; setColor(15, 0); }
        else { cout << " ����� � ������� ����" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> ����� �� ���������" << endl; setColor(15, 0); }
        else { cout << " ����� �� ���������" << endl; }

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