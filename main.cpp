#include <iostream>
#include <fstream>

using namespace std;


int main() {

	/*
	 * bad() - badbit(1) -  return true if there is an error, for example file have flag ios::in (for reading)
	 * fail() - failbit(4) - returns true if we try to assign string to integer while reading from file or batbit happens
	 *
	 * after bad() was used we have to clear the state. For this we use
	 *
	 * eof() - eofbit(2) - returns true if the file opened to read reaches End Of File
	 *
	 * represented by bytes
	 * 1 - 001
	 * 2 - 010
	 * 4 - 100
	 *
	 * bitwise operator: & | ^
	 *
	 * good() - goodbit(0) - return true if everything is fine(if all above flags are false (they didn't happened)
	 *
	 *
	 * rdstate() - ReaDSTATE - check what state is file
	 *
	 * clear() - which clears the state
	 *
	 *
	 *
	 */

	fstream file;

	file.open("sample.txt", ios::in);

	if(file.is_open())
	{
		string buffer;

	do {

		file >> buffer;
		cout << buffer << endl;
	}while (!file.eof());

		if(file.rdstate() == 2)
		{
			cout << "end of file";
			file.clear();
		} else(cout << "not end of file") << endl;

		cout << endl;
		cout << file.rdstate() << endl;

		/*cout << buffer << endl;
		cout << file.fail() << " <-If 0 is OK if 1 Fail" << endl;
		cout << file.good() << " <- if 0 is OK if 1 Fail" << endl;

*/
	} else
		cout << "Error opening file" << endl;
	return 0;
}
/*

*/
/*
	 * bad() - badbit-  return true if there is an error, for example file have flag ios::in (for reading)
	 * fail() - failbit - returns true if we try to assign string to integer while reading from file or batbit happens
	 *
	 * after bad() was used we have to clear the state. For this we use
	 *
	 * clear() - which clears the state
	 *//*


fstream file;

file.open("sample.txt", ios::in);

if(file.is_open())
{
file << "sample text "; // this will not work as file is only open for reading ios::in
//cout << file.bad(); // in that case this statement will return 1 on error and 0 when no error present

//cout << file.bad();
// so what we could do is create if statement
if(file.bad())
{
cout << "bad shit happened!";
file.clear();
}
file.clear();

string temp;

file >> temp;

cout << temp;

} else
cout << "Error opening file" << endl;*/
