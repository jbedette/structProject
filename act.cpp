#include "head.h"
        
//John Bedette, cs162
//working with structs to make an activity storage thing

int menu(int &  i, act arr[]){
    char option = ' ';
    menuText();//display menu text 
    cin >> option;
    cin.clear();//get rid of nasty error inputs
    cin.ignore(100,'\n');
    option = tolower(option);                                                  
    
    if(option == 'a'){
        actAdd(arr[i],i);            
        ++i;
        option = ' ';
        menu(i, arr);
    }else if(option == 's'){                                               
        actSearch(i,arr);                                                  
        option = ' ';
        menu(i, arr);
    }else if(option == 'd'){                                                
        for(int all = 0; all < i; ++all){ 
            actDisplay(arr[all]);  
        } 
        option = ' ';
        menu(i, arr);
    }else if(option == 'q'){
        cout << ">> Goodbye"<< "\n\n";
        return 0;
    }else{
        cout << ">> Please Select an option" << "\n\n";
        option = ' ';
        menu(i,arr);
    } 
}

void actAdd(act & anAct,int i){
    if(i <= 20){
        cout << ">> What kind of activity is it?" << "\n\n";
        read(TYPE,anAct.type);
        cout << ">> Where is it? What is it like?" << "\n\n";
        read(LARGE, anAct.desc);
        cout << ">> What season is it best in?" << "\n\n";
        read(SEASON, anAct.season);
        cout << ">> What should you bring?" << "\n\n";
        read(LARGE, anAct.toBring);
    }else{
        cout << ">> Sorry, you can't add anymore activities." << "\n\n";
    }
}

void read(int size, char result[]){
    cin.get(result,size,'\n');
    cin.ignore(282,'\n');
}

void actSearch(int i, act arr[]){
    char search[20];

    cout << ">> What type of activity would you like to see all of?" << "\n\n";
    //was trying to iterate through the types and only display one of a kind
    //cout << ">> These are the current types of activities stored: ";
    //displayType(i,arr);
    cin.get(search,20,'\n');
    cin.ignore(100,'\n');

    for(int all = 0; all < i; ++all){ 
        if(comparer(search, arr[all].type)){
            actDisplay(arr[all]);  
        }
    } 
}

/*
void displayType(int max, act arr[]){
    char termA[20];
    char termB[20];

    for(int actloc = 0; actloc < max; ++actloc){

        for (int i = 0; i < 20; ++i){
            cout << "======= " << actloc << '\n';
        }
    }
    for(int all = 0;all < i; ++all){
        termA[all] = arr[all].type;
        for(int all = 0; all < i; ++all){ 
            termB[all] = arr[all].type;
            if(!comparer(termA,termB)){
                cout << arr.type << ", ";
            }
        } 
    }
}
*/

void actDisplay(act anAct){
   cout << ">> " << anAct.type << '\n'; 
   cout << ">> " << anAct.desc << '\n'; 
   cout << ">> " << anAct.season << '\n'; 
   cout << ">> " << anAct.toBring << "\n\n"; 
}

bool comparer(char search[], char type[]){
    char termA[TYPE];
    char termB[TYPE];
    
    for(int i = 0; i < TYPE; ++i){
        termA[i]=tolower(search[i]);
        termB[i]=tolower(type[i]);
    }
    return !strcmp(termA,termB);
}
void menuText(){
    cout << ">> Would you like to:" << '\n';                                   
    cout << ">> [A]dd an activity?" << '\n';                                   
    cout << ">> [S]earch for an activity by type" << '\n';                     
    cout << ">> [D]isplay all activitites" << '\n'; 
    cout << ">> [Q]uit" << '\n';
}





