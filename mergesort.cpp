#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void merge (vector<int> &vec, int start, int end){
    int el_num = end-start;
    int mid = (start+end)/2;
    vector<int> temp;
    int i = start;
    int i_end = mid;
    int j = mid;
    while(temp.size()<el_num){
        
        if(vec[j]<=vec[i]){
            temp.push_back(vec[j]);
            j++;
        }
        else{
            temp.push_back(vec[i]);
            i++;
        }
    }
    if(i>(j-mid)){
        temp.insert(temp.end(),vec.begin()+j,vec.end());
    }
    else if (i<(j-mid)){
        temp.insert(temp.end(),vec.begin()+i,vec.begin()+mid);
    }
    cout<<start<<"\t"<<end<<endl;
    cout<<"--------"<<endl;
    for (int i = start; i<end;i++){
        vec[i] = temp[i-start];
        cout<<i<<"\t"<<i-start<<endl;
    }
    cout<<"#######"<<endl;
}

void merge_sort(vector<int> &vec, int start, int end){
    int el_num = end-start;

    //Base case
    if((el_num)<2)return;
    else if ((el_num) == 2) { 
        if(vec[start]>vec[end]){
            swap(vec[start],vec[end]);
        }
        return;
    }
    
    //###Recursive case##
    int mid = (start+end)/2;

    //Divide
    merge_sort(vec,start,mid);
    merge_sort(vec,mid,end);

    //Merge
    merge(vec,start,end);
}

int main(){
    vector<int> vec = {5,6,8,23,5,2,2,0};
    function<void(vector<int>&,int,int)> func = merge_sort;
    func(vec,0,7);

    for(int num: vec){
        cout<<num<<endl;
    }
    return 0;


}

// vector<int> merge(vector<int> arr1, vector<int> arr2){
// //     int i = 0;
//     int j = 0;
//     vector<int> result;
//     while(i<arr1.size()&&j<arr2.size()){
//         if(arr1[i]<=arr2[j]){
//             result.push_back(arr1[i]);
//             i++;
//         }
//         else{
//             result.push_back(arr2[j]);
//             j++;
//         }
//     }
//     if(i<j){
//         result.insert(result.end(),arr1.begin()+i,arr1.end());
//     }
//     else if(i>j){
//         result.insert(result.end(),arr2.begin()+j,arr2.end());
//     }
//     return result;
// }