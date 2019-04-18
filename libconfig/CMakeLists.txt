add_executable(libocnfig_test libconfig_test.c)

target_link_libraries(libocnfig_test
        config)

add_executable(libocnfig_test_simple libconfig_test_simple.c)

target_link_libraries(libocnfig_test_simple
        config)
