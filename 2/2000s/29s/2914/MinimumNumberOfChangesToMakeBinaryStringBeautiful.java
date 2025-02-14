/*
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05
*/

class Solution {
    public int minChanges(String s) {
        int lengthOfS=s.length(), currentIndex=0, currentNumberOfChanges=0;
        while(true){
            if(currentIndex>=lengthOfS) break;
            StringBuilder currentSubString=new StringBuilder();
            while(true){
                if((currentSubString.length()>0&&currentSubString.length()%2==0)||currentIndex>=lengthOfS) break;
                if(currentSubString.length()==0){
                    currentSubString.append(s.charAt(currentIndex));
                    currentIndex++;
                } else{
                    if(s.charAt(currentIndex)!=currentSubString.charAt(0)){
                        currentNumberOfChanges++;
                        currentSubString.append(currentSubString.charAt(0));
                        currentIndex++;
                    } else{
                        currentSubString.append(currentSubString.charAt(0));
                        currentIndex++;
                    }
                }
            }
        }
        return currentNumberOfChanges;
    }
}

// ------- ******* -------

class Solution2 {
    public int minChanges(String s) {
        int lengthOfS=s.length(), currentIndex=0, currentNumberOfChanges=0;
        while(true){
            if(currentIndex>=lengthOfS) break;
            char currentChar='#';
            while(true){
                if(currentIndex>=lengthOfS) break;
                if(currentChar=='#'){
                    currentChar=s.charAt(currentIndex);
                    currentIndex++;
                } else{
                    if(s.charAt(currentIndex)!=currentChar){
                        currentNumberOfChanges++;
                        currentIndex++;
                        break;
                    } else{
                        currentIndex++;
                        break;
                    }
                }
            }
        }
        return currentNumberOfChanges;
    }
}

// ------- ******* -------

class Solution3 {
    public int minChanges(String s) {
        int lengthOfS=s.length(), currentIndex=0, currentNumberOfChanges=0;
        while(true){
            if(currentIndex>=lengthOfS) break;
            if(s.charAt(currentIndex)!=s.charAt(currentIndex+1)) currentNumberOfChanges++;
            currentIndex+=2;
        }
        return currentNumberOfChanges;
    }
}