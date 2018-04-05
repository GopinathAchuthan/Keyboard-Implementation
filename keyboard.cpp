#include<bits/stdc++.h>
using namespace std;

// # -> NEW LINE
// @ -> CAPS LOCK
// < -> LEFT ARROW
// > -> RIGHT ARROW
// ^ -> UP ARROW
// ? -> DOWN ARROW
// / -> BACKSPACE

void display(vector <string> v, int line)
{
	cout<<endl;
	for(int i=0;i<line;i++)
		cout<<v[i]<<endl;
}
int main()
{
	cout<<"Keyboard\n";
	cout<<"# -> NEW LINE"<<endl;
	cout<<"@ -> CAPS LOCK"<<endl;
	cout<<"< -> LEFT ARROW"<<endl;
	cout<<"> -> RIGHT ARROW"<<endl;
	cout<<"^ -> UP ARROW"<<endl;
	cout<<"? -> DOWN ARROW"<<endl;
	cout<<"/ -> BACKSPACE"<<endl;

	string str;
	cout<<"Enter the input:\n";
	getline(cin,str);
	vector <string> res;
	res.push_back("");
	int line=0;
	int pos=0;
	bool caps=false;
	for(int i=0;i<str.size();i++)
	{
		switch(str[i])
		{
			case '#':
				if(line+1==res.size())
				{
					line++;
					res.push_back("");
					pos=0;
				}
				else
				{
					line++;
					pos=0;
					res.push_back("");
					for(int k=res.size()-1;k>line;k--)
					{
						string ch=res[k];
						res[k]=res[k-1];
						res[k-1]=ch;
					}
				}
				break;
			case '@':
				(caps)?caps=false:caps=true;
				break;
			case '<':
				if(pos!=0)
					pos--;
				else if(line!=0)
				{
					line--;
					pos=res[line].size();
				}
				break;
			case '>':
				if(line+1==res.size() && pos+1<=res[line].size())
					pos++;
				else if(line+1<res.size())
				{
					pos=0;
					line++;
				}
				break;
			case '^':
				if(line==0)
				{
					if(pos>res[line].size())
					{
						pos=res[line].size();
					}
				}
				else
				{
					line--;
					if(pos>res[line].size() && i+1<str.size() && str[i+1]!='^')
						pos=res[line].size();
				}
				break;
			case '?':
				if(line+1==res.size())
				{
					if(pos>res[line].size())
						pos=res[line].size();
				}
				else
				{
					line++;
					if(pos>res[line].size() && i+1<str.size() && str[i+1]!='?')
						pos=res[line].size();
				}
				break;
			case '/':
				if(pos==0)
				{
					if(line!=0)
					{
						pos=res[line-1].size();
						res[line-1]+=res[line];
						for(int i=line+1;i<res.size();i++)
							res[i].swap(res[i-1]);
						res[res.size()-1]="";
						line--;
					}
				}	
				else
				{

					pos--;
					res[line]=res[line].substr(0,pos)+res[line].substr(pos+1,res[line].size()-pos-1);
				}
				
				break;
			default:
				if(pos==res[line].size())
				{
					if(caps)
						res[line].push_back(str[i]-32);
					else
						res[line].push_back(str[i]);
				}
				else
				{
					if(caps)
					{
						string ch="";
						ch.push_back(str[i]-32);
						res[line].insert(pos,ch);
					}
					else
					{
						string ch="";
						ch.push_back(str[i]);
						res[line].insert(pos,ch);
					}
				}
				pos++;
		}
		//cout<<str[i]<<":\n";
		//cout<<"\tline: "<<line<<endl;
		//cout<<"\tpos: "<<pos<<endl;
		//display(res,res.size());
	}
	display(res,res.size());
	return 0;
}
