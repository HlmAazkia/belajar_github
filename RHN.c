#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 100

typedef struct {
    char id[20];
    char asal[50];
    char tujuan[50];
    int lamaPinjam; // dalam hari
    int denda; // denda per hari
    int totalDenda; // total denda yang harus dibayar
} Kendaraan;

Kendaraan kendaraan[MAX_VEHICLES];
int count = 0;

// Fungsi untuk menambahkan kendaraan
void tambahKendaraan() {
    if (count < MAX_VEHICLES) {
        printf("Masukkan ID Kendaraan: ");
        scanf("%s", kendaraan[count].id);
        printf("Masukkan Asal: ");
        scanf("%s", kendaraan[count].asal);
        printf("Masukkan Tujuan: ");
        scanf("%s", kendaraan[count].tujuan);
        printf("Masukkan Lama Peminjaman (dalam hari): ");
        scanf("%d", &kendaraan[count].lamaPinjam);
        printf("Masukkan Denda per Hari: ");
        scanf("%d", &kendaraan[count].denda);
        kendaraan[count].totalDenda = 0; // Inisialisasi total denda
        count++;
        printf("Kendaraan berhasil ditambahkan!\n");
    } else {
        printf("Data kendaraan sudah penuh!\n");
    }
}

// Fungsi untuk mengembalikan kendaraan
void kembalikanKendaraan() {
    char id[20];
    printf("Masukkan ID Kendaraan yang dikembalikan: ");
    scanf("%s", id);

    for (int i = 0; i < count; i++) {
        if (strcmp(kendaraan[i].id, id) == 0) {
            int lamaKeterlambatan;
            printf("Masukkan Lama Keterlambatan (dalam hari): ");
            scanf("%d", &lamaKeterlambatan);
            if (lamaKeterlambatan > 0) {
                kendaraan[i].totalDenda = lamaKeterlambatan * kendaraan[i].denda;
                printf("Kendaraan dengan ID %s dikembalikan. Total Denda: %d\n", kendaraan[i].id, kendaraan[i].totalDenda);
            } else {
                printf("Kendaraan dengan ID %s dikembalikan tepat waktu. Tidak ada denda.\n", kendaraan[i].id);
            }
            return;
        }
    }
    printf("Kendaraan dengan ID %s tidak ditemukan.\n", id);
}

// Fungsi untuk menampilkan semua kendaraan
void tampilkanKendaraan() {
    printf("\nDaftar Kendaraan:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %s, Asal: %s, Tujuan: %s, Lama Pinjam: %d hari, Denda per Hari: %d, Total Denda: %d\n",
               kendaraan[i].id, kendaraan[i].asal, kendaraan[i].tujuan,
               kendaraan[i].lamaPinjam, kendaraan[i].denda, kendaraan[i].totalDenda);
    }
}

int main() {
    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kendaraan\n");
        printf("2. Kembalikan Kendaraan\n");
        printf("3. Tampilkan Kendaraan\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahKendaraan();
                break;
            case 2:
                kembalikanKendaraan();
                break;
            case 3:
                tampilkanKendaraan();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}
