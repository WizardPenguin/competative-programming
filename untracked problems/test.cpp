#include <iostream>
#include <graphics.h>
using namespace std;
int main() {
    int g = DETECT,gm;
    initgraph(&g, &gm, "");
    cout<<"input coordinates of line"<<endl; 
    cout<<"enter start coordinates of line"; 
    int x1,x2,y1,y2; 
    cout<<" x: "; 
    cin>>x1; 
    cout<<" y: "; 
    cin>>y1; 
    cout<<"enter ending coordinates of line"; 
    cout<<" x: "; 
    cin>>x2; 
    cout<<" y: "; 
    cin>>y2; 
    // draw line 
    line(x1, y1, x2, y2);
    // to stop screen till dummy is not pressed closegraph willn't be called 
    int dummy;
    cin>>dummy; 
    closegraph();
    return 0;
}