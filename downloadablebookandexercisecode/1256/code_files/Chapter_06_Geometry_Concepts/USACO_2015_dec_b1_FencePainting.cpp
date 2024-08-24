

#include <iostream>

using namespace std;

int main(){

    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    int a,b,c,d;
    cin >> a >> b ;
    cin >> c >> d;

    int l = 0;

    // Naive way

    // no overlap
    if (b <= c || d <= a){
        l = (b - a) + (d - c);
    }
    else if ( b<=d ){
        if (a <=c ) l= d - a;
        else l = d - c;
    }  else if ( a >=c ){
        if (b <= d) l = d - c;
        else l = b - c;
    }
    // end of Naive way

    // clean way

    int leftOverlap = max(a,c);
    int rightOverlap = min(b,d);
    int overlap = (rightOverlap > leftOverlap ) ? rightOverlap - leftOverlap  : 0 ;

    l = (b-a) + (d-c) - overlap;

    // end of clean way



    cout << l;
    return 0;
}