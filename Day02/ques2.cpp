//**keypad combinations**

#include<bits/stdc++.h>

using namespace std;

vector<string> keyMap = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypadCombinations(vector<string> &res, string str, const string keys,int index){
    int n=keys.size();

    if(index==n){
        res.push_back(str);
        return;
    }
    
    char key = keys[index];

    for(char x : keyMap[key-'0']){
        keypadCombinations(res,str+x,keys,index+1);
    };

}

int main(){
    int index=0;
    vector<string> res;
    string str="",keys="234";

    keypadCombinations(res,str,keys,index);

    for(string x : res)
        cout<<x<<endl;

    return 0;
}