#include <iostream>
#include <fstream>
#include <list>
using namespace std;

/*ifstream infile("A-small-practice.txt");      // file it is reading from
ofstream outfile("scalarSmallOutput.txt");      // file it is printing to
*/
ifstream infile("A-large-practice.txt");        // file it is reading from
ofstream outfile("scalarLargeOutput.txt");      // file it is printing to

void minScalar(const int&);
void quickSort(int[], const int&, const int&, const char&);
int pivot(int[], const int&, const int&, const char&);
bool fileIsValid();

int main(){
    int numbCases;

    if(fileIsValid()){
        infile >> numbCases;
        for(int i = 1; i <= numbCases; i++){
            minScalar(i); //send what case it is in
        }
    }

    return 0;

}

//This function will find the smallest scalar product
//It prints the smallest for each case
void minScalar(const int &caseIn){
    int vectorSize;
    infile >> vectorSize;

    int v1[vectorSize], v2[vectorSize];
    long long int smallest = 0;

    char ascending = '+', descending = '-';

    //assign values in the vectors
    for(int i = 0; i < vectorSize; i++){
        infile >> v1[i];
    }
    for(int j = 0; j < vectorSize; j++){
        infile >> v2[j];
    }//end of assigning the vector values

    //sort both vectors, one ascending the other descending
    quickSort(v1,0,vectorSize-1,ascending);
    quickSort(v2,0,vectorSize-1,descending);

    for(int k = 0; k < vectorSize; k++){
        smallest += (long long int)v1[k]*v2[k];
    }

    outfile << "Case #" << caseIn << ": " << smallest <<endl;

}

//this function sorts ascending and descending order
//pass and array to be sorted and the beginning and end
//the last parameter will be either a '+' or '-' to indicate how to sort the array
void quickSort(int arr[], const int &first, const int &last, const char &order)
{
    int pivotE;

    if(first < last){
        pivotE = pivot(arr, first, last, order);
        quickSort(arr, first, pivotE-1,order);
        quickSort(arr, pivotE+1, last,order);
    }
}

// pivot is called in quickSort()
int pivot(int arr[], const int &first, const int &last, const char &order){
    int  p = first, temp;
    int pivotElement = arr[first];

    for(int i = first+1; i <= last; i++){
        if(order == '+'){                       //sort in ascending
            if(arr[i] <= pivotElement){
                p++;
                //swap
                temp = arr[i];
                arr[i] = arr[p];
                arr[p] = temp;
            }
        }
        else if(order == '-'){                  //sort in descending order
            if(arr[i] > pivotElement){
                p++;
                //swap
                temp = arr[i];
                arr[i] = arr[p];
                arr[p] = temp;
            }
        }
    }
    //swap
    temp = arr[p];
    arr[p] = arr[first];
    arr[first] = temp;

    return p;
}

//checks to see if file is found, or if file is empty (returns false)
//if file is good and is not empty (return true)
bool fileIsValid(){
    if (!infile.good()){
        cout<<"FILE NOT FOUND!"<<endl;
        return false;
    }
    else if(infile.peek() == -1){
        cout<<"FILE IS EMPTY!"<<endl;
        return false;
    }

    return true;
}

