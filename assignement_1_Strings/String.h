#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;

void get_Divided(int len, vector<int> lengths, vector <string> strings);

int get_size(string line, int start, int extension);

string get_last_syl(string line); 

#endif // STRING_H_INCLUDED
