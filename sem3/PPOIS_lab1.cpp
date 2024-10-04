#include <iostream>
#include <cassert>
#include <limits>

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

class decimal
{
    private:
        int numerator;
        int denominator;

        /*Алгоритм Евклида:
        1.Большее число делим на меньшее.
        2.Если делится без остатка, то меньшее число и есть НОД (следует выйти из цикла).
        3.Если есть остаток, то большее число заменяем на остаток от деления.
        4.Переходим к пункту 1.
        */
       
        void reduct_decimal()
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

            // std::cout << "Reduced fraction: " << numerator << "/" << denominator << std::endl;
        }
        
    public:

        //конструктор по умолчанию
        decimal(int m_numerator = 0, int m_denominator = 1)
        {
            numerator = m_numerator;
            denominator = m_denominator;
        }

        //конструктор копирования (+ небольшое изменение числителя)
        decimal(const decimal &some_decimal)
        {
            numerator = some_decimal.numerator + 3;
            denominator = some_decimal.denominator;
            this->reduct_decimal();
            // std::cout << "Copied decimal: " << numerator << "/" << denominator << std::endl;
        }

        //деструктор
        ~decimal()
        {
            // std::cout << "Fraction " << numerator << "/" << denominator << " deleted" << std::endl;
        }

        //геттеры
        int get_numerator() {return numerator;}
        int get_denominator() {return denominator;}

        //получаем целую часть, числитель и знаменатель
        void input_num_denom_main()
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


        decimal operator = (const decimal& right_operand)
        {
            this->numerator = right_operand.numerator;
            this->denominator = right_operand.denominator;
            return *this;
        }

        decimal operator + (const decimal& right_operand) const
        {
            decimal temp;
            temp.denominator = denominator * right_operand.denominator;
            temp.numerator = denominator * right_operand.numerator + right_operand.denominator * numerator;
            temp.reduct_decimal();
            return temp;
        }

        decimal operator += (const decimal& operand)
        {
            *this = *this + operand;
            this->reduct_decimal();
            return *this;
        }

        decimal operator - (const decimal& right_operand) const
        {
            decimal temp;
            temp.denominator = denominator * right_operand.denominator;
            temp.numerator = right_operand.denominator * numerator - denominator * right_operand.numerator;
            temp.reduct_decimal();
            return temp;
        }

        decimal operator -= (const decimal& operand)
        {
            *this = *this - operand;
            this->reduct_decimal();
            return *this;
        }

        decimal operator * (const decimal& right_operand) const
        {
            decimal temp;
            temp.denominator = denominator * right_operand.denominator;
            temp.numerator = numerator * right_operand.numerator;
            temp.reduct_decimal();
            return temp;
        }

        decimal operator *= (const decimal& operand)
        {
            *this = *this * operand;
            this->reduct_decimal();
            return *this;
        }

        decimal operator / (const decimal& right_operand) const
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


        decimal operator /= (const decimal& operand)
        {
            *this = *this / operand;
            this->reduct_decimal();
            return *this;
        }

        decimal operator + (int number) const
        {
            decimal temp = *this + decimal(number, 1);
            temp.reduct_decimal();
            return temp;
        }

        decimal operator += (int number)
        {
            *this = decimal(number, 1) + *this;
            this->reduct_decimal();
            return *this;
        }

        decimal operator - (int number) const
        {
            decimal temp = *this - decimal(number, 1);
            temp.reduct_decimal();
            return temp;
        }

        decimal operator -= (int number)
        {
            *this = *this - decimal(number, 1);
            this->reduct_decimal();
            return *this;
        }

        decimal operator * (int number) const
        {
            decimal temp = *this * decimal(number, 1);
            temp.reduct_decimal();
            return temp;
        }

        decimal operator *= (int number)
        {
            *this = decimal(number, 1) * *this;
            this->reduct_decimal();
            return *this;
        }

        decimal operator / (int number) const
        {
            if (number == 0)
            {
                throw std::invalid_argument("Division on 0");
            }
            decimal temp = *this / decimal(number, 1);
            temp.reduct_decimal();
            return temp;
        }

        decimal operator /= (int number)
        {
            *this = *this / decimal(number, 1);
            this->reduct_decimal();
            return *this;
        }

        decimal operator++()
        {
            this->reduct_decimal();
            *this += 1;
            return *this;
        }

        decimal operator++(int)
        {
            this->reduct_decimal();
            decimal temp = *this;
            ++(*this);
            return temp;
        }

        decimal operator--()
        {
            this->reduct_decimal();
            *this -= 1;
            return *this;
        }

        decimal operator--(int)
        {
            this->reduct_decimal();
            decimal temp = *this;
            --(*this);
            return temp;
        }

        bool operator > (const decimal& other) const
        {
            return numerator * other.denominator > other.numerator * denominator;
        }

        bool operator >= (const decimal& other) const
        {
            return numerator * other.denominator >= other.numerator * denominator;
        }

        bool operator < (const decimal& other) const
        {
            return numerator * other.denominator > other.numerator * denominator;
        }

        bool operator <= (const decimal& other) const
        {
            return numerator * other.denominator >= other.numerator * denominator;
        }

        bool operator > (int number) const
        {
            return *this > decimal(number, 1);
        }

        bool operator >= (int number) const
        {
            return *this >= decimal(number, 1);
        }

        bool operator < (int number) const
        {
            return *this < decimal(number, 1);
        }

        bool operator <= (int number) const
        {
            return *this <= decimal(number, 1);
        }

        double to_double()
        {
            return double(numerator)/denominator;
        }

        
        void show()
        {
            if (numerator != 0)
            {std::cout << numerator << "/" << denominator;}
            else
            {
                std::cout << numerator;
            }
        }
};


