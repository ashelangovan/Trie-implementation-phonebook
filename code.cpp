#include "template.cpp"
using namespace std;



class data_node
{
	public:
		string name;
		string number;
		vector<string> address;
		data_node(string a, string b, vector<string> c)
		{
			name=a;
			number=b;
			REP(i,5)
				address.PB(c[i]);
		}
		void disp()
		{
			REP(i,20)
				cout<<"=";
			cout<<endl;
			cout<<"Name       :" << name<<endl;
			cout<<"Number     :" << number<<endl;
			cout<<"Address    :" << endl;
			cout<<"Door Number:" << address[0]<<endl;
			cout<<"Street     :" << address[1]<<endl;
			cout<<"Area       :" << address[2]<<endl;
			cout<<"City       :" << address[3]<<endl;
			cout<<"Pincode    :" << address[4]<<endl;
			REP(i,20)
				cout<<"=";
			cout<<endl;
		}
};






//////
//AVL 
/////

class node
{
public:
data_node* data;
struct node *left,*right;
int ht;
};


class AVL
{
public:
node* root;
int height(node *);
node* rotate_right(node *);
node* rotate_left(node *);
node* RR(node *);
node* LL(node *);
node* LR(node *);
node* RL(node *);
int BF(node *);
AVL()
{
root=NULL;
}
node* insert(node *,data_node*);
node* delet(node *,data_node*);
};




node *AVL::insert(node *T,data_node* x)

{
if(T==NULL)
{
T=new node;
T->data=x;
T->left=NULL;
T->right=NULL;
}
else
{
if(x>T->data)
{
T->right=insert(T->right,x);
if(BF(T)==-2)
{
if(x>T->right->data)
T=RR(T);
else
T=RL(T);
}
}
else if(x<T->data)
{
T->left=insert(T->left,x);
if(BF(T)==2)
{
if(x<T->left->data)
T=LL(T);
else
T=LR(T);
}
}
}
T->ht=height(T);
return(T);
}

node *AVL::delet(node *T,data_node* x)
{
node *p;
if(T==NULL)
return NULL;
else
if(x>T->data)
{
T->right=delet(T->right,x);
if(BF(T)==2)
if(BF(T->left)>=0)
T=LL(T);
else
T=LR(T);
}
else if(x<T->data)
{
T->left=delet(T->left,x);
if(BF(T)==-2)
if(BF(T->right)<=0)
T=RR(T);
else
T=RL(T);
}
else
{
if(T->right!=NULL)
{
p=T->right;
while(p->left!=NULL)
p=p->left;
T->data=p->data;
T->right=delet(T->right,p->data);
if(BF(T)==2)
if(BF(T->left)>=0)
T=LL(T);
else
T=LR(T);
}
else
return(T->left);
}
T->ht=height(T);
return(T);
}

int AVL::height(node *T)

{
int LH,RH;
if(T==NULL)
return(0);
if(T->left==NULL)
LH=0;
else
LH=1+T->left->ht;
if(T->right==NULL)
RH=0;
else
RH=1+T->right->ht;
if(LH>RH)
return (LH);
else
return (RH);
}

int AVL::BF(node *T)

{
int LH,RH;
if(T==NULL)
return(0);
if(T->left==NULL)
LH=0;
else
LH=1+T->left->ht;
if(T->right==NULL)
RH=0;
else
RH=1+T->right->ht;
return(LH-RH);
}

node *AVL::rotate_left(node *x)

{
node *y;
y=x->right;
x->right=y->left;
y->left=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}

node *AVL::rotate_right(node *x)

{
node *y;
y=x->left;
x->left=y->right;
y->right=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}

node *AVL::LL(node *T)

{
T=rotate_right(T);
return(T);
}

node *AVL::RR(node *T)

{
T=rotate_left(T);
return(T);
}

node *AVL::LR(node *T)

{
T->left=rotate_left(T->left);
T=rotate_right(T);
return(T);
}

node *AVL::RL(node *T)

{
T->right=rotate_right(T->right);
T=rotate_left(T);
return(T);
}












char newline;
	
	
class tri_node
{
	public:
	int end;
	int sum;
	tri_node* next[10];
	data_node* data;
		tri_node()
		{
			end=0;
			sum=0;
			REP(i,10)
				next[i]=NULL;
	 	data=NULL;
	 }
	tri_node(int en, data_node *temp)
	{
		end=1;
		sum=0;
		REP(i,10)
			next[i]=NULL;
		data=temp;
	}
};


