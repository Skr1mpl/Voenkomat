#include "Files.h"

ostream& operator<<(ostream& os, MainAdmin& mainadmins) {
    os << mainadmins.getLogin() << endl << encryptPass(mainadmins.getPass()) << endl;
    os << mainadmins.getName() << endl << mainadmins.getSName() << endl;
    os << mainadmins.getRank() << endl;
    return os;
}

istream& operator>>(istream& is, MainAdmin& mainadmins) {
    string s;
    getline(is, s);
    mainadmins.changeLogin(s);
    getline(is, s);
    mainadmins.changePass(deencryptPass(s));
    getline(is, s);
    mainadmins.changeName(s);
    getline(is, s);
    mainadmins.changeSName(s);
    getline(is, s);
    mainadmins.changeRank(s);
    return is;
}

istream& operator>>(istream& is, Admin& admins) {
    string s;
    getline(is, s);
    admins.changeLogin(s);
    getline(is, s);
    admins.changePass(deencryptPass(s));
    getline(is, s);
    admins.changeName(s);
    getline(is, s);
    admins.changeSName(s);
    getline(is, s);
    admins.changePosition(s);
    return is;
}

ostream& operator<<(ostream& os, Admin& admins) {
    os << admins.getLogin() << endl << encryptPass(admins.getPass()) << endl << admins.getName() << endl;
    os << admins.getSName() << endl << admins.getPosition() << endl;
    return os;
}

ostream& operator<<(ostream& os, User& users) {
    os << users.getLogin() << endl << encryptPass(users.getPass()) << endl;
    os << users.getName() << endl << users.getS_Name() << endl << users.getT_Name() << endl;
    os << users.getBornDate() << endl << users.getPhoneNumber() << endl << users.getAdress() << endl;
    os << users.getGoden() << endl << users.getUnit() << endl << users.getPost() << endl;
    for (int i = 0; i < 7; i++)
        os << users.getGodDoc(i) << endl;
    return os;
}

istream& operator>>(istream& is, User& users) {
    string s;
    getline(is, s);
    users.changeLogin(s);
    getline(is, s);
    users.changePass(deencryptPass(s));
    getline(is, s);
    users.setName(s);
    getline(is, s);
    users.setSName(s);
    getline(is, s);
    users.setTName(s);
    getline(is, s);
    users.setBornDate(s);
    getline(is, s);
    users.setPhone(s);
    getline(is, s);
    users.setAdress(s);
    getline(is, s);
    users.setGoden(s);
    getline(is, s);
    users.setUnit(s);
    getline(is, s);
    users.setPost(s);
    for (int i = 0; i < 7; i++) {
        getline(is, s);
        users.setGodDoc(i, stoi(s));
    }
    return is;
}

void createFiles() {
    ifstream check;
    ofstream of;
    check.open("mainadmins.txt");
    if (!check.is_open()) {
        of.open("mainadmins.txt");
        of << "0" << endl;
        of.close();
    }
    check.open("admins.txt");
    if (!check.is_open()) {
        of.open("admins.txt");
        of << "0" << endl;
        of.close();
    }
    check.close();
    check.open("users.txt");
    if (!check.is_open()) {
        of.open("users.txt");
        of << "0" << endl;
        of.close();
    }
    check.close();
}

void fillSize(int& nMainAdmins, int& nAdmins, int& nUsers) {
    ifstream check;
    check.open("mainadmins.txt");
    check.seekg(-3, ios::end);
    check >> nMainAdmins;
    check.close();
    check.open("admins.txt");
    check.seekg(-3, ios::end);
    check >> nAdmins;
    check.close();
    check.open("users.txt");
    check.seekg(-3, ios::end);
    check >> nUsers;
    check.close();
}

void fillClasses(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers) {
    ifstream fin;
    fin.open("mainadmins.txt");
    if (fin.peek() != EOF) {
        for (int i = 0; i < nMainAdmins; i++) {
            fin >> mainadmins[i];
        }
    }
    fin.close();
    fin.open("admins.txt");
    if (fin.peek() != EOF) {
        for (int i = 0; i < nAdmins; i++) {
            fin >> admins[i];
        }
    }
    fin.close();
    fin.open("users.txt");
    if (fin.peek() != EOF) {
        for (int i = 0; i < nUsers; i++) {
            fin >> users[i];
        }
    }
    fin.close();
}

void fillFiles(MainAdmin*& mainadmins, Admin*& admins, User*& users, int& nMainAdmins, int& nAdmins, int& nUsers) {
    ofstream fout;
    fout.open("mainadmins.txt");
    for (int i = 0; i < nMainAdmins; i++) {
        fout << mainadmins[i];
    }
    fout << nMainAdmins << endl;
    fout.close();
    fout.open("admins.txt");
    for (int i = 0; i < nAdmins; i++) {
        fout << admins[i];
    }
    fout << nAdmins << endl;
    fout.close();
    fout.open("users.txt");
    for (int i = 0; i < nUsers; i++) {
        fout << users[i];
    }
    fout << nUsers << endl;
    fout.close();
}

void changeSizeUsers(User*& users, int& nUsers) {
    nUsers++;
    User* ptr = new User[nUsers];
    for (int i = 0; i < nUsers - 1; i++)
        ptr[i] = users[i];
    users = ptr;
    ptr = NULL;
    delete[]ptr;
}

void changeSizeAdmins(Admin*& admins, int& nAdmin) {
    nAdmin++;
    Admin* ptr = new Admin[nAdmin];
    for (int i = 0; i < nAdmin - 1; i++)
        ptr[i] = admins[i];
    admins = ptr;
    ptr = NULL;
    delete[]ptr;
}

void changeSizeMainAdmins(MainAdmin*& mainadmins, int& nMainAdmins) {
    nMainAdmins++;
    MainAdmin* ptr = new MainAdmin[nMainAdmins];
    for (int i = 0; i < nMainAdmins - 1; i++)
        ptr[i] = mainadmins[i];
    mainadmins = ptr;
    ptr = NULL;
    delete[]ptr;
}