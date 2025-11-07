#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int myatoi(char *s)
{
    int i = 0, result = 0, isNegative = 0;

    // Atla: baştaki boşlukları
    while (isspace(s[i])) i++;

    // Negatif sayı kontrolü
    if (s[i] == '-') {
        isNegative = 1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Rakamları işle
    while (isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return isNegative ? -result : result;
    printf("myatois func : %s",s);
}

int main(void)
{	
	char *dizi = NULL;
    size_t boyut = 0;
	
	printf("\n Dizgi Giriniz -- > \n");

    //ssize_t char_len = getline(&dizi, &boyut, stdin);
    int char_len = getline(&dizi, &boyut, stdin);

    if (char_len == -1)
    {
        perror("Error, Unknown Input Format");
        return 1;
    }
	
    printf("Your Writining : %s", dizi);
    int sonuc = myatoi(dizi);
    
    free(dizi);
    printf("Your Writining after free: %s", dizi);
    printf("Myatoi Result: %d", sonuc);
	return 0;
}
