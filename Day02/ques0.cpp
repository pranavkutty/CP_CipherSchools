long long int nthFibonacci(long long int n){
    const long long mod = 1000000007;
    if(n<=1)
        return n;
    
    return (nthFibonacci(n-1)%mod+nthFibonacci(n-2)%mod)%mod;
}