#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct switch_case
{
    
};

//////////////////////////////////////////////////////////////////////////////
void entering_app(){
    cout << " /////////////////////////// Please Enter Your Command ////////////////////////////" << endl;
    cout << " /////////////////////////// 1- Adding New Registration ///////////////////////////" << endl;
    cout << " /////////////////////////// 2- Delete Registration ///////////////////////////////" << endl;
    cout << " /////////////////////////// 3- Sort The Registrations ////////////////////////////" << endl;
}

void re_entering_app(){
    cout << " /////////////////////////// Press -1- to Add New Registration ////////////////////////////" << endl;
    cout << " ///////////////////////////        Press -2- to EXIT          ////////////////////////////" << endl;          
}
//////////////////////////////////////////////////////////////////////////////
void adding(){

    string entered = "";
    vector<string> data;

    ofstream file_database;
    file_database.open("database.txt",ios::app);

    for (int i = 0; i < 5; i++)
    {
        if (i == 0){
            cout << "Please Enter Student's Name : ";
            cin >> entered;
            data.insert(data.begin(),string(entered));
            file_database << entered + " ";
        }else if (i == 1){
            cout << "Please Enter Student's Surname : ";
            cin >> entered;
            data.insert(data.end(),string(entered));
            file_database << entered + " ";
        }else if (i == 2){
            cout << "Please Enter Student's ID Number : ";
            cin >> entered;
            data.insert(data.end(),string(entered));
            file_database << entered + " ";
        }else if (i == 3){
            cout << "Please Enter Student's Phone Number : ";
            cin >> entered;
            data.insert(data.end(),string(entered));
            file_database << entered + " ";
        }else if (i == 4){
            cout << "Please Enter Student's e-mail Address : ";
            cin >> entered;
            data.insert(data.end(),string(entered));   
            file_database << entered+"\n";
        }
    }
    
}



