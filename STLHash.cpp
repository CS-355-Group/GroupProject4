#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print_help();

int main(){
    unordered_map<int, int> hashMap;

    print_help();

     do {
        table.showStructure();

        cout << endl << "Command: ";
        char cmd;
	string input;
	int pos = 1;
        int item, key;
        getline(cin,input); 

	cmd = input.substr(0,pos);
	input.erase(0,pos);
	pos = input.find(" ");
	key = input.substr(0,pos);
	input.erase(0,++pos);
	value = input;

	/*
        if (cmd == '+' || cmd == '?' || cmd == '-') {
           
        }

        switch (cmd) {
            case 'H':
            case 'h':
                print_help();
                break;

            case '+':
                table.insert(item, item.getKey());
                cout << "Inserted data item with key ("
                    << item.getKey() << ") and value ("
                    << item.getValue() << ")" << endl;
                break;

            case '-':
                if (table.remove(item.getKey())) {
                    cout << "Removed data item with key ("
                        << item.getKey() << ")" << endl;
                } else {
                    cout << "Could not remove data item with key ("
                        << item.getKey() << ")" << endl;
                }
                break;

            case '?':
                if (table.retrieve(item.getKey(), item)) {
                    cout << "Retrieved data item with key ("
                        << item.getKey() << ") and value ("
                        << item.getValue() << ")" << endl;
                } else {
                    cout << "Could not retrieve data item with key ("
                        << item.getKey() << ")" << endl;
                }
                break;

            case 'C':
            case 'c':
                cout << "Clear the hash table" << endl;
                table.clear();
                break;

            case 'E':
            case 'e':
                cout << "Hash table is "
                    << (table.isEmpty() ? "" : "NOT")
                    << " empty" << endl;
                break;
*/
            case 'Q':
            case 'q':
                return 0;

            default:
                cout << "Invalid command" << endl;
        }
    } while (1);

    return 0;
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
