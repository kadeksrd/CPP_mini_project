#include <iostream>

using namespace std;

int main(){
    int start,ratio,years,periodic,total;
 

    cout<<"Welcome To Future Value Calculator"<<endl;
    cout<<"Starting Amount : ";cin>>start;	
    cout<<"Ratio Return : ";cin>>ratio;
    cout<<"Years Target : ";cin>>years; 	
    cout<<"Periodic Deposit (Monthly) : ";cin>>periodic;
    
    total=(start*periodic*(1+ratio/100)^years);	
    cout<<"\n\n"<<endl;

    cout<<"Total Investment "<<"Rp. "<<total<<endl;






}