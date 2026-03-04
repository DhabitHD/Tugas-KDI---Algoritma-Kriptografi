# Tugas Kriptografi - Implementasi Algoritma RC4

Repositori ini berisi implementasi algoritma kriptografi simetris (stream cipher) RC4 menggunakan bahasa pemrograman C. Program ini dibuat untuk mendemonstrasikan proses enkripsi dan dekripsi langkah demi langkah dari awal, tanpa menggunakan library kriptografi eksternal.

## Persyaratan Sistem

Untuk menjalankan kode program ini, Anda memerlukan kompilator bahasa C (C Compiler) seperti GCC (GNU Compiler Collection) yang terinstal di sistem Anda.

## Instruksi Menjalankan Program

Program dapat dikompilasi dan dieksekusi melalui antarmuka baris perintah (Terminal/Command Prompt). 

1. Unduh atau clone repositori ini ke dalam komputer Anda.
2. Buka terminal dan navigasikan ke direktori tempat file rc4.c berada.
3. Lakukan kompilasi source code menggunakan kompilator GCC dengan menjalankan perintah berikut:

       gcc rc4.c -o rc4

4. Setelah proses kompilasi berhasil, sebuah file executable akan terbentuk. Jalankan program dengan perintah berikut sesuai dengan sistem operasi yang digunakan:

   Untuk environment Linux (seperti pada Mint atau EndeavourOS) dan macOS:

       ./rc4

   Untuk environment Windows:

       rc4.exe

## Alur Program

Ketika program dieksekusi, alur kerja algoritma akan berjalan secara berurutan seperti berikut:

1. Inisialisasi Input: Program mendefinisikan sebuah kunci rahasia (key) bertipe string dan sebuah pesan asli (plaintext) yang akan diproses.

2. Eksekusi Enkripsi:
   - Program memanggil fungsi utama rc4.
   - Di dalam fungsi tersebut, algoritma KSA (Key-Scheduling Algorithm) pertama kali dijalankan untuk menginisialisasi dan mengacak array S-box berukuran 256 byte menggunakan kunci rahasia yang telah ditentukan.
   - Selanjutnya, bagian PRGA (Pseudo-Random Generation Algorithm) mulai melakukan perulangan (loop) sepanjang karakter pesan. PRGA menghasilkan byte demi byte karakter acak (keystream) dari S-box.
   - Setiap byte plaintext kemudian digabungkan dengan byte keystream menggunakan operasi logika bitwise XOR. Hasil dari operasi ini adalah ciphertext.

3. Menampilkan Ciphertext: Output hasil enkripsi dicetak ke layar. Karena ciphertext umumnya berupa karakter yang tidak dapat direpresentasikan dalam teks standar (unreadable), program akan mencetak nilainya dalam format representasi Heksadesimal (Hex) agar perubahannya terlihat jelas.

4. Eksekusi Dekripsi:
   - Program kembali memanggil fungsi rc4 yang sama, kali ini dengan memberikan ciphertext sebagai data masukannya, namun tetap menggunakan kunci rahasia yang sama persis.
   - KSA menginisialisasi ulang S-box, dan PRGA menghasilkan keystream yang identik dengan yang dihasilkan pada saat proses enkripsi.
   - Ciphertext dioperasikan dengan XOR terhadap keystream tersebut. Karena sifat matematis dari XOR, operasi ini akan membatalkan efek enkripsi dan mengembalikan ciphertext ke bentuk aslinya.

5. Menampilkan Plaintext: Hasil proses dekripsi dicetak ke layar sebagai string karakter standar. Output ini akan persis sama dengan pesan yang diinisialisasi pada langkah pertama.
