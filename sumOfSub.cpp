#include<iostream>
using namespace std;

#define MAX 20

int n, m;
static int count = 0;
int w[MAX];
int x[MAX];

void printx() {
    count++;
    cout << "Solution " << count << " : ";
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void sumOfSub(int sum, int item, int remSum) {
    if(sum == m && remSum == 0) {
        printx();
    }
    if(sum > m || remSum == 0) {
        return;
    }
    else {
        x[item] = 1; //if item is included
        sumOfSub(sum+w[item], item+1, remSum-w[item]);
        x[item] = 0; //if item is excluded
        sumOfSub(sum, item+1, remSum-w[item]);
    }
}

int main()
{
    int rSum = 0;
    cout << "Enter the number of items : ";
    cin >> n;
    cout << "Enter the weights : ";
    for(int i=0; i<n; i++)
    {
        cin >> w[i];
        rSum += w[i];
    }
    cout << "Enter the capacity : ";
    cin >> m;
    sumOfSub(0, 0, rSum);
}