////////////////////////////Umut Guzel/////////////////////////////////////////
////////////////////////////18011004//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER 200

typedef struct pgm{
	char type[5];
	int row;
	int col;
	int max;
	int **mat;
}pgm;

pgm* readPGMfile(char* filename, pgm *pgmdata){
	int i,j,rw,cl;
	FILE *fp;
	char type[5];
	char check[BUFFER];
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("open attempt failed!");
		exit(1);
	}
	fscanf(fp,"%s\n",type);
	strcpy(pgmdata->type,type);
	if(strcmp(type,"P2")!=0){
		printf("invalid file type");
		exit(1);
	}
	fgets(check,BUFFER,fp);
	if(check[0]=='#'){
		fgets(check,BUFFER,fp);
	}
	sscanf(check,"%d %d",&cl,&rw);
	pgmdata->col=cl;
	pgmdata->row=rw;
	fscanf(fp,"%d",&pgmdata->max);
	pgmdata->mat=(int**)malloc(rw*sizeof(int*));
	for(i=0;i<rw;i++){
		pgmdata->mat[i]=(int*)malloc(cl*sizeof(int));
	}
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			fscanf(fp,"%d ",&pgmdata->mat[i][j]);
		}
	}
	fclose(fp);
	return pgmdata;	
}

void encodePGM(pgm *pgmdata){
	int i,j,cnt,value;
	FILE *fp;
	bool last_op;
	fp=fopen("test_encoded.txt","w");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	value=pgmdata->mat[0][0];
	cnt=0;	
	fprintf(fp,"%c%c\n",pgmdata->type[0],pgmdata->type[1]);
	fprintf(fp,"%d %d\n",pgmdata->col,pgmdata->row);
	fprintf(fp,"%d\n",pgmdata->max);
	for(i=0;i<pgmdata->row;i++){
		for(j=0;j<pgmdata->col;j++){
			if(value==pgmdata->mat[i][j]){
				cnt++;
				last_op=true;
			}else{
				fprintf(fp,"%d %d \n",cnt,value);
				value=pgmdata->mat[i][j];
				cnt=1;
				last_op=false;
			}
		}
	}
	if(last_op==true){
		fprintf(fp,"%d %d ",cnt,value);
		value=pgmdata->mat[i-1][j-1];
	}
	fclose(fp);
}

bool control(){
	FILE *fp;
	char type[5];
	int rw,cl,tmp_cnt,tmp_val=0,past_val,max;
	fp=fopen("test_encoded.txt","r");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	fscanf(fp,"%s",type);
	fscanf(fp,"%d %d",&rw,&cl);
	fscanf(fp,"%d",&max);
	int pxcnt=0;
	while(!feof(fp)){
		past_val=tmp_val;
		fscanf(fp,"%d %d\n",&tmp_cnt,&tmp_val);
		pxcnt+=tmp_cnt;
		if(tmp_val<0&&tmp_val>255){
			fclose(fp);
			printf("a color value is out of bound!!\n");
			return false;			
		}
		if(tmp_val==past_val){
			fclose(fp);
			printf("%d %d\n",past_val,tmp_val);
			printf("sequential values cannot be equal!!\n");
			return false;
		}
	}
	if(pxcnt!=(rw*cl)){
		fclose(fp);
		printf("pixel count is not equal to row*column!!\n");
		return false;
	}
	fclose(fp);	
	printf("this file is compatible to decode\n");
	return true;
		
}

