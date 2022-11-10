#include<stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool comp(const pair<int, int> &p1,const pair<int, int> &p2){
    
    if(p1.second == p2.second){     //빈도수가 같으면 
        return p1.first < p2.first; //숫자(key)작은게 앞으로 
    }
    return p1.second > p2.second;    //다르면 빈도수가 큰게 앞으로 
    
}

void swap(int* arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int main(int argc, char const *argv[])
{
    int arrsize = 0;
    int arr[500001];
    int sum = 0, G = -4000, L = 4000, average1, average2, average3, average4;


    scanf("%d", &arrsize);
    for (int i = 0; i < arrsize; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 힙 구조 만들기
    for (int i = 0; i < arrsize; i++)
    {
        // 산술평균
        sum+=arr[i];

        // 최댓값
        if (arr[i] > G)
        {
            G = arr[i];
        }
        // 최솟값
        if (arr[i] < L)
        {
            L = arr[i];
        }
        
        int c = i;
        int root;
        do
        {
            root = (c-1)/2 ;
            if (arr[root] < arr[c])
            {
                swap(arr, root, c);
            }
            c = root;
        } while (c != 0);
        
    }
    // 하나씩 줄여가면서 뒤로 보냄
    for (int i = arrsize-1; i >= 0; i--)
    {
        int c = 1;
        int root = 0;
        swap(arr, 0, i);
        do
        {
            c = root*2 + 1;
            if (arr[c] < arr[c+1] && c < i-1)
            {
                c++;
            }
            
            if (arr[root] < arr[c] && c< i)
            {
                swap(arr,root,c);
            }
            root = c;
        } while (c < i);
        
    }
    // 산술평균
    average1 = round((double) sum/arrsize) ;
    printf("%d\n", average1);
    
    // 중앙값
    average2 = arr[arrsize/2];
    printf("%d\n", average2);
    
    // 최빈값
    vector<pair<int, int>> st; // key와 빈도수 저장할 vector

    for (int i = 0; i < arrsize; i++)
    {
        if (st.empty())
        {
            st.push_back(pair<int, int>(arr[i],1));
            continue;
        }
        if (st.back().first == arr[i]) // 같은게 있다면
        {
            pair<int, int> tmp = st.back();
            tmp.second++; // 하나 증가
            st.pop_back(); // 기존 것 없애고
            st.push_back(tmp); // 새로운 것 다시 삽입
        }else{
            st.push_back(pair<int, int>(arr[i],1));
        }
    }
    // 빈도수가 높고, 숫자가 낮은 순으로 정렬
    sort(st.begin(), st.end(), comp);
    if (st[0].second == st[1].second)
    {
        average3 = st[1].first;
    }else{
        average3 = st[0].first;
    }
    printf("%d\n", average3);
    
    // 범위
    average4 = G-L;
    printf("%d",average4);

    return 0;
}
