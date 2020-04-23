#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

char memarr[77000000]; void *mem = memarr;
#define MD 1000000007

int N;
double dp[120];
double C[120][120];
double pw[120];

double prob(int x, int y, int z){
  int s = x + y + z;
  return pw[s] * C[s][x] * C[s-x][y];
}

int main(){
  int i, j, k;
  int x, y, z, nx;
  int arr[3];
  double p, dame;

  rep(i,120) C[0][i] = 0;
  rep(i,120) C[i][0] = 1;
  REP(i,1,120) REP(j,1,120) C[i][j] = C[i-1][j-1] + C[i-1][j];

  pw[0] = 1;
  REP(i,1,120) pw[i] = pw[i-1] / 3;

  dp[0] = dp[1] = 0;
  REP(i,2,101){
    dp[i] = 0;
    dame = 0;
    rep(x,i+1) rep(y,i+1){
      z = i - x - y;
      if(z < 0) continue;

      p = prob(x, y, z);
      arr[0] = x;
      arr[1] = y;
      arr[2] = z;
      sort(arr, arr+3);
      if(arr[0]==arr[2]){ dame += p; continue; }
      if(arr[0]==0 && arr[1]==0){ dame += p; continue; }
      nx = arr[0];
      if(nx==0) nx = arr[1];
      dp[i] += (dp[nx] + 1) * p;
    }
    dp[i] = (dp[i] + dame) / (1 - dame);
  }

  reader(&N);
  writerLn(dp[N]);

  return 0;
}
