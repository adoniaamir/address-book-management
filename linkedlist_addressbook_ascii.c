/*!
* \mainpage Assignment 2 : LinkedList_AddressBook_Ascii
*
* \section title Linked List - Adoni Address Book Management System - Ascii
*
* \details This is the documentation of <b>Adoni Address Book Management System</b>
* implemented using <b>Linked List</b> on <b>Ascii file (Text File)</b>.
* \n The purpose of this program is exactly the same of the previous
* <b>MAIN "Address Book Management System"</b> documented on <b>24-April-17</b>.
* \n However, the coding is totally different from the previous code.
* \n\n Two new conceptions are implemented in this program. They are:
* \n 1. ASCII (Text File implementation)
* \n 2. Linked List Data Structure.
*
* \subsection functionality Functions:
* Following are features of this program:
* 1. Print the current address book on console window.
* 2. Print user entered file name address book on console window.
* 3. Save current address book as a new file or append with another existing file.
* 4. User makes a new entry of Record to current address book.
* 5. User can search for any specific entry in current address book records.
*
* \author Adoni Aamir <a href="adoniaamir1@gmail.com"> adoniaamir1@gmail.com </a>
* \version 1.0
* \date 18-June-2017*/


#include <stdio.h>
/** \file stdio.h
* \brief Functions used: FILE, fopen(), fseek(), ftell(), fflush(), fclose (), fprintf(), printf(), fscanf(), scanf(),
* getc(), getchar(), rewind(), etc..
*/
#include <stdlib.h>
/** \file stdlib.h
* \brief Functions used:
* exit(), malloc(), free(), sizeof(), etc..
*/
#include <string.h>
/** \file string.h
* \brief Functions used:
* memset(), strncat(), strncpy(), strstr(),  strtok(), etc..
*/
#include <stdbool.h>
/** \file stdbool.h
* \brief Used to check if helping functions run successfully or unsuccessfully.
* If return true, function run successfully
*/


/**
* \section description Description
* \brief Self-referential structure of Linked List
* \details It include 8 informations about user into addressbook and a self-referential pointer.
* \n\n
* The informations are first name,surname, address, city, country, zip code, phone number, mobile number
* of the user.
* \n\n
* The self-referential pointer is a pointer pointing to itself and it carries address of next node into
memory to form a linked list.*/

struct node
{
    char firstName[15]; /**< <b>firstName</b> is a character member of struct node.
                        It is  array which stores the <b>First Name</b> of user.
                        \n It can store <b>15</b> characters at max.
                        */

    char surName[15];  /**< <b>surName</b> is an array member of struct node.
                       It is a character array which stores the <b>Surname</b> into it.
                       \n It can store <b>15</b> characters
                       */

    char streetAddress[60]; /**< <b>streetAddress</b> is an array member of struct node.
                            It is a character array which stores the <b>Street Address</b> into it.
                            \n It can store <b>60</b> characters
                            */

    char city[15]; /**< <b>city</b> is an array member of struct node.
                   It is a character array which stores the <b>City Name</b> into it.
                   \n It can store <b>15</b> characters
                   */

    char country[15]; /**< <b>country</b> is an array member of struct node.
                      It is a character array which stores the <b>Country Name</b> into it.
                      \n It can store <b>15</b> characters
                      */

    char zipCode[7]; /**< <b>zipCode</b> is an array member of struct node.
                     It is a character array which stores the <b>Zip Code</b> into it.
                     \n It can store <b>7</b> characters
                     */

    char phoneNumber[15]; /**< <b>phoneNumber</b> is an array member of struct node.
                          It is a character array which stores the <b>Phone Number</b> into it.
                          \n It can store <b>15</b> characters
                          */

    char mobileNumber[15]; /**< <b>mobileNumber</b> is an array member of struct node.
                           It is a character array which stores the <b>Mobile Number</b> into it.
                           \n It can store <b>15</b> characters
                           */

    struct node *link; /**< <b>struct node *link</b> is a pointer member of struct node which points to itself.
                       It is a link pointer which carries address of the next node.
                       */
};
//Root pointer holds the address of the starting node of the linked list
struct node *root = NULL; /**<This is the head (root) pointer to the first node of linked list and
*is initialized as NULL*/
int len; /**<This is the global variable to count the number of nodes in the linked list*/

/*Function prototypes*/

/* Main Functions
1. Read Current Address Book to console
2. Read other Address Book File from system to console
3. Append Current Address Book to another file
4. Write Current Address Book to new file
5. Write New Data Entry to Current Address Book
6. Get Random Record from Current Address Book
*/
/**
    \title <b> Task 0 Main Function. (Run by operating system)

    \param void No parameter
    \return 0 when successful.
*/
int main(void);
/**
    \title <b> Task 1 Read the Current Address Book to console.

    \param fileName File Name of type Character array
    \return void No return
*/
void ReadCurrentAddressBook (char fileName[]);
/**
    \title <b> Task 2 Reads the User entered File name to console.

    \param void No parameter
    \return void No return
*/
void ReadNewFile (void);
/**
    <b> Task 3 Copy the Current Address Book and append to another file.

    \param fileName File Name of type Character array
    \return void No return
*/
void CopyAndAppendFile (char fileName[]);
/**
    <b> Task 4 Copy the Current Address Book and writes to another file.

    \param fileName File name of Current Address Book.
    \return void No return
*/
void CopyAndWriteFile (char fileName[]);
/**
    <b> Task 5 Write a new entry to the Current Address Book.

    \param fileName File name of Current Address Book
    \return void No return
*/
void WriteNewEntry (char fileName[]);
/**
    <b> Task 6 Searches the Current Address book with user entered string among all struct members.

    \param fileName File name of Current Address Book.
    \return void No return
*/
void GetRandomRecord (char fileName[]);



/*  Helper Functions
Helper function 1. Sorting current address book
Helper function 2. Display Linked list
Helper function 3. Add Node to File
Helper function 4. Delete Node from Linked List
Helper function 5. Length of Linked List
Helper function 6. String Data Entry
Helper function 7. Count all characters in single records
Helper function 8. Count number of records in address book
Helper function 9. Print records of file
Helper function 10. Count total records and total characters in file
Helper function 11. Print records of file and search specific string
Helper function 12. File to file data transfer
Helper function 13. Scan all characters into array from file
Helper function 14. Tokenize records from file
*/
/**
    \title <b> Helper Function 1: sort_current_address_book

    \param fileName File Name of type Character array
    \param filePointer File Pointer pointing to FILE struct
    \return true when successful.
*/
bool sort_current_address_book (char fileName[],
                                FILE *filePointer);
