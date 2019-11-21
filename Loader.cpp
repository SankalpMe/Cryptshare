//
// Created by Sankalp Bhamare on 21/11/19.
//

#include "Loader.h"
using namespace std;
bool isLoading = false;
thread spt;
void showLoader1(){
    cout << R"(
    __                      __ _                  __
   / /   ____   ____ _ ____/ /(_)____   ____ _   / /
  / /   / __ \ / __ `// __  // // __ \ / __ `/  / /
 / /___/ /_/ // /_/ // /_/ // // / / // /_/ /  /_/
/_____/\____/ \__,_/ \__,_//_//_/ /_/ \__, /  (_)
                                     /____/
)" << endl;
}
void showLoader2(){
    cout << R"(
    __                      __ _                  __
   / /   ____   ____ _ ____/ /(_)____   ____ _   / /
  / /   / __ \ / __ `// __  // // __ \ / __ `/  / /
 / /___/ /_/ // /_/ // /_/ // // / / // /_/ /  /_/_
/_____/\____/ \__,_/ \__,_//_//_/ /_/ \__, /  (_)(_)
                                     /____/
)" << endl;
}

void showLoader3(){
    cout << R"(
    __                      __ _                  __
   / /   ____   ____ _ ____/ /(_)____   ____ _   / /
  / /   / __ \ / __ `// __  // // __ \ / __ `/  / /
 / /___/ /_/ // /_/ // /_/ // // / / // /_/ /  /_/_  _
/_____/\____/ \__,_/ \__,_//_//_/ /_/ \__, /  (_)(_)(_)
                                     /____/
)" << endl;
}
void loaderShow(){
    int duration = 500;
    while(isLoading){
        system("clear");
        showLoader1();
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        system("clear");
        showLoader2();
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        system("clear");
        showLoader3();
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    }
    system("clear");
}
void startLoading(){
    isLoading = true;
    spt = thread(loaderShow);
}
void stopLoading(){
    isLoading = false;
    spt.join();
}