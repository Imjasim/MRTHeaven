// MRTHeaven Ticket Booking System

#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

// Global Variable Movie Ticket Booking System in C++ with MySQL
int qstate, qstate2;
MYSQL* conn;
MYSQL_ROW row, row2;
MYSQL_RES* res;
MYSQL_RES* res2;
int user_id;
// Global Variable End



class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);

        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "mrtheaven", 3306, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

void Welcome() {
    cout << "********************************************" << endl;
    cout << "*                                          *" << endl;
    cout << "*       Welcome to MRTCINEMA HEAVEN        *" << endl;
    cout << "*                                          *" << endl;
    cout << "********************************************" << endl;
}



// Functions
void AddNewMovie();
void EditMovie();
void DeleteMovie();
void ShowMovieList();
void AddNewShowTime();
void ShowShowtimeList();
void RegisterUser();
void LoginUser();
void loginMenu();
void customerMenu ();
void adminMenu();
void BookTicket();


int main()
{
    // Initial Load
    system("cls");
    system("title Movie Ticket Booking Program");
    system("color 0f");
    // Initial Load End

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    // Variables

    // Variables End

    Welcome();
    loginMenu();
    return 0;
}
void loginMenu() {
int chooseOneFromMenu = 0;
char exitSurity;
int num = 1;
int fin = 0;
      for (int i = 0; i < 1; i++) {
        fin = num;
        cout << fin << ". Login User" << endl;
        fin += num;
        cout << fin << ". Register" << endl;
        fin += num;
        cout << fin << ". Exit" << endl;
        cout << "Choose One: ";
    }
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        LoginUser();
        break;
    case 2:
        RegisterUser();
        break;
    case 3:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            exit(0);
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 3. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
}
void adminMenu(){
int chooseOneFromMenu = 0;
char exitSurity;
int num = 1;
int fin = 0;
Welcome();
     for (int i = 0; i < 1; i++) {
        fin = num;
        cout << fin << ". Add New Movie" << endl;
        fin += num;
        cout << fin << ". Edit Movie" << endl;
        fin += num;
        cout << fin << ". Delete Movie" << endl;
        fin += num;
        cout << fin << ". Show Movie List" << endl;
        fin += num;
        cout << fin << ". Add New Show Time" << endl;
        fin += num;
        cout << fin << ". Movie Show Time" << endl;
        fin += num;
        cout << fin << ". Add New User" << endl;
        fin += num;
        cout << fin << ". Exit" << endl;
        cout << "Choose One: ";
    }
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        AddNewMovie();
        break;
    case 2:
        EditMovie();
        break;
    case 3:
        DeleteMovie();
        break;
    case 4:
        ShowMovieList();
        break;
    case 5:
        AddNewShowTime();
        break;
    case 6:
        ShowShowtimeList();
        break;
    case 7:
        RegisterUser();
        break;
    case 8:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            exit(0);
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 9. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
}
void customerMenu(){
int chooseOneFromMenu = 0;
char exitSurity;
int num = 1;
int fin = 0;
Welcome();
      for (int i = 0; i < 1; i++) {
        fin = num;
        cout << fin << ". Book Ticket" << endl;
        fin += num;
        cout << fin << ". Show My Ticket" << endl;
        fin += num;
        cout << fin << ". Check Seat" << endl;
        fin += num;
        cout << fin << ". Exit" << endl;
        cout << "Choose One: ";
    }
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        BookTicket();
        break;
    case 2:
        /*ShowMyTicket();*/
        break;
    case 3:
        /*CheckSeat();*/
        break;
    case 4:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            exit(0);
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 4. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
}

