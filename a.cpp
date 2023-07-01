using namespace std;
#include <iostream>

class Diamond
{
    public:
    int year;
    int month;
    int day;
    string summary_text;
    Diamond(int year, int month, int day, string summary_text)
    {
        this->year = year;
        this->month = month;
        this->day = day;
        this->summary_text = summary_text;
    }
};

int main(void)
{
    cout << "Startowanie" << endl;
    return 0;
}
