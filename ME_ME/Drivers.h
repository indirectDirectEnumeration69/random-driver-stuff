#include <fstream>
#include <iostream>

int Printinf() {
    using namespace std;
    fstream file;
    file.open("drive.inf", ios::out);
    file << "[autorun]\n";
    file << "open=drive.txt\n";         //SPREAD OR BE DEAD 8b
    file << "icon=drive.ico\n";
    file << "label=MyCD\n";
    if (!file)
    {
        cout << "Error in creating file!!!";
        return 0;
    }
    cout << "File created successfully.";
    file.close();

    return 0;
}