void BookTicket(){
    system("cls");

    // Variables
    char choose;
    string input;
    int itemId, showid, numTicket, seatNum;
    bool HaveException = false;
    std::vector<int> ticketsBooked;
    //int ticketsBooked[40];
    int seatRow =5, seatColumn=9;
    int movie_seats[seatRow][seatColumn] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},};

    Welcome();
    qstate = mysql_query(conn, "select * from movie");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-45s | %-15s | %-15s | %-15s |\n", "Id", "Title", "Description", "Duration", "Language", "Subtitle");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s | %-45s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Movie ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID NUMBER." << endl;
        HaveException = true;
        BookTicket();
    }

    Welcome();
    stringstream streamid;
    string movieid;
    streamid << itemId;
    streamid >> movieid;
    string findbyid_query = "select a.id, b.title, a.date, c.time FROM showtime a INNER JOIN movie b ON a.movie_id = b.id  INNER JOIN time_slots c ON a.slot_id = c.id where b.id = '"+movieid+"'";
    const char* qi = findbyid_query.c_str();
    qstate2 = mysql_query(conn, qi);


    if (!qstate2)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-15s | %-15s | \n", "Id", "Title", "Date", "Time");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s | %-15s | %-15s | \n", row[0], row[1], row[2], row[3]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    try
    {
        cout << endl;
        cout << "Choose a showtime ID: ";
        cin >> showid;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID NUMBER." << endl;
        HaveException = true;
        BookTicket();
    }

    stringstream streamid2;
    string showTimeId;
    streamid2 << showid;
    streamid2 >> showTimeId;
    cout << endl;
    cout << "Showtime ID chosed: ";
    cout << showTimeId;
    cout << endl;

    string findbyid_query2 = "select seat_num FROM booking where showtime_id = '"+showTimeId+"'";
    const char* qi2 = findbyid_query2.c_str();
    qstate = mysql_query(conn, qi2);


    int backSeatNum, splitSeatNum, frontSeatNum;
      if (!qstate)
    {
        res = mysql_store_result(conn);

        cout << "res: ";
        cout << res;
        cout << endl;
        row = mysql_fetch_row(res);
        if (row != NULL)
        {
                int j =0;
                printf("| %-10s | \n", row[0]);
                stringstream SS(row[0]);
                int booked_seat;
                SS >> booked_seat;
                ticketsBooked.push_back(booked_seat);

                backSeatNum = (booked_seat % 10)-1;
                splitSeatNum = booked_seat/10;
                frontSeatNum = (splitSeatNum%10)-1;
                movie_seats[frontSeatNum][backSeatNum] = 1;

            while ((row = mysql_fetch_row(res)))
            {
                j++;
                stringstream SS(row[0]);
                int booked_seat;
                SS >> booked_seat;
                ticketsBooked.push_back(booked_seat);

                backSeatNum = (booked_seat % 10)-1;
                splitSeatNum = booked_seat/10;
                frontSeatNum = (splitSeatNum%10)-1;
                movie_seats[frontSeatNum][backSeatNum] = 1;
            }
        }
        else
        {

        }

        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | \n", " ","1", "2", "3", "4", "5", "6", "7", "8", "9");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        for(int a = 0; a < seatRow; a++)
        {
                switch (a) {
                  case 0:
                    printf("| %-5s |", "A");
                    break;
                  case 1:
                    printf("| %-5s |", "B");
                    break;
                  case 2:
                    printf("| %-5s |", "C");
                    break;
                  case 3:
                    printf("| %-5s |", "D");
                    break;
                  case 4:
                    printf("| %-5s |", "E");
                    break;
                }

            for(int b = 0; b < seatColumn; b++)
            {
              printf(" %-5d |", movie_seats[a][b]);
            }
            cout << endl;
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Choose number of tickets to book: ";
        cin >> numTicket;
        cout << endl;

        if(numTicket == 0)
        {
             throw ("Please Enter a valid NUMBER.");
        }
        else if(numTicket > 10)
        {
             throw ("Maximum number of ticket allowed per transaction is 10");
        }
    }
    catch (exception e )
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
    }
    catch (char const* e )
    {
        cout << e << endl;
        HaveException = true;
        BookTicket();
    }


    std::vector<int> movie_seats_chosen;
    int numSeatChosed = 0;
    while(numSeatChosed < numTicket)
    {
        int backSeatNum2, frontSeatNum2;
        char inputRowSeatNum, inputColumnSeatNum;
        int splitSeatNum2;
        string tempSeatNum, inputSeatNum;
        cout << "Inside while."<< numSeatChosed << endl;
        cout << "numTicket."<< numTicket << endl;
        try
        {
            cout << endl;
            cout << "Choose a seat number to book: ";
            cin >> inputSeatNum;
            cout << endl;

            vector<char> c(inputSeatNum.begin(), inputSeatNum.end());

            backSeatNum2 = c.at(1) - '0';
            cout << "backSeatNum2."<< backSeatNum2 << endl;


            switch (c.at(0)) {
                  case 'A':
                    frontSeatNum2 = 1;
                    break;
                  case 'B':
                    frontSeatNum2 = 2;
                    break;
                  case 'C':
                    frontSeatNum2 = 3;
                    break;
                  case 'D':
                    frontSeatNum2 = 4;
                    break;
                  case 'E':
                    frontSeatNum2 = 5;
                    break;
                }

            string SS = std::to_string(frontSeatNum2) + std::to_string(backSeatNum2);
            seatNum = stoi(SS);
            cout << "seatNum."<< seatNum << endl;

        int found=0;
        for(int i = 0; i < ticketsBooked.size(); i++){
             if(ticketsBooked.at(i) == seatNum){
                cout << "This seat is already booked. Please select a different seat." << endl;
                found=1;
                 break;
             }
        }
        if (found == 0 ){
            movie_seats_chosen.push_back(seatNum);
            numSeatChosed++;
        }
        }
        catch (exception e )
        {
            cout << "Please Enter a valid NUMBER." << endl;
            HaveException = true;
        }
        catch (char const* e )
        {
            cout << e << endl;
            HaveException = true;
        }

    }


    for(int i = 0; i < movie_seats_chosen.size(); i++)
    {

        string insert_query = "insert into booking (user_id, showtime_id, seat_num) values ('"+std::to_string(user_id)+"','"+showTimeId+"','"+std::to_string(movie_seats_chosen.at(i))+"')";

        const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            cout << endl << "Successfully added in database." << endl;
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }

    ExitMenu:
    cout << "Press 'm' to Menu, 'e' to another ticket and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
       system("cls");
        customerMenu();
    }
    else if (choose == 'e' || choose == 'E')
    {
        system("cls");
        BookTicket();
    }
    else
    {
        exit(0);
    }
}


