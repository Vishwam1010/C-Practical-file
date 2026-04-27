#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Currency {
public:
    string code, name;
    double rate;

    Currency() {}
    Currency(string c, string n, double r) {
        code = c;
        name = n;
        rate = r;
    }
};

class Bank {
public:
    Currency list[8] = {
        {"USD", "US Dollar",         1.0000},
        {"EUR", "Euro",              0.9200},
        {"GBP", "British Pound",     0.7900},
        {"INR", "Indian Rupee",     83.5000},
        {"JPY", "Japanese Yen",    149.5000},
        {"CAD", "Canadian Dollar",   1.3600},
        {"AUD", "Australian Dollar", 1.5300},
        {"AED", "UAE Dirham",        3.6700}
    };
    int total = 8;

    
    int find(string code) {
        for (int i = 0; i < total; i++)
            if (list[i].code == code) return i;
        return -1;
    }

    
    void showAll() {
        cout << "--------------------------------------\n";
        cout << left << setw(6) << "CODE" << setw(20) << "NAME" << "RATE\n";
        cout << "--------------------------------------\n";
        for (int i = 0; i < total; i++)
            cout << left << setw(6)  << list[i].code
                         << setw(20) << list[i].name
                 << fixed << setprecision(4) << list[i].rate << "\n";
        cout << "--------------------------------------\n";
    }
};


class App {
    Bank bank;

    void line() { cout << "--------------------------------------\n"; }

    void toUpper(string &s) {
        for (char &c : s) c = toupper(c);
    }

    double convert(double amount, double from, double to) {
        return (amount / from) * to;
    }

   
    void convertTwo() {
        string from, to;
        double amount;

        cout << " From : "; cin >> from; toUpper(from);
        cout << " To   : "; cin >> to;   toUpper(to);

        int i = bank.find(from);
        int j = bank.find(to);

        if (i == -1 || j == -1) {
            cout << " [!] Invalid code!\n"; return;
        }

        cout << " Amount : "; cin >> amount;

        double result = convert(amount, bank.list[i].rate, bank.list[j].rate);

        line();
        cout << fixed << setprecision(4);
        cout << " " << amount << " " << from << " = " << result << " " << to << "\n";
        cout << " 1 " << from << " = " << convert(1, bank.list[i].rate, bank.list[j].rate) << " " << to << "\n";
        line();
    }

    
    void convertAll() {
        string from;
        double amount;

        cout << " From   : "; cin >> from; toUpper(from);
        int i = bank.find(from);

        if (i == -1) { cout << " [!] Invalid code!\n"; return; }

        cout << " Amount : "; cin >> amount;

        line();
        for (int j = 0; j < bank.total; j++) {
            if (j == i) continue;
            cout << " " << left << setw(5) << bank.list[j].code
                 << fixed << setprecision(4)
                 << convert(amount, bank.list[i].rate, bank.list[j].rate) << "\n";
        }
        line();
    }

    
    void updateRate() {
        string code; double newRate;

        cout << " Currency code : "; cin >> code; toUpper(code);
        int i = bank.find(code);

        if (i == -1)       { cout << " [!] Not found!\n";             return; }
        if (code == "USD") { cout << " [!] Cannot change USD!\n";     return; }

        cout << " Current : 1 USD = " << bank.list[i].rate << " " << code << "\n";
        cout << " New rate : "; cin >> newRate;

        if (newRate <= 0)  { cout << " [!] Must be positive!\n";      return; }

        bank.list[i].rate = newRate;
        cout << " [✓] Updated!\n";
    }

public:
    void run() {
        int choice;
        cout << "======================================\n";
        cout << "   CURRENCY EXCHANGE RATE SIMULATOR\n";
        cout << "======================================\n";

        while (true) {
            cout << "\n [1] View All Rates\n";
            cout << " [2] Convert Currency\n";
            cout << " [3] Convert to All\n";
            cout << " [4] Update a Rate\n";
            cout << " [0] Exit\n";
            cout << " Choice : "; cin >> choice; cout << "\n";

            if      (choice == 1) bank.showAll();
            else if (choice == 2) convertTwo();
            else if (choice == 3) convertAll();
            else if (choice == 4) updateRate();
            else if (choice == 0) { cout << " Goodbye!\n"; return; }
            else                    cout << " [!] Invalid choice!\n";
        }
    }
};

int main() {
    App app;
    app.run();
    return 0;
}