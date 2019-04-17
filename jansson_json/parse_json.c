#include <stdio.h>

#include "jansson.h"

int main() {
    json_error_t error;

    char *json_string = "{\n"
                        "  \"id\": 1234,\n"
                        "  \"name\": \"apple\",\n"
                        "  \"etc\": \"banana\"\n"
                        "}";

    json_t *root = json_loads(json_string, 0, &error);

    if (!root) {
        fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
        return 1;
    }

    if (!json_is_object(root)) {
        fprintf(stderr, "error: root is not data\n");
        json_decref(root);
        return 1;
    }

    json_t *name = json_object_get(root, "name");

    if (!json_is_string(name)) {
        fprintf(stderr, "error: name is not an string\n");
        json_decref(root);
        return 1;
    }

    printf("name=%s\n", json_string_value(name));

    return 0;
}
