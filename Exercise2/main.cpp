#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>


using namespace std;

int main()
{
    string file_name = "data.txt";
    
    double i = 0;
    vector<double> l = {};
    vector<double> mean = {};
    ifstream file(file_name);
    if ( file.is_open() ) {
        string line;
        while ( getline(file, line) ) {
 
            i = stod(line)*0.75 - 1.75;
            l.push_back(i);

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
