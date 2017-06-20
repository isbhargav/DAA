ll x;
        map<ll,ll> mp;
        for (int i = 0; i < n; i++){
            cin >> x;
            for (int j = 0; j < primes.size(); j++){
                while (x % primes[j] == 0){
                    x /= primes[j];
                    mp[primes[j]] ++;
                }
                if (x == 1) break;
            }
            if (x > 1) mp[x] ++;
        }