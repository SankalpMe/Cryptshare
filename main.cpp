#include <iostream>
#include <math.h>
#include <fstream>
#include "RSA.h"
#include "Loader.h"

using namespace std;

bool keyLoaded = false;
RSAKey loadedKey;
char namex[40];

class Employee{
    char name[40];
    int age;
    double salary;
public:
    void accept(){

        cout << "Name : ";

        cin.getline(name,40);
        cout << "Age : ";
        cin >> age;
        cin.get();
        cout << "Salary : ";
        cin >> salary;
        cin.get();


    }
    void display(){
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Salary : " << salary << endl;

    }
};
//int main() {
//    RSAGenerator gen(302305);
//    gen.createKey();
//    RSAKey kb(gen);
//    RSABlockKey key(kb);
//    ofstream fout("s.txt",ios::binary | ios::out);
//    Player ab[4];
//    for(int i =0; i < 4;i++){
//        ab[i].accept();
//        key.writeBlockData((char*)&ab[i], sizeof(Player),fout);
//    }
//    fout.close();
//    ifstream fin("s.txt",ios::binary | ios::in);
//    for(int i =0; i < 4;i++){
//        Player p;
//        key.readBlockData((char*)&p, sizeof(Player),fin);
//        p.display();
//    }
//
//
//
////    char res[20];
////    char cmd[20] = "sankalp is happy";
////
////    RSABlockKey kb(key);
////    RSABlockWriter rbw(key);
////    RSABlockReader rbr(key);
////
////    ofstream fout("s.txt",ios::binary | ios::out);
////    rbw.writeBlockData(cmd,20,fout);
////    fout.close();
////
////    ifstream fin("s.txt",ios::binary | ios::in);
////    rbr.readBlockData(res,20,fin);
////
////    cout << res << endl;
//    return 0;
//}
void clearScr(){
    system("clear");
}
void printTitleScreen(){


    cout << R"(
   ____  _____ ___       _______   ______________  ______  __________  ____
   / __ \/ ___//   |     / ____/ | / / ____/ __ \ \/ / __ \/_  __/ __ \/ __ \
  / /_/ /\__ \/ /| |    / __/ /  |/ / /   / /_/ /\  / /_/ / / / / / / / /_/ /
 / _, _/___/ / ___ |   / /___/ /|  / /___/ _, _/ / / ____/ / / / /_/ / _, _/
/_/ |_|/____/_/  |_|  /_____/_/ |_/\____/_/ |_| /_/_/     /_/  \____/_/ |_|
)" << endl;
    cout << " Version 1.0.1" << endl;



}
void printSMenuScreen(){
    cout << R"(
   __  ___
  /  |/  /___  ___  __ __
 / /|_/ // -_)/ _ \/ // /
/_/  /_/ \__//_//_/\_,_/

1. Generate Key     2. Load Private Key
3. Load Public Key  4. Exit
)" << endl;
}
void printMenuScreen(){
    cout << R"(
   __  ___
  /  |/  /___  ___  __ __
 / /|_/ // -_)/ _ \/ // /
/_/  /_/ \__//_//_/\_,_/

1. Read Message     2. New Message
3. Classes          4. Unload Key
5. Exit
)" << endl;
}
void printKeyGenerator(){
    cout << R"(
    __ __                ______                                 __
   / //_/___   __  __   / ____/___   ____   ___   _____ ____ _ / /_ ____   _____
  / ,<  / _ \ / / / /  / / __ / _ \ / __ \ / _ \ / ___// __ `// __// __ \ / ___/
 / /| |/  __// /_/ /  / /_/ //  __// / / //  __// /   / /_/ // /_ / /_/ // /
/_/ |_|\___/ \__, /   \____/ \___//_/ /_/ \___//_/    \__,_/ \__/ \____//_/
            /____/
)" << endl;
}
void printGeneratingKey(){
    cout << R"(
   ______                                 __   _                  __ __                __
  / ____/___   ____   ___   _____ ____ _ / /_ (_)____   ____ _   / //_/___   __  __   / /
 / / __ / _ \ / __ \ / _ \ / ___// __ `// __// // __ \ / __ `/  / ,<  / _ \ / / / /  / /
/ /_/ //  __// / / //  __// /   / /_/ // /_ / // / / // /_/ /  / /| |/  __// /_/ /  /_/
\____/ \___//_/ /_/ \___//_/    \__,_/ \__//_//_/ /_/ \__, /  /_/ |_|\___/ \__, /  (_)
                                                     /____/               /____/
)" << endl;
}
void printSaveKey(){
    cout << R"(
   _____                        __  __                       ____  _____  ___       __ __
  / ___/ ____ _ _   __ ___      \ \/ /____   __  __ _____   / __ \/ ___/ /   |     / //_/___   __  __
  \__ \ / __ `/| | / // _ \      \  // __ \ / / / // ___/  / /_/ /\__ \ / /| |    / ,<  / _ \ / / / /
 ___/ // /_/ / | |/ //  __/      / // /_/ // /_/ // /     / _, _/___/ // ___ |   / /| |/  __// /_/ /  _
/____/ \__,_/  |___/ \___/      /_/ \____/ \__,_//_/     /_/ |_|/____//_/  |_|  /_/ |_|\___/ \__, /  (_)
                                                                                            /____/
)" << endl;
}
void printLoadPrivateKey(){
    cout << R"(
    __                      __   ____         _                __           __ __                __
   / /   ____   ____ _ ____/ /  / __ \ _____ (_)_   __ ____ _ / /_ ___     / //_/___   __  __   / /
  / /   / __ \ / __ `// __  /  / /_/ // ___// /| | / // __ `// __// _ \   / ,<  / _ \ / / / /  / /
 / /___/ /_/ // /_/ // /_/ /  / ____// /   / / | |/ // /_/ // /_ /  __/  / /| |/  __// /_/ /  /_/
/_____/\____/ \__,_/ \__,_/  /_/    /_/   /_/  |___/ \__,_/ \__/ \___/  /_/ |_|\___/ \__, /  (_)
                                                                                    /____/
)" << endl;
}
void printLoadPublicKey(){
    cout << R"(
    __                      __   ____          __     __ _          __ __                __
   / /   ____   ____ _ ____/ /  / __ \ __  __ / /_   / /(_)_____   / //_/___   __  __   / /
  / /   / __ \ / __ `// __  /  / /_/ // / / // __ \ / // // ___/  / ,<  / _ \ / / / /  / /
 / /___/ /_/ // /_/ // /_/ /  / ____// /_/ // /_/ // // // /__   / /| |/  __// /_/ /  /_/
/_____/\____/ \__,_/ \__,_/  /_/     \__,_//_.___//_//_/ \___/  /_/ |_|\___/ \__, /  (_)
                                                                            /____/
)" << endl;
}
void printKeyNotFound(){
    cout << R"(
    __ __                _   __        __     ______                          __   __
   / //_/___   __  __   / | / /____   / /_   / ____/____   __  __ ____   ____/ /  / /
  / ,<  / _ \ / / / /  /  |/ // __ \ / __/  / /_   / __ \ / / / // __ \ / __  /  / /
 / /| |/  __// /_/ /  / /|  // /_/ // /_   / __/  / /_/ // /_/ // / / // /_/ /  /_/
/_/ |_|\___/ \__, /  /_/ |_/ \____/ \__/  /_/     \____/ \__,_//_/ /_/ \__,_/  (_)
            /____/
)" << endl;
    cout << "Press Any Key To Continue..." << endl;
}
void printNewMessage(){
    cout << R"(
    _   __                  __  ___
   / | / /___  _      __   /  |/  /___   _____ _____ ____ _ ____ _ ___     _
  /  |/ // _ \| | /| / /  / /|_/ // _ \ / ___// ___// __ `// __ `// _ \   (_)
 / /|  //  __/| |/ |/ /  / /  / //  __/(__  )(__  )/ /_/ // /_/ //  __/  _
/_/ |_/ \___/ |__/|__/  /_/  /_/ \___//____//____/ \__,_/ \__, / \___/  (_)
                                                         /____/
)" << endl;
}
void printSaveYourMessage(){
    cout << R"(
   _____                        __  __                       __  ___                                         __
  / ___/ ____ _ _   __ ___      \ \/ /____   __  __ _____   /  |/  /___   _____ _____ ____ _ ____ _ ___     / /
  \__ \ / __ `/| | / // _ \      \  // __ \ / / / // ___/  / /|_/ // _ \ / ___// ___// __ `// __ `// _ \   / /
 ___/ // /_/ / | |/ //  __/      / // /_/ // /_/ // /     / /  / //  __/(__  )(__  )/ /_/ // /_/ //  __/  /_/
/____/ \__,_/  |___/ \___/      /_/ \____/ \__,_//_/     /_/  /_/ \___//____//____/ \__,_/ \__, / \___/  (_)
                                                                                          /____/
)" << endl;
}
void printMessageSaved(){
    cout << R"(
    __  ___                                         _____                          __   __
   /  |/  /___   _____ _____ ____ _ ____ _ ___     / ___/ ____ _ _   __ ___   ____/ /  / /
  / /|_/ // _ \ / ___// ___// __ `// __ `// _ \    \__ \ / __ `/| | / // _ \ / __  /  / /
 / /  / //  __/(__  )(__  )/ /_/ // /_/ //  __/   ___/ // /_/ / | |/ //  __// /_/ /  /_/
/_/  /_/ \___//____//____/ \__,_/ \__, / \___/   /____/ \__,_/  |___/ \___/ \__,_/  (_)
                                 /____/
)" << endl;
    cout << "Press Any Key To Continue..." << endl;
}
void printLoadYourMessage(){
    cout << R"(
    __                      __   __  __                       __  ___                                         __
   / /   ____   ____ _ ____/ /   \ \/ /____   __  __ _____   /  |/  /___   _____ _____ ____ _ ____ _ ___     / /
  / /   / __ \ / __ `// __  /     \  // __ \ / / / // ___/  / /|_/ // _ \ / ___// ___// __ `// __ `// _ \   / /
 / /___/ /_/ // /_/ // /_/ /      / // /_/ // /_/ // /     / /  / //  __/(__  )(__  )/ /_/ // /_/ //  __/  /_/
/_____/\____/ \__,_/ \__,_/      /_/ \____/ \__,_//_/     /_/  /_/ \___//____//____/ \__,_/ \__, / \___/  (_)
                                                                                           /____/
)" << endl;
}
void printMessageNotFound(){
    cout << R"(
    __  ___                                         _   __        __     ______                          __   __
   /  |/  /___   _____ _____ ____ _ ____ _ ___     / | / /____   / /_   / ____/____   __  __ ____   ____/ /  / /
  / /|_/ // _ \ / ___// ___// __ `// __ `// _ \   /  |/ // __ \ / __/  / /_   / __ \ / / / // __ \ / __  /  / /
 / /  / //  __/(__  )(__  )/ /_/ // /_/ //  __/  / /|  // /_/ // /_   / __/  / /_/ // /_/ // / / // /_/ /  /_/
/_/  /_/ \___//____//____/ \__,_/ \__, / \___/  /_/ |_/ \____/ \__/  /_/     \____/ \__,_//_/ /_/ \__,_/  (_)
                                 /____/
)" << endl;
}
void printYourMessage(){
    cout << R"(
__  __                       __  ___
\ \/ /____   __  __ _____   /  |/  /___   _____ _____ ____ _ ____ _ ___     _
 \  // __ \ / / / // ___/  / /|_/ // _ \ / ___// ___// __ `// __ `// _ \   (_)
 / // /_/ // /_/ // /     / /  / //  __/(__  )(__  )/ /_/ // /_/ //  __/  _
/_/ \____/ \__,_//_/     /_/  /_/ \___//____//____/ \__,_/ \__, / \___/  (_)
                                                          /____/
)" << endl;
}
void printLoading(){
    cout << R"(
    __                      __ _                  __
   / /   ____   ____ _ ____/ /(_)____   ____ _   / /
  / /   / __ \ / __ `// __  // // __ \ / __ `/  / /
 / /___/ /_/ // /_/ // /_/ // // / / // /_/ /  /_/_  _
/_____/\____/ \__,_/ \__,_//_//_/ /_/ \__, /  (_)(_)(_)
                                     /____/
)" << endl;
}
void printCOTitle(){
    cout << R"(
   ______ __                                  ___                __   ____   __       _              __
  / ____// /____ _ _____ _____ ___   _____   /   |   ____   ____/ /  / __ \ / /_     (_)___   _____ / /_ _____
 / /    / // __ `// ___// ___// _ \ / ___/  / /| |  / __ \ / __  /  / / / // __ \   / // _ \ / ___// __// ___/
/ /___ / // /_/ /(__  )(__  )/  __/(__  )  / ___ | / / / // /_/ /  / /_/ // /_/ /  / //  __// /__ / /_ (__  )
\____//_/ \__,_//____//____/ \___//____/  /_/  |_|/_/ /_/ \__,_/   \____//_.___/__/ / \___/ \___/ \__//____/
                                                                               /___/
1. Employee
2. Student
3. Person
)" << endl;
}
int askForInput(){
    cout << "Choice: ";
    int n;
    cin >> n;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        n = askForInput();
    }

    return n;
}
int askForSaltInput(){
    cout << "Salt (6-DIGIT ONLY):";
    int n;
    cin >> n;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        n = askForSaltInput();
    }
    return n;
}
void askForKeyName(char* name){
    cout << "Key's Name:";
    cin >> name;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        askForKeyName(name);
    }
    cin.get();
}
void askForMessageName(char* name){
    cout << "Message Name : ";
    cin >> name;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        askForMessageName(name);
    }
    cin.get();
}
void askForNewMessage(char* msg){
    cin.clear();
    char mtoken[100];
    while(cin.getline(mtoken,100)){

        strcat(msg,mtoken);
        strcat(msg,"\n");
        if(mtoken[strlen(mtoken)-1] == '/'){
            msg[strlen(msg)-2] = '\0';
            break;
        }
    }

}
int askForClassInput(){
    cout << "Select Class :";
    int n;
    cin >> n;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        n = askForClassInput();
    }

    return n;
}
void genKey(){
    clearScr();
    printKeyGenerator();
    int salt = askForSaltInput();
    clearScr();
    printGeneratingKey();
    RSAGenerator gen(salt);
    gen.createKey();
    if(!gen.checkSalt()){
        genKey();
        return;
    }
    clearScr();
    printSaveKey();
    char name[40];

    askForKeyName(name);
    RSAKey key(gen);
    char name2[40];
    strcpy(name2,name);
    strcat(name,".key.dat");
    key.saveToFile(name);
    strcat(name2,".public.key.dat");
    key.savePublicKey(name2);
}

