#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int StringMakerFuncCalls =0 ;
int PrintConsoleFuncCalls =0 ;
int mismatch =0;
char ActualColorGuide[25][2];

void ActualColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
         ActualColorGuide[i+j][0]=majorColor[i];  
         ActualColorGuide[i+j][1]=minorColor[j];
        }
    }
}

void PrintStringMaker( int MajorColorId , int MinorColorId);
void PrintOnConsole(int PairNum, const char *MajorColor, const char *MinorColor);

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
         PrintStringMaker(i,j);  
        }
    }
    return i * j;
}

void PrintStringMaker( int MajorColorId , int MinorColorId){
    PrintOnConsole( (MajorColorId*5+ MinorColorId) , majorColor[MajorColorId] , minorColor[MajorColorId]);
    StringMakerFuncCalls+=1;
        if(((MajorColorId*5+ MinorColorId) <=0 || (MajorColorId*5+ MinorColorId) >25) || (majorColor[MajorColorId] != ActualColorGuide[MajorColorId*5+ MinorColorId][0]) || (minorColor[MajorColorId]!=ActualColorGuide[MajorColorId*5+ MinorColorId][1])){
             mismatch = 1;
         }
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
