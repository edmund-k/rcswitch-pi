/*
 Example for REV outlets (e.g. 8342 BHC), based on sendTriState.cpp

 Usage: ./sendRevBHC <systemCode> <device> <command>
 SystemCode must have a length of 7
 Valid device is 1..3
 Command is 0 for OFF and 1 for ON
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include "RCSwitch.h"

int main(int argc, char *argv[]) {

    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;

    if (argc < 4 ) {
      fprintf(stderr, "Usage: %s <systemCode> <device> <command>\n", argv[0]);
      fprintf(stderr, "\twhere:\n");
      fprintf(stderr, "\t  SystemCode must have a length of 7,\n");
      fprintf(stderr, "\t  Valid device is 1..3 and\n");
      fprintf(stderr, "\t  Command is 0 for OFF and 1 for ON\n");

      return EXIT_FAILURE;
    }

    const char* sGroup = argv[1];
    int nDevice = atoi(argv[2]);
    int command  = atoi(argv[3]);

    if (wiringPiSetup () == -1) return 1;

    printf("sending sGroup[%s] nDevice[%i] command[%i]\n", sGroup, nDevice, command);
    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(PIN);
    mySwitch.setPulseLength(100); // I tested 100 .. 250 us

    switch(command) {
        case 1:
            mySwitch.switchOnBHC(sGroup, nDevice);
            break;
        case 0:
            mySwitch.switchOffBHC(sGroup, nDevice);
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
