#include <iostream>
int main()
{
    std::cout << "Enter the first year: ";
    int year;
    std::cin >> year;
    std::cout << "Enter the number of patients we saw that year: ";
    double patients1 = 0.0;
    std::cin >> patients1;
    std::cout << "Enter the second year: ";
    double year_2;
    std::cin >> year_2;
    std::cout << "Enter the number of patients we saw that year: ";
    double patients2;
    std::cin >> patients2;

    double charity1 = 1071.87 * patients1;
    double charity2= 1071.87 * patients2;

    double percent_inc = ((patients2 - patients1) / patients1) * 100;

    std::cout << "In year "<< year << ", our hospital issued " <<charity1<< " dollars of charity charges.\n";
    std::cout << "In year " << year_2 << ", our hospital issued "
    << charity2<< " dollars of charity charges.\n";
    std::cout << "Between "<< year << " and " << year_2 <<  ", there was a " << percent_inc << "% increase in patients seen at our hospital.\n";
    return 0;

}
