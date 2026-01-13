extern "C" {
    short factorial(short n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    unsigned short factorial(unsigned short n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    int factorial(int n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    unsigned factorial(unsigned n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    long factorial(long n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    unsigned long factorial(unsigned long n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    long long factorial(long long n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    unsigned long long factorial(unsigned long long n) {
        if(n == 0)
            return n;
        return n * factorial(n - 1);
    }
    float factorial(float n) {
    if(n == 0)
        return n;
    return n * factorial(n - 1);
    }
    double factorial(double n) {
    if(n == 0)
        return n;
    return n * factorial(n - 1);
    }
    long double factorial(long double n) {
    if(n == 0)
        return n;
    return n * factorial(n - 1);
    }
}


template <class T>
extern T factorial(T n) {
    if(n == 0)
        return n;
    return n * factorial(n - 1);
}