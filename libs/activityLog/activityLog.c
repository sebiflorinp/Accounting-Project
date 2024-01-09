#include "activityLog.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void addActivity(char activityDescription[]) {
    /*
     * A function that adds an activity in the activity log.
     *  Preconditions: activityDescription: a char array
     *  Post-conditions: -
     */
    //get current time
    time_t time1;
    struct tm *currentTime;
    time1 = time(NULL);
    currentTime = localtime(&time1);
    int currentDay = currentTime->tm_mday;
    int currentMonth = currentTime->tm_mon + 1;
    int currentYear = currentTime->tm_year + 1900;
    int currentHour = currentTime->tm_hour;
    int currentMinute = currentTime->tm_min;
    int currentSecond = currentTime->tm_sec;
    // open the db
    FILE *activityDB = fopen("../db/log.txt", "a");
    fprintf(activityDB, "%s\nYear: %d Month: %d Day: %d Hour: %d Minute: %d Second: %d\n\n",
            activityDescription, currentYear, currentMonth, currentDay, currentHour, currentMinute, currentSecond);
    fclose(activityDB);
}