void AddNewMovie() {

    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string title = "";
    string description = "";
    string duration = "";
    string language = "";
    string subtitle = "";
    char choose;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Description: ";
    getline(cin, description);
    cout << "Enter Movie Duration: ";
    getline(cin, duration);
    cout << "Enter Language: ";
    getline(cin, language);
    cout << "Enter Subtitle: ";
    getline(cin, subtitle);

    string insert_query = "insert into movie (title, description, duration, language, subtitle) values ('"+title+"','"+description+"','"+duration+"','"+language+"','"+subtitle+"')";
    /*string insert_query = "insert into movie (title, description, duration, language, subtitle) values ('"+name+"','"+genre+"','"+format+"',STR_TO_DATE('"+showDate+"', '%d-%m-%Y'),'"+showTime+"','"+ticketPrice+"', '"+seat+"')";*/

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        system("cls");
        adminMenu();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddNewMovie();
    }
    else
    {
        exit(0);
    }
}

void EditMovie() {

    system("cls");

    // Variables
    string title = "";
    string description = "";
    string duration = "";
    string language = "";
    string subtitle = "";
    string items[5000];
    char choose;
    int itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storetitle = "";
    string storedesc = "";
    string storeduration = "";
    string storelanguage = "";
    string storesubtitle = "";
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select id, title from movie");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("--------------------------------\n");
        printf("| %-10s | %-15s |\n", "Column Id", "Title");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s |\n", row[0], row[1]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("--------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from movie where id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << "Column ID: " << row[0] << "\nTitle: "
                         << row[1] << "\nDescription: " << row[2] << "\nDuration: " << row[3] << "\nLanguage: " << row[4] << "\nSubtitle: " << row[5] << endl << endl;

                    storeid = row[0];
                    storetitle = row[1];
                    storedesc = row[2];
                    storeduration = row[3];
                    storelanguage = row[4];
                    storesubtitle = row[5];
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            string defaultString = "xx";
            cout << "Enter Title (" << defaultString << "  to not change): ";
            getline(cin, title);
            if (title == defaultString)
            {
                title = storetitle;
            }
            cout << "Enter Description (" << defaultString << "  to not change): ";
            getline(cin, description);
            if (description == defaultString)
            {
                description = storedesc;
            }
            cout << "Enter Duration (" << defaultString << "  to not change): ";
            getline(cin, duration);
            if (duration == defaultString)
            {
                duration = storeduration;
            }
            cout << "Enter Language (" << defaultString << "  to not change): ";
            getline(cin, language);
            if (language == defaultString)
            {
                language = storelanguage;
            }
            cout << "Enter Subtitle (" << defaultString << "  to not change): ";
            getline(cin, subtitle);
            if (subtitle == defaultString)
            {
                subtitle = storesubtitle;
            }

            string update_query = "update movie set title = '"+title+"', description = '"+description+"', duration = '"+duration+"', language = '"+language+"', subtitle = '"+subtitle+"' where id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
       system("cls");
        adminMenu();
    }
    else if (choose == 'e' || choose == 'E')
    {
        system("cls");
        EditMovie();
    }
    else
    {
        exit(0);
    }
}

