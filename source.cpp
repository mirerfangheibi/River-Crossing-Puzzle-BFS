//--------------------------------------------------------
//--------|     ____  _            _  _      _    |-------
//--------|    / ___|| |__    ___ (_)| |__  (_)   |-------
//--------|   | |  _ | '_ \  / _ \| || '_ \ | |   |-------
//--------|   | |_| || | | ||  __/| || |_) || |   |-------
//--------|    \____||_| |_| \___||_||_.__/ |_|   |-------
//--------|                                       |-------
//--------------------------------------------------------

#define BOAT river_system[0]
#define POLICE river_system[1]
#define FATHER river_system[2]
#define MOTHER river_system[3]
#define THIEF river_system[4]
#define DAUGHTER1 river_system[5]
#define DAUGHTER2 river_system[6]
#define SON1 river_system[7]
#define SON2 river_system[8]

#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

string hashTable[9] = {"BOAT","POLICE","FATHER","MOTHER","THIEF","DAUGHTER1","DAUGHTER2","SON1","SON2"};

class Boat_River{
private:
    bool river_system[9];
    //    _______________________________________________________________
    //   |  __  |  __  |  __  |  __  |  __  |  __  |  __  |  __  |  __  |
    //   | |0 | | |1 | | |2 | | |3 | | |4 | | |5 | | |6 | | |7 | | |8 | |
    //   | |B | | |P | | |F | | |M | | |T | | |D1| | |D2| | |S1| | |S2| |
    //   | |__| | |__| | |__| | |__| | |__| | |__| | |__| | |__| | |__| |
    //   |______|______|______|______|______|______|______|______|______|
    //
    //   0 - B: Boat
    //   1 - P: Police
    //   2 - F: Father
    //   3 - M: Mother
    //   4 - T: Thief
    //   5 - D1: Daughter 1
    //   6 - D2: Daughter 2
    //   7 - S1: Son 1
    //   8 - S2: Son 2

    string Path; // (POLICE and THIEF)-->; (POLICE)<-- ...
public:
    Boat_River();
    
    void set_value(bool* argum);
    void concat_path(string p);
    bool is_valid();
    bool get_value(int x);
    bool operator==(const Boat_River& BR);
    bool operator!=(const Boat_River& BR);
    bool is_goal();
    bool toggle_1(int x);
    bool toggle_2(int x, int y);
    string get_path();
    
};

Boat_River::Boat_River(){
    for (int i = 0; i < 9; ++i)
    {
        river_system[i]=false;
    }
}
void Boat_River::set_value(bool* argum){
    for (int i = 0; i < 9; i++){
        river_system[i] = argum[i];
    }
}
void Boat_River::concat_path(string p){
    Path += p;
}
bool Boat_River::is_goal(){

    return river_system[0] &&
        river_system[1] &&
        river_system[2] &&
        river_system[3] &&
        river_system[4] &&
        river_system[5] &&
        river_system[6] &&
        river_system[7] &&
        river_system[8] &&
        true;
}
bool Boat_River::is_valid(){
    if (!((THIEF == POLICE) || ((THIEF != POLICE) &&(THIEF != FATHER) &&(THIEF != MOTHER) &&(THIEF != DAUGHTER1) &&(THIEF != DAUGHTER2) && (THIEF != SON1) && (THIEF != SON2))))
        return false;
    else if (((MOTHER == SON1) && (MOTHER != FATHER)) || ((MOTHER == SON2) && (MOTHER != FATHER)))
        return false;
    else if (((FATHER == DAUGHTER1) && (MOTHER != FATHER)) || ((FATHER == DAUGHTER2) && (MOTHER != FATHER)))
        return false;
    else
        return true;

}
bool Boat_River::get_value(int x){
    return river_system[x];
}
bool Boat_River::toggle_1(int x){
    if (river_system[x] == river_system[0]){
        river_system[x] = !river_system[x];
        river_system[0] = !river_system[0];
        return true;
    }
    else
        return false;
}
bool Boat_River::toggle_2(int x,int y){
    if (((x <= 3 && x >= 1) || (y <= 3 && y >= 1)) && ((river_system[y] == river_system[x]) && (river_system[x] == river_system[0]))){
        river_system[y] = !river_system[y];
        river_system[x] = !river_system[x];
        river_system[0] = !river_system[0];
        return true;
    }
    else
        return false;
}