void loadPrivateKey(){
    clearScr();
    printLoadPrivateKey();
    char name[40];
    askForKeyName(name);
    strcpy(namex,name);
    strcat(name,".key.dat");
    if(loadedKey.loadFromFile(name)){
        keyLoaded = true;
    }else{
        clearScr();
        printKeyNotFound();
        cin.get();
        loadPrivateKey();
        return;
    }
}


void loadPublicKey(){
    clearScr();
    printLoadPublicKey();
    char name[40];
    askForKeyName(name);
    strcpy(namex,name);
    strcat(name,".public.key.dat");
    if(loadedKey.loadFromFile(name)){
        keyLoaded = true;
    }else{
        clearScr();
        printKeyNotFound();
        cin.get();
        loadPublicKey();
        return;
    }
}

void unloadKey(){
    keyLoaded = false;
}

void createNewMessage(){
    clearScr();
    printNewMessage();
    cout << "Use ( / ) To End Message !" << endl << endl;
    char msg[400];
    msg[0] = '\0';
    askForNewMessage(msg);
    RSABlockKey kb(loadedKey);
    clearScr();
    printSaveYourMessage();
    char name[40];



    askForMessageName(name);
    strcat(name,".msg.dat");
    ofstream fout(name,ios::binary|ios::out);
    kb.writeBlockData(msg,400,fout);
    printMessageSaved();
    fout.close();
}
void readMessage(){

    clearScr();
    if(!loadedKey.isPrivate){
        cout << "Key Is Not Private!";
        cin.ignore();
        cin.get();
        return;
    }
    printLoadYourMessage();
    char name[40];
    askForMessageName(name);
    strcat(name,".msg.dat");
    ifstream fin(name,ios::binary|ios::in);
    if(!fin){
        printMessageNotFound();
        readMessage();
        return;
    }
    clearScr();
    char msg[400];
    RSABlockKey kb(loadedKey);
    startLoading();
    kb.readBlockData(msg,400,fin);
    stopLoading();
    clearScr();
    printYourMessage();
    cout << msg << endl;
    cin.get();
}
void classesUI(){
    while (true){
        clearScr();
        printCOTitle();
        int n = askForClassInput();
        switch(n){
            case 1:
                break;
            case 2:
            break;
            case 3:
                break;
            case 4:
                return;
        }
    }
}

int main(){
    clearScr();
    printTitleScreen();
    if(!keyLoaded){
        printSMenuScreen();
        int n = askForInput();
        clearScr();
        switch(n){
            case 1:
                genKey();
                break;
            case 2:
                loadPrivateKey();
                break;
            case 3:
                loadPublicKey();
                break;
            case 4:
                return 0;
        }
    }else{
        cout << " Key Loaded : "<< namex << " "<< ((loadedKey.isPrivate)? "(private)" : "(public)" )<<endl;
        printMenuScreen();
        int n = askForInput();
        clearScr();
        switch(n){
            case 1:
                readMessage();
                break;
            case 2:
                createNewMessage();
                break;
            case 3:
                classesUI();
                break;
            case 4:
                unloadKey();
                break;
            case 5:
                return 0;
        }
    }

    main();

    return 0;
}

