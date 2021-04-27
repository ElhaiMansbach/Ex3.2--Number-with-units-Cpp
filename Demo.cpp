/**
 * Demo file for the exercise on numbers with units
 *
 * @author Elhai Mansbach
 * @since 2021
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <stdlib.h>
#include "NumberWithUnits.hpp"

#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

using namespace std;
using namespace ariel;

static string ans;
static int money = 0;

void check_money(bool correct, int q)
{
    if (correct)
    {
        cout << BOLDGREEN << "Good job, that is correct :) " << endl;
        cout << endl;
        sleep(1);
        money += q * 10000;
        cout << BOLDBLUE << "Let's take a look at how much you've earned so far:" << endl;
        sleep(1);
        cout << "You've earned " << money << "$" << endl;
        cout << endl;
        sleep(1);
        if (q == 1)
        {
            cout << BOLDGREEN << "Well done, keep it up!" << endl;
            sleep(2);
            cout << endl;
        }
        else
        {
            if (money == 30000)
            {
                cout << BOLDGREEN << "Congratulations, you won the game!!!!!!!" << endl;
            }
            sleep(1);
            cout << endl;
            cout << BOLDGREEN << "Thank you for playing: Go with money or go with nothing." << endl;
            sleep(1);
            cout << endl;
            cout << "Have a good day :)" << endl;
            sleep(2);
        }
    }
    else
    {
        cout << BOLDRED << "I'm sorry this is a wrong answer :( " << endl;
        cout << endl;
        sleep(2);
        cout << BOLDMAGENTA << "Let's take a look at how much you've earned so far:" << endl;
        sleep(1);
        cout << "You've earned " << money << "$" << endl;
        sleep(1);
        cout << endl;
        if (q == 1)
        {
            cout << BOLDGREEN << "Keep trying, it's not over yet" << endl;
            sleep(2);
            cout << endl;
        }
        else
        {
            if (money == 0)
            {
                cout << BOLDRED << "Game over, and in your case you are - going with nothing :(" << endl;
                sleep(1);
                cout << endl;
                cout << BOLDGREEN << "Good luck next time" << endl;
            }
            else
            {
                cout << BOLDGREEN << "It's not perfect but hey, you won! Good job :)" << endl;
                sleep(1);
                cout << endl;
                cout << BOLDGREEN << "Have a good day :)" << endl;
            }
        }
    }
}

int option1(string q1)
{
    string ans1;
    string ans2;
    // ------------------------ Question 1 ------------------------
    cout << BOLDCYAN << "Question number 1 for 10,000 $" << endl;
    sleep(2);
    cout << BOLDYELLOW << "Eiffel Tower is 300 m high." << endl;
    cout << BOLDYELLOW << "How much it is in cm?" << endl;
    cout << BOLDWHITE;
    cin >> ans1;
    sleep(1);
    istringstream iss{ans1 + " [ cm ]"};
    NumberWithUnits a{300, "m"};
    NumberWithUnits a1{30000, "cm"};
    iss >> a;
    cout << endl;
    //sleep(1);
    if (a == a1)
    {
        check_money(true, 1);
    }
    else
    {
        check_money(false, 1);
    }

    // ------------------------ Question 2 ------------------------
    cout << BOLDCYAN << "Question number 2 for 20,000 $" << endl;
    sleep(2);
    cout << BOLDYELLOW << "An Asian elephant weighs 4000 kg." << endl;
    cout << BOLDYELLOW << "How much in g?" << endl;
    cout << BOLDWHITE;
    cin >> ans2;
    cout << endl;
    sleep(1);
    istringstream is{ans2 + " [ g ]"};
    NumberWithUnits b{4000, "kg"};
    NumberWithUnits b1{4000000, "g"};
    is >> b;
    if (b == b1)
    {
        check_money(true, 2);
    }
    else
    {
        check_money(false, 2);
    }
    cout << endl;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
int option2(string q2)
{
    string ans1;
    string ans2;
    // ------------------------ Question 1 ------------------------
    cout << BOLDCYAN << "Question number 1 for 10,000 $" << endl;
    sleep(2);
    cout << BOLDYELLOW << "What is worth more?" << endl;
    cout << BOLDGREEN << "1. 4 USD" << endl;
    cout << "2. 3.33 ILS" << endl;
    cout << "3. 3.95 USD" << endl;
    cout << "4. 12.5 ILS" << endl;
    cout << BOLDWHITE;
    cin >> ans1;
    int num = stoi(ans1);
    double answers[] = {4, 3.33, 3.95, 12.5};
    string num2 = to_string(answers[num - 1]);
    sleep(1);
    istringstream iss{num2 + " [ USD ]"};
    NumberWithUnits a{1, "USD"};
    NumberWithUnits a1{4, "USD"};
    NumberWithUnits a2{3.33, "ILS"};
    NumberWithUnits a3{3.95, "USD"};
    NumberWithUnits a4{12.5, "ILS"};
    iss >> a;
    cout << endl;
    if (a >= a1 && a > a2 && a >= a3 && a >= a4)
    {
        check_money(true, 1);
    }
    else
    {
        check_money(false, 1);
    }

    // ------------------------ Question 2 ------------------------
    cout << BOLDCYAN << "Question number 2 for 20,000 $" << endl;
    sleep(1);
    cout << BOLDYELLOW << "How many seconds are in one hour?" << endl;
    cout << BOLDGREEN << "1. 36000" << endl;
    cout << "2. 3600" << endl;
    cout << "3. 360" << endl;
    cout << "4. 36" << endl;
    cout << BOLDWHITE;
    cin >> ans2;
    cout << endl;
    int n = stoi(ans2);
    double arr[] = {36000, 3600, 360, 36};
    string n2 = to_string(arr[n - 1]);
    sleep(1);
    istringstream is{n2 + " [ sec ]"};
    NumberWithUnits b{1, "hour"};
    NumberWithUnits b1{36000, "sec"};
    NumberWithUnits b2{3600, "sec"};
    NumberWithUnits b3{360, "sec"};
    NumberWithUnits b4{36, "sec"};
    is >> b;
    if (b == b2)
    {
        check_money(true, 2);
    }
    else
    {
        check_money(false, 2);
    }
    cout << endl;
    return 0;
}

int option3(string q3)
{
    string ans1;
    string ans2;
    // ------------------------ Question 1 ------------------------
    cout << BOLDCYAN << "Question number 1 for 10,000 $" << endl;
    sleep(2);
    cout << BOLDYELLOW << "Is 1 ton equal to  500 kg + 500,000 g?" << endl;
    cout << BOLDGREEN << "1. True" << endl;
    cout << "2. False" << endl;
    cout << BOLDWHITE;
    cin >> ans1;
    NumberWithUnits a1{1, "ton"};
    NumberWithUnits a2{500, "kg"};
    NumberWithUnits a3{500000, "g"};
    cout << endl;
    if (ans1 == "1" && a1 == (a2 + a3))
    {
        check_money(true, 1);
    }
    else
    {
        check_money(false, 1);
    }

    // ------------------------ Question 2 ------------------------
    cout << BOLDCYAN << "Question number 2 for 20,000 $" << endl;
    sleep(1);
    cout << BOLDYELLOW << "Is it true that there are 23 hours in a day?" << endl;
    cout << BOLDGREEN << "1. True" << endl;
    cout << "2. False" << endl;
    cout << BOLDWHITE;
    cin >> ans2;
    cout << endl;
    NumberWithUnits b1{23, "hour"};
    NumberWithUnits b2{24, "hour"};
    if (ans2 == "2" && b1 < b2)
    {
        check_money(true, 2);
    }
    else
    {
        check_money(false, 2);
    }
    cout << endl;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    cout << BOLDBLUE << "Hello and welcome to the game: Go with money or go with nothing :)" << endl;
    cout << endl;
    sleep(1);
    while (true)
    {
        //cout << BOLDYELLOW << "Please choose a level between 1-3:" << endl;
        cout << BOLDCYAN << "Please select a question type:" << endl;
        sleep(1);
        cout << BOLDYELLOW << "1. Open questions" << endl;
        cout << BOLDYELLOW << "2. multiple choice question" << endl;
        cout << BOLDYELLOW << "3. True and false questions" << endl;
        cout << BOLDWHITE << endl;
        cin >> ans;
        cout << endl;
        if (ans == "1" || ans == "2" || ans == "3")
            break;
    }
    cout << BOLDMAGENTA << "Loading the game" << endl;
    sleep(1);
    unsigned int fast = 100000;
    for (unsigned int i = 0; i <= 40; i++)
    {
        if (i == 28)
        {
            usleep(fast * 2);
            cout << BOLDMAGENTA << "98%";
            fflush(stdout);
            usleep(fast);
        }
        else if (i == 34)
        {
            usleep(fast * 2);
            cout << BOLDMAGENTA << "99%";
            fflush(stdout);
            usleep(fast * 2);
        }
        else if (i == 40)
        {
            usleep(fast * 2);
            cout << BOLDMAGENTA << "100%";
            fflush(stdout);
            usleep(fast);
        }
        else
        {
            cout << BOLDMAGENTA << ".";
            fflush(stdout);
            usleep(fast);
        }
    }
    sleep(2);
    cout << endl;
    cout << BOLDBLUE << "Done! let's play " << endl;
    sleep(1);
    cout << BOLDBLUE << "Good Luck!!!!!!!! :-)" << endl;
    cout << endl;
    sleep(1);
    cout << endl;
    if (ans == "1")
    {
        option1(ans);
    }
    else
    {
        ans == "2" ? option2(ans) : option3(ans);
    }
    sleep(1);
    return 0;
}
