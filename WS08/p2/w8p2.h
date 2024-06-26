/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : Aayushee Singh
Student ID#: 173927211
Email      : asingh1221@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


#define maxProducts 3
#define numOfGrams 64
#define conversionFactor 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNum;
    double productPrice;
    int calories;
    double weight;
};

struct ReportData
{
    int skuNum;
    double productPrice;
    int calories;
    double weightLBS;
    double weightKG;
    int weightG;
    double totalServings;
    double costPerServing;
    double costCalories;
};
   
// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num);



// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProduct);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int index);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* productPrice, const int calories, const double* weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds,double* wtKilo);


// 9. convert lbs: g
int convertLbsG(const double* pounds, int* wtGrams);


// 10. convert lbs: kg / g

void convertLbs(const double* pounds, double* kg, int* grams);



// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double* numOfServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalNumOfServings, double* costPerServing);


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPerCalorie);


// 14. Derive a reporting detail record based on the cat food product data
 struct ReportData calculateReportData(const struct CatFoodInfo catfood);



// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rdata, const int productOption);



// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catfood);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);

