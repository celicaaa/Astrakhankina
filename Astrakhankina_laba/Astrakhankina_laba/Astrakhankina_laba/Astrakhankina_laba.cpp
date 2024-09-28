// Astrakhankina_laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Pipe {

    string name = "None";
    double length = 0.0;
    int diameter = 0;
    bool remont = false;

};

struct Stantion{

    string ks_name = "None";
    int ks_all_cex = 0;
    int ks_act_cex = 0;
    int ks_effect = 0;

};

void inputInt(int& value) {
    cin >> value;
    while (cin.fail() || cin.peek() != '\n' || value <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nPlease, enter a positive integer type\n";
        cin >> value;
    }
}
void inputEffect(int& value){
    cin >> value;
    while (cin.fail() || cin.peek() != '\n' || value> 5 || value<0){
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter an integer type from 0 to 5\n";
        cin >> value;
    }
}
void inputDouble(double& value) {
    cin >> value;
    while (cin.fail() || cin.peek() != '\n' || value <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nPlease, enter a positive double type\n";
        cin >> value;
    }
}
void inputBool(bool& value) {
    cin >> value;
    while (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nPlease, enter a boolean type (0 or 1)\n";
        cin >> value;
    }
}

Pipe createPipe()

{
    Pipe newPipe;
    cout << "Enter the name of the pipe: ";
    cin >> newPipe.name;
    cout << "Enter the length of the pipe: ";
    inputDouble(newPipe.length);
    cout << "Enter the diameter of the pipe: ";
    inputInt(newPipe.diameter);
    cout << "Does the pipe need repair? (0 for No, 1 for Yes): ";
    inputBool(newPipe.remont);
    return newPipe;

}

void displayPipe(const Pipe& pipe) {
    cout << "\n-----------Pipe Info-----------\n"
        << "Name: " << pipe.name << "\n"
        << "Length: " << pipe.length << "\n"
        << "Diameter: " << pipe.diameter << "\n"
        << "Needs Repair: " << (pipe.remont ? "Yes" : "No") << "\n";
}
void editRemont(Pipe& pipe) {
    cout << "Change repair status (0 for No, 1 for Yes): ";
    inputBool(pipe.remont);
}

Stantion createStantion(){
    Stantion newStantion;
    cout << "Enter the name of the station: ";
    cin >> newStantion.ks_name;
    cout << "Enter the number workshops: ";
    inputInt(newStantion.ks_all_cex);
    int act_cex;
    while (true) {
        cout << "Enter the number of operating workshops: ";
        inputInt(act_cex);
        if (act_cex <= newStantion.ks_all_cex) {
            newStantion.ks_act_cex = act_cex;
            break;
        }
        else {
            cout << "\nThe number of operating workshops cannot exceed the total number of workshops\n";
        }
    }
    cout << "Enter station efficiency from 0 to 5: ";
    inputEffect(newStantion.ks_effect);
    return newStantion;

}

void displayStantion(const Stantion& ks) {
    cout << "\n-----------Station Info-----------\n"
        << "Name: " << ks.ks_name << "\n"
        << "Number workshops: " << ks.ks_all_cex << "\n"
        << "Number of operating workshops: " << ks.ks_act_cex << "\n"
        << "Station efficiency: " 
        << (ks.ks_effect == 0 ? "not working"
            : ks.ks_effect == 1 ? "low efficiency"
            : ks.ks_effect == 2 ? "medium efficiency"
            : ks.ks_effect == 3 ? "high efficiency"
            : ks.ks_effect == 4 ? "very high efficiency"
            : ks.ks_effect == 5 ? "excellent efficiency" : "")
        << "\n";
}
void editCex(Stantion& ks) {
    cout << "Change number workshops: ";
    inputInt(ks.ks_all_cex);
    int act_cex;
    while (true) {
        cout << "Change number of operating workshops: ";
        inputInt(act_cex);
        if (act_cex <= ks.ks_all_cex) {
            ks.ks_act_cex = act_cex;
            break;
        }
        else {
            cout << "\nThe number of operating workshops cannot exceed the total number of workshops\n";
        }
    }
}


int main()
{   
    int n = -1;
    Pipe currentPipe;
    Stantion currentStantion;

    while (true) {
        cout << endl << "Menu:\n";
        cout << "1 Add pipe\n";
        cout << "2 Add station\n";
        cout << "3 View all objects\n";
        cout << "4 Edit pipe\n";
        cout << "5 Edit station\n";
        cout << "6 Save\n";
        cout << "7 Download\n";
        cout << "0 Exit\n";
        cout << "\nEnter the command number: ";
        cin >> n;

        if (cin.fail() || n < 0 || n > 7)
        {
            cout << "Invalid choice. Please try again. \n" ;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (n)
        {
        case 1: //add pipe
        {
            currentPipe = createPipe();
            displayPipe(currentPipe);
            break;
        }
        case 2: //add ks
        {
            currentStantion = createStantion();
            displayStantion(currentStantion);
            break;
        }
        case 3: //view all
        {
            displayPipe(currentPipe);
            displayStantion(currentStantion);
            break;
        }
        case 4: //edit pipe
        {
            editRemont(currentPipe);
            cout << "\nChanges saved\n";
            displayPipe(currentPipe);
            break;
        }
        case 5: //edit ks
        {
            editCex(currentStantion);
            cout << "\nChanges saved\n";
            displayStantion(currentStantion);
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
            cout << "exit..........." << endl;
            return false;
            break;
        }
        }
    }
    return 0;
}