/**
    \title <b> Helper Function 2: display_linked_list

    \param void No parameter
    \return true when successful.
*/
bool display_linked_list (void);
/**
    \title <b> Helper Function 3: add_node_to_file

    \param *fPtr File Pointer pointing to struct FILE
    \param *head Head Pointer pointing to struct Node
    \param *newNode New Pointer pointing to struct Node
    \return true when successful.
*/
bool add_node_to_file (FILE *fPtr, struct node *head, struct node *newNode);
/**
    \title <b> Helper Function 4: delete_node_from_linked_list

    \param void No parameter
    \return true when successful.
*/
bool delete_node_from_linked_list (void);
/**
    \title <b> Helper Function 5: length_of_linked_list

    \param void no parameter
    \return length integer value of number of nodes in linked list
*/
int length_of_linked_list (void);
/**
    \title <b> Helper Function 6: string_data_entry

    \param entry Input from user into character array
    \param size_array Max. size of array
    \return true when successful.
*/
bool string_data_entry (char entry[],unsigned int size_array );
/**
    \title <b> Helper Function 7: count_address_record_character
    \param *fPtr Pointer pointing to struct FILE
    \return integer value
*/
int count_address_record_character (FILE *fPtr);
/**
    \title <b> Helper Function 8: count_address_record_lines

    \param *fPtr File Pointer pointing to FILE struct
    \param recordCharacter Number of characters in 1 Record
    \return integer value
*/
int count_address_record_lines (FILE *fPtr, int recordCharacter);
/**
    \title <b> Helper Function 9: print_records_from_file

    \param *fPtr File pointer pointing to FILE struct
    \param recordSerial Number of Records in File
    \param recordCharacter Number of characters in 1 record
    \return true when successful.
*/
bool print_records_from_file (FILE *fPtr, int recordSerial, int recordCharacter);
/**
    \title <b> Helper Function 10: count_records_characters_in_file

    \param *fPtr File pointer pointing to FILE struct
    \param *character Character pointer pointing to characters in calling function
    \param *record Record pointer pointing to records in calling function
    \return true when successful.
*/
bool count_records_characters_in_file (FILE *fPtr, int *character, int *record);
/**
    \title <b> Helper Function 11: print_records_from_file_search

    \param *fPtr File pointer pointing to FILE struct
    \param recordSerial Number of Records in file
    \param recordCharacter Number of Characters in 1 record
    \return true when successful.
*/
bool print_records_from_file_search (FILE *fPtr, int recordSerial, int recordCharacter);
/**
    \title <b> Helper Function 12: file_to_file_transfer

    \param *fileSend File pointer to Read file
    \param *fileReceive File pointer to write/append file
    \param records Total number of records in record
    \param characters Total number of characters in record
    \return true when successful
*/
bool file_to_file_transfer (FILE *fileSend, FILE *fileReceive, int records, int characters);
/**
    \title <b> Helper Function 13: scan_all_characters_from_file

    \param *fPtr File pointer pointing to FILE struct
    \param *completeFile Pointer pointing to completeFile array in calling function
    \return true when successful.
*/
bool scan_all_characters_from_file (FILE *fPtr, char *completeFile);
/**
    \title <b> Helper Function 14: tokenize_records_from_file

    \param **completeRecords Double pointer pointing to pointer pointing to completeRecords in calling function
    \param *completeFile Pointer pointing to completeFile array in calling function
    \return true when successful
*/
bool tokenize_records_from_file (char **completeRecords, char *completeFile);

/*0. Main function*/
int main()
{
    /*! \details
     <i> <b> Main function</b> which executes all the tasks of this program.
     \n This program is executed by operating system. </i>
     \n\n Function does following:
     \n 1. It does string concatenation of string "random" with its extension ".dat".
     This string is the filename of current address book and is passed via parameter to
     all other functions for processing.
     \n 2. It prints the main menu in while Loop showing all the functions available to user.
     \n 3. It uses switch() function to execute all the tasks as per requirement of the user.
     \n 4. The main menu is printed in loop and switch() functions are also in loop.
     It ends only when user decides to quit by pressing q.</i>
    \n\n Following is the table of available functions in this program and the assigned key
    to execute them.
    \n\n
     <table>
    <caption>User Input & Functions Table</caption>
    <tr><th>User Input <th>Function command
    <tr><td>a <td> Print the current address book to console
    <tr><td>b <td> Load address book from file
    <tr><td>c <td> i. Save current address book to file
    <tr><td>  <td> ii. Append to existing file
    <tr><td>d <td> Make a new entry
    <tr><td>e <td> Search for an entry
    <tr><td>q <td> Quit
    </table>

     */
    /*Variables used in the main function*/
    char currentFileName[15] = "random";
    char extFileName[4] = ".dat";
    char saveToFile[3] = {0};
    char menuChoice;

    /*String concatenation to build filename with the file type*/
    strncat(currentFileName,extFileName,4);

    while(1)
    {
         printf("Note: Uppercase & Lowercase Letters both are accepted\n\n"
                "WELCOME TO ADONI'S ADDRESS BOOK MANAGEMENT SYSTEM\n\t\tMAIN MENU\n\n"
               "Please enter your selection\n\n"
               "a) Print the current address book to console\n"
               "b) Load address book from file\n"
               "c) Save current address book to file\n"
               "\ti) Append\n"
               "\tii) New File\n"
               "d) Make a new entry\n"
               "e) Search for an entry\n"
               "q) Quit\n"
               "? ");

        /*Inputting choice of selection from menu*/
        fflush(stdin);
        menuChoice = getchar();

        /*Inputting choice into switch control to navigate to user purposes (functions)*/
        switch (menuChoice)
        {
            case 'a': case 'A': ReadCurrentAddressBook(currentFileName);
                                break;

            case 'b': case 'B': ReadNewFile();
                                break;

            case 'c': case 'C': printf("\nSave current address book to file.\n"
                                       "Choose:\n"
                                       "i) Append to existing file\n"
                                       "ii) New File\n? ");

                                if (string_data_entry(saveToFile,3) == true)
                                {
                                    printf("\nString Data Entry run successful.\n\n");
                                }
                                else
                                {
                                    printf("\nUnsuccessful. String Data Entry.\n\n");
                                }

                                if (strcmp(saveToFile,"i") == 0)
                                {
                                    CopyAndAppendFile(currentFileName);
                                    break;
                                }

                                else if (strcmp(saveToFile,"ii") == 0)
                                {
                                    CopyAndWriteFile(currentFileName);
                                    break;
                                }
                                else
                                {
                                    printf("\nInvalid. Select i or ii\n\n");
                                    break;
                                }

            case 'd': case 'D': WriteNewEntry(currentFileName);
                                break;

            case 'e': case 'E': GetRandomRecord(currentFileName);
                                break;

            case 'q': case 'Q': break;

            default: printf("\nInvalid! choose option between ""a-e"" or ""q"" to quit\n\n");
                     break;
        }

        /*Break while loop if user enters 'q' or 'Q'*/
        if (menuChoice == 'q' || menuChoice == 'Q')
            break;
    }
    /*If function executes successfully, return value of integer 0*/
    return 0;

}

