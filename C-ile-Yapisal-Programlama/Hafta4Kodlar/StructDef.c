#include <stdio.h>
#include <string.h>

struct student{
	int id;
	int age;
	char fname[20];
	char lname[20];
	char department[];
};

int main(){
		struct student std1;
		std1.id=18011004;
		std1.age=22;
		strcpy(std1.department,"Computer Engineering");
		strcpy(std1.fname,"Umut");
		strcpy(std1.lname,"Guzel");
		
		printf("%d-%d-%s-%s-%s",std1.id,std1.age,std1.department,std1.fname,std1.lname);
		return 0;
}