#include "header.h"
#include "userList.h"
#include "wishList.h"
#include "productList.h"

ListUser Users;
ListProduct Products;

adr_UL userLogin() {
    string username, password;
    cout << "Login Akun" << endl;
    cout << "Input Username: ";
    cin >> username;
    cout << "Input Password: ";
    cin >> password;

    adr_UL user = findUser(Users, username);
    if (user != NULL && password == info(user).password) {
        return user;
    } else {
        return NULL;
    }

}

bool userRegister() {
    string username, password;
    cout << "Register Akun" << endl;
    cout << "Input Username: ";
    cin >> username;
    if (findUser(Users, username) != NULL) {
        return false;
    }
    cout << "Input Password: ";
    cin >> password;

    insertUserFirst(Users, createElemenUserList({username, password}));
    return true;

}

void mainMenu(adr_UL user) {
    int userInput = -1;
    while (userInput != 0) {
        cout << endl
        << "-==Wishlist " << info(user).username <<"==-" << endl
        << "1. Your Wishlist" << endl
        << "2. Add Wishlist" << endl
        << "3. Show Products" << endl
        << "4. Show Users" << endl
        << "5. Buy Wish" << endl
        << "0. Log Out" << endl
        << "#> ";
        cin >> userInput;
        switch (userInput) {
        case 1:

            break;

        case 2:

            break;

        case 0:
            cout << "Logged Out!" << endl;
        default:
            break;
        }
    }

}

int main()
{
    int userInput = -1;
    adr_UL user;
    while (userInput != 0) {
        cout << endl
        << "-==Wishlist Natal==-" << endl
        << "1. Login" << endl
        << "2. Register" << endl
        << "0. Exit" << endl
        << "#> ";
        cin >> userInput;
        switch (userInput) {
        case 1:
            user = userLogin();
            if (user) {
                cout << "Berhasil Login!" << endl;
                mainMenu(user);
            } else {
                cout << "Login Gagal!" << endl;
            }
            break;

        case 2:
            if (userRegister()) {
                cout << "Akun ditambahkan!" << endl;
            } else {
                cout << "Akun sudah ada!" << endl;
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
