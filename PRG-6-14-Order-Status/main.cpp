//
//  main.cpp
//  PRG-6-14-Order-Status
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  The Middletown Wholesale Copper Wire Company sells spools of copper wiring for
//  $100 each. Write a program that displays the status of an order. The program should
//  have a function that asks for the following data:
//
//  * The number of spools ordered.
//  * The number of spools in stock.
//  * Whether there are special shipping and handling charges.
//
//  (Shipping and handling is normally $10 per spool.) If there are special charges, the
//  program should ask for the special charges per spool.
//  The gathered data should be passed as arguments to another function that displays:
//
//  * The number of spools ready to ship from current stock
//  * The number of spools on backorder (the number ordered is greater than what is
//    in stock)
//  * Subtotal of the portion ready to ship (the number of spools ready to ship times
//    $100)
//  * Total shipping and handling charges on the portion ready to ship
//  * Total of the order ready to ship
//
//  The shipping and handling parameter in the second function should have the default
//  argument 10.00.
//
//  Input Validation: Do not accept numbers less than 1 for spools ordered. Do not accept
//  a number less than 0 for spools in stock or shipping and handling charges.

#include <iostream>
#include <iomanip>

using namespace std;

void inputData(int &, int &, float &);
void calculateFunction(int &, int &, float &);
void validateInt(int &);
void validateFlt(float &);

int main()
{
    int intSpoolsOrdered,
        intSpoolsStock;
    
    float fltCostShippingPerUnitModifier;
    
    inputData(intSpoolsOrdered, intSpoolsStock, fltCostShippingPerUnitModifier);
    
    // Debug to test if input data modified the variables correctly
    //    cout << intSpoolsOrdered << endl
    //         << intSpoolsStock << endl
    //         << fltCostShippingPerUnitModifier;
    
    calculateFunction(intSpoolsOrdered, intSpoolsStock, fltCostShippingPerUnitModifier);
    
    return 0;
}

void inputData(int &refSpools, int &refStock, float &refCharges)
{
    cout << "Please enter the number of spools\n"
         << "you would like to order:\n";
    cin >> refSpools;
    
    validateInt(refSpools);
    
    cout << "Please enter the number of spools\n"
         << "that are currently in stock:\n";
    cin >> refStock;
    
    validateInt(refStock);
    
    cout << "Please enter any additional cost\n"
         << "for shipping each spool:\n";
    cin >> refCharges;
    
    validateFlt(refCharges);
}

// No default value here
void calculateFunction(int &refSpools, int &refStock, float &refCharges)
{
    int intSpoolsReadyToShip,
        intSpoolsOnBackorder;
    
    const float FLT_BASE_SHIPPING_COST = 10.0f;
    
    float fltShippingCostFinal,
          fltSubtotalReadyToShip,
          fltSubtotalReadyToShipShipping,
          fltSubtotalTotal;
    
    fltShippingCostFinal = FLT_BASE_SHIPPING_COST + refCharges;
    
    if(refStock >= refSpools)
    {
        intSpoolsReadyToShip = refStock - refSpools;
        intSpoolsOnBackorder = 0;
    }
    else
    {
        intSpoolsReadyToShip = refStock;
        intSpoolsOnBackorder = refSpools - refStock;
    }
    
    fltSubtotalReadyToShip = intSpoolsReadyToShip * 100.0f;
    
    fltSubtotalReadyToShipShipping = intSpoolsReadyToShip * fltShippingCostFinal;
    
    fltSubtotalTotal = fltSubtotalReadyToShip + fltSubtotalReadyToShipShipping;
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "With a total of " << refSpools << " requested\n"
         << "and with a stock of " << refStock << endl
         << "you will have a backorder of " << intSpoolsOnBackorder << endl
         << "and a shipping cost of $" << fltSubtotalReadyToShipShipping << endl
         << "from a per unit shipping cost of $" << fltShippingCostFinal << endl
         << " ($" << FLT_BASE_SHIPPING_COST << " + $" << refCharges << ")" << endl
         << "and the total cost of the order will be $" << fltSubtotalTotal << endl;
}

void validateInt(int &refInt)
{
    while(!cin || refInt < 0 || refInt > 1000)
    {
        cout << "Please enter a valid number:\n";
        cin.clear();
        cin.ignore();
        cin >> refInt;
    }
}

void validateFlt(float &refFlt)
{
    while(!cin || refFlt < -10.0f || refFlt > 10.0f)
    {
        cout << "Please enter a valid number:\n";
        cin.clear();
        cin.ignore();
        cin >> refFlt;
    }
}

