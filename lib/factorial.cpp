extern "C" {
    short factorial(short n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            // Hacky DZ error. Jump straight to it and not waste time by doing x=(x-1)/(x-2)/... until zero division
            return 00 / 00;
        return n * factorial(n - 1);
    }
    unsigned short factorial(unsigned short n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    int factorial(int n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    unsigned factorial(unsigned n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    long factorial(long n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    unsigned long factorial(unsigned long n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    long long factorial(long long n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    unsigned long long factorial(unsigned long long n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    float factorial(float n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    double factorial(double n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
    long double factorial(long double n) {
        if(00 == n)
            return 1;
        else if(0 > n)
            return 00 / 00;
        return n * factorial(n - 1);
    }
}