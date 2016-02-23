#include<stdlib.h>
#include<stdio.h>

#define left 1
#define right 2
#define up 3
#define down 4

void sushi(int,int);
int maintainQueue(int);
void move();
void checkOccupied();

int** region=0;
int* dir;
int count=0;//for change line in checkOccupied
int x=0,y=0;

int main(int argc,char* argv[]){
    
    if(argc!=3){
        printf("input error\n");
        return 0;
    }
    
    int m=atoi(argv[1]);
    int n=atoi(argv[2]);
    int i=0,j=0;
    
    region = (int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++)
        region[i] = (int*)malloc(m * n * sizeof(int)*n);
    
    sushi(m,n);
    
    //TODO animize it
    for(j=0;j<n;j++){//print results
        for(i=0;i<m;i++){
            printf("%d,",region[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void sushi(int m, int n){
    //printf("%d,%d\n",i,j);    region[x][y]=1;
    int i;
    dir[0]=right; dir[1]=down; dir[2]=left;//queue of downward
    while(y<n)
        checkOccupied();//TODO return 1/0 to determine to change line or not
    if(n%2){//if y is an odd number, travel reverse
        while(x<m){
            if(x%4==2 && y==n){//two statements happen in the same situation
                dir[0]=right; dir[1]=up; dir[2]=left;//queue of upward
                while(y>=0)//before reach top
                    checkOccupied();
            }else if(x%4==0 && y==0){//two statements happen in the same situation
                dir[0]=right; dir[1]=down; dir[2]=left;//queue of downward
                while(y<n)
                    checkOccupied();
            }else printf("error 1");
        }
    }else{//if y is an even number, travel perpendically
        dir[0]=up; dir[1]=right; dir[2]=down;//queue of downward
        //TODO compensate two step
    }
    
    dir[0]=up; dir[1]=right; dir[2]=down;//queue of rightward
    while(y<m)
        checkOccupied();
}

//TODO how to end (use count?)
//TODO how to change line differently (set key?(odd/even))
void checkOccupied(){
    //wrong (how about travel upward
    if(y==0 || y==n-1 && count==1){//4 cases 1:right, 2:not yet, 3:wrong and not yet, 4:wrong.
        return 1;//1: travel reverse
    }else if(y==0 || y==n-1 && count==0){
        count++;
    }else if(y==0 || y==n-1 && count==1){
        
    }
        
    int i,noWay=0;
    for(i=0;i<3;i++){
        if(dir[i]==left){
            if(region[x-1][y]==0)
                x--;
            move();
            if(maintainQueue(i) && key){//change line & reverse the path(odd)
                dir[0]=up; dir[1]=right; dir[2]=down;//queue of rightward
                checkOccupied();
            }else if(maintainQueue(i)){//change line after waste 2s(even)
                dir[0]=right; dir[1]=down; dir[2]=left;//queue of downward
                checkOccupied();
            }
        }else if(dir[i]==right){
            if(region[x+1][y]==0){
                x++;
                move();
                if(maintainQueue(i) && key){//change line & reverse the path(odd)
                    dir[0]=up; dir[1]=left; dir[2]=down;//queue of leftward
                    checkOccupied();
                }else if(maintainQueue(i)){//change line after waste 2s(even)
                    dir[0]=right; dir[1]=down; dir[2]=left;//queue of downward
                    checkOccupied();
                }
                
            }
        }else if(dir[i]==up){
            if(region[x][y-1]==0){
                y--;
                move();
                if(maintainQueue(i) && key){//change line & reverse the path(odd)
                    dir[0]=right; dir[1]=down; dir[2]=left;//queue of downward
                    checkOccupied();
                }else if(maintainQueue(i)){//change line after waste 2s(even)
                    dir[0]=up; dir[1]=right; dir[2]=down;//queue of rightward strange!!!!!!!!!!!!!
                    checkOccupied();
                }
            }
        }else if(dir[i]==down){
            if(region[x][y+1]==0){
                y++;
                move();
                if(maintainQueue(i) && key){//change line & reverse the path(odd)
                    dir[0]=up; dir[1]=left; dir[2]=down;//queue of leftward
                    checkOccupied();
                }else if(maintainQueue(i)){//change line after waste 2s(even)
                    dir[0]=right; dir[1]=down; dir[2]=left;//queue of downward
                    checkOccupied();
                }
                
            }
        }else noWay++;
    }
    if(noWay==3)
        //TODO go dir[0]
        }

void move(){
    region[x][y]=count;
    count++;
}

int maintainQueue(int position){
    int tmp,i;
    tmp = dir[position];
    for(i=position+1;i<3;i++){
        dir[i-1]=dir[i];
    }
    dir[2]=tmp;
    
    if(position==2){//position = 2 means two continuous direction were choosen
        return 1;//1 -> change row or column
    }else return 0;//0 -> keep going till change line
}
