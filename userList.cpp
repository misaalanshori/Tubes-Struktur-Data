#include "header.h"
#include "userList.h"

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

void showUsers(ListUser L){
    adr_UL P = first(L);
    int i = 1;

    if (first(L) != NULL){
        while (P != NULL){
            cout << i << ".";
            cout << info(P).username << " ; ";
            cout << info(P).password << endl;
            P = next(P);
            i++;
        }
        cout<<endl;
    }else{
        cout<<"List kosong."<<endl;
    }
};
adr_UL findUser(ListUser L, string username){
    adr_UL a = first(L);

    if (a == NULL){
        cout<<"List kosong."<<endl;
        return NULL;
    } else {
        while ((a != NULL) && (info(a).username != username)){
            a = next(a);
        }
        return a;
    }
};
