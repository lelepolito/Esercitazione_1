#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;
//ios_base& scientific (std::ios_base& str);
//tr.setf(std::ios_base::scientific, std::ios_base::floatfield);


int main()
{
    string file_name = "data.txt";
    
    float i = 0;
    vector<float> l = {};
    vector<float> mean = {};
    ifstream file(file_name);
    if ( file.is_open() ) {
        string line;
        while ( getline(file, line) ) {
          
            
            i = stof(line)*0.75 - 1.75;
            l.push_back(i);
            cout << scientific << setprecision(16) << i << endl;

        }
        file.close();
    i = 0;
    ofstream file_out;
    file_out.open("result.txt");
    file_out << "# N Mean" << endl;
    for (int c = 0; c < l.size(); c++) {
        i = l[c] + i;
        mean.push_back((i/(c+1)));
        file_out << c+1 << " " << scientific << setprecision(16) << i/(c+1) << endl;
    }
    file_out.close();
    }
    return 0;
}
