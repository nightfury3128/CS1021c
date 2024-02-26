#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

const int QuartersPerYear = 4;
const int EpochYear = 1977;
const int EpochQuarter = 1;

/*
   Main Function:
   This function drives the program execution by interacting with the user,
   obtaining input for the year and quarter, calculating the quarters since
   the base year, estimating the per capita GDP, and displaying the result to the user.
*/

int main() {
	std::cout << "Please enter the year for the calculation: ";
	int input_year = get_int();
	std::cout << "Please enter the quarter for the calculation: ";
	int input_quarter = get_int();
	int quarters_since_base = (input_year * QuartersPerYear) + (input_quarter - EpochQuarter);
	int qb = quarters_since_base - (EpochYear * QuartersPerYear);
	double gdp_estimate = calculate_per_capita_gdp_estimate(qb);
	std::string formatted_amount = format_money(gdp_estimate);
	std::string ordinal_quarter = quarter_to_ordinal(input_quarter);
	std::cout << "In the " << ordinal_quarter << " quarter of " << input_year << ", the projected contribution to GDP per working-age person is $" << formatted_amount << ".\n";
	return 0;
}