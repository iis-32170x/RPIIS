#include <iostream>
#include <cassert>
#include <limits>

int check_key();

class decimal
{
    private:

     int numerator;
     int denominator;
     void reduct_decimal();

    public:

     decimal(int m_numerator = 0, int m_denominator = 1);
     decimal(const decimal &some_decimal);
     ~decimal();
     int get_numerator();
     int get_denominator();
     void input_num_denom_main();
     decimal operator = (const decimal& right_operand);
     decimal operator + (const decimal& right_operand) const;
     decimal operator += (const decimal& operand);
     decimal operator - (const decimal& right_operand) const;
     decimal operator -= (const decimal& operand);
     decimal operator * (const decimal& right_operand) const;
     decimal operator *= (const decimal& operand);
     decimal operator / (const decimal& right_operand) const;
     decimal operator /= (const decimal& operand);
     decimal operator + (int number) const;
     decimal operator += (int number);
     decimal operator - (int number) const;
     decimal operator -= (int number);
     decimal operator * (int number) const;
     decimal operator *= (int number);
     decimal operator / (int number) const;
     decimal operator /= (int number);
     decimal operator++();
     decimal operator++(int);
     decimal operator--();
     decimal operator--(int);
     bool operator > (const decimal& other) const;
     bool operator >= (const decimal& other) const;
     bool operator < (const decimal& other) const;
     bool operator <= (const decimal& other) const;
     bool operator > (int number) const;
     bool operator >= (int number) const;
     bool operator < (int number) const;
     bool operator <= (int number) const;
     double to_double();
     void show();
    
};