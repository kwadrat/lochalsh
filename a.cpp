using namespace std;
#include <iostream>
#include <vector>
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
        #if VERBOSE_DIAG
            cout << "Basic!\n";
        #endif // VERBOSE_DIAG
        return false;
    }
    public:
    virtual void perform_ordering(std::vector<Diamond> a2)
    {
        std::sort(a2.begin(), a2.end(), basic_compare);
    }
};

class SortObject: public SortBasic
{
    public:
    void perform_ordering(std::vector<Diamond> a3)
    {
        #if VERBOSE_DIAG
            cout << "Compare objects - single message!\n";
        #endif // VERBOSE_DIAG
        std::sort(a3.begin(), a3.end());
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
    std::vector<Diamond> a1;

    void init_data(void)
    {
        a1.push_back(d_a);
        a1.push_back(d_b);
        a1.push_back(d_c);
        a1.push_back(d_d);
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
        this->sort_ptr->perform_ordering(a1);
    }
};

SortBasic sort_basic;
SortObject sort_object;


int main(void)
{
    JewelBox jewel_box;
    jewel_box.init_data();
    jewel_box.set_strategy( & sort_basic);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("Experimental, by class");

    jewel_box.set_strategy( & sort_object);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("Just object");

    std::sort(jewel_box.a1.begin(), jewel_box.a1.end(), sort_by_txt);
    jewel_box.show_current_table("By text");

    std::sort(jewel_box.a1.begin(), jewel_box.a1.end(), sort_by_month);
    jewel_box.show_current_table("By month");

    std::sort(jewel_box.a1.begin(), jewel_box.a1.end());
    jewel_box.show_current_table("Just object");
    return 0;
}