/*1. Read Current Address Book to console*/
void ReadCurrentAddressBook (char fileName[])
{
    /*! \details
        <i>This <b> ReadCurrentAddressBook function </b> reads data from the Current Address Book file.
        \n The parameter of this function is the filename of Current Address Book.
        \n This function is called from the main function.</i>
        \n\n The function does following:
        \n 1. It opens the file having fileName using fopen()function and checks whether file opens successfully
        or not.
        \n 2. It counts the total number of characters in one address record using
        <i> count_address_record_character (filePointer) </i>.
        \n 3. It counts the total number of address Records in a file using
        <i>count_address_record_lines (filePointer, recordCharacter)</i>
        \n 4. It prints the total address records from the file using
        <i>print_records_from_file(filePointer,recordSerial,recordCharacter).</i>.
        \n 5. It asks user to sort the address Records according to first name alphabetically
        using function <i>sort_current_address_book(fileName,filePointer)</i>.
        \n 6. The file is closed using fclose() function.

        \note 1. The data entries inside the text file are separated by '|' pipesign symbol which is hidden
        to console window for better view.

        \n Format of the data displayed on the screen is: \n
        <table>
        <caption>Read data Format</caption>
        <tr><th>First Name <th>Surname <th>Street Address <th>City <th>Country
        <th>Zip code <th> Phone Number <th>Mobile Number
        <tr><td>... <td>... <td>... <td>... <td>...
        <td>... <td> ... <td>...
        </table>

    */

    FILE *filePointer; //->File pointer
    int recordSerial = 0; //->no is number of records in addressbook
    int recordCharacter = 0; //->1st address record characters counter
    char selectSort;

    filePointer = fopen(fileName,"r");

    if (filePointer == NULL)
    {
        printf("Empty File!\n\n");
        return;
    }

    else
    {
        printf("\nCurrent Address book File: %s\n",fileName);

        recordCharacter = count_address_record_character (filePointer);

        recordSerial = count_address_record_lines (filePointer, recordCharacter);

        printf("Number of records (%s)= %d\n",fileName,recordSerial);

        if (print_records_from_file(filePointer,recordSerial,recordCharacter) == true)
        {
            printf("\nPrint Records from file run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. Print Records from file.\n\n");
        }

        /*Run sorting function to sort the data according to first name*/
        printf("\nNote: Both Uppercase & Lowercase Letters are accepted\n\n"
               "Sort Data alphabetically with first name:\nY-Yes\nN-No\n? ");
        fflush(stdin);
        selectSort = getchar();

        if(selectSort == 'Y' || selectSort == 'y')
        {
            if (sort_current_address_book(fileName,filePointer) == true)
            {
                printf("\nSort Function run successful.\n\n");
            }
            else
            {
                printf("\nUnsuccessful. Sort function.\n\n");
            }
        }
        else
        {
            fclose(filePointer);
        }
        /*Closing the file with file pointer after file is read to console*/
    }
}

/*2. Read other Address Book File from system to console*/
void ReadNewFile (void)
{
    /*! \details
        <i>This <b> ReadNewFile function </b> reads data from the user entered file.
        \n There is no parameter of this function and so it is void.
        \n This function is called from the main function.</i>
        \n\n The function does following:
        \n 1. It prints the message to the user to enter desired filename.
        The user enters the filename (including extension) and the filename is read using fopen() function.
        \n 2. It checks whether file opens successfully or not.
        \n 3. It counts the total number of characters in one address record using
        <i> count_address_record_character (filePointer) </i>.
        \n 4. It counts the total number of address Records in a file using
        <i>count_address_record_lines (filePointer, recordCharacter)</i>
        \n 5. It prints the total address records from the file using
        <i>print_records_from_file(filePointer,recordSerial,recordCharacter).</i>.
        \n 6. It asks user to sort the address Records according to first name alphabetically
        using function <i>sort_current_address_book(fileName,filePointer)</i>.
        \n 7. The file is closed using fclose() function.

        \note 1. The fileName to be opened must be having the same structure as selected for the
        Current Address Book.
        \n 2. The data entries inside the text file are separated by '|' pipesign symbol which is hidden
        to console window for better view.

        \n Format of the data displayed on the screen is: \n
        <table>
        <caption>Read data Format</caption>
        <tr><th>First Name <th>Surname <th>Street Address <th>City <th>Country
        <th>Zip code <th> Phone Number <th>Mobile Number
        <tr><td>... <td>... <td>... <td>... <td>...
        <td>... <td> ... <td>...
        </table>

    */

    /*Variables used in this function*/
    FILE *filePointer;
    char fileName[20] = {0};
    char selectSort;
    int recordSerial = 0; //->no is number of records in addressbook
    int recordCharacter = 0; //->1st address record characters counter

    printf("\nNote: Please include extension\n\nEnter desired filename to open: ");
    if (string_data_entry(fileName,20) == true)
    {
        printf("\nString Data Entry run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. String Data Entry.\n\n");
    }


    /*Opening the file with file pointer*/
    filePointer = fopen(fileName,"r");

    /*Checking if file opens successfully*/
    if (filePointer == NULL)
    {
        printf("\nFile could not be opened or file is empty!\n\n");
        return;
    }

    else
    {
        printf("\nNew Address book File: %s\n",fileName);

        recordCharacter = count_address_record_character (filePointer);

        recordSerial = count_address_record_lines (filePointer, recordCharacter);

        printf("Number of records (%s)= %d\n",fileName,recordSerial);

        if (print_records_from_file(filePointer,recordSerial,recordCharacter) == true)
        {
            printf("\nPrint Records from file run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. Print Records from file.\n\n");
        }

        /*Run sorting function to sort the data according to first name*/
        printf("\nNote: Both Uppercase & Lowercase Letters are accepted\n\n"
               "Sort Data alphabetically with first name:\nY-Yes\nN-No\n? ");
        fflush(stdin);
        selectSort = getchar();

        if(selectSort == 'Y' || selectSort == 'y')
        {
            if (sort_current_address_book(fileName,filePointer) == true)
            {
                printf("\nSort Function run successful.\n\n");
            }
            else
            {
                printf("\nUnsuccessful. Sort function.\n\n");
            }
        }
        else
        {
            fclose(filePointer);
        }
        /*Closing the file with file pointer after file is read to console*/
    }
}

/*3. Append Current Address Book to another file*/
void CopyAndAppendFile (char fileName[])
{
    /*! \details
        <i>This <b> CopyAndAppendFile function </b> reads data from the Current Address Book file
        and at the same time Appends the data to the user entered file.
        \n The parameter of this function is the filename of Current Address Book.
        \n This function is called from the main function.</i>
        \n\n The function does following:
        \n 1. It asks the user to entered desired filename (including extension) to which append the data
        of current address book to.
        \n 2. Append file name is opened using fopen()function and checks whether file opens successfully
        or not. "a" is entered into fopen() function to open the file in append mode.
        \n 3. It counts the total number of characters and total number of records in the file using
        <i> count_records_characters_in_file(filePointerRead, &characterInFile, &recordsInFile) </i> function.
        \n 4. Total number of characters in record is calculated as follows
            1. <b> Total number of characters in record  = characterInRecord</b>
            2. <b> Total number of characters in file = characterInFile</b>
            3. <b> Total number of records in file= recordsInFile</b>

            \f{eqnarray*}{
            characterInRecord &=& \frac{characterInFile}{recordsInFile}
            \f}

        \n 5. <i>file_to_file_transfer(filePointerRead, filePointerAppend, recordsInFile, characterInRecord)
        </i>function is used to simultaneously read 1 record at a time from current address book and append
        it to the user entered address book.
        \n 6. Both File pointers are closed using fclose() function.
        \n 7. A success message after successfully appending is displayed on console.

        \note 1. The user has to include the extension of the file with the filename.
    */

    printf("\nAppending current address book to existing file.\n\n");

    /*Variables for this function*/
    FILE *filePointerRead,*filePointerAppend;
    char append_fileName[15] = {0};
    int characterInFile = 0;
    int recordsInFile = 0;
    int characterInRecord = 0;

    printf("Note: Please include extension\n\nEnter File ""filename"" to append with Current Address Book: ");
    if (string_data_entry(append_fileName,15) == true)
    {
        printf("\nString Data Entry run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. String Data Entry.\n\n");
    }

    /*File pointers for reading from file and writing to file*/
    filePointerRead = fopen(fileName,"r");
    filePointerAppend = fopen(append_fileName,"a");

    if (filePointerRead == NULL)
    {
        printf("Error! File cannot be opened!\n");
        return;
    }
    if (filePointerAppend == NULL)
    {
        printf("Error! File cannot be opened!\n");
        return;
    }

    else
    {
        if (count_records_characters_in_file(filePointerRead, &characterInFile, &recordsInFile) == true)
        {
            printf("\nCount Records and Characters in file run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. Count Records and Characters in file.\n\n");
        }

        characterInRecord = characterInFile/recordsInFile;
        printf("\n1) No. of characters in file (%s) = %d"
               "\n2) No. of characters in one record = %d"
               "\n3) No. of lines = %d\n\n",
                fileName,characterInFile,characterInRecord,recordsInFile);

        if (file_to_file_transfer(filePointerRead, filePointerAppend, recordsInFile, characterInRecord) == true)
        {
            printf("\nFile to file data transfer run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. File to file data transfer.\n\n");
        }

    }

    fclose(filePointerRead);
    fclose(filePointerAppend);

    printf("\n(%s) File appended into (%s) successfully.\n\n",fileName,append_fileName);
}

