//
// Created by 周健 on 2020-06-22.
//
#include <stdio.h>

const double PI = 3.1415927;
const double INCHES_TO_FEET = 12;
const double FEET_TO_MILE = 5280;
const int SECOND_TO_HOUR = 3600;
const double NUM = PI / INCHES_TO_FEET / FEET_TO_MILE ;

int main() {
    int round = 0;
    double diameter,seconds;
    int revolutions;
    while (scanf("%lf%d%lf", &diameter, &revolutions,&seconds) && revolutions != 0) {
        double distance = diameter * NUM * revolutions;
        double speed = distance * SECOND_TO_HOUR / seconds;
        printf("Trip #%d: %.2f %.2f\n", ++round, distance, speed);
    }
    return 0;
}

