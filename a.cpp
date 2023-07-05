using namespace std;
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define VERBOSE_DIAG 0

class MixinTele
{
    public:
    string tele_phone;
    MixinTele(string tele_text)
    {
        this->tele_phone = tele_text;
    }
};

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

    void show_time(void)
    {
        cout << "year: " << year << " ";
        cout << "month: " << month << " ";
        cout << "day: " << day << " ";
        cout << "summary_text: " << summary_text;
    }

    void show_end(void)
    {
        cout << endl;
    }

    void show_details(void)
    {
        show_time();
        cout << endl;
    }
};

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
    virtual void perform_ordering(std::vector<Diamond> & a2)
    {
        std::sort(a2.begin(), a2.end(), basic_compare);
    }
};

class SortObject: public SortBasic
{
    public:
    void perform_ordering(std::vector<Diamond> & a3)
    {
        #if VERBOSE_DIAG
            cout << "Compare objects - single message!\n";
        #endif // VERBOSE_DIAG
        std::sort(a3.begin(), a3.end());
    }
};

class SortText: public SortBasic
{
    static bool sort_by_txt(Diamond a, Diamond b)
    {
        #if VERBOSE_DIAG
            cout << "Text!\n";
        #endif // VERBOSE_DIAG
        return a.summary_text <= b.summary_text;
    }

    public:
    void perform_ordering(std::vector<Diamond> & a4)
    {
        std::sort(a4.begin(), a4.end(), sort_by_txt);
    }
};

class SortMonth: public SortBasic
{
    static bool sort_by_month(Diamond a, Diamond b)
    {
        #if VERBOSE_DIAG
            cout << "Month!\n";
        #endif // VERBOSE_DIAG
        return a.month <= b.month;
    }

    public:
    void perform_ordering(std::vector<Diamond> & a5)
    {
        std::sort(a5.begin(), a5.end(), sort_by_month);
    }
};

class SortDay: public SortBasic
{
    static bool sort_by_day(Diamond a, Diamond b)
    {
        #if VERBOSE_DIAG
            cout << "Day!\n";
        #endif // VERBOSE_DIAG
        return a.day <= b.day;
    }

    public:
    void perform_ordering(std::vector<Diamond> & a6)
    {
        std::sort(a6.begin(), a6.end(), sort_by_day);
    }
};

class JewelBox
{
    SortBasic * sort_ptr;
    public:
    std::vector<Diamond> a1;

    void init_data(void)
    {
        a1.push_back(Diamond(1999, 2, 12, "zenith"));
        a1.push_back(Diamond(2001, 4, 11, "glass"));
        a1.push_back(Diamond(2000, 1, 14, "magma"));
        a1.push_back(Diamond(2002, 3, 13, "amphora"));
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

    void using_builtin_function(void)
    {
        perform_sorting();
        show_current_table("Just object");
    }
};

int main(void)
{
    SortBasic sort_basic;
    SortObject sort_object;
    SortText sort_text;
    SortMonth sort_month;
    SortDay sort_day;

    JewelBox jewel_box;
    jewel_box.init_data();
    jewel_box.set_strategy( & sort_basic);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("Experimental, by class");

    jewel_box.set_strategy( & sort_object);
    jewel_box.using_builtin_function();

    jewel_box.set_strategy( & sort_text);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("By text");

    jewel_box.set_strategy( & sort_month);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("By month");

    jewel_box.set_strategy( & sort_day);
    jewel_box.perform_sorting();
    jewel_box.show_current_table("By day");

    jewel_box.set_strategy( & sort_object);
    jewel_box.using_builtin_function();
    return 0;
}
