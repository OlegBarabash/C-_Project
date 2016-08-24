#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <cctype>

using namespace std;

void output_words(multiset<string> file, string str_search)
{
    string str, str2;
    for(auto itr = file.begin(); itr != file.end(); ++itr)
        {
            str = *itr;
            if(str.find(str_search) != string::npos)
            {
                for(size_t i=0; i != str.length(); ++i )
                {
                    if( !isdigit(str[i]) && str[i] != ';')
                    {
                        cout << str.substr( i, str.length() ) ;
                        break;
                    }
                }
            }
        }
}

int main()
{
    string head_file("Head.csv");
    string nest_file("nest.csv");
    string proverb_file("proverb.csv");
    string str;
    map<string, string> head_words;
    setlocale (LC_ALL,"Russian");

    ifstream file_head(head_file);

    while(getline(file_head, str))
    {
        pair<string,string> para;
        for(size_t i = 0; i != str.length(); ++i)
        {
            if(str[i] == ';')
            {
                para.first = str.substr(0,i);
                para.second = str.substr(i+1,str.length());
            }
        }
        head_words.insert(para);
    }
    file_head.close();

    ifstream file_nest(nest_file);
    multiset<string> msstr_nest;
    while(getline(file_nest, str))
    {
        msstr_nest.insert(str);
    }
    file_nest.close();

    ifstream file_proverb(proverb_file);
    multiset<string> msstr_proverb;
    while(getline(file_proverb, str))
    {
        msstr_proverb.insert(str);
    }
    file_proverb.close();

    while(true)
    {
        cout << "____________________________________________" << endl;
        cout << "This is a program of word usage in proverbs.\n" << endl;

        cout << "Enter the word number from 118001 to 118182\n"
             << "Or choose the one from the list" << endl;

        cout << "\t Enter \'L\' - to see the list.\n"
             << "\t       \'E\' - to Exit." << endl;

        string sstr;

        cin >> sstr;

        cout << "***_" << head_words.find(sstr)->second << "_***" << endl;

        switch(sstr[0])
        {
        case 'l' :
            for(auto i: head_words)
            {
                cout << i.first << " - " << i.second << endl;
            }
            break;
        case 'L' :
            for(auto i: head_words)
            {
                cout << i.first << " - " << i.second << endl;
            }
            break;
        case 'e' :
            return 0;
            break;
        case 'E' :
            return 0;
            break;
        }
        if( !isdigit(sstr[0]) && sstr.size() != 6 )
            continue;

        for(auto itr = msstr_nest.begin(); itr != msstr_nest.end(); ++itr)
        {
            str = *itr;
            if(str.find(sstr) != string::npos)
            {
                string number(";");
                bool numset = false;
                for(size_t i=0; i != str.length(); ++i )
                {
                    if( !numset && str[i] == ';' && isdigit(str[i+1]))
                    {
                        number += str.substr(0,i+1);
                        cout << " -- " ;
                        numset = true;
                        output_words(msstr_proverb, number);
                    }

                    if( !isdigit(str[i]) && str[i] != ';')
                    {
                        cout << "\n\t" << str.substr( i, str.length() ) << endl;
                        break;
                    }
                }
            }
        }

    }

    return 0;
}
