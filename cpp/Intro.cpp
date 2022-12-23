#include<iostream>
#include<string.h>
using namespace std;

class Hero{

    int health;
    char level;
    char* name;

    
    public:
        //Simple Constructor
        //Remember to make Default Constructor else there will be no non-parameterised Constructor
        Hero(){
            cout << "Simple Constructor called with Default Values" << endl;
            name = new char[100];
            health = 100;
            level = 'C';
        }

        //Parameterised Constructor
        Hero(int health, char level){
            cout << "Costructor called with Parameters Passed" << endl;
            this->health = health;
            this->level = level;
        }

        //Copy Constructor
        Hero(Hero& temp){
            cout << "Copy Constructor Called" << endl;
            
            //Deep Copy
            char *ch= new char[strlen(temp.name)+1];
            strcpy(ch, temp.name);
            this->name = ch;

            this->health = temp.health;
            this->level = temp.level;
        }

        void setHealth(int health) {
            this->health = health;
        }
        void setLevel(char level) {
            this->level = level;
        }
        void setName(char name[]) {
            strcpy(this->name, name);
        }

        int getHealth() {
            return health;
        }
        char getLevel() {
            return level;
        }

        void print() {

            cout << "[ Name is:" << name << ", ";
            cout << "Health is:" << health << ", ";
            cout << "Level is:" << level << " ]" << endl;
        }

        //Destructor
        ~Hero() {
            cout << "Destructor Called";
        }

    
};

int main(){

    //Static Allocation
    // Hero h1(70, 'A');
    // h1.print();

    // Dynamic Allocation 
    // Hero *h2 = new Hero();
    // h2->print();

    //Copy Class
    // Hero h3(h1);
    // h3.print();

    Hero h1;
    char name[6] = "Riken";
    h1.setName(name);
    h1.print();

    //Use of default copy constructor -> Shallow Copy
    //Use of Self made Copy constructor -> Deep Copy
    // Hero h2(h1);
    // h2.print();

    // h1.name[0] = 'H';

    // h1.print();
    // h2.print();





    return 0;
}
