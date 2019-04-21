find_package(OpenSSL REQUIRED)

add_executable(hmac_sample1 hmac_sample1.c)
target_link_libraries(hmac_sample1
        crypto)

add_executable(hmac_sample2 hmac_sample2.c)
target_link_libraries(hmac_sample2
        crypto)

add_executable(base64 base64.c)
target_link_libraries(base64
        crypto)

add_executable(hmac_sample1_base64 hmac_sample1_base64.c)
target_link_libraries(hmac_sample1_base64
        crypto)
