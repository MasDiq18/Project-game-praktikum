#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[16];
    char password[16];
} login;

void registeruser() {
    // Fungsi untuk register
    FILE *file;
    file = fopen("database/login.bin", "ab");
    if (file == NULL) {
        printf("Gagal membuka file\n");
        return;
    }
    
    login User;
    printf("================\n");
    printf("=   Register   =\n");
    printf("================\n");
    printf("Masukkan username: ");
    scanf("%15s", User.username);
    printf("Masukkan password: ");
    scanf("%15s", User.password);

    fwrite(&User , sizeof(login), 1, file);
    fclose(file);
    printf("Registrasi berhasil! Silakan login.\n");
}

int loginuser() {
    FILE *file;
    file = fopen("database/login.bin", "rb");

    if (file == NULL) {
        printf("Gagal membuka file\n");
        return 0;
    }

    char username[16];
    char password[16];
    int loginsucces = 0;
    login user;
    
    printf("==================\n");
    printf("=     login      =\n");
    printf("==================\n");
    printf("Username: ");
    scanf("%15s", username);
    printf("Password: ");
    scanf("%15s", password);

    while (fread(&user, sizeof(login), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            loginsucces = 1;
            break; // Keluar dari loop jika login berhasil
        }
    }
    
    fclose(file);
    
    if (loginsucces) {
        printf("Login berhasil!\n");
    } else {
        printf("Coba lagi!\n");
    }
    
    return loginsucces;
}

void mulaiquiz() {
    char username[16];
    char password[16];
    printf("=====================================\n");
    printf("=   Who Wants to be A Billionaire   =\n");
    printf("=          Selamat datang,          =\n");
    printf("=====================================\n");
    printf("Silahkan pilih jenis soal yang anda kuasai: \n");
    printf("1) \n");
    printf("2) \n");
    int soal;
    scanf("%d", &soal);
    switch (soal)
    {
    case 1:
        printf("Fakta Unik Dunia:\n");
        printf("1. Apa nama tempat dengan suhu terendah yang pernah tercatat di bumi?\n");
        printf("   a. Death Valley\n");
        printf("   b. Oymyakon\n");
        printf("   c. Vostok Station\n");
        printf("   d. Sahara\n");
        printf("   Jawaban: c\n\n");

        printf("2. Di negara mana terletak gunung tertinggi di dunia, Mount Everest?\n");
        printf("   a. Nepal\n");
        printf("   b. India\n");
        printf("   c. China\n");
        printf("   d. Bhutan\n");
        printf("   Jawaban: a\n\n");

        printf("3. Apa nama gurun pasir terbesar di dunia?\n");
        printf("   a. Gurun Sahara\n");
        printf("   b. Gurun Gobi\n");
        printf("   c. Gurun Kalahari\n");
        printf("   d. Gurun Atacama\n");
        printf("   Jawaban: a\n\n");

        printf("4. Berapa persen permukaan bumi yang tertutup oleh air?\n");
        printf("   a. 50%%\n");
        printf("   b. 60%%\n");
        printf("   c. 70%%\n");
        printf("   d. 80%%\n");
        printf("   Jawaban: c\n\n");

        printf("5. Negara mana yang memiliki garis pantai terpanjang di dunia?\n");
        printf("   a. Amerika Serikat\n");
        printf("   b. Kanada\n");
        printf("   c. Indonesia\n");
        printf("   d. Australia\n");
        printf("   Jawaban: b\n");
        
        break;
    case 2:
        printf("Fakta Unik Manusia:\n");
        printf("1. Berapa jumlah tulang pada tubuh manusia dewasa?\n");
        printf("   a. 206\n");
        printf("   b. 208\n");
        printf("   c. 210\n");
        printf("   d. 212\n");
        printf("   Jawaban: a\n\n");

        printf("2. Organ apa yang terus tumbuh sepanjang hidup manusia?\n");
        printf("   a. Hati\n");
        printf("   b. Hidung dan telinga\n");
        printf("   c. Otak\n");
        printf("   d. Paru-paru\n");
        printf("   Jawaban: b\n\n");

        printf("3. Apa organ terbesar dalam tubuh manusia?\n");
        printf("   a. Hati\n");
        printf("   b. Kulit\n");
        printf("   c. Usus halus\n");
        printf("   d. Paru-paru\n");
        printf("   Jawaban: b\n\n");

        printf("4. Berapa persen otak manusia terdiri dari air?\n");
        printf("   a. 50%%\n");
        printf("   b. 60%%\n");
        printf("   c. 70%%\n");
        printf("   d. 80%%\n");
        printf("   Jawaban: d\n\n");

        printf("5. Berapa rata-rata detak jantung manusia per menit saat istirahat?\n");
        printf("   a. 50–60 bpm\n");
        printf("   b. 60–100 bpm\n");
        printf("   c. 100–120 bpm\n");
        printf("   d. 120–140 bpm\n");
        printf("   Jawaban: b\n");

        break;
    default:
        printf("Hanya ada pilihan satu ataupun dua, pilih hanya salah satu \n");
        break;
    }


    
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        int akun;
        printf("======================================\n");
        printf("=        Selamat datang di quiz      =\n");
        printf("=    Who Wants to be A Billionaire   =\n");
        printf("======================================\n");
        printf("Sebelumnya, apakah pemain sudah punya akun?\n");
        printf("1) Sudah\n");
        printf("2) Belum\n");
        
        scanf("%d",&akun);
        switch (akun)
        {
        case 1:
            printf(" Jalankan kembali program dengan menggunakan format'./main register' untuk mendaftar\n");
            break;
        case 2:
            printf("Jalankan kembali program dengan menggunakan format './main login' untuk masuk.\n");
            break;
        default:
            printf("Gunakan format yang sesuai.\n");
            break;
        }
        
           
    } else if (argc == 2) {
        if (strcmp(argv[1], "login") == 0) {
            int loginsucces = loginuser();
            if (loginsucces == 1) {
                mulaiquiz();
            }
        } else if (strcmp(argv[1], "register") == 0) {
            registeruser();
        } else {
            printf("Perintah tidak dikenali. Gunakan 'login' atau 'register'.\n");
        }
    } else {
        printf("Gunakan format sesuai!\n");
    }
    return 0;
}
