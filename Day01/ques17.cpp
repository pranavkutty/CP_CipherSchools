//merge two sorted array using n+m extra space

void merge(vector<int>& vec1, int n1, vector<int>& vec2, int n2) {
    vector<int> merged(n1+n2);
    int a=0,b=0,c=0;
    while(a<n1 && b<n2){
        if(vec1[a]<=vec2[b]){
            merged[c] = vec1[a];
            a++;
        }
        else{
            merged[c] = vec2[b];
            b++;
        }
        c++;
    }
    while(a<n1){
        merged[c] = vec1[a];
        a++;
        c++;
    }
    while(b<n2){
        merged[c] = vec2[b];
        b++;
        c++;
    }
    
    for(int i=0;i<n1+n2;i++){
        vec1[i] = merged[i];
    }

}

//without using extra space