#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int mystrlen(char *s)
{
    int i = 0;

    while(s[i] != '\0')
    {
        i++;
    }

    return i;
}

// Ana program
int main(int argc, char *argv[])
{
    bool line_mode = false;
    char *filename = NULL;

    // Komut satırı argümanlarını işle
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            line_mode = true; // Satır satır işleme modu aktif
        } else {
            filename = argv[i]; // İlk dosya adını kaydet
        }
    }

    // Eğer hem dosya adı hem -l flag'i varsa dosyayı satır satır işle
    if (line_mode && filename != NULL) {
        FILE *fp = fopen(filename, "r");
        if (!fp) {
            perror("Cant Open");
            return 1;
        }

        printf("File \"%s\" lbl:\n", filename);
        char *line = NULL;
        size_t len = 0;
        int line_num = 1;

        while (getline(&line, &len, fp) != -1) {
            // Satır sonundaki \n karakterini temizle
            size_t linelen = strlen(line);
            if (linelen > 0 && line[linelen - 1] == '\n') {
                line[linelen - 1] = '\0';
            }

            int value = mystrlen(line);
            printf("test %d: input \"%s\" :: result => %d\n", line_num++, line, value);
        }

        free(line);
        fclose(fp);
        return 0;
    }

    // Eğer sadece doğrudan argümanlar varsa (örn. ./program 123 -456 +789)
    if (argc >= 2 && !line_mode) {
        printf("CMD args:\n");
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') continue; // flag'leri atla (örn. -l)
            printf("Arg[%d] = \"%s\"\n", i, argv[i]);
            int arg_result = mystrlen(argv[i]);
            printf("atoi result(\"%s\") = %d\n\n", argv[i], arg_result);
        }
    }

    // Standart girişten manuel girdi alma
    char *dizi = NULL;
    size_t boyut = 0;

    printf("Input: ");
    int char_len = getline(&dizi, &boyut, stdin);

    if (char_len == -1) {
        perror("Error: Invalid Input.");
        return 1;
    }

    if (dizi[char_len - 1] == '\n') {
        dizi[char_len - 1] = '\0';
    }

    printf("Input: \"%s\"\n", dizi);
    int sonuc = mystrlen(dizi);
    free(dizi);
    printf("atoi result: %d\n", sonuc);

    return 0;
}
