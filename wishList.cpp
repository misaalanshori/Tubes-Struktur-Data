#include "header.h"
#include "productList.h"
#include "userList.h"
#include "wishList.h"


adr_WL createElemenWL(adr_PL X) {
    adr_WL wish = new elmWishList;
    wishProduct(wish) = X;
    next(wish) = NULL;
    prev(wish) = NULL;
    return wish;
}

void insertWFirst( adr_UL  L, adr_WL P) {
    adr_WL elm = userWish(L);
    if (elm == NULL) {
        userWish(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        next(P) = userWish(L);
        prev(P) = prev(userWish(L));
        prev(userWish(L)) = P;
        userWish(L) = P;
    }
}

void showWishList(adr_UL  L) {
    adr_WL elm = userWish(L);
    if (elm == NULL) {
        cout << "Wishlist Kosong!";
    } else {
        do {
            cout << info(wishProduct(elm)).productID << ". " << info(wishProduct(elm)).nama << " (Rp" << info(wishProduct(elm)).harga << ")" << endl;
            elm = next(elm);
        } while (elm != userWish(L));
    }
}

void deleteWish(adr_UL  L, adr_WL P) {
    prev(next(P)) = prev(P);
    next(prev(P)) = next(P);
    if (P == userWish(L)) {
        userWish(L) = next(P);
    }
}

adr_WL findWish(adr_UL  L, int productID) {
    adr_WL a = userWish(L);

    if (a == NULL){
        cout<<"List kosong."<<endl;
        return NULL;
    } else {
        while ((a != NULL) && (info(wishProduct(a)).productID != productID)){
            a = next(a);
        }
        return a;
    }
}