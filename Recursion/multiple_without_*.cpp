/**
 * Author: Tanmay Jha
 * Date: 07/06/2018
 * Email: tanmay.jha1@gmail.com
 */

#include<bits/stdc++.h>

using namespace std;

int multiply(int x,int y){
    
    if(y==0||x==0)
       return 0;

    if(x<0&&y>0)
        return (x+multiply(x,y-1));
    
    else if(y<0&&x>0)
        return (y+multiply(x-1,y));
    
    else {
        if(x<0){
            x=-x;
            y=-y;
        }
        return (x+multiply(x,y-1));
    }

}

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<multiply(x,y);
    cout<<endl;
    return 0;
} 

        
