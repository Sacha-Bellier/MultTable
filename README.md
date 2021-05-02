
# MultTable

## Short term goals
Same result as the python script presented in this littlt article (made by Sébastien Dumortier) : https://apmep-toulouse.eu/la-beaute-des-mathematiques-se-cache-sous-la-table/

It determine all different paterns of the multiplication tables for number of modulo m form 0 to a specified number. 

## Getting Started
Start by cloning the repository with `git clone `

Generate the exectutable by using the `make` commande on the working directory

Use can use it by running the executable which is located in the bin directory:
- Windows : `.\MultTable.exe 200 false` or `.\MultTable 200 false`
- Linux   : `./MultTable.out 200 false` or `./MultTable 200 false`

### Parameters
There are two parameters to specify
- The first is the number to reach, in this case from 0 to 200
- The second is if you want that the program show lines that are equals, also if this parameter is set to false the program will run on multithreading which is much faster 