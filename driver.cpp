#include <iostream>
#include <fstream>
#include<iomanip>
#include<windows.h>
#include "Tree.h"
using namespace std;

int main()
{
	Tree t1;
	int selector;
	int option;
	ifstream inFile_1;
	inFile_1.open("data.txt");
	t1.readFromFile(inFile_1);
	system("color 80");
	cout << setw(70) << " ----------------------\n";
	cout << setw(70) << " Binary Tree Dictionary " << endl;
	cout << setw(70) << " ----------------------\n";
	do
	{
		system("cls");
		cout << setw(70) << " Binary Tree Dictionary " << endl;
		cout << " Please select your option\n";
		cout << " 1- Admin\n 2- User\n 3- Exit\n";
		cin >> selector;
		system("cls");
		
		cout << setw(70) << " Binary Tree Dictionary " << endl;
		
		if (selector == 1)
		{
			string fileName = "control.txt";
			bool log = t1.logIn(fileName);
			if (log)
			{
				do
				{
					system("cls");
					cout << " Please Select Your Option\n";
					cout << " 1- Add a Word\n";
					cout << " 2- Edit a Word\n";
					cout << " 3- Remove a Word\n";
					cout << " 4- Search a Word\n";
					cout << " 5- Set BookMark\n";
					cout << " 6- Show BookMarked\n";
					cout << " 7- To Edit Synonym\n";
					cout << " 8- To show all words\n";
					cout << " 9- To Exit the Menu\n";
					cin >> option;
					switch (option)
					{
					case 1:
					{
						string word;
						string syn;
						string mean;

						system("cls");
					
						cout << setw(70) << " Binary Tree Dictionary " << endl;
						
						cout << " Please Enter the Word :  ";
						cin >> word;
						cout << " Please Enter the Synonym of the Word :  ";
						cin >> syn;
						cout << " Please Enter the Meaning of the Word :  ";
						cin >> mean;
						t1.insert(word, syn, mean); 
						ofstream outFile_2;
						outFile_2.open("data.txt");
						t1.writeToFile(outFile_2);
						system("pause>nul");
						system("cls");
						break;
					}
					case 2:
					{
						system("cls");
			
						cout << setw(70) << " Binary Tree Dictionary " << endl;
		
						string existWord, newWord;
						cout << " Please Enter the Word you Want to edit :  ";
						cin >> existWord;
						cout << " Please Enter the new Word :  ";
						cin >> newWord;
						t1.editWord(existWord, newWord); 
						system("pause>nul");
						break;
					}
					case 3:
					{
						system("cls");

						cout << setw(70) << " Binary Tree Dictionary " << endl;
						
						string word;
						cout << " Please Enter the word you want to Remove :  ";
						cin >> word;
						t1.removeWord(word);
						system("pause>nul");
						break;
					}
					case 4:
					{
						system("cls");

						cout << setw(70) << " Binary Tree Dictionary " << endl;

						string word;
						cout << "\n Please Enter the Word you want to Search :  ";
						cin >> word;
						Node* ptr = t1.search(word);
						ptr->printWord();
						system("pause>nul");
						break;
					}
					case 5:
					{
						system("cls");
			
						cout << setw(70) << " Binary Tree Dictionary " << endl;
				
						string word;
						cout << "\n Please enter the word you want to bookmark :  ";
						cin >> word;
						t1.setBookMark(word);
						system("pause>nul");
						break;
					}
					case 6:
					{
						system("cls");
						cout << setw(70) << " Binary Tree Dictionary " << endl;
						cout << " The following Words have been Bookmarked : \n";
						t1.printMarked();
						system("pause>nul");
						break;
					}

					case 7:
					{
						system("cls");
						cout << setw(70) << " Binary Tree Dictionary " << endl;
						string existWord, newSynonym;
						cout << " Please Enter the Word whose synonym you Want to edit :  ";
						cin >> existWord;
						cout << " Please Enter the new Synonym :  ";
						cin >> newSynonym;
						t1.editWord(existWord, newSynonym);
						system("pause>nul");
						break;
					}
					case 8:
					{
						system("cls");
						cout << "\nALL WORDS: \n";
						t1.printInfixOrder();
						system("pause>nul");
						break;
					}
					}

				} while (option != 9);
			}
		}


		else if (selector == 2)
		{
			int option;
			system("cls");
			cout << "\n";
			cout << setw(70) << " Binary Tree Dictionary " << endl;
			cout << "\n";
			t1.wordOfTheDay();
			cout << "\n\n Please Select your Option\n";
			cout << " 1- Search a Word\n";
			cout << " 2- Set BookMark\n";
			cout << " 3- Show BookMarked\n";
			cout << " 4- To exit\n";
			cin >> option;
			switch (option)
			{
			case 1:
			{
				system("cls");
				cout << setw(70) << " Binary Tree Dictionary " << endl;
				string word;
				cout << "\n\n Please enter the word you want to search :  ";
				cin >> word;
				t1.search(word);
				break;
			}
			case 2:
			{
				system("cls");
				string s1;
				cout << "\n Enter the word you want to bookmark: ";
				cin >> s1;
				Node* ptr = t1.search(s1);
				ptr->setBookMark();
				break;
			}
			case 3:
			{
				system("cls");

				cout << setw(70) << " Binary Tree Dictionary " << endl;

				cout << "\n";
				t1.printMarked();
				system("pause>nul");
				break;

			}
			}
		
			
		}
		} while (selector != 3);

		system("pause");
	}