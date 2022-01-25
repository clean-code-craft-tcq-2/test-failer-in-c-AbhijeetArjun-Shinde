#include <stdio.h>
#include <assert.h>

int StringMakerFuncCalls =0 ;
int PrintConsoleFuncCalls =0 ;
int mismatch =0;

int PrintStringMaker( int MajorColorId , int MinorColorId);
void PrintOnConsole(int PairNum, const char *MajorColor, const char *MinorColor);

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
         int PairNum[i*5+j] = PrintStringMaker(i,j); 
         if((PairNum <=0 && PairNum >25){
             mismatch = 1;
         }
        }
    }
    return i * j;
}

int PrintStringMaker( int MajorColorId , int MinorColorId){
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    PrintOnConsole( (MajorColorId*5+ MinorColorId) , majorColor[MajorColorId] , minorColor[MajorColorId]);
    StringMakerFuncCalls+=1;
    return (MajorColorId*5+ MinorColorId);
    }

void PrintOnConsole(int PairNum,const char *MajorColor ,const char *MinorColor){
    printf("%d | %s | %s\n",PairNum, MajorColor, MinorColor);
    PrintConsoleFuncCalls +=1;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert ( mismatch ==0);
    assert(StringMakerFuncCalls == 25);
    assert(PrintConsoleFuncCalls == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
