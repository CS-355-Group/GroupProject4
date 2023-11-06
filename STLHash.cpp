#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print_help();

int main(){
    unordered_map<int, int> hashMap;

    print_help();

 do {
        for (auto x : hashMap){ 
    	    cout << x.first << " " <<  x.second << endl; 
	}

        cout << endl << "Command: ";
        char cmd;
        cin >> cmd;

        int key, value;
        if (cmd == '+' || cmd == '?' || cmd == '-') {
            cin >> key;
	    cin >> value;
        }

        switch (cmd) {
            case 'H':
            case 'h':
                print_help();
                break;

            case '+':
                hashMap.insert(make_pair(key, value)); 
                cout << "Inserted data item with key ("
                    << key << ") and value ("
                    << value << ")" << endl;
                break;

            case '-':
                if (hashMap.find(key) != hashMap.end()) {
                    cout << "Removed data item with key ("
                        << key << ")" << endl;
			hashMap.erase(key);
                } 
		else {
                    cout << "Could not remove data item with key ("
                        << key << ")" << endl;
                }
                break;

            case '?':
                if (hashMap.find(key) != hashMap.end()) {
                    cout << "Retrieved data item with key ("
                        << key << ") and value ("
                        << hashMap.at(key) << ")" << endl;
                } else {
                    cout << "Could not retrieve data item with key ("
                        << key << ")" << endl;
                }
                break;

            case 'C':
            case 'c':
                cout << "Clear the hash table" << endl;
                hashMap.erase(hashMap.begin(), hashMap.end());
                break;

            case 'E':
            case 'e':
                cout << "Hash table is "
                    << (hashMap.empty() ? "" : "NOT")
                    << " empty" << endl;
                break;

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
