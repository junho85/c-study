add_executable(parse_json parse_json.c)

target_link_libraries(parse_json
        jansson)