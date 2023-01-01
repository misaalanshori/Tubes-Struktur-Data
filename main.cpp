#include "header.h"
#include "userList.h"
#include "wishList.h"
#include "productList.h"

ListUser Users;
ListProduct Products;

void pause() {
    cout << endl << "Press Enter to continue!";
    cin.ignore();
    cin.ignore();
}

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

    int productID;
    string prodName;
    int prodPrice;

    string username;
    string tempInput;

    adr_PL tempP;
    adr_UL tempU;
    adr_WL tempW;
    while (userInput != 0) {
        cout << endl
        << "-==Wishlist " << info(user).username <<"==-" << endl
        << "1. Your Wishlist" << endl
        << "2. Add Wishlist" << endl
        << "--Products--" << endl
        << "3. Show Products" << endl
        << "4. Input New Product" << endl
        << "5. Remove Product" << endl
        << "--Users--" << endl
        << "6. Show Users" << endl
        << "7. Buy Wish" << endl 
        << endl
        << "99. Delete User" << endl
        << "0. Log Out" << endl
        << "#> ";
        cin >> userInput;
        switch (userInput) {
        case 1:
            cout << "# Your Wishlist" << endl;
            showWishList(user);
            cout << endl;
            pause();
            break;

        case 2:
            cout << "# Add Wishlist" << endl;
            cout << "Input Product ID: ";
            cin >> productID;
            tempP = findProduct(Products, productID);
            if (findWish(user, productID)) {
                cout << "Product is already in Wishlist!" << endl;
            } else {
                if (tempP) {
                    insertWFirst(user, createElemenWL(tempP));
                    cout << "Added " << info(tempP).nama << " to your wishlist!" << endl;
                } else {
                    cout << "Product Not Found!" << endl;
                }
            }
            
            pause();
            break;
        
        case 3:
            cout << "# Available Products" << endl;
            showProducts(Products);
            pause();
            break;

        case 4:
            cout << "# Add New Products" << endl;
            cout << "Input Product ID: ";
            cin >> productID;
            if (findProduct(Products, productID)) {
                cout << "Product ID exists!";
                break;
            }
            cout << "Input Product Name: ";
            cin >> prodName;
            cout << "Input Product Price: ";
            cin >> prodPrice;
            insertProductLast(Products, createElemenProductList({productID, prodName, prodPrice}));
            cout << "Added " << prodName << " as item id " << productID << endl;
            pause();
            break;

        case 5:
            cout 
            << "# Delete a Product" << endl
            << "(Warning: Will delete product from all wishlist!)" << endl
            << "Input Product ID: ";
            cin >> productID;
            tempP = findProduct(Products, productID);
            if (tempP == NULL) {
                cout << "Product not found!" << endl;
            } else {
                tempU = first(Users);
                while (tempU != NULL) {
                    tempW = findWish(tempU, productID);
                    if (tempW != NULL) {
                        deleteWish(tempU, tempW);
                    }
                    tempU = next(tempU);
                }
                deleteProduct(Products, tempP, productID);
                cout << "Deleted the product " << info(tempP).nama << endl;
                delete tempP;
            }
            break;

        case 6:
            cout << "# Registered Users" << endl;
            showUsers(Users);
            pause();
            break;

        case 7:
            cout << "# Buy a Gift!" << endl;
            cout << "Input Username: ";
            cin >> username;
            tempU = findUser(Users, username);
            if (tempU == NULL) {
                cout << "User not found!" << endl;
            } else {
                showWishList(tempU);
                cout << "Input Product ID to buy: ";
                cin >> productID;
                tempP = findProduct(Products, productID);
                if (tempP == NULL) {
                    cout << "Product not found!" << endl;
                } else {
                    tempW = findWish(tempU, productID);
                    if (tempW == NULL) {
                        cout << "Product not in user Wishlist!" << endl;
                    } else {
                        deleteWish(tempU, tempW);
                        cout << "You have purchased " << info(wishProduct(tempW)).nama << " for " << info(tempU).username << endl;
                        delete tempW;
                    }
                }
                pause();
            }
            break;
        
        case 99:
            cout << "# Delete User " << info(user).username << endl;
            cout << "Are you sure? (y/n) ";
            cin >> tempInput;
            if (tempInput == "y") {
                deleteUser(Users, tempU, info(user).username);
                cout << "Deleted user " << info(tempU).username << endl;
                delete tempU;
            }
            userInput = 0;
            
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
        << "3. Show Everyone's Wishlist" << endl
        << "0. Exit" << endl
        << "#> ";
        cin >> userInput;
        switch (userInput) {
        case 1:
            user = userLogin();
            if (user) {
                cout << "Login Successfull!" << endl;
                mainMenu(user);
            } else {
                cout << "Login Failed!" << endl;
            }
            break;

        case 2:
            if (userRegister()) {
                cout << "Account Added!" << endl;
            } else {
                cout << "Account Exists!" << endl;
            }
            break;
        
        case 3:
            showUsersChild(Users);
            pause();
            break;

        case 0:
            cout << "Keluar!" << endl;
        default:
            break;
        }
    }
    return 0;
}
