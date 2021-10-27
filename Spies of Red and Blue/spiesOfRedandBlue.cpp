//worked for only 25% test cases

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;



struct spy{
    string label;
    struct spy* next=NULL;
};

struct result{
 int count;
 string flag;   
};

 
spy* headRedSpies=NULL;
spy* tailRedSpies=NULL;
spy* headBlueSpies=NULL;
spy* tailBlueSpies=NULL;


void addSpy(string val, int parent, vector<spy*> spies){
    spies[stoi(val.substr(1))+1]->next=spies[parent];
}

// spy* addBlueSpy(string val){
//     spy* newSpy=new spy;
//     newSpy->label=val;
//     if(headBlueSpies==NULL){
//         headBlueSpies=newSpy;
//     }else{
//         newSpy->next=tailBlueSpies;
//     }
    
//     tailBlueSpies=newSpy; 
    
//     return newSpy;   
// }

void cross(string label1, string label2, vector<spy*> redSpies,vector<spy*> blueSpies){
    spy *spy1,*spy2;
    if(label1[0]=='R'){
        spy1=redSpies[stoi(label1.substr(1))];
        spy2=blueSpies[stoi(label1.substr(1))];
    }else{
        spy2=redSpies[stoi(label1.substr(1))];
        spy1=blueSpies[stoi(label1.substr(1))];
    }
    
    spy1->next=spy2;
    
}

result sendInfoRed(string label, vector<spy*> redSpies){
    int count=0;
    spy* redSpy=redSpies[stoi(label.substr(1))];
    spy* ptr1;
    ptr1=redSpy;
    while(ptr1==headRedSpies||ptr1==headBlueSpies){
        ptr1=ptr1->next;
        count++;
    }
    result r;
    r.count=count;
    if(ptr1==headBlueSpies){
        r.flag="b";
    }else{
        r.flag="r";
    }
    return r;
}

result sendInfoBlue(string label, vector<spy*> blueSpies){
    int count=0;
    spy* blueSpy=blueSpies[stoi(label.substr(1))];
    spy* ptr1;
    ptr1=blueSpy;
    while(ptr1==headRedSpies||ptr1==headBlueSpies){
        ptr1=ptr1->next;
        count++;
    }
    result r;
    r.count=count;
    if(ptr1==headBlueSpies){
        r.flag="b";
    }else{
        r.flag="r";
    }
    return r;
}

int main() {
    int t,i,j,k;
    int  nr,nb,e;
    vector<spy*> redSpies(nr);
    vector<spy*> blueSpies(nb);
    cin>>t;
    for(i=0;i<t;i++){
        cin>>nr>>nb>>e;
        for(j=0;j<nr;j++){
            spy* newSpy=new spy;
            newSpy->label="R"+to_string(j+1);
            if(j==0){
                headRedSpies=newSpy;
            }
            redSpies.push_back(newSpy);
        }
        for(j=0;j<nr-1;j++){
            spy* newSpy=new spy;
            newSpy->label="B"+to_string(j+1);
            if(j==0){
                headBlueSpies=newSpy;
            }
            blueSpies.push_back(newSpy);
        }
        for(j=0;j<nr-1;j++){
            string red;
            cin>>red;
            addSpy(red, j+1, redSpies);
        }
        
        for(j=0;j<nb-1;j++){
            string blue;
            cin>>blue;
            addSpy(blue, j+1, blueSpies);
        }
        // for(j=0;j<e;j++){
        //     char op;
        //     cin>>op;
        //     if(op=='w'){
        //         string red1,blue1;
        //         cin>>red1>>blue1;
        //         result redScore,blueScore;
        //         redScore=sendInfoRed( red1, redSpies);
        //         blueScore=sendInfoBlue(blue1, blueSpies);
        //     }else if(op=='c'){
                
        //     }
        // }
        for(k=0;k>nr;k++){
            cout<<redSpies[k]->label;
        }
        
    }
    
    
}