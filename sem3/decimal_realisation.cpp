/*#include <iostream>
#include <cassert>
#include <limits>*/
#include "PPOIS_1.hpp"

int check_key()
{
    int number;

    while(1)
    {   
        std::cin >> number;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input! Try again " << std::endl;
        }
        else
        {
            std::cin.clear();
            break;
        }
    }
    
    return number;
}

void decimal::reduct_decimal()
{
    int a = abs(numerator);
    int b = abs(denominator);

    while(a && b)
    {
        if (a == 1 || b == 1)
        {
            a = 1;
            b = 0;
            break;
        }
                
        if(a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    numerator /= (a + b);
    denominator /= (a + b);

    if (denominator < 0)
    {
        denominator = -denominator;
        numerator = -numerator;
    }
         
}
decimal::decimal(int m_numerator, int m_denominator)
{
    numerator = m_numerator;
    denominator = m_denominator;
}

decimal::decimal(const decimal &some_decimal)
{
    numerator = some_decimal.numerator + 3;
    denominator = some_decimal.denominator;
    this->reduct_decimal();
}

decimal::~decimal(){}

int decimal::get_numerator() {return numerator;}
int decimal::get_denominator() {return denominator;}

void decimal::input_num_denom_main()
{
    int whole_part;
            
    std::cout << "Input whole part: ";
    whole_part = check_key();

    std::cout << "Input numerator: ";
    numerator = check_key(); 
    do
    { 
        std::cout << "Input denominator: ";
        denominator = check_key();
    } while (denominator <= 0 && std::cout << "Denominator must be > 0, retry" << std::endl);

    if(numerator < 0) {whole_part = -whole_part;}
    else if(whole_part < 0) {numerator = -numerator;}
            
    if (numerator == denominator)
    {numerator = whole_part + 1; denominator = 1;}
    else if (numerator != 0)
    {numerator = whole_part * denominator + numerator;}
    else if (numerator == 0)
    {
        numerator = 0;
        denominator = 1;
    }

    this->reduct_decimal();
}


decimal decimal::operator=(const decimal& right_operand)
{
    this->numerator = right_operand.numerator;
    this->denominator = right_operand.denominator;
    return *this;
}

decimal decimal::operator+(const decimal& right_operand) const
{
    decimal temp;
    temp.denominator = denominator * right_operand.denominator;
    temp.numerator = denominator * right_operand.numerator + right_operand.denominator * numerator;
    temp.reduct_decimal();
    return temp;
}

decimal decimal::operator += (const decimal& operand)
{
    *this = *this + operand;
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator -(const decimal& right_operand) const
{
    decimal temp;
    temp.denominator = denominator * right_operand.denominator;
    temp.numerator = right_operand.denominator * numerator - denominator * right_operand.numerator;
    temp.reduct_decimal();
    return temp;
}

decimal decimal::operator -= (const decimal& operand)
{
    *this = *this - operand;
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator * (const decimal& right_operand) const
{
    decimal temp;
    temp.denominator = denominator * right_operand.denominator;
    temp.numerator = numerator * right_operand.numerator;
    temp.reduct_decimal();
    return temp;
}


decimal decimal::operator *= (const decimal& operand)
{
    *this = *this * operand;
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator / (const decimal& right_operand) const
{

    if(right_operand.numerator == 0)
    {
        throw std::invalid_argument("Division on 0");
    }
        
    decimal temp;

    temp.denominator = denominator * right_operand.numerator;
    temp.numerator = numerator * right_operand.denominator;
    temp.reduct_decimal();

    return temp;
}

decimal decimal::operator /= (const decimal& operand)
{
    *this = *this / operand;
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator + (int number) const
{
    decimal temp = *this + decimal(number, 1);
    temp.reduct_decimal();
    return temp;
}

decimal decimal::operator += (int number)
{
    *this = decimal(number, 1) + *this;
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator - (int number) const
{
    decimal temp = *this - decimal(number, 1);
    temp.reduct_decimal();
    return temp;
}

decimal decimal::operator -= (int number)
{
    *this = *this - decimal(number, 1);
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator * (int number) const
{
    decimal temp = *this * decimal(number, 1);
    temp.reduct_decimal();
    return temp;
}

decimal decimal::operator *= (int number)
{
    *this = decimal(number, 1) * *this;
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator / (int number) const
{
    if (number == 0)
    {
        throw std::invalid_argument("Division on 0");
    }
    decimal temp = *this / decimal(number, 1);
    temp.reduct_decimal();
    return temp;
}

decimal decimal::operator /= (int number)
{
    *this = *this / decimal(number, 1);
    this->reduct_decimal();
    return *this;
}

decimal decimal::operator++()
{
    this->reduct_decimal();
    *this += 1;
    return *this;
}

decimal decimal::operator++(int)
{
    this->reduct_decimal();
    decimal temp = *this;
    ++(*this);
    return temp;
}

decimal decimal::operator--()
{
    this->reduct_decimal();
    *this -= 1;
    return *this;
}

decimal decimal::operator--(int)
{
    this->reduct_decimal();
    decimal temp = *this;
    --(*this);
    return temp;
}

bool decimal::operator > (const decimal& other) const
{
    return numerator * other.denominator > other.numerator * denominator;
}

bool decimal::operator >= (const decimal& other) const
{
    return numerator * other.denominator >= other.numerator * denominator;
}

bool decimal::operator < (const decimal& other) const
{
    return numerator * other.denominator < other.numerator * denominator;
}

bool decimal::operator <= (const decimal& other) const
{
    return numerator * other.denominator <= other.numerator * denominator;
}

bool decimal::operator > (int number) const
{
    return *this > decimal(number, 1);
}

bool decimal::operator >= (int number) const
{
    return *this >= decimal(number, 1);
}

bool decimal::operator < (int number) const
{
    return *this < decimal(number, 1);
}

bool decimal::operator <= (int number) const
{
    return *this <= decimal(number, 1);
}

double decimal::to_double()
{
    return double(numerator)/denominator;
}

void decimal::show()
{
    if (numerator != 0)
    {std::cout << numerator << "/" << denominator;}
    else
    {
        std::cout << numerator;
    }
}

