#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long key;
    int height;
    long long frq, size;
    Node *l, *r;
    Node(long long k){
        key = k;
        height = 1;
        frq = 1;
        size = 1;
        l = nullptr;
        r = nullptr;
    }
};

class AVL{
public:
    long long sizee(Node* t){
        if(!t) return 0;
        return t->size;
    }

    int hight(Node* t){
        if(!t) return 0;
        return t->height;
    }

    void update(Node* t){
        if(!t) return;
        int hl = hight(t->l);
        int hr = hight(t->r);
        if(hl >= hr)
            t->height = hight(t->l)+1;
        else if (hl < hr)
            t->height = hight(t->r)+1;
        t->size = sizee(t->l) + sizee(t->r) + t->frq;
    }
    Node* RL(Node* t){
        Node* t1 = t->l;
        Node* t2 = t1->r;
        t1->r = t;
        t->l = t2;
        update(t);
        update(t1);
        return t1;
    }
    Node* RR(Node* t){
        Node* t1 = t->r;
        Node* t2 = t1->l;
        t1->l = t;
        t->r = t2;
        update(t);
        update(t1);
        return t1;
    }

    int Balancenum(Node* t){
        if(!t) return 0;
        return hight(t->l) - hight(t->r);
    }

    Node* balance(Node* t){
        if(!t) return t;
        update(t);
        int x = Balancenum(t);
        if(x > 1){
            if(Balancenum(t->l) < 0)
                t->l = RR(t->l); 
            return RL(t);   
        }

        if(x < -1){
            if(Balancenum(t->r) > 0)
                t->r = RL(t->r);
            return RR(t);
        }
        return t; 
    }

    Node* insert(Node* t, long long x){
        if(!t) return new Node(x);
        if(x == t->key)
            t->frq++;
        else if(x < t->key)
            t->l = insert(t->l, x);
        else
            t->r = insert(t->r, x);
        
        return balance(t);
    }
    long long count(Node* t, long long k){
        if(!t) return 0;
        if(k < t->key)
            return count(t->l, k);
        else if(k > t->key)
            return sizee(t->l) + t->frq + count(t->r, k);
        else
            return sizee(t->l) + t->frq;
        
    }
};

int main(){
    // So what the algorithm does is that it gives all the prefix sums into an AVL Tree that keeps track of the
    //  Nodes(prefixes) that their differnce of prefixes are less than k:
    long long n, x;
    cin >> n >> x;
    vector<long long> A(n);
    for(int i = 0; i < n; i++)   cin >> A[i];
    AVL avl;
    Node* root = nullptr;
    root = avl.insert(root, 0);
    long long total = 1, pref = 1 , ans = 0;
// We are going to use prefix sums :S(sum)[r] - S(l-1) < k
// Y represents how many K's are there that this inequation is correct!!!
    for(int r = 0; r < n; r++){
        pref += A[r];
        long long t = pref - x;
        long long y = total - avl.count(root, t);
        ans += y;
        root = avl.insert(root, pref);
        total += 1;
    }
    cout << ans << "\n";
    return 0;
}

// This problem was solved from a hint by "Behrad Hemmati"
// The AVL tree was made by the help of : https://www.geeksforgeeks.org/dsa/insertion-in-an-avl-tree/
