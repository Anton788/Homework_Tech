#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Swords
{
  public:
    virtual int UseSword() = 0;
    virtual ~Swords() {}
};

class Armor
{
  public:
    virtual int UseArmor() = 0;
    virtual ~Armor() {}
};

class Boots
{
  public:
    virtual int UseBoots() = 0;
    virtual ~Boots() {}
};


class IronSword: public Swords
{
  public:
    int UseSword() {
      return 40;
    }
};

class IronArmor: public Armor
{
  public:
    int UseArmor() {
      return 80;
    }
};

class IronBoots: public Boots
{
  public:
    int UseBoots() {
      return -30;
    }
};


class WoodSword: public Swords
{
  public:
    int UseSword() {
      return 20;
    }
};

class LeatherArmor: public Armor
{
  public:
    int UseArmor() {
      return 40;
    }
};

class LeatherBoots: public Boots
{
  public:
    int UseBoots() {
      return 30;
    }
};


class Equipment
{
  public:
    virtual Swords* createSword() = 0;
    virtual Armor* createArmor() = 0;
    virtual Boots* createBoots() = 0;
    virtual ~Equipment() {}
};


class IronEquipment: public Equipment
{
  public:
    Swords* createSword() {
      return new IronSword;
    }
    Armor* createArmor() {
      return new IronArmor;
    }
    Boots* createBoots() {
      return new IronBoots;
    }
};


class LeatherEquipment: public Equipment
{
  public:
    Swords* createSword() {
      return new WoodSword;
    }
    Armor* createArmor() {
      return new LeatherArmor;
    }
    Boots* createBoots() {
      return new LeatherBoots;
    }
};


class Person
{
  public:
   ~Person() {
      int i;
      for(i = 0; i < sw.size(); ++i)  delete sw[i];
      for(i = 0; i < ar.size(); ++i)  delete ar[i];
      for(i = 0; i < bo.size(); ++i)  delete bo[i];
    }
    void ShowEquipment() {
      int i;
      int k = 0;
      cout << "Attack: ";
      for(i = 0; i < sw.size(); ++i){
        k += sw[i]->UseSword();
      }
      cout << k << endl;
      k = 0;
      cout << "Defense: ";
      for(i = 0; i < ar.size(); ++i){
        k += ar[i]->UseArmor();
      }
      cout << k << endl;
      k = 0;
      cout << "Skill: ";
      for(i = 0; i < bo.size(); ++i){
        k += bo[i]->UseBoots();
      }
      cout << k << endl;
    }
    vector<Swords*> sw;
    vector<Armor*> ar;
    vector<Boots*> bo;
};


class Human
{
  public:
    Person* createPerson( Equipment& factory ) {
      Person* p = new Person;
      p->sw.push_back( factory.createSword());
      p->ar.push_back( factory.createArmor());
      p->bo.push_back( factory.createBoots());
      return p;
    }
};

int OpeningDoor (Person* fighter, int &tresure, int door1, Equipment* q){
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
                fighter->ShowEquipment();
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
                    sum += fighter->bo[i]->UseBoots();
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
    cin >> n;
    Person* fighter;
    if (n == 1) {
        q = &ir_factory;
        fighter = game.createPerson( ir_factory);
    } else if (n == 2) {
        fighter = game.createPerson( le_factory);
        q = &le_factory;
    }
    cout << "Your Characteristics:" << endl;
    fighter->ShowEquipment();
    int tresure = 1;
    while(true) {
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
    }
}
