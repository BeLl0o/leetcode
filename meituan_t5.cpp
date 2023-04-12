#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    cout << s << "\n";
    unordered_map<string, string> dict;
    int m = 0, n = 0;
    while(m <= n && n < s.length()){
        string key, value;
        //key
        while(s[n] != '=' && s[n] != ';'){
            n++;
        }
        key = s.substr(m, n - m);
        //value
        n++;
        m = n;
        while(s[n] != '=' && s[n] != ';'){
            n++;
        }
        value = s.substr(m, n - m);
        n += 2;
        m = n;
        dict[key] = value;
    }
    int num;
    cin >> num;
    vector<string> request;
    for(int i = 0; i < num; i++){
        string tmp;
        cin >> tmp;
        request.push_back(tmp);
    }
    for(int i = 0; i < num; i++){
        if(dict.count(request[i]) != 0){
            cout << dict.at(request[i]) << endl;
        }else{
            cout << "EMPTY" << endl;
        }
    }
    return 0;

}
