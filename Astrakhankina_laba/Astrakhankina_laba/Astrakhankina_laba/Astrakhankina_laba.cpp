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

struct Station{
    string ks_name = "None";
    int ks_all_cex = 0;
    int ks_act_cex = 0;
    int ks_effect = 0;
};

int inputInt(string message, int min_value, int max_value) {
    int value;

    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min_value || value > max_value)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << message;
    }
    return value;
}
int inputDouble(string message, double min_value, double max_value) {
    int value;

    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min_value || value > max_value)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << message;
    }
    return value;
}
 bool isValidName(const string& name) {
    return name != "None";
}

 //----------------------------------------------------------------------------------------
Pipe createPipe(){
    Pipe newPipe;
    cout << "Enter the name of the pipe: ";
    cin >> ws;
    getline(cin, newPipe.name);
    cout << "Enter the length of the pipe: ";
    newPipe.length = inputDouble("\nPlease, enter a positive double type\n",0,10000);
    cout << "Enter the diameter of the pipe: ";
    newPipe.diameter = inputInt("\nPlease, enter a positive integer type\n", 1, 10000);
    cout << "Does the pipe need repair? (0 for No, 1 for Yes): ";
    newPipe.remont=inputInt("\nPlease, enter a boolean type (0 or 1)\n",0,1);
    return newPipe;
}
void displayPipe(const Pipe& pipe) {
    if (!isValidName(pipe.name)) {
        return;
    }
    cout << "\n-----------Pipe Info-----------\n"
        << "Name: " << pipe.name << "\n"
        << "Length: " << pipe.length << "\n"
        << "Diameter: " << pipe.diameter << "\n"
        << "Needs Repair: " << (pipe.remont ? "Yes" : "No") << "\n";
}
void editRemont(Pipe& pipe) {
    if (!isValidName(pipe.name)) {
        cout << "\nNo data to change\n";
        return;
    }
    cout << "Change repair status (0 for No, 1 for Yes): ";
    pipe.remont = inputInt("\nPlease, enter a boolean type (0 or 1)\n", 0, 1);
    cout << "\nChanges saved\n";
}
void writePipeToFile( ofstream& out, Pipe& pipe) {
    if (!isValidName(pipe.name)) {
        cout << "\nNo data to record pipe\n";
        out.close();
        return;
    }
    out << "-----------Pipe Info-----------\n"
        << pipe.name << "\n"
        << pipe.length << "\n"
        << pipe.diameter << "\n"
        << pipe.remont << "\n";
    cout << "Pipe writing to file completed...\n";
}
void readPipeFromFile(ifstream& in,Pipe& pipe) {
    getline(in, pipe.name);
    in >> pipe.diameter;
    in >> pipe.length;
    in >> pipe.remont;
}
//-------------------------------------------------------------------------------------------------
Station createStation(){
    Station newStation;
    cout << "Enter the name of the station: ";
    cin >> ws;
    getline(cin, newStation.ks_name);
    cout << "Enter the number workshops: ";
    newStation.ks_all_cex=inputInt("\nPlease, enter a possitive integer type\n",0,10000);
    while (true) {
        cout << "Enter the number of operating workshops: ";
        newStation.ks_act_cex = inputInt("\nPlease, enter a possitive integer type\n", 0, 10000);
        if (newStation.ks_act_cex <= newStation.ks_all_cex) {
            break;
        }
        else {
            cout << "\nThe number of operating workshops cannot exceed the total number of workshops\n";
        }
    }
    cout << "Enter station efficiency from 0 to 5: ";
    newStation.ks_effect=inputInt("\nPlease, enter a possitive integer type from 0 to 5\n",0,5);
    return newStation;

}
void displayStation(const Station& ks) {
    if (!isValidName(ks.ks_name)) {
        return;
    }
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
void editCex(Station& ks) {
    if (!isValidName(ks.ks_name)) {
        cout << "\nNo data to change\n";
        return;
    }
    cout << "Change number workshops: ";
    ks.ks_all_cex=inputInt("\nPlease, enter a possitive integer type\n", 0, 10000);
    int act_cex;
    while (true) {
        cout << "Change number of operating workshops: ";
        act_cex = inputInt("\nPlease, enter a possitive integer type\n", 0, 10000);
        if (act_cex <= ks.ks_all_cex) {
            ks.ks_act_cex = act_cex;
            break;
        }
        else {
            cout << "\nThe number of operating workshops cannot exceed the total number of workshops\n";
        }
    }
    cout << "\nChanges saved\n";
}
void writeStationToFile(ofstream&out, Station& ks) {
    if (!isValidName(ks.ks_name)) {
        cout << "\nNo data to record station\n";
        out.close();
        return;
    }
    out << "-----------Station Info-----------\n"
        << ks.ks_name << "\n"
        << ks.ks_all_cex << "\n"
        << ks.ks_act_cex << "\n"
        << ks.ks_effect << "\n";
    cout << "Station writing to file completed...\n";
}
void readStationFromFile(ifstream& in, Station& ks) {
    getline(in, ks.ks_name);
    in >> ks.ks_all_cex;
    in >> ks.ks_act_cex;
    in >> ks.ks_effect;
}
void readAll(ifstream& in, Pipe& pipe, Station& ks){
    string str;
    bool pipeRead = false;
    bool stationRead = false;

    while (getline(in, str)) {
        if (str == "-----------Pipe Info-----------") {
            readPipeFromFile(in, pipe);
            pipeRead = true;
            cout << "Data about pipe added\n" << endl;
        }
        else if (str == "-----------Station Info-----------") {
            readStationFromFile(in, ks);
            stationRead = true;
            cout << "Data about station added\n" << endl;
        }
        /*else {
            return;
        }*/
    }
    if (!pipeRead) {
        cout << "No pipe information found in the file.\n";
    }
    if (!stationRead) {
        cout << "No station information found in the file.\n";
    }
}
//--------------------------------------------------------------------------------------------------
int main()
{   
    int n = -1;
    Pipe currentPipe;
    Station currentStation;
    string file = "pipe and station.txt";

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

        if (cin.fail() || n < 0 || n > 7){
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
            currentStation = createStation();
            displayStation(currentStation);
            break;
        }
        case 3: //view all
        {
            displayPipe(currentPipe);
            displayStation(currentStation);
            break;
        }
        case 4: //edit pipe
        {
            editRemont(currentPipe);
            displayPipe(currentPipe);
            break;
        }
        case 5: //edit ks
        {
            editCex(currentStation);
            displayStation(currentStation);
            break;
        }
        case 6: //write
        {
            ofstream out;
            out.open(file, ios::out);
            if (out.is_open()) {
                writePipeToFile(out, currentPipe);
                writeStationToFile(out, currentStation);
                out.close();
            }
            break;
        }
        case 7://read
        {
            ifstream in;
            in.open(file, ios::in);
            if (in.is_open()){
                readAll(in, currentPipe, currentStation);
                in.close();
            }
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
