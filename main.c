#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
// struct untuk menyimpan username dan password    
    char username[50];
    char password[50];
} login;

void registeruser(){
// Fungsi untuk register
FILE *file;
file= fopen("database/login.bin","ab");
if(file == NULL){
    printf("Gagal membuka file");
    return;
}
    login User;
    printf(">>> Register <<<\n");
    printf("Masukkan username: ");
        scanf("%s", User.username);
    printf("Masukkan password: ");
        scanf("%s", User.password);

    fwrite(&User, sizeof(login), 1, file);
        fclose(file);
        printf("Registrasi berhasil! Silakan login.\n");

}
int loginuser(){
// Fungsi login

}

void startquiz(){
// Fungsi untuk mulai quiz

}

int rulesquiz(){
// Fungsi untuk memunculkan peraturan game  

}

int menu(){
    
}


int main(int argc, char *argv[]){
// Badan utama jalannya program
    if(argc == 0){
        //Untuk menampilkan menu awal
        

        //Tanyakan pada user apakah sudah memiliki akun

    }

    if(argc == 1){
        if(argv[1] == 'register' ){
            //Untuk register
            registeruser();
        }
        else if(argv[1] == 'login'){
            //Untuk login
            loginuser();


            int loggedin;
            //Kalau login berhasil, beralih ke menu
        }
        else{
            //Kalau user memasukkan format yang tidak sesuai
            printf("Silahkan masuk sesuai format yang berlaku\n");
            printf("* ./main register bagi pengguna baru \n");
            printf("* ./main login bagi yang sudah register \n");

        }
    }

return 0;
}
