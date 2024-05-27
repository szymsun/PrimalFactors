// Rozkladanie liczb na czynniki pierwsze i obliczanie liczb pierwszych




#include <iostream>


using namespace std;

int ArrayLength(int* array){
    return sizeof(array)/sizeof(array[0]);
}

bool IsPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

// Przyklad rekurencji
int GetPrimalNumber(int StartingPoint){
    if(!IsPrime(StartingPoint)){
        return GetPrimalNumber(StartingPoint + 1);
    }
    return StartingPoint;
}


void CalculatePrimeFactors (int number, int* primalFactors)
{
    int num = number;
    int primalNum;
    int i = 0;

    primalNum = GetPrimalNumber(i);

    if(IsPrime(num)){
        primalFactors[0] = num;

        cout << "Czynniki pierwsze z " << number << ": " << primalFactors[0];
        return;
    }

    while (num != 1){
        if(num % primalNum != 0){
            primalNum = GetPrimalNumber(primalNum + 1);
        }
        else{
            primalFactors[i] = primalNum;
            cout << primalNum << "  " << i << endl;
            i++;
            num /= primalNum;
        }
    }



    cout << "Czynniki pierwsze z " << number << ": " ;
    for (int j = 0; j < i; ++j) {
        cout << endl << primalFactors[j];
    }
    cout << endl;

}




int main() {
    int *czynniki;
    czynniki = new int;
    int size;

    // Test1
    CalculatePrimeFactors(25, czynniki);


    int Wtestu = 1;

    for (int i = 0; i < ArrayLength(czynniki); ++i) {
        Wtestu *= czynniki[i];
    }

    if(Wtestu == 25)
    {
        cout << "TEST1: PASS";
    }
    else{
        cout << "TEST1: FAIL";
        delete czynniki;
        return -1;
    }


    // Memory leak prevention
    delete czynniki;

    return 0;
}
