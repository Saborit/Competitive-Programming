/* Fenwick Tree (Binary Indexed Tree)
 * 
 * Tested on: http://dmoj.uclv.cu/problem/oci19day2b
 * */

#define MN  (int)1e6

struct fenwick_tree{
    int T[MN+5];
    
    int acc(int b){ 
        int ans = 0;
        for(; b; b-=(b&(-b))) ans += T[b];
        return ans;
    }    
    
    int query(int a, int b){
        return acc(b) - (a==1 ? 0 : acc(a-1));     
    }
    
    void update(int p, int val){
        for(; p<=MN; p+=(p&(-p)))
            T[p] += val;    
    }
};
