/******************************************************************************
BunnyTHEcoder
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int recursive(int n){
    if(n==1 || n==0){
        return n;
    }
    else{
        return(recursive(n-1) + recursive(n-2));
    }
}

void non_recursive(int n){
    int first = 0,last=1;
    if(n==1 || n==0){
        cout<<n<<endl;
        return;
    }
    else{
        cout<<0<<" "<<1<<" ";
        for(int i=2;i<n;i++){
            int cur = last + first;
            first = last;
            last = cur;
            cout<<cur<<" ";
        }
    }
}

int main()
{
    int n,i=0;
    cin>>n;

    // Recursive way
    while(i < n) {
      cout << " " << recursive(i);
      i++;
    }
    cout<<endl;

    // non_recursive way;
    non_recursive(n);

    return 0;
}
