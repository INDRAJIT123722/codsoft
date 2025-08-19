#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int main(){
    int random,guess;
    srand(time(0));
    random=(rand()%100)+1;
    int count=0;
    cout<<"Welcome to the  World of Gussing number"<<endl;
    do
    {
       cout<<"Enter your guess between(1 to 100): ";
       cin>>guess;
       count++;
       if (guess<random)
       {
        cout<<"Guess a larger  number"<<endl;
       }
       else if (guess>random)
       {
         cout<<"Guess a smaller number: "<<endl;
       }
       else
       {
        cout<<"congratulation!! You have successfully guessed The number in :"<<count<<" attempts"<<endl;
       }
       
       
    } while (guess!=random);
    cout<<"Thanks for playing: "<<endl;
    cout<<"Developed by Akash munain: "; 
}