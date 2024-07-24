/*
https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24
*/

class CustomPair{
    public int mappedNumber;
    public int originalNumber;
    public int indexOfNumber;

    CustomPair(int mappedNumber, int originalNumber, int indexOfNumber){
        this.mappedNumber=mappedNumber;
        this.originalNumber=originalNumber;
        this.indexOfNumber=indexOfNumber;
    }
}

class CustomComparator implements Comparator<CustomPair>{

    @Override
    public int compare(CustomPair A, CustomPair B){
        if(A.mappedNumber==B.mappedNumber){
            return Integer.compare(A.indexOfNumber, B.indexOfNumber);
        }
        return Integer.compare(A.mappedNumber, B.mappedNumber);
    }
}


class Solution {

    public static String trimPrefixZeros(StringBuilder str){
        int lengthOfStr=str.length(), index=0;
        while(true){
            if(str.charAt(index)!='0') break;
            str.setCharAt(index, '#');
            index++;
            if(index>=lengthOfStr) break;
        }
        if(str.length()==1&&str.charAt(0)=='#') return "0";
        StringBuilder fnstr=new StringBuilder();
        for(int i=index; i<lengthOfStr; ++i){
            fnstr.append(str.charAt(i));
        }
        return String.valueOf(fnstr);
    }

    public int[] sortJumbled(int[] mapping, int[] nums) {
        ArrayList<CustomPair>listOfMappedNumbers=new ArrayList<>();
        int sz=nums.length;
        for(int i=0; i<sz; ++i){
            int currentNum=nums[i];
            String currentNumInString=String.valueOf(currentNum);
            StringBuilder mappedStringNumber=new StringBuilder();
            int lengthOfCurrentNumInString=currentNumInString.length();
            for(int j=0; j<lengthOfCurrentNumInString; ++j){
                mappedStringNumber.append(String.valueOf(mapping[currentNumInString.charAt(j)-'0']));
            }
            String trimmedString=trimPrefixZeros(mappedStringNumber);
            int newInt=Integer.parseInt(trimmedString);
            CustomPair newPair=new CustomPair(newInt, currentNum, i);
            listOfMappedNumbers.add(newPair);
        }
        Collections.sort(listOfMappedNumbers, new CustomComparator());
        int[] resultantList=new int[listOfMappedNumbers.size()];
        for(int i=0; i<listOfMappedNumbers.size(); ++i){
            resultantList[i]=listOfMappedNumbers.get(i).originalNumber;
        }
        return resultantList;
    }
}