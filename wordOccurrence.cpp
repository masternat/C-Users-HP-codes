#include <iostream>
using namespace std;

int OccurenceCout(string str, string word)
{
	int count = 0;
	int strLen  = str.length();
	int wordLen = word.length();
	int j;

	for(int i=0; i <= strLen; i++)
	{
		for(j=0; j< wordLen; j++)
		{
			if(str[i + j] != word[j])
			{
				break;
			}
		}
		if(j == wordLen)
		{
            count++;
		}
	}
	return count;
}

int main()
{
	string word;
	string sentence;
	cout<<"Enter a sentence "<<endl;
	getline(cin,sentence);
	cout<<"Enter a word to search in your sentence : ";
	getline(cin,word);
	cout<<"\n";
	cout << "You have entered : " <<sentence;
	cout<<" occurence of "<< word;
	cout<<" is : "<< OccurenceCout(sentence, word);
	return 0;
}
