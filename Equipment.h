#include <iostream>
#include <vector>
#include <ctime>
#include <assert.h>

using namespace std;

class Person;

class Swords
{
  public:
    virtual void UseSword(Person&) = 0;
    virtual ~Swords() {}
};

class Armor
{
  public:
    virtual void UseArmor(Person&) = 0;
    virtual ~Armor() {}
};

class Decorate_Armor:public Armor
{
    Armor* modern_ar;
    public:
        Decorate_Armor(Armor* ar){
            modern_ar = ar;
        }
        void UseArmor(Person& p);
};
class Rough : public Decorate_Armor
{
public:
    Rough(Armor* ar):Decorate_Armor(ar){}
    void UseArmor(Person &p);
};

class Boots
{
  public:
    virtual void UseBoots(Person&) = 0;
    virtual ~Boots() {}
};

class Decorate_Boots:public Boots
{
    Boots* modern_bo;
    public:
        Decorate_Boots(Boots* bo){
            modern_bo = bo;
        }
        void UseBoots(Person& p);
};

class Spiny : public Decorate_Boots
{
public:
    Spiny(Boots* bo):Decorate_Boots(bo){}
    void UseBoots(Person &p);
};

class Material
{
    public:
    virtual int Power_of_material() = 0;
    virtual void Add_Material(Material* p) {
      assert(false);
    }
    virtual ~Material(){}
};

class Obsidian : public Material
{
    public:
    virtual int Power_of_material(){
        static unsigned int k = 10;
        return k;
    }
};

class Paladium : public Material
{
    public:
    virtual int Power_of_material(){
        static unsigned int k = 20;
        return k;
    }
};

class Gold : public Material
{
    public:
    virtual int Power_of_material(){
        static unsigned int k = 30;
        return k;
    }
};

class Composite_of_Material: public Material
{
    public:
    vector<Material*> store;
    void Add_Material(Material* m);
    int Power_of_material();
    ~Composite_of_Material(){
        for (int i = 0; i < store.size(); ++i){
            delete store[i];
        }
    }
};


class Person
{
  public:
    Person(int max_h){
        health = max_h;
        storage = new Composite_of_Material;
    }
    int health;
    int power;
    int defen;
    int skill;
    Composite_of_Material* storage;
    void Create_Rune();
   ~Person() {
      int i;
      for(i = 0; i < sw.size(); ++i)  delete sw[i];
      for(i = 0; i < ar.size(); ++i)  delete ar[i];
      for(i = 0; i < bo.size(); ++i)  delete bo[i];
    }
    void ShowEquipment(Person& p);
    int Go_Left_Door(int k){
        srand(time(0));
        cout << "You go into left door" << endl;
        int a = rand() % 100;
        if (a <= k){
            cout << "You find tresure" << endl;
            return 1;
        } else if (a < k + 40) {
            cout << "You find dragon" << endl;
            return 2;
        } else if (a < k + 70) {
            return 3;
        } else{
            return 4;
        }
    }
    int Go_Right_Door(int k){
        cout << "You go into right door" << endl;
        int a = rand() % 100;
        if (a <= k){
            cout << "You find tresure" << endl;
            return 1;
        } else if (a < k + 40) {
            cout << "You find dragon" << endl;
            return 2;
        } else if (a < k + 70) {
            return 3;
        } else{
            return 4;
        }
    }
    int Go_Medium_Door(int k){
        cout << "You go into medium door" << endl;
        int a = rand() % 100;
        if (a <= k){
            cout << "You find tresure" << endl;
            return 1;
        } else if (a < k + 40) {
            cout << "You find dragon" << endl;
            return 2;
        } else if (a < k + 70) {
            return 3;
        } else{
            return 4;
        }
    }
    vector<Swords*> sw;
    vector<Armor*> ar;
    vector<Boots*> bo;
};

class Decorate_Sword: public Swords
{
    Swords* modern_sw;
    public:
        Decorate_Sword(Swords* sw){
            modern_sw = sw;
        }
        void UseSword(Person& p);
};

class Jagged : public Decorate_Sword
{
public:
    Jagged(Swords* sw):Decorate_Sword(sw){}
    void UseSword(Person &p);
};

class Poisonous : public Decorate_Sword
{
public:
    Poisonous(Swords* sw): Decorate_Sword(sw){}
    void UseSword(Person &p);
};

class Equipment
{
  public:
    virtual Swords* createSword() = 0;
    virtual Armor* createArmor() = 0;
    virtual Boots* createBoots() = 0;
    virtual ~Equipment() {}
};

class IronSword: public Swords {
public:
    void UseSword(Person& p);
};

class IronArmor: public Armor {
  public:
    void UseArmor(Person& p);
};

class IronBoots: public Boots {
  public:
    void UseBoots(Person& p);
};

class IronEquipment: public Equipment {
  public:
    Swords* createSword();
    Armor* createArmor();
    Boots* createBoots();
};

class WoodSword: public Swords
{
  public:
    void UseSword(Person& p);
};

class LeatherArmor: public Armor
{
  public:
    void UseArmor(Person& p);
};

class LeatherBoots: public Boots
{
  public:
    void UseBoots(Person& p);
};

class LeatherEquipment: public Equipment {
  public:
    Swords* createSword();
    Armor* createArmor();
    Boots* createBoots();
};
