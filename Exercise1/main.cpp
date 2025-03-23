
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;


int main(void)
{
    string file_name = "data.txt";
    int i = 0;
    int l = 0;
    int s = 0;
    int dif = 0;
    int n = 18;
    ifstream file(file_name);
    if ( file.is_open() ) {
        string line;
        while ( getline(file, line) ) {
            if (line[0] == '#'){
                line = "0";
                continue;
            }
            if (line.empty()){ 
                line = "0";
            }
            cout << line << endl;
            l = stoi(line);
            i = i + l*l;
        }
        file.close();
    }

    s = (n*(n+1)*(2*n+1))/6;
    dif = s - i;
    cout << "The difference is: " << dif << endl;
    cout << "The sum is: " << s << endl;
    cout << "The sum of the squares is: " << i << endl;
    return 0;
}
