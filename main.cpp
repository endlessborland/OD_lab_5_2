#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
const int MAXINPUT = 1024;

string readLine();
void tokenize(const string&,
              vector<string>&,
              const string&);
bool checkPolindrom(string);

int main()
{
    cout << "Insert the data" << endl;
    string text = readLine();
    vector<string> words;
    bool pfound = false;
    tokenize(text, words, " ,.;\"?!-:()");
    for (int i = 0; i < words.size(); i++)
    {
        if (checkPolindrom(words[i]))
        {
            cout << words[i] << endl;
            pfound = true;
        }
    }
    if (pfound == false)
    {
        cout << "No such words!" << endl;
    }
    return 0;
}

string readLine()
{
    char* input = (char*)calloc(1, sizeof(char)); /* init the array */
    char c;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if (i < MAXINPUT)
        {
            input = (char*)realloc(input, (i+1) * sizeof(char));
            input[i] = c;
            i++;
        }
    }
    input = (char*)realloc(input, (i + 1) * sizeof(char)); /* finishing a string */
    input[i] = '\0';
    return string(input);
}

void tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

bool checkPolindrom(string word)
{
    int len = word.length();
    for(int i = 0; i < len/2; ++i)
    {
        if(word[i] != word[len-i-1])
        {
            return false;
        }
    }
    return true;
}
