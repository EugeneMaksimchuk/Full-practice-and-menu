#include<iostream>
#include<time.h>
#include<string>
#include <conio.h>
#include<fstream>
#include <windows.h>
using namespace std;


//Menu functions



void SetColor(int col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Size_Console(int x, int y)
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { x, y };
    SMALL_RECT src = { 0, 0, crd.X , crd.Y };
    SetConsoleWindowInfo(out_handle, true, &src);
    SetConsoleScreenBufferSize(out_handle, crd);
}
int Menu(string menu_items[], int SIZE) {
    int key = 0;
    int code;
    do {
        //system("cls");
        key = (key + SIZE) % SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            SetPos(20, 10 + i);
            if (key == i)
            {

                cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
            }
            else
            {
                cout << " "; cout << menu_items[i]; cout << " " << endl;
            }

        }
        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == 80) key++;
            if (code == 72) key--;
        }
    } while (code != 13);
    system("cls");
    return key;
}





// End of menu functions
struct Date
{
    int day;
    int month;
    int year;
    void Print()
    {
        cout << "Day:" << day << endl;
        cout << "Month:" << month << endl;
        cout << "Year:" << year << endl;
    }
    void Fill()
    {
        cout << "Day:";
        cin >> day;
        cout << endl << "Month:";
        cin >> month;
        cout << endl << "Year:";
        cin >> year;
    }
    void FillRandom(int min, int max)
    {
        day = 1 + rand() % 31;
        month = 1 + rand() % 12;
        year = min + (rand() % (max - min));
    }
};
struct Students
{
    string FirstName;
    string LastName;
    int age;
    Date date;
    int marks[10];
    bool vidminnyk;
    string status = "Vidminnyk";
    double average = 0;
    double SumAverage;
    bool privilegia = true;
    void Fill()
    {
        string sn[5] = { "Bondarenko", "Melnik", "Shevchenko", "Tkachenko", "Kovalenko" };
        string n[5] = { "Olexiy", "Alexandr", "Maxim", "Boris", "Yriy" };
        int a, b;
        a = rand() % 4;
        b = rand() % 4;
        FirstName = n[a];
        LastName = sn[b];
        age = 22 + rand() % 39;
        date.FillRandom(2000, 2004);

        int qwe = rand() % 10;

        privilegia = rand() % 2;
        /* for (int i = 0; i < 10; i++)
         {
             if (marks[i] < 10)
             {
                 privilegia = false;
             }
         }*/
        if (qwe == 0)
        {
            FillRandomTrueMarks();
            vidminnyk = true;
        }
        else
        {
            vidminnyk = false;

            FillRandomMarks();
        }
        for (int i = 0; i < 10; i++)
        {
            average = average + marks[i];
        }
        average = average / 10.0;
    }
    void FillRandomTrueMarks()
    {
        for (int i = 0; i < 10; i++)
        {
            marks[i] = 10 + rand() % (12 - 10);
        }
    }
    void Print()
    {
        cout << "First name\tLast name\tDay.Month.Year\t\n";
        cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
        cout << "Marks: ";
        for (int i = 0; i < 10; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;

    }
    void FillRandomMarks()
    {

        for (int i = 0; i < 10; i++)
        {
            marks[i] = 1 + rand() % 12;
        }
    }

};
struct Teachers
{
    string FirstName;
    string LastName;
    int age;
    Date date;


