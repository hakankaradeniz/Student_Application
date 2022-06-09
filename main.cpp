#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

void menu()
{

    cout << "  1> Adding New Registration " << endl;
    cout << "  2> Delete Registration " << endl;
    cout << "  3> Sort The Registrations" << endl;
    cout << "  4> Print the all DATA  " << endl;
    cout << "  5> To EXIT the Program " << endl;
    cout << "  Please Enter Your Command " << endl;
}

struct registration
{
    int id_num, phone_num;
    string name, surname, mail;
};

vector<registration> app;

int registration_save()
{
    ofstream data_write;
    ifstream file_read;
    file_read.open("main_file.txt");
    data_write.open("main_file.txt", ios::app);


    int pre_data{0};
    cout << "Please Enter Student's ID No: ";
    cin >> pre_data;

    while (!file_read.eof())
    {
        registration adding;
        file_read >> adding.id_num >> adding.name >> adding.surname >> adding.mail >> adding.phone_num;

        app.push_back(adding);
    }
    file_read.close();

    int ok{1};
    int i = 0;
    while (i < app.size())
    {
        if (app[i].id_num==pre_data)
        {

            ok = 0;
            break;
        }
        i++;
    }

    if (ok)
    {
        registration adding;

        cout << "Please Enter Student's Name: ";
        cin >> adding.name;
        cout << endl;
        cout << "Please Enter Student's Surname: ";
        cin >> adding.surname;
        cout << endl;
        cout << "Please Enter Student's e-mail: ";
        cin >> adding.mail;
        cout << endl;
        cout << "Please Enter Student's Phone Number: ";
        cin >> adding.phone_num;
        cout << endl;
        adding.id_num=pre_data;
        data_write << adding.id_num << " " << adding.name << " " << adding.surname << " " << adding.mail << " " << adding.phone_num << endl;

        app.push_back(adding);
    }
        data_write.close();

    return 0;
}

int main()
{

    int menuChoice{-1};

    while (menuChoice)
    {
        menu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            registration_save();
            break;
        case 2:
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            cout << "Exited The Program" << endl;
            menuChoice = 0;
            break;
        default:
            cout << "Please Enter True Command" << endl;
            break;
        }
    }
}