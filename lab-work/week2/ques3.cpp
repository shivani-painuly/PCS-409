#include <iostream>
using namespace std;

void sequenceFinder(int arr[], int n){
    for(int i=0; i<n; i++){
        int x = arr[i];
        for(int j=i+1; j<n; j++){
            int y = arr[j];
            for(int k=j+1; k<n; k++){
                int z = arr[k];
                if(z>x+y)   break;
                if(x+y==z){
                    cout<<i+1<<", "<<j+1<<", "<<k+1<<endl;
                    //cout<<x<<", "<<y<<", "<<z<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No sequence found\n";
}

int main()
{    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sequenceFinder(arr, n);

    }

    return 0;
}
