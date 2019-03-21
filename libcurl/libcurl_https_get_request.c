#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

struct curl_string {
    char *ptr;
    size_t len;
};

static void init_string(struct curl_string *s) {
    s->len = 0;
    s->ptr = malloc(s->len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

static size_t writefunc(void *ptr, size_t size, size_t nmemb, struct curl_string *s) {
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr + s->len, ptr, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size * nmemb;
}

int main() {
    long response_code = 0;

    CURL *curl = curl_easy_init();

    if (curl) {
        struct curl_string string_body;
        struct curl_string string_header;

        init_string(&string_body);
        init_string(&string_header);

        const char *url = "https://www.daum.net";
        const long timeout_ms = 1000; // 1 second

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, timeout_ms);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &string_body);

        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &string_header);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        printf("%s\n", string_body.ptr);
        printf("%s\n", string_header.ptr);

        free(string_body.ptr);
        free(string_header.ptr);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    return 0;
}