void DeleteMovie() {
    system("cls");

    char choose;
    int itemId;
    string items[5000];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;

    Welcome();
    qstate = mysql_query(conn, "select * from movie");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("--------------------------------------------------\n");
        printf("| %-10s | %-15s | %-15s |\n", "Movie Id", "Title", "Description");
        printf("--------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s | %-15s |\n", row[0], row[1], row[2]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("--------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Movie ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from movie where id = '"+strid+"'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    // Exit Code
    ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
       system("cls");
        adminMenu();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteMovie();
    }
    else
    {
        system("cls");
        exit(0);
    }
}

void ShowMovieList() {
    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select * from movie");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-15s | %-45s | %-15s | %-15s | %-15s |\n", "Title", "Description", "Duration", "Language", "Subtitle");
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-45s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5]);
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'm' to Menu any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        system("cls");
        adminMenu();
    }
    else
    {
        exit(0);
    }
}


void AddNewShowTime() {

    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string movieid = "";
    string date = "";
    string timeslotid = "";
    string availability = "";
    string hallid = "";
    char choose;
    string items[5000];
    string itemId;
    string input_hall_id;
    bool HaveException = false;
    bool NotInDatabase = false;
    string inputtimeslot, inputDate;
    int indexForId = 0;
    // Variables End


    Welcome();
    qstate = mysql_query(conn, "select id, title from movie");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("--------------------------------\n");
        printf("| %-10s | %-15s |\n", "Column Id", "Title");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s |\n", row[0], row[1]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("--------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string movieid;
        streamid << itemId;
        streamid >> movieid;

        for (int i = 0; i < indexForId; i++)
        {
            if (movieid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from hall";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << "Hall ID: " << row[0] << "\ Hall Name: "
                         << row[1] << endl << endl;
                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            try
            {
                cout << endl;
                cout << "Enter Hall ID: ";
                cin >> input_hall_id;
                cout << endl;
            }
            catch (exception e)
            {
                cout << "Please Enter a valid NUMBER." << endl;
                HaveException = true;
                goto ExitMenu;
            }


            qstate2 = mysql_query(conn, "select id, time from time_slots");
            if (!qstate2)
            {
                res = mysql_store_result(conn);
                printf("--------------------------------\n");
                printf("| %-10s | %-15s |\n", "Column Id", "Time Slot");
                while ((row = mysql_fetch_row(res)))
                {
                    printf("| %-10s | %-15s |\n", row[0], row[1]);
                    items[indexForId] = row[0];
                    indexForId++;
                }
                printf("--------------------------------\n");
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            try
            {
                cout << endl;
                cout << "Enter Time ID: ";
                cin >> inputtimeslot;
                cout << endl;
            }
            catch (exception e)
            {
                cout << "Please Enter a valid NUMBER." << endl;
                HaveException = true;
                goto ExitMenu;
            }

            try
            {
                cout << endl;
                cout << "Enter Date (dd-mm-yyyy): ";
                cin >> inputDate;
                cout << endl;
            }
            catch (exception e)
            {
                cout << "Please Enter a valid DATE." << endl;
                HaveException = true;
                goto ExitMenu;
            }

            /*cin.ignore(1, '\n');
            cout << "Choose Time Slot: ";
            getline(cin, inputtimeslot);*/


            string new_booking_query = "insert into showtime (movie_id, date, slot_id, availability, hall_id) values ('"+movieid+"',STR_TO_DATE('"+inputDate+"', '%d-%m-%Y'),'"+inputtimeslot+"','1','"+input_hall_id+"')";
            const char* qu = new_booking_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Saved In Database." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    ExitMenu:
    cout << "Press 'm' to Menu, 'e' to add another showtime and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'e' || choose == 'E')
    {
        AddNewShowTime();
    }
    else
    {
        exit(0);
    }
}



void ShowShowtimeList()
{
    system("cls");

    char choose;

    Welcome();
    qstate = mysql_query(conn, "select a.id, b.title, a.date, c.time FROM showtime a INNER JOIN movie b ON a.movie_id = b.id  INNER JOIN time_slots c ON a.slot_id = c.id");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-15s | %-15s | %-15s | \n", "Title", "Date", "Time");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-15s | %-15s | \n", row[1], row[2], row[3]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'm' to Menu any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

inline uint32_t left_rotate(uint32_t value, uint32_t shift) {
    return (value << shift) | (value >> (32 - shift));
}

// MD5 transformation function for a 64-byte block
void md5_transform(uint32_t state[4], const uint8_t block[64]) {
    static const uint32_t k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t m[16];

    // Convert the block (64 bytes) to 16 32-bit words
    for (int i = 0; i < 16; ++i) {
        m[i] = (block[i * 4 + 0] << 24) |
               (block[i * 4 + 1] << 16) |
               (block[i * 4 + 2] << 8) |
               (block[i * 4 + 3]);
    }

    for (int i = 0; i < 64; ++i) {
        uint32_t f, g;
        if (i < 16) {
            f = (b & c) | ((~b) & d);
            g = i;
        } else if (i < 32) {
            f = (d & b) | ((~d) & c);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            f = b ^ c ^ d;
            g = (3 * i + 5) % 16;
        } else {
            f = c ^ (b | (~d));
            g = (7 * i) % 16;
        }

        uint32_t temp = d;
        d = c;
        c = b;
        b = b + left_rotate((a + f + k[i] + m[g]), 7);
        a = temp;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

// MD5 algorithm main function
string md5(const string& message) {
    uint32_t state[4] = { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476 };
    uint32_t message_length = message.length();
    uint32_t bit_length = message_length * 8;

    string modifiedMessage = message;  // Make a copy of the input message

    // Pre-processing: adding a single '1' bit, padding with zeros
    modifiedMessage += static_cast<char>(0x80); // Append a '1' bit

    while ((modifiedMessage.length() % 64) != 56) {
        modifiedMessage += static_cast<char>(0x00); // Padding with zeros
    }

    // Append the length of the message in bits as a 64-bit number
    for (int i = 0; i < 8; ++i) {
        modifiedMessage += static_cast<char>((bit_length >> (i * 8)) & 0xFF);
    }

    uint32_t a0 = state[0], b0 = state[1], c0 = state[2], d0 = state[3];
    // MD5 algorithm - rest of the code here...

    stringstream ss; // Declaration of stringstream ss
    for (uint32_t s : state) {
        ss << hex << setw(8) << setfill('0') << s;
    }

    return ss.str(); // Return the hashed message
}

void RegisterUser()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string name = "";
    string email = "";
    string password = "";
    char choose;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Email: ";
    getline(cin, email);
    string select_query = "SELECT name, email, password, user_role FROM user WHERE email='"+email+"'";
    const char* q = select_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);
      if (!qstate)
    {
        res = mysql_store_result(conn);

        row = mysql_fetch_row(res);
        if (row != NULL)
        {
            cout<<"User Already Exist. Please login."<<endl;
            system("pause");
            system("cls");
             main();
        }
        else
        {
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Password: ";
            getline(cin, password);
            password = md5(password);
            string insert_query = "insert into user (name, email, password, user_role) values ('"+name+"','"+email+"','"+password+"','2')";

            q = insert_query.c_str(); // c_str converts string to constant char and this is required

            qstate = mysql_query(conn, q);

            if (!qstate)
            {
                cout << endl << "User successfully added in database." << endl;
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            // Exit Code
            cout << "Press 'm' to Menu and 'a' to Create New User Again Or Any Other key to exit: ";
            cin >> choose;
            if (choose == 'm' || choose == 'M')
            {
                system("cls");
                main();
            }
            else if (choose == 'a' || choose == 'A')
            {
                system("cls");
                RegisterUser();
            }
            else
            {
                exit(0);
            }
                }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

}

void LoginUser()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string name = "";
    string email = "";
    string password = "";
    char choose;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Password: ";
    getline(cin, password);
    password = md5(password);

    string select_query = "SELECT id, name, email, password, user_role FROM user WHERE email='"+email+"'";

    const char* q = select_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        res = mysql_store_result(conn);

        row = mysql_fetch_row(res);
        if (row[3] == password)
        {
            cout << endl << "Correct Password. User Logged In" << endl << endl;
            stringstream SS(row[0]);
            SS >> user_id;
            int result = strcmp(row[4], "1");
           if(result == 0){
            system("cls");
            adminMenu();
           }
           else {
            system("cls");
            customerMenu();
           }
        }
        else
        {
            cout << endl << "Wrong Password" << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'm' to Menu any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

