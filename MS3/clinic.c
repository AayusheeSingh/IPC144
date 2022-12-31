/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
int AppointCounter = 0;



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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, flag = 0;
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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data)
{
    int index, i;
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
        //printf("%d", index);
        if (index != -1)
        {
            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
    }
    printf("\n");
    return;
}



// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i, end, index;

    struct Date date = { 0 };
    //date.year = year;
    //date.month = month;
    //date.day = day;


    printf("Year        : ");
    date.year = inputIntPositive();
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    printf("Day (1-");
    if (date.month == 2)
    {

        if (((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))
        {
            end = 29;
        }
        else
        {
            end = 28;
        }
    }
    else if (date.month == 2 || date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        end = 30;
    }
    else
    {
        end = 31;
    }
    printf("%d)  : ", end);
    date.day = inputIntRange(1, end);
    printf("\n");


    displayScheduleTableHeader(&date, 0);


    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
        {
            index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
            if (index != -1)
            {
                displayScheduleData(&data->patients[index], &data->appointments[i], 0);
            }
        }
    }
    printf("\n");
    return;
}


// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    struct Appointment* test = { 0 };
    test = appointments;
    int i, index = -1, flag = 1, flag1 = 1, patNumber, end;
    struct Date date = { 0 };
    struct Time time = { 0 };
    int number;
    for (i = 0; i < maxAppointments && flag == 1; i++)
    {

        if (appointments[i].patientNumber < 1)
        {
            index = i;
            flag = 0;
        }
    }

    if (index != -1)
    {
        printf("Patient Number: ");
        patNumber = inputIntPositive();
        do
        {
            printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);
            printf("Day (1-");
            if (date.month == 2)
            {
                if (((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))
                {
                    end = 29;
                }
                else
                {
                    end = 28;
                }
            }
            else if (date.month == 2 || date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
            {
                end = 30;
            }
            else
            {
                end = 31;
            }
            printf("%d)  : ", end);
            date.day = inputIntRange(1, end);



            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);


            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);


            number = 0;
            for (i = 0; i < maxAppointments; i++)
            {
                if (test[i].date.year == date.year)
                {
                    if (test[i].date.month == date.month)
                    {
                        if (test[i].date.day == date.day)
                        {
                            if (test[i].time.hour == time.hour)
                            {
                                if (test[i].time.min == time.min)
                                {
                                    number = 1;
                                }
                            }
                        }
                    }
                }
            }


            if (number == 1)
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else
            {
                do
                {
                    if (((time.hour >= START_HOUR) && (time.hour <= END_HOUR)) && ((time.min == 0) || (time.min == MIN_INTERVAL)))
                    {
                        //if ((time.hour == END_HOUR) && (time.min != MIN_INTERVAL && time.min==0))
                        if ((time.hour == END_HOUR) && (time.min == MIN_INTERVAL))
                        {
                            printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                            printf("Hour (0-23)  : ");
                            time.hour = inputIntRange(0, 23);
                            printf("Minute (0-59): ");
                            time.min = inputIntRange(0, 59);

                        }
                        else
                        {
                            flag1 = 0;
                        }
                    }
                    else
                    {
                        printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                        printf("Hour (0-23)  : ");
                        time.hour = inputIntRange(0, 23);
                        printf("Minute (0-59): ");
                        time.min = inputIntRange(0, 59);
                    }
                } while (flag1);
            }
        } while (number);
        printf("\n");
        printf("*** Appointment scheduled! ***\n");
        printf("\n");
        appointments[index].patientNumber = patNumber;
        appointments[index].date = date;
        appointments[index].time = time;        
        sortAppointment(appointments, maxPatient);
    }
    else
    {
        printf("ERROR: listing is FULL!\n\n");
    }
    return;
}




