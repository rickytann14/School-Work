#include <iostream>

using namespace std;

int main()
{
    int array[] = {31, 32, 33, 34, 35};
    int Test_Input = 5;

    int sum = 0;
    int largest = array[0];
    int smallest = array[0];

    for(int i = 0; i < Test_Input; i++)
    {
        sum = sum + array[i];

        if(array[i] > largest)
        {
            largest = array[i];
        }

        else if(array[i] < smallest)
        {
            smallest = array[i];
        }
    }

    cout << "Sum: " << sum << endl;                 // X10
    cout << "Largest: " << largest << endl;         // X11
    cout << "Smallest: " << smallest << endl;       // X12

}