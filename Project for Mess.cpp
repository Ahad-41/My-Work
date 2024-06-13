#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

char *name[] = {"Rony", "Sadman", "Imran", "Ahad"};
int mealCount[4], totalCost[4];
double finalAmount[4];

int FirstDayCost, WeeksCost, OverAllMeal, OverAllAmount;
double MealRate;

int main()
{
    cout << "   ---------------------\n   Welcome to CSE-Dorbar\n   ---------------------\n\n\n";

    // Read the first day cost individual person
    cout << "First Day Cost (Individual): ";
    cin >> FirstDayCost;

    // For every week
    for(int i = 0; i < 4; i++){
        printf("\n--> %s's Week:\n", name[i]);
        cout << "       -> Total Cost: ";
        cin >> WeeksCost;
        cout << endl;
        totalCost[i] = WeeksCost + FirstDayCost;

        int n = 0;// n = total meals in this week
        for(int j = 0; j < 4; j++){
            printf("       -> %s's Meal: ", name[j]);
            int InputMeal; cin >> InputMeal;
            mealCount[j] += InputMeal;
            n += InputMeal;
        }

        printf("\n   *Total Meal in This Week: %d\n\n\n", n);
    }


    //For calculate over all meal(individual) and over all amount(individual) and print individual total cost
    cout << "\nTotal Cost (Individual) -->\n";
    for(int i = 0; i < 4; i++){
        OverAllMeal += mealCount[i];
        OverAllAmount += totalCost[i];
        printf("       -> %s's: %d Taka\n", name[i], totalCost[i]);
    }
    cout << "       --------------------\n       *Total      " << OverAllAmount <<  " Taka\n";


    //For calculate meal rate and final amount(individual) and also print over all meal individual
    MealRate = OverAllAmount / (OverAllMeal * 1.0);
    cout << "\nTotal Meal (Indivizual) -->\n";
    for(int i = 0; i < 4; i++){
        finalAmount[i] =  totalCost[i] - (MealRate * mealCount[i]);
        printf("       -> %s's: %d\n", name[i], mealCount[i]);
    }
    cout << "       ----------------\n       *Total      " << OverAllMeal << endl;


    //for print meal rate
    printf("\n\n----------------------\n* Meal Rate: %0.2lf Taka\n----------------------\n\n\n", MealRate);


    //for print final total amount of meal
    cout << "\nFinal Total Amount For Meal (Individual): ";
    for(int i = 0; i < 4; i++) printf("\n   -> %s: %0.lf", name[i], MealRate*mealCount[i]);
    cout << "\n\n\n";


    for(int i = 0; i < 4; i++){
        if(finalAmount[i] >= 0) printf("--> %s: (%0.lf) Taka return from mess\n", name[i], finalAmount[i]);
        else printf("--> %s: (%0.lf) Taka give to mess\n", name[i], abs(finalAmount[i]));
    }

    getch();
}