void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    struct Date date = { 0 };
    char input;
    int patNumber, index, end, i, flag = 1, newIndex=-1;
    printf("Patient Number: ");
    patNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patNumber, patients, maxPatient);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        printf("Year        : ");
        date.year = inputIntPositive();
        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);
        printf("Day (1-");
        if (date.month == 2)
        {
            if (((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))
            {
                end = 29;
            }
            else
            {
                end = 28;
            }
        }
        else if (date.month == 2 || date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
        {
            end = 30;
        }
        else
        {
            end = 31;
        }
        printf("%d)  : ", end);
        date.day = inputIntRange(1, end);

        printf("\n");
        displayPatientData(&patients[index], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        input = inputCharOption("yn");

        if (input == 'y')
        {
            for (i = 0; i < maxAppointments && flag == 1; i++)
            {
                if (appointments[i].patientNumber == patNumber && appointments[i].date.day == date.day && appointments[i].date.month == date.month && appointments[i].date.year == date.year)
                {
                    newIndex = i;                    
                    flag = 0;
                }
            }
            appointments[newIndex].patientNumber = 0;           
            printf("\nAppointment record has been removed!\n\n");           
        }
    }
    return;
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
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
                if ((phone->number[i] < '0' && phone->number[i] > '9'))
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



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = NULL;
    int  i = 0,value=1;
    //int val = 1;
    fp = fopen(datafile, "r");
    
    if (fp != NULL)
    {        
        while(fp!=NULL && i< max && value>0)        
        {
            value = fscanf(fp, "%d|%[^|]|%[^|]|%[^|\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
            i++;
        }
        fclose(fp);
    }
   
    if (i != max)
    {
        i--;
    }
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* fp = NULL;
    int val = 1, i = 0;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        while (fp != NULL && i < max && val>0)

        {
            val = fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            i++;
        }
        fclose(fp);
    }
  
    if (i != max)
    {
        i--;
    }

    sortAppointment(appoints, i);
    return i;
}

int lowestAppointment(struct Appointment appoints[], int number)
{

    int i, index = 0;
    int minYear = 99999;
    int minMonth = 12;
    int minDay = 31;
    int minHour = 24;
    int minMin = 59;

    for (i = 0; i < number; i++)
    {
        if (appoints[i].date.year < minYear && appoints[i].patientNumber != 0)
        {
            minYear = appoints[i].date.year;
        }
    }

    for (i = 0; i < number; i++)
    {
        if (appoints[i].date.year == minYear && appoints[i].date.month < minMonth && appoints[i].patientNumber != 0)
        {
            minMonth = appoints[i].date.month;
        }
    }

    for (i = 0; i < number; i++)
    {
        if (appoints[i].date.year == minYear && appoints[i].date.month == minMonth && appoints[i].date.day < minDay && appoints[i].patientNumber != 0)
        {
            minDay = appoints[i].date.day;
        }
    }

    for (i = 0; i < number; i++)
    {
        if (appoints[i].date.year == minYear && appoints[i].date.month == minMonth && appoints[i].date.day == minDay &&
            appoints[i].time.hour < minHour && appoints[i].patientNumber != 0)
        {
            minHour = appoints[i].time.hour;
        }
    }


    for (i = 0; i < number; i++)
    {
        if (appoints[i].date.year == minYear && appoints[i].date.month == minMonth && appoints[i].date.day == minDay
            && appoints[i].time.hour == minHour && appoints[i].time.min < minMin && appoints[i].patientNumber != 0)
        {
            minMin = appoints[i].time.min;
            index = i;
        }
    }

    return index;
}



void sortAppointment(struct Appointment appoints[], int number)
{
    int i, index;
    struct Appointment temp[50] = { {0} };



    for (i = 0; i < number; i++)
    {
        index = lowestAppointment(appoints, number);
        temp[i].patientNumber = appoints[index].patientNumber;
        temp[i].date.year = appoints[index].date.year;
        temp[i].date.month = appoints[index].date.month;
        temp[i].date.day = appoints[index].date.day;
        temp[i].time.hour = appoints[index].time.hour;
        temp[i].time.min = appoints[index].time.min;
        appoints[index].patientNumber = 0;
    }

    for (i = 0; i < number; i++)
    {
        appoints[i].patientNumber = temp[i].patientNumber;
        appoints[i].date.year = temp[i].date.year;
        appoints[i].date.month = temp[i].date.month;
        appoints[i].date.day = temp[i].date.day;
        appoints[i].time.hour = temp[i].time.hour;
        appoints[i].time.min = temp[i].time.min;
    }
    return;
}

















































