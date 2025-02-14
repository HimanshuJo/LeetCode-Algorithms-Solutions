/*
https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14
*/

class ProductOfNumbers {
public:

    vector<int>curlst;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        curlst.push_back(num);
    }
    
    int getProduct(int k) {
        int curidx=curlst.size()-1, res=1;
        while(k--){
            res*=curlst[curidx--];
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */