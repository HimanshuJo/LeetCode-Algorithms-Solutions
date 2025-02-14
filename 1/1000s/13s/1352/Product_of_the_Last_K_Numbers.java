/*
https://leetcode.com/problems/product-of-the-last-k-numbers/submissions/1543166230/?envType=daily-question&envId=2025-02-14
*/

class ProductOfNumbers {

    ArrayList<Integer>currentList;

    public ProductOfNumbers() {
        currentList=new ArrayList<>();
    }
    
    public void add(int num) {
        currentList.add(num);
    }
    
    public int getProduct(int k) {
        int traversingIndex=currentList.size()-1, resultantProduct=1;
        while(k-- >0){
            resultantProduct*=currentList.get(traversingIndex--);
        }
        return resultantProduct;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */