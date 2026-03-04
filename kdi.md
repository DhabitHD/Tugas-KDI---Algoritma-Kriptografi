#### 1. Pengantar Singkat

RC4 (Rivest Cipher 4) adalah algoritma *stream cipher* simetris yang diciptakan oleh Ron Rivest pada tahun 1987 untuk RSA Security. Di dunia nyata, RC4 dulunya adalah salah satu algoritma enkripsi yang paling banyak digunakan karena kecepatan dan kesederhanaannya. Algoritma ini pernah menjadi standar keamanan untuk jaringan nirkabel (WEP dan WPA awal) serta protokol keamanan internet seperti SSL dan TLS.

#### 2. Pembangkitan Kunci (Key Generation)

Pada RC4, pembangkitan kunci dilakukan melalui tahap yang disebut **Key-Scheduling Algorithm (KSA)**.

* Kunci yang dimasukkan (bisa berupa teks apa saja dengan panjang 1 hingga 256 *byte*) digunakan untuk menginisialisasi array substitusi, yang sering disebut **S-box** (berisi angka 0 hingga 255).
* S-box ini kemudian diacak (*scrambled*) berdasarkan nilai-nilai dari kunci rahasia tersebut. S-box yang sudah diacak inilah yang menjadi "status internal" untuk proses enkripsi selanjutnya.

#### 3. Proses Enkripsi

RC4 menggunakan tahap kedua yang disebut **Pseudo-Random Generation Algorithm (PRGA)**.

* Berdasarkan S-box yang sudah diacak pada tahap KSA, algoritma ini akan menghasilkan aliran *byte* acak yang disebut *keystream*.
* **Langkah matematis/logika:** *Plaintext* diubah menjadi *Ciphertext* dengan melakukan operasi logika **XOR (Exclusive OR)** antara bit *plaintext* dengan bit *keystream*.

#### 4. Proses Dekripsi

Karena RC4 menggunakan operasi XOR, proses dekripsi **persis sama** dengan proses enkripsi. Jika kita memasukkan *ciphertext* ke dalam algoritma RC4 menggunakan kunci rahasia yang sama persis, operasi XOR akan membalikkan efeknya dan mengembalikan data menjadi *plaintext* asli.

#### 5. Kelebihan & Kelemahan

* **Kelebihan:** Sangat cepat, efisien, dan mudah diimplementasikan baik dalam perangkat keras maupun perangkat lunak. Tidak membutuhkan memori yang besar.
* **Kelemahan:** Ditemukan memiliki bias statistik yang signifikan. Jika sebagian kunci diketahui, sisa kunci dapat ditebak (rentan terhadap *Fluhrer, Mantin, and Shamir attack*). Saat ini, RC4 dianggap **tidak aman** untuk aplikasi modern dan penggunaannya telah dilarang di berbagai protokol standar seperti TLS.
