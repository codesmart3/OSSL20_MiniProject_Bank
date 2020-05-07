# OSSL20_MiniProject_Bank
This program mimics bank account management system. Its main function is to take user’s information as the input and create a bank account as an output. The required fields to generate an account is as follows: Name, Residental Registration Number (RRN), Address, Phone Number, and Password.

##How to Run
Clone the repository to your local directory.
Run the makefile by './make'
Run the program by './main'

## Manual
Once you succesfully execute the program, you will be able to see the menu, which has the list of actions you could do. 
Some of the choices (ex. 1. Add a new member) require you to give inputs. Follow the instruction given by the program carefully.
Example text files are included. 
'8. Read from text file' will read records from "list.txt"
'9. Append Data from text file' will read records from "append.txt"
'4. Save records to text file' will save the records to "output.txt"
You can modify the records in "list.txt" and "append.txt", but make sure you follow the format. 

## Example Scenario
If you are not sure how to add the record, follow below inputs. 
```
1.
Jack
990101-1234567
South Korea, Pohang
010-1234-5678
1234
1234
```
Once you have correctly given the inputs, an account number will be generated and you can check it by selecting '2'.
