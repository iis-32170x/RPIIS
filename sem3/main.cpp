
#include "decimal_realisation.cpp"
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
