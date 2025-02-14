# https://leetcode.com/problems/product-of-the-last-k-numbers/submissions/1543166230/?envType=daily-question&envId=2025-02-14

class ProductOfNumbers:

    def __init__(self):
        self.currentList=[]

    def add(self, num: int) -> None:
        self.currentList.append(num)

    def getProduct(self, k: int) -> int:
        traversingIndex=len(self.currentList)-1
        resultantProduct=1
        while(k):
            resultantProduct*=self.currentList[traversingIndex]
            k-=1
            traversingIndex-=1
        return resultantProduct


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)