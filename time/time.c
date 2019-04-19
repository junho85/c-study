#include <stdio.h>
#include <time.h>

time_t get_curtime() {
    return time((time_t *) 0);
}

void test_cur_yyyymmdd() {
    char formatted_date[9];

    time_t cur_time = time((time_t *) 0);

    struct tm *tp = localtime(&cur_time);
    size_t ret = strftime(formatted_date, 9, "%Y%m%d", tp);

    printf("%s\n", formatted_date); // e.g. 20190419
    printf("%zu\n", ret); // 8 - length
}

void test_cur_yyyymmddhhmmss() {
    char formatted_date[15];

    time_t cur_time = time((time_t *) 0);

    struct tm *tp = localtime(&cur_time);
    size_t ret = strftime(formatted_date, 15, "%Y%m%d%H%M%S", tp);

    printf("%s\n", formatted_date); // e.g. 20190419000305
    printf("%zu\n", ret); // 14 - length
}

void test_format() {
    time_t current_time = time(NULL);
    char* c_time_string = ctime(&current_time);

    printf("%s", c_time_string); // e.g. Fri Apr 19 11:07:46 2019
}

void test_mime_date_format() {
    time_t now = time(0);
    struct tm tm = *gmtime(&now);

    char buf[100];

    strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
    printf("%s\n", buf); // e.g. Fri, 19 Apr 2019 02:12:08 UTC
}

int main() {
    test_cur_yyyymmdd();
    test_cur_yyyymmddhhmmss();
    test_format();
    test_mime_date_format();

    return 0;
}