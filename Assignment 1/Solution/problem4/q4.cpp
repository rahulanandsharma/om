#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<glpk.h>
#include<cmath>
#include<fstream>
#define N 9

using namespace std;
int ia[1000000],ja[1000000],D[N+1][N+1];
double ar[1000000];

int main()
{
string arr;
int cnt=1;
while(getline (std::cin,arr))
{	
	int X,z,i,j,k,l,m,n,o,p,q;
	int C=1;
	double a;
	
	if(cnt==0)
	{
	cout<<endl;
	}
	else
	{
	cnt=0;
	}

	
	glp_term_out(GLP_OFF);
	glp_prob *lp;
	lp=glp_create_prob();
	glp_set_prob_name(lp,"SDK");
	glp_set_obj_dir(lp,GLP_MAX);
	glp_add_rows(lp,4*N*N);
	glp_add_cols(lp,N*N*N);

	m=1;

	for(i=1;i<=N;i++)             // sum(xijk) over k for each i,j is 1
	{
		for(j=1;j<=N;j++)
		{
			for(k=1;k<=N;k++)
			{
				ia[m]= C;
				ja[m]= (i-1)*N*N+(j-1)*N+k;
				ar[m]= 1;
				m++;
			}
			C++;
		}
	}

	for(i=1;i<=N;i++)
	{
		for(k=1;k<=N;k++)
		{
			for(j=1;j<=N;j++)
			{
				ia[m] = C;
				ja[m] = (i-1)*N*N+(j-1)*N+k;
				ar[m]=1;
				m++;
			}
			C++;
		}
	}

	for(j=1;j<=N;j++)
	{
		for(k=1;k<=N;k++)
		{
			for(i=1;i<=N;i++)
			{
				ia[m] = C;
				ja[m] = (i-1)*N*N+(j-1)*N+k;
				ar[m]=1;
				m++;
			}
			C++;
		}
	}

	for(i=0;i<=2*sqrt(N);i+=sqrt(N))
	{
		for(j=0;j<=2*sqrt(N);j+=sqrt(N))
		{
			for(k=1;k<=N;k++)
			{
				for(p=1;p<=sqrt(N);p++)
				{
					for(o=1;o<=sqrt(N);o++)
					{
						ia[m]=C;
						ja[m]=(i+p-1)*N*N+(j+o-1)*N+k;
						ar[m]=1;
						m++;
					}
				}
			C++;
			}
		}
	}
	//cout<<m<<endl;

	char ch;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
			{
			ch=getchar();
			D[i][j]=ch-48;
			}
		getchar();
	}

	for(i=1;i<=4*N*N;i++)
	{
		glp_set_row_bnds(lp,i,GLP_FX,1.0,1.0);
	}

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			for(k=1;k<=N;k++)
			{
				glp_set_obj_coef(lp,(i-1)*N*N+(j-1)*N+k,1);
				glp_set_col_kind(lp,(i-1)*N*N+(j-1)*N+k,GLP_IV);
				if(D[i][j]==k)
				{
					glp_set_col_bnds(lp, (i-1)*N*N+(j-1)*N+k,GLP_FX,1.0,1.0);
				}
				else
				{
					glp_set_col_bnds(lp, (i-1)*N*N+(j-1)*N+k,GLP_DB,0.0,1.0);
				}
			}
		}
	}
	glp_load_matrix(lp,m-1,ia,ja,ar);
	glp_iocp sol;
	glp_init_iocp(&sol);
	sol.presolve=GLP_ON;

 	X=glp_intopt(lp,&sol);
	
	
	z = glp_mip_obj_val(lp);
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
		{

			for(k=1; k<=N; k++)
			{
				a = glp_mip_col_val(lp,N*N*(i-1)+N*(j-1)+k);
				if((int)a==1)
				{
					cout<<k<<"";

				}
			}
		}
		cout<<endl;
	}
	glp_delete_prob(lp);
	
}
}
