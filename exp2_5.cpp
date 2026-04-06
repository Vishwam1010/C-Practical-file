#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class LoanAccount 
{
private:
int loanId;
string applicantname;
double loanamount;
double interestrate;
int tenuremonths;

public:
LoanAccount()
{
    loanId=0;
    applicantname="test applicant";
    loanamount=0;
    interestrate=0.0;
    tenuremonths=0;
}
LoanAccount(int id,string name,double p,double rate,int m)
{
    loanId=id;
    applicantname=name;
    loanamount=p;
    interestrate=rate;
    tenuremonths=m;
}
double calculateEmi()
{
    double R=interestrate/(12*100);
    int T=tenuremonths;

    double emi=(loanamount * R * pow(1+R,T))/(pow(1+R,T)-1);
    return emi;
}
void display()
{
    cout << "loan account details"<<endl;
    cout<< "loan ID"<<loanId<<endl;
    cout<< "applicant name--"<<applicantname<<endl;
    cout<< "loan amount--"<<loanamount<<endl;
    cout<< "interest rate--"<<interestrate<<endl;
    cout<< "number of months--"<<tenuremonths<<endl;
    cout<< "monthly EMI--"<< calculateEmi() << endl;
}
};
int main()
{
    LoanAccount L1;
    int Id;
    string holder;
    double amt;
    double r;
    int month;
    cout<< "enter the details"<<endl;
    cout<< "enter the loanid--"<<endl;
    cin>>Id;
    cout<< "enter the applicant name--"<<endl;
    cin.ignore();
    cout<< "applicant name"<<endl;
    getline(cin,holder);
    cout<< "enter the principal amt--"<<endl;
    cin>>amt;
    cout<< "enter the interest rate--"<<endl;
    cin>>r;
    cout<< "enter the number of months--"<<endl;
    cin>>month;
    
    L1=LoanAccount(Id,holder,amt,r,month);
    L1.display();
    return 0;
    
}
