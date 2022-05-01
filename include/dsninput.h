#ifndef DASHANAN_INPUT_H
#define DASHANAN_INPUT_H

int get_user_input(int argc, char** argv, char* framework, char* algorithm, 
                    char* scheduler, char* data);

void launch_interactive_UI(char* framework, char* algorithm, 
                        char* scheduler, char* data);

void get_interactive_input(const char* input_field, char* output_buffer);
void get_data_source(char* data);
void print_version();
void print_help();
void print_banner();

#endif