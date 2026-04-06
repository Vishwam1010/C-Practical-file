#include<iostream>
using namespace std;

class employee
{
private:
    string empname;
    double basicsalary;
    double bonus;

public:
    employee(string name="unknown", double basic=0.0, double b=5000)
    {
        empname = name;
        basicsalary = basic;
        bonus = b;
    }

    inline double calctotalsalary()
    {
        return basicsalary + bonus;
    }

    void display()
    {
        cout << "---employee details---" << endl;
        cout << "employee name -- " << empname << endl;
        cout << "employee basic salary -- " << basicsalary << endl;
        cout << "employee total salary -- " << calctotalsalary() << endl;
        cout << endl;
    }
};

int main()
{
    int n;
    char choice;

    cout << "enter the total number of employees -- ";
    cin >> n;

    employee* emp = new employee[n];

    string name;
    double basic, bonus;

    for(int i = 0; i < n; i++)
    {
        cout << "--employee details-- " << i+1 << endl;

        cout << "employee name -- ";
        cin >> name;

        cout << "employee basic salary -- ";
        cin >> basic;

        cout << "employee bonus custom (y/n) -- ";
        cin >> choice;

        if(choice == 'Y' || choice == 'y')
        {
            cout << "enter bonus -- ";
            cin >> bonus;
            emp[i] = employee(name, basic, bonus);
        }
        else
        {
            emp[i] = employee(name, basic);
        }
    }

    for(int i = 0; i < n; i++)
    {
        emp[i].display();
    }

    delete[] emp;
    return 0;
}
