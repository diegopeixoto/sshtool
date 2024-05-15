#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <json-c/json.h>
#include "database.h"

#define DB_PATH "~/.dotfiles/sshtool-db.json"

struct Database db;

void load_db() {
    FILE *file = fopen(DB_PATH, "r");
    if (file == NULL) {
        initialize_db();
    } else {
        // Load existing database from file
        struct json_object *parsed_json;
        struct json_object *last_connected_host;
        struct json_object *key_path;
        struct json_object *hosts;
        struct json_object *users;
        struct json_object *keys;

        fread(parsed_json, sizeof(parsed_json), 1, file);
        fclose(file);

        json_object_object_get_ex(parsed_json, "last_connected_host", &last_connected_host);
        json_object_object_get_ex(parsed_json, "key_path", &key_path);
        json_object_object_get_ex(parsed_json, "hosts", &hosts);
        json_object_object_get_ex(parsed_json, "users", &users);
        json_object_object_get_ex(parsed_json, "keys", &keys);

        strcpy(db.last_connected_host, json_object_get_string(last_connected_host));
        strcpy(db.key_path, json_object_get_string(key_path));

        // Copy hosts, users, keys arrays
    }
}

void save_db() {
    FILE *file = fopen(DB_PATH, "w");
    if (file == NULL) {
        fprintf(stderr, "Error saving database.\n");
        return;
    }

    // Convert db struct to JSON and write to file
    struct json_object *parsed_json = json_object_new_object();
    struct json_object *last_connected_host = json_object_new_string(db.last_connected_host);
    struct json_object *key_path = json_object_new_string(db.key_path);
    struct json_object *hosts = json_object_new_array();
    struct json_object *users = json_object_new_array();
    struct json_object *keys = json_object_new_array();

    // Populate hosts, users, keys arrays

    json_object_object_add(parsed_json, "last_connected_host", last_connected_host);
    json_object_object_add(parsed_json, "key_path", key_path);
    json_object_object_add(parsed_json, "hosts", hosts);
    json_object_object_add(parsed_json, "users", users);
    json_object_object_add(parsed_json, "keys", keys);

    fprintf(file, "%s", json_object_to_json_string(parsed_json));
    fclose(file);
}

void initialize_db() {
    printf("Database not found. Initializing setup wizard...\n");
    printf("Creating database in ~/.dotfiles/sshtool-db.json\n");

    strcpy(db.key_path, "~/.keys");
    printf("Enter host address: ");
    scanf("%s", db.hosts[0]);
    printf("Enter host name: ");
    scanf("%s", db.last_connected_host);
    printf("Enter user: ");
    scanf("%s", db.users[0]);
    printf("Enter key: ");
    scanf("%s", db.keys[0]);

    save_db();
    printf("Database initialized at %s\n", DB_PATH);
}
