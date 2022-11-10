#include <stdio.h>
int main() {
    char ch;
    printf("Bir karakter giriniz:");
    scanf("%c",&ch);
	scanf("%c",&ch);
	
    if(ch>='a'&& ch<='z') {
        printf("ch: %c is alphabet",&ch);
    }
    else if(ch>='0'&& ch<='9') {
        printf("ch: %c is digit",ch);
    }
    else {
        printf("ch: %c is special character",ch);
    }
return 0;
}
