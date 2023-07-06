using namespace std;
#include <iostream>

template <typename NazwaTypu>
void pokaz(NazwaTypu cos_a)
{
    cout << cos_a << endl;
}

int main(void)
{
    int a = 5;
    pokaz<int>(a);

    float c = 5.2;
    pokaz<float>(c);

    string tmp_napis = "kredka";
    pokaz<string>(tmp_napis);

    return 0;
}
