#include<iostream>
#include<cmath>
using namespace std;

void print(){
    cout << "-------------------------\n";
    cout << "Welcome to Simple Calculator:\n";
    cout << "Choose one of the following options:\n";
    cout << "1. Add"<<endl;
    cout << "2. Subtract"<<endl;
    cout << "3. Divide"<<endl;
    cout << "4. Multiply"<<endl;
    cout << "5. Modulus"<<endl;
    cout << "6. Power"<<endl;
    cout << "7. Exit"<<endl;
    cout << "Enter your choice: ";
}

double division(double a, double b){
    if (b == 0){
        cout << "Invalid argument for division."<<endl;
        return NAN;
    }
    return a / b;
}

int mod(int a, int b){
    if (b == 0){
        cout << "Invalid argument for modulus.\n";
        return NAN;
    }
    return a % b;
}

int main(){
    int choice;
    double a, b, res;

    while (true){
        print();
        cin >> choice;

        if (choice == 7){
            cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7){
            cerr << "Invalid choice!\n\n";
            continue;
        }

        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;

        switch (choice){
            case 1:
                res = a + b;
                break;
            case 2:
                res = a - b;
                break;
            case 3:
                res = division(a, b);
                break;
            case 4:
                res = a * b;
                break;
            case 5:
                res = mod(static_cast<int>(a), static_cast<int>(b));
                break;
            case 6:
                res = pow(a, b);
                break;
        }

        if (!isnan(res)){
            cout << "Result of operation is: " << res << endl<<endl;
        }
    }

    return 0;
}