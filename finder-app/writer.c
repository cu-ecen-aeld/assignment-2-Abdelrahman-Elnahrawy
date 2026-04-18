#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);
    FILE *fp;
    if (argc != 3)
    {
        fprintf(stderr, "Invalid number of arguments \n");
        fprintf(stderr, "Usage: Full path to the file  string to be written in the file \n");
        fprintf(stderr, "Example: ./writer /tmp/test.txt \"Hello World\" \n");
        syslog(LOG_ERR, "Wrong number of arguments! Expected 2, got %d", argc - 1);
        closelog();
        return 1;
    }
    else if ((fp = fopen(argv[1], "w")) == NULL)
    {
        fprintf(stderr, "Error opening file: %s \n", strerror(errno));
        syslog(LOG_ERR, "Error opening file! Error : %s", strerror(errno));
        closelog();
        return 1;
    }
    else
    {
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
        fputs(argv[2], fp);
        fclose(fp);
        closelog();
        return 0;
    }
}
