#include <stdio.h>

int main(){
	enum font_type{
		bold=1,  //0001
		italic=2, //0010
		underlined=4, //0100
		highlighted=8 //1000
	};
	
	int font1=bold|underlined;
	int font2=highlighted|underlined;
	int font3=bold|italic|underlined|highlighted;

	printf("%d-%d-%d\n",font1,font2,font3 );



	return 0;
}