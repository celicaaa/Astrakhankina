// Astrakhankina_laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;
struct Pipe {

    string name = "None";
    double length = 0.0;
    int diameter = 0;
    bool remont = false;

};

int check_int(int& int_data)

{
    cin >> int_data;
    while (cin.fail() || cin.peek() != '\n' || int_data <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter an int type > 0\n";
        cin >> int_data;
    }
    return int_data;
}
double check_double(double& double_data)
{
    cin >> double_data;
    while (cin.fail() || cin.peek() != '\n' || double_data <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a double type > 0\n";
        cin >> double_data;

    }
    return double_data;

}

bool check_bool(bool& bool_data)

{
    cin >> bool_data;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a bool type\n";
        cin >> bool_data;

    }
    return bool_data;
}
Pipe AddPipe()

{

    Pipe new_pipe;
    cout << endl << "Adding a new pipe..." << endl;
    cout << "Enter the name of the pipe: ";
    cin>>new_pipe.name;

    cout << "Enter the length of the pipe: ";
    check_double(new_pipe.length);

    cout << "Enter the pipe diameter: ";
    check_int(new_pipe.diameter);

    cout << "Enter the repair status: ";
    check_bool(new_pipe.remont);

    return new_pipe;

}

void PrintAddPipe(Pipe& new_pipe)

{
    cout << endl << "Info about your pipe..." << endl;
    if (new_pipe.name == "None")
    {
        cout << "No pipes available!\n";
    }
    else
    {
        cout << "Name: " << new_pipe.name << "\tLength: " << new_pipe.length

            << "\tDiameter: " << new_pipe.diameter << "\tRepair: " << new_pipe.remont << endl;
    }
}


int main()
{   
    Pipe pipe0;
    int n;
    while (true) {
        cout << endl << "Menu:" << endl;
        cout << "1 Add pipe" << endl;
        cout << "2 Add CS" << endl;
        cout << "3 View all objects" << endl;
        cout << "4 Edit pipe" << endl;
        cout << "5 Edit CS" << endl;
        cout << "6 Save" << endl;
        cout << "7 Download" << endl;
        cout << "0 Exit" << endl;
        cout << endl << "Enter the command number: ";
        cin >> n;

        if (cin.fail() || n < 0 || n > 7)
        {
            cout << "Not found this command" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (n)
        {
        case 1: //add pipe
        {
            pipe0 = AddPipe();
            PrintAddPipe(pipe0);
            break;
        }
        case 2: //add cs
        {
            cout << "iwed" << endl;
            break;
        }
        case 3: //edit pipe
        {
            cout << "jdku" << endl;
            break;
        }
        case 4: //edit cs
        {
            cout << "jeiw" << endl;
            break;
        }
        case 5: 
        {
            cout << "slwo" << endl;
            break;
        }
        case 6: //save
        {
            cout << "slwo" << endl;
            break;
        }
        case 7: 
        {
            cout << "slwo" << endl;
            break;
        }
        case 0: //exit
        {
            cout << "slwo" << endl;
            break;
        }
        }
    }
    return 0;
}


