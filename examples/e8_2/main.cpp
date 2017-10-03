// Example 8.2 : Time and date
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <string>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Some method we are going to time
int fun(int n){
    int result = 0;
    for (int i = 0; i<1000*1000; ++i)
        result = (result + i*(i+1)*(i+2))%12345;

    return result;
}


//==============================
int main(){
    {
        cout << "\nRatio: :\n\n";

        using R1 = ratio<1, 1000>;
        cout << "1/1000 = " << R1::num << "/" << R1::den << endl;

        using R2 = ratio<25, 15>;
        cout << "25/15 = " << R2::num << "/" << R2::den << endl;

        using R3 = ratio<100, -10>;
        cout << "100/-10 = " << R3::num << "/" << R3::den << endl;

        // Pre-defined ratios
        cout << "atto = " << atto::num << "/" << atto::den << endl;
        cout << "nano = " << nano::num << "/" << nano::den << endl;
        cout << "milli = " << milli::num << "/" << milli::den << endl;
        cout << "giga = " << giga::num << "/" << giga::den << endl;
        cout << "exa = " << exa::num << "/" << exa::den << endl;

        // Arithmetics
        using R5 = ratio_add<ratio<1, 2>, ratio<1, 3>>;
        cout << "1/2 + 1/3 = " << R5::num << "/" << R5::den << endl;

        using R6 = ratio_multiply<ratio<1, 2>, ratio<1, 3>>;
        cout << "1/2 * 1/3 = " << R6::num << "/" << R6::den << endl;

        // Comparison. Static field value gives true or false.
        cout << boolalpha <<  "1/2 > 1/3 = " << ratio_greater<ratio<1, 2>, ratio<1, 3>>::value << endl;
    }

    {
        cout << "\nduration, duration_cast :\n\n";

        // Define own duration types
        using DMinutes = duration<double, ratio<60>>;
        using DSeconds = duration<double>;
        using DDays = duration<double, ratio<60*60*24>>;   // 60*60*24/1
        using DHours = duration<double, ratio<60*60>>;      // 60*60/1

        // Examples from cppreference.com
        constexpr auto year = 31556952ll; // seconds in average Gregorian year
        using Shakes = duration<int, ratio<1, 100000000>>;
        using Jiffies = duration<int, centi>;
        using Microfortnights = duration<float, ratio<14*24*60*60, 1000000>>;
        using Nanocenturies = duration<float, ratio<100*year, 1000000000>>;

        // Variables
        seconds s148(148);       //148 int seconds
        minutes m1(1);          //1 int minute
        DSeconds ds1_3(1.3);    //1.3 double seconds
        auto dur1 = minutes(1) + seconds(3) - milliseconds(247);

        // Time literals, use operator""h etc.
        using namespace std::chrono_literals;
        auto dur2 = 1h + 10min + 42s;
        auto dur3 = 1s + 234ms + 567us + 890ns;

        // count(), duration_cast
        // Implicit cast
        cout.precision(9);
        cout << "148 seconds = " << DMinutes(s148).count() << " DMinutes" << endl;
        // Here we need duration_cast beacuse of loss of accuracy
        cout << "148 seconds = " << duration_cast<minutes>(s148).count() << " minutes" << endl;

        cout << "1.3 seconds = " << duration_cast<milliseconds>(ds1_3).count() << " milliseconds" << endl;
        cout << "dur1 = " << milliseconds(dur1).count() << " milliseconds" << endl;
        cout << "dur2 = " << seconds(dur2).count() << " seconds" << endl;
        cout << "dur3 = " << DSeconds(dur3).count() << " DSeconds" << endl;
    }

    {
        cout << "\nduration, duration_cast :\n\n";
    }

    return 0;
}
