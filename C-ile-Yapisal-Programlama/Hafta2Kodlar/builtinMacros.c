#include <stdio.h>

int main(){
	printf("Bugünün tarihi:%s\nSaat: %s\nBulunduğumuz Kod Satırı: %d\nBulunulan Dosya: %s\n",__DATE__,__TIME__,__LINE__,__FILE__ );
	return 0;
}