#include <string>
#include <iostream>
using namespace std;

int main() {

	string my_string;
	// or
	// std::string my_string;

	// You can also specify an initial value for the string in a constructor :
	// string my_string("starting value");

	// String I/O is easy, as strings are supported by cin.
	cin >> my_string;
	getchar();

	// If you need to read an entire line at a time, you can use getline function
	// and pass in an input stream object(such as cin, to read from standard input,
	// or a stream associated with a file, to read from a file), the string,
	// and a character on which to terminate input. The following code reads a line
	// from standard input(e.g., the keyboard) untill a newline is entered.
	getline(cin, my_string, '\n');

	// String concatenation
	// String can also be assigned to each other or appended together using the + operator
	string my_string1 = "a string";
	string my_string2 = " is this";
	string my_string3 = my_string1 + my_string2;
	// will Output "a string is this"
	cout << my_string3 << endl;

	// Naturally, the += operator is also defined! String concatenation will work as long
	// as either of two strings is a C++ string--the other can be a static string
	// or a char*

	// String Comparisons
	// One of the most confusing parts of using char*s as strings is that comparisons
	// are tricky, requiring a special comparison function, and using tests such as
	// == or < don't mean what you'd expect. Fortunately, for C++ strings, all of the 
	// typical relational operators work as expected to compapre either C++ strings or a 
	// C++ string and either a C string or a static string(i.e., "one in quotes").
	// For instance, the following code does exactly what you would expect, namely,
	// it determines whether an input string is equal to a fixed string :
	string passwd;

	getline(cin, passwd, '\n');
	if (passwd == "xyzzy")
	{
		cout << "Access allowed" << endl;
	}

	// String Length and Accessing Individual Elements
	// To take the length of a string, you can use either the length or size function,
	// which are members of the string class, and which return the number of characters 
	// in a string :
	string my_string10 = "ten chars ";
	int len = my_string10.length(); // or .size();
	cout << "my_string10 size is " << len << endl;

	// Strings, like C strings(char*s), can be indexed numerically. For instance, you
	// could iterate over all of the characters in a string indexing them by number,
	// as though the the string were an array. Note that the use of the length() or
	// size() function is important here because C++ strings are not guaranteed to be
	// null - terminated(by a '\0'). (In fact, you should be able to store bytes with
	// a value of 0 inside a C++ string with no adverse effects. In a C string, this
	// would terminate the string!)
	
	cout << "my_string is ";
	for (unsigned int i = 0; i < my_string.length(); i++)
	{
		
		cout << my_string[i];
	}
	cout << endl;
	// On the other hand, strings are actually sequences, just like any other STL
	// container, so you can use iterators to iterate over the contents of a string.
	
	string::iterator my_iter;
	for (my_iter = my_string.begin(); my_iter != my_string.end(); my_iter++)
	{
		cout << *my_iter;
	}
	cout << endl;

	// Note that my_string.end() is beyond the end of the string, so we don't want
	// to print it, whereas my_string.begin() is at the first character of the string.
	// Incidentally, C++ string iterators are easily invalidated by operators that
	// change the string, so be wary of using them after calling any string function
	// that may modify the string.

	// Searching and Substrings
	// The string class supports simple searching and substring retrieval using the 
	// functions find(), rfind(), and substr(). The find member function takes a string
	// and a position and begins searching the string from the given position for the
	// first occurence of the given string. It returns the position of the first
	// occurence of the string, or a special value, string::npos, that indicates that
	// it did not find the substring.
	// This sample code searches for every instance of the string "cat" in a given string
	// and counts the total number of instances :
	
	string input;

	int cat_appearances = 0;

	getline(cin, input, '\n');

	for (int i = input.find("cat", 0); i != string::npos; i = input.find("cat", i))
	{
		cat_appearances++;
		i++;	// Move past the last discovered instance to avoid finding same string
	}
	cout << cat_appearances << endl;
	
	// Similarly, it would be possible to use rfind in almost the exact same way,
	// except that searching would begin at the very end of the string, rather than
	// the beginning. (String matches would still be from left - to - right -- that is,
	// it wouldn't match "cat" with a string containing "tac".)

	// On the other hand, the substr function can be used to create a new string
	// consisting only of the slice of the string beginning at a given position and of
	// a particular length. For instance, to extract the first ten characters of a
	// string, you might use :
	string my_string2z = "abcdefghijklmnop";
	string first_ten_of_alphabet = my_string2z.substr(0, 10);
	cout << "The first ten letters of the alphabet are " << first_ten_of_alphabet << endl;

	// Modifying String via Splicing or Erasure
	// It's also possible to modify C++ strings to either remove part of a string
	// add in new text. The erase() function takes a position and a character count
	// and removes that many characters starting from the given position. Note that
	// position is zero-indexed, as usual :
	string my_removal = "remove aaa";
	my_removal.erase(7, 3); // erases aaa
	cout << my_removal << endl;

	// To delete an entire string, you could use str.erase(0, str.length());
	// On the other hand, you can also splice one string into another. The member
	// function insert takes a position and a string and inserts that string starting
	// at the given position :
	string my_stringinsert = "ade";
	my_stringinsert.insert(1, "bc");	// my_string is now "abcde"
	cout << my_stringinsert << endl;

	// Copying vs. Sharing
	// Beacuse strings are mutable (they can change what they hold), it is important to
	// know whether strings are copied or share the same memory. (This matters if, for
	// instance, you pass a string to a function that modifies the string--does it also
	// modify the string passed in to the function because they share the same memory
	// storing the actual string ? ) It turns out that, in effect, they are copied,
	// but in practice, it's possible that your implementation may delay copying untill
	// absolutely necessary.As a result, some operations you might expect to be slow,
	// such as passing a large string to a function, may turn out to be faster than expected.
	// Of course, before you rely on this behaviour, you should check your implementation
	// to make sure that it delays; copies when not necessary.

	// Retrieving a c - style string(char*)
	// Sometimes it can be useful to retrieve a char* from a C++ string.This might
	// be necessary for use with a particuler C standard library function that takes a
	// char*, or for compartibility wit older code that expects a char* rather than a
	// C++ string.The string member function c_str() will return the string in the
	// form of.a char* (with a null - terminator).

	string my_string4 = "abcdef";
	cout << strlen(my_string4.c_str()) << endl;
	// Notice that the returned char* is a const value; you should not try to modify
	// this string(it is read - only), add you do not need to free / delete it. Doing so
	// is an error. If you need to modify the char*, you should create a second string
	// and use the strcpy function to duplicate the result of calling c_str().
	// The string class also contains a Date() member function inherited from the
	// basic_string class. This return type for data may not be a valid C-string,
	// because no null character gets appended. The null character '\0' is used as
	// a special character in a C-style to mark the end of the string, but has no
	// just like any other character .

	// std::basic_string
	// Although the string class is useful, it may not suit your needs for
	// internationalization. In particular, if you need support for a different character
	// set or wide characters, you may want something a bit different. For this, you can
	// take advantage of the basic_string template, from which string itself is derived.
	
	return (0);
}