#ifndef WISHLIST_H_INCLUDED
#define WISHLIST_H_INCLUDED


typedef struct elmWishList *adr_WL;
typedef struct WishListData infotypeW;

struct elmWishList{
    adr_WL next;
    adr_WL prev;
};

adr_WL createElemenWL(infotypeW X);
void insertWFirst( adr_UL  L, adr_WL &P);
void showWishList(adr_UL  L);
void deleteWish(adr_UL  &L, adr_WL &P);
adr_WL findWish(adr_UL  L, string produkname);

#endif // WISHLIST_H_INCLUDED
