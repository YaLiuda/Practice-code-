#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cctype>
using namespace std;

void checkforLOG(){
ifstream checkingforlog("server.log");
if(checkingforlog.is_open()){
    string loginfo;
while(getline(checkingforlog, loginfo)){
size_t index= loginfo.find("INFO");  
if(index != string::npos){    /*
    Like in this case the readed lines from the file are gonna be assigned to the loginfo variable 
thereafter we are looking for the word wrotten in the () if it finds it will return a index position where the word in the sentence beggins 
however the program will continue executing in case if the index position isnt equal to no position like if the word actually EXIST IN THE STRING LINE CURRENTLY 
thus writing to a file sentence where the info keyword is we use the loginfo variable since if the index was faunded means what the variable currently holded the necessary line*/
/* its like being able to actually output the sentence where the word what we are looking for locates is by outputting
the entire line where it was founded and the presence of index position confirmed it*/   

ofstream allinfo ("infofromfile.txt", ios::app);
        if(!allinfo.is_open()){
            cerr<<"[FILE FAILED TO OPEN]";
        return ;
        } else {
            allinfo << loginfo <<endl; //writing index it will output the
             allinfo.close();}
        
    }
}
}}
/* opening the log file (if the user inputed the correct word), we pass
    the user's input 
    as a parameter to a function
    checking which user exactly 
    inputed this data (promocode system?)
    
    or probably we could pass the incorect score as a function parameter 
    inside which extracting the log text we understand for which special employee 
    the score was invalid */

void insert (int average, int employecount, int*MAX, int*MIN){
ofstream inserttofile("emplresults.txt");
 if(!inserttofile.is_open()){
 cerr<<"[Failed to open an insert file]";
 return;
 } else{
 inserttofile<<"The employees score average "<<average<<endl<<
 "The employees whose score is > than "<<average<<" : "<< employecount<< endl<<
 "The minimum score "<<*MIN<< endl<< "The maximum score "<< *MAX;
 inserttofile.close();
 checkforLOG();
}}

void change (int ptr [], int size, int *max, int *min) {
/*int ptr if we assign an array to a function it has to contain [] or * like symbol of array. Since otherwise 
we say like "int ptr is a single variable" */
*max = ptr[0];
*min = ptr[0];
int emplScoreMore = 0;
auto sum = 0;

int average= 0;

for (int i =0; i < size; i++) {
if (*max < ptr[i]) {
*max = ptr[i]; }
 if (*min > ptr[i]) { 
 *min = ptr[i]; }
 sum += ptr[i];}

average = sum /size; 

for (int j = 0; j < size; j++) {
if (ptr[j] > average) {
emplScoreMore ++;
}
}
cout <<"--"<<"Maximum score: "<<"--"<<*max<<endl;
cout <<"--"<< "Minimum score: " <<"--"<<*min<<endl;
cout <<"--"<< "Average score: " <<"--"<<average<<endl;
cout <<"--"<< "Employes whose score is more than average" <<"-- "<<emplScoreMore;
insert (average, emplScoreMore, max, min);


/*
max and min are alredy int * since try to pass them as a function parameter
with & won't work 
IN CASES WHEN WE TRY TO PASS THE ADRESS OF THE POINTER IT SELF WHEN INITIALLY THEY WERE CREATED AS A NORMAL VARIBLES - WE DONT HAVE TO WRITE &
ITS GONNA BE ENOUTH IN THE FUNCTION PARAMETER WRITE JUST *NEWVARIABLE NAME
*/
}

int maxlimit=10;
int main() {

cout<<"Wich system evaluating you prefer to use?"<< endl;
cout<< "For 1-10 write A. For 1-100 write B"<< endl;
  
char anwer;
cin>> anwer;
if(anwer=='A' || anwer=='a'){
maxlimit=10; 
}
else if(anwer=='B' || anwer=='b'){
maxlimit=100;}
 
else {cerr<<"[Invalid evaluating system]";
return 1;
}

int score;
/*
int *employecount=0;
cout<<" Enter, how many employes do you wanna evaluate? ";
cin>>*employecount;
for(char checkingval:*employecount) {
while(*checkingval.ispunct()){
        cerr<<"[The inputed amount of employes contains unavaible puncts]"<<endl;
        cout<<"Input the avaible number of employes which you want to evaluate"<<endl;
cin>>*employecount;        
    } }


/IDEA TO CAHNCGE EVERYTHING TO A VECTOR
vector<int> employes (employecount);
for(int r=0; )
/


int employes[*employecount];
 for(int r=0;r<*employecount;r++){
cout<<"For "<<r+1<<" employer, the score is:"<<endl;
cin>>score;   */


/*
vector<int> employes (employecount);
for(int r=)


*/
int employes[employecount];
 for(int r=0;r<employecount;r++){
cout<<"For "<<r+1<<" employer, the score is:"<<endl;
cin>>score;


while (score<1 || score>maxlimit){
try{
throw runtime_error("Invalid inputed score");}
catch (const runtime_error& e){
cout<<e.what()<<endl;
cout<<"Input the corresponding score once again (selected system was from 1 to: "
<<maxlimit<<") ";
cin>>score;}}
employes[r]=score;}

int Vmax, Vmin;

 change (employes, employecount, &Vmax, &Vmin);

 return 0;
}