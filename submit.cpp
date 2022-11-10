#include<stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool comp(const pair<int, int> &p1,const pair<int, int> &p2){
    
    if(p1.second == p2.second){     //�󵵼��� ������ 
        return p1.first < p2.first; //����(key)������ ������ 
    }
    return p1.second > p2.second;    //�ٸ��� �󵵼��� ū�� ������ 
    
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
    // �� ���� �����
    for (int i = 0; i < arrsize; i++)
    {
        // ������
        sum+=arr[i];

        // �ִ�
        if (arr[i] > G)
        {
            G = arr[i];
        }
        // �ּڰ�
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
    // �ϳ��� �ٿ����鼭 �ڷ� ����
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
    // ������
    average1 = round((double) sum/arrsize) ;
    printf("%d\n", average1);
    
    // �߾Ӱ�
    average2 = arr[arrsize/2];
    printf("%d\n", average2);
    
    // �ֺ�
    vector<pair<int, int>> st; // key�� �󵵼� ������ vector

    for (int i = 0; i < arrsize; i++)
    {
        if (st.empty())
        {
            st.push_back(pair<int, int>(arr[i],1));
            continue;
        }
        if (st.back().first == arr[i]) // ������ �ִٸ�
        {
            pair<int, int> tmp = st.back();
            tmp.second++; // �ϳ� ����
            st.pop_back(); // ���� �� ���ְ�
            st.push_back(tmp); // ���ο� �� �ٽ� ����
        }else{
            st.push_back(pair<int, int>(arr[i],1));
        }
    }
    // �󵵼��� ����, ���ڰ� ���� ������ ����
    sort(st.begin(), st.end(), comp);
    if (st[0].second == st[1].second)
    {
        average3 = st[1].first;
    }else{
        average3 = st[0].first;
    }
    printf("%d\n", average3);
    
    // ����
    average4 = G-L;
    printf("%d",average4);

    return 0;
}
