#ifndef PRODUCTLIST_H_INCLUDED
#define PRODUCTLIST_H_INCLUDED

struct productData {
    int productID;
    string nama;
    int harga;
} ;

typedef struct productData infotypeP;
typedef struct elmProduct *adr_PL;

struct elmProduct{
    infotypeP info;
    adr_PL next;
};

struct ListProduct {
    adr_PL first;
};

void createListProduct(ListProduct &L);
adr_PL createElemenProductList(infotypeP X);
void insertProductLast( ListProduct &L, adr_PL P);
void showProducts(ListProduct L);
void deleteProduct(ListProduct &L, adr_PL &P, int productID);
adr_PL findProduct(ListProduct L, int productID);

#endif // PRODUCTLIST_H_INCLUDED
