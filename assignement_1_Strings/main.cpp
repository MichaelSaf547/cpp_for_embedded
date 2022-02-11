
#include <iostream>
#include <string>
#include <vector>

#include "String.cpp"


/*
/ Driver Code
*/

int main(void)
{
    int num_test = 2;

    vector<int> lengths{3, 2};

    vector<string> strings{"dragons_Song .mp3 11b", "theGreatGig.flac 1000b","file.txt 5b", "out .e x e 100b", "inception.mkv 10000b"};

    get_Divided(num_test, lengths, strings);

	return 0;
}
