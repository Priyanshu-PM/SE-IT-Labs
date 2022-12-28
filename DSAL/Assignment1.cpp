#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;

// declaring the student structure
struct stud
{
    int rollno;
    char name[20];
    float sgpa;
};

// creation of the database
void createDatabase(stud students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the details of the "<< " student "<< (i + 1) << " : ";
        cin >> students[i].rollno >> students[i].name >> students[i].sgpa;
    }
}

// display the contents of the database
void displayDatabase(stud students[], int n)
{
    cout << "Displaying the contents of the database : \n\n";
    cout << "Roll no    "<< "Name       "<< "sgpa\n"<< endl;

    for (int i = 0; i < n; i++)
    {
        cout <<students[i].rollno << setw(10) << students[i].name << setw(10) << students[i].sgpa << setw(5) << endl;
    }
    cout <<"\n";

}

void selectionSort(stud students[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (students[i].rollno > students[j].rollno)
            {
                swap(students[i], students[j]);
            }
        }
    }
}

// sorting the students using according to their roll numbers using bubble sort
void bubbleSort(stud students[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].rollno > students[j + 1].rollno)
            {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void insertionSort(stud students[], int n)
{

    stud key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = students[i];
        j = i-1;
        while(j>=0 && strcmp(students[j].name, key.name) > 0) {

            students[j+1] = students[j];
            j = j-1;
        }
        students[j+1] = key;
    }
}

int partition(stud students[], int start, int end)
{

    float pivot = students[start].sgpa;
    int i = start;
    int j = end;
    while(i < j)
    {    
        while(i < end && students[i].sgpa >= pivot)
            i++;
        while(j >= 0 && students[j].sgpa < pivot)
            j--;
        if( i < j)
            swap(students[i], students[j]);
    }
    swap(students[j], students[start]);
    return j;
}

// finding first ten toppers from the class using Quick sort method
void quickSort(stud students[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(students, start, end);

        quickSort(students, start, pivot - 1);
        quickSort(students, pivot + 1, end);
    }
}

// linear search algorithm
void linearSearch(stud students[], int n)
{
    float ssgpa;
    cout << "Enter the sgpa to search : ";
    cin >> ssgpa;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (students[i].sgpa == ssgpa)
        {
            flag = true;
            cout << "Found student with same sgpa \n";
            cout << students[i].rollno << setw(15) << students[i].name << setw(10) << students[i].sgpa << endl;
        }
    }
    if (flag == false)
    {
        cout << "No record found !!\n";
    }
}


// binary search algorithm for searching students using their name
void binarySearchWithName(stud students[], int n) {

    char key[20];
    cout << "Enter the name to search :";
    cin >> key;
    int low = 0, high = n-1;
    bool flag = false;
    while(low <= high) {

        int mid = (low+high)/2;

        if(strcmp(students[mid].name, key) == 0) {
            flag = true;
            cout << "Found record with given name : \n";
            cout << students[mid].rollno << setw(10) << students[mid].name << setw(15) << students[mid].sgpa<< endl;
            break;

        }
        else {
            if(strcmp(students[mid].name, key) > 0) {
                high = mid -1;
            }

            else {
                low = mid +1;
            }
        }
    }

    if(!flag) {
        cout << "No record found with given name !!\n";
    }
}

// void linearSearch(stud students[], int n)
// {

//     int low = 0, high = n - 1;
//     char search_Name[20];
//     bool flag = false;
//     cout << "Enter the name to be searched : ";
//     cin >> search_Name;

//     for(int i = 0; i < n; i++) {
//         if(strcmp(students[i].name, search_Name) == 0) {
//             flag =true;
//             cout << "Found student with given name :\n";
//             cout << students[i].rollno <<setw(15) << students[i].name << setw(15) << students[i].sgpa << endl; 
//         }
//     }
//     if(flag == false) {
//         cout << "No student found with required name !!\n";
//     }
// }


// main method (Driver code)
int main()
{

    int n;
    cout << "Enter the numbers of students you want to enter (less than 20) : ";
    cin >> n;
    stud students[n];
    createDatabase(students, n);
    cout << "Display database contents :\n\n";
    displayDatabase(students, n);

    bubbleSort(students, n);
    cout << "\nDatabase contents after bubble sort :\n\n";
    displayDatabase(students, n);

    insertionSort(students, n);
    cout << "\nDatabase contents after insertion sort :\n\n";
    displayDatabase(students, n);


    cout << "\nDatabase contents after quick sort :\n\n";
    quickSort(students, 0, n-1);
    displayDatabase(students, n);

    insertionSort(students, n);
    cout << "\nname wise sorting !!\n";
    displayDatabase(students, n);
    // linearSearch(students, n);
    cout << "\n\n";
    binarySearchWithName(students, n);

    // int choice = 0;
    // do
    // {
    //     cout << "1. Arrange list of students according to their roll numbers\n";
    //     cout << "2. Arrange list of students alphabetically\n";
    //     cout << "3. Find out first ten toppers of the class\n";
    //     cout << "4. Search students according to sgpa\n";
    //     cout << "5. Seach students according to their name\n";
    //     cout << "6. display the database\n";
    //     cout << "0. exit\n\n";
    //     cout << "Enter your choice : ";
    //     cin >> choice;

    //     switch (choice)
    //     {

    //         case 1:
    //         {
    //             bubbleSort(students, n);
    //             displayDatabase(students, n);
    //             break;
    //         }

    //         case 2:
    //         {
    //             insertionSort(students, n);
    //             cout << "After performing insertion sort\n";
    //             displayDatabase(students, n);
    //             break;
    //         }

    //         case 3:
    //         {
    //             quickSort(students, 0, n);
    //             cout << "After performing quick sort\n";
    //             displayDatabase(students, n);
    //             break;
    //         }

    //         case 4:
    //         {
    //             linearSearch(students, n);
    //             break;
    //         }

    //         case 5:
    //         {
    //             binarySearch(students, n);
    //             break;
    //         }

    //         case 6:
    //         {
    //             displayDatabase(students, n);
    //             break;
    //         }
    //         case 0:
    //         {
    //             cout << "Program terminated successfully !!";
    //             break;
    //         }

    //         default:
    //         {
    //             cout << "Wrong choice !!\nEnter again !!\n";
    //         }
    //     }

    // } while (choice != 0);

    return 0;
}