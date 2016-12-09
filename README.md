# Trie-implementation

This is a program to implement trie trees. I have implemented them to create a phone database
for faster access. Also, I have also implemented a prediction algorithm which predicts the number/name
 to be entered when the user is typing the number/name. I have used the "stty raw/cooked" function of
 linux to obtain the input before pressing enter.

 The syntax for the query is as follows
 	1. insert //inserts a contact
   2. search/delete phonebook over name/number like <name/number> //here, '_' can be inserted if the user forgot 
 				// the character and all possible values will be returned
 	3. search/delete phonebook over name/number dynn // dynamically predicts the name/number which is to be 
 				//entered before entering it
 	4. import from <filename> imports data from a file
 	5. export to <filename> exports data to a file
