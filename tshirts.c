#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms <= 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}


void TestShirtSize (int SizeCms , char ExpectedSize){
    assert(size(SizeCms) == ExpectedSize);
    }
    
int main() {
    TestShirtSize(37, 'S');
    TestShirtSize(38, 'S');
    TestShirtSize(39, 'M');
    TestShirtSize(41, 'M');
    TestShirtSize(42, 'M');
    TestShirtSize(43, 'L');
    TestShirtSize(44, 'L');
    printf("All is well (maybe!)\n");
    return 0;
}
