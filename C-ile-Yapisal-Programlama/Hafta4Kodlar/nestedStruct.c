#include <stdio.h>

typedef struct fullname{
	char fname[10];
	char lname[10];
}fname;

typedef struct person{
	int id;
	fullname name;
}person;

int main(){
	person p1;
	p1.id=111111111;
	strcpy(p1.name.fname,"Isim");
	strcpy(p1.name.lname,"Soyisim");
}