#include <iostream>
#include <fstream>
#include <vector>

#define fileA "/home/uco1518/CLionProjects/pmul/cmake-build-debug/groupa.txt"
#define fileB "groupb.txt"
#define fileC "groupc.txt"

using namespace std;

void showTable(char &i);

void updateTable(char &i);

void writeFile(char &i, vector<string> &names, vector<int> &points);

int getPoistionPoints(int position);


int main() {

    string input = "1 a";
    while (input[0] != '0') {
        cout << "\033[2J\033[1;1H";
        cout << endl << "Enter 1 to show table" << endl;
        cout << "Enter 2 to update table" << endl;
        getline(cin, input);
        if (input[0] == '1')
            showTable(input[2]);
        if (input[0] == '2')
            updateTable(input[2]);
    }
    return 0;
}

void readFile(char &i, vector<string> &names, vector<int> &points) {

    ifstream ifile;

    switch (i) {
        case 'a':
            ifile.open(fileA);
            break;
        case 'b':
            ifile.open(fileB);
            break;
        case 'c' :
            ifile.open(fileC);
            break;
    }
//    cout << ifile.good() << endl;
//    string line;

    while (ifile.good()) {

        string name;
        ifile >> name;
        string temp;
        ifile >> temp;
//        cout<<name <<" "<<temp<<endl;
        if (name.size() > 0) {
            int point = stoi(temp);
            names.push_back(name);
            points.push_back(point);
        }
    }
    ifile.close();
}

void updateTable(char &i) {

    vector<string> names;
    vector<int> points;
    readFile(i, names, points);

    while (1) {
        cout << "\033[2J\033[1;1H" << endl;
        cout << "Enter update line \nteamCode \n position \n killpoint" << endl;
        string x, y, z;
        cin >> x >> y >> z;
        if (x == "q")
            break;
        else {


            int teamCode = stoi(x);
            int position = stoi(y);
            int killpoints = stoi(z);

            points[teamCode] += getPoistionPoints(position) + killpoints;
        }
    }
    writeFile(i, names, points);


}


int getPoistionPoints(int position) {
    //todo : place the switch case here
    return position;
}

void showTable(char &i) {

    vector<string> names;
    vector<int> points;
    readFile(i, names, points);

    //todo : sort it;
    for (int k = 0; k < names.size(); k++)
        cout << names[k] << "   " << points[k] << endl;

}

void writeFile(char &i, vector<string> &names, vector<int> &points) {
    ofstream ofile;

    switch (i) {
        case 'a':
            ofile.open(fileA);
            break;
        case 'b':
            ofile.open(fileB);
            break;
        case 'c' :
            ofile.open(fileC);
            break;
    }
    for (int i = 0; i < names.size(); i++) {
        string line = names[i] + ' ' + to_string(points[i]) + '\n';
        ofile << line;
    }
    ofile.close();

}
