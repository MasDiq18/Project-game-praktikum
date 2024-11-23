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
        
        break;
    case 2:

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
