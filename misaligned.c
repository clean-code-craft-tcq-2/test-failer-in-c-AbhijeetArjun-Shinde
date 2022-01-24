#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors =sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors =sizeof(minorColor) / sizeof(minorColor[0]);

void PrintOnConsole( int minorcolorid, int majorcolorid){
printf("%d | %s | %s\n", minorcolorid * 5 + majorcolorid, majorColor[majorcolorid], minorColor[minorcolorid]);
}


int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < numberOfMinorColors; i++) {
        for(j = 0; j < numberOfMajorColors; j++) {
            PrintOnConsole(i,j);    
        }
    }
    return i * j;
}


    
int main() {
    int result = printColorMap();
    assert(result == 24);
    printf("All is well (maybe!)\n");
    return 0;
}
