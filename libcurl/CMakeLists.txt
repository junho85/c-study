# osx homebrewed libcurl
include_directories(/usr/local/opt/curl/include)
link_directories(/usr/local/lib /usr/local/opt/curl/lib)

add_executable(libcurl_https_get_request libcurl_https_get_request.c)
target_link_libraries(libcurl_https_get_request
        curl)

add_executable(libcurl_smtp_mime libcurl_smtp_mime.c)
target_link_libraries(libcurl_smtp_mime
        curl)