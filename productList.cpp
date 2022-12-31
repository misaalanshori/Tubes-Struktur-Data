#include "header.h"
#include "productList.h"

void createListProduct(ListProduct &L) {
    first(L) = NULL;
}

adr_PL createElemenProductList(infotypeP X) {
    adr_PL produk = new elmProduct;
    info(produk) = X;
    next(produk) = NULL;
    return produk;

}

void insertProductLast(ListProduct &L, adr_PL P) { 
    adr_PL elm = first(L);
    if (elm == NULL) {
        first(L) = P;
    } else {
        while (next(elm) != NULL) {
            elm = next(elm);
        }
        next(elm) = P;
    }
    
}

void showProducts(ListProduct L) {
    adr_PL elm = first(L);
    cout << "Daftar Produk:" << endl; 
    if (elm == NULL) {
        cout << "Produk Kosong!" << endl;
    } else {
        while (elm != NULL) {
            cout << info(elm).productID << ". " << info(elm).nama << " (Rp" << info(elm).harga << ")" << endl;
            elm = next(elm);
        }
    }
}


void deleteProduct(ListProduct &L, adr_PL &P, int productID){
    if (info(first(L)).productID == productID) {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    } else {
        adr_PL a = first(L);
        adr_PL prec = first(L);

        while  (next(a) != NULL && info(a).productID != productID){
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


adr_PL findProduct(ListProduct L, int productID) {
    adr_PL a = first(L);
    while (a != NULL && info(a).productID != productID) {
        a = next(a);
    }
    return a;
}
