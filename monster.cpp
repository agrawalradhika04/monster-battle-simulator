// Radhika Agrawal
// HW 5 - CS 210
// Implementation of Monster class

#include "Monster.h"
#include <iostream>

using namespace std;

// Constructor - Set health to 100, power and toughness to 1, and make the monster alive
Monster::Monster(string name){
    my_health = 100;
    my_power = 1;
    my_toughness = 1;
    am_alive = true;

}

// Accessor functions for the monster's name, health, power, toughness, and if it is alive or dead
string Monster::Get_Name(){
    return my_name;
}

int Monster::Get_Health(){
    return my_health;
}

int Monster::Get_Power(){
    return my_power;
}

int Monster::Get_Toughness(){
    return my_toughness;
}

bool Monster::Is_Living(){
    return am_alive; // Alive if am_alive returns true, dead otherwise
}

void Monster::Display(){
    if(am_alive){
        cout << my_name << " is coming to eat your babies!!!" << endl;
        cout << "Here are his stats: " << endl;
        cout << "Health: " << my_health << endl;
        cout << "Power: " << my_power << endl;
        cout << "Toughness: " << my_toughness << endl;
        cout << "BEWARE! He is alive and hungry..." << endl;
    }
    else{
        cout << my_name << " is dead. " << endl;
    }
}

// Mutator functions for monster's name, health, power, and toughness
void Monster::Set_Name(string new_name){
    my_name = new_name;
}

void Monster::Set_Health(int h){
   if(h <= 0){
        my_health = 0;
   }
   else{
        my_health = h;
   }
}

void Monster::Set_Power(int p){
    if(p <= 0){
        my_power = 1;
    }
    else{
        my_power = p;
    }
}

void Monster::Set_Toughness(int t){
    if(t <= 0){
        my_toughness = 1;
    }
    else{
        my_toughness = t;
    }
}

void Monster::Set_If_Alive(){
    if(my_health == 0){
        am_alive = false;
    }
    else{
        am_alive = true;
    }
}

void Monster::Heal(int amount){
    if(amount >= 0){ // Function cannot have negative parameter values
        int new_health = my_health + amount;
        Set_Health(new_health);
        if(new_health > 100){ // Health cannot over 100
            Set_Health(100);
        }
        Set_If_Alive(); // Update life status of the monster depending on its health now
        cout << "alive" << Is_Living();
    }
}

void Monster::Fight(Monster& other){
    bool play = true;

    while(play){
        if(am_alive && other.Is_Living()){
            int damage_AB = my_power - other.Get_Toughness();
            int newhealth_other = other.Get_Health() - damage_AB;

            int damage_BA = other.Get_Power() - my_toughness;
            int newhealth_MonsterA = my_health - damage_BA;

            if(newhealth_other <= 0){
                other.Set_Health(0);
                other.Set_If_Alive();
            }
            else{
                other.Set_Health(newhealth_other);
            }

            if(newhealth_MonsterA <= 0){
                Set_Health(0);
                Set_If_Alive();
            }
            else{
                Set_Health(newhealth_MonsterA);
            }

            Display();
            cout << endl;
            other.Display();
            cout << endl;
        }
        else{
            cout << "One or more player is dead. Not enough players to play right now. Do you want to buy some health for your dead player? Enter 1 for yes and 0 for no. ";
            bool buy_health;
            cin >> buy_health;

            if(buy_health){
                cout << "Enter an amount: ";
                int amount;
                cin >> amount;

                if(!Is_Living()){
                    Heal(amount);
                }
                else{
                    other.Heal(amount);
                }
            }
        }

        cout << "Go again? Enter 1 for yes and 0 for no. ";
        cin >> play;
    }
}

