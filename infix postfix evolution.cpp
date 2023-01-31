#include <iostream>
#include <string.h>
using namespace std;


class stack
{
	int data;
	stack *link, *top;
	
	public:
		stack()
		{
			top = NULL;	
		}
		void push(int);
		void pop();
		char* InfixToPostfix(char[]);
		int priority(char);
		char* reverse(char[]);
		void evolution(char[]);
};

void stack::push(int item)
{
	stack *newnode = new stack();
	newnode->data = item;
	newnode->link = NULL;

	if(top == NULL)
	{
		top = newnode;
	}
	else
	{
		newnode->link = top;
		top = newnode;
	}
}

void stack::pop()  
{
	
	if(top == NULL)
	{
		cout<<"\n...Stack is empty...";
	}
	else
	{  
		stack *node = top;
		top = top->link;
		delete(node);
	}
}

int stack::priority(char x)

{
	if(x=='^')
		return 3;	
		
	else if((x =='*') || (x == '/'))
		return 2;
		
	else if((x == '+') || (x == '-'))
		return 1;
		
	else
		return 0;
	
}

char* stack::InfixToPostfix(char infix[])
{
	int i = 0, j = 0, instack, income;
	char postfix[20];
	while(infix[i]!='\0')
	{
		if(!isalnum(infix[i]))
		{
			if(infix[i]=='(')
			{
				push(infix[i]);
				i++;
			}
			else
			{
				if(top == NULL)
				{
					push(infix[i]);
					i++;
				}
				else
				{
					if(infix[i]==')')
					{
						while(top->data!='(')
						{
							postfix[j]=top->data;
							j++;
							pop();
						}
						pop();
						i++;
					}
					else
					{
					
						instack = priority(top->data);
						income = priority(infix[i]);
						
						while(top!=NULL && instack>=income)
						{
							postfix[j] = top->data;
							j++;
							pop();
							if(top!=NULL)
							{							
							instack = priority(top->data);
							income = priority(infix[i]);
							}
						}
							push(infix[i]);
							i++;	
					}
				}
			}
		}
		else
		{
			postfix[j] = infix[i];
			i++;
			j++;	
		}
	}
	while(top != NULL)
	{
		postfix[j]=top->data;
		pop();
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}

int calculate(int y, int x ,char opr)
{
	if(opr == '/' && y != 0)
		return (x / y);
		
	else if(opr == '-')
		return (x - y);
		
	else if(opr == '*')
		return (x * y);
		
	else 
		return (x + y);
}

void stack::evolution(char postfix[])
{
	int input, x, y, result, answer, i=0;
	do
	{	
		while(isalnum(postfix[i]))
		{
			if(!isalpha(postfix[i]))
			{
				push(postfix[i]);
			}
			else
			{
				cout<<"\nEnter the value of : "<<postfix[i]<<" ";
				cin>>input;
				push(input);
			}
			i++;
		}
		y = top->data;
		pop();
		x = top->data;
		pop();
		result = calculate(y, x , postfix[i]);
		i++;	
		push(result);
	}while(postfix[i] != '\0');
			
		answer = top->data;
		cout<<"\nEVOLUTION OF POSTFIX :"<<answer;
		pop();	
}

char* stack::reverse(char line[])
{
	int i, j = 0;
	char revline[20];
	int len = strlen(line); 
	for(i=len-1; i>=0; i--)
	{
		if(line[i] == '(')
		{
			revline[j] = ')';
		}
		else if(line[i] == ')')
		{
			revline[j] = '(';
		}
		else
		{		
		revline[j] = line[i];
		}
		j++;
	
	}
	revline[j] = '\0';
	return revline;
}

int main()
{
	int ch;
	char infix[20];
	char* post;
	char* revstr;
	char* temp;
	char* prefix;
	stack obj;
	cout<<"\nEnter the Infix Expression : ";
	cin>>infix;
	
	do
	{
	
	cout<<" \n 01.Postfix Expression"<<"\n 02.Prefix Expression"<<"\n 03.Postfix Evaluation"<<"\n 00.Exit"<<endl;
	cout<<"\nEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			post = obj.InfixToPostfix(infix);
			cout<<"\nPOSTFIX EXPRESSION  : "<<post<<endl;
			break;
		case 2:
			revstr = obj.reverse(infix);
			temp = obj.InfixToPostfix(revstr);			
			prefix = obj.reverse(temp);
			cout<<"\nPREFIX EXPRESSION  :\t"<<prefix<<endl;
			break;
		case 3:
			post = obj.InfixToPostfix(infix);		
			obj.evolution(post);
			break;			
		default:
			cout<<"\n.....INVALID CHOICE.....\n";	
				
	}
	}while(ch!=0); 

}
