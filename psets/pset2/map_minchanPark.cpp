//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: minchanPark Student Number: 21800270

#include <iostream>
#include <map>
using namespace std;

int main() {
    cout << "declare a map variable called table\n";

    map<string, int> table;

    cout << "initialize table using array[], insert(), pair<>, make_pair()\n";

    table["John"]=21;
    table["Paul"]=15;
    table["Pate"]=10;
    table["Adam"]=11;

    cout << "print table using range-based for loop\n";
    for(auto x: table){
        cout<<"name: "<<x.first<<"\t";
        cout<<" age: "<<x.second<<endl;
    }
    cout << "print table using iterator\n";
    for(auto it=table.begin(); it != table.end(); ++it){
        cout<<"name: "<<it->first<<"\t";
        cout<<" age: "<<it->second<<endl;
    }
    cout << "define and initialize chart using pair<> and make_pair() only\n";
    cout << "print chart using range-based for loop\n";
    map<char, int> chart{
        pair<char, int>('A', 65),
        pair<char, int>('C', 67),
        make_pair('D', 68),
        make_pair('B', 66)
    };
    for(auto item: chart){
        cout<<"ascii: "<<item.first<<"\t";
        cout<<" code: "<<item.second<<endl;
    }
    cout<<chart['B']<<endl;

    return 0;
}
