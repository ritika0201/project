# include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ int n,f=0,temp;
float avg_wt,avg_tat,total;
int bt[20],p[20],wt[20],tat[20];
y:
cout<<"Enter the number 0f process\n";
cin>>n;
if(n==0)
{
cout<<"enter the valid process"<<endl;
goto y;
}
temp=0;
double priority[n];
int arrival[10],waiting[10];
for (int i=0;i<n;i++)
{
p[i]=i+1;
priority[i]=0;
}
cout<<"Enter the burst time for "<<n<<" PROCESSES";
x:
for (int i=0;i<n;i++)
{
cin>>bt[i];
if(bt[i]==0)
{
cout<<"enter valid burst time";
goto x;
}
}
cout<<endl;
for(int i=0;i<n;i++)
{
int pos=i;
for(int j=0;j<n;j++)
{
if(bt[j]<bt[pos]);
pos=j;
}
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0; //waiting time for the first process will be zero
//calculating waiting time
for(int i=1;i<n;i++)
{
wt[i]=0;
for(int j=0;j<i;j++)
{
wt[i]+=bt[j];
}
total+=wt[i];
}
avg_wt=(float)total/n;
total=0;
printf("\nProcess\t Burst time \tWaiting
time\tturnaround time");
for(int i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\np%d\t\t %d\t\t
%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
avg_tat=(float)total/n;
cout<<"\n\nAverage waiting time "<<avg_wt;
cout<<"\nAverage Turnaround time "<<avg_tat;
for(int i=0;i<n;i++)
{
int pos=i;
for(int j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
pos=j;
}
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
cout<<"\nPROCESS EXECUTION ACCORDING TO THE
PRIORITY"<<endl;
waiting[0]=0,priority[0]=0;
cout<<"PROCESS ID "<<p[0]<<" succesfully completes its
execution"<<endl;
for(int i=1;i<n;i++)
{
for(int k=i;k<n;k++)
{
waiting[k]=0;
for(int j=0;j<k;j++)
{
waiting[k]+=bt[j];
}
}
for(int l=i;l<n;l++)
{
priority[l]=0;
double z=((double)waiting[l]/(double)bt[l]);
priority[l]=1+z;
}
for(int m=i;m<n;m++)
{
int pos=m;
for(int j=m+1;j<n;j++)
{
if(priority[j]<priority[pos])
pos=j;
}
temp=priority[m];
bt[m]=priority[pos];
priority[pos]=temp;
temp=p[m];
p[m]=p[pos];
p[pos]=temp;
}
cout<<"PROCESS ID "<<p[i]<<" succesfully completes ite
execution"<<endl;
}
}
