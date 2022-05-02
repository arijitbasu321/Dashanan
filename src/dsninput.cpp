#include <iostream>
#include <getopt.h>
#include <cstring>
#include <stdlib.h>
#include <unordered_map>
#include "../include/dsninput.h"

using namespace std;

int get_user_input(int argc, char** argv, char* framework, 
                    char* algorithm, char* scheduler, char* data) {
    int arg;
    int option_index = 0;
    
    while(1) {
        static struct option long_options[] = {
            {"interactive", no_argument, 0, 'I'},
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'v'},
            {"framework", required_argument, 0, 'f'},
            {"algorithm", required_argument, 0, 'a'},
            {"scheduler", required_argument, 0, 's'},
            {"data", required_argument, 0, 'd'}
        };

        arg = getopt_long(argc, argv, "Ihvf:a:s:d:", long_options, 
                            &option_index);

        if (arg == -1) {
            break;
        }

        switch(arg) {
            case 'I':
                launch_interactive_UI(framework, algorithm, 
                                        scheduler, data);
                return 1;
                break;

            case 'v':
                print_version();
                exit(0);
                break;

            case 'h':
                print_help();
                exit(0);
                break;

            case 'f':
                strcpy(framework, optarg);
                break;

            case 'a':
                strcpy(algorithm, optarg);
                break;
            
            case 's':
                strcpy(scheduler, optarg);
                break;

            case 'd':
                strcpy(data, optarg);
                break;
            
            case '?':
                cout << endl;
                print_help();
                exit(254);
                break;

            default:
                abort();
        }
    }

    if(optind < argc) {
        cout << "unrecognized arguments: ";
        while(optind < argc) {
            cout << argv[optind++];
        }
        cout << endl;
        exit(254);
    }

    return 0;
}

void launch_interactive_UI(char* framework, char* algorithm, 
                        char* scheduler, char* data) {                      

    get_data_source(data);

    unordered_map<const char*, char*> input_options;
    input_options["framework"] = framework;
    input_options["algorithm"] = algorithm;
    input_options["scheduler"] = scheduler;

    for(auto x : input_options) {
        get_params_interactive(x.first, x.second);
    }

    cout << endl;
    system("clear");
}

void get_params_interactive(const char* input_field, 
                            char* output_buffer) {
    char choice;
    int choice_key;
    char c;
    FILE* ptr;
    char option[25];
    // int no_of_options = 0;
    char options_file[] = "config/";
    strcat(options_file, input_field);
    strcat(options_file, ".list");
    unordered_map<int, char*> options;
    
    ptr = fopen(options_file, "r");
    if (NULL == ptr) {
        puts("File cannot be read!");
        exit(1);
    }

    print_banner();
    cout << "Choose " << input_field << ":" << endl;
    cout << "------------------" << endl;
    cout << endl;

    int no_of_options = 0;
    while (NULL != fgets(option, 25, ptr)) {
        options[no_of_options]=option;
        printf("%d => %s", no_of_options++, option);
    }
    fclose(ptr);

    cout << "\n\nEnter Your choice? [Choose Number]\n\n=> ";

    cin >> choice;
    while ((c = getchar()) != '\n' && c != EOF) { }

    if(isdigit(choice)) {
        choice_key = (int)choice - 48;
        if(choice_key < no_of_options) {
            strcpy(output_buffer, options[choice_key]);
        }
        else {
            cout << "Invalid Input" << endl;
            exit(1);
        }
    }
    else {
        cout << "Invalid Input" << endl;
        exit(1);
    }    
}

void get_data_source(char* data) {
    print_banner();
    cout << "Choose Data Source [Enter Path]\n\n=> ";
    cin >> data;
}

void print_version(){
    cout << "Dashanan => v0.0.0" << endl;
}

void print_help(){
    cout << "Usage: dashanan  [OPTIONS]\n\n"
    << "-h  --help        Print usage details\n"
    << "-v  --version     Print version information.\n"
    << "-f  --framework   Select prarallel framework [OpenMPI/OpenMP]\n"
    << "-a  --algorithm   Select algorithm [OpenMPI/OpenMP]\n"
    << "-s  --scheduler   Select HPC scheduler [OpenPBS/SLURM]\n"
    << "-a  --data        Full path to the data source.\n"
    << flush;
}

void print_banner() {
    system("clear");
    cout << "####################################################\n"
            "# ____            _                                #\n" 
            "# |  _ \\  __ _ ___| |__   __ _ _ __   __ _ _ __    #\n"   
            "# | | | |/ _` / __| '_ \\ / _` | '_ \\ / _` | '_ \\   #\n"  
            "# | |_| | (_| \\__ \\ | | | (_| | | | | (_| | | | |  #\n" 
            "# |____/ \\__,_|___/_| |_|\\__,_|_| |_|\\__,_|_| |_|  #\n"
            "#                                                  #\n"
            "# The Parallel Programmer...                       #\n"
            "#                                                  #\n"
            "####################################################\n"
        << endl;
}

