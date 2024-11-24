#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[16];
    char password[16];
} login;

int isUsernameDuplicate(char *username){
    FILE *file = fopen("database/login.bin", "rb");
    if(file == NULL){
        printf("Gagal membuka file!"); //anggap username sudah digunakan
        return 1;
    }
    login user;
    while(fread(&user, sizeof(login), 1, file)){
        if(strcmp(user.username , username)== 0){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void registeruser() {
    // Fungsi untuk register
    FILE *file;
    file = fopen("database/login.bin", "ab");
    if (file == NULL) {
        printf("Gagal membuka file\n");
        return;
    }
    
    login newuser;
    printf("================\n");
    printf("=   Register   =\n");
    printf("================\n");

    while(1){
        printf("Masukkan username: ");
        scanf("%15s", newuser.username);

        if(isUsernameDuplicate(newuser.username)){
            printf("Username tersebut sudah digunakan\n");
            printf("coba lagi dengan username yang berbeda\n");
        }else{
            break;
            }
    }

    printf("Masukkan password: ");
    scanf("%15s", newuser.password);

    fwrite(&newuser, sizeof(login), 1, file);
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
    printf("=     Login      =\n");
    printf("==================\n");
    printf("Username: ");
    scanf("%15s", username);
    printf("Password: ");
    scanf("%15s", password);

    while (fread(&user, sizeof(login), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            loginsucces = 1;
            break;
        }
    }
    
    fclose(file);
    
    if (loginsucces) {
        printf("Login berhasil!\n");
    } else {
        printf("Login gagal. Coba lagi!\n");
    }
    
    return loginsucces;
}

void mulaiquiz() {
    int skor = 0;
    int jawabanBenar;

    printf("=====================================\n");
    printf("=   Who Wants to be A Millionaire   =\n");
    printf("=====================================\n");
    printf("Silakan pilih jenis soal yang Anda kuasai:\n");
    printf("1) Fakta Unik Dunia\n");
    printf("2) Fakta Unik Manusia\n");
    int soal;
    printf("Masukkan pilihan anda: ");
    scanf("%d", &soal);

    switch (soal) {
    case 1:
        printf("Fakta Unik Dunia:\n");

        printf("1. Apa nama tempat dengan suhu terendah yang pernah tercatat di bumi?\n");
        printf("   a. Death Valley\n");
        printf("   b. Oymyakon\n");
        printf("   c. Vostok Station\n");
        printf("   d. Sahara\n");
        printf("Jawaban Anda: ");
        char jawab1;
        scanf(" %c", &jawab1);
        jawabanBenar = (jawab1 == 'c' || jawab1 == 'C');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("2. Di negara mana terletak gunung tertinggi di dunia, Mount Everest?\n");
        printf("   a. Nepal\n");
        printf("   b. India\n");
        printf("   c. China\n");
        printf("   d. Bhutan\n");
        printf("Jawaban Anda: ");
        char jawab2;
        scanf(" %c", &jawab2);
        jawabanBenar = (jawab2 == 'a' || jawab2 == 'A');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("3. Apa nama gurun pasir terbesar di dunia?\n");
        printf("   a. Gurun Sahara\n");
        printf("   b. Gurun Gobi\n");
        printf("   c. Gurun Kalahari\n");
        printf("   d. Gurun Atacama\n");
        printf("Jawaban Anda: ");
        char jawab3;
        scanf(" %c", &jawab3);
        jawabanBenar = (jawab3 == 'a' || jawab3 == 'A');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("4. Berapa persen permukaan bumi yang tertutup oleh air?\n");
        printf("   a. 50%%\n");
        printf("   b. 60%%\n");
        printf("   c. 70%%\n");
        printf("   d. 80%%\n");
        printf("Jawaban Anda: ");
        char jawab4;
        scanf(" %c", &jawab4);
        jawabanBenar = (jawab4 == 'c' || jawab4 == 'C');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("5. Negara mana yang memiliki garis pantai terpanjang di dunia?\n");
        printf("   a. Amerika Serikat\n");
        printf("   b. Kanada\n");
        printf("   c. Indonesia\n");
        printf("   d. Australia\n");
        printf("Jawaban Anda: ");
        char jawab5;
        scanf(" %c", &jawab5);
        jawabanBenar = (jawab5 == 'b' || jawab5 == 'B');
        if (jawabanBenar) skor += 200000;
        else break;

        break;

    case 2:
        printf("Fakta Unik Manusia:\n");

        printf("1. Berapa jumlah tulang pada tubuh manusia dewasa?\n");
        printf("   a. 206\n");
        printf("   b. 208\n");
        printf("   c. 210\n");
        printf("   d. 212\n");
        printf("Jawaban Anda: ");
        char jawab6;
        scanf(" %c", &jawab6);
        jawabanBenar = (jawab6 == 'a' || jawab6 == 'A');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("2. Organ apa yang terus tumbuh sepanjang hidup manusia?\n");
        printf("   a. Hati\n");
        printf("   b. Hidung dan telinga\n");
        printf("   c. Otak\n");
        printf("   d. Paru-paru\n");
        printf("Jawaban Anda: ");
        char jawab7;
        scanf(" %c", &jawab7);
        jawabanBenar = (jawab7 == 'b' || jawab7 == 'B');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("3. Apa organ terbesar dalam tubuh manusia?\n");
        printf("   a. Hati\n");
        printf("   b. Kulit\n");
        printf("   c. Usus halus\n");
        printf("   d. Paru-paru\n");
        printf("Jawaban Anda: ");
        char jawab8;
        scanf(" %c", &jawab8);
        jawabanBenar = (jawab8 == 'b' || jawab8 == 'B');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("4. Berapa persen otak manusia terdiri dari air?\n");
        printf("   a. 50%%\n");
        printf("   b. 60%%\n");
        printf("   c. 70%%\n");
        printf("   d. 80%%\n");
        printf("Jawaban Anda: ");
        char jawab9;
        scanf(" %c", &jawab9);
        jawabanBenar = (jawab9 == 'd' || jawab9 == 'D');
        if (jawabanBenar) skor += 200000;
        else break;

        printf("5. Berapa rata-rata detak jantung manusia per menit saat istirahat?\n");
        printf("   a. 50-60 bpm\n");
        printf("   b. 60-100 bpm\n");
        printf("   c. 100-120 bpm\n");
        printf("   d. 120-140 bpm\n");
        printf("Jawaban Anda: ");
        char jawab10;
        scanf(" %c", &jawab10);
        jawabanBenar = (jawab10 == 'b' || jawab10 == 'B');
        if (jawabanBenar) skor += 200000;
        else break;

        break;

    default:
        printf("Hanya ada pilihan 1 atau 2. Silakan pilih salah satu.\n");
        break;
    }

    printf("\nQuiz selesai! Total uang yang anda dapatkan adalah: Rp.%d\n", skor);
}

int menu(){
    int choice;
    int loggedIn = 0;

        do {
            printf("\n=== Menu ===\n");
            printf("1. Mulai Quiz\n");
            printf("2. Peraturan Quiz\n");
            printf("3. Keluar\n");
            printf("Pilihan Anda: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    mulaiquiz();
                    break;
                case 2:
                    peraturan();
                    break;
                case 3:
                    printf("Terima kasih telah menggunakan program ini!\n");
                    break;    
                default:
                    printf("Pilihan tidak valid.\n");
            }
        } while (choice != 3);
    

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        int akun;
        printf("======================================\n");
        printf("=        Selamat datang di quiz      =\n");
        printf("=    Who Wants to be A Millionaire   =\n");
        printf("======================================\n");
        printf("Apakah Anda sudah memiliki akun?\n");
        printf("1) Sudah\n");
        printf("2) Belum\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &akun);
        switch (akun) {
        case 1:
            printf("Jalankan kembali program dengan format './main login' untuk masuk.\n");
            break;
        case 2:
            printf("Jalankan kembali program dengan format './main register' untuk mendaftar.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
    } else if (argc == 2) {
        if (strcmp(argv[1], "login") == 0) {
            int loginsucces = loginuser();
            if (loginsucces) {
                mulaiquiz();
            }
        } else if (strcmp(argv[1], "register") == 0) {
            registeruser();
        } else {
            printf("Perintah tidak dikenali. Gunakan 'login' atau 'register'.\n");
        }
    } else {
        printf("Gunakan format yang sesuai.\n");
    }
    return 0;
}
