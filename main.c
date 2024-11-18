#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
// struct untuk menyimpan username dan password    
    char username[50];
    char password[50];
}login ;

void registeruser(){
// Fungsi untuk register

FILE *file;
file= fopen("database/login.bin","ab");
if(file == NULL){
    printf("Gagal membuka file");
}
fclose(file);
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


int main(){
// Badan utama jalannya program


return 0;
}
