#include <iostream>
#include <vector>
#include <ctime>
#include "Equipment.h"
using namespace std;

class Human
{
  public:
    Person* createPerson( Equipment& factory, int health ) {
      Person* p = new Person(health);
      p->sw.push_back( factory.createSword());
      p->ar.push_back( factory.createArmor());
      p->bo.push_back( factory.createBoots());
      return p;
    }
};

/*int OpeningDoor (Person* fighter, int &tresure, int door1, Equipment* q){
        srand(time(0));
        bool dragon = false;
        if (door1 <= tresure){
                cout << "You Win!!!" << endl;
                return 3;
        } else if (tresure < door1 && door1 <= 40) {
                cout << "You find way on next level" << endl;
        } else if (40 < door1 && door1 <= 60) {
                cout << "You find Artefact!!!" << endl;
                int art;
                art = rand() % 3;
                if (art == 0){
                    fighter->sw.push_back((*q).createSword());
                }
                if (art == 1) {
                    fighter->ar.push_back((*q).createArmor());
                }
                if (art == 2) {
                    fighter->bo.push_back((*q).createBoots());
                }
                fighter->ShowEquipment(*fighter);
        } else {
                cout << "You find DRAGON!!!" << endl;
                dragon = true;
        }
        if (dragon) {
            cout << "Choose : 1 - run; 2 - fight" << endl;
            int ch;
            cin >> ch;
            if (ch == 1) {
                int chance;
                int sum = 0;
                for (int i = 0; i < fighter->bo.size(); ++i) {
                    sum += fighter->bo[i]->UseBoots(*fighter);
                }
                chance = rand() % (50) + sum;
                if (chance < 50) {
                    cout << "You are dead" << endl;
                    return 1;
                } else {
                    cout << "You could run" << endl;
                }
            } else {
                int dragon_chance;
                dragon_chance = rand() % 300;
                int sum = 0;
                for (int i = 0; i < fighter->ar.size(); ++i){
                    sum += fighter->ar[i]->UseArmor();
                }
                for (int i = 0; i < fighter->sw.size(); ++i){
                    sum += fighter->sw[i]->UseSword();
                }
                if (dragon_chance > sum) {
                    cout << "You are dead" << endl;
                    return 1;
                } else {
                    cout << "You can survive" << endl;
                }
            }
        }
        tresure += 1;
        return 2;
}*/



int main()
{
    srand(time(0));
    Human game;
    IronEquipment ir_factory;
    LeatherEquipment le_factory;
    Equipment* q;
    int n;
    cout << "Choose person - 1 : IronFighter - 2 : Scout" << endl;
    cin >> n;
    Person* fighter;
    if (n == 1) {
        q = &ir_factory;
        fighter = game.createPerson( ir_factory, 1000);
    } else if (n == 2) {
        fighter = game.createPerson( le_factory, 700);
        q = &le_factory;
    }
    cout << "Your Characteristics:" << endl;
    fighter->ShowEquipment(*fighter);
    cout << fighter->health << endl;
    int tresure = 1;
    fighter->sw.push_back(new Jagged((*q).createSword()));
    fighter->bo.push_back(new Spiny((*q).createBoots()));
    fighter->ShowEquipment(*fighter);
    cout << fighter->health;
    /*while(true) {
        int k;
        int door1 = rand() % 100;
        int door2 = rand() % 100;
        int door3 = rand() % 100;
        cout << "Choose the door: 1 - LeftDoor; 2 - MiddleDoor; 3 - RightDoor" << endl;
        cin >> k;
        int l;
        if (k == 1) {
              l = OpeningDoor(fighter, tresure, door1, q);
              if (l == 1 or l == 3){
                break;
              }
        }
        if (k == 2) {
            l = OpeningDoor(fighter, tresure, door2, q);
            if (l == 1 or l == 3){
                break;
            }
        }
        if (k == 3) {
            l = OpeningDoor(fighter, tresure, door3, q);
            if (l == 1 or l == 3){
                break;
            }
        }
    }*/
}