    void Fill()
    {
        string sn[5] = { "Ivanchuk", "Melnychuk", "Tkach", "Zelenskiy", "Stolyar" };
        string n[5] = { "Dmitro", "Vadim", "Maxim", "Nazar", "Stanislav" };
        int a, b;
        a = rand() % 4;
        b = rand() % 4;
        FirstName = n[a];
        LastName = sn[b];
        age = 22 + rand() % 39;
        date.FillRandom(1965, 1990);
    }
    void Print()
    {
        cout << "First name\tLast name\tDay.Month.Year\t\n";
        cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
        date.Print();
    }
};
struct Group
{
    Teachers teacher;
    Students* students = new Students[5];
    string Name;
    void Fill(string name)
    {
        Name = name;
        teacher.Fill();
        for (int i = 0; i < 5; i++)
        {
            students[i].Fill();
        }
    }
    void Print()
    {
        cout << "----------------------" << Name << "--------------";
        cout << "----------------------------------------------" << endl;
        cout << "Teacher:";

        teacher.Print();

        for (int i = 0; i < 5; i++)
        {
            cout << "------------------------------------" << endl;
            cout << "Student" << endl;
            students[i].Print();
        }
    }
};
void PrintVidminnyk(Group* groups)
{

    for (int i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (groups[i].students[j].vidminnyk)
            {
                groups[i].students[j].status;
                cout << "The best students are:" << endl;
                groups[i].students[j].Print();
            }
        }
    }
}
void PrintTheBestKerivnuk(Group* groups)
{
    float avg1 = 0;
    float avg2 = 0;
    float avg3 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int h = 0; h < 10; h++)
            {
                if (i == 0)
                {
                    avg1 += groups[i].students[j].marks[h];
                }
                if (i == 1)
                {
                    avg2 += groups[i].students[j].marks[h];
                }
                if (i == 2)
                {
                    avg3 += groups[i].students[j].marks[h];
                }
            }

        }
    }

    if (avg1 > avg2 && avg1 > avg3)
    {
        cout << "The best class teacher are:" << endl;
        groups[0].teacher.Print();
    }
    if (avg2 > avg1 && avg2 > avg3)
    {
        cout << "The best class teacher are:" << endl;
        groups[1].teacher.Print();
    }
    if (avg3 > avg1 && avg3 > avg2)
    {
        cout << "The best class teacher are:" << endl;
        groups[2].teacher.Print();
    }
}
void PoorClass(Group* groups, string* names)
{

    float avg1 = 0;
    float avg2 = 0;
    float avg3 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int h = 0; h < 10; h++)
            {
                if (i == 0)
                {
                    avg1 += groups[i].students[j].marks[h];
                }
                if (i == 1)
                {
                    avg2 += groups[i].students[j].marks[h];
                }
                if (i == 2)
                {
                    avg3 += groups[i].students[j].marks[h];
                }
            }

        }
    }

    if (avg1 < avg2 && avg1 < avg3)
    {
        cout << names[0] << endl;
    }
    if (avg2 < avg1 && avg2 < avg3)
    {
        cout << names[1] << endl;
    }
    if (avg3 < avg1 && avg3 < avg2)
    {
        cout << names[2] << endl;
    }
}
void StudentsBornInOneDay(Group* groups)
{
    Students* arr1 = new Students[15];
    for (int i = 0, s = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++, s++)
        {
            arr1[s] = groups[i].students[j];
        }
    }
    /* for (int i = 0; i < 15; i++)
     {
         arr1[i].Print();
         cout << endl;
     }*/
    cout << "Born in one day:" << endl;
    int x = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = i + 1; j < 15; j++)
        {
            if (arr1[i].date.day == arr1[j].date.day && arr1[i].date.month == arr1[j].date.month && arr1[i].date.year == arr1[j].date.year)
            {
                arr1[i].Print();
                cout << endl;
                arr1[i].Print();
                x++;
            }
        }
    }
    if (x == 0)
    {
        cout << "No one born in one day" << endl;
    }
}
void TheOldestStudent(Group* groups)
{
    int year = groups[0].students[0].date.year;
    int month = groups[0].students[0].date.month;
    int day = groups[0].students[0].date.day;
    int res;
    res = day + month * 30 + (2020 - year) * 360;
    int res2;
    int indexi = 0;
    int indexj = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            year = groups[i].students[j].date.year;
            month = groups[i].students[j].date.month;
            day = groups[i].students[j].date.day;
            year = (2020 - year) * 360;
            month = month * 30;
            res2 = day + month + year;
            if (res < res2)
            {
                res = res2;
                indexi = i;
                indexj = j;
            }
        }
    }
    cout << "The oldest student is:" << endl;
    groups[indexi].students[indexj].Print();
}
void CountOfGoodStudent(Group* groups)
{

    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (groups[i].students[j].average > 8.5)
            {
                counter++;
            }
        }
    }
    cout << "Count of good students: " << counter << endl;
}
void Pilga(Group* groups)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (groups[i].students[j].privilegia == true)
            {
                cout << "Students with privelegia: " << endl;
                groups[i].students[j].Print();
            }
        }
    }

}
void Clear()
{
    system("Pause");
    system("CLS");
}
void main()
{
    srand(time(0));
    Group groups[3];
    string names[3] = { "Group 1","Group 2","Group 3" };
    for (int i = 0; i < 3; i++)
    {
        groups[i].Fill(names[i]);
        // groups[i].Print();
    }



    //For Menu


    for (int i = 0; i != 7;)
    {
        string menu[] = { "Print excellent students","Print the best class teacher","Print the poorest class","Print students which born in one day", "Print the oldest student", "Print all good students", "Print students with privilege", "Exit" };
        int m = Menu(menu, size(menu));
        Size_Console(80, 35);
        i == m;

        if (m == 0)
        {
            PrintVidminnyk(groups);
            Clear();
        }
        if (m == 1)
        {
            PrintTheBestKerivnuk(groups);
            Clear();
        }
        if (m == 2)
        {
            PoorClass(groups, names);
            Clear();
        }
        if (m == 3)
        {
            StudentsBornInOneDay(groups);
            Clear();
        }
        if (m == 4)
        {
            TheOldestStudent(groups);
            Clear();
        }
        if (m == 5)
        {
            CountOfGoodStudent(groups);
            Clear();
        }
        if (m == 6)
        {
            Pilga(groups);
            Clear();
        }
        if (m == 7)
            break;
    }
    //PrintVidminnyk(groups);
    //PrintTheBestKerivnuk(groups);
    //PoorClass(groups, names);
    //StudentsBornInOneDay(groups);
    //TheOldestStudent(groups);
    //CountOfGoodStudent(groups);
    //Pilga(groups);



}