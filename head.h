#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//John Bedette, cs162
//working with structs to make an activity storage thing



const int TYPE = 20;
const int SEASON = 7;
const int LARGE = 281;

struct act{
    char type[TYPE];
    char season[SEASON];
    char toBring[LARGE];
    char desc[LARGE]; 
};

//prototypes
int menu(int &, act []);
void actAdd(act &, int);
void actSearch(int, act []);
void actDisplay(act);
void read(int, char result[]);
bool comparer(char [], char[]);
void menuText();
void displayType(int, act []);