bool Boat_River::operator==(const Boat_River& BR){
    return (BR.river_system[0] == river_system[0]&&
            BR.river_system[1] == river_system[1]&&
            BR.river_system[2] == river_system[2]&&
            BR.river_system[3] == river_system[3]&&
            BR.river_system[4] == river_system[4]&&
            BR.river_system[5] == river_system[5]&&
            BR.river_system[6] == river_system[6]&&
            BR.river_system[7] == river_system[7]&&
            BR.river_system[8] == river_system[8]);
}
bool Boat_River::operator!=(const Boat_River& BR){
    return !operator==(BR);
}
string Boat_River::get_path(){
    return Path;
}

queue<Boat_River> expand(Boat_River n){
    queue<Boat_River> children;
    Boat_River temp;
    temp = n;
    
    //Police
    if (temp.get_value(0) == temp.get_value(1)){
        if (temp.get_value(1))
            temp.concat_path(hashTable[1]+" <--\n");
        else
            temp.concat_path(hashTable[1]+" -->\n");

        temp.toggle_1(1);
        if (temp.is_valid())
            children.push(temp);
        temp = n;
    }

    //Father
    if (temp.get_value(0) == temp.get_value(2)){
        if (temp.get_value(2))
            temp.concat_path(hashTable[2]+" <--\n");
        else
            temp.concat_path(hashTable[2]+" -->\n");

        temp.toggle_1(2);
        if (temp.is_valid())
            children.push(temp);
        temp = n;
    }

    //Mother
    if (temp.get_value(0) == temp.get_value(3)){
        if (temp.get_value(3))
            temp.concat_path(hashTable[3]+" <--\n");
        else
            temp.concat_path(hashTable[3]+" -->\n");

        temp.toggle_1(3);
        if (temp.is_valid())
            children.push(temp);
        temp = n;
    }

    //Police
    for (int i = 2; i <= 8; i++){
        if (temp.get_value(0) == temp.get_value(1) && temp.get_value(1) == temp.get_value(i)){
            if (temp.get_value(i))
                temp.concat_path(hashTable[1] + " and " + hashTable[i] + " <--\n");
            else
                temp.concat_path(hashTable[1] + " and " + hashTable[i] + " -->\n");

            temp.toggle_2(1, i);
            if (temp.is_valid())
                children.push(temp);
            temp = n;
        }
    }

    //Father
    for (int i = 3; i <= 8; i++){
        if (temp.get_value(0) == temp.get_value(2) && temp.get_value(2) == temp.get_value(i)){
            if (temp.get_value(i))
                temp.concat_path(hashTable[2] + " and " + hashTable[i] + " <--\n");
            else
                temp.concat_path(hashTable[2] + " and " + hashTable[i] + " -->\n");

            temp.toggle_2(2, i);
            if (temp.is_valid())
                children.push(temp);
            temp = n;
        }
    }

    //Mother
    for (int i = 4; i <= 8; i++){
        if (temp.get_value(0) == temp.get_value(3) && temp.get_value(3) == temp.get_value(i)){
            if (temp.get_value(i))
                temp.concat_path(hashTable[3] + " and " + hashTable[i] + " <--\n");
            else
                temp.concat_path(hashTable[3] + " and " + hashTable[i] + " -->\n");

            temp.toggle_2(3, i);
            if (temp.is_valid())
                children.push(temp);
            temp = n;
        }
    }

    
    return children;

}
int main(){

    //--1
    Boat_River s; // Start State

    Boat_River n; // Node
    
    bool sucess = 0; // Success Flag
    
    queue<Boat_River> Un; // Unexpanded Nodes
    queue<Boat_River> children; // Returned Value From Expand
    list<Boat_River> Ex; // Expanded Nodes
    //queue<Boat_River> R; // Set Of Solutions

    Un.push(s);
    
    while (1) {
        //--2

        if (Un.empty()){
            //if (R.empty()){
                sucess = false;
                break;
            //}
        }

        else{
            n = Un.front();
        }
        
        //--3
        //if (!Un.empty())
        Un.pop();
        
        //--4
        if (n.is_goal()){
            //R.push(n);
            sucess = true;
            break;
        }
        
        //--5
        if ((count(Ex.begin(), Ex.end(), n))!=1){
            Ex.push_back(n);
            children = expand(n);
            while (!children.empty())
            {
                Un.push(children.front());
                children.pop();
            }
        }
    }

    
    if (sucess == false)
        cout << "There is no solution out there!" << endl;
    else{
        cout << "Possible Solution: " << endl;
            cout << "----------------------------\n" << endl;
            cout <<n.get_path() << endl;
            cout << "----------------------------" << endl;
        }
    
    cout << "Press any key to exit";
    cin.get();
    return 0;
}
