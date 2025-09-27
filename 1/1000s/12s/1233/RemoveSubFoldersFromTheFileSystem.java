/*
https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25
*/

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder, (A, B)->Integer.compare(A.length(), B.length()));
        HashSet<String>seenFolders=new HashSet<>();
        ArrayList<String>resultantList=new ArrayList<>();
        int lengthOfFolder=folder.length;
        for(int i=0; i<lengthOfFolder; ++i){
            String currentFolder=folder[i];
            if(seenFolders.contains(currentFolder)) continue;
            int lengthOfCurrentFolder=currentFolder.length(), currentIndex=1;
            StringBuilder folderToBeChecked=new StringBuilder();
            folderToBeChecked.append(currentFolder.charAt(0));
            boolean isAlreadyPresent=false;
            while(currentIndex<=lengthOfCurrentFolder-1){
                while(true){
                    if(currentIndex>=lengthOfCurrentFolder) break;
                    if(currentFolder.charAt(currentIndex)=='/'){
                        if(seenFolders.contains(folderToBeChecked.toString())){
                            isAlreadyPresent=true;
                            break;
                        }
                        folderToBeChecked.append("/");
                        currentIndex++;
                        break;
                    }
                    folderToBeChecked.append(currentFolder.charAt(currentIndex));
                    currentIndex++;
                }
                if(isAlreadyPresent) break;
            }
            if(!isAlreadyPresent){
                resultantList.add(currentFolder);
                seenFolders.add(currentFolder);
            }
        }
        return resultantList;
    }
}