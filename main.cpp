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

class Comand{
public:
    virtual ~Comand(){};
    virtual int execute(int k) = 0;
protected:
    Comand (Person* man): t_man(man){}
    Person* t_man;
};

class Go_Left_Doors : public Comand{
public:
    Go_Left_Doors(Person* man): Comand(man){}
    int execute(int k){
        return t_man->Go_Left_Door(k);
    }
};

class Go_Right_Doors : public Comand{
public:
    Go_Right_Doors(Person* man): Comand(man){}
    int execute(int k){
        return t_man->Go_Right_Door(k);
    }
};

class Go_Medium_Doors : public Comand {
public:
    Go_Medium_Doors(Person* man): Comand(man){}
    int execute(int k){
        return t_man->Go_Medium_Door(k);
    }
};


class Start{
    Start* next;
public:
    Start(){
        next = 0;
    }
    void Next_it(Start* n){
        next = n;
    }
    void Add_it(Start* n){
        if (next == 0){
            next = n;
        } else {
            next->Add_it(n);
        }
    }
    virtual void Processing(int &sum_attack){
        next->Processing(sum_attack);
    }
};

class Preporation : public Start{
public:
    void Processing(int &sum_attack){
        srand(time(0));
        int a = rand() % 100;
        if (a < 50){
            sum_attack = sum_attack;
        } else {
            sum_attack = 2*sum_attack;
        }
        Start :: Processing(sum_attack);
    }
};

class Run : public Start{
public:
    void Processing(int &sum_attack){
        srand(time(0));
        int a = rand() % 100;
        if (a < 20){
            sum_attack = sum_attack / 3;
        } else if (a < 60){
            sum_attack = sum_attack;
        } else {
            sum_attack = 3 * sum_attack;
        }
        Start :: Processing(sum_attack);
    }
};


class Impact : public Start{
public:
    void Processing(int &sum_attack){
        srand(time(0));
        int a = rand() % 100;
        if (a < 20){
            sum_attack = sum_attack / 2;
        } else if (a < 60){
            sum_attack = sum_attack;
        } else {
            sum_attack = 2 * sum_attack;
        }
    }
};

int OpeningDoor (Person* fighter, int &tresure, int index, Equipment* q, Start* first){
        srand(time(0));
        bool dragon = false;
        if (index == 1){
                cout << "You Win!!!" << endl;
                return 1;
        } else if (index == 4) {
                cout << "You find way on next level" << endl;
        } else if (index == 3) {
                cout << "You find Artefact!!!" << endl;
                int art;
                art = rand() % 3;
                if (art == 0){
                    int decor = rand() % 3;
                    if (decor == 0) {
                        cout << "This is sword" << endl;
                        fighter->sw.push_back((*q).createSword());
                    }
                    if (decor == 1){
                        cout << "This is jagged sword" << endl;
                        fighter->sw.push_back(new Jagged((*q).createSword()));
                    }
                    if (decor == 2){
                        cout << "This is poisonous sword" << endl;
                        fighter->sw.push_back(new Poisonous((*q).createSword()));
                    }
                }
                if (art == 1) {
                    int decor = rand() % 2;
                    if (decor == 0) {
                        cout << "This is armor" << endl;
                        fighter->ar.push_back((*q).createArmor());
                    }
                    if (decor == 1){
                        cout << "This is rough armor" << endl;
                        fighter->ar.push_back(new Rough((*q).createArmor()));
                    }
                }
                if (art == 2) {
                    int decor = rand() % 2;
                    if (decor == 0) {
                        cout << "This is boots" << endl;
                        fighter->bo.push_back((*q).createBoots());
                    }
                    if (decor == 1) {
                        cout << "This is spiny boots" << endl;
                        fighter->bo.push_back(new Spiny((*q).createBoots()));
                    }
                }
                fighter->ShowEquipment(*fighter);
        } else if (index == 5){
                cout << "You find material" << endl;
                int key = rand() % 3;
                if (key == 0){
                    cout << "Obsidian" << endl;
                    fighter->storage->Add_Material(new Obsidian);
                }
                if (key == 1){
                    cout << "Palladium" << endl;
                    fighter->storage->Add_Material(new Paladium);
                }
                if (key == 2){
                    cout << "Gold" << endl;
                    fighter->storage->Add_Material(new Gold);
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
                sum = fighter->skill;
                chance = rand() % (50) + sum;
                if (chance < 50) {
                    cout << "You are dead" << endl;
                    return 1;
                } else {
                    cout << "You could run" << endl;
                }
            } else if (ch == 2){
                int dragon_chance;
                dragon_chance = rand() % 300;
                int sum1 = 0;
                int sum2 = 0;
                sum1 = fighter->defen;
                sum2 = fighter->power;
                first->Processing(sum2);
                if (dragon_chance > sum1 + sum2) {
                    cout << "You are dead" << endl;
                    return 1;
                } else {
                    cout << "You can survive" << endl;
                }
            } else {
                cout << "Wrong answer" << endl;
                return OpeningDoor(fighter, tresure, index, q, first);
            }
        }
        tresure += 1;
        return 2;
}

int main()
{
    srand(time(0));
    Human game;
    IronEquipment ir_factory;
    LeatherEquipment le_factory;
    Equipment* q;
    int n;
    cout << "Choose person - 1 : IronFighter - 2 : Scout" << endl;
    Person* fighter;
    while (true) {
        cin >> n;
        if (n == 1) {
            q = &ir_factory;
            fighter = game.createPerson( ir_factory, 1000);
            break;
        } else if (n == 2) {
            fighter = game.createPerson( le_factory, 700);
            q = &le_factory;
            break;
        } else {
            cout << "Wrong answer. Try again." << endl;
        }
    }
    cout << "Your Characteristics:" << endl;
    fighter->ShowEquipment(*fighter);
    int tresure = 1;
    vector<Comand*> steps;
    Preporation first;
    Run second;
    Impact third;
    first.Add_it(&second);
    first.Add_it(&third);
    while(true) {
        if (fighter->health <= 0){
            cout << "You died"<< endl;
            break;
        }
        int k;
        int situation;
        int door1 = rand() % 100;
        int door2 = rand() % 100;
        int door3 = rand() % 100;
        cout << "Choose the door: 1 - LeftDoor; 2 - MiddleDoor; 3 - RightDoor" << endl;
        cin >> k;
        if (k == 1) {
            Go_Left_Doors* step = new Go_Left_Doors(fighter);
            situation = step->execute(tresure);
            int res = OpeningDoor(fighter, tresure, situation, q, &first);
            if (res == 1){
                break;
            }
            steps.push_back(step);
        }

        if (k == 2) {
            Go_Medium_Doors* step = new Go_Medium_Doors(fighter);
            situation = step->execute(tresure);
            int res = OpeningDoor(fighter, tresure, situation, q, &first);
            if (res == 1){
                break;
            }
            steps.push_back(step);
        }

        if (k == 3) {
            Go_Right_Doors* step = new Go_Right_Doors(fighter);
            situation = step->execute(tresure);
            int res = OpeningDoor(fighter, tresure, situation, q, &first);
            if (res == 1){
                break;
            }
            steps.push_back(step);
        }
        ++tresure;
    }
    for (int i = 0; i < steps.size(); ++i){
        delete steps[i];
    }
    system("pause");
    return 0;
}
