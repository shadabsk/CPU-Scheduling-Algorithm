/**
 * Title		:	CPU Scheduling algorithm (SJF)
 * Author		:	Shadab Shaikh
 * Date			:	05-04-2018
 * Version		:	1.0
 * Availability	:	https://github.com/shadabsk
 */
		#include<stdio.h>		//for using printf like function
		#include<stdlib.h>		//for using abs function
		int main()
		{
			int pn,pno[20],at[20],bt[20],i,tat[20],com[20],wt[20],temp,j;
			float avg,avg2,avgtat,avgwt;
			printf("Enter the number of process for SJF SCHEDULING\n");
			scanf("%d",&pn);
			printf("Enter the process 1 by 1\n");
			for(i=0;i<pn;i++)
				scanf("%d",&pno[i]);
			printf("Enter the process of Arrival time\n");
			for(i=0;i<pn;i++)
				scanf("%d",&at[i]);
			printf("Enter the process burst time\n");
			for(i=0;i<pn;i++)
				scanf("%d",&bt[i]);			//accepting burst time process number and arrival time from user
				
			for(i=0;i<pn;i++)
			{
				for(j=i+1;j<pn;j++)
				{
					if(at[i]>at[j])
					{
						temp=at[i];
						at[i]=at[j];
						at[j]=temp;
						
						temp=pno[i];
						pno[i]=pno[j];
						pno[j]=temp;
						
						temp=bt[i];
						bt[i]=bt[j];
						bt[j]=temp;
							
					}
				}
			}
			
			com[0]=bt[0]+at[0];
			
			if(com[0]>at[pn-1])
			{
				for(i=1;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(bt[i]>bt[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bt[i];
							bt[i]=bt[j];
							bt[j]=temp;
								
						}
					}
				}
				tat[0]=bt[0];
				wt[0]=0;
				
				
				for(i=1;i<pn;i++)
					com[i]=abs(com[i-1]+bt[i]);		//completion time
			}
			else
			{
				for(i=1;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(at[i]>at[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bt[i];
							bt[i]=bt[j];
							bt[j]=temp;
								
						}
					}
				}
				
				com[1]=bt[1]+at[1];
				
				for(i=2;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(bt[i]>bt[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bt[i];
							bt[i]=bt[j];
							bt[j]=temp;
								
						}
					}
				}
				
					tat[0]=bt[0];
					wt[0]=0;
					
					
					for(i=2;i<pn;i++)
						com[i]=abs(com[i-1]+bt[i]);		//completion time
			}
			
			for(i=0;i<pn;i++)
				tat[i]=abs(com[i]-at[i]);		//turn aroun time
				
				
			for(i=0;i<pn;i++)
				wt[i]=abs(tat[i]-bt[i]);		//waiting time
			
			for(i=0;i<pn;i++)
				avg=avg+tat[i];				//average TAT
			
			avgtat=avg/pn;
			
			for(i=0;i<pn;i++)
				avg2=avg2+wt[i];			//average WT
			
			avgwt=avg2/pn;
			
			
			printf("pno\tat\tbt\tcom\ttat\twt\t\n");
			for(i=0;i<pn;i++)
			{
				printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bt[i],com[i],tat[i],wt[i]);
			}
			
			printf("ATAT=  %f\nAWT= %f\n",avgtat,avgwt);			//displaying every values
			
		}
