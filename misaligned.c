#include <stdio.h>
#include <assert.h>

void PrintStringMaker( int MajorColorId , int MinorColorId);
void PrintOnConsole(int PairNum, int MajorColorId , int MinorColorId);
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
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    PrintOnConsole( (MajorColorId*5+ MinorColorId) , majorColor[MajorColorId] , minorColor[MajorColorId]);
    }
void PrintOnConsole(int PairNum, char *MajorColor , char *MinorColor){
    printf("%d | %s | %s\n",PairNum, MajorColor, MinorColor);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
