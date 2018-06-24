#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    
    char sdate[45];
    strftime(sdate, 45, "%A %d %b %Y %H:%M:%S (Week %W)", tm_now);
    printf("strftime: %s\n", sdate);
    
    printf("asctime:  %s\n", asctime(tm_now));
    return 0;
}
