#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <iomanip>

pair<int,int> sum_time(int hour1,int hour2,int minute1,int minute2){
    
	int minute=minute1+minute2;
	int hour=hour1+hour2+(minute/60);
	minute=minute%60;
	if(hour>=24)hour-=24;
	return {hour,minute};
}

pair<int,int> diff_time(int hour1,int hour2,int minute1,int minute2){
    if(minute2 > minute1) {
      hour1--;
      minute1 += 60;
   }
   int diff_minute = minute1 - minute2;
   int diff_hour = hour1 - hour2;
  if(diff_hour>=24)diff_hour-=24;
   
   return {diff_hour,diff_minute };
}

void comp(vector<int> &a, vector<int> &b){
    pair<int,int>p=sum_time(a[1],a[5],a[2],a[6]);
    pair<int,int>p1=sum_time(b[1],b[5],b[2],b[6]);
    if(p.first>p1.first || (p.first==p1.first && p.second>=p1.second) ){
        
        int dh=diff_time(a[3],a[1],a[4],a[2]).first,dm=diff_time(a[3],a[1],a[4],a[2]).second;
        int a1=a[1],a2=a[2],b1=b[1],b2=b[2];
        //for a
        b[1]=p1.first;
        b[2]=p1.second;
        b[3]=sum_time(b[3],b[5],b[4],b[6]).first;
        b[4]=sum_time(b[3],b[5],b[4],b[6]).second;
        b[5]=0;b[6]=0;
        if(p.first>sum_time(b[3],0,b[4],1).first || 
        (p.first==sum_time(b[3],0,b[4],1).first && p.second>sum_time(b[3],0,b[4],1).second)){
            a[1]=p.first;
            a[2]=p.second;
        }
        else{
             a[1]=sum_time(b[3],0,b[4],1).first;
            a[2]=sum_time(b[3],0,b[4],1).second;
        }
        
        a[3]=sum_time(a[1],dh,a[2],dm).first;
        a[4]=sum_time(a[1],dh,a[2],dm).second;
        a[5]=0;a[6]=0;
        //for b
        swap(a,b);
    }
    else{
        pair<int,int>p2=sum_time(b[1],b[5],b[2],b[6]);
        pair<int,int>p3=sum_time(a[3],a[5],a[4],a[6]);
        if(p2.first>p3.first || (p2.first==p3.first && p2.second>p3.second)){
            int a1=a[1],a2=a[2];
            a[1]=p.first;
            a[2]=p.second;
            a[3]=sum_time(a[3],a[5],a[4],a[6]).first;
            a[4]=sum_time(a[3],a[5],a[4],a[6]).second;
            a[5]=0;a[6]=0;
            b[1]=p1.first;
            b[2]=p1.second;
            b[3]=sum_time(b[3],b[5],b[4],b[6]).first;
            b[4]=sum_time(b[3],b[5],b[4],b[6]).second;
            b[5]=0;b[6]=0;
        }
        else{
            int dh=diff_time(b[3],b[1],b[4],b[2]).first,dm=diff_time(b[3],b[1],b[4],b[2]).second;
            int a1=a[1],a2=a[2],b1=b[1],b2=b[2];
            a[1]=p.first;
            a[2]=p.second;
            a[3]=sum_time(a[3],a[5],a[4],a[6]).first;
            a[4]=sum_time(a[3],a[5],a[4],a[6]).second;
            a[5]=0;a[6]=0;
            if(p1.first>sum_time(a[3],0,a[4],1).first || 
            (p1.first==sum_time(a[3],0,a[4],1).first && p1.second>sum_time(a[3],0,a[4],1).second)){
            b[1]=p.first;
            b[2]=p.second;
            }
            else{
                 b[1]=sum_time(a[3],0,a[4],1).first;
                b[2]=sum_time(a[3],0,a[4],1).second;
            }
            
            b[3]=sum_time(b[1],dh,b[2],dm).first;
            b[4]=sum_time(b[1],dh,b[2],dm).second;
            b[5]=0;b[6]=0;
        }
    }
   
}
int main() {

	vector<vector<int>> train_list;
	train_list.push_back({1,10,00,10,05,0,6}); 
    train_list.push_back({2,10,03,10,10,0,3});//delay 
    train_list.push_back({3,10,20,10,25,00,3});
    train_list.push_back({4,10,27,10,30,0,0});
    train_list.push_back({5,10,33,10,35,00,10});
    train_list.push_back({6,10,36,10,40,0,0});
    train_list.push_back({7,10,50,10,55,00,9});
    train_list.push_back({8,11,10,11,15,0,0});
    train_list.push_back({9,11,20,11,25,00,7});
    train_list.push_back({10,12,20,12,25,0,0});

    vector<vector<int>> vec(train_list.begin(),train_list.end());
 
    for(int j=1;j<train_list.size();j++){
        comp(train_list[j-1],train_list[j]);
    }
    
    cout<<endl;
    int s_h=10,s_m=0;
    cout<<"Schedule Arrival"<<endl;
    for(int j=0;j<=30;j=j+5){
       
        cout<<"AT "<<s_h<< ":"<<setw(2) << setfill('0') <<s_m+j<<endl;
        cout<<"TN "<<"RTime"<<" Arrival"<<"  "<<"Dept"<< "  "<<"delay"<<endl; 
        int i=0;
        while(i<train_list.size()){
            string d="";
            while(train_list.size()!=0 && 
            train_list[0][1]<s_h || (train_list[0][1]==s_h && train_list[0][2]<s_m+j)){
                auto it = train_list.begin(); 
                train_list.erase(it);
            }
           
            if(i<train_list.size()){
            	  if(train_list[i][1]<s_h+1 || (train_list[i][1]==s_h+1
                    && train_list[i][2]<s_m+j)){
                        
            	    cout<< train_list[i][0]<< "  ";
            	    cout<< setw(2) << setfill('0') <<vec[train_list[i][0]-1][1]<< ":";
                    cout<< setw(2) << setfill('0') << vec[train_list[i][0]-1][2]<<"  ";
                    cout<< setw(2) << setfill('0') << train_list[i][1]<< ":";
                    cout<< setw(2) << setfill('0') << train_list[i][2];
                    cout<<"  "<< setw(2) << setfill('0')<< train_list[i][3] << ":";
                    cout<<setw(2) << setfill('0')<< train_list[i][4] <<"  ";
                    cout<< setw(2) << setfill('0')<< train_list[i][1]-vec[train_list[i][0]-1][1] << ":";
                    cout<<setw(2) << setfill('0')<< train_list[i][2]-vec[train_list[i][0]-1][2] <<endl;
                }
            }
            
            i++;
            
    
        }
        cout<<endl;
    
    }
	return 0;
}