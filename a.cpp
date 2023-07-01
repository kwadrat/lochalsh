using namespace std;
#include <iostream>
#include <array>
#include <bits/stdc++.h>

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
    bool operator <(Diamond elem_b)
    {
        return year < elem_b.year;
    }
    void show_details(void)
    {
        cout << "year: " << year << " ";
        cout << "month: " << month << " ";
        cout << "day: " << day << " ";
        cout << "summary_text: " << summary_text;
        cout << endl;
    }
};

Diamond d_a(1999, 2, 12, "zenith");
Diamond d_b(2001, 4, 11, "glass");
Diamond d_c(2000, 1, 14, "magma");
Diamond d_d(2002, 3, 13, "amphora");

std::array<Diamond, 4> a1 = {d_a, d_b, d_c, d_d};

void show_current_table(void)
{
    for(int i = 0; i < a1.size(); i++)
    {
        a1[i].show_details();
    }
    cout << endl;
}

bool sort_by_txt(Diamond a, Diamond b)
{
    return a.summary_text <= b.summary_text;
}

bool sort_by_month(Diamond a, Diamond b)
{
    return a.month <= b.month;
}

int main(void)
{
    std::sort(std::begin(a1), std::end(a1));
    show_current_table();

    std::sort(a1.begin(), a1.end(), sort_by_txt);
    show_current_table();

    std::sort(a1.begin(), a1.end(), sort_by_month);
    show_current_table();

    std::sort(a1.begin(), a1.end());
    show_current_table();
    return 0;
}
