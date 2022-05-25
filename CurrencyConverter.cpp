#include <iostream>
#include <limits>
#include <iomanip> // setprecision is set the maximum numbers of digits to whatever you set
#include <math.h>  // For round() to round to the
using namespace std;

// !Default 2022 USA Dollar
const double USA = 1.00; // = Below currencies conversion

// !1 Qatari Rial
const double qatar = 3.64;
// !2 Singapore Dollar
const double singapore = 1.39;
// !3 Dirham
const double unitedArabEmirates = 3.67;
// !4 Pounds Sterling
const double unitedKingdom = 0.81;
// !5 Euros
const double france = 0.95;

double multiplicationQatar(double userAmountInput) // Qatar
{

    return userAmountInput * qatar;
}

double multiplicationSingapore(double userAmountInput) // Singapore
{
    return userAmountInput * singapore;
}

double multiplicationUnitedKingdom(double userAmountInput) // United Kingdom
{
    return userAmountInput * unitedKingdom;
}

double multiplicationUnitedArabEmirates(double userAmountInput) // United Arab Emirates
{
    return userAmountInput * unitedArabEmirates;
}

double multiplicationFrance(double userAmountInput) // France
{
    return userAmountInput * france;
}

int userOptionsOfCurrency()
{
    int userSelectedCountryOfChoiceForConversion;
    cout << "\nWhich Currency would you like to convert to?" << endl
         << "(1) for Qatar (Qatari Rial)" << endl
         << "(2) for Singapore (Singaporean Dollar)" << endl
         << "(3) for United Kingdom (Pounds)" << endl
         << "(4) for United Arab Emirates (Dirham)" << endl
         << "(5) for France (Euros)" << endl
         << "Input choice here: ";

    while (!(cin >> userSelectedCountryOfChoiceForConversion) || (userSelectedCountryOfChoiceForConversion < 1) || (userSelectedCountryOfChoiceForConversion > 5))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Forces user to only put integers and not letters
        cout << "\nInvalid Input";
        cout << "\nInput Choice here: ";
    }

    return userSelectedCountryOfChoiceForConversion;
}

double userTotalAmountForConversion() // todo finish this
{
    double userAmountInput;
    cout << "\nHow much in US Dollars do you want to convert?" << endl
         << "Input amount here: $ ";

    while (!(cin >> userAmountInput))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Forces user to only put integers and not letters
        cout << "\nInvalid Input" << endl
             << "Input amount here: $ ";
    }
    userAmountInput = round(userAmountInput * 100) / 100; // for two decimal places
    return userAmountInput;
}

void showConversion(double userAmountInput, int userSelectedCountryOfChoiceForConversion)
// setprecision displays the user's input for only 2 decimal places
{
    if (userSelectedCountryOfChoiceForConversion == 1)
        cout << "QR " << multiplicationQatar(userAmountInput) << endl;
    // 1. Qatar

    if (userSelectedCountryOfChoiceForConversion == 2)
        cout << "S$ " << multiplicationSingapore(userAmountInput) << endl;
    // 2. Singapore

    if (userSelectedCountryOfChoiceForConversion == 3)
        cout << multiplicationUnitedKingdom(userAmountInput) << " Pounds" << endl;
    // 3. United Kingdom

    if (userSelectedCountryOfChoiceForConversion == 4)
        cout << "AED " << multiplicationUnitedArabEmirates(userAmountInput) << endl;
    // 4. United Arab Emirates

    if (userSelectedCountryOfChoiceForConversion == 5)
        cout << multiplicationFrance(userAmountInput) << " Euros" << endl; //
    // 5. France
}

int main() // todo Add more if you want to try again
{
    int userSelectedCountryOfChoiceForConversion;
    double userAmountInput;

    userSelectedCountryOfChoiceForConversion = userOptionsOfCurrency();
    userAmountInput = userTotalAmountForConversion();
    showConversion(userAmountInput, userSelectedCountryOfChoiceForConversion);

    int userSelectedOption;
    int loopUserSelectedOption;

    cout << "\nWould you like to use the Currency Converter? *(1) for yes or enter anything for no: ";
    cin >> userSelectedOption;

    for (loopUserSelectedOption = 0; userSelectedOption < 1000000; loopUserSelectedOption++)
    {
        if (userSelectedOption == 1)
        {
            userSelectedCountryOfChoiceForConversion = userOptionsOfCurrency();
            userAmountInput = userTotalAmountForConversion();
            showConversion(userAmountInput, userSelectedCountryOfChoiceForConversion);

            cout << "\nWould you like to use the Currency Converter? *(1) for yes or enter anything for no: ";
            cin >> userSelectedOption;
        }
        else
        {
            cout << "\nThank you for using the Calculator!";
            cout << "\n         Have A Great Day!";
            cout << "\n            ";

            return 0;
        }
    }

    return 0;
}

// Improvement - Add something that will allow user to have more freedom to use any currency as default instead of only using US dollar
// Improvement - Add a way to store inputs like in a expandable array or pointer (Train cars)
// Improvement - Maybe have a price comparison of multiple user inputs
// Improvement - Have tax rate in countries of interest if available
// Improvement - Maybe have something that allows user to input the item with the price as well for comparison like a house price in US compared to UK

// todo - Finish functions for rounding numbers
// todo - start putting functions in int main()
// todo - Check for spelling errors
// todo - Maybe add a picture of the country flag for more user appeal
// todo -