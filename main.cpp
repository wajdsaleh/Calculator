#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
//infix to postfix
struct node1{
char info;
node1 *next;};

class InfToPostfix{
private:
    node1 *top;
public:
    InfToPostfix(){
    top=NULL;}

bool isEmpty1(){
if(top==NULL)
return true;
else return false;}

void push1(char symb){
node1 *p = new node1;
p->info=symb;
p->next=top;
top=p;}

char pop1(){
    char temp=top->info;
    node1 *te=top;
    top=top->next;
    delete te;
return temp;}

char peak1(){
return top->info;}

bool prcd(char top, char symb){
if(symb=='^'||symb=='(')
    return false;
else if(((top=='-'|| top=='+')&&(symb=='*'||symb=='/'||symb=='%')))
return false;
else if(((top=='*'|| top=='/'||symb=='%')&&(symb=='+'||symb=='-')))
return true;
else if(top=='(')
    return false;
else return true;}};

/*The difference between the 2 stacks , the first one is converting infix to postfix so it should be char type 
while the second one is evaluating the postfix expression so it should be float or double*/

//postfix evaluation
struct node{
float info;
node *next;};

class EvaluatePost{
private:
    node *top;
public:
    EvaluatePost(){
    top=NULL;}

bool isEmpty(){
if(top==NULL)
return true;
else return false;}

void push(float item){
node *p = new node;
p->info=item;
p->next=top;
top=p;}

float pop(){
    float temp=top->info;
    node *te=top;
    top=top->next;
    delete te;
return temp;}

float peak(){
return top->info;}

float evaluation(float opnd1,float opnd2,char symb){
switch(symb){
case '+':
return opnd1+opnd2;
case '-':
return opnd1-opnd2;
case '*':
return opnd1*opnd2;
case '/':
    if(opnd2==0){
        cout<<"division by zero is not allowed!\n";
    return 0;}
return opnd1/opnd2;
case '%':
return (int)opnd1%(int)opnd2;
case '^':
return pow(opnd1,opnd2);}}};


int main(){

InfToPostfix s1;
EvaluatePost s;
string exp,postfix,answer,y="yes",n="no";
char topsym , symb,symb2;
cout<<"\t\t\t\t\t\t\tCalculator"<<endl<<endl;
int i=0,j=0;
float value,opnd2,opnd1;
Here:{
cout<<"Type the arithmetic expression to calculate it for you:\n"<<
"Number range from : 0-9 (single digit numbers only)\n";
        cin>>exp;

while (i<exp.length()){
symb=exp[i];
if (isdigit(symb))
postfix+=symb;
else{
while (!s1.isEmpty1()&&s1.prcd(s1.peak1(), symb)){
    topsym=s1.pop1();
postfix+=topsym;}
 if (s1.isEmpty1() || symb != ')')
 s1.push1(symb);
 else
topsym= s1.pop1();}
i++;}

while (!s1.isEmpty1()){
    topsym=s1.pop1();
postfix+=topsym;}
cout<<"The postfix expression: "<<postfix<<endl;
//start evaluation here

while (j<postfix.length()){
symb2=postfix[j];
if (isdigit(symb2))
s.push((int)symb2-((int)'0'));//ASCII representation of 0 is 48

else{
opnd2=s.pop();
opnd1=s.pop();
value=s.evaluation(opnd1,opnd2,symb2);
s.push(value);}
   j++;}
cout<<"Result:"<<(float)s.pop();}

cout<<"\nDo you want continue evaluating on the same last result? , YES,NO\n";
cin>>answer;
if(strcasecmp(answer.c_str(), n.c_str()) == 0){
    cout<<"Do you want to restart ? or Quit? , YES = restart ,NO = quit\n";
    cin>>answer;
    if(strcasecmp(answer.c_str(), y.c_str()) == 0){
    i=0,j=0;
    postfix="";
    goto Here;}}

else if (strcasecmp(answer.c_str(), y.c_str()) == 0){
    i=0,j=0;
    goto Here;}

    cout<<"\nThank you..\n";

    return 0;}
