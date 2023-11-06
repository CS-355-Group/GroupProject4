#include <iostream>
#include <unordered_map>
using namespace std;

void print_help();

int main(){
    unordered_map<int, int> hashMap;

    print_help();

    do {
	    hashMap;

	    cout << endl << "Command: ";
	    char cmd;
	    cin >> cmd;




}

void print_help(){
    cout << endl << "Commands:" << endl;
    cout << " H  : Help (displays this message)" << endl;
    cout << " +x : Insert (or update) data item with key x" << endl;
    cout << " -x : Remove the data element with the key x" << endl;
    cout << " ?x : Retrieve the data element with the key x" << endl;
    cout << " E  : Empty table?" << endl;
    cout << " C  : Clear the table" << endl;
    cout << " q  : Quit the test program" << endl;
}
