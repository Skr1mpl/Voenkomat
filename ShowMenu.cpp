#include "ShowMenu.h"

int chooseMainMenu() {
    int choose_menu = 0, keyboard_button = 0;
    while (true) {
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 3) % 3;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Войти в аккаунт" << endl; setColor(15, 0); }
        else cout << " Войти в аккаунт" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Создать новый аккаунт" << endl; setColor(15, 0); }
        else cout << " Создать новый аккаунт" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Выйти из программы" << endl; setColor(15, 0); }
        else { cout << " Выйти из программы" << endl; }

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
        cout << "   Здраствуйте главный администратор!" << endl;
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 6) % 6;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр информации всех аккаунтов" << endl; setColor(15, 0); }
        else cout << " Просмотр информации всех аккаунтов" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Редактировать аккаунты" << endl; setColor(15, 0); }
        else cout << " Редактировать аккаунты" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Добавление аккаунта" << endl; setColor(15, 0); }
        else { cout << " Добавление аккаунта" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Меню призывников/солдатов" << endl; setColor(15, 0); }
        else { cout << " Меню призывников/солдатов" << endl; }

        if (choose_menu == 4) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 5) { setColor(2, 0); cout << " -> Выход из программы" << endl; setColor(15, 0); }
        else { cout << " Выход из программы" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 4) % 4;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Главных администраторов" << endl; setColor(15, 0); }
        else cout << " Главных администраторов" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Администраторов" << endl; setColor(15, 0); }
        else cout << " Администраторов" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Пользователей" << endl; setColor(15, 0); }
        else { cout << " Пользователей" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Вернуться назад" << endl; setColor(15, 0); }
        else { cout << " Вернуться назад" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите главного администратора" << endl;
        choose_menu = (choose_menu + (nMainAdmins + 1)) % (nMainAdmins + 1);

        for (int i = 0; i < nMainAdmins; i++)
            if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << mainadmins[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << mainadmins[i].getLogin() << endl; }

        if (choose_menu == nMainAdmins) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите что редактировать" << endl;
        choose_menu = (choose_menu + 6) % 6;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> Логин: " << mainadmins[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " Логин: " << mainadmins[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Пароль: " << mainadmins[choose].getPass() << endl; setColor(15, 0); }
        else cout << " Пароль: " << mainadmins[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Имя: " << mainadmins[choose].getName() << endl; setColor(15, 0); }
        else cout << " Имя: " << mainadmins[choose].getName() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Фамилия: " << mainadmins[choose].getSName() << endl; setColor(15, 0); }
        else cout << " Фамилия: " << mainadmins[choose].getSName() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> Звание: " << mainadmins[choose].getRank() << endl; setColor(15, 0); }
        else cout << " Звание: " << mainadmins[choose].getRank() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите администратора" << endl;
        choose_menu = (choose_menu + (nAdmins + 1)) % (nAdmins + 1);

        for (int i = 0; i < nAdmins; i++)
            if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << admins[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << admins[i].getLogin() << endl; }

        if (choose_menu == nAdmins) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите что редактировать" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> Логин: " << admin[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " Логин: " << admin[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Пароль: " << admin[choose].getPass() << endl; setColor(15, 0); }
        else cout << " Пароль: " << admin[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Имя: " << admin[choose].getName() << endl; setColor(15, 0); }
        else cout << " Имя: " << admin[choose].getName() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Фамилия: " << admin[choose].getSName() << endl; setColor(15, 0); }
        else cout << " Фамилия: " << admin[choose].getSName() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> Должность: " << admin[choose].getPosition() << endl; setColor(15, 0); }
        else cout << " Должность: " << admin[choose].getPosition() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> Права: Админ" << endl; setColor(15, 0); }
        else cout << " Права: Админ" << endl;

        if (choose_menu == 6) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пользователя" << endl;
        choose_menu = (choose_menu + (nUsers + 1)) % (nUsers + 1);

        for (int i = 0; i < nUsers; i++)
            if (i == choose_menu) { setColor(2, 0); cout << " -> " << i + 1 << " - " << users[i].getLogin() << endl; setColor(15, 0); }
            else { cout << " " << i + 1 << " - " << users[i].getLogin() << endl; }

        if (choose_menu == nUsers) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите что редактировать" << endl;
        choose_menu = (choose_menu + 7) % 7;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> Логин: " << users[choose].getLogin() << endl; setColor(15, 0); }
        else cout << " Логин: " << users[choose].getLogin() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Пароль: " << users[choose].getPass() << endl; setColor(15, 0); }
        else cout << " Пароль: " << users[choose].getPass() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Имя: " << users[choose].getName() << endl; setColor(15, 0); }
        else cout << " Имя: " << users[choose].getName() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Фамилия: " << users[choose].getS_Name() << endl; setColor(15, 0); }
        else cout << " Фамилия: " << users[choose].getS_Name() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> Отчество: " << users[choose].getT_Name() << endl; setColor(15, 0); }
        else cout << " Отчество: " << users[choose].getT_Name() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> Права: Пользователь" << endl; setColor(15, 0); }
        else cout << " Права: Пользователь" << endl;

        if (choose_menu == 6) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 5) % 5;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр всей информации" << endl; setColor(15, 0); }
        else cout << " Просмотр всей информации" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Редактировать информацию" << endl; setColor(15, 0); }
        else cout << " Редактировать информацию" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Поиск информации" << endl; setColor(15, 0); }
        else { cout << " Поиск информации" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Отсортировать информацию" << endl; setColor(15, 0); }
        else { cout << " Отсортировать информацию" << endl; }

        if (choose_menu == 4) { setColor(2, 0); cout << " -> Вернуться назад" << endl; setColor(15, 0); }
        else { cout << " Вернуться назад" << endl; }

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите что редактировать" << endl;
        choose_menu = (choose_menu + 10) % 10;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> Имя: " << users[choose].getName() << endl; setColor(15, 0); }
        else cout << " Имя: " << users[choose].getName() << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Фамилия: " << users[choose].getS_Name() << endl; setColor(15, 0); }
        else cout << " Фамилия: " << users[choose].getS_Name() << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Отчество: " << users[choose].getT_Name() << endl; setColor(15, 0); }
        else cout << " Отчество: " << users[choose].getT_Name() << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Дата рождения: " << users[choose].getBornDate() << endl; setColor(15, 0); }
        else cout << " Дата рождения: " << users[choose].getBornDate() << endl;

        if (choose_menu == 4) { setColor(2, 0); cout << " -> Номер телефона: " << users[choose].getPhoneNumber() << endl; setColor(15, 0); }
        else cout << " Номер телефона: " << users[choose].getPhoneNumber() << endl;

        if (choose_menu == 5) { setColor(2, 0); cout << " -> Адрес: " << users[choose].getAdress() << endl; setColor(15, 0); }
        else cout << " Адрес: " << users[choose].getAdress() << endl;

        if (choose_menu == 6) { setColor(2, 0); cout << " -> Военская часть: " << users[choose].getUnit() << endl; setColor(15, 0); }
        else cout << " Военская часть: " << users[choose].getUnit() << endl;

        if (choose_menu == 7) { setColor(2, 0); cout << " -> Статус " << users[choose].getPost() << endl; setColor(15, 0); }
        else cout << " Статус " << users[choose].getPost() << endl;

        if (choose_menu == 8) { setColor(2, 0); cout << " -> Заключения врачей " << endl; setColor(15, 0); }
        else cout << " Заключения врачей " << endl;

        if (choose_menu == 9) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт" << endl;
        choose_menu = (choose_menu + 8) % 8;

        for (int i = 0; i < 7; i++) {
            string s;
            int k = users[choose].getGodDoc(i);
            if (k == 0) s = "Годен";
            else s = "Не годен";
            if (i == choose_menu) {
                setColor(2, 0);
                cout << " -> " << i + 1 << " - " << s << endl;
                setColor(15, 0);
            }
            else { cout << " " << i + 1 << " - " << s << endl; }
        }
        if (choose_menu == 7) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт" << endl;
        choose_menu = (choose_menu + 4) % 4;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> По логину" << endl; setColor(15, 0); }
        else cout << " По логину" << endl;
        
        if (choose_menu == 1) { setColor(2, 0); cout << " -> По фамилии" << endl; setColor(15, 0); }
        else cout << " По фамилии" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> По году рождения" << endl; setColor(15, 0); }
        else cout << " По году рождения" << endl;

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт" << endl;
        choose_menu = (choose_menu + 3) % 3;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> По логину" << endl; setColor(15, 0); }
        else cout << " По логину" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> По фамилии" << endl; setColor(15, 0); }
        else cout << " По фамилии" << endl;

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Вернутся назад" << endl; setColor(15, 0); }
        else cout << " Вернутся назад" << endl;

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
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт" << endl;
        choose_menu = (choose_menu + 2) % 2;

        if (choose_menu == 0) { setColor(2, 0); cout << " -> По возрастанию" << endl; setColor(15, 0); }
        else cout << " По возрастанию" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> По убыванию" << endl; setColor(15, 0); }
        else cout << " По убыванию" << endl;

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
        cout << "   Здраствуйте администратор!" << endl;
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 4) % 4;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр информации всех аккаунтов" << endl; setColor(15, 0); }
        else cout << " Просмотр информации всех аккаунтов" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Меню призывников/солдатов" << endl; setColor(15, 0); }
        else { cout << " Меню призывников/солдатов" << endl; }

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Выход из программы" << endl; setColor(15, 0); }
        else { cout << " Выход из программы" << endl; }

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
        cout << "   Здраствуйте пользователь!" << endl;
        cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
        choose_menu = (choose_menu + 6) % 6;
        if (choose_menu == 0) { setColor(2, 0); cout << " -> Просмотр информации всех аккаунтов" << endl; setColor(15, 0); }
        else cout << " Просмотр информации всех аккаунтов" << endl;

        if (choose_menu == 1) { setColor(2, 0); cout << " -> Просмотр своей информации" << endl; setColor(15, 0); }
        else { cout << " Просмотр своей информации" << endl; }

        if (choose_menu == 2) { setColor(2, 0); cout << " -> Выход в главное меню" << endl; setColor(15, 0); }
        else { cout << " Выход в главное меню" << endl; }

        if (choose_menu == 3) { setColor(2, 0); cout << " -> Выход из программы" << endl; setColor(15, 0); }
        else { cout << " Выход из программы" << endl; }

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