#include "header.h"
#include "userList.h"
#include "wishList.h"
#include "productList.h"

#include <string>

// Testing Stuff Dummy Code
#define getPassword(username) (username + "123")
#define findUser(username) (username.length() < 5 ? NULL : 0x420)

bool userLogin() {
    string username, password;
    cout << "Login Akun" << endl;
    cout << "Input Username: ";
    cin >> username;
    cout << "Input Password: ";
    cin >> password;

    if (findUser(username) != NULL) {
        return password == getPassword(username);
    } else {
        return false;
    }

}

bool userRegister() {
    string username, password;
    cout << "Register Akun" << endl;
    cout << "Input Username: ";
    cin >> username;
    if (findUser(username) != NULL) {
        return false;
    }
    cout << "Input Password: ";
    cin >> password;

    return true;

}

void mainMenu() {


}

int main()
{
    int userInput = -1;

    while (userInput != 0) {
        cout
        << "-==Wishlist Natal==-" << endl
        << "1. Login" << endl
        << "2. Register" << endl
        << "0. Exit" << endl
        << "#> ";
        cin >> userInput;
        switch (userInput) {
        case 1:
            if (userLogin()) {
                cout << "Berhasil Login!" << endl;
                mainMenu();
            } else {
                cout << "Login Gagal!" << endl;
            }
            break;
        case 2:
            if (userRegister()) {
                cout << "Akun ditambahkan!" << endl;
            } else {
                cout << "Äkun sudah ada!" << endl;
            }
            break;

        case 0:
            cout << "Keluar!" << endl;
        default:
            break;

    }
    }
    return 0;
}
