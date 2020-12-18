#include "Task1TextDistribution.hpp"
#include "Task2VectorMatrixDistribution.hpp"
#include "Task3HashTable.hpp"
#include "unordered_map"
#include "vector"
using namespace std;
int main() {
//    Task1();
//    Task2();
//    Task2_2();
//    Task3();
//   vector<pair<string,int>> words;
//  unordered_map<string,int> m;
//    m["lolka"] = 3;
//    m["lol"] = 4;
//    m["loooool"] = 5;
//    cout << m["lol"]<<endl;
//
//    for(unordered_map<string,int>::iterator it = m.begin(); it != m.end(); it++)
//    {
//        words.push_back(make_pair((*it).first,(*it).second));
//        //cout << (*it).second<<" ";
//    }
//    sort(words.begin(),words.end(),[](const pair<string,int>& p1,const pair<string,int>& p2){ return p1.second > p2.second;});

//    Dictionary<int,int> dict = Dictionary<int,int>();
//    dict.Set(10,45);
//    dict.Set(20,5);
//    //cout << dict.Get("Lol")<<endl;
//    dict.Print();
    Dictionary<string,int> dict = Dictionary<string,int>();
    dict.Add("lolka",4);
    dict.Add("lol",5);
    dict.Add("loool",6);
//    dict.Add("loool",9);
//    dict.Add("lolkaf",40);
//    dict.Delete("lol");
//    dict.Add("qwrtewl",666);
    dict["lol"] = 666;

    dict.Add("lolf",6);
    //dict.Add("sdff",666);
    dict.Print();
    //dict.Delete("sdff");
    //dict.Print();
    //cout << dict["lolka"]<<endl;
    return 0;
}
