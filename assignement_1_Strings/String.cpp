#include "String.h"
#include <sstream>
#include <algorithm>


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*
/   get_size function is used to get the file size in bytes.
/   It takes string line: the line to get the size from it,
/   int start: the position of the extension,
/   int extension: the length of the extension to cut it.
/
/   It returns int: the file size.
*/

int get_size(string line, int start, int extension)
{
    stringstream digit;
    int number;
    string my_str = line.substr(start + extension);

    my_str.erase(remove(my_str.begin(), my_str.end(), 'b'), my_str.end());

    digit << my_str;
    digit >> number;

    return number;
}

/*
/   get_last_syl function is used to get the last word in the string.
/   It takes string line: the line to get the last word of it,
/   int extension: the length of the extension to cut it.
/
/   It returns string: the the last word.
*/

string get_last_syl(string line)
{

    //Define contant data that will be worked as delimiter
    const char separator = ' ';

    //Define the dynamic array variable of strings
    std::vector<string> outputArray;

	//Construct a stream from the string
    std::stringstream streamData(line);

	/*
    Declare string variable that will be used
    to store data after split
    */

	std::string val;

	/*
    The loop will iterate the splitted data and
    insert the data into the array
    */

	while (std::getline(streamData, val, separator)) {
        outputArray.push_back(val);
    }

	return outputArray[outputArray.size() - 1];
}

/*
/   get_Dicided function is used to search for each extension and sum the sizes of same category.
/   It takes int len: the number of test cases,
/   vector of integers lengths: the number of strings of each test case,
/   vector of strings strings: holds all the strings of the test cases.
/
/   It does not return anything, it prints the each category with its size for each test case.
*/

void get_Divided(int len, vector<int> lengths, vector <string> strings)
{

    /*
    / The extensions i am searching for
    */
    vector<string> extensions{"flac", "aac", "mp3", "jpg", "bmp", "gif", "mp4", "avi", "mkv"};


    /*
    / The output result for each type of media.
    */
    int music_Length;
    int image_Length;
    int moive_Length;
    int other_Length;

    /*
    / Helper counters and variables.
    */
    int strings_vector_counter = 0;     // counter for strings inside the vector.
    int test_cases_counter = 0;         // counter for test cases.
    int strings_test_counter;           // counter for strings inside each test case.
    int counter;                        // counter for the extension vector.

    string line;                        // string to hold each line of the input.
    int found;                          // the location of the extension.
    int file_size;                      // the size of each line.

    /*
    / This while loop for the test cases .
    */
    while(test_cases_counter < len)
    {
        /*
        / Reset sizes of all media for new test case.
        */
        music_Length = 0;
        image_Length = 0;
        moive_Length = 0;
        other_Length = 0;

        strings_test_counter = 0;       // Reset the counter of strings for each test case.

        while(strings_test_counter < lengths[test_cases_counter])
        {
            line = strings[strings_vector_counter];     // Read line by line.

            counter = 0;                // Reset the counter of the extension vector

            /*
            / This while loop for the extension vector to find one of the defined extension
            / It breaks whenever it find an extension.
            */
            while(counter < 9)
            {
                found = line.find(extensions[counter]);
                if(found < line.size())
                {
                    if(counter < 1)
                    {
                        file_size = get_size(line, found, 5);   // as this extension ("flac") is four chars
                        break;
                    }
                    else
                    {
                        file_size = get_size(line, found, 4);
                        break;
                    }
                }
                counter++;
            }

            /*
            / Checks if the counter is in the defines vector or not depending on its value.
            / The first three are for music.
            / The next three are for image.
            / The last three are for video.
            / If it is out of that it means that it belongs to others,
            / so get the last word that has the size then get the file size.
            */
            if(counter < 3)
            {
                music_Length += file_size;
            }
            else if(counter >= 3 && counter < 6)
            {
                image_Length += file_size;
            }
            else if(counter >= 6 && counter < 9)
            {
                moive_Length += file_size;
            }
            else
            {
                other_Length += get_size(get_last_syl(line), 0, 0);
            }

            /*
            / Increase the strings counter of each case.
            / Increase the strings counter of the input vector.
            */

            strings_test_counter++;
            strings_vector_counter++;
        }

        /*
        / After finishing each test print the result of this test.
        / Increase the test cases counter to start the new test caseS.
        */

        cout<<"music "<<music_Length<<"b";
        cout<<" images "<<image_Length<<"b";
        cout<<" movies "<<moive_Length<<"b";
        cout<<" other "<<other_Length<<"b"<<endl;

        test_cases_counter++;
    }

}