/*4. Write Current Address Book to new file*/
void CopyAndWriteFile (char fileName[])
{
    /*! \details
        <i>This <b> CopyAndWriteFile function </b> reads data from the Current Address Book file
        and at the same time Writes the data to the user entered file.
        \n The parameter of this function is the filename of Current Address Book.
        \n This function is called from the main function.</i>
        \n\n The function does following:
        \n 1. It asks the user to entered desired filename (including extension) to which write the data
        of current address book to.
        \n 2. Write file name is opened using fopen() function and checks whether file opens successfully
        or not. "w" is entered into fopen() function to open the file in write mode.
        \n 3. It counts the total number of characters and total number of records in the file using
        <i> count_records_characters_in_file(filePointerRead, &characterInFile, &recordsInFile) </i> function.
        \n 4. Total number of characters in record is calculated as follows
            1. <b> Total number of characters in record  = characterInRecord</b>
            2. <b> Total number of characters in file = characterInFile</b>
            3. <b> Total number of records in file= recordsInFile</b>

            \f{eqnarray*}{
            characterInRecord &=& \frac{characterInFile}{recordsInFile}
            \f}

        \n 5. <i>file_to_file_transfer(filePointerRead, filePointerWrite, recordsInFile, characterInRecord)
        </i>function is used to simultaneously read 1 record at a time from current address book and write
        it to the user entered address book.
        \n 6. Both File pointers are closed using fclose() function.
        \n 7. A success message after successfully appending is displayed on console.

        \note 1. The user has to include the extension of the file with the filename.
    */
    printf("\nAppending current address book to existing file.\n\n");

    /*Variables for this function*/
    FILE *filePointerRead,*filePointerWrite;
    char write_fileName[15] = {0};
    int i_Vertical;
    int characterInFile = 0;
    int recordsInFile = 0;
    int characterInRecord = 0;
    int readCharactersFromFile;

    printf("Note: Please include extension\n\nEnter File ""filename"" to write the Current Address Book: ");
    if (string_data_entry(write_fileName,15) == true)
    {
        printf("\nString Data Entry run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. String Data Entry.\n\n");
    }

    /*File pointers for reading from file and writing to file*/
    filePointerRead = fopen(fileName,"r");
    filePointerWrite = fopen(write_fileName,"w");

    if (filePointerRead == NULL)
    {
        printf("Error! File cannot be opened!\n");
        exit(1);
    }

    if (filePointerWrite == NULL)
    {
        printf("Error! File cannot be opened!\n");
        exit(1);
    }

    else
    {
        if (count_records_characters_in_file(filePointerRead, &characterInFile, &recordsInFile) == true)
        {
            printf("\nCount Records and Characters in file run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. Count Records and Characters in file.\n\n");
        }

        characterInRecord = characterInFile/recordsInFile;
        printf("\n1) No. of characters in file (%s) = %d"
               "\n2) No. of characters in one record = %d"
               "\n3) No. of records = %d\n\n",
                fileName,characterInFile,characterInRecord,recordsInFile);

        if (file_to_file_transfer(filePointerRead, filePointerWrite, recordsInFile, characterInRecord) == true)
        {
            printf("\nFile to file data transfer run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. File to file data transfer.\n\n");
        }

    }

    fclose(filePointerRead);
    fclose(filePointerWrite);

    printf("\n(%s) File appended into (%s) successfully.\n\n",fileName,write_fileName);
}

