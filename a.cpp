using namespace std;
#include <iostream>
#include <array>
#include <bits/stdc++.h>

#define TEMPORARY_TOP_LEVEL_FUNCTIONS 1

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

class SortBasic
{
    static bool basic_compare(Diamond a, Diamond b)
    {
        return false;
    }
};

class JewelBox
{
    public:
    void init_data(void)
    {
        ;
    }
};

Diamond d_a(1999, 2, 12, "zenith");
Diamond d_b(2001, 4, 11, "glass");
Diamond d_c(2000, 1, 14, "magma");
Diamond d_d(2002, 3, 13, "amphora");

std::array<Diamond, 4> a1 = {d_a, d_b, d_c, d_d};

#if TEMPORARY_TOP_LEVEL_FUNCTIONS
bool top_level_cmp(Diamond a, Diamond b)
{
    return false;
}
#else // TEMPORARY_TOP_LEVEL_FUNCTIONS
#endif // TEMPORARY_TOP_LEVEL_FUNCTIONS

SortBasic sort_basic;

void show_current_table(string one_txt)
{
    cout << one_txt << ":" << endl;
    for(int i = 0; i < a1.size(); i++)
    {
        a1[i].show_details();
    }
    cout << endl;
}

#if TEMPORARY_TOP_LEVEL_FUNCTIONS
bool sort_by_txt(Diamond a, Diamond b)
{
    return a.summary_text <= b.summary_text;
}

bool sort_by_month(Diamond a, Diamond b)
{
    return a.month <= b.month;
}
#else // TEMPORARY_TOP_LEVEL_FUNCTIONS
#endif // TEMPORARY_TOP_LEVEL_FUNCTIONS

int main(void)
{
    JewelBox jewel_box;
    jewel_box.init_data();
    std::sort(a1.begin(), a1.end(), top_level_cmp);
    show_current_table("Experimental, by class");

    std::sort(std::begin(a1), std::end(a1));
    show_current_table("Just object");

    std::sort(a1.begin(), a1.end(), sort_by_txt);
    show_current_table("By text");

    std::sort(a1.begin(), a1.end(), sort_by_month);
    show_current_table("By month");

    std::sort(a1.begin(), a1.end());
    show_current_table("Just object");
    return 0;
}