int main()
{


    decimal drob1, drob2;

    int switcher = 1, f_operations = 0;

    double tr_double;

    while(switcher)
    {
        std::cout << "Your operands: "; drob1.show(); std::cout << ", "; drob2.show(); std::cout << ", " << f_operations; std::cout << std::endl;
        std::cout << "1 - Input operands" << std::endl;
        std::cout << "2 - Perform operations" << std::endl;
        std::cout << "0 - Quit" << std::endl;

        switcher = check_key();

        switch(switcher)
        {
            case(1):
            {
                std::cout << "Input first decimal operand" << std::endl;

                drob1.input_num_denom_main();

                std::cout << "Input second decimal operand" << std::endl;

                drob2.input_num_denom_main();

                std::cout << "Input third integer operand" << std::endl;

                f_operations = check_key();

                break;
            }
            case(2):
            {
                decimal temp_drob1;
                temp_drob1 = drob1;

                std::cout << "Operations with decimals:" << std::endl;
                drob1.show(); std::cout << " + "; drob2.show(); std::cout << " = "; (drob1 + drob2).show(); std::cout << std::endl;
                drob1.show(); std::cout << " - "; drob2.show(); std::cout << " = "; (drob1 - drob2).show(); std::cout << std::endl;
                drob1.show(); std::cout << " * "; drob2.show(); std::cout << " = "; (drob1 * drob2).show(); std::cout << std::endl;
                drob1.show(); std::cout << " / "; drob2.show(); std::cout << " = "; (drob1 / drob2).show(); std::cout << std::endl;

                drob1.show(); std::cout << " += "; drob2.show(); temp_drob1 += drob2; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                drob1.show(); std::cout << " -= "; drob2.show(); temp_drob1 -= drob2; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                drob1.show(); std::cout << " *= "; drob2.show(); temp_drob1 *= drob2; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                drob1.show(); std::cout << " /= "; drob2.show(); temp_drob1 /= drob2; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                std::cout << "Operations with integer:" << std::endl;

                drob1.show(); std::cout << " + " << f_operations; std::cout << " = "; (drob1 + f_operations).show(); std::cout << std::endl;
                drob1.show(); std::cout << " - " << f_operations; std::cout << " = "; (drob1 - f_operations).show(); std::cout << std::endl;
                drob1.show(); std::cout << " * " << f_operations; std::cout << " = "; (drob1 * f_operations).show(); std::cout << std::endl;
                drob1.show(); std::cout << " / " << f_operations; std::cout << " = "; (drob1 / f_operations).show(); std::cout << std::endl;

                drob1.show(); std::cout << " += " << f_operations; temp_drob1 += f_operations; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                drob1.show(); std::cout << " -= " << f_operations; temp_drob1 -= f_operations; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                drob1.show(); std::cout << " *= " << f_operations; temp_drob1 *= f_operations; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                drob1.show(); std::cout << " /= " << f_operations; temp_drob1 /= f_operations; std::cout << " Result: "; temp_drob1.show(); std::cout << std::endl;
                temp_drob1 = drob1;

                std::cout << "To double:" << std::endl;

                tr_double = drob1.to_double();
                drob1.show(); std::cout << " => " << tr_double << std::endl;

                tr_double = drob2.to_double();
                drob2.show(); std::cout << " => " << tr_double << std::endl;


            }
            case(0):
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }
    
}