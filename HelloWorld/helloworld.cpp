#include <iostream>
#include <thread>
#include "helloworld.h"

// Static Outside of a Class 
static int s_needForSpeed = 5;

// Function
int multiply(int a, int b) {
    return a*b;
}

// Interface 
class Printable {
    public:
    virtual int getId() = 0;
};

class Table : public Printable {
    public:
        int id;
        int getId() override {
            return id;
        }
};

// Player Class
class Player {
    public:
        // Static member variable
        static int z;

        // Nonstatic member variable
        int x,y;
        int speed;

        // Default constructor
        Player() {
            std::cout << "Default Constructor" << std::endl;
            x = 0;
            y = 0;
        }

        // Parameterized constructor
        Player(int x, int y) {
            std::cout << "Parameterized Constructor" << std::endl;
            x = x;
            y = y;
        }

        // Destructor 
        ~Player() {
            std::cout << "Object Has Been Deleted" << std::endl;
        }

        // Virtual Function
        virtual int move(int deltax, int deltay) {
            x = x + deltax * speed;
            y = y + deltay * speed;
            return x;
        }
    
    private:
        // Private member variable 
        int ID;

        // Private method
        int setID(int newID) {
            ID = newID;
        }
};

// Inheritance 
class MarioPlayer : public Player {
    public:
        char* name;
    
    // Overriden function
    int move(int deltax, int deltay) override {
        x = x + deltax * 0.5*speed;
        y = y + deltay * 0.5*speed;
        return x;
    }

};

// Defining static variable out of our class scope
int Player::z = 0;

// Struct
struct Vec2 {
    float x1, x2;
};

int main()
{
    // Variable Declaration
    unsigned int var = 6; 
    // Pointer
    unsigned int* var2; 
    // Reference
    unsigned int& var3 = var;

    // Conditionals and Branching Statements
    if (var < 6) {
        std::cout << "var is less than 6" << std::endl;
    }
    else if (var < 10) {
        std::cout << "var is less than 10" << std::endl;
    }
    else {
        std::cout << "var is greater than 6" << std::endl;
    }

    // Loops
    // For Loop
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        else if (i == 8) {
            break;
        }
        std::cout << i << std::endl;
    }

    // While Loop
    int j = 5;
    while (j < 5) {
        j = j-1;
    } 

    // Instantiating the objects player1 and player2 with data type Player 
    Player player1;
    Player player2;
    Player player3(4,5);
    player3.move(2,5);

    std::cout << player1.z << std::endl;
    std::cout << player3.z << std::endl;

    // Updating the static variable z
    player1.z = 4;
    player2.z = 2;
    Player::z = 8;

    // Allocate memory on the stack
    int x = 5;
    int array[5];

    // Allocate memory on the heap
    int* xp = new int;
    *xp = 5;
    int* harray = new int[5];

    delete xp;
    delete harray;

    // Starts the worker thread
    std::thread worker(multiply(4,5));

    // Similar to waiting in modern day languages
    worker.join();

}