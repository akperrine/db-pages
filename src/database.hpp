#include <fstream>
#include <string>

namespace database {

class Database {
public:
    void create_db(std::string db_name);
    void drop_db();
private:
    std::string db_path;
};

};