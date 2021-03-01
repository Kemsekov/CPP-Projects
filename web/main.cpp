#include <iostream>
#include <math.h>

bool isPrime(int num){
    int i = 1;
    while (++i<num)
    {
        if(num % i == 0)
        return false;
    }
    return true;
}

int main(){
    using namespace std;
    double num = 0;
    int primeCount = 0;
    int nonPrimeCount = 0;
    double previous = 0;
    for(int i=1;i<10000;i++){
        num = sqrt((24*i)+1);
        if(abs(num-round(num))<1e-5){
            if(isPrime((int)num)){
                primeCount++;
                cout<<num<<endl;
                //cout<<num<<" i : "<<i<<" Prime\n";
            }
            else{
                nonPrimeCount++;
                //cout<<num<<" i : "<<i<<" Non Prime\n";
            }
        }
    }
    cout<<primeCount<<" "<<nonPrimeCount<<endl;
    return 0;
}