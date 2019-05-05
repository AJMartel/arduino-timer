#include <timer.h>

Timer<2> timer;

unsigned long TIMER_ID = 0;

void setup() {
    Serial.begin(115200);
}

/*this function will be executed only if you comment the cancel*/
bool test(void *) {
    Serial.println("Test function was executed");
}

void loop() {
  
    timer.tick();
   
    if (TIMER_ID != 0) { 
        timer.cancel(TIMER_ID); //Comment here to execute the function test()
        TIMER_ID = 0;
        Serial.println("Test function was cancelled");
        Serial.println("");
    } 
    
    TIMER_ID = timer.in(5000, test);
    Serial.println("Test function will be executed in 5 seconds");

    //some delay to improve the readability
    delay(1000);
    
}