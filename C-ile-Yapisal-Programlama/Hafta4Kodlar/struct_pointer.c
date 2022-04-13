#include <stdio.h>
#include <string.h>

struct kisi{
	char name[20];
	char lastname[20];
	int age;
};

int main(){
	struct kisi p1;
	p1.age=12;
	strcpy(p1.name,"Ayca");
	strcpy(p1.lastname,"Aydogan");
}