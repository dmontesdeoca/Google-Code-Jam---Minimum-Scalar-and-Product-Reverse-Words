#include <iostream>
#include <stack>
#include <sstream>
#include <fstream>
using namespace std;
/*
ifstream infile("B-small-practice.txt");         // file it is reading from
ofstream outfile("reverseSmallOutput.txt");      // file it is printing to
*/
ifstream infile("B-large-practice.txt");         // file it is reading from
ofstream outfile("reverseLargeOutput.txt");      // file it is printing to

bool fileIsValid();
void reverseLines(const int&);

int main(){
    int numbCases;
    string line;

    if(fileIsValid()){
        // get number of cases from file
        getline(infile,line);
        stringstream caseLine(line);
        caseLine >> numbCases;

        reverseLines(numbCases);
    }

    return 0;

}

void reverseLines(const int &numbCase){
    stack<string> storeWords;
    string token, line;

    for(int i = 0; i < numbCase; i++){
        getline(infile,line);
        // create the line into tokens
        stringstream lineStream(line);

        //  push each token on the stack (storeWords)
        while(lineStream >> token){storeWords.push(token);}

        outfile << "Case #" << i+1 << ": ";

        while( !storeWords.empty() ){
            outfile << storeWords.top() << " ";
            storeWords.pop();
        }
        outfile << endl;
    }

}
//checks to see if file is found, or if file is empty (returns false)
//if file is good and is not empty (return true)
bool fileIsValid(){
    if (!infile.good()){
        cout << "FILE NOT FOUND!" << endl;
        return false;
    }
    else if(infile.peek() == -1){
        cout << "FILE IS EMPTY!" << endl;
        return false;
    }

    return true;
}
