#include <iostream>
#include <sstream>
#include <AVLTree.h>
using namespace std;

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/

/*
 * CITATIONS:
 *         https://cplusplus.com/forum/beginner/50209/
 *         https://www.geeksforgeeks.org/
 *
 */


bool checkNameValidity(string _input) {
	for (char c : _input) {
		if (!isalpha(c) || c == ' ') {
			return false;
		}
	}
	return true;
}

bool checkDigits(string _input) {
    for (char c : _input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool checkIDValidity(string _input) {
	if(_input.length() > 8) {
		return false;
	}
	return checkDigits(_input);
}

int main(){
    string commandCapIn;
    int commandCap;
    AVLTree tree;

    // collect the command cap
    getline(cin, commandCapIn);
    while(!checkDigits(commandCapIn)) {
        cout << "unsuccessful\n";
        getline(cin, commandCapIn);
    }
    commandCap = stoi(commandCapIn);

	for(int k = 0; k < commandCap; k++) {
        string line;
        string command = "";
        string paraOne = "";
        string paraTwo = "";

        // read 1 line of cin
        getline(cin, line);

        bool isName = false;
        int parameterTracker = 0; // keeps track of what variable to add to
        bool successful = true;

        for (int i = 0; i < line.size(); i++) { // read command character by character
            if (line[i] == '\"') { // if character = "
                successful = !successful; // while quotations not finished, mark as unsuccessful
                isName = true;
                if (0 == parameterTracker) {
                    cout << "incrementing tracker" << endl;
                    parameterTracker++;



                }
            } else if (line[i] == ' ' && successful) { // if it's a space and the quotations haven't finished
                parameterTracker++;

                // depending on tracker, add to proper variable
            } else if (parameterTracker == 0) { command += line[i]; }
            else if (parameterTracker == 1) { paraOne += line[i]; }
            else if (parameterTracker == 2) { paraTwo += line[i]; }
            else if (parameterTracker > 2) { successful = false; }
        }

        if (checkDigits(paraOne)) {
            if (paraOne[0] < 33) { // remove leading white space
                paraOne.erase(paraOne.begin());
            }

            // remove ending white space
            paraOne.erase(paraOne.find_last_not_of(" \t\n\r\f\v") + 1);
        }

        // run commands
        if (!successful) { // if already marked as unsuccessful
            cout << "unsuccessful";

        } else if (command == "insert") { // insert NAME ID
            if((!checkNameValidity(paraOne) && isName) || !checkIDValidity(paraTwo)) {
                cout << "unsuccessful";

            } else {
                if(tree.insertNode(paraOne, stoi(paraTwo)) == nullptr) {
                    cout << "unsuccessful";
                } else {
                    cout << "successful";
                }

            }

        } else if (command == "remove") { // remove ID
            // if not valid, invalid
            if(!checkIDValidity(paraOne)) {
                cout << "unsuccessful";

            } else {
                cout << tree.removeByID(stoi(paraOne));

            }

        } else if (command == "search") { // search by name OR ID
            if (checkNameValidity(paraOne) && isName){ // if name
                string foundString = tree.searchByName(paraOne);
                if (foundString == "") {
                    cout << "unsuccessful";

                } else {
                    cout << foundString;

                }

            } else if (checkIDValidity(paraOne)){ // if ID
                cout << tree.searchByID(stoi(paraOne));

            } else {
                cout << "unsuccessful";

            }

        } else if (command == "printInorder") { // print inorder traversal
            cout << tree.inorderTraversal();

        } else if (command == "printPreorder") { // print preorder traversal
            cout << tree.preorderTraversal();

        } else if (command == "printPostorder") { // print postorder traversal
            cout << tree.postorderTraversal();

        } else if (command == "printLevelCount") { // print maximum level
            cout << tree.levelCount();

        } else if (command == "removeInorder") { // remove the Nth value of the inorder traversal
            if (!checkDigits(paraOne)) { // check if first parameter is an integer
                cout << "unsuccessful";
            } else {
                cout << tree.removeAtN(stoi(paraOne));
            }

        } else { // command not recognized
            cout << "unsuccessful";
        }
        cout << "\n";

	}

    exit(0);
}

