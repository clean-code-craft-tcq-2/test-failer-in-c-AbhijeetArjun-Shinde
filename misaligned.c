#include <stdio.h>
#include <assert.h>

int StringMakerFuncCalls =0 ;
int PrintConsoleFuncCalls =0 ;

void PrintStringMaker( int MajorColorId , int MinorColorId);
void PrintOnConsole(int PairNum, char *MajorColor, char *MinorColor);

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
    char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    PrintOnConsole( (MajorColorId*5+ MinorColorId) , majorColor[MajorColorId] , minorColor[MajorColorId]);
    StringMakerFuncCalls+=1;
    }
void PrintOnConsole(int PairNum, char *MajorColor , char *MinorColor){
    printf("%d | %s | %s\n",PairNum, MajorColor, MinorColor);
    PrintConsoleFuncCalls +=1;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(StringMakerFuncCalls == 25);
    assert(PrintConsoleFuncCalls == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
