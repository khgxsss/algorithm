#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
    static const int DEFAULT_VALUE = 0;
    //static const int DEFAULT_VALUE = numeric_limits<int>::max(); // max
    //static const int DEFAULT_VALUE = numeric_limits<int>::min(); // min

    int N; // size
    vector <int> tree; // segment tree
    vector <int> lazyValue;
    vector <bool> lazyExist;

    int merge(int left, int right){
        return left + right; // sum의 경우
        //return min(left, right); // min
        //eturn max(left, right); // max
    }

    int mergeBlock(int value, int size){
        return value * size; // sum
        //return value; // min
        //return value; // max
    }

    // segment tree의 각 node에 부여한 번호, 해당 노드가 cover 하는 배열의 범위
    int pushDown(int newValue, int node, int nodeLeft, int nodeRight){
        if (nodeLeft == nodeRight)
        {
            return tree[node] = newValue;
        }

        // 자식 노드에 업데이트할 값을 전달한다.
        lazyExist[node] = true;
        lazyValue[node] = newValue;
        return tree[node] = mergeBlock(newValue, nodeRight - nodeLeft +1);
        
    }

    // 각 노드에 부여된 번호, 원래 입력 배열에서의 범위
    int buildRec(const int arr[], int node, int nodeLeft, int nodeRight){
        // tree의 leaf에 도달했다면 값을 update
        if (nodeLeft == nodeRight)
        {
            return tree[node] = arr[nodeLeft];
        }
        // tree의 중간 node라면 구간을 2개로 나눠 recursive call
        int mid = nodeLeft + (nodeRight-nodeLeft) / 2; // overflow 방지
        int leftVal = buildRec(arr, node*2, nodeLeft, mid);
        int rightVal = buildRec(arr, node*2 +1, mid+1, nodeRight);

        // 구한 왼쪽 sub-tree와 오른쪽 sub-tree의 값을 더해서 node의 값으로 저장 및 return
        return tree[node] = merge(leftVal, rightVal);
    }

    void build(const int arr[], int size){
        N = size;
        tree.resize(N*4);

        buildRec(arr, 1, 0,N-1);
    }
    // 원래 입력 배열에서의 범위 , 각 노드의 번호, 해당 노드가 cover 하는 입력 배열의 범위
    int queryRec(int left, int right, int node, int nodeLeft, int nodeRight){

        // Query 구간을 벗어나면 0을 리턴 (기본값)
        if (right < nodeLeft || nodeRight < left)
        {
            return 0; // default value
        }
        
        // Query 구간에 완전 포함되는 경우는 현재 값을 그냥 return (leaf 포함)
        if (left <= nodeLeft && nodeRight <= right)
        {
            return tree[node];
        }
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        // 노드의 영역이 query 영역에 완전히 포함되지 않으면서 lazy 값이 있다면 lazy 값을 push-down 한다.
        if (lazyExist[node])
        {
            lazyExist[node] = false;
            pushDown(lazyValue[node], node*2, nodeLeft, mid);
            pushDown(lazyValue[node], node*2 + 1, mid+1, nodeRight);
            lazyValue[node] = DEFAULT_VALUE;
        }
        

        // Tree의 중간 node라면 구간을 2개로 나눠 recursive call 한 후, 왼쪽 sub-tree와 오른쪽 sub-tree의 값을 더해서 return
        return merge(queryRec(left, right, node*2, nodeLeft, mid), queryRec(left, right, node*2+1, mid +1, nodeRight));
    }

    // 업데이트할 위치, 노드번호, 해당 노드가 cover하는 입력 배열의 범위
    int updateRec(int left, int right, int newValue, int node, int nodeLeft, int nodeRight){
        // 업데이트 위치와 관련이 없는 segment 이면 현재 값을 return
        if (right < nodeLeft || nodeRight < left){
            return tree[node];
        }
        // leaf노드이면 값을 업데이트하고 해당 값을 리턴
        if (nodeLeft == nodeRight)
        {
            return tree[node] = newValue;
        }

        // 노드의 영역이 query 영역에 완전히 포함된다면, 해당 노드만 업데이트하고 return
        if (left <= nodeLeft && nodeRight <= right)
        {
            lazyExist[node] = true;
            lazyValue[node] = newValue;
            return tree[node] = mergeBlock(newValue, nodeRight - nodeLeft + 1);
        }
        
        // Tree의 중간 node 라면 구간을 2개로 나눠 recursive call 한 후, 
        // 왼쪽 sub-tree와 오른쪽 sub-tree의 값을 더해서 return
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        //노드의 영역이 query 영역에 완전히 포함되지 않으면서 lazy값이 있다면, lazy 값을 push-down 한다.
        if (lazyExist[node])
        {
            lazyExist[node] = false;
            pushDown(lazyValue[node], node*2, nodeLeft, mid);
            pushDown(lazyValue[node], node*2 + 1, mid+1, nodeRight);
            lazyValue[node] = DEFAULT_VALUE;
        }
        
        int leftVal = updateRec(left, right, newValue, node*2, nodeLeft, mid);
        int rightVal = updateRec(left, right, newValue, node*2+1, mid+1, nodeRight);
        return tree[node] = merge(leftVal, rightVal);
        
        
    }

    int update(int left, int right, int newValue){
        return updateRec(left, right, newValue, 1, 0, N-1);
    }
};




int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 3층의 4호에 살려면 2층의 1호부터 4호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다.

    return 0;
}
