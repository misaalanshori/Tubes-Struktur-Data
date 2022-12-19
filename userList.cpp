#include "header.h"
#include "userList.h"

void createListUser(ListUser &L){
    first(L) = NULL;
};

adr_UL createElemenUserList(infotype X){
    adr_UL P = new ElmUser;
    info(P) = X;
    next(P) = NULL;
    return P;
};

void insertUserFirst( ListUser &L, adr_UL &P){
    adr_UL q;

    if (first(L) == NULL){
        first(L) = P;
        next(P) = NULL;
    }else {
        next(P) = first(L);
        first(L) = P;
    }
};

void deleteUser(ListUser &L, adr_UL &P){

};

void showUsers(ListUser L){
      adr_UL P = first(L);
      int i = 0;

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

};