void decodePGM(){
	int i,j,rw,cl,max,val,repeat,total,cnt=0;
	char type[5];
	FILE *fp,*fp2;
	fp=fopen("test_decoded.pgm","w");
	fp2=fopen("test_encoded.txt","r");
	
	fscanf(fp2,"%s",type);
	fprintf(fp,"%c%c\n",type[0],type[1]);
	
	fscanf(fp2,"%d %d",&cl,&rw);
	fprintf(fp,"%d %d\n",cl,rw);
	
	fscanf(fp2,"%d",&max);
	fprintf(fp,"%d\n",max);
	
	total=rw*cl;
	while(total>0){
		fscanf(fp2,"%d %d",&repeat,&val);
		for(i=0;i<repeat;i++){
			fprintf(fp,"%d ",val);
			cnt++;
			if(cnt==cl){
				cnt=0;
				fprintf(fp,"\n");
			}
		}
		total=total-repeat;
	}
	
}

void changeColor(int old_color,int new_color){
	int i,j,total,rw,cl,idx1=0,cnt=0,val,repeat;
	bool last_op;
	FILE *fp;
	fp=fopen("test_encoded.txt","r");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	pgm *p;
	p=(pgm*)malloc(sizeof(pgm));
	
	fscanf(fp,"%s",p->type);
	fscanf(fp,"%d %d",&p->col,&p->row);	
	fscanf(fp,"%d",&p->max);
	printf("\ntype: %c%c\nColumns: %d \nRows:%d \nMax Color Value%d\n\n",p->type[0],p->type[1],p->col,p->row,p->max);
	
	rw=p->row;
	cl=p->col;
	
	p->mat=(int**)malloc(rw*sizeof(int*));
	for(i=0;i<rw;i++){
		p->mat[i]=(int*)malloc(cl*sizeof(int));
	}
	
	total=rw*cl;
	
	while(total>0){
		fscanf(fp,"%d %d",&repeat,&val);
		for(i=0;i<repeat;i++){
			if(val==old_color){
				val=new_color;
			}	
			p->mat[idx1][cnt]=val;
			//printf("%d ",p->mat[idx1][cnt]);
			cnt++;
			if(cnt==cl){
				cnt=0;
				idx1++;
			}
			
		}
		total=total-repeat;
	}
	fclose(fp);
	
	fp=fopen("test_encoded.txt","w");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	
	fprintf(fp,"%c%c\n",p->type[0],p->type[1]);
	fprintf(fp,"%d %d\n",p->col,p->row);
	fprintf(fp,"%d\n",p->max);
	val=p->mat[0][0];
	cnt=0;
	for(i=0;i<p->row;i++){
		for(j=0;j<p->col;j++){
			printf("%d ",p->mat[i][j]);
			if(val==p->mat[i][j]){
				cnt++;
				last_op=true;
			}else{
				fprintf(fp,"%d %d\n",cnt,val);
				val=p->mat[i][j];
				cnt=1;
				last_op=false;
			}
		}
		printf("\n");
	}
	if(last_op==true){
		fprintf(fp,"%d %d ",cnt,val);
		val=p->mat[i-1][j-1];
	}
	fclose(fp);
	free(p);
}


void changePixelVal(int rwco,int clco, int new_val){
	int i,j,total,rw,cl,idx1=0,cnt=0,val,repeat;
	bool last_op;
	FILE *fp;
	fp=fopen("test_encoded.txt","r");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	pgm *p;
	p=(pgm*)malloc(sizeof(pgm));
	
	fscanf(fp,"%s",p->type);
	fscanf(fp,"%d %d",&p->col,&p->row);	
	fscanf(fp,"%d",&p->max);
	printf("\ntype: %c%c\nColumns: %d \nRows:%d \nMax Color Value%d\n\n",p->type[0],p->type[1],p->col,p->row,p->max);
	
	rw=p->row;
	cl=p->col;
	
	p->mat=(int**)malloc(rw*sizeof(int*));
	for(i=0;i<rw;i++){
		p->mat[i]=(int*)malloc(cl*sizeof(int));
	}
	
	total=rw*cl;
	
	while(total>0){
		fscanf(fp,"%d %d",&repeat,&val);
		for(i=0;i<repeat;i++){
			if(idx1==rwco&&cnt==clco){
				p->mat[idx1][cnt]=new_val;
			}else{
				p->mat[idx1][cnt]=val;
			}
			cnt++;
			if(cnt==cl){
				cnt=0;
				idx1++;
			}
			
		}
		total=total-repeat;
	}
	fclose(fp);
	fp=fopen("test_encoded.txt","w");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	
	fprintf(fp,"%c%c\n",p->type[0],p->type[1]);
	fprintf(fp,"%d %d\n",p->col,p->row);
	fprintf(fp,"%d\n",p->max);
	val=p->mat[0][0];
	cnt=0;
	for(i=0;i<p->row;i++){
		for(j=0;j<p->col;j++){
			if(val==p->mat[i][j]){
				cnt++;
				last_op=true;
			}else{
				fprintf(fp,"%d %d\n",cnt,val);
				val=p->mat[i][j];
				cnt=1;
				last_op=false;
			}
			printf("%d ",p->mat[i][j]);
		}
		printf("\n");
	}
	
	if(last_op==true){
		fprintf(fp,"%d %d ",cnt,val);
		val=p->mat[i-1][j-1];
	}
	fclose(fp);
	free(p);	
}


