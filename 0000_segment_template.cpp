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
        return left + right; // sum�� ���
        //return min(left, right); // min
        //eturn max(left, right); // max
    }

    int mergeBlock(int value, int size){
        return value * size; // sum
        //return value; // min
        //return value; // max
    }

    // segment tree�� �� node�� �ο��� ��ȣ, �ش� ��尡 cover �ϴ� �迭�� ����
    int pushDown(int newValue, int node, int nodeLeft, int nodeRight){
        if (nodeLeft == nodeRight)
        {
            return tree[node] = newValue;
        }

        // �ڽ� ��忡 ������Ʈ�� ���� �����Ѵ�.
        lazyExist[node] = true;
        lazyValue[node] = newValue;
        return tree[node] = mergeBlock(newValue, nodeRight - nodeLeft +1);
        
    }

    // �� ��忡 �ο��� ��ȣ, ���� �Է� �迭������ ����
    int buildRec(const int arr[], int node, int nodeLeft, int nodeRight){
        // tree�� leaf�� �����ߴٸ� ���� update
        if (nodeLeft == nodeRight)
        {
            return tree[node] = arr[nodeLeft];
        }
        // tree�� �߰� node��� ������ 2���� ���� recursive call
        int mid = nodeLeft + (nodeRight-nodeLeft) / 2; // overflow ����
        int leftVal = buildRec(arr, node*2, nodeLeft, mid);
        int rightVal = buildRec(arr, node*2 +1, mid+1, nodeRight);

        // ���� ���� sub-tree�� ������ sub-tree�� ���� ���ؼ� node�� ������ ���� �� return
        return tree[node] = merge(leftVal, rightVal);
    }

    void build(const int arr[], int size){
        N = size;
        tree.resize(N*4);

        buildRec(arr, 1, 0,N-1);
    }
    // ���� �Է� �迭������ ���� , �� ����� ��ȣ, �ش� ��尡 cover �ϴ� �Է� �迭�� ����
    int queryRec(int left, int right, int node, int nodeLeft, int nodeRight){

        // Query ������ ����� 0�� ���� (�⺻��)
        if (right < nodeLeft || nodeRight < left)
        {
            return 0; // default value
        }
        
        // Query ������ ���� ���ԵǴ� ���� ���� ���� �׳� return (leaf ����)
        if (left <= nodeLeft && nodeRight <= right)
        {
            return tree[node];
        }
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;

        // ����� ������ query ������ ������ ���Ե��� �����鼭 lazy ���� �ִٸ� lazy ���� push-down �Ѵ�.
        if (lazyExist[node])
        {
            lazyExist[node] = false;
            pushDown(lazyValue[node], node*2, nodeLeft, mid);
            pushDown(lazyValue[node], node*2 + 1, mid+1, nodeRight);
            lazyValue[node] = DEFAULT_VALUE;
        }
        

        // Tree�� �߰� node��� ������ 2���� ���� recursive call �� ��, ���� sub-tree�� ������ sub-tree�� ���� ���ؼ� return
        return merge(queryRec(left, right, node*2, nodeLeft, mid), queryRec(left, right, node*2+1, mid +1, nodeRight));
    }

    // ������Ʈ�� ��ġ, ����ȣ, �ش� ��尡 cover�ϴ� �Է� �迭�� ����
    int updateRec(int left, int right, int newValue, int node, int nodeLeft, int nodeRight){
        // ������Ʈ ��ġ�� ������ ���� segment �̸� ���� ���� return
        if (right < nodeLeft || nodeRight < left){
            return tree[node];
        }
        // leaf����̸� ���� ������Ʈ�ϰ� �ش� ���� ����
        if (nodeLeft == nodeRight)
        {
            return tree[node] = newValue;
        }

        // ����� ������ query ������ ������ ���Եȴٸ�, �ش� ��常 ������Ʈ�ϰ� return
        if (left <= nodeLeft && nodeRight <= right)
        {
            lazyExist[node] = true;
            lazyValue[node] = newValue;
            return tree[node] = mergeBlock(newValue, nodeRight - nodeLeft + 1);
        }
        
        // Tree�� �߰� node ��� ������ 2���� ���� recursive call �� ��, 
        // ���� sub-tree�� ������ sub-tree�� ���� ���ؼ� return
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        //����� ������ query ������ ������ ���Ե��� �����鼭 lazy���� �ִٸ�, lazy ���� push-down �Ѵ�.
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

    int update(int index, int newValue){
        return updateRec(index, newValue, 1, 0, N-1);
    }
};




int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 3���� 4ȣ�� ����� 2���� 1ȣ���� 4ȣ���� ������� ���� �ո�ŭ ������� ������ ��ƾ� �Ѵ�.

    return 0;
}