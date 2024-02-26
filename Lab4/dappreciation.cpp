#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};// Decelration of a string
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;//Taking input from the user 
  if (has_options_string == "yes") {
    return true;// used for return "true" as the boolean value
  } else {
    return false; // used for returning "false" as the boolean value
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

int main() {/* 
    This function is used to resale value of a car
    Within a range of 10 years and less than 3 accident
    */
    int y = car_model_year();
    int x = 2023 - y;
    int ac = car_accidents();
    bool p = car_has_premium_options(); 
    double ms = car_msrp();
    double final{ 0 };
    double per{ 0 };
    double acc{ 0 };
    double pr{ 0 };
    int flag1 = 0;
    int flag2 = 0;
    if (x >=0 && x <= 4) {
        per = 85;
    }
    else if (x > 4 && x <= 8) {
        per = 63;
    }
    else if (x == 9 || x==10) {
        per = 45;
    }
    else {
        flag1 = 1;
    }

    if (ac == 0) {
        acc = 0;
    }
    else if (ac == 1) {
        acc = 2;
    }
    else if (ac == 2) {
        acc = 10;
    }
    else if (ac==3) {
        acc = 20;
    }
    else {
        flag2 = 1;
    }

    if (p == true) {
        pr = 5;
    }
    else {
        pr = 0;
    }

    final = (per - acc) + pr;
    if (flag1 == 0 && flag2 == 0) {
        double price = ms * (final / 100);
        print_eligible_message(price);
    }
    else {
        print_ineligible_message();
    }
    return 0;
}
