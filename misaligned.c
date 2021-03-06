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

void ActualColorMap( int i , int j );
void FramePrintString( int MajorColorId , int MinorColorId);
void PrintOnConsole(int PairNum, const char *MajorColor, const char *MinorColor);

void ActualColorMap( int i , int j ) {
             ActualColorPattern[i*5 +j].PairID= i*5+j+1 ;
             strcpy(ActualColorPattern[i*5 +j].MajorColor,majorColor[i] );
             strcpy(ActualColorPattern[i*5 +j].MinorColor,minorColor[j] );
}

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
    PrintOnConsole( (MajorColorId*5+ MinorColorId+1) , majorColor[MajorColorId] , minorColor[MinorColorId]);
     
    ActualColorMap( MajorColorId ,MinorColorId );
    // Checking for PairNumber Mismatch
    if(ActualColorPattern[MajorColorId*5+MinorColorId].PairID != MajorColorId*5+MinorColorId) {
        PairIdMismatchCnt +=1;
    }
    //Checking for Major Color mismatch
    else if (strcmp(ActualColorPattern[MajorColorId*5+MinorColorId].MajorColor,majorColor[MajorColorId])!=0) {
        MajorColorMismatchCnt +=1 ;
    }
    // Checking for minor color mismatch
    else if(strcmp(ActualColorPattern[MajorColorId*5+MinorColorId].MinorColor,minorColor[MajorColorId])!=0){
        MinorColorMismatchCnt +=1 ;
    }
    }

void PrintOnConsole(int PairNum,const char *MajorColor ,const char *MinorColor){
    printf("%d | %s | %s\n",PairNum, MajorColor, MinorColor);
}

void CheckColorManual(int result){
    assert(result == 25);
    assert (PairIdMismatchCnt == 0);
    assert (MajorColorMismatchCnt == 0);
    assert (MinorColorMismatchCnt == 0); 
    assert(ActualColorPattern[6].PairID == 6);
    assert(strcmp(ActualColorPattern[6].MajorColor,"Red") == 0);
    assert(strcmp(ActualColorPattern[6].MinorColor,"Blue") == 0);
}

int main() {
    
    int result = printColorMap();
    CheckColorManual(result);
    printf("All is well (maybe!)\n");
    return 0;
}
