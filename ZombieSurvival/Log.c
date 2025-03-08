#include <time.h>
#include <stdio.h>

void LogInfo(char *str)
{
    FILE *filePointer;
    char buf[255];

    time_t current_time;
    struct tm* time_info;
    char time_string[50];

    time(&current_time);

    time_info = localtime(&current_time);

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    filePointer = fopen("game.log","a");
    sprintf(buf, "%s - %s\n", time_string, str);
    fprintf(filePointer, "%s", buf);
    printf("%s", buf);
    fclose(filePointer);
}
