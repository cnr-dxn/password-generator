# Password Cracker

A C++ based password generator based upon a multitude of researched intelligence and data points in order to make it as efficient and intelligent as possible. 

**Strategic Hash Generations**: This algorithm utilizes a research-based strategy to generate the most likely hashed passwords in the order in which they would be most successful. Doing so results in a much more successful output than a brute force method.

**Maximized Efficiency**: In order to further increase the efficiency of the algorithm, when generating possible strings, it pulls from both a library of the top-used passwords, as well as a dictionary of the top 10,000 words found in passwords. 

## How to run this application:

This is run as a C++ application, and thus to allow correct access to existing credientials to the necessary executables, run the following code:
```
chmod +rwx xec
```
Then, ensure that the password desired is entered in the xec executable (as to provide the generator a 
password to crack):
```
echo compiling...
g++ -o completelyNew passwordGenerator.cpp
echo removing output...
rm output.txt
echo touching output...
touch output.txt
echo running...
./completelyNew **<DESIRED PASSWORD>**

```
This will change the permissions to run the executable:
```
./xec
```
Then just simply watch the output to the screen to see how many iterations it takes to crack the provided password, and open **output.txt** to see the generated passwords. 

## File Structure

**passwordGenerator.cpp** is where all the main functionality is written.

**wordAssets.txt** is a list of all of the stored dictionary words the algorithm uses

**symbolAssets2.txt** is a list of all of the symbols sites allow in passwords

