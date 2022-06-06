#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void menu() {
    cout << "  Please Enter Your Command " << endl;
    cout << "  1> Adding New Registration " << endl;
    cout << "  2> Delete Registration " << endl;
    cout << "  3> Sort The Registrations" << endl;
    cout << "  4> Print the all DATA  " << endl;
    cout << "  5> To EXIT the Program " << endl;
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
    
    if(n == '1')
        cout << "       Press >1 to Back Main menu  /" << endl;    
        cin >> n;
}



void student_adding(vector<string> data){
    
    
    ofstream file_write;
    file_write.open("main_file.txt",ios::app);

    string name;
    string surname;
    string id_num;
    string phone_num;
    string mail;

    cout << "Please Enter Student's Name :" ;
    cin >> name;
    cout << endl;

    cout << "Please Enter Student's Surname :";
    cin >> surname;
    cout << endl;

    cout << "Please Enter Student's ID Number:";
    cin >> id_num;
    cout << endl;

    cout << "Please Enter Student's Phone Number:";
    cin >> phone_num;
    cout << endl;

    cout << "Please Enter Student's E-mail Address :";
    cin >> mail;
    cout << endl;
    

    data.insert(data.begin(),name);
    data.insert(data.end(),surname);
    data.insert(data.end(),id_num);
    data.insert(data.end(),phone_num);
    data.insert(data.end(),mail);

    file_write << name + " ";
    file_write << surname + " ";
    file_write << id_num + " ";
    file_write << phone_num + " ";
    file_write << mail + "\n";

}




int main(){

    vector<string> data;
    int menuChoice = 0;
    

    while(menuChoice != 5){ 
        menu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            student_adding(data);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            print_data();
            break;
        case 5:
            cout << "Exited The Program" << endl;
            break;
        default:
            cout << "Please Enter True Command" << endl;
            break;
        }

    }

    

}