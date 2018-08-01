//
//  main.cpp
//  polymorphism
//
//  Created by Katelyn Suhr on 7/20/18.
//  Copyright © 2018 Katelyn Suhr. All rights reserved.
//

#include <iostream>
using namespace std;
//Ninja and Monsters are enemys
//virtual knows that it looks in specific class?

//virutal functions
//each enemy has a specific attack function,
//virtual template functions and any class that inherits
//virtual members is a polymorphic class
//polymorphism can call same function but has different results

class Enemy{
public:
    virtual void attack(){}
};

//class Ninja inherits from Enemy
class Ninja: public Enemy{
public:
    void attack(){
        cout << "Ninja attack!"<< endl;
    }
    
};

class Monster: public Enemy{
public:
    void attack(){
        cout << "Monster attack!"<< endl;
    }
   
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Ninja n;
    Monster m;
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;
    
    enemy1->attack();
    enemy2->attack();
   
    return 0;
}