void createHistogram(){
	int rw,cl,max,cnt,val,i;
	FILE *fp;
	char type[5];
	int colors[256];
	fp=fopen("test_encoded.txt","r");
	if(fp==NULL){
		printf("open attempt failed!!");
		exit(1);
	}
	fscanf(fp,"%s",type);
	fscanf(fp,"%d %d",&rw,&cl);
	fscanf(fp,"%d",&max);
	
	for(i=0;i<256;i++){
		colors[i]=0;
	}
	
	while(!feof(fp)){
		fscanf(fp,"%d %d\n",&cnt,&val);
		colors[val]+=cnt;
	}
	printf("\nColor Value     count\n___________     _______\n");
	for(i=0;i<256;i++){
		if(colors[i]!=0){
			printf("%d---------------> %d\n",i,colors[i]);
		}
	}
	fclose(fp);
}


int main(){
	int input,input2,x,y,z;
	pgm *pgmdata;
	char filename[25];
	pgmdata=(pgm*)malloc(sizeof(pgm));
    input=6;
	while(input!=0){
		printf("Author:Umut Guzel-18011004\n####################MAIN MENU####################\n1.read PGM file\n2.Compress PGM file\n3.decode PGM file\n4.Operations(change color,change pixel value, create histogram)\n0.exit\n");
		printf("input: ");
		scanf("%d",&input);
		switch(input){
			case 1:
				printf("please enter name of the file: ");
				scanf("%s",filename);
				readPGMfile(filename,pgmdata);
				printf("operation successful\n");
				break;
			case 2:
				encodePGM(pgmdata);
				printf("operation successful\n");
				break;
			case 3:
				if(control()==true){
					decodePGM();
					printf("operation successful\n");
				}
				break;
			case 4:
				printf("\n\nPlease choose an operation: \n1.Change Color\n2.Change a pixel's value\n3.Create Histogram\n0.main menu\n");
				printf("input: "); 
				scanf("%d",&input2);
				switch(input2){
					case 1:
						printf("please enter the color value you want to change: ");
						scanf("%d",&x);
						printf("please enter the new color value: ");
						scanf("%d",&y);
						if(x>=0&&x<=255&&y>=0&&y<=255){
							changeColor(x,y);
						}else{
							printf("the color value out of bound");
						}
						break;
					case 2:
						printf("please enter the row: ");
						scanf("%d",&x);
						printf("please enter the column: ");
						scanf("%d",&y);
						printf("please enter the new color value: ");
						scanf("%d",&z);
						changePixelVal(x,y,z);
						break;
					case 3:
						createHistogram();
						break;
					case 0:
						break;
					default:
						printf("you entered invalid value...returning to main menu.\n");
				}
			case 0:
				break;
			default:
				printf("you entered invalid value...please try again.\n");
		}
	}
	
	return 0;
}