class phonebook
{
	public:
		tri_node* head;
		phonebook()
		{
			head=new tri_node();
		}
		void addnum(string num, data_node* node)
		{
			tri_node *temp=head;
			REP(i,num.length()-1)
			{
				if(temp->next[num[i]-'0']==NULL)
				{
					temp->next[num[i]-'0']=new tri_node();
				}

				temp=temp->next[num[i]-'0'];
				temp->sum++;
			}
			temp->next[num[num.length()-1]-'0']=new tri_node(1,node);
			temp->next[num[num.length()-1]-'0']->sum++;
		}
		
		void se( tri_node *temp, string s, vector<data_node*> &nums)
		{
			if(temp->end&&s=="")
			{
				nums.PB(temp->data);
				return;
			}
			
			if(s=="")
			{
				return;
			}
			if(s[0]>='0'&&s[0]<='9')
			{
				if(temp->next[s[0]-'0']==NULL)
				{
					return;
				}
				se(temp->next[s[0]-'0'],s.substr(1),nums);
				return;
			}
			REP(i,10)
			{
				
				if(temp->next[i]==NULL)
					continue;
				se(temp->next[i],s.substr(1),nums);
			}
			return;
		}
				
		vector<data_node*> search(string number )
		{
			vector<data_node*> nums;
			se(head,number,nums);
			if(nums.size()!=0){
			return nums;
			}
			for(int i=number.length()-1;i>=0;i--)
			{
				string ns=number;
				ns[i]='_';
				se(head,ns,nums);
				if(nums.size()!=0){
				return nums;
				}
			}
			return nums;
		}

		data_node* search_dynn()
		{
			cout<<"Enter the number"<<endl;
			system("stty raw");
			char a;
			tri_node* temp=head,*temp1;
			string str1,str2;
			int count=0,flag=0;
			while(a=getchar())
			{
				if(a==char(13))
					break;
				if(!(a>='0'&&a<='9'))
					continue;
				str1+=a;
				REP(j,count+1)
				{
					cout<<" ";
				}
				REP(j,count+1)
				{
					cout<<"\b";
				}
				
				if(temp==NULL||temp->next[a-'0']==NULL)
				{
					temp=NULL;
					continue;
				}
				temp=temp->next[a-'0'];
				count=0;flag=0;
				temp1=temp;
				while(!flag)
				{
					if(temp1->end)
						break;
					for(int i=0;i<10;i++)
					{
						if(temp1->next[i])
						{
							cout<<char(i+'0');
							count++;
							temp1=temp1->next[i];
							flag=0;
							break;
						}
						flag=1;
					}

				}
				REP(i,count)
					cout<<"\b";
			}
			cout<<" \b\b \b\b";
			for(int i=0;i<count+4;i++)
				cout<<" ";
			system("stty cooked");
			cout<<endl;
			if(temp!=NULL&&temp->end)
			{
				if(temp->data!=NULL)
				return temp->data;
			}
			else if(temp1!=NULL&&temp1->end)
			{
				if(temp1->data!=NULL)
				return temp1->data;
			}
			return NULL;
		}
		void del_tri(string s)
		{
			tri_node* temp=head;
			REP(i,s.length())
			{
				if(temp->next[s[i]-'0']==NULL||temp->next[s[i]-'0']->sum==1)
				{
					if(temp->next[s[i]-'0']==NULL||temp->next[s[i]-'0']->sum==1)
					{
						if(temp->next[s[i]-'0']==NULL)
							return;
						temp->next[s[i]-'0']=NULL;
						return;
					}
				}
				temp=temp->next[s[i]-'0'];
			}

			temp->end=0;
			temp->data=NULL;
			return;
		}
		void display_tri()
		{
			tri_node* temp=head;
			while(1)
			{
				REP(i,10)
					cout<<temp->next[i]<<'\t';
				cout<<"e "<<temp->sum;
				cout<<endl;
				int n;
				cin>>n;
				if(n==-1) {return;}
				cout<<n<<endl;
				temp=temp->next[n];
			}
		}
		bool ispresent(string number)
		{
			tri_node* temp=head;
			REP(i,number.length())
			{
				if(temp->next[number[i]-'0']==NULL)
				{
					return 0;
				}
				temp=temp->next[number[i]-'0'];
			}
			return temp->end;
		}
};			 		
		

