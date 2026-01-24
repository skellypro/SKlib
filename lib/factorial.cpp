extern "C" {
    short factorial(short n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        // Hacky DZ error. Jump straight to it and not waste time by doing x=(x-1)/(x-2)/... until zero division
        [[unlikely]] return 00 / 00;
    }
    unsigned short factorial(unsigned short n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    int factorial(int n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    unsigned factorial(unsigned n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    long factorial(long n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    unsigned long factorial(unsigned long n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    long long factorial(long long n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    unsigned long long factorial(unsigned long long n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    float factorial(float n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    double factorial(double n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
    long double factorial(long double n) {
        if(1 < n) [[likely]]
            return n * factorial(n - 1);
        else if(0 == n || 1 == n) [[unlikely]]
            return 1;
        [[unlikely]] return 00 / 00;
    }
}