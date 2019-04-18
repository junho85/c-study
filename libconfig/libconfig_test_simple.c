#include <stdio.h>
#include <libconfig.h>
#include <libgen.h>

int main() {
    config_t cfg;

    config_init(&cfg);

    char filepath[200];
    sprintf(filepath, "%s/example_simple.cfg", dirname(__FILE__));

    if (!config_read_file(&cfg, filepath)) {
        fprintf(stderr, "%d - %s\n", config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
        return 1;
    }

    const char *api_host;
    if (config_lookup_string(&cfg, "api_host", &api_host))
        printf("api_host: %s\n", api_host);
    else
        fprintf(stderr, "No 'api_host' setting in configuration file.\n");

    const char *api_key;
    if (config_lookup_string(&cfg, "api_key", &api_key))
        printf("api_key: %s\n", api_key);
    else
        fprintf(stderr, "No 'api_key' setting in configuration file.\n");

    config_destroy(&cfg);

    return 0;
}