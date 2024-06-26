/*
*****************************************************************************
                          Workshop - #8 (P1)
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
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNum;
    double productPrice;
    int calories;
    double weight;
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
    void displayCatFoodData(const int skuNum,const double* productPrice,const int calories,const double* weight);



// 7. Logic entry point
    void start(void);


