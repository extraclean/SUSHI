//TODO need occupied bit of each block
//TODO need new moving function

#include<stdlib.h>
#include<stdio.h>

#define left 1
#define right 2
#define up 3
#define down 4

//void down(int,int,int,int,int,int);
//void up(int,int,int,int,int,int);
//void left(int,int,int,int,int,int);
//void right(int,int,int,int,int,int);
void sushi(int,int);
void moveArray(int);

struct structure {
    int count;
    int occupied;
};
struct structure region[100][100];
int* dir;

int main(int argc,char* argv[]){
	
	if(argc!=3){
		printf("input error\n");
		return 0;
	}

    int m=atoi(argv[1]);
	int n=atoi(argv[2]);
	int x=0,y=0,i=0;
    
//    region = (int**)malloc(sizeof(int*)*m);
//    for(i=0;i<m;i++)
//        region[i] = (int*)malloc(m * n * sizeof(int)*n);
    

	sushi(m,n);

	for(y=0;y<n;y++){
		for(x=0;x<m;x++){
			printf("%d,",region[x][y].count);
		}
		printf("\n");
	}
	return 0;
}

void sushi(int m, int n){
	//printf("%d,%d\n",i,j);
	int x=0,y=0,dir=0,count=2;
	region[x][y].count=1;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            region[i][j].occupied=0;
            region[i][j].count=0;
        }
    }
	
}

void moveArray(int position){
    int tmp,i;
    tmp = dir[position];
    for(i=position+1;i<4;i++){
        dir[i-1]=dir[i];
    }
    dir[3]=tmp;
}

//void down(int x,int y,int m,int dir,int count,int limitY){
//    while(limitY<y<m){
//        switch(dir%4){
//            case 0:
//                region[++x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 1:
//                region[x][++y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 2:
//                region[--x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 3:
//                region[x][++y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            default:
//                printf("switch error\n");
//        }
//    }
//    count--;
//    dir--;
//}
//
//void up(int x,int y,int n,int dir,int count,int limitX){
//    while(limitX<x<n){
//        switch(dir%4){
//            case 0:
//                region[++x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 1:
//                region[x][--y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 2:
//                region[--x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 3:
//                region[x][--y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            default:
//                printf("switch error\n");
//        }
//    }
//    count--;
//    dir--;
//}
//
//void right(int x,int y,int n,int dir,int count,int limitX){
//    while(limitX<x<n){
//        switch(dir%4){
//            case 0:
//                region[x][--y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 1:
//                region[++x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 2:
//                region[x][++y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;				
//                break;
//            case 3:
//                region[++x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            default:
//                printf("switch error\n");
//        }
//    }
//    count--;
//    dir--;
//}
//
//void left(int x,int y,int n,int dir,int count,int limitX){
//    while(limitX<y<n){
//        switch(dir%4){
//            case 0:
//                region[x][--y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;				
//                break;
//            case 1:
//                region[--x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            case 2:
//                region[x][++y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;				
//                break;
//            case 3:
//                region[--x][y]=count;
//                //printf("%d,%d\n",x,y);
//                dir++;
//                count++;
//                break;
//            default:
//                printf("switch error\n");
//        }
//    }
//    count--;
//    dir--;
//}
