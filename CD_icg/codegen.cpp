#include <bits/stdc++.h>
using namespace std;

string cts(int x)
{
	string res;
	stringstream ss;
	ss << x;
	res = ss.str();
	return res;
}
ofstream outfile;
int counter;
string token;
int ret;
stack <string> operands;
stack <map<string,pair<string,int> > > s;
stack <map<string,pair<string,int> > > t;
map<string,pair<string,int> > table;
map<string,pair<vector<string>,string> > func_args;
map<string, string> columnMap;

map<string, int> helper;
map<string, string> func;
int countTemp = 0;
int labelCount = 0;
int funcCount = 0;

void printRet()
{
	outfile.open("icg.txt",ios::app);
	string a = operands.top();
	operands.pop();
	outfile<<"return "<<a<<endl;
	outfile.close();
}
void makeFunction(string fname)
{
	string f = "F" + cts(funcCount++);
	func[fname] = f;
	outfile.open("icg.txt",ios::app);
	outfile<<f<<": "<<fname<<endl;
	outfile.close();
}

void printTACun(char op)
{
	outfile.open("icg.txt",ios::app);
	string a = operands.top();
	operands.pop();
	outfile<<a<<" = "<<a<<" "<<op<<" 1"<<endl;
	outfile.close();
}

void labelFuncCall(string fname)
{
	outfile.open("icg.txt",ios::app);
	string f = func[fname];
	outfile<<"goto "<<f<<endl;
	outfile.close();
}

void printLabel()
{
	outfile.open("icg.txt",ios::app);
	string a = operands.top();
	operands.pop();
	outfile<<a<<":"<<endl;
	outfile.close();
}

void printGotoLabel()
{
	outfile.open("icg.txt",ios::app);
	string l = "L" + cts(labelCount++);
	outfile<<"goto "<<l<<endl;
	outfile.close();
	printLabel();
	operands.push(l);
}

void makeLabel()
{
	outfile.open("icg.txt",ios::app);
	string l = "L" + cts(labelCount++);
	outfile<<l<<":"<<endl;
	operands.push(l);
	outfile.close();
}

void printTAIfNot()
{
	outfile.open("icg.txt",ios::app);
	string l = "L" + cts(labelCount++);
	string a = operands.top();
	operands.pop();
	outfile<<"if (not "<<a<<") then goto "<<l<<endl;
	outfile.close();
	operands.push(l);
}

void printTADoWhile()
{
	outfile.open("icg.txt",ios::app);
	string a = operands.top();
	operands.pop();
	string l = operands.top();
	operands.pop();
	outfile<<"if ("<<a<<") then goto "<<l<<endl;
	outfile.close();
}


void printTAC(string op)
{
	outfile.open("icg.txt",ios::app);
	string t = "t" + cts(countTemp++);
	string a = operands.top();
	operands.pop();
	string b = operands.top();
	operands.pop();
	outfile<<t<<" = "<<b<<" "<<op<<" "<<a<<endl;
	outfile.close();
	operands.push(t);
}

void printTACasgn()
{
	outfile.open("icg.txt",ios::app);
	string a = operands.top();
	operands.pop();
	string b = operands.top();
	operands.pop();
	outfile<<a<<" = "<<b<<endl;
	outfile.close();
}

int funcType(string name,int arg1,int arg2)
{
	if(func_args.find(name)!=func_args.end())
	{
		if(helper[func_args[name].first[0]] != arg1 || helper[func_args[name].first[1]] != arg2)
		{
			return -1;
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

int insertFunc(string returnType,string name,string arg1,string arg2)
{
	if(func_args.find(name)==func_args.end())
	{
		func_args[name].second = returnType;
		func_args[name].first.push_back(arg1);
		func_args[name].first.push_back(arg2);

		return 1;
	}
	else
	{
		return -1;
	}
}

// Insert token
int insertToken(int TOKENID, map<string,pair<string,int> > &table)
{
	cout<<"INSERT "<<token<<endl<<endl;
	if(table.find(token)!=table.end())
		return 1;
	switch(TOKENID)
	{
		case 1 : table[token].first = "FUNCTION"; break;
		case 2 : table[token].first = "MAIN_FUNCTION"; break;
		case 3 : table[token].first = "INTEGER_VARIABLE"; break;
		case 4 : table[token].first = "CHAR_VARIABLE"; break;
		case 5 : table[token].first = "VOID_VARIABLE";
	}
	table[token].second = counter;
	if(!s.empty())
		s.pop();
	s.push(table);
	return 0;
}

int lookupTable(string token)
{
	bool flag = true;
	while(!s.empty())
	{
		// Assigning temporary map to the top of the stack(current scope)
		map<string, pair<string, int> > temp = s.top();
		map<string, pair<string, int> >::iterator it;
		it = temp.find(token);
		if(it!=temp.end())
		{
			flag = false;
			break;
		}
		// Popping the current scope block
		s.pop();
		// Storing current scope map in some temporary stack
		t.push(temp);
	}
	while(!t.empty())
	{
		s.push(t.top());
		t.pop();
	}
	if(flag)
		return 2;
	else
		return 0;
}

int lookupType(string token)
{
	bool flag = true;
	string type = "";
	while(!s.empty())
	{
		// Assigning temporary map to the top of the stack(current scope)
		map<string, pair<string, int > > temp = s.top();
		map<string, pair<string, int> >::iterator it;
		it = temp.find(token);
		if(it!=temp.end())
		{
			flag = false;
			type = (*it).second.first;
			break;
		}
		// Popping the current scope block
		s.pop();
		// Storing current scope map in some temporary stack
		t.push(temp);
	}
	while(!t.empty())
	{
		s.push(t.top());
		t.pop();
	}
	if(type.compare("FUNCTION")==0)
	{
		return 1;
	}
	else if(type.compare("MAIN_FUNCTION")==0)
	{
		return 2;
	}
	else if(type.compare("INTEGER_VARIABLE")==0)
	{
		return 3;
	}
	else if(type.compare("CHAR_VARIABLE")==0)
	{
		return 4;
	}
	else if(type.compare("VOID_VARIABLE")==0)
	{
		return 5;
	}
	else
	{
		return -1;
	}
}

void disp(map<string,pair<string,int> > table)
{
	cout << "\nNEW BLOCK" << endl;
	for(map<string,pair<string,int> >::iterator it = table.begin(); it != table.end(); it++)
		cout << "< " << it->first << " , " << (it -> second).first << " , " << (it -> second).second << " >" << endl;
	cout<<endl<<endl;
}


void displayCurrentStatus()
{
	int sz = (int)s.size();
	while(!s.empty())
	{
		// Assigning temporary map to the top of the stack(current scope)
		map<string, pair<string, int> > temp = s.top();


		for(map<string, pair<string, int> >::iterator it = temp.begin(); it != temp.end(); it++)
		{
			cout<<it->first<<" "<<(*it).second.first<<endl;
		}
		// Popping the current scope block
		s.pop();
		// Storing current scope map in some temporary stack
		t.push(temp);
		sz--;
	}
	while(!t.empty())
	{
		s.push(t.top());
		t.pop();
	}
}
