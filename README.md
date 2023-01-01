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
User List akan menyimpan data semua orang yang menggunakan perangkat lunak ini. Data yang disimpan adalah:
- UserID
- Nama
- Password
- wishList (pointer to wishlist)

### wishList
Wish List akan menyimpan daftar relasi dari pengguna ke elemen pada Product List. Data yang disimpan adalah:
- productList (pointer to productlist)

### productList
Product List akan menyimpan daftar produk yang ada. Data yang disimpan adalah:
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
  - addProduct
- Menghubungkan data parent ke data child (5)
  - addWishlist
- Menampilkan seluruh data parent beserta childnya (15)
  - showAllWishlist
- Mencari data child pada parent tertentu (10)
  - findWish
- Menghapus data child pada parent tertentu beserta relasinya (15)
  - deleteWish
- Menghitung jumlah data child dari parent tertentu (5)
  - countWish
- Main program (10)

## Struktur Menu
- Login
  - Input Username
  - Input Password
  - Login
    - Your Wishlist
    - Add Wishlist
      - Input Product ID
    - Show Products
      - Display Product List ("{productId} - {productName} ({hargaProduk})")
    - Add New Product
    - Remove Product
    - Show Users
      - Display User List
    - Buy Wish
      - Input User ID
        - Display Wishlist Product Lists ("{productId} - {productName} ({hargaProduk})")
        - Input Product ID
- Register
  - Input Username
  - Input Password
  - Register
