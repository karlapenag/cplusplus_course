//
// Created by Karla Angélica Peña Guerra on 3/26/22.
//
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main ()
{
    const char *str="hola beba    karla  ola";
    // Extract the first token
    char * token = strtok(str, " ");
// loop through the string to extract all other tokens
    while( token != NULL ) {
        printf( " %s\n", token ); //printing each token
        token = strtok(NULL, " ");
    }
    return 0;
    /*char c;
    int i=0;
    char str[]="Example sentence to test isspace\n";
    while (str[i])
    {
        c=str[i];
        cout<<isspace(c)<<endl;
        if (isspace(c)) c='\n';
        putchar (c);
        i++;
    }
    return 0;*/
}


/*#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;

int main(){
    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                  "Sed laoreet sem  leo, in posuere orci elementum.";
    string space_delimiter = " ";
    string tab_delimiter = "\t";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos || (pos = text.find(tab_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    for (const auto &str : words) {
        cout << str << endl;
    }

    return EXIT_SUCCESS;
}*/

  /*char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;*/

