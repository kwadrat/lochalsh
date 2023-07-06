using namespace std;
#include <iostream>

template <typename NazwaTypu>
NazwaTypu add(NazwaTypu liczba1, NazwaTypu liczba2)
{
    return (liczba1 + liczba2);
}

int main(void)
{
    int a = 5;
    int b = 3;
    int rezult_calk = add<int>(a, b);
    cout << "rezult_calk: " << rezult_calk << endl;

    float c = 5.2;
    float d = 3.1;
    float rezult_zmiennop = add<float>(c, d);
    cout << "rezult_zmiennop: " << rezult_zmiennop << endl;

    return 0;
}
