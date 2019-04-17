#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

#define FROM    "<test@example.org>"
#define TO      "<junho85@daum.net>"
#define CC      "<jworld2000@daum.net>"

static const char *headers_text[] = {
        "Date: Tue, 22 Aug 2017 14:08:43 +0100",
        "To: " TO,
        "From: " FROM " (Example User)",
        "Cc: " CC " (Another example User)",
        "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
        "rfcpedant.example.org>",
        "Subject: example sending a MIME-formatted message",
        NULL
};

static const char inline_text[] =
        "This is the inline text message of the e-mail.\r\n"
        "\r\n"
        "  It could be a lot of lines that would be displayed in an e-mail\r\n"
        "viewer that is not able to handle HTML.\r\n";

static const char inline_html[] =
        "<html><body>\r\n"
        "<p>This is the inline <b>HTML</b> message of the e-mail.</p>"
        "<br />\r\n"
        "<p>It could be a lot of HTML data that would be displayed by "
        "e-mail viewers able to handle HTML.</p>"
        "</body></html>\r\n";


int main(void) {
    CURLcode res = CURLE_OK;

    CURL *curl = curl_easy_init();
    if (curl) {
//        curl_easy_setopt(curl, CURLOPT_URL, "smtp://mx1.hanmail.net");
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://mail-rmail51.pg1.krane.9rum.cc");

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);

        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, TO);
        recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        struct curl_slist *headers = NULL;
        const char **cpp;
        for (cpp = headers_text; *cpp; cpp++)
            headers = curl_slist_append(headers, *cpp);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_mime *mime = curl_mime_init(curl);

        curl_mime *alt = curl_mime_init(curl);

        curl_mimepart *part;

        part = curl_mime_addpart(alt);
        curl_mime_data(part, inline_html, CURL_ZERO_TERMINATED);
        curl_mime_type(part, "text/html");

        part = curl_mime_addpart(alt);
        curl_mime_data(part, inline_text, CURL_ZERO_TERMINATED);

        part = curl_mime_addpart(mime);
        curl_mime_subparts(part, alt);
        curl_mime_type(part, "multipart/alternative");

        struct curl_slist *slist = curl_slist_append(NULL, "Content-Disposition: inline");
        curl_mime_headers(part, slist, 1);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        curl_slist_free_all(recipients);
        curl_slist_free_all(headers);

        curl_easy_cleanup(curl);

        curl_mime_free(mime);
    }

    return (int) res;
}