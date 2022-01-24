#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            PrintOnConsole(i,j);    
        }
    }
    return i * j;
}

PrintOnConsole( int majorcolorid, int minorcolorid){
printf("%d | %s | %s\n", majorcolorid * 5 + minorcolorid, majorColor[majorcolorid], minorColor[minorcolorid]);
}
    
int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
