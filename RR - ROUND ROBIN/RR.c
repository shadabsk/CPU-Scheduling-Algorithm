/**
 * Title		:	CPU Scheduling algorithm (RR)
 * Author		:	Shadab Shaikh
 * Date			:	18-03-2018
 * Version		:	1.0
 * Availability	:	https://github.com/shadabsk
 */
		#include<stdio.h>		//for using printf like function
		#include<stdlib.h>		//for using abs function
		int main()
		{
			int pn,pno[50]={0},at[50],bt[50],i,tat[50],com[50],wt[50],temp,j,qm,bttemp[50],btttemp[50]={0},tattemp[50]={0},tatat[50]={},tatttemp[50]={},wtbt[50],wttbt[50]={};
			float avg,avg2,avgtat,avgwt;
			printf("Enter the number of process for RR SCHEDULING\n");
			scanf("%d",&pn);
			printf("Enter the process 1 by 1\n");
			for(i=0;i<pn;i++)
				scanf("%d",&pno[i]);
			printf("Enter the process of Arrival time\n");
			for(i=0;i<pn;i++)
				scanf("%d",&at[i]);
			printf("Enter the process burst time\n");
			for(i=0;i<pn;i++)
				scanf("%d",&bt[i]);	
			printf("Enter the quantum\n");
				scanf("%d",&qm);	
				
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
			
			
			for(i=0;i<pn;i++)	
			{		
				bttemp[i]=bt[i]-qm;
				if(bttemp[i]<0)
				{
					bttemp[i]=bt[i];
					btttemp[i]=bttemp[i];
					bttemp[i]=0;
				}
				if(bt[i]<=qm)
					bttemp[i]=bt[i]-bt[i];	
				
			}
			
			
			for(i=0;i<pn;i++)
			{
				if(bttemp[i]==bttemp[i+1])
				{
					com[0]=bt[0]+at[0];
					tat[0]=bt[0];
					wt[0]=0;
					for(i=1;i<pn;i++)
						com[i]=abs(com[i-1]+bt[i]);		//completion time
					
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
				else if(bttemp[i]>bttemp[i+1]||bttemp[i]<bttemp[i+1])
				{
					if(bttemp[0]>=qm)
						com[0]=at[0]+qm;
					else
						com[0]=at[0]+bt[0];
					
					for(i=1;i<pn;i++)
					{
						if(bt[i]>=qm)
							com[i]=com[i-1]+qm;
						else
							com[i]=com[i-1]+bt[i];
							
					}
			
					for(i=0;i<pn;i++)
					{
						
						if(bttemp[i]>0)
						{
							pno[i+pn]=pno[i];
							at[i+pn]=at[i];
							bt[i+pn]=bt[i];
							bttemp[i+pn]=bttemp[i]-qm;
							if(bttemp[i+pn]<0)
							{
								bttemp[i+pn]=bttemp[i];
								btttemp[i]=bttemp[i+pn];
								bttemp[i+pn]=0;
							}
							if(bttemp[i]<=qm)
								bttemp[i+pn]=bttemp[i]-bttemp[i];
							
						}
						else
						{
							pno[i+pn]=0;
							at[i+pn]=0;
							bt[i+pn]=0;
							bttemp[i+pn]=0;
						}
					}
				
			
					for(i=0;i<pn;i++)
					{
						if(bttemp[i+pn]!=-1)
						{
							if(bttemp[i+pn]>=qm)
								com[i+pn]=com[i+pn-1]+qm;
							else
								com[i+pn]=com[i+pn-1]+btttemp[i];
						}
						else
						{
							com[i+pn]=0;
						}
						
					}
					for(i=pn;i<pn+pn-1;i++)
					{
						
						if(bttemp[i]>0)
						{
							pno[i+pn-1]=pno[i];
							at[i+pn-1]=at[i];
							bt[i+pn-1]=bt[i];
							bttemp[i+pn-1]=bttemp[i]-qm;
							if(bttemp[i+pn-1]<0)
							{
								bttemp[i+pn-1]=bttemp[i];
								btttemp[i]=bttemp[i+pn-1];
								bttemp[i+pn-1]=0;
							}
							if(bttemp[i]<=qm)
								bttemp[i+pn-1]=bttemp[i]-bttemp[i];
						}
						else
						{
							pno[i+pn-1]=0;
							at[i+pn-1]=0;
							bt[i+pn-1]=0;
							bttemp[i+pn-1]=0;
						}
						
					}
					
					for(i=pn;i<pn+pn-1;i++)
					{
						if(bttemp[i+pn-1]!=-1)
						{
							if(bttemp[0+pn]>=qm)
								com[i+pn-1]=com[i+pn-1]+qm;
							else
								com[i+pn-1]=com[i+pn-1]+btttemp[i];
						}
						else
						{
							com[i+pn-1]=0;
						}
					}
			
					for(i=pn+pn-1;i<pn+pn+1;i++)
					{
						if(bttemp[i]>0)
						{
								pno[i+1]=pno[i];
								at[i+1]=at[i];
								bt[i+1]=bt[i];
								bttemp[i+1]=bttemp[i]-qm;
								if(bttemp[i+1]<0)
								{
									bttemp[i+1]=bttemp[i];
									btttemp[i]=bttemp[i+1];
									bttemp[i+1]=0;
								}
								if(bttemp[i]<=qm)
									bttemp[i+1]=bttemp[i]-bttemp[i];
						}
						else
						{
							pno[i+1]=0;
							at[i+1]=0;
							bt[i+1]=0;
							bttemp[i+1]=0;
						}
						
					}
			
					for(i=pn+pn-1;i<pn+pn+1;i++)
					{
						if(bttemp[i+1]!=-1)
						{
							if(bttemp[i]>=qm)
								com[i+1]=com[i]+qm;
							else
								com[i+1]=com[i]+btttemp[i];
						}
						else
						{
							com[i+1]=0;
						}
					}
					
					for(i=0;i<pn+pn+1;i++)
					{
						tattemp[i]=com[i];
						tatat[i]=at[i];
						wtbt[i]=bt[i];
					}
					
					
					for(i=0;i<pn+pn+1;i++)		
					{
						for(j=i+1;j<pn+pn+1;j++)
						{
							if(tatat[i]>tatat[j])
							{
								temp=tatat[i];
								tatat[i]=tatat[j];
								tatat[j]=temp;
								
								temp=tattemp[i];
								tattemp[i]=tattemp[j];
								tattemp[j]=temp;
								
									
								temp=wtbt[i];
								wtbt[i]=wtbt[j];
								wtbt[j]=temp;
								
							}
						}
					}
					
					for(i=0;i<pn+pn+1;i++)
					{
							if(tatat[i]!=tatat[i+1])
							{
									tatttemp[i]=tattemp[i];
									wttbt[i]=wtbt[i];				
							}
					}
					
					for(i=0;i<pn+pn+1;i++)
					{
							tat[i]=tatttemp[i]-tatat[i];
							if(tat[i]<0)
								tat[i]=0;
							wt[i]=tat[i]-wttbt[i];
							if(wt[i]<0)
								wt[i]=0;
					}
					
					
					
					
					for(i=0;i<pn+pn+1;i++)
						avg=avg+tat[i];				//average TAT

					avgtat=avg/pn;
					
					for(i=0;i<pn+pn+1;i++)
						avg2=avg2+wt[i];			//average WT
					
					avgwt=avg2/pn;
					
					
					printf("pno\tat\tbt\tcom\ttat\twt\t\n");
					for(i=0;i<pn+pn+1;i++)
					{
						printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bttemp[i],com[i],tat[i],wt[i]);
					}
					
					printf("ATAT=  %f\nAWT= %f\n",avgtat,avgwt);			//displaying every values*/
				}
			}
			
				
			
			
			
			
		}
