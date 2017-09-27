//
// Created by ok on 9/27/17.
//
#include <iostream>

using namespace std;

class Weather {
    int day_of_month;
    float high_temp, low_temp, ammount_rain, ammount_snow;
public:
    Weather() {
        this->get_data();
    }
    Weather(
            int day_of_month,
            float high_temp,
            float low_temp,
            float ammount_rain,
            float ammount_snow
    ) {
        this->day_of_month = day_of_month;
        this->high_temp = high_temp;
        this->low_temp = low_temp;
        this->ammount_rain = ammount_rain;
        this->ammount_snow = ammount_snow;
    }

    void get_data() {
        cout << "Enter the data("
                "day_of_month,"
                "high_temp,"
                "low_temp,"
                "ammount_rain,"
                "ammount_snow): ";
        cin >> day_of_month >> high_temp >> low_temp >> ammount_rain >> ammount_snow;
    }

    void put_data() {
        cout << day_of_month << "\t" << high_temp << "\t" << low_temp << "\t" << ammount_rain << "\t" << ammount_snow;
    }
};

int main() {

}
