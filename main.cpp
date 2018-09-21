#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void print_vector(vector<int> v){
    int size = v.size();
    for(int i=0; i < size; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void selection_sort(vector<int> &v){
    int size = v.size();
    for(int i=0; i < size; i++){
        //print_vector(*v);
        int min = INT_MAX;
        int min_index = i;
        for(int j=i; j < size; j++){
            int next_num = v[j];
            if(next_num < min){
                min = next_num;
                min_index = j;
            }
        }
        int temp = v[i];
        v[i] = min;
        v[min_index] = temp;
    }
}

int qc_partition(vector<int> &v, int left, int right){
    int p = right; //pivot
    int l = left;  //left
    while(l < p){
        if(v[l] <= v[p]){
            l++;
        }
        else{
            int l_val = v[l];
            int m_val = v[p-1];
            int p_val = v[p];
            v[l] = m_val;
            v[p-1] = p_val;
            v[p] = l_val;
            p--;
        }
    }
    return p;
}

void quick_sort(vector<int> &v, int low, int high){
    if(low < high){
        int p = qc_partition(v, low, high);
        quick_sort(v, low, p-1);
        quick_sort(v, p+1, high);
    }
}

void merge(vector<int> &v, int l, int m, int h){
    vector<int> v_help;
    int p1_left = l;
    int p1_right = m;
    int p2_left = m+1;
    int p2_right = h;
    for(int i=l; i <= h; i++){
        if(p1_left > p1_right){
            v_help.push_back(v[p2_left]);
            p2_left++;
        }
        else if(p2_left > p2_right){
            v_help.push_back(v[p1_left]);
            p1_left++;
        }
        else if(v[p1_left] < v[p2_left]){
            v_help.push_back(v[p1_left]);
            p1_left++;
        }
        else{
            v_help.push_back(v[p2_left]);
            p2_left++;
        }
    }
    int vsize = v_help.size();
    for(int i=0; i < vsize; i++){
        v[l+i] = v_help[i];
    }
}

void merge_sort(vector<int> &v, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        merge_sort(v, low, mid);
        merge_sort(v, mid+1, high);
        merge(v, low, mid, high);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int num_ints;
    vector<int> intarr;
    cin >> num_ints;
    for(int i=0; i<num_ints; i++){
        int next_num;
        cin >> next_num;
        intarr.push_back(next_num);
    }
    
    //selection_sort(intarr);
    //quick_sort(intarr, 0, num_ints-1);
    merge_sort(intarr, 0, num_ints-1);
    //sort(intarr.begin(), intarr.end());
    print_vector(intarr);
    
    return 0;
}
