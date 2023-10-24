#include <iostream>
#include <mysql.h>

using namespace std;

int main()
{
    MYSQL* connection;
    connection = mysql_init(0);
    connection = mysql_real_connect(connection, "localhost", "root", "", "mrtheaven", 3306, NULL, 0);

    if (connection)
    {
        cout << "MySQL Connection Success!" << mysql_errno(connection) << endl;
        /* while (true)
        {
            system("cls || clear");
            AppView::Menu();
            AppController::getChoice();
        }*/
    }
    else
    {
        cout << "Connection -> MySQL Failed!" << mysql_errno(connection) << endl;
    }

    return 0;
}
