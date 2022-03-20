#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("inData.txt");
    outFile.open("outData.txt");
    //first line of data
    string firstname, lastname, dept;
    inFile >> firstname >> lastname >> dept;
    outFile << "Name: " << firstname << " " << lastname << ", Department: " << dept << endl;
    //second line of Data
    double salary, bonus, tax;
    inFile >> salary >> bonus >> tax;
    outFile << fixed << showpoint << setprecision(2);
    outFile << "Monthly Gross Salary: $" << salary << ", Monthly Bonus: " << bonus << "%, Taxes: " << tax << "%" << endl;
    double bonus_amount, new_salary, tax_amount;
    bonus_amount = salary * bonus / 100;
    new_salary = salary + bonus_amount;
    tax_amount = new_salary * tax / 100;
    new_salary = new_salary - tax_amount;
    outFile << "Paycheck: $" << new_salary << endl << endl;
    // Third line of data
    double distance, time;
    inFile >> distance >> time;
    outFile << "Distance Traveled: " << distance << "Mile, Traveling Time: " << time << endl;
    outFile << "Average Speed: " << distance / time << " mile per hour" << endl << endl;
    // Fourth line of data
    double amtsold, cost;
    inFile >> amtsold >> cost;
    outFile << "Number of coffee cups Sold: " << amtsold << " ,Cost: $" << cost << "per cup" << endl;
    outFile << "Sale amount = $" << amtsold * cost << endl << endl;

    inFile.close();
    outFile.close();
    cout<< endl;
    cout<< endl;

 /* ------------------------------------------------- Part 2 of the HomeWork ------------------------------------------------------- */
    // Open 2 dir's to read/write too!
    inFile.open("Ch3_Ex5Data.txt");
    outFile.open("Ch3_Ex5Output.txt");

    // set decimal point to just 2 decimal places
    outFile << setprecision(2) << showpoint << fixed;

    // for-loop; repeat 3 times
    for(int i = 0; i < 3; i++){
        string firstName, lastName; // redeclare to initial empty state for variables 3x's
        double currentSalary, percentageIncrease,updatedSalary; // redeclare to initial state empty for variables 3x's

        inFile >> firstName >> lastName >> currentSalary >> percentageIncrease; // read from open file Ex5ata.txt
        updatedSalary = ((currentSalary * percentageIncrease) /100) + currentSalary; // generic percent incr. formula
        outFile << firstName <<" "<< lastName << " " << updatedSalary << "\n"; // write to new file called Ex5Output
    }

    // Close for formalities
    inFile.close();
    outFile.close();
    return 0;
}
