#include <stdio.h>
#include <assert.h>

#define MAX_TEMP_THRESHOLD_CEL 180

int alertFailureCount = 0;
int NumOfAlertInCelciusFuncCalls =0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius > MAX_TEMP_THRESHOLD_CEL){
        return 500;
    }
    else{
        return 200;
    }
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
        
    }
    NumOfAlertInCelciusFuncCalls++;
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(NumOfAlertInCelciusFuncCalls==2);
    assert(alertFailureCount !=0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