class word_node
{
	public:
	int end;
	int sum;
	word_node* next[26];
	data_node* data;
	word_node()
	{
		end=0;
		sum=0;
		REP(i,26)
			next[i]=NULL;
	 	data=NULL;
	 }
	word_node(int en, data_node *temp)
	{
		end=1;
		sum=0;
		REP(i,26)
			next[i]=NULL;
		data=temp;
	}
};


class phonebookword
{
	public:
		word_node* head;
		phonebookword()
		{
			head=new word_node();
		}
		void addword(string word, data_node* nodejs)
		{
			word_node *temp=head;
			REP(i,word.length()-1)
			{
				if(temp->next[word[i]-'a']==NULL)
				{
					temp->next[word[i]-'a']=new word_node();
				}
				temp=temp->next[word[i]-'a'];
				temp->sum++;
			}
			temp->next[word[word.length()-1]-'a']=new word_node(1,nodejs);
			temp->next[word[word.length()-1]-'a']->sum++;
		}
		
		void se( word_node *temp, string s, vector<data_node*> &nums)
		{
			if(temp->end&&s=="")
			{
				nums.PB(temp->data);
				return;
			}
			
			if(s=="")
			{
				return;
			}
			if(s[0]>='a'&&s[0]<='z')
			{
				if(temp->next[s[0]-'a']==NULL)
				{
					return;
				}
				se(temp->next[s[0]-'a'],s.substr(1),nums);
				return;
			}
			REP(i,26)
			{
				
				if(temp->next[i]==NULL)
					continue;
				se(temp->next[i],s.substr(1),nums);
			}
			return;
		}
				
		vector<data_node*> search(string number )
		{
			vector<data_node*> nums;
			se(head,number,nums);
			if(nums.size()!=0){
			return nums;
			}
			for(int i=number.length()-1;i>=0;i--)
			{
				string ns=number;
				ns[i]='_';
				se(head,ns,nums);
				if(nums.size()!=0){
				return nums;
				}
			}
			return nums;
		}

		data_node* search_dynn()
		{
			cout<<"Enter the name"<<endl;
			system("stty raw");
			char a;
			word_node* temp=head,*temp1;
			string str1,str2;
			int count=0,flag=0;
			while(a=getchar())
			{
				if(a==char(13))
					break;
				if(!((a>='a'&&a<='z')||(a>='A'&&a<='Z')))
					continue;
				if(a>='A'&&a<='Z')
					a+=32;
				str1+=a;
				REP(j,count+1)
				{
					cout<<" ";
				}
				REP(j,count+1)
				{
					cout<<"\b";
				}
				
				if(temp==NULL||temp->next[a-'a']==NULL)
				{
					temp=NULL;
					continue;
				}
				temp=temp->next[a-'a'];
				count=0;flag=0;
				temp1=temp;
				while(!flag)
				{
					if(temp1->end)
						break;
					for(int i=0;i<26;i++)
					{
						if(temp1->next[i])
						{
							cout<<char(i+'a');
							count++;
							temp1=temp1->next[i];
							flag=0;
							break;
						}
						flag=1;
					}

				}
				REP(i,count)
					cout<<"\b";
			}
			cout<<" \b\b \b\b";
			for(int i=0;i<count;i++)
				cout<<" ";
			system("stty cooked");
			cout<<endl;
			if(temp->end)
			{
				if(temp->data!=NULL)
				return temp->data;
			}
			else if(temp1->end)
			{
				if(temp1->data!=NULL)
				return temp1->data;
			}
			return NULL;
		}
		void del_word(string s)
		{
			
			word_node* temp=head;
			REP(i,s.length())
			{
				if(temp->next[s[i]-'a']==NULL||temp->next[s[i]-'a']->sum==1)
				{
					if(temp->next[s[i]-'a']==NULL||temp->next[s[i]-'a']->sum==1)
					{
						if(temp->next[s[i]-'a']==NULL)
							return;
						temp->next[s[i]-'a']=NULL;
						return;
					}
				}
				temp=temp->next[s[i]-'a'];
			}
			temp->end=0;
			return;
		}
		void display_word()
		{
			word_node* temp=head;
			while(1)
			{
				REP(i,26)
					cout<<temp->next[i]<<'\t';
				cout<<"e "<<temp->sum;
				cout<<endl;
				int n;
				cin>>n;
				if(n==-1) return;
				temp=temp->next[n];
			}
		}
		bool ispresent(string number)
		{
			word_node* temp=head;
			REP(i,number.length())
			{
				if(temp->next[number[i]-'a']==NULL)
				{
					return 0;
				}
				temp=temp->next[number[i]-'a'];
			}
			return temp->end;
		}
};		

