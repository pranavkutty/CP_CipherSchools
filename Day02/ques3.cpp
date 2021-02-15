//Count Possible Decodings of a given Digit Sequence

#include<bits/stdc++.h>

using namespace std;

string charMap = "_abcdefghijklmnopqrstuvwxyz";

void digitDecode(string digits,vector<string> &res,string str,int index){
    int n = digits.size();

    if(index>=n){
        res.push_back(str);
        return;
    }

    if(index==n-1 || digits[index+1]!='0')
        digitDecode(digits,res,str+charMap[digits[index]-'0'],index+1);

    if(index<n-1){
        int digit = 10*(digits[index]-'0') + (digits[index+1]-'0');
        if(digit<=26)
            digitDecode(digits,res,str+charMap[digit],index+2);
    }
    
}

int main(){
    string digits = "1234";
    vector<string> res;
    string str="";
    int index=0;

    digitDecode(digits,res,str,index);

    for(string result : res){
        cout<<result<<endl;
    }

    return 0;
}