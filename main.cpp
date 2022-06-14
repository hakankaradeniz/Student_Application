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
            cout << "There is a Registration with the same ID Number " << endl;        
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
        
        cout << "Please Enter Student's Surname: ";
        cin >> adding.surname;
        
        cout << "Please Enter Student's e-mail: ";
        cin >> adding.mail;
        
        cout << "Please Enter Student's Phone Number: ";
        cin >> adding.phone_num;
        
        adding.id_num=pre_data;
        data_write << adding.id_num << " " << adding.name << " " << adding.surname << " " << adding.mail << " " << adding.phone_num << endl;

        app.push_back(adding);
    }
    
    data_write.close();
        
    return 0;
}

void print_data(){

    char n;
    ifstream file_read;
    file_read.open("main_file.txt");
    file_read >> noskipws;
    while (file_read >> n)
    {
       cout << n;
    }

    cout << "       Press> 1 to Back Main Menu  " << endl;    
    cin >> n;

}

int registration_delete(){

    ofstream data_write;
    ifstream file_read;
    file_read.open("main_file.txt");
    data_write.open("main_file_2.txt", ios::app);

    int pre_data{0};
    cout << "Please Enter Student's ID No: ";
    cin >> pre_data;

    while (!file_read.eof())
    {
        registration adding;
        file_read >> adding.id_num >> adding.name >> adding.surname >> adding.mail >> adding.phone_num;

        app.push_back(adding);
    }

    auto it = app.begin();
    int i = 0;

    while (i < app.size())
    {
        if (app[i].id_num==pre_data)
        {

            app.erase(it);
            cout << "DELETED" << endl;
            break;
        }else
            cout << "There is a Registration with the same ID Number " << endl;  
        i++;
        it++;
    }

    for (int i = 0; i < app.size()-1; i++)
    {
        data_write << app[i].id_num << " " << app[i].name << " " << app[i].surname << " " << app[i].mail << " " << app[i].phone_num << endl;
    }
    
    data_write.close();
    file_read.close();

    remove("main_file.txt");
    rename("main_file_2.txt","main_file.txt");

    return 0;
}

int registration_sorting(){
    int sorting_num{-1};
    int loop{-1};

    ifstream file_read;
    file_read.open("main_file.txt");
    ofstream data_write;
    data_write.open("main_file_2.txt", ios::app);

    while (!file_read.eof())
    {
        registration adding;
        file_read >> adding.id_num >> adding.name >> adding.surname >> adding.mail >> adding.phone_num;

        app.push_back(adding);
    }

    cout << "Please Enter Your Sorting Choice :";
    cout << "1> Among Student ID " << endl;
    cout << "2> Among Name " << endl;
    cout << "3> Among Surnane " << endl;
    cout << "4> Among Mail " << endl;
    cout << "5> Among Phone Number " << endl;
    cin >> sorting_num;

   
   switch (sorting_num)
   {
       case 1:
               for (int i = 0; i < app.size()-1; i++)
               {
               data_write << app[i].id_num << " " << app[i].name << " " << app[i].surname << " " << app[i].mail << " " << app[i].phone_num << endl;
               }
               rename("main_file_2.txt","Student_Num.txt");
           break;
       case 2:
               for (int i = 0; i < app.size()-1; i++)
               {
               data_write  << app[i].name << " " << app[i].surname << " " << app[i].mail << " " << app[i].phone_num << " " << app[i].id_num << endl;
               }
               rename("main_file_2.txt","Name.txt");
           break;
       case 3:
               for (int i = 0; i < app.size()-1; i++)
               {
               data_write  << app[i].surname << " " << app[i].name << " " << app[i].id_num << " " << app[i].mail << " " << app[i].phone_num << endl;
               }
               rename("main_file_2.txt","Surname.txt");
           break;
       case 4:
               for (int i = 0; i < app.size()-1; i++)
               {
               data_write  << app[i].mail << " " << app[i].id_num << " " << app[i].name << " " << app[i].surname << " " << app[i].phone_num << endl;
               }
               rename("main_file_2.txt","Mail.txt");
           break;
       case 5:
               for (int i = 0; i < app.size()-1; i++)
               {
               data_write  << app[i].phone_num << " " << app[i].id_num << " " << app[i].name << " " << app[i].surname << " " << app[i].mail << endl;
               }
               rename("main_file_2.txt","Phone_Num.txt");
           break;
    
       default: cout << "Wrong Command ! ";
           break;
   }

    data_write.close();
    file_read.close();

    
    

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
            registration_delete();
            break;
        case 3:
            registration_sorting();
            break;
        case 4:
            print_data();
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