#include <iostream>
#include <stack>
#include <cmath>
#include<sstream>
using namespace std;
const double Pi=acos(-1);

double Sin(double x) 
{ 
    return (round(sin(x) * 10000000) / 10000000);
}
double aSin(double x)
{
    return(round(asin(x) * 10000000) / 10000000);
}

double Cos(double x)
{ 
    return (round(cos(x) * 10000000) / 10000000);
}
double aCos(double x)
{
    return(round(acos(x) * 10000000) / 10000000);
}

double Ctg(double x)
{ 
    double vala = Cos(x);
    double valb = Sin(x);
    return (vala / valb);
}
double aCtg(double x)
{
    double vala = aCos(x);
    double valb = aSin(x);
    return (vala / valb);
}
struct opernumb
{
    char type;
    double value;
};

bool calculate(opernumb& number, stack <opernumb>& stack_numbers, stack <opernumb>& stack_operators)
{
    double vala, valb, valc;
    vala = stack_numbers.top().value;
    stack_numbers.pop();


    switch (stack_operators.top().type)
    {
    case '+':
        valb = stack_numbers.top().value;
        stack_numbers.pop();
        valc = vala + valb;
        number.type = '0';
        number.value = valc;
        stack_numbers.push(number);
        stack_operators.pop();
        break;
    case '-':
        valb = stack_numbers.top().value;
        
        stack_numbers.pop();
        valc = valb - vala;
        number.type = '0';
        number.value = valc;
        stack_numbers.push(number);
        stack_operators.pop();
        break;
    case '*':
        valb = stack_numbers.top().value;
        stack_numbers.pop();
        valc = vala * valb;
        number.type = '0';
        number.value = valc;
        stack_numbers.push(number);
        stack_operators.pop();
        break;
    case '/':
        valb = stack_numbers.top().value;
        if (vala == 0)
        {
            cerr << "нельзя педик так" << endl;
            return false;
            break;
        }
        stack_numbers.pop();
        valc = (valb / vala);
        number.type = '0';
        number.value = valc;
        stack_numbers.push(number);
        stack_operators.pop();
        break;
        case '^':
            valb = stack_numbers.top().value;
            stack_numbers.pop();
            valc=pow(valb, vala);
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 's':
            valc = Sin(vala);
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 'c':
            valc = Cos(vala);
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 't':
            if (Cos(vala) == 0)
            {
                cout << "error" << endl;
                return false;
            }
            valc = tan(vala);
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 'g':
            if (Sin(vala) == 0)
            {
                cout << "error" << endl;
                return false;
            }
            else 
            {
                valc = Ctg(vala);
                number.type = '0';
                number.value = valc;
                stack_numbers.push(number);
                stack_operators.pop();
                break;
            }
        case 'q':
            valc = aCos(vala);
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 'w':
            valc = aSin(vala);
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 'r':
            valc = atan(vala);
            if (aCos(vala) == 0)
            {
                cout << "error" << endl;
                return false;
            }
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;
        case 'd':
            valc = aCtg(vala);
            if (aSin(vala) == 0)
            {
                cout << "error" << endl;
                return false;
            }
            number.type = '0';
            number.value = valc;
            stack_numbers.push(number);
            stack_operators.pop();
            break;

    default:
        cerr << "нельзя педик так" << endl;
        return false;
        break;
    }
    return true;
}

