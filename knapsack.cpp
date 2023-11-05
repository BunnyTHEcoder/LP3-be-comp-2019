/******************************************************************************
BunnyTHEcoder
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
void value_to_weight_ratio_sort(float values[] , float weights[] ,  vector<int> indexes , int n,float max_weight,float max_value,vector<float> fractions){
    float value_by_weight[n];
    int  i = n-1;
    while(i>=0){
        value_by_weight[i] = values[i] / weights[i] ;
        i--;
    }
    for(int j=0;j<n;j++){
        float maxx = INT_MIN;
        int m_index = 0;
        for(int i =0;i<n;i++){
            if(maxx < value_by_weight[i]){
                m_index = i;
                maxx = value_by_weight[i];
            }
        }
        indexes.push_back(m_index);
        value_by_weight[m_index] = 0;
    }
    for(int i=0;i<n;i++){
        int a = indexes[i];
        if(max_weight > weights[a] ){
            max_weight -= weights[a];
            max_value += values[a];
            fractions[a] =1;
        }
        else{
            max_value += (max_weight / weights[a]) * values[a];
            fractions[a] = max_weight / weights[a] ;
            break;
        }
    }
    cout<<"The maximum value of items that can be carried: "<<max_value <<endl;
    cout<<"The fractions in which the items should be taken: ";
    for(int i=0;i<n;i++){
        cout<<fractions[i]<<" ";
    }
    
    

}

int main()
{
    int n;
    cin>>n;
    float max_weight,max_value;
    float values[n];
    float weights[n];
    vector<int> indexes;
    vector<float> fractions(n, 0);
    for(int i =0;i<n;i++){
        cin>>values[i];
    }
    for(int i =0;i<n;i++){
        cin>>weights[i];
    }
    cin>>max_weight;
    value_to_weight_ratio_sort(values , weights , indexes , n,max_weight,max_value,fractions);
    
    

    return 0;
}