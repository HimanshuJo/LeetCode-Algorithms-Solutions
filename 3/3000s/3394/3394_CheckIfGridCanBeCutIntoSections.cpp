/*
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/?envType=daily-question&envId=2025-03-25
*/

/*
Time complexity: O(nlogn)
The time complexity is dominated by the sorting operation, which takes O(nlogn) time.

We call the checkCuts function twice (once for horizontal cuts and once for vertical cuts), 
and each call performs sorting and a linear scan through the rectangles.

This gives us 2⋅(O(nlogn)+O(n)), which simplifies to O(nlogn).
*/

/*
Space complexity: O(S)
The space taken by the sorting algorithm (S) depends on the language of implementation:

In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logn).
In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worst-case space complexity of O(logn).
In Python, the sort() method sorts a list using the Timsort algorithm which is a combination of Merge Sort and Insertion Sort and has a space complexity of O(n).

Other than this, we're only using a few variables (gapCount, furthestEnd, loop indices) that don't scale with the input size. 
Therefore, the overall space complexity remains O(S).
*/

class CustomComparator{
    public:
    bool operator()(const vector<int>&rectA, const vector<int>&rectB){
        return rectA[1]<rectB[1];
    }
};

class Solution {
public:

    bool checkVerticalValidCuts(vector<vector<int>>rectangles){
        sort(rectangles.begin(), rectangles.end(), CustomComparator());
        int sz=rectangles.size(), curmaxend=rectangles[0][3], countGaps=0;
        for(int i=0; i<sz; ++i){
            vector<int>currectangle=rectangles[i];
            int curendx=currectangle[1], curendy=currectangle[3];
            if(curendx>=curmaxend){
                countGaps++;
            }
            curmaxend=max(curmaxend, curendy);
        }
        return countGaps>=2;
    }

    bool checkHorizontalValidCuts(vector<vector<int>>rectangles){
        sort(rectangles.begin(), rectangles.end());
        int sz=rectangles.size(), curmaxstartend=rectangles[0][2], countGaps=0;
        for(int i=0; i<sz; ++i){
            vector<int>currectangle=rectangles[i];
            int curstartx=currectangle[0], curstarty=currectangle[2];
            if(curstartx>=curmaxstartend){
                countGaps++;
            }
            curmaxstartend=max(curmaxstartend, curstarty);
        }
        return countGaps>=2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        bool canHaveHorizontalValidCuts=checkHorizontalValidCuts(rectangles),
             canHaveVerticalValidCuts=checkVerticalValidCuts(rectangles);
        return canHaveHorizontalValidCuts||canHaveVerticalValidCuts;
    }
};