class phonedb
{
	public:
		AVL tree;
		phonebook numbers;
		phonebookword words;
		void get_user_phonenumber()
		{
			string name,tname;
			cout<<"Enter the Name : ";
			getline(cin,name);
			REP(i,name.length())
			{
				if(name[i]>='a'&&name[i]<='z')
				{
					tname+=name[i];
					continue;
				}
				if(name[i]>='A'&&name[i]<='Z')
				{
					tname+=char(name[i]+32);
					continue;
				}
			}
			if(words.ispresent(tname))
			{
				cout<<"Name Exists"<<endl;
				return;
			}
			string num,tnum;
			cout<<"Enter Phone Number:";
			cin>>num;
			int fl=0;
			while(1)
			{
				fl=0;
				REP(i,num.length())
				{
					if(num[i]>='0'&&num[i]<='9')
						continue;
					fl=1;
					break;
				}
				if(fl)
				{
					cout<<"Invalid Number. Enter Again:";
					cin>>num;
					continue;
				}
				break;
			}
			if(numbers.ispresent(num))
			{
				cout<<"Number already exists"<<endl;
				return;
			}
			vector<string> addr;
			string tell;
			system("stty raw");
			cout<<"Enter address:Door Number:";
			cin>>tell;
			addr.PB(tell);
			REP(i,13+tell.length()+1)
				cout<<" \b\b";
			cout<<"Street Name:";
			cin>>tell;
			addr.PB(tell);
			REP(i,13+tell.length()+1)
				cout<<" \b\b";
			cout<<"Area Name:";
			cin>>tell;
			addr.PB(tell);
			REP(i,11+tell.length()+1)
				cout<<" \b\b";
			cout<<"City Name:";
			cin>>tell;
			addr.PB(tell);
			REP(i,11+tell.length()+1)
				cout<<" \b\b";
			cout<<"Pin Code:";
			cin>>tell;
			addr.PB(tell);
			cout<<" \b\b \b\b \b\b";
			data_node* tempo=new data_node(name,num,addr);
			system("stty cooked");
			cout<<endl;
			numbers.addnum(num,tempo);
			words.addword(tname,tempo);
			tree.root=tree.insert(tree.root,tempo);
			ofstream outfile;
			outfile.open("dictionary.txt",ios::app);
			outfile<<tempo->name<<endl;
			outfile<<tempo->number<<endl;
			REP(kl,5)outfile<<tempo->address[kl]<<endl;
			outfile.close();
		}
		void put_in_file(data_node* temp, string pal)
		{
			ofstream outfile;
			outfile.open(pal.c_str(),ios::app);
			outfile<<temp->name<<endl;
			outfile<<temp->number<<endl;
			REP(kl,5)outfile<<temp->address[kl]<<endl;
			outfile.close();

		}
		void put_phonenumber(data_node* temp)
		{
			string name,tname;
			if(words.ispresent(temp->name))
			{
				cout<<"Error while Importing 1 attribute."<<endl;
				return;
			}
			if(numbers.ispresent(temp->number))
			{
				cout<<"Error while Importing 1 attribute."<<endl;
				return;
			}
			numbers.addnum(temp->number,temp);
			words.addword(temp->name,temp);
			tree.root=tree.insert(tree.root,temp);
		}
		vector<data_node*> select_one(vector<data_node*> s, int r)
		{
			if(r)
			{
				vector<data_node*> ar;
				int i;
				for(i=1;i<=s.size();i++)
				{
					cout<<i<<"."<<s[i-1]->name<<endl;
				}
				cout<<i<<". All the above"<<endl;
				int n;
				scanf("%d",&n);
				getchar();
				if(n==i)
					return s;
				ar.PB(s[n-1]);
				return ar;
			}
			vector<data_node*> ar;
			int i;
			for(i=1;i<=s.size();i++)
			{
				cout<<i<<"."<<s[i-1]->number<<endl;
			}
			cout<<i<<". All the above"<<endl;
			int n;
			scanf("%d",&n);
			getchar();
			if(n==i)
				return s;
			ar.PB(s[n-1]);
			return ar;

		}
		void search_first(vector<string> as)
		{
			if(as.size()<5)
			{
				cout<<"Query Invalid"<<endl;
				return;
			}

			if(as[1]!="phonebook")
			{
				cout<<"Invalid identifier "<<as[1]<<endl;
				return;
			}
			if(as[2]!="over")
			{
				cout<<"Invalid identifier "<<as[2]<<endl;
				return;	
			}
			if((as[3]!="name"&&as[3]!="number"))
			{
				cout<<"Invalid identifier "<<as[3]<<endl;
				return;	
			}
			if(as[4]=="dynn")
			{
				data_node* data;
				if(as[3]=="number")
				{
					data=numbers.search_dynn();
				}
				else
				{
					data=words.search_dynn();
				}
				if(data==NULL)
					cout<<"Wrong entry :("<<endl;
				else
					data->disp();
				return;
			}
			if(as[4]=="like")
			{
				vector<data_node*> datas;
				if(as[3]=="name")
				{
					datas=words.search(as[5]);
					datas=select_one(datas,1);
				}
				else{
					datas=numbers.search(as[5]);
					datas=select_one(datas,0);
				}

				REP(i,datas.size())
					datas[i]->disp();

			}
			return;
		}
		void go_inorder(node* temp, string pal)
		{
			if(!temp) return;
			go_inorder(temp->left,pal);
			put_in_file(temp->data, pal);
			go_inorder(temp->right,pal);
		}

