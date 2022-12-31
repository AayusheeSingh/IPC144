/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  :Aayushee Singh
Student ID#:173927211
Email      :asingh1221@myseneca.ca
Section    :NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i,flag=0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("*** New patient record added ***\n");
    }
    printf("\n");
    return;

}



// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)void searchPatientData(const struct Patient patient[], int max);
void searchPatientData(const struct Patient patient[], int max)
{
    int flag = 1;
    int select;
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        select = inputIntRange(0, max);

        if (select == 1)
        {
            searchPatientByPatientNumber(patient, max);
            printf("\n");
            suspend();
        }
        else if (select == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            suspend();
        }
        else
        {
            printf("\n");
            flag = 0;
        }
    } while (flag);
    return;
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i, index = -1, flag = 1;
    for (i = 0; i < max && flag == 1; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
            flag = 0;
        }
    }
    if (index != -1)
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n");
        printf("\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    return;
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int edit_patientNum;
    int index;
    printf("Enter the patient number: ");
    edit_patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(edit_patientNum, patient, max);
    printf("\n");
    if (index != -1)
    {
        menuPatientEdit(&patient[index]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
        printf("\n");
    }
    return;
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int remove_patientNum;
    int index;
    printf("Enter the patient number: ");
    remove_patientNum = inputIntPositive();
    index = findPatientIndexByPatientNum(remove_patientNum, patient, max);
    printf("\n");
    if (index != -1)
    {
        char input;
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        input = inputCharOption("yn");
        if (input == 'y')
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
            printf("\n");

        }
        else
        {
            printf("Operation aborted.\n");
            printf("\n");
        }

    }
    else
    {
        printf("ERROR: Patient record not found!\n");
        printf("\n");
    }
    return;
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int search, index;
    printf("\n");
    printf("Search by patient number: ");
    search = inputIntPositive();
    printf("\n");
    index = findPatientIndexByPatientNum(search, patient, max);

    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***");
        printf("\n");
    }
    return;
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, count = 0;
    char search[PHONE_LEN + 1] = { '\0' };
    printf("\n");
    printf("Search by phone number: ");
    inputCString(search, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(search, patient[i].phone.number) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            count++;
        }
    }
    if (count == 0)
    {
        printf("\n");
        printf("*** No records found ***");
        printf("\n");
    }
    return;
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int max_patientNum = patient[0].patientNumber, maxNum;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > max_patientNum)
        {
            max_patientNum = patient[i].patientNumber;
        }
    }
    maxNum = max_patientNum + 1;
    return maxNum;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    int ans = -1;
    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            ans = i;
            //return i;
        }
    }
    return ans;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    int i;
    char name[NAME_LEN] = { '\0' };
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(name, 1, NAME_LEN);

    for (i = 0; i < strlen(name); i++)
    {
        patient->name[i] = name[i];
    }
    printf("\n");
    inputPhoneData(&patient->phone);
    return;
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int select;
    int flag = 0, i;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    select = inputIntRange(1, 4);
    printf("\n");
    if (select == 1 || select == 2 || select == 3)
    {
        if (select == 1)
        {
            strcpy(phone->description, "CELL");
            
        }
        else  if (select == 2)
        {
            strcpy(phone->description, "HOME");
            
        }
        else if (select == 3)
        {
            strcpy(phone->description, "WORK");
            
        }
        printf("Contact: %s\n", phone->description);
        do
        {
            printf("Number : ");
            inputCString(phone->number, PHONE_LEN, PHONE_LEN);
            for (i = 0; i < PHONE_LEN; i++)
            {
                if ((phone->number[i]<'0' && phone->number[i] > '9'))
                {
                    flag = 1;
                }
            }
        } while (flag == 1);
        printf("\n");
    }
    else
    {
        strcpy(phone->description, "TBD");
        phone->number[0] = 0;
    }
    return;
}
