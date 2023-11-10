#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print_help();

int main(){
    //initialize the hash map
    unordered_map<int, int> hashMap;

    //display the menu
    print_help();

// loop until user is finished
 do {
	//iterate through the map and display
        for (auto x : hashMap){ 
    	    cout << x.first << " " <<  x.second << endl; 
	}

	//get desired command
        cout << endl << "Command: ";
        char cmd;
        cin >> cmd;

        int key, value;

	// if the user wants to add, get key and value 
        if (cmd == '+' ) {
            cin >> key;
	    cin >> value;
        }

	// if the user wants to remove or retrieve get the key
	else if (cmd == '?' || cmd == '-') {
            cin >> key; 
	}

	// execute the desired command
        switch (cmd) {
            case 'H':
            case 'h':
                print_help();
                break;

            case '+':
		if (hashMap.find(key) != hashMap.end()){
			cout << "That key already holds a value!" << endl;
			
			break;
		}

		else{
                	hashMap.insert(make_pair(key, value)); 
                	cout << "Inserted data item with key ("
                    		<< key << ") and value ("
                    		<< value << ")" << endl;

               		 break;
		}

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

	    // quit
            case 'Q':
            case 'q':
                return 0;

	    // user input does not match availible choices
            default:
                cout << "Invalid command" << endl;
        }
    } while (1);

    return 0;
}
//------------------------------------------------------------------------------------------
// print_help()
// no parameters
// no return value
// The print_help function displays a menu for the user to choose disired actions
void print_help(){
    cout << endl << "Commands:" << endl;
    cout << " H  : Help (displays this message)" << endl;
    cout << " +x : Insert (or update) data item with key x then desired value" << endl;
    cout << " -x : Remove the data element with the key x" << endl;
    cout << " ?x : Retrieve the data element with the key x" << endl;
    cout << " E  : Empty table?" << endl;
    cout << " C  : Clear the table" << endl;
    cout << " q  : Quit the test program" << endl;
}
