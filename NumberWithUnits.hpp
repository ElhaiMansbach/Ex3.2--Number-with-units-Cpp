#include <iostream>
#include <fstream>
#include <string>
#include <map>


namespace ariel
{
    class NumberWithUnits
    {

    private:
        double num;
        std::string unit;

    public:
        NumberWithUnits(double num, const std::string &unit);

        static void read_units(std::ifstream &units_file);
        static double convert_unit(double n, const std::string& before, const std::string& after);
        
        //Six accounting operators
        NumberWithUnits operator+(const NumberWithUnits &n2) const;
        NumberWithUnits operator-(const NumberWithUnits &n2) const;
        NumberWithUnits &operator+=(const NumberWithUnits &n2);
        NumberWithUnits &operator-=(const NumberWithUnits &n2);
        NumberWithUnits operator+();
        NumberWithUnits operator-();

        //Six comparison operators
        bool operator>(const NumberWithUnits &n2) const;
        bool operator>=(const NumberWithUnits &n2) const;
        bool operator<(const NumberWithUnits &n2) const;
        bool operator<=(const NumberWithUnits &n2) const;
        bool operator==(const NumberWithUnits &n2) const;
        bool operator!=(const NumberWithUnits &n2) const;

        //Increase by 1 (++) and decrease by 1 (--) before and after the number
         NumberWithUnits &operator++(); //++n
         NumberWithUnits operator++(int); //n++
         NumberWithUnits &operator--(); //--n
         NumberWithUnits operator--(int); //n--

        //Multiplication by real number
        friend NumberWithUnits operator*(const NumberWithUnits &n, double x);
        friend NumberWithUnits operator*(double x, const NumberWithUnits &n);
        NumberWithUnits &operator*=(double x);

        //Input and output operator
        friend std::ostream &operator<<(std::ostream &output, const NumberWithUnits &n);
        friend std::istream &operator>>(std::istream &input, NumberWithUnits &n);
    };
}