		void delete_first(vector<string> as)
		{
			if(as.size()<5)
			{
				cout<<"Query Invalid"<<endl;
				return;
			}

			if(as[1]!="phonebook")
			{
				cout<<"Invalid identifier "<<as[1]<<endl;
				return;
			}
			if(as[2]!="over")
			{
				cout<<"Invalid identifier "<<as[2]<<endl;
				return;	
			}
			if(as[3]!="name"&&as[3]!="number")
			{
				cout<<"Invalid identifier "<<as[3]<<endl;
				return;	
			}
			if(as[4]=="dynn")
			{
				data_node* data;
				if(as[3]=="number")
				{
					data=numbers.search_dynn();
				}
				else
				{
					data=words.search_dynn();
				}
				if(data==NULL)
					cout<<"Wrong entry :(";
				else
				{
					numbers.del_tri(data->number);
					string p;
					REP(k,data->name.length())
					{
						if(data->name[k]>='a'&&data->name[k]<='z')
							p+=data->name[k];
						if(data->name[k]>='A'&&data->name[k]<='Z')
							p+=data->name[k]+32;
					}
					words.del_word(p);
				}
			}
			if(as[4]=="like")
			{
				vector<data_node*> datas;
				if(as[3]=="name")
				{
					datas=words.search(as[5]);
					datas=select_one(datas,1);
				}
				else{
					datas=numbers.search(as[5]);
					datas=select_one(datas,0);
				}
				REP(i,datas.size())
				{
					numbers.del_tri(datas[i]->number);
					string p;
					REP(k,datas[i]->name.length())
					{
						if(datas[i]->name[k]>='a'&&datas[i]->name[k]<='z')
							p+=datas[i]->name[k];
						if(datas[i]->name[k]>='A'&&datas[i]->name[k]<='Z')
							p+=datas[i]->name[k]+32;
					}
					words.del_word(p);
				}
			}
			return;	
		}
		void tokenize()
		{
			string input;
			while(1){
			getline(cin,input);
			if(input.size()==0) continue;
			string p;
			vector<string> as;
			istringstream ss(input);
			ss>>p;
			while(ss)
			{
				as.PB(p);
				ss>>p;
			}
			if(as[0]=="search")
			{
				search_first(as);
			}
			else if(as[0]=="delete")
			{
				delete_first(as);
			}
			else if(as[0]=="insert")
			{
				get_user_phonenumber();
			}
			else if(as[0]=="exit")
			{
				return;
			}
			else if(as[0]=="import")
			{
				if(as[1]!="from")
				{
					cout<<"Invalid syntax"<<endl;
					continue;
				}
				ifstream fileop(as[2].c_str());
				if(fileop.is_open())
				{
					while(fileop.good())
					{
						vector<string> ar;
						string s;
						REP(i,7)
						{
							getline(fileop,s);
							if(s=="")
								goto s;
							ar.PB(s);
						}
						vector<string> p;
						REP(i,5)
						p.PB(ar[i+2]);
						data_node* yoda=new data_node(ar[0],ar[1],p);
						put_phonenumber(yoda);
					}
				s:;
				}
			}
			else if(as[0]=="export")
			{
				if(as[1]!="to")
				{
					cout<<"Invalid syntax"<<endl;
					continue;
				}
				
				go_inorder(tree.root, as[2]);
			}
			else
				cout<<"Invalid Entry"<<endl;
		}
		}

};
int main()
{
	phonedb a;
	a.tokenize();
}
