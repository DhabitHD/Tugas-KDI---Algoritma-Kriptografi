#include <stdio.h>
#include <string.h>

// Fungsi bantuan untuk menukar nilai dua variabel
void swap(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Key-Scheduling Algorithm (KSA) - Tahap Pembangkitan Kunci
void ksa(char *key, unsigned char *S) {
    int len = strlen(key);
    int j = 0;
    
    // Inisialisasi S-box dengan nilai 0-255
    for(int i = 0; i < 256; i++) {
        S[i] = i;
    }
    
    // Acak S-box berdasarkan Kunci
    for(int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % len]) % 256;
        swap(&S[i], &S[j]);
    }
}

// 2. Pseudo-Random Generation Algorithm (PRGA) - Tahap Enkripsi/Dekripsi
void rc4(char *key, unsigned char *data, int data_len) {
    unsigned char S[256];
    
    // Bangkitkan state internal dengan kunci
    ksa(key, S);

    int i = 0, j = 0;
    
    // Proses setiap byte data
    for(int n = 0; n < data_len; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(&S[i], &S[j]);
        
        int t = (S[i] + S[j]) % 256;
        unsigned char keystream = S[t]; // Hasil pseudo-random
        
        // Lakukan operasi XOR (^) antara data dan keystream
        data[n] ^= keystream; 
    }
}

int main() {
    // Tentukan Kunci dan Pesan
    char key[] = "KUNCI_RAHASIA_123";
    unsigned char data[] = "Halo, ini adalah pesan rahasia!";
    int len = strlen((char *)data);

    printf("======================================\n");
    printf("     DEMONSTRASI ALGORITMA RC4\n");
    printf("======================================\n\n");

    printf("[1] Plaintext Awal : %s\n", data);

    // Proses Enkripsi
    rc4(key, data, len);
    
    printf("\n[2] Proses Enkripsi Selesai...\n");
    printf("[3] Ciphertext (Hex): ");
    // Menampilkan hasil enkripsi dalam bentuk Hexadecimal agar terlihat jelas perubahannya
    for(int i = 0; i < len; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    // Proses Dekripsi
    // Kita memasukkan data yang sudah terenkripsi ke fungsi yang sama dengan kunci yang sama
    rc4(key, data, len);
    
    printf("\n[4] Proses Dekripsi Selesai...\n");
    printf("[5] Hasil Dekripsi  : %s\n", data);

    return 0;
}