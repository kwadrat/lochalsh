using namespace std;
#include <iostream>
#include <array>
#include <bits/stdc++.h>

#define TEMPORARY_TOP_LEVEL_FUNCTIONS 1
#define VERBOSE_DIAG 0

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

#if TEMPORARY_TOP_LEVEL_FUNCTIONS
bool top_level_cmp(Diamond a, Diamond b)
{
    #if VERBOSE_DIAG
        cout << "Hit!\n";
    #endif // VERBOSE_DIAG
    return true; /* true - good order, false - wrong order, replace elements */
}

bool sort_by_txt(Diamond a, Diamond b)
{
    return a.summary_text <= b.summary_text;
}

bool sort_by_month(Diamond a, Diamond b)
{
    return a.month <= b.month;
}
#endif // TEMPORARY_TOP_LEVEL_FUNCTIONS

class SortBasic
{
    static bool basic_compare(Diamond a, Diamond b)
    {
        return false;
    }
};

Diamond d_a(1999, 2, 12, "zenith");
Diamond d_b(2001, 4, 11, "glass");
Diamond d_c(2000, 1, 14, "magma");
Diamond d_d(2002, 3, 13, "amphora");


class JewelBox
{
    SortBasic * sort_ptr;
    public:
    std::array<Diamond, 4> a1 = {d_a, d_b, d_c, d_d};

    void init_data(void)
    {
        ;
    }

    void set_strategy(SortBasic * sort_ptr)
    {
        this->sort_ptr = sort_ptr;
    }

    void show_current_table(string one_txt)
    {
        cout << one_txt << ":" << endl;
        for(int i = 0; i < a1.size(); i++)
        {
            a1[i].show_details();
        }
        cout << endl;
    }

    void perform_sorting(void)
    {
        std::sort(a1.begin(), a1.end(), top_level_cmp);
    }
};

SortBasic sort_basic;


int main(void)
{
    JewelBox jewel_box;
    jewel_box.init_data();
    jewel_box.set_strategy( & sort_basic);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("Experimental, by class");

    std::sort(std::begin(jewel_box.a1), std::end(jewel_box.a1));
    jewel_box.show_current_table("Just object");

    std::sort(jewel_box.a1.begin(), jewel_box.a1.end(), sort_by_txt);
    jewel_box.show_current_table("By text");

    std::sort(jewel_box.a1.begin(), jewel_box.a1.end(), sort_by_month);
    jewel_box.show_current_table("By month");

    std::sort(jewel_box.a1.begin(), jewel_box.a1.end());
    jewel_box.show_current_table("Just object");
    return 0;
}
