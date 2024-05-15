#ifndef DATABASE_H
#define DATABASE_H

struct Database {
    char last_connected_host[256];
    char key_path[256];
    char hosts[10][256];
    char users[10][256];
    char keys[10][256];
};

extern struct Database db;

void load_db();
void save_db();
void initialize_db();

#endif // DATABASE_H