int priority(char Char)
{
    if (Char == '^')
    {
        return 3;
    }
    if (Char =='*' || Char == '/')
    {
        return 2;
    }
    if (Char == '+' || Char == '-')
    {
        return 1;
    }
    if (Char == 's' || Char == 'c' || Char == 't' || Char == 'g' || Char == 'q' || Char == 'w' || Char == 'r' || Char == 'd')
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    while (true)
    {
        char Char;
        double value;
        string str;
        bool point = true;
       stack <opernumb> stack_numbers;
        stack <opernumb> stack_operators;
        opernumb number;
        getline(cin, str);
        stringstream sstr{ str };
        while (true)
        {
            Char = sstr.peek();
            if (Char == '\377')
            {
                break;
            }
           /* if (Char == ' ');
            {
                sstr.ignore();
                continue;
            }*/
            if (Char == 'p')
            {
                number.type = '0';
                number.value = Pi;
                stack_numbers.push(number);
                sstr.ignore();
                continue;
            }

            if (Char >= '0' && Char <= '9' || Char == '-' && point == 1)
            {
                sstr >> value;
                number.type = '0';
                number.value = value;
                stack_numbers.push(number);
                point = 0;
                continue;
            }

             if (Char == 's' || Char == 'c' || Char == 't' || Char == 'e')
             {
                 char trygonometry[3];
                 for (int i = 0; i < 3; i++)
                 {
                     Char = sstr.peek();
                     trygonometry[i] = Char;
                     sstr.ignore();
                 }
                 if (trygonometry[0]=='c'&& trygonometry[1] == 'o' && trygonometry[2] == 's' )
                 {
                     number.type = 'c';
                     number.value = 0;
                     stack_operators.push(number);
                     
                     continue;
                 }
                 if (trygonometry[0] == 's' && trygonometry[1] == 'i' && trygonometry[2] == 'n'  )
                 {
                     number.type = 's';
                     number.value = 0;
                     stack_operators.push(number);
                     
                     continue;
                 }
                 if (trygonometry[0] == 't' && trygonometry[1] == 'a' && trygonometry[2] == 'n')
                 {
                     number.type = 't';
                     number.value = 0;
                     stack_operators.push(number);
            
                     continue;
                 }
                 if (trygonometry[0] == 'c' && trygonometry[1] == 'a' && trygonometry[2] == 't')
                 {
                     number.type = 'g';
                     number.value = 0;
                     stack_operators.push(number);
                     
                     continue;
                 }
                 if (trygonometry[0] == 'e' && trygonometry[1] == 'x' && trygonometry[2] == 'p')
                 {
                     number.type = 'e';
                     number.value = 0;
                     stack_operators.push(number);
                    
                     continue;
                 }
                 
             }
             else if (Char == 'a')
             {
                 char revtryg[4];
                 for (int i = 0; i < 4; i++)
                 {
                     Char = sstr.peek();
                     revtryg[i] = Char;
                     sstr.ignore();
                 }
                 if (revtryg[0] == 'a' && revtryg[1] == 'c' && revtryg[2] == 'o' && revtryg[3] == 's')
                 {
                     number.type = 'q';
                     number.value = 0;
                     stack_operators.push(number);
                     continue;
                 }
                 if (revtryg[0] == 'a' && revtryg[1] == 's' && revtryg[2] == 'i' && revtryg[3] == 'n')
                 {
                     number.type = 'w';
                     number.value = 0;
                     stack_operators.push(number);
                     continue;
                 }
                 if (revtryg[0] == 'a' && revtryg[1] == 't' && revtryg[2] == 'a' && revtryg[3] == 'n')
                 {
                     number.type = 'r';
                     number.value = 0;
                     stack_operators.push(number);
                     continue;
                 }
                 if (revtryg[0] == 'a' && revtryg[1] == 'c' && revtryg[2] == 'a' && revtryg[3] == 't')
                 {
                     number.type = 'd';
                     number.value = 0;
                     stack_operators.push(number);
                     continue;
                 }
             }
            if (Char == '+' || Char == '-' && point == 0 || Char == '*' || Char == '/' || Char == '^')
            {
                if (stack_operators.size() == 0)
                {
                    number.type = Char;
                    number.value = 0;
                    stack_operators.push(number);
                    sstr.ignore();
                    continue;
                }
                if (stack_operators.size() != 0 && priority(Char) > priority(stack_operators.top().type))
                {
                    number.type = Char;
                    number.value = 0;
                    stack_operators.push(number);
                    sstr.ignore();
                    continue;
                }
                if (stack_operators.size() != 0 && priority(Char) <= priority(stack_operators.top().type))
                {
                    if (calculate(number, stack_numbers, stack_operators) == false)
                    {
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (Char == '(')
            {
                number.type = Char;
                number.value = 0;
                stack_operators.push(number);
                sstr.ignore();
                continue;
            }
            if (Char == ')')
            {
                while (stack_operators.top().type != '(')
                {
                    if (calculate(number, stack_numbers, stack_operators) == false)
                    {
                        system("pause");
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                    
                }
                stack_operators.pop();
                sstr.ignore();
                continue;
            }
            else
            {
                cout << "ошибка ввода! Повторите попытку" << endl;
                system("pause");
                return 0;
            }
        }
        while (stack_operators.size() != 0)
        {
            if (calculate(number, stack_numbers, stack_operators) == false)
            {
                system("pause");
                return 0;
            }
            else continue;
        }
        cout << "result: " << stack_numbers.top().value << endl;
        system("pause");
    }
    return 0;
}