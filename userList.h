#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED

struct userData {
   string username,password;
} ;

typedef struct elmUser *adr_UL;
typedef struct userData infotype;
typedef struct elmWishList *adr_WL;

struct elmUser{
    infotype info;
    adr_UL next;
    adr_WL wishList;
};

struct ListUser {
    adr_UL first;
};

void createListUser(ListUser &L);
adr_UL createElemenUserList(infotype X);
void insertUserFirst( ListUser &L, adr_UL P);
void showUsers(ListUser L);
void deleteUser(ListUser &L, adr_UL &P, string username);
adr_UL findUser(ListUser L, string username);
void showUsersChild(ListUser L);
int userWishCount(adr_UL p);

#endif // USERLIST_H_INCLUDED
