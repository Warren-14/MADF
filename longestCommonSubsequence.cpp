#include<iostream>
#include<string>
using namespace std;

int Max(int x, int y) {
    return (x > y) ? x : y;
}

void lcs(string string1, string string2, int length1, int length2) {
    int matrix[length1+1][length2+1];
    //calculating the values of the matrix
    //i and j start from 1 since 0 row and column are already filled
    for(int i=0; i<=length1; i++) {
        for(int j=0; j<=length2; j++) {
        //initializing first row and column of the matrix to zero
        //condition 1
            if(i==0 || j==0) {
                matrix[i][j] = 0;
            }
            //condition 2
            //if a character from string1 matches with a character from string2
            else if(string1[i-1] == string2[j-1]) {
                matrix[i][j] = 1 + matrix[i-1][j-1];
                //where matrix[i-1][j-1] is the diagonal element
            }
            else {
                matrix[i][j] = Max(matrix[i-1][j], matrix[i][j-1]);
                //picking the maximum of an element that is either on the left or above current element
            }
        }
    }
    //return(matrix[length1][length2]); //returning this element because it contains length of subsequence
    int index = matrix[length1][length2]; //keeps track of visited indices

    //character array to store lcs string
    char lcs[index]; //why +1?
    lcs[index] = '\0';

    int i = length1, j = length2;
    while(i>0 && j>0) /*so that it doesn't reach the zero row and column */ {
        if(string1[i-1] == string2[j-1]) {
            lcs[index] = string1[i-1];
            i--;
            j--;
            index--;
        }
        else if(matrix[i-1][j] > matrix[i][j-1])
            i--; //move upwards if greater
        else
            j--; //move left if greater
    }
    for(int i=0; i<=length1; i++) {
        for(int j=0; j<=length2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "LCS of " << string1 << " and " << string2 << " is " << "'" << lcs << "'" << endl << endl;
    cout << "Length of longest common sub-sequence : " << matrix[length1][length2] << endl << endl;
}
int main() {
    string string1, string2;
    cout << "Enter string 1 : ";
    cin >> string1;
    cout << "Enter string 2 : ";
    cin >> string2;

    int length1 = string1.length();
    int length2 = string2.length();

    lcs(string1, string2, length1, length2);
    return 0;
}
