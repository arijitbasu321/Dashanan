#include <iostream>
#include "../include/dsninput.h"

using namespace std;

int main(int argc, char** argv) {
    
    char framework[20];
    char algorithm[20];
    char scheduler[20];
    char data[20];

    get_user_input(argc, argv, framework, algorithm, scheduler, data);

    cout << framework << endl;
    cout << algorithm << endl;
    cout << scheduler << endl;
    cout << data << endl;

    return 0;
}