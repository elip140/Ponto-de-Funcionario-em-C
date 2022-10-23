#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t convertStringToDate(char* str) {
    struct tm  tm;
    char buffer[30];
    time_t ret;

    char *ptr = strtok(str, " ");

    char* date1 = ptr;
	ptr = strtok(NULL, " ");
	char* date2 = ptr;

	char *ptr2 = strtok(date1, "-");

	char* year = ptr2;
	ptr2 = strtok(NULL, "-");
	char* month = ptr2;
	ptr2 = strtok(NULL, "-");
	char* day = ptr2;

    char *ptr3 = strtok(date2, ":");

	char* hour = ptr3;
	ptr3 = strtok(NULL, ":");
	char* minute = ptr3;
	ptr3 = strtok(NULL, ":");
	char* second = ptr3;

    int yeari = atoi(year);
    int monthi = atoi(month);
    int dayi = atoi(day);

    int houri = atoi(hour);
    int minutei = atoi(minute);
    int secondi = atoi(second);

    time(&ret);
    tm = *localtime (&ret);
    tm.tm_year = yeari - 1900;
    tm.tm_mon = monthi - 1;
    tm.tm_mday = dayi;
    tm.tm_hour = houri;
    tm.tm_min = minutei;
    tm.tm_sec = secondi;
    ret = mktime(&tm);

    return ret;
}
