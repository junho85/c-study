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

    printf("%s\n", formatted_date); // e.g. 20190328
    printf("%zu\n", ret); // 8
}

void test_cur_yyyymmddhhmmss() {
    char formatted_date[15];

    time_t cur_time = time((time_t *) 0);

    struct tm *tp = localtime(&cur_time);
    size_t ret = strftime(formatted_date, 15, "%Y%m%d%H%M%S", tp);

    printf("%s\n", formatted_date); // e.g. 20190328180843
    printf("%zu\n", ret); // 14
}




int main() {
    test_cur_yyyymmdd();
    test_cur_yyyymmddhhmmss();

    return 0;
}