// Radhika Agrawal
// HW 5 - CS 210
// Main program to call monster class

#include "Monster.h"
#include <iostream>

using namespace std;

int main(){
    Monster A;
    A.Set_Name("Iron Man");

    if(A.Is_Living()){
        cout << "You are " << A.Get_Name() << ". Your stats currently are: " << endl;
        cout << "Health: " << A.Get_Health() << endl;
        cout << "Power: " << A.Get_Power() << endl;
        cout << "Toughness: " << A.Get_Toughness() << endl;
    }

    Monster B;
    B.Set_Name("Thanos");

    if(B.Is_Living()){
        cout << endl << "Your opponent is " << B.Get_Name() << ". His stats currently are: " << endl;
        cout << "Health: " << B.Get_Health() << endl;
        cout << "Power: " << B.Get_Power() << endl;
        cout << "Toughness: " << B.Get_Toughness() << endl;
    }

    int p_A, t_A;
    cout << endl << "It is time to set your stats. Enter your power and toughness: ";
    cin >> p_A >> t_A;
    A.Set_Power(p_A);
    A.Set_Toughness(t_A);

    int p_B, t_B;
    cout << endl << "It is time to set your opponent's stats. Enter his power and toughness: ";
    cin >> p_B >> t_B;
    B.Set_Power(p_B);
    B.Set_Toughness(t_B);

    A.Fight(B);

    return 0;
}