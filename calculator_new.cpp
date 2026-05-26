#include <iostream>
#include  <string>
#include <limits>
#include <cmath>

using namespace std;

class Simple_calculator
{

    public:

    double cal(double x,char opr,double y ,bool& haserr,string errmsg)
    {
        haserr = false;
        errmsg = " ";
        switch(opr)
        {
            case '+' : return x+y;

            case '-' : return x-y;

            case '*'  : return x*y;

            case '/':
            if(y == 0)
            {
                haserr = true;
                errmsg = "Division by zero is mathematically undefined";
                return 0;
            }
            return x/y;
            case '%':
                if ((int)y == 0) {
                    haserr = true;
                    errmsg = "Modulo by zero is undefined.";
                    return 0;
                }
                return (int)x % (int)y;

            case '^':
                return pow(x, y);

               
            default:
            haserr = true;

            errmsg = "unknow or unsupported operation";
            return 0;
        }
    }

};

double do_calculation(const string& input)

{
    double num;
    while(true){
    cout<<input;

    if(cin>>num)
    {
        return num;
    }
    else{
        cout<< "INVALID INPUT , Please Enter valid Number(Decimal Number Allowed).\n";
        cin.ignore();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    }
}

char math_operations()
{
 char op;
 cout<<"Enter an operator (+.-,*,/,%,^,s)";
 cin>>op;
  if (op == '+' || op == '-' || op == '*' || op == '/' ||
            op == '%' || op == '^')
             {
            return op;
        }
   else
 {
    cout<<"invalid operator ! please provide correct operator.\n";
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

}

}

int main()

{

    Simple_calculator cal;

    char choice;
    cout << "=====================================================\n";
    cout << "              SIMPLE CALCULATOR                         \n";
    cout << "=====================================================\n";
    do
    { 
    double num1 = do_calculation("Enter the first number : ");
    char op = math_operations();
    double num2 = do_calculation("Enter the second number : ");

    bool haserror = false;

    string errormsg = " ";

    double result = cal.cal(num1,op,num2,haserror,errormsg);

    if(haserror)
    {
        cout<<" "<<"ERROR:"<<errormsg<<"\n";
    }
    else
    {
        cout<<"RESULT: "<<" "<<num1<<" "<<op<<" "<<num2<<" = "<< result <<"\n";
    }
    cout << "----------------------------------------------------\n";
    cout<<"do you want choose perform again the calaculation (y/n): ";
    cin>>choice;
    cout<<"\n";


}
while(choice == 'y' || choice == 'Y');

cout << "Thank you for using the calculator. Goodbye!\n";
return 0;
}