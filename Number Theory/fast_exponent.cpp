ll power(ll a, ll b){
        if (b == 0) return 1;
        if (b == 1) return a;
        if (b%2 == 1) return (a*power(a,b-1))%MOD;
        ll x = power(a,b/2)%MOD;
        return (x*x)%MOD;
    }