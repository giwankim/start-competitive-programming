#include <iostream>

using namespace std;

int isCovered(int x, int y, int x1, int y1, int x2, int y2){
  if (x>=x1 && x<=x2 && y>=y1 && y<=y2)
    return 1;
  return 0;
}


int main() {

    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);

    int b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2;

    cin >> b1x1 >> b1y1 >> b1x2 >> b1y2; //lawnmower
    cin >> b2x1 >> b2y1 >> b2x2 >> b2y2; //cow feed

  	int coveredCorners = 0;
    coveredCorners += isCovered(b1x1,b1y1,b2x1,b2y1,b2x2,b2y2);
    coveredCorners += isCovered(b1x1,b1y2,b2x1,b2y1,b2x2,b2y2);
    coveredCorners += isCovered(b1x2,b1y1,b2x1,b2y1,b2x2,b2y2);
    coveredCorners += isCovered(b1x2,b1y2,b2x1,b2y1,b2x2,b2y2);

   int tarpArea;
   if (coveredCorners >=3) tarpArea = 0;
   if (coveredCorners <=1) tarpArea = (b1x2-b1x1)*(b1y2-b1y1);
   if (coveredCorners ==2){
     int overlapX = min(b1x2, b2x2) - max(b1x1, b2x1);
     int overlapY = min(b1y2, b2y2) - max(b1y1, b2y1);
     tarpArea = (b1x2-b1x1)*(b1y2-b1y1) - overlapX*overlapY ;

   }

      cout << tarpArea;

    return 0;
}
