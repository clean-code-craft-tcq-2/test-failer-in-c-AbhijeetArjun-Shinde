#include <stdio.h>
#include <assert.h>

#define MAX_TEMP_THRESHOLD_CEL 180
#define MIN_TEMP_THRESHOLD_CEL 150

int alertFailureCount = 0;

float ConvertFarenheitToCelcius( float farenheit);

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if((celcius >= MIN_TEMP_THRESHOLD_CEL) && (celcius <= MAX_TEMP_THRESHOLD_CEL)){
        return 200;
    }
    else{
        return 500;
    }
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
}

float ConvertFarenheitToCelcius( float farenheit){
    return ((farenheit - 32) * 5 / 9);
}


void alertInCelcius(float farenheit, int (*Func_Ptr_NetworkAlerter)(float)) {
    float celcius = ConvertFarenheitToCelcius(farenheit)
    int returnCode = Func_Ptr_NetworkAlerter(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;      
    }
}

int main() {
    int (*Func_Ptr_NetworkAlerter)(float) =&networkAlertStub;
    alertInCelcius(400.5,Func_Ptr_NetworkAlerter);
    alertInCelcius(303.6,Func_Ptr_NetworkAlerter);
    assert(alertFailureCount ==1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
