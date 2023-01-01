#include "header.h"
#include "userList.h"
#include "wishList.h"
#include "productList.h"

void createListUser(ListUser &L){
    first(L) = NULL;
};

adr_UL createElemenUserList(infotype X){
    adr_UL P = new elmUser;
    info(P) = X;
    next(P) = NULL;
    userWish(P) = NULL;
    return P;
};

void insertUserFirst( ListUser &L, adr_UL P){
    adr_UL q;

    if (first(L) == NULL){
        first(L) = P;
        next(P) = NULL;
    }else {
        next(P) = first(L);
        first(L) = P;
    }
};

void deleteUser(ListUser &L, adr_UL &P, string username) {

    if (info(first(L)).username == username) {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    } else {
        adr_UL a = first(L);
        adr_UL prec = first(L);

        while  (next(a) != NULL && info(a).username != username){
            prec = a;
            a = next(a);
        }
        if (a != NULL) {
            P = next(prec);
            next(prec) = next(P);
            next(P) = NULL;
        } else {
            P = NULL;
        }
        
    }

    
};

int userWishCount(adr_UL p) {
    int count = 0;
    adr_WL wish = userWish(p);
    if (wish != NULL) {
        do {
            count++;
            wish = next(wish);
        } while (wish != userWish(p));
    }
    return count;
}

void showUsers(ListUser L){
    adr_UL P = first(L);
    int i = 1;

    if (first(L) != NULL){
        while (P != NULL){
            cout << i << ". ";
            cout << info(P).username;
            cout << " (" << userWishCount(P) << " Wishes)" << endl;
            P = next(P);
            i++;
        }
    }else{
        cout<<"List kosong."<<endl;
    }
};

void showUsersChild(ListUser L){
    adr_UL P = first(L);
    int i = 1;

    if (first(L) != NULL){
        while (P != NULL){
            cout << i << ". " << info(P).username << ": " << endl;
            adr_WL w = userWish(P);
            if (w != NULL) {
                do {
                    cout 
                    << "\t"
                    << info(wishProduct(w)).productID << ". " 
                    << info(wishProduct(w)).nama 
                    << " (Rp" << info(wishProduct(w)).harga << ")" << endl;
                    w = next(w);
                } while (w != userWish(P));
            }
            P = next(P);
            i++;
        }
    }else{
        cout<<"List kosong."<<endl;
    }
};

adr_UL findUser(ListUser L, string username){
    adr_UL a = first(L);

    if (a == NULL){
        return NULL;
    } else {
        while ((a != NULL) && (info(a).username != username)){
            a = next(a);
        }
        return a;
    }
};
