#include <stdio.h>      // printf, getline, fopen, fclose, etc.
#include <stdlib.h>     // malloc, free, atoi, exit, etc.
#include <string.h>     // strlen
#include <ctype.h>      // isdigit
#include <stdbool.h>    // bool veri tipi desteği (true / false)

// Kullanıcı tanımlı atoi fonksiyonu: bir string'i (dizeyi) integer'a çevirir
int myatoi(char *s)
{
    int i = 0, result = 0;
    bool negative = false;  // Sayı negatif mi?
    
    // Baştaki boşlukları atla
    while (s[i] == ' ') {
        i++;
    }

    // Opsiyonel: işaret kontrolü (- veya +)
    if (s[i] == '-') {
        negative = true;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Sayı karakterlerini sırayla işle (0-9)
    while (isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    // Sonuç döndürülmeden önce işaret kontrol edilir
    return negative ? -result : result;
}

// Ana program
int main(int argc, char *argv[])
{
    // Komut satırında argüman verildiyse işlenir
    if (argc >= 2) {
        printf("Komut satırı argümanları:\n");
        for (int i = 1; i < argc; i++) {
            printf("Argüman[%d] = \"%s\"\n", i, argv[i]);

            // Her argüman için myatoi() uygulanır ve sonuç basılır
            int arg_result = myatoi(argv[i]);
            printf("myatoi(\"%s\") = %d\n\n", argv[i], arg_result);
        }
    }

    // Kullanıcıdan manuel giriş alma (stdin)
    char *dizi = NULL;          // getline için dinamik bellek işaretçisi
    size_t boyut = 0;           // getline tarafından doldurulacak uzunluk

    printf("Bir sayı giriniz: ");

    // getline() -> Kullanıcının girişini alır (enter'a kadar)
    int char_len = getline(&dizi, &boyut, stdin);

    // Hata kontrolü: getline başarısızsa
    if (char_len == -1) {
        perror("Hata: Girdi alınamadı.");
        return 1;
    }

    // Giriş sonundaki newline karakteri (\n) varsa, onu kes
    if (dizi[char_len - 1] == '\n') {
        dizi[char_len - 1] = '\0';
    }

    // Girdiyi ekrana yazdır
    printf("Girdiğiniz: \"%s\"\n", dizi);

    // Girdiyi tam sayıya çevir
    int sonuc = myatoi(dizi);

    // Belleği serbest bırak
    free(dizi);

    // Sonucu yazdır
    printf("myatoi sonucu: %d\n", sonuc);

    return 0;
}
