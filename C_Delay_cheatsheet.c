
/*
    C Delay / Wait Cheat Sheet (Single File)
    ----------------------------------------
    Contains examples of:
    - sleep()       : seconds (POSIX)
    - usleep()      : microseconds (POSIX)
    - nanosleep()   : nanoseconds (POSIX)
    - Cross-platform delay_ms()
    - Busy wait (not recommended)
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>     // sleep(), usleep()

// Cross-platform millisecond delay
#ifdef _WIN32
    #include <windows.h>
    void delay_ms(int ms) {
        Sleep(ms);
    }
#else
    void delay_ms(int ms) {
        usleep(ms * 1000);     // convert ms to µs
    }
#endif


int main() {

    printf("sleep(1) — waiting 1 second...\n");
    sleep(1);


    printf("usleep(500000) — waiting 0.5 seconds...\n");
    usleep(500000);            // 500,000 µs = 0.5 sec


    printf("nanosleep() — waiting 1.2 seconds...\n");
    struct timespec ts;
    ts.tv_sec  = 1;            // 1 second
    ts.tv_nsec = 200000000;    // 0.2 sec
    nanosleep(&ts, NULL);


    printf("delay_ms(700) — waiting 0.7 seconds...\n");
    delay_ms(700);


    printf("Busy wait (not recommended)...\n");
    for (volatile long long i = 0; i < 50000000LL; i++);


    printf("Done!\n");
    return 0;
}
