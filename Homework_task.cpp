# include <iostream>
# include <>

// Include SQLiteCpp header

int main() {
    try {
        // Open a database connection
        SQLite::Database db("example.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // Create a table
        db.exec("CREATE TABLE IF NOT EXISTS Users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)");

        // Insert some data
        SQLite::Statement query(db, "INSERT INTO Users (name, age) VALUES (?, ?)");
        query.bind(1, "Alice");
        query.bind(2, 30);
        query.exec();
        query.reset();
        query.bind(1, "Bob");
        query.bind(2, 25);
        query.exec();

        // Retrieve data
        SQLite::Statement querySelect(db, "SELECT * FROM Users");
        while (querySelect.executeStep()) {
            int id = querySelect.getColumn(0);
            std::string name = querySelect.getColumn(1);
            int age = querySelect.getColumn(2);
            std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age << std::endl;
        }

        // Close the connection
        db.close();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
