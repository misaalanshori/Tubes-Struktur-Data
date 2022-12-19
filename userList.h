#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED

struct userData {
   string username,password;
   int userID;
} ;

typedef struct elmUser *adr_UL;
typedef struct userData infotype;
typedef struct elmProduct *adr_PL;

struct ElmUser{
    infotype info;
    adr_UL next;
    adr_PL wishList;
};

struct ListUser {
    adr_UL first;
};

void createListUser(ListUser &L);
adr_UL createElemenUserList(infotype X);
void insertUserFirst( ListUser &L, adr_UL &P);
void showUsers(ListUser L);
void deleteUser(ListUser &L, adr_UL &P);
adr_UL findUser(ListUser L, string username, int userID);

#endif // USERLIST_H_INCLUDED
