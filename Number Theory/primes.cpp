vector<ll> primes;
        primes.pb(2);
        for (int i = 3; i < 31625; i += 2){
            for (int j = 0; j < primes.size(); j++){
                if (i%primes[j] == 0) break;
                if (primes[j]*primes[j] > i){
                    primes.pb(i);
                    break;
                }
            }
        }