/*5. Write New Data Entry to Current Address Book*/
void WriteNewEntry (char fileName[])
{
    /** \details
        <i>This <b> WriteNewEntry function </b> writes first name,surname,address etc using Linked List Data
        Structure and appends it to the Current Address Book file.
        \n A pointer root (head) is global declared pointer pointing to struct node which is supposed to be
        pointing to the first node.
        \n The pointer temp is declared in function pointing to struct node to access dynamic memory.
        \n A linked list is accessed via a root (head) pointer which carries address of first node.
        Subsequent nodes are accessed via the link pointer which carries address of next node.
        \n The last node contains NULL in its link pointer which means it is the last node.
        and at the same time Writes the data to the user entered file.
        \n The parameter of this function is the filename of Current Address Book.
        \n This function is called from the main function.</i>

        \n\n The function does following:
        \n 1. Opens the current address book file using fopen() into append mode and checks whether the
        file opens successfully or not.
        \n 2. Dynamic memory is allocated with the sizeof(struct node) using malloc(). The malloc() converts
        the value using typecasting into struct node * to temp variable.
        \n 3. The temp variable holds the memory address of temp dynamic memory allocated.
        \n 4. User is asked for first name, surname, address etc subsequently. The strings are stored into
        struct members using <i>string_data_entry(temp->firstName,sizeof(temp->firstName)) </i> function.
        \n 5. The size of each struct member i-e first name, street address is mentioned for user.
        \n 5. The link pointer in temp memory allocated is assigned NULL, considering it as last node.
        \n 6. In the <i> add_node_to_file(root, temp) </i> function, temp value is assigned to root variable.
        This is because the root variable value is NULL and takes the value of temp variable. The values are
        printed into the text file using fprintf() function and data entries are separated by '|' pipe sign
        symbol.
        \n 7. User will be asked if he wants to continue adding new data entry to file. If he selects yes,
        the next node will be assigned at end of linked list. The link pointer of previously last node will
        point to the NewNode.

        \n\n The data values are separated using '|' pipe sign symbol to avoid conflict while reading data
        from file. Following is the structure of data values entered into address book file:
        <table>
        <caption>Write data Format</caption>
        <tr><th>First Name|<th>Surname|<th>Street Address|<th>City|<th>Country|
        <th>Zip code|<th> Phone Number|<th>Mobile Number|
        <tr><td>... <td>... <td>... <td>... <td>...
        <td>... <td> ... <td>...
        </table>

        \note 1. The data values written to the text file are separated by '|' pipe sign symbol to avoid
        conflict while reading data from the address book file.
        \n 2. The temp pointing to structure members writes its data values to the file. The linked list is
        formed after setting link pointer as NULL. The next node will be added to end of linked list forming
        links but if user doesn't continues entering data, the dynamic memory is deallocated using free and
        the link list is removed from memory.

    */

    FILE *filePointer;
    char newEntry;
    struct node *temp;

    filePointer = fopen(fileName,"a");

    if (filePointer == NULL)
    {
        printf("Error! Cannot make an Entry.\n");
        return;
    }

    else
    {
        printf("\nOpened Address book File: %s\n",fileName);
        while(1)
        {
            temp = (struct node*) malloc(sizeof(struct node));

            if (temp == NULL)
            {
                return;
            }

            else
            {
                printf("\n\nNote: First Name max. size = 15.\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter First name?\n");
                if (string_data_entry(temp->firstName,sizeof(temp->firstName)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: Surname max. size = 15\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter Surname?\n");
                if (string_data_entry(temp->surName,sizeof(temp->surName)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: Street Address max. size = 60\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter Street Address (with commas)?\n");
                if (string_data_entry(temp->streetAddress,sizeof(temp->streetAddress)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: City max. size = 15\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter City?\n");
                if (string_data_entry(temp->city,sizeof(temp->city)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: Country max. size = 15\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "Enter Country?\n");
                if (string_data_entry(temp->country,sizeof(temp->country)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: Zip Code max. size = 7\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter Zipcode?\n");
                if (string_data_entry(temp->zipCode,sizeof(temp->zipCode)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: Phone Number max. size = 15\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter Phone number?\n");
                if (string_data_entry(temp->phoneNumber,sizeof(temp->phoneNumber)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                printf("\n\nNote: Mobile Number max. size = 15\n"
                       "Limitation: Last character in array will be replaced with NULL to properly use "
                       "fgets().\n"
                       "User can enter alphanumeric data\n"
                       "\nEnter Mobile number?\n");
                if (string_data_entry(temp->mobileNumber,sizeof(temp->mobileNumber)) == true)
                {
                    printf("\nString Data Entry run successful.\n\n");
                }
                else
                {
                    printf("\nUnsuccessful. String Data Entry.\n\n");
                }

                temp->link = NULL;

                if (add_node_to_file(filePointer,root, temp) == true)
                {
                    printf("\nAdd Node to File Function run successful.\n\n");
                }

                else
                {
                    printf("\nUnsuccessful. Add Node to File.\n\n");
                }

                printf("CONTINUE\nN-NO\n? ");
                fflush(stdin);
                newEntry = getchar();

                if (newEntry == 'N' || newEntry == 'n')
                    break;
            }
        }

        free(temp);
    }

    fclose(filePointer);
}

/*6. Get Random Record from Current Address Book*/
void GetRandomRecord (char fileName[])
{
    /** \details
        <i>This <b> GetRandomRecord function </b> searches the user entered search string in first name,surname,
        address etc of records.
        \n The flow of this function is similar to <b> CopyAndAppend function </b> and <b> CopyAndAppend
        function </b> except that it searches the search string before printing the records.
        \n The parameter of this function is the filename of Current Address Book.
        \n This function is called from the main function.</i>

        \n\n The function does following:
        \n 1. Opens the current address book file using fopen() into read mode and checks whether the
        file opens successfully or not.
        \n 2. It counts the total number of characters and total number of records in the file using
        <i> count_records_characters_in_file(filePointerRead, &characterInFile, &recordsInFile) </i> function.
        \n 3. Total number of characters in record is calculated as follows
            1. <b> Total number of characters in record  = characterInRecord</b>
            2. <b> Total number of characters in file = characterInFile</b>
            3. <b> Total number of records in file= recordsInFile</b>

            \f{eqnarray*}{
            characterInRecord &=& \frac{characterInFile}{recordsInFile}
            \f}
        \n 4. It prints the address records from the file which matches the user entered search string using
        <i>print_records_from_file_search(filePointer,recordSerial,recordCharacter).</i>.
        \n 5. fclose() function closes the file.

        \note 1. The searching method is case sensitive. Therefore, it is important for the user to know
        whether to use Uppercase Letter or Lowercase Letter in search string.

    */

    /*Variables used for this function*/
    FILE *filePointer;
    int characterInFile =0;
    int recordsInFile = 0;
    int characterInRecord = 0;

    filePointer = fopen(fileName,"r");

    if (filePointer == NULL)
    {
        printf("Empty File!\n\n");
        return;
    }

    else
    {
        printf("\nOpened Address book File: %s\n",fileName);
        if (count_records_characters_in_file(filePointer, &characterInFile, &recordsInFile) == true)
        {
            printf("\nCount Records and Characters in file run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. Count Records and Characters in file.\n\n");
        }

        characterInRecord = characterInFile / recordsInFile;
        printf("\n1) No. of characters in file (%s) = %d"
               "\n2) No. of characters in one record = %d"
               "\n3) No. of lines = %d\n\n",
                fileName,characterInFile,characterInRecord,recordsInFile);

        if (print_records_from_file_search(filePointer,recordsInFile,characterInRecord) == true)
        {
            printf("\nPrint Records from file run successful.\n\n");
        }
        else
        {
            printf("\nUnsuccessful. Print Records from file.\n\n");
        }
    }

    fclose(filePointer);
}


/*Helper Functions*/

/*Helper function 1. Sorting current address book*/
bool sort_current_address_book (char fileName[], FILE *filePointer)
{
    /** \details
        <i>This <b> sort_current_address_book function </b> sorts the Records by first name alphabetically.
        \n This function use 3 helper functions, sorts and print the Records.
        \n The parameter of this function is the filename of Current Address Book and filePointer.
        \n This function is called from the main function.</i>

        \n\n The function does following:
        \n 1. It counts the total number of characters and total number of records in the file using
        <i> count_records_characters_in_file(filePointerRead, &characterInFile, &recordsInFile) </i> function.
        \n 2. Total number of characters in record is calculated as follows
            1. <b> Total number of characters in record  = characterInRecord</b>
            2. <b> Total number of characters in file = characterInFile</b>
            3. <b> Total number of records in file= recordsInFile</b>

            \f{eqnarray*}{
            Total number of characters in record &=& \frac{Total number of characters in file}
            {Total number of records in file}
            \f}
        \n 3. <i>scan_all_characters_from_file (filePointer,completeFile)</i> function is used to get character
        by character from the address book file and copy it into completeFile array.
        \n 4. <i>tokenize_records_from_file(&completeRecords,completeFile)</i> function is used to tokenize
        Records from the completeFile array using '\n' character and copy it into completeRecords array.
        \n 5. completeRecords array is sorted using strncmp() and strncpy() function if the 2nd record
        first name is having less value than 1st record first name.
        \n 6. Sorted completeRecords array is printed using for() loop and function returns true after success.

        \note 1. The sorting is operated only with comparing First Name (15 characters max).
        The maximum characters of struct member is displayed to user in <i>WriteNewEntry</i> function.
    */

    printf("\nFile: %s",fileName);

    /*Variables used for this function*/
    int j_horizontal = 0, compare_Record, sorting_round;
    int characterInRecord = 0; //maximum characters in 1 record
    int characterInFile = 0; //count characters in file
    int recordsInFile = 0; //count lines after '\n' character

    /*Calculating size of one record and number of records*/
    fseek(filePointer,0,SEEK_SET);

    if (count_records_characters_in_file (filePointer, &characterInFile, &recordsInFile) == true)
    {
        printf("\nCount Records and Characters in file run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. Count Records and Characters in file.\n\n");
    }

    characterInRecord = characterInFile/recordsInFile;

    printf("\n1) No. of characters in file = %d"
           "\n2) No. of characters in one record = %d"
           "\n3) No. of records = %d\n\n",
            characterInFile,characterInRecord,recordsInFile);

    char *completeRecords[recordsInFile]; //Hold records in the array
    memset( completeRecords, '0', recordsInFile );

    char completeFile[characterInFile]; //Hold total characters in the file
    memset( completeFile, '0', characterInFile );

    char tempRecord[characterInRecord]; //Hold 1 record characters during sorting
    memset( tempRecord, '0', characterInRecord );

    /*Seeking position to beginning of file*/
    fseek(filePointer,0,SEEK_SET);

    if (scan_all_characters_from_file (filePointer,completeFile) == true)
    {
        printf("\nScan all Characters from file run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. Scan all Characters from file.\n\n");
    }

    if (tokenize_records_from_file(&completeRecords,completeFile) == true)
    {
        printf("\nTokenize records from file run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. Tokenize records from file.\n\n");
    }

    /*Sort the datastring array alphabetically*/
    for(sorting_round=0; sorting_round < recordsInFile - 1; sorting_round++)
    {
        for(j_horizontal=0; j_horizontal < recordsInFile-1; j_horizontal++)
        {
            //Compare i with i+1 in the Record
            compare_Record = strncmp(completeRecords[j_horizontal],completeRecords[j_horizontal+1],15);

            if(compare_Record > 0)
            {
                strncpy(tempRecord,completeRecords[j_horizontal],characterInRecord);
                strncpy(completeRecords[j_horizontal],completeRecords[j_horizontal+1],characterInRecord);
                strncpy(completeRecords[j_horizontal+1],tempRecord,characterInRecord);
            }
        }
    }

    /*Put column headings to console window to display data entries*/
    printf( "\n%-15s %-15s %-60s %-15s %-15s %-6s %-15s %-15s\n\n",
            "First-Name","Surname","Street Address","City",
            "Country", "Zip", "Phone Number" , "Mobile Number"  );

    for(j_horizontal=0; j_horizontal < recordsInFile; j_horizontal++)
    {
        printf("%s\n",completeRecords[j_horizontal]);
    }

    printf("\n\n");

    return true;
}

/*Helper function 2. Display Linked list*/
bool display_linked_list (void)
{
    /** \details
        <i>This <b> display_linked_list function </b> displays the Linked List.
        \n 1. This function is NOT INCLUDED in this program and not being used.
        \n 2. This function was used only for testing Linked Lists before writing the program
        \n 3. This function displays the Linked List nodes allocated on dynamic memory on console.
        The dynamic memory is deallocated using free().</i>

        \n\n The function does following:
        \n 1. A temp pointer pointing to struct node is declared and carries the value of root (head pointer
        to linked list.
        \n 2. If the temp value is NULL meaning no node. It displays "List is empty".
        \n 3. Otherwise, if temp value is not NULL the Records are displayed accordingly using
        while (temp!=NULL) condition.
        \n 4. The temp pointer takes the value of next link node and displays the
        record.
        \n 5. When temp == NULL value, the while (temp!=NULL) breaks and all the Records are displayed on the console
        \n 6. It returns true after successful execution.

        \note 1. This function is NOT USED in the current program. This function is considered a debugging function
        for Linked List Display.
    */

    struct node *temp;
    temp = root;

    if(temp == NULL)
    {
        printf("\nList is empty\n\n");
    }

    else
    {
        /*Printing the column headings on console for data to be read from file*/
        printf( "\n%-15s %-15s %-60s %-15s %-15s %-6s %-15s %-15s\n\n",
               "First-Name","Surname","Street Address","City",
               "Country", "Zip", "Phone Number" , "Mobile Number"  );

        while(temp != NULL)
        {
            printf("%-15s %-15s %-60s %-15s %-15s %-6s %-15s %-15s\n",
                    temp->firstName,temp->surName,temp->streetAddress,temp->city,
                    temp->country,temp->zipCode,temp->phoneNumber,temp->mobileNumber);

            temp = temp->link;
        }
        printf("\n\n");
    }

    return true;
}

/*Helper function 3. Add Node to File*/
bool add_node_to_file (FILE *fPtr, struct node *head, struct node *newNode)
{
    /** \details
        <i>This <b> add_node_to_file function </b> adds the node of Linked List into Current Address Book file.
        \n 1. This function has two parameters of head pointer and newNode pointer.
        \n 2. This function copy the head pointer value to global variable root pointer. It happens if the root
        is NULL before meaning no nodes.</i>

        \n\n The function does following:
        \n 1. Parameter head pointer pointing to struct node copies its value into root (global variable)
        if the head value is NULL meaning no node.
        \n 2. Otherwise, temp2 pointer pointing to struct is declared and copies the value of head into it.
        \n 3. Temp2 pointer is used to point to last node and copies newNode pointer value into NULL pointer
        value of last node.
        \n 4. It means nodes are appended into the Linked List.
        \n 5. The values are printed into the text file using fprintf() function.

        \n The data values are separated using '|' pipe sign symbol to avoid conflict while reading data
        from file. \n Following is the structure of data values entered into address book file:
        <table>
        <caption>Write data Format</caption>
        <tr><th>First Name|<th>Surname|<th>Street Address|<th>City|<th>Country|
        <th>Zip code|<th> Phone Number|<th>Mobile Number|
        <tr><td>... <td>... <td>... <td>... <td>...
        <td>... <td> ... <td>...
        </table>

        \n 6. It returns true after successful execution.

        \note 1. The data values written to the text file are separated by '|' pipe sign symbol to avoid
        conflict while reading data from the address book file.

    */

    if (head == NULL)
    {
        head = newNode;
        root = head;
    }

    else
    {
        struct node *temp2;
        temp2 = head;

        while(temp2->link != NULL)
        {
            temp2 = temp2->link;
        }
        temp2->link = newNode;
    }

    fprintf(fPtr,"%-15s|%-15s|%-60s|%-15s|%-15s|%-6s|%-15s|%-15s\n",
            newNode->firstName,newNode->surName,newNode->streetAddress,newNode->city,
            newNode->country,newNode->zipCode,newNode->mobileNumber,newNode->phoneNumber);

    return true;
}

/*Helper function 4. Delete Node from Linked List*/
bool delete_node_from_linked_list (void)
{
    /** \details
        <i>This <b> delete_node_from_linked_list function </b> delete the node from the Linked List.
        \n 1. This function is NOT INCLUDED in this program and not being used because of requirement.
        \n 2. This function was used only for testing Linked Lists before writing the program
        \n 3. This function is used to delete node from linked list allocated dynamically.
        \n 4. However, once the function is executed, the allocated dynamic memory is deallocated using
        free.</i>

        \n\n The function does following 3 steps:
        1. It asks the user to enter the location of the node he wants to delete. Location is checked with
        the global variable len whether location is greater than total no. of records.
        2. If location is 1, temp pointer copy the value of root (head pointer to linked list)
        and root holds the link value of 2nd node (next node). temp pointer pointing to link is null and free
        the temp pointer. This way root is start pointing to next node.
        3. Otherwise, two pointers to struct node are declared. The first pointer points to root (head to
        linked list). The while loop works under the condition if the i_index counter is less than the value
        of location given by user. When the condition is turned false, i_index has counted the number of nodes
        and first pointer is having pointer value pointing to previous node than given location. The last
        pointer holds the pointer value of node pointing to given location by user. first to link copy the value
        of last to link so to keep hold of linked list. The last to link is equal to NULL and last pointer is
        free().

        \note 1. This function is NOT USED in the current program. This function is considered a debugging
        function for deleting Linked List nodes on dynamic memory.
    */

    struct node *temp;
    int loc;

    printf("Note: Location is integer value\n\nEnter location to delete: \n");
    scanf("%d", &loc);

    if (loc > len)
    {
        printf("Invalid\n");
    }

    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }

    else
    {
        struct node *first = root, *last;
        int i_index = 1;

        while (i_index<loc-1)
        {
            first = first->link;
            i_index++;
        }

        last = first->link;
        first->link = last->link;
        last->link = NULL;
        free(last);
    }

    return true;
}

/*Helper function 5. Length of Linked List*/
int length_of_linked_list (void)
{
    /** \details
        <i>This <b> length_of_linked_list </b> counts the number of nodes in Linked List and return the value.
        \n 1. This function is NOT INCLUDED in this program and not being used.
        \n 2. This function was used only for testing Linked Lists before writing the final program.</i>

        \n\n The function does following steps:
        \n 1. A count variable is used as a counter in this function and is initialized with value 0. A temp
        pointer is declared in function which contains value of root (head pointer to linked list) to point
        to all nodes in the Linked List.
        \n 2. A condition is set in while loop that while the temp pointing to link is not equal to Null. The
        count variable is counting number of nodes and the temp pointer is pointing to next node until reaches
        NULL the end of list.
        \n 3. The count variable holds the value of number of nodes in Linked List when temp is equal to NULL.
        The value is returned back to calling function.

        \note 1. This function is NOT USED in the current program. This function is considered a debugging
        function for counting number of Linked List nodes on dynamic memory.
    */

    struct node *temp;
    int count = 0;
    temp = root;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

/*Helper function 6. String Data Entry*/
bool string_data_entry (char entry[],unsigned int size_array )
{
    /** \details
        <i>This <b> string_data_entry </b> adds characters into string entry.
        The function used in this helper function is fgets(). It also make sure that string don't include
        more characters than size_array.

        \n\n The function does following steps:
        \n 1. stdin (standard input stream) is flushed out using fflush() function to avoid any garbage value.
        \n 2. Function fgets() is used to input characters to string entry with max size of array.
        \n 3. Function strlen() is used to get the total length of string and initialize the last character in
        array to NULL '\0' manually.
        \n 4. Function returns true upon successful execution.

        \note 1. Last character in fgets() function contains '\n' next line character. Therefore, it is
        important to initialize the last character in array to NULL '\0' manually.
    */

//    int i;

    fflush(stdin);
    fgets(entry, size_array, stdin);
    entry[strlen(entry)- 1] = '\0';

//    for (i=0; entry[i] != '\0'; i++)
//    {
//        printf("%c#",entry[i]);
//    }
//
//    printf("String length: %d\n",strlen(entry));

    return true;
}

/*Helper function 7. Count all characters in single records*/
int count_address_record_character (FILE *fPtr)
{
    /** \details
        <i>This <b> count_address_record_character </b> function counts total characters into 1 address Record.
        It returns the number of characters in 1 record. </i>

        \n\n The function does following steps:
        \n 1. A single dummy Record array is initialized as an character array with value 0.
        \n 2. The position in File is set to the beginning of file. Function fgets() is used to copy
        characters into dummy Record according to its maximum size given.
        \n 3. For loop is used to count the number of characters into one Record.

        \note 1. It is considered that the Records are ended with NULL '\0' character.
    */
    char dummyRecord[1][200] = {0}; //->Array to hold 1st address record
    int singleRecordCharacter = 0;
    int j_index;

    fseek(fPtr,0,SEEK_SET);
    fgets(dummyRecord[0],sizeof(dummyRecord[0]),fPtr);

    for(j_index=0; dummyRecord[0][j_index] != '\0'; j_index++)
    {
        singleRecordCharacter++;
    }

    return singleRecordCharacter;
}

/*Helper function 8. Count number of records in address book*/
int count_address_record_lines (FILE *fPtr, int recordCharacter)
{
    /** \details
        <i>This <b> count_address_record_lines </b> is a function which counts total number of Records.
        It returns the number of Records in file. </i>

        \n\n The function does following steps:
        \n 1. File is positioned to the end of file. The size of file is known using ftell() function.
        \n 2. Number of Records is calculated by dividing the File Size with number of characters in 1 Record
        calculated from <i>count_address_record_character</i>.
        Number of Records is calculated as follows
            1. <b> Total number of Records  = recordSerial</b>
            2. <b> File size = size_File</b>
            3. <b> Total number of characters in record= recordCharacter</b>

            \f{eqnarray*}{
            Total number of Records &=& \frac{File size}{Total number of characters in record}
            \f}

    */
    int size_File;
    int recordSerial;

    fseek(fPtr,0,SEEK_END);
    size_File=ftell(fPtr);
    recordSerial=size_File/recordCharacter;

    return recordSerial;
}

/*Helper function 9. Print records of file*/
bool print_records_from_file (FILE *fPtr, int recordSerial, int recordCharacter)
{
    /** \details
        <i>This <b> print_records_from_file </b> function prints all Records from the file.
        It returns true after success. </i>

        \n\n The function does following steps:
        \n 1. allRecords is a double subscripted array holding value of number of Records and number of
        characters. The 2D array is initialized with value 0.
        \n 2. File is positioned to beginning of file. A notification to the user is given for special cases.
        For loop is used to print all Records using 2 indexes i & j. During printing of Records, the '|' pipe
        sign symbol is replaced with space for better display.
        \n 3. After the allRecords array is printed, the function returns true meaning success.

        \note 1. Data entries inside the text file are separated by '|' pipe sign symbol. However, it is replaced
            with space symbol during printing of records on console.

    */
        char allRecords[recordSerial][recordCharacter];
        memset(allRecords, '0', sizeof(allRecords));
        int i_index,j_index;

        fseek(fPtr,0,SEEK_SET);
        printf("\n\nNote: Data entries inside the text file are separated "
               "by '|' pipe sign symbol."
               "However, it is replaced with space symbol during printing "
               "of records on console.\n\n");

        printf( "\n%-15s %-15s %-60s %-15s %-15s %-6s %-15s %-15s \n\n",
                "First-Name","Surname","Street Address","City",
                "Country", "Zip", "Phone Number" , "Mobile Number"  );

        for(i_index=0; i_index<recordSerial; i_index++)
        {
            fgets(allRecords[i_index],recordCharacter+1,fPtr);

            for(j_index=0; allRecords[i_index][j_index] != '\0'; j_index++)
            {
                if (allRecords[i_index][j_index]== '|')
                {
                    allRecords[i_index][j_index] = ' ';
                }
            }
            printf("%s",allRecords[i_index]);
        }
        printf("\n");

        return true;
}

/*Helper function 10. Count total records and total characters in file*/
bool count_records_characters_in_file (FILE *fPtr, int *character, int *record)
{
    /** \details
        <i>This <b> count_records_characters_in_file </b> function calculates number of characters and number
        of Records in file. The characters and records are parameters to this function as pointers.
        It returns true after success. </i>

        \n\n The function does following steps:
        \n 1. In the While loop, getc() is used to get characters from the file until it reaches EOF.
        \n 2. During the While loop, characters are counted into characterInFile and records are counted into
        recordsInFile when getc() gets a '\n' next line character.
        \n 3. Total characters in file and Total records in file are passed back to calling function via
        pointers.
        \n 4. The function returns true after success.

        \note 1. Records are separated with '\n' next line character and also '\0' character. It can be
        recognized after understanding <i>count_records_characters_in_file</i> and
        <i>print_records_from_file</i>.
        \n 2. It isn't possible to return two values from the function. Therefore, setting up two pointer
        variables as parameters to function can send back two variable values.

    */

    int readCharactersFromFile = 0;
    int characterInFile = 0;
    int recordsInFile = 0;

    /*Calculate the size of structure and number of records in address book file*/
    while (( readCharactersFromFile = getc( fPtr ) ) != EOF)
    {
         characterInFile++;
         if (readCharactersFromFile == '\n')
            recordsInFile++;
    }

    *character = characterInFile;
    *record = recordsInFile;

    return true;
}

/*Helper function 11. Print records of file and search specific string*/
bool print_records_from_file_search (FILE *fPtr, int recordSerial, int recordCharacter)
{
    /** \details
        <i>This <b> print_records_from_file_search </b> function prints all Records from the file if Record
        match with the search string.
        It returns true after success. </i>

        \n\n The function does following steps:
        \n 1. allRecords is a double subscripted array holding value of number of Records and number of
        characters. The 2D array is initialized with value 0. The search string array is initialized with
        value 0 and is given max. size of 60 characters. It is because the largest character array in
        struct members is street address.
        \n 2. User is asked to enter the search string value. The value is entered into search string using
        <i>string_data_entry</i> function.
        \n 3. File is positioned to the beginning of file. For loop is used to print Records if the Records
        matches with the search string using 2 indexes i & j .
        During printing of Records, the '|' pipe sign symbol is replaced with space for better display.
        \n 3. After the matched Records are printed, the function returns true meaning success.

        \note 1. Data entries inside the text file are separated by '|' pipe sign symbol. However, it is
        replaced with space symbol during printing of records on console.
        \n 2. The maximum size of search string is 60 characters. It is given because the largest character
        array in Records can be street address which is 60 characters.

    */

    char allRecords[recordSerial][recordCharacter];
    memset(allRecords, '0', sizeof(allRecords));
    char inputSearchEntry[60] = {0};
    int i_index,j_index;

    printf("Note: Uppercase/Lowercase sensitive search entry.\n\nPlease enter your desired search entry?\n");
    if (string_data_entry(inputSearchEntry,60) == true)
    {
        printf("\nString Data Entry run successful.\n\n");
    }
    else
    {
        printf("\nUnsuccessful. String Data Entry.\n\n");
    }

    printf( "\n%-15s %-15s %-60s %-15s %-15s %-6s %-15s %-15s\n\n",
           "First-Name","Surname","Street Address","City",
           "Country", "Zip", "Phone Number" , "Mobile Number"  );

    fseek(fPtr,0,SEEK_SET);

    for(i_index=0; i_index<recordSerial; i_index++)
    {
        fgets(allRecords[i_index],recordCharacter+1,fPtr);
        for(j_index=0; allRecords[i_index][j_index] != '\0'; j_index++)
        {
            if (allRecords[i_index][j_index]== '|')
            {
                allRecords[i_index][j_index] = ' ';
            }
        }
        if(strstr(allRecords[i_index],inputSearchEntry) != 0)
        {
            printf("%s",allRecords[i_index]);
        }
    }

    printf("\n\n");

    return true;
}

/*Helper function 12. File to file data transfer*/
bool file_to_file_transfer (FILE *fileSend, FILE *fileReceive, int records, int characters)
{
    /** \details
        <i>This <b> file_to_file_transfer </b> function transfers the data from one file to another.
        The main Tasks implemented in this program are Append and Write to files. This is decided upon
        opening of file using fopen(). It returns true after success. </i>

        \n\n The function does following steps:
        \n 1. It has the allRecords 2D array initialized with value 0.
        \n 2. File Pointers of File to Read and File to write are both set to beginning of file using fseek().
        \n 3. Total number of Records in the file to read are copied into the file to append/write using for
        loop. The maximum number of Records in file is the limit in the for loop.
        \n 4. fgets() and fprintf() functions are used to transfer information from File to read to file to
        append/write.
        \n 4. The function returns true after success.

        \note 1. This function is ok to use for both functions <i>CopyAndWriteFile</i> and
        <i>CopyAndAppendFile</i>.
        This is because selection of append/write into file is decided before in fopen() function.

    */
    int i_index;
    char allRecords[records][characters];
    memset(allRecords, '0', sizeof(allRecords));

    /*Reading data from current address book and writing data to other address book*/

    fseek(fileSend,0,SEEK_SET);
    fseek(fileReceive,0,SEEK_SET);

    for (i_index=0; i_index <records; i_index++)
    {
        fgets(allRecords[i_index],characters+1,fileSend);
        fprintf(fileReceive,"%s",allRecords[i_index]);
    }

    return true;
}

/*Helper function 13. Scan all characters into array from file*/
bool scan_all_characters_from_file (FILE *fPtr, char *completeFile)
{
    /** \details
        <i>This <b> scan_all_characters_from_file </b> function scans every character from file and copies
        it into completeFile array. The parameters are file pointer and pointer to completeFile array.
        It returns true after success. </i>

        \n\n The function does following steps:
        \n 1. In the While loop, getc() is used to get characters from the file until it reaches EOF.
        \n 2. During the While loop, two steps are being done. '|' pipeline symbol is replaced with
        the space character and j index is incremented and copies each character from file into
        completeFile array.
        \n 3. While() loop stops when EOF (End of File) is reached.
        \n 4. The function returns true after success.

        \note 1. completeFile array is pointed into this function. Therefore, it is possible to retrieve
        the values of completeFile array from the calling function without using address '&' operator. But
        if it is double pointer then it is required to use '&' operator.
    */

    int j_horizontal=0;
    int readCharactersFromFile=0;

    while (( readCharactersFromFile = getc( fPtr) ) != EOF)
    {
        if(readCharactersFromFile == '|')
        {
            readCharactersFromFile = ' ';
        }
        completeFile[j_horizontal++] = readCharactersFromFile;
    }

    return true;
}

/*Helper function 14. Tokenize records from file*/
bool tokenize_records_from_file (char **completeRecords, char *completeFile)
{
    /** \details
        <i>This <b> tokenize_records_from_file </b> function tokenize the completeFile array with '\n'
        new line character. The completeRecords is double pointer to this function and completeFile is
        single pointer as parameters to this function. It returns true after success. </i>

        \n\n The function does following steps:
        \n 1. token_Record is a pointer which points to strings tokenized from completeFile using strtok()
        function.
        \n 2. token_Records are broken with '\n' newline characters and are copied into completeRecords array
        under the condition of while() loop that token_Records is not equal to NULL.
        \n 3. completeRecords and completeFile are passed back to calling function via double pointers and
        single pointer.
        \n 4. The function returns true after success.

        \note 1. completeFile array is pointed into this function. Therefore, it is possible to retrieve
        the values of completeFile array from the calling function without using address '&' operator. But
        if it is double pointer like completeRecords array then it is required to use '&' operator.

    */

    /*Tokenizing the records in array with next line terminator*/
    int j_horizontal=0;
    char *token_Record;

    token_Record = strtok( completeFile, "\n" ); //file contents = completeFile

    while ( token_Record != NULL )
    {
        completeRecords[j_horizontal++] = token_Record;
        token_Record = strtok( NULL, "\n" );
    }

    return true;
}

/*END*/
