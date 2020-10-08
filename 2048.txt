#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
int print(int a[][4],int k,int ok);
int bakht(int a[4][4],int ok);
int main(){
	
	int marzi=9,lose=0,k=0,ok=0,harekat=0,score=0,hi=0,i,j,i1,j1;
	while(marzi==9){
		int a[4][4]={0};
		
		score=0;
		while(lose==0){
			
			if(hi==0){
				k++;
				srand(time(NULL));
				while(marzi==9){
					i1=rand()%4;
					j1=rand()%4;
					//printf("%d",k);
					if(a[i1][j1]==0){
						int tmp;
						tmp=rand()%10;
						if(tmp==8 || tmp==9){
							a[i1][j1]=4;
						}
						else{
							a[i1][j1]=2;
						}
						break;
					}
				}
			}
			print(a,k,ok);
			harekat=0;
			int ch;
			ch=_getch();
			if(ch=='e'){
				system("cls");
				return 0;
			}
			if(ch=='n'){
				system("cls");
				break;
			}
			//rast.....................................................................................................
			if(ch==77){
				int B[4][4]={0};
				int adaddarim=0;
				ok=0;
				k=0;
				int i2,j2;
				for(i2=0;i2<4;i2++){
					for(j2=2;j2>-1;j2--){
						if(a[i2][j2]!=0){
							adaddarim=1;
							int b=j2;
							while(b<3){
							
								
								
								if(a[i2][b]==a[i2][b+1]){
									if(B[i2][b+1]==1)
										break;
									B[i2][b+1]=1;
									hi=0;
									harekat=1;
								
									a[i2][b]=0;
									a[i2][b+1] *=2;
									score+=a[i2][b+1];
									if(a[i2][b+1]==2048){
										printf("\n\n                                                ");
										printf("(^_^) YOU WIN (^_^)");
									}
									break;
								}
								
								if(a[i2][b]!=a[i2][b+1] && a[i2][b+1]!=0){
									
									break;
								}
								if(a[i2][b+1]==0){
									hi=0;
									harekat=1;
									a[i2][b+1]=a[i2][b];
									a[i2][b]=0;
									b++;
								}
							
							}
							
						}
					}
				}
				
				//tashkhis bakht.............................................................................................
				for(j=0;j<4;j++){
					for(i=0;i<4;i++){
						if(a[i][j]!=0){
							k++;}
					}
				}
				ok=bakht(a,ok);
				
				if(adaddarim==0 || harekat==0){
					hi=56;
					system("cls");
				
					continue;	
				
				}
				//.....................................................................................................
				system("cls");
				
				continue;	
				
			}
			//chap....................................................................................................................
			if(ch==75){
				int B[4][4]={0};
				ok=0;
				k=0;
				int adaddarim=0;
				int i2,j2;
				for(i2=0;i2<4;i2++){
					for(j2=1;j2<4;j2++){
						if(a[i2][j2]!=0){
							adaddarim=1;
							int b=j2;
							while(b>0){
							
								
								
								
								
								if(a[i2][b]==a[i2][b-1]){
									if(B[i2][b-1]==1)
										break;
									B[i2][b-1]=1;
									
									hi=0;
									harekat=1;
									a[i2][b]=0;
									a[i2][b-1] *=2;
									score+=a[i2][b-1];
									if(a[i2][b-1]==2048){
										printf("\n\n                                                ");
										printf("(^_^) YOU WIN (^_^)");
									}
									break;	
								}
								if(a[i2][b]!=a[i2][b-1] && a[i2][b-1]!=0){
									break;
								}
								if(a[i2][b-1]==0){
									hi=0;
									harekat=1;
									a[i2][b-1]=a[i2][b];
									a[i2][b]=0;
									b--;
								}
							
							}
							
						}
					}
				}
				//tashkhis bakht.............................................................................................
				for(j=0;j<4;j++){
					for(i=0;i<4;i++){
						if(a[i][j]!=0){
							k++;}
					}
				}
				
				bakht(a,ok);
				if(adaddarim==0 || harekat==0){
					hi=34;
					system("cls");
				
					continue;	
				
				}
				//.....................................................................................................
				system("cls");
				
				continue;	
				
			}
			//paeen.....................................................................................................................
			if(ch==80){
				int B[4][4]={0};
				ok=0;
				k=0;
				int adaddarim=0;
				int i2,j2;
				for(j2=0;j2<4;j2++){
					for(i2=2;i2>-1;i2--){
						if(a[i2][j2]!=0){
							adaddarim=1;
							int b=i2;
							while(b<3){
							
								
								if(a[b][j2]==a[b+1][j2]){
									if(B[b+1][j2]==1)
										break;
									B[b+1][j2]=1;
									
									hi=0;
									harekat=1;
									a[b][j2]=0;
									a[b+1][j2] *=2;
									score+=a[b+1][j2];
									if(a[b+1][j2]==2048){
										printf("\n\n                                                ");
										printf("(^_^) YOU WIN (^_^)");
									}
								 	break;
								}
								
								if(a[b][j2]!=a[b+1][j2] && a[b+1][j2]!=0){
									
									break;
								}
								
								
								if(a[b+1][j2]==0){
									hi=0;
									harekat=1;
									a[b+1][j2]=a[b][j2];
									a[b][j2]=0;
									b++;
								}
							
							}
							
						}
					}
				}
				
				//tashkhis bakht.............................................................................................
				for(j=0;j<4;j++){
					for(i=0;i<4;i++){
						if(a[i][j]!=0){
							k++;}
					}
				}
				ok=bakht(a,ok);
				if(adaddarim==0 || harekat==0){
					hi=56;
					system("cls");
				
					continue;	
				
				}
				//.....................................................................................................
				system("cls");
				
				continue;	
				
			}
			//bala....................................................................................................................
			if(ch==72){
				int B[4][4]={0};
				ok=0;
				k=0;
				int adaddarim=0;
				int i2,j2;
				for(j2=0;j2<4;j2++){
					for(i2=1;i2<4;i2++){
						
						if(a[i2][j2]!=0){
							adaddarim=1;
							int b=i2;
							while(b>0){
								
								if(a[b][j2]==a[b-1][j2]){
									if(B[b-1][j2]==1)
										break;
									B[b-1][j2]=1;
									
									hi=0;
									harekat=1;
									a[b][j2]=0;
									a[b-1][j2] *=2;
									score+=a[b-1][j2];
									if(a[b-1][j2]==2048){
										printf("\n\n                                                ");
										printf("(^_^) YOU WIN (^_^)");
									}
									
								}
								if(a[b][j2]!=a[b-1][j2] && a[b-1][j2]!=0){
									break;
								}
								if(a[b-1][j2]==0){
									hi=0;
									harekat=1;
									a[b-1][j2]=a[b][j2];
									a[b][j2]=0;
									b--;
								}
							
							}
							
						}
					}
				}
				//tashkhis bakht.............................................................................................
				for(j=0;j<4;j++){
					for(i=0;i<4;i++){
						if(a[i][j]!=0){
							k++;}
					}
				}
				ok=bakht(a,ok);
				if(adaddarim==0 || harekat==0){
					hi=34;
					system("cls");
				
					continue;	
				
				}
				//.....................................................................................................
				system("cls");
				
				continue;	
				
			}
			
			//0_0............................................................................................................................
			else{
				hi=24;
				system("cls");
				continue;
			}
		}
		continue;
	}
}
int print(int a[4][4] ,int k,int ok ){
	int i,j,score;
	printf("\n                                                    YOUR SCORE : %d\n",score);
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,187);
			
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(j==0){
						printf("                                                ");
					}
				 	printf("%c",186);
					 if(a[i][j]==0){
				 		printf("    ");
				 	}
				 	else{
				 		printf("%-4d",a[i][j]);
				 	}
					if(j==3){
						printf("%c\n",186);
					}
				
				}
				printf("                                                ");
				if(i==1 || i==2 || i==0){
					printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185);
				}
					
			}
			
			
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,188);
			
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
			printf("\n                                                %cplay with arrow keys%c\n",177,177);
			printf("                                                ");
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177);
			printf("                                                press N to new game\n");
			
			printf("                                                press E to exit\n");
			
			if(k==16 && ok==8){
				printf("\n\n                                                ");
				printf("(+_+) YOU LOSE (+_+)\n");
				
				
			}
			return 0;
			
}
int bakht(int a[4][4],int ok){
			if(a[0][0]!=a[0][1] && a[0][0]!=a[1][0]){
				ok++;}
			if(a[0][2]!=a[0][1] && a[0][2]!=a[1][2] && a[0][2]!=a[0][3]){
				ok++;}
			if(a[1][1]!=a[0][1] && a[1][1]!=a[1][0] && a[1][1]!=a[1][2] && a[1][1]!=a[2][1]){
				ok++;}
			if(a[1][3]!=a[1][2] && a[1][3]!=a[0][3] && a[1][3]!=a[2][3]){
				ok++;}
			if(a[2][0]!=a[1][0] && a[2][0]!=a[2][1] && a[2][0]!=a[3][0]){
				ok++;}
			if(a[2][2]!=a[2][1] && a[2][2]!=a[1][2] && a[2][2]!=a[2][3] && a[2][2]!=a[3][2]){
				ok++;}
			if(a[3][1]!=a[2][1] && a[3][1]!=a[3][0] && a[3][1]!=a[3][2]){
				ok++;}
			if(a[3][3]!=a[3][2] && a[3][3]!=a[2][3]){
				ok++;}
			return ok;
}
