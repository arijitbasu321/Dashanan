#include <iostream>
#include <getopt.h>
#include <cstring>

using namespace std;

int get_user_input(int argc, char** argv, char* framework, char* algorithm, 
                    char* scheduler, char* data);

void launch_interactive_UI(char* framework, char* algorithm, 
                        char* scheduler, char* data);

void print_help();

void print_version();

void print_banner();

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

int get_user_input(int argc, char** argv, char* framework, char* algorithm, 
                    char* scheduler, char* data) {

    int arg;
    
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

        int option_index = 0;

        arg = getopt_long(argc, argv, "Ihvf:a:s:d:", long_options, &option_index);

        if (arg == -1) {
            break;
        }

        switch(arg) {
            case 'I':
                launch_interactive_UI(framework, algorithm, scheduler, data);
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

void print_version(){
    cout << "Dashanan => v0.0.0" << endl;
}

void launch_interactive_UI(char* framework, char* algorithm, 
                        char* scheduler, char* data) {

    int choice;

    system("clear");
    print_banner();
    cout << "Choose Data Source:\n\n=> ";
    cin >> data;
    cout << endl;

    system("clear");
    print_banner();
    cout << "Choose framework: \n1. OpenMPI\n2. OpenMP\n\n=> ";
    cin >> choice;
    switch(choice) {
        case 1:
            strcpy(framework, "OpenMPI");
            break;
        case 2:
            strcpy(framework, "OpenMP");
            break;
        default:
            print_help();
            exit(254);
    }
    cout << endl;

    system("clear");
    print_banner();
    cout << "Choose algorithm: \n1. Linear-search \n2. Binary-search\n\n=> ";
    cin >> choice;
    switch(choice) {
        case 1:
            strcpy(algorithm, "Linear-search");
            break;
        case 2:
            strcpy(algorithm, "Binary-search");
            break;
        default:
            print_help();
            exit(254);
    }
    cout << endl;

    system("clear");
    print_banner();
    cout << "Choose scheduler: \n1. OpenPBS \n2. SLURM\n\n=> ";
    cin >> choice;
    switch(choice) {
        case 1:
            strcpy(scheduler, "OpenPBS");
            break;
        case 2:
            strcpy(scheduler, "SLURM");
            break;
        default:
            print_help();
            exit(254);
    }
    cout << endl;
    
    system("clear");
}

void print_banner() {
    cout << " ____            _                             \n" 
            "|  _ \\  __ _ ___| |__   __ _ _ __   __ _ _ __  \n"   
            "| | | |/ _` / __| '_ \\ / _` | '_ \\ / _` | '_ \\ \n"  
            "| |_| | (_| \\__ \\ | | | (_| | | | | (_| | | | |\n" 
            "|____/ \\__,_|___/_| |_|\\__,_|_| |_|\\__,_|_| |_|\n" 
        << endl;
}