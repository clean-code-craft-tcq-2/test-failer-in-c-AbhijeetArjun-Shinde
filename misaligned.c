#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


typedef struct {
     int PairID;
     char MajorColor[8];
     char MinorColor[8];
}ColorPair; 

ColorPair ActualColorPattern[25];

int PairIdMismatchCnt = 0;
int MajorColorMismatchCnt = 0;
int MinorColorMismatchCnt = 0;

void ActualColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
             ActualColorPattern[i*5 +j].PairID= i*5+j ;
             strcpy(ActualColorPattern[i*5 +j].MajorColor,majorColor[i] );
             strcpy(ActualColorPattern[i*5 +j].MinorColor,minorColor[j] );
        }
    }
}

void FramePrintString( int MajorColorId , int MinorColorId);
void PrintOnConsole(int PairNum, const char *MajorColor, const char *MinorColor);

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
         FramePrintString(i,j);  
        }
    }
    return i * j;
}

void FramePrintString( int MajorColorId , int MinorColorId){
    PrintOnConsole( (MajorColorId*5+ MinorColorId) , majorColor[MajorColorId] , minorColor[MajorColorId]);
    // Checking for PairNumber Mismatch
    if(ActualColorPattern[MajorColorId*5+MajorColorId].PairID != MajorColorId*5+MajorColorId) {
        PairIdMismatchCnt +=1;
    }
    //Checking for Major Color mismatch
    else if (ActualColorPattern[MajorColorId*5+MajorColorId].MajorColor != majorColor[MajorColorId]) {
        MajorColorMismatchCnt +=1 ;
    }
    // Checking for minor color mismatch
    else if(ActualColorPattern[MajorColorId*5+MajorColorId].MinorColor != minorColor[MajorColorId]){
        MinorColorMismatchCnt +=1 ;
    }
    }

void PrintOnConsole(int PairNum,const char *MajorColor ,const char *MinorColor){
    printf("%d | %s | %s\n",PairNum, MajorColor, MinorColor);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert ( PairIdMismatchCnt ==0);
    assert(MajorColorMismatchCnt == 0);
    assert(MinorColorMismatchCnt == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
