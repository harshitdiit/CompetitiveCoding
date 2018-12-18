#include<bits/stdc++.h>
using namespace std;

#define finput ifstream cin;cin.open("in.txt")

struct point{
  long long x, y;
};


long long countBlack(point p1, point p2){
  long long t = (p2.x-p1.x+1)*(p2.y-p1.y+1);
  if(t%2){
    if((p1.x+p1.y)%2){
      return t/2+1;
    }
    else{
      return t/2;
    }
  }
  else{
    return t/2;
  }
}

long long countWhite(point p1, point p2){
  long long t = (p2.x-p1.x+1)*(p2.y-p1.y+1);
  if(t%2){
    if((p1.x+p1.y)%2){
      return t/2;
    }
    else{
      return t/2+1;
    }
  }
  else{
    return t/2;
  }
}

int main(){
  finput;

  point p, q;
  p.x=1; p.y=1;

  int T;
  cin>>T;
  while(T--){
    point p1, p2, p3, p4;
    cin>>q.x>>q.y;
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    cin>>p3.x>>p3.y>>p4.x>>p4.y;

    long long black, white;
    black = countBlack(p, q);
    white = countWhite(p, q);

    white = white + countBlack(p1, p2);
    black = black - countBlack(p1, p2);

    white = white - countWhite(p3, p4);
    black = black + countWhite(p3, p4);

    if(max(p1.x, p3.x)<=min(p2.x, p4.x) && max(p1.y, p3.y)<=min(p2.y, p4.y)){
      point p5, p6;
      p5.x = max(p1.x, p3.x);
      p5.y = max(p1.y, p3.y);
      p6.x = min(p2.x, p4.x);
      p6.y = min(p2.y, p4.y);

      black = black + countBlack(p5, p6);
      white = white - countBlack(p5, p6);

    }
    cout<<white<<" "<<black<<endl;
  }
  return 0;
}
