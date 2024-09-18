// Astrakhankina_laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;
struct Pipe {

    string name = "None";
    float length = 0.0;
    int diameter = 0;
    bool remont = false;

};

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

            cout << "iwed" << endl;
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
        case 5: //save
        {
            cout << "slwo" << endl;
            break;
        }
        }
    }
    return 0;
}


