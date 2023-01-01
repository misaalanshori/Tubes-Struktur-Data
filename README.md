# Tugas Struktur Data
Tugas Struktur Data Kelompok 11

## Anggota Kelompok
- Muhammad Isa Al Anshori (1302210014)
- Liyan Made Leon Wayan (1302213037)

## Studi Kasus
Natal sudah dekat, maka diperlukan cara mudah untuk mencari hadiah untuk orang orang terdekat. Proses ini kadang sulit karena kita perlu mengetahui apa yang diinginkan oleh orang lain. Maka diperlukan cara untuk mengorganisasikan barang yang sedang kita inginkan untuk memudahkan mencari hadiah yang sesuai.

## Spesifikasi
Berikut adalah spesifikasi untuk Multi Linked List M-N yang akan kami gunakan

### userList
User List merupakan single linked list yang akan akan menyimpan data semua orang yang menggunakan perangkat lunak ini. Data yang disimpan adalah:
- Username
- Password
- wishList (pointer to wishlist)

### wishList
Wish List merupakan circular double linked list yang akan menyimpan daftar relasi dari pengguna ke elemen pada Product List. Data yang disimpan adalah:
- productadr (pointer to productlist)

### productList
Product List adalah single linked list yang akan menyimpan daftar produk yang ada. Data yang disimpan adalah:
- ProductID
- Nama Produk
- Harga Produk  

## Fungsionalitas
- Insert data parent dari depan/belakang (5)
  - insertUserFirst
- Show all data parent (5)
  - showUsers
- Menghapus data parent beserta relasinya (15)
  - deleteUser
- Mencari data parent (5)
  - findUser
- Mencari data child (5)
  - findProduct
- Menambahkan data child (5)
  - createElemenProductList
  - insertProductLast
- Menghubungkan data parent ke data child (5)
  - insertWFirst
- Menampilkan seluruh data parent beserta childnya (15)
  - showUsersChild
- Mencari data child pada parent tertentu (10)
  - findWish
- Menghapus data child pada parent tertentu beserta relasinya (15)
  - deleteWish
- Menghitung jumlah data child dari parent tertentu (5)
  - userWishCount
- Main program (10)

## Struktur Menu
- Login
  - Input Username
  - Input Password
  - Login
    - Your Wishlist
      - Display User Wishlist
    - Add Wishlist
      - Input Product ID
    - Show Products
      - Display Product List
    - Input New Product
      - Input Product ID
      - Input Product Name
      - Input Product Price
    - Remove Product
      - Input Product ID
    - Show Users
      - Display User List
    - Buy Wish
      - Input Username
        - Display Wishlist Product Lists
        - Input Product ID
    - Delete User
- Register
  - Input Username
  - Input Password
  - Register
- Show Everyone's Wishlist
  - Display semua user dan semua isi wishlistnya
