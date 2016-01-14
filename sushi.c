#include<stdlib.h>
#include<stdio.h>

int** region;
	region = (int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
		region[i] = (int*)malloc(m * n * sizeof(int)*n);

void down(int x,int y,int m,int dir,int count,int limitY){
	while(limitY<y<m){
		switch(dir%4){
			case 0:
				region[++x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 1:
				region[x][++y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			case 2:
				region[--x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 3:
				region[x][++y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			default:
				printf("switch error\n");
		}
	}
	count--;
	dir--;
}

void up(int x,int y,int n,int dir,int count,int limitX){
	while(limitX<x<n){
		switch(dir%4){
			case 0:
				region[++x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 1:
				region[x][--y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			case 2:
				region[--x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 3:
				region[x][--y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			default:
				printf("switch error\n");
		}
	}
	count--;
	dir--;
}

void right(int x,int y,int n,int dir,int count,int limitX){
	while(limitX<x<n){
		switch(dir%4){
			case 0:
				region[x][--y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 1:
				region[++x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			case 2:
				region[x][++y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 3:
				region[++x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			default:
				printf("switch error\n");
		}
	}
	count--;
	dir--;
}

void left(int x,int y,int n,int dir,int count,int limitX){
	while(limitX<y<n){
		switch(dir%4){
			case 0:
				region[x][--y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 1:
				region[--x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			case 2:
				region[x][++y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;				
				break;
			case 3:
				region[--x][y]=count;
				//printf("%d,%d\n",x,y);
				dir++;
				count++;
				break;
			default:
				printf("switch error\n");
		}
	}
	count--;
	dir--;
}

void sushi(int m, int n, int **region){
	//printf("%d,%d\n",i,j);
	int x=0,y=0,dir=0,count=2;
	region[x][y]=1;

	
}

int main(int argc,char* argv[]){
	
	if(argc!=3){
		printf("input error\n");
		return 0;
	}

	int m=atoi(argv[1]);
	int n=atoi(argv[2]);
	int x=0,y=0,i=0;

	sushi(m,n,region);

	for(y=0;y<n;y++){
		for(x=0;x<m;x++){
			printf("%d,",region[x][y]);
		}
		printf("\n");
	}
	return 